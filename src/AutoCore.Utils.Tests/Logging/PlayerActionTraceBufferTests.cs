using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class PlayerActionTraceBufferTests
{
    [TestInitialize]
    public void Init()
    {
        GameLog.ResetForTests();
        GameLog.SetSinkForTests(new InMemoryLogSink());
        GameLog.MinimumLevel = StructuredLogLevel.Trace;
        PlayerActionTraceBuffer.Clear();
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        PlayerActionTraceBuffer.Clear();
    }

    [TestMethod]
    public void Record_ViaGameLog_IsQueryableBySessionAndCharacter()
    {
        using (LogContext.Push(("SessionId", "sess-aaa"), ("CharacterId", 42L)))
        {
            GameLog.Audit("CurrencyChanged", ("Delta", -10));
            GameLog.Info("ObjectUsed", ("Handler", "Vendor"));
        }

        using (LogContext.Push(("SessionId", "other"), ("CharacterId", 99L)))
        {
            GameLog.Audit("CurrencyChanged", ("Delta", 1));
        }

        var forPlayer = PlayerActionTraceBuffer.SnapshotForPlayer("sess-aaa", 42, limit: 100);
        Assert.AreEqual(2, forPlayer.Count);
        Assert.IsTrue(forPlayer.All(r =>
            Equals(r.GetProperty("CharacterId"), 42L) || Equals(r.GetProperty("SessionId"), "sess-aaa")));
    }

    [TestMethod]
    public void Snapshot_RespectsLimit_ReturnsOldestOfLastN()
    {
        using (LogContext.Push(("SessionId", "s1"), ("CharacterId", 1L)))
        {
            for (var i = 0; i < 5; i++)
                GameLog.Info("Tick", ("i", i));
        }

        var last2 = PlayerActionTraceBuffer.SnapshotForPlayer("s1", 1, limit: 2);
        Assert.AreEqual(2, last2.Count);
        Assert.AreEqual(3, last2[0].GetProperty("i"));
        Assert.AreEqual(4, last2[1].GetProperty("i"));
    }

    [TestMethod]
    public void Action_IsRetainedEvenWhenBelowMinimumLevel_AndWithoutSink()
    {
        // Production bug: report buffer only saw post-filter NDJSON writes, so Debug dual-writes
        // and Action breadcrumbs never reached /reportbug under MinimumLevel=Info.
        GameLog.ResetForTests(); // no sink, MinimumLevel=Info
        PlayerActionTraceBuffer.Clear();

        using (LogContext.Push(("SessionId", "sess-x"), ("CharacterId", 7L)))
        {
            GameLog.Action("NpcInteract", ("Outcome", "DialogOpened"), ("NpcCoid", 99L));
            // Dual-write path: Debug legacy under ambient session must still hit the buffer
            // even though MinimumLevel is Info and there is no NDJSON sink.
            AutoCore.Utils.Logger.WriteLog(AutoCore.Utils.LogType.Debug, "TakeDamage: vehicle coid=1");
        }

        var snap = PlayerActionTraceBuffer.SnapshotForPlayer("sess-x", 7, limit: 50);
        Assert.IsTrue(snap.Any(r => r.EventName == "NpcInteract"),
            "GameLog.Action must always enter the report buffer.");
        Assert.IsTrue(snap.Any(r => r.EventName == "Legacy"),
            "Legacy dual-write under session context must enter the report buffer even at Debug.");
    }

    [TestMethod]
    public void Snapshot_MatchesActorAndVictimCharacterIds()
    {
        GameLog.Action("DamageDealt", ("ActorCharacterId", 11L), ("Damage", 5));
        GameLog.Action("DamageTaken", ("VictimCharacterId", 11L), ("Damage", 3));
        GameLog.Action("DamageDealt", ("ActorCharacterId", 22L), ("Damage", 9));

        var for11 = PlayerActionTraceBuffer.SnapshotForPlayer(null, 11, limit: 50);
        Assert.AreEqual(2, for11.Count);
        Assert.IsTrue(for11.All(r =>
            Equals(r.GetProperty("ActorCharacterId"), 11L)
            || Equals(r.GetProperty("VictimCharacterId"), 11L)));
    }
}
