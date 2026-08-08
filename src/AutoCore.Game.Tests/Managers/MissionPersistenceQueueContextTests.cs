using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Game.Managers;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Utils;
using AutoCore.Utils.Logging;

/// <summary>
/// Phase 2 context capture across the mission persistence queue: an op enqueued inside a
/// session scope must be flushed (and its failures logged) under that same scope, so a
/// background persistence failure is attributable to the player who caused the write.
/// </summary>
[TestClass]
public class MissionPersistenceQueueContextTests
{
    private InMemoryLogSink _sink;

    [TestInitialize]
    public void Init()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
    }

    [TestMethod]
    public void Flush_FailureLog_CarriesEnqueueSiteContext()
    {
        var queue = new MissionPersistenceQueue();

        using (LogContext.Push(("SessionId", "mission-session-1"), ("CharacterId", 10L)))
        {
            queue.Enqueue(10, 100, QuestPersistOp.Upsert(0, 0, Array.Empty<byte>()));
        }

        // The flush runs with no ambient scope (background worker) — attribution must
        // come from the context captured at enqueue time.
        queue.Flush((_, _, _) => throw new InvalidOperationException("db down"));

        var warning = _sink.Records.Single(r =>
            r.EventName == "Legacy" &&
            r.Level == StructuredLogLevel.Warning &&
            (r.Message?.Contains("mission persist") ?? false));

        Assert.AreEqual("mission-session-1", warning.GetProperty("SessionId"),
            "A mission-write failure must be attributable to the session that enqueued it.");
        Assert.AreEqual(10L, warning.GetProperty("CharacterId"),
            "A mission-write failure must be attributable to the character whose progress is at risk.");
    }

    [TestMethod]
    public void Flush_RetriedOp_KeepsItsCapturedContext()
    {
        var queue = new MissionPersistenceQueue();

        using (LogContext.Push(("SessionId", "mission-session-2")))
        {
            queue.Enqueue(11, 200, QuestPersistOp.Complete());
        }

        queue.Flush((_, _, _) => throw new InvalidOperationException("transient"));
        _sink.Clear();
        queue.Flush((_, _, _) => throw new InvalidOperationException("transient again"));

        var warning = _sink.Records.Single(r =>
            r.EventName == "Legacy" &&
            r.Level == StructuredLogLevel.Warning &&
            (r.Message?.Contains("mission persist") ?? false));
        Assert.AreEqual("mission-session-2", warning.GetProperty("SessionId"),
            "A retried op must not lose its enqueue-site attribution when re-queued after failure.");
    }

    [TestMethod]
    public void Flush_DoesNotLeakCapturedContextIntoCaller()
    {
        var queue = new MissionPersistenceQueue();

        using (LogContext.Push(("SessionId", "mission-session-3")))
        {
            queue.Enqueue(12, 300, QuestPersistOp.Complete());
        }

        queue.Flush((_, _, _) => { });

        Assert.AreEqual(0, LogContext.CurrentProperties.Count,
            "Restore must be scoped to each persist call; the flush caller's ambient context " +
            "must be unchanged afterwards.");
    }
}
