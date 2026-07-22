using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Experience;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Experience.Fakes;
using AutoCore.Game.TNL;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Entities;

/// <summary>
/// Covers ReactionType.AddXP and ResetTrigger residual handlers.
/// </summary>
[TestClass]
public class ReactionAddXpAndResetTriggerTests
{
    private ExperienceService _xp = null!;
    private RecordingProgressPersistence _persist = null!;

    [TestInitialize]
    public void SetUp()
    {
        TriggerManager.Instance.ClearAllForTests();
        _xp = ExperienceService.Instance;
        _xp.ResetForTests();
        _persist = new RecordingProgressPersistence();
        _xp.Persistence = _persist;
        _xp.PersistOnGrant = false;
        _xp.SendPacketsOnGrant = false;
        _xp.ResolveThreshold = ExperienceService.DefaultRetailThreshold;
        _xp.ResolveLevelRow = level => new AutoCore.Database.World.Models.ExperienceLevel
        {
            Level = level,
            Experience = ExperienceService.DefaultRetailThreshold(level),
            SkillPoints = 1,
            AttributePoints = 1,
            ResearchPoints = 0
        };
    }

    [TestCleanup]
    public void TearDown()
    {
        TriggerManager.Instance.ClearAllForTests();
        _xp.ResetForTests();
    }

    [TestMethod]
    public void AddXp_WithCharacterActivator_GrantsAmount()
    {
        var (character, vehicle, map) = CreatePlayer();
        character.AttachTestDataForTests("addxp");
        character.SetExperience(0);
        character.SetLevel(1);

        var tpl = new ReactionTemplate
        {
            COID = 90001,
            Name = "add_xp",
            ReactionType = ReactionType.AddXP,
            ActOnActivator = true,
            GenericVar1 = 250,
        };
        var reaction = new Reaction(tpl);
        reaction.SetCoid(90001, false);
        reaction.SetMap(map);

        Assert.IsTrue(reaction.TriggerIfPossible(vehicle));
        Assert.IsTrue(character.Experience >= 250, $"Expected XP grant, got experience={character.Experience} level={character.Level}");
    }

    [TestMethod]
    public void AddXp_ZeroAmount_NoOp()
    {
        var (character, vehicle, map) = CreatePlayer();
        character.AttachTestDataForTests("addxp0");
        character.SetExperience(10);
        character.SetLevel(1);

        var tpl = new ReactionTemplate
        {
            COID = 90002,
            Name = "add_xp0",
            ReactionType = ReactionType.AddXP,
            ActOnActivator = true,
            GenericVar1 = 0,
        };
        var reaction = new Reaction(tpl);
        reaction.SetCoid(90002, false);
        reaction.SetMap(map);

        Assert.IsTrue(reaction.TriggerIfPossible(vehicle));
        Assert.AreEqual(10, character.Experience);
    }

    [TestMethod]
    public void AddXp_WithoutCharacter_StillSucceeds()
    {
        var continent = new ContinentObject
        {
            Id = 901,
            MapFileName = "tm_addxp",
            DisplayName = "t",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
        var creature = new Creature();
        creature.SetCoid(10, false);
        creature.SetMap(map);

        var tpl = new ReactionTemplate
        {
            COID = 90003,
            Name = "add_xp_npc",
            ReactionType = ReactionType.AddXP,
            ActOnActivator = true,
            GenericVar1 = 100,
        };
        var reaction = new Reaction(tpl);
        reaction.SetCoid(90003, false);
        reaction.SetMap(map);

        Assert.IsTrue(reaction.TriggerIfPossible(creature));
    }

    [TestMethod]
    public void ResetTrigger_WithObjectsList_Succeeds()
    {
        var (_, vehicle, map) = CreatePlayer();
        const long triggerCoid = 7001;

        var tpl = new ReactionTemplate
        {
            COID = 90010,
            Name = "reset_trig",
            ReactionType = ReactionType.ResetTrigger,
            Objects = { triggerCoid },
        };
        var reaction = new Reaction(tpl);
        reaction.SetCoid(90010, false);
        reaction.SetMap(map);

        Assert.IsTrue(reaction.TriggerIfPossible(vehicle));
        // Soft-assert: ResetTriggerFor is callable for listed cooids without throw.
        TriggerManager.Instance.ResetTriggerFor(vehicle.ObjectId.Coid, triggerCoid);
    }

    [TestMethod]
    public void ResetTrigger_WithGenericVar1_Succeeds()
    {
        var (_, vehicle, map) = CreatePlayer();
        const long triggerCoid = 7002;

        var tpl = new ReactionTemplate
        {
            COID = 90011,
            Name = "reset_g1",
            ReactionType = ReactionType.ResetTrigger,
            GenericVar1 = (int)triggerCoid,
        };
        var reaction = new Reaction(tpl);
        reaction.SetCoid(90011, false);
        reaction.SetMap(map);

        Assert.IsTrue(reaction.TriggerIfPossible(vehicle));
        TriggerManager.Instance.ResetTriggerFor(vehicle.ObjectId.Coid, triggerCoid);
    }

    [TestMethod]
    public void ResetTrigger_NoTargets_StillSucceeds()
    {
        var (_, vehicle, map) = CreatePlayer();
        var tpl = new ReactionTemplate
        {
            COID = 90012,
            Name = "reset_empty",
            ReactionType = ReactionType.ResetTrigger,
            GenericVar1 = 0,
        };
        var reaction = new Reaction(tpl);
        reaction.SetCoid(90012, false);
        reaction.SetMap(map);

        Assert.IsTrue(reaction.TriggerIfPossible(vehicle));
    }

    private static (Character Character, Vehicle Vehicle, SectorMap Map) CreatePlayer()
    {
        var continent = new ContinentObject
        {
            Id = 900,
            MapFileName = "tm_addxp_reset",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);

        var character = new Character();
        character.SetCoid(350, true);
        character.SetOwningConnection(connection);
        connection.CurrentCharacter = character;

        var vehicle = new Vehicle();
        vehicle.SetCoid(351, true);
        character.SetCurrentVehicleForTests(vehicle);

        character.SetMap(map);
        vehicle.SetMap(map);
        return (character, vehicle, map);
    }
}
