using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Game.Entities;
using AutoCore.Game.Experience;
using AutoCore.Game.Inventory;
using AutoCore.Game.Managers;
using AutoCore.Game.Tests.Experience.Fakes;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Game.Tests.Mission.Infrastructure;
using AutoCore.Utils.Logging;
using GameMission = AutoCore.Game.Mission.Mission;
using GameMissionObjective = AutoCore.Game.Mission.MissionObjective;

/// <summary>Phase 3E: mission grant/complete/fail structured audit events.</summary>
[TestClass]
public class MissionAuditLoggingTests
{
    private InMemoryLogSink _sink = null!;
    private ExperienceService _svc = null!;
    private RecordingProgressPersistence _persist = null!;

    [TestInitialize]
    public void Init()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);

        _svc = ExperienceService.Instance;
        _svc.ResetForTests();
        _persist = new RecordingProgressPersistence();
        _svc.Persistence = _persist;
        _svc.PersistOnGrant = false;
        _svc.SendPacketsOnGrant = false;
        _svc.ResolveThreshold = ExperienceService.DefaultRetailThreshold;
        _svc.ResolveQuestFrac = ExperienceService.DefaultQuestFrac;
        _svc.ResolveQuestCreditsFrac = _ => 0f;
        _svc.ResolveQuestBaseCredits = _ => 0;
        _svc.ResolveLevelRow = level => new AutoCore.Database.World.Models.ExperienceLevel
        {
            Level = level,
            Experience = ExperienceService.DefaultRetailThreshold(level),
            SkillPoints = 0,
            AttributePoints = 0,
            ResearchPoints = 0
        };
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        _svc.ResetForTests();
    }

    [TestMethod]
    public void GrantMission_New_EmitsMissionGranted()
    {
        using var fx = new MissionTestFixture();
        const int missionId = 94001;
        var o0 = fx.CreateSimpleObjective(95001, 0, missionId);
        fx.SeedMission(missionId, 0, o0);
        var player = fx.CreatePlayer();
        _sink.Clear();

        NpcInteractHandler.GrantMission(player.Connection, player.Character, missionId);

        var rec = _sink.Single("MissionGranted");
        Assert.IsTrue(rec.Audit);
        Assert.AreEqual(missionId, Convert.ToInt32(rec.GetProperty("MissionId")));
        Assert.AreEqual(player.Character.ObjectId.Coid, Convert.ToInt64(rec.GetProperty("CharacterId")));
    }

    [TestMethod]
    public void FailMission_Active_EmitsMissionFailed()
    {
        using var fx = new MissionTestFixture();
        const int missionId = 94002;
        var o0 = fx.CreateSimpleObjective(95002, 0, missionId);
        fx.SeedMission(missionId, 0, o0);
        var player = fx.CreatePlayer();
        fx.GiveQuest(player.Character, missionId);
        _sink.Clear();

        NpcInteractHandler.FailMission(player.Connection, player.Character, missionId);

        var rec = _sink.Single("MissionFailed");
        Assert.IsTrue(rec.Audit);
        Assert.AreEqual(missionId, Convert.ToInt32(rec.GetProperty("MissionId")));
    }

    [TestMethod]
    public void ApplyMissionCompleteRewards_EmitsMissionCompleted_WithAwards()
    {
        var inv = new InventoryManager(new RecordingInventoryPersistence());
        var character = new Character();
        character.SetCoid(7001, true);
        character.AttachTestDataForTests("MComp");
        character.SetExperience(0);
        character.SetLevel(1);
        character.SetCredits(0);
        character.AttachInventoryForTests(inv);

        var mission = GameMission.CreateForTests(77);
        mission.TargetLevel = 1;
        var objective = GameMissionObjective.CreateForTests(1, 0, 77);
        typeof(GameMissionObjective).GetProperty(nameof(GameMissionObjective.XP))!.SetValue(objective, 50);
        typeof(GameMissionObjective).GetProperty(nameof(GameMissionObjective.Credits))!.SetValue(objective, 25);
        _sink.Clear();

        NpcInteractHandler.ApplyMissionCompleteRewards(character, mission, objective, source: "UnitTest");

        var rec = _sink.Single("MissionCompleted");
        Assert.IsTrue(rec.Audit);
        Assert.AreEqual(77, Convert.ToInt32(rec.GetProperty("MissionId")));
        Assert.AreEqual(false, rec.GetProperty("Forced"));
        Assert.IsTrue(Convert.ToInt32(rec.GetProperty("XpAwarded")) >= 0);
        Assert.IsTrue(Convert.ToInt64(rec.GetProperty("CreditsAwarded")) >= 0);
        Assert.IsNotNull(rec.GetProperty("TransactionId"));
    }

    [TestMethod]
    public void ForceCompleteMission_EmitsMissionCompleted_ForcedTrue()
    {
        using var fx = new MissionTestFixture();
        const int missionId = 94003;
        var o0 = fx.CreateSimpleObjective(95003, 0, missionId);
        fx.SeedMission(missionId, 0, o0);
        var player = fx.CreatePlayer();
        fx.GiveQuest(player.Character, missionId);
        player.Character.AttachInventoryForTests(new InventoryManager(new RecordingInventoryPersistence()));
        _sink.Clear();

        NpcInteractHandler.ForceCompleteMission(player.Connection, player.Character, missionId);

        var rec = _sink.Single("MissionCompleted");
        Assert.AreEqual(true, rec.GetProperty("Forced"));
        Assert.AreEqual(missionId, Convert.ToInt32(rec.GetProperty("MissionId")));
    }
}
