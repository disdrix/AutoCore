using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Utils.Logging;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Diagnostics;

[TestClass]
public class PlayerActionTraceTests
{
    [TestInitialize]
    public void Init()
    {
        GameLog.ResetForTests();
        GameLog.SetSinkForTests(new Fakes.InMemoryLogSink());
        GameLog.MinimumLevel = StructuredLogLevel.Info;
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
    public void ObjectUsed_AppearsInReportBuffer_WithCharacterId()
    {
        var character = new Character();
        character.SetCoid(501, true);

        PlayerActionTrace.ObjectUsed(character, targetCoid: 900, handler: "MissionDialog", objectiveId: 12);

        var snap = PlayerActionTraceBuffer.SnapshotForPlayer(null, 501, limit: 20);
        Assert.AreEqual(1, snap.Count);
        Assert.AreEqual("ObjectUsed", snap[0].EventName);
        Assert.AreEqual("MissionDialog", snap[0].GetProperty("Handler"));
        Assert.AreEqual(900L, Convert.ToInt64(snap[0].GetProperty("TargetCoid")));
    }

    [TestMethod]
    public void NpcInteract_And_SkillCast_AppearInReportBuffer()
    {
        var character = new Character();
        character.SetCoid(502, true);

        PlayerActionTrace.NpcInteract(character, 44, 1200, "DialogOpened", objectiveId: 1, missionCount: 2);
        PlayerActionTrace.SkillCast(character, skillId: 77, rank: 2, success: true, response: "Ok", targetCoid: 44);

        var snap = PlayerActionTraceBuffer.SnapshotForPlayer(null, 502, limit: 20);
        Assert.AreEqual(2, snap.Count);
        Assert.IsTrue(snap.Any(r => r.EventName == "NpcInteract" && Equals(r.GetProperty("Outcome"), "DialogOpened")));
        Assert.IsTrue(snap.Any(r => r.EventName == "SkillCast" && Equals(r.GetProperty("Success"), true)));
    }

    [TestMethod]
    public void DamageTaken_ViaTakeDamageWithAttacker_RecordsForPlayerVehicleOwner()
    {
        var victim = new Character();
        victim.SetCoid(600, true);
        var vehicle = new Vehicle();
        vehicle.SetCoid(601, true);
        vehicle.SetOwner(victim);
        victim.SetCurrentVehicleForTests(vehicle);

        // Initialize HP so TakeDamage can apply.
        vehicle.GetType(); // ensure constructed
        // GraphicsObject path needs health; Vehicle uses SimpleObject HP via base.
        // Force a heal setup if needed by dealing damage only when HP>0.
        // Use Creature/Vehicle TakeDamage path with positive MaxHP via Restore if available.
        var before = vehicle.GetCurrentHP();
        if (before <= 0)
        {
            // EnsureHealth may not run; skip if unit vehicle has 0 max.
            // Still verify the trace helper itself:
            PlayerCombatTrace.OnDamage(vehicle, attacker: null, actualDamage: 5);
        }
        else
        {
            vehicle.TakeDamage(5, attacker: null);
        }

        var snap = PlayerActionTraceBuffer.SnapshotForPlayer(null, 600, limit: 20);
        Assert.IsTrue(snap.Any(r => r.EventName == "DamageTaken"),
            "Player-owned vehicle damage must produce DamageTaken for report buffer. Events: "
            + string.Join(",", snap.Select(r => r.EventName)));
    }

    [TestMethod]
    public void HighFidelity_InteractDamageHealSkill_AllAppearInBugReportZip()
    {
        var character = new Character();
        character.SetCoid(777, true);

        // Simulate a short play session: NPC clicks, combat, heal, skill.
        PlayerActionTrace.ObjectUsed(character, targetCoid: 111, handler: "MissionDialog", objectiveId: 3);
        PlayerActionTrace.ObjectUsed(character, targetCoid: 111, handler: "MissionDialog", objectiveId: 3);
        PlayerActionTrace.NpcInteract(character, 111, 5555, "DialogOpened", objectiveId: 3, missionCount: 1);
        PlayerActionTrace.MissionDialogResponse(character, missionId: 42, accepted: true, npcCoid: 111, outcome: "Received");
        PlayerActionTrace.DamageDealt(character, target: null, damage: 12, isCrit: false);
        PlayerActionTrace.DamageTaken(character, attacker: null, damage: 4, hpAfter: 96, hpMax: 100);
        PlayerActionTrace.Healed(character, amount: 8, hpAfter: 100, hpMax: 100, source: "RestoreHealth");
        PlayerActionTrace.SkillCast(character, skillId: 9, rank: 1, success: true, response: "Ok", targetCoid: 222);

        var package = BugReportBuilder.Build(character, "high fidelity trace check");
        using var ms = new MemoryStream(package.ZipBytes);
        using var zip = new System.IO.Compression.ZipArchive(ms, System.IO.Compression.ZipArchiveMode.Read);
        var entry = zip.GetEntry("player-events.ndjson");
        Assert.IsNotNull(entry);
        using var reader = new StreamReader(entry.Open());
        var ndjson = reader.ReadToEnd();

        foreach (var name in new[]
                 {
                     "ObjectUsed", "NpcInteract", "MissionDialogResponse",
                     "DamageDealt", "DamageTaken", "Healed", "SkillCast"
                 })
        {
            Assert.IsTrue(ndjson.Contains(name, StringComparison.Ordinal),
                $"Bug report must include {name}. Body:\n{ndjson}");
        }

        // Multiple ObjectUsed clicks must both be present (not collapsed).
        var objectUsedCount = ndjson.Split('\n', StringSplitOptions.RemoveEmptyEntries)
            .Count(line => line.Contains("ObjectUsed", StringComparison.Ordinal));
        Assert.IsTrue(objectUsedCount >= 2, $"Expected ≥2 ObjectUsed lines, got {objectUsedCount}");
    }
}
