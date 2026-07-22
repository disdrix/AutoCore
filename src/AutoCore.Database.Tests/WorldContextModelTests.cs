using System.ComponentModel.DataAnnotations.Schema;
using System.Reflection;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.World;
using AutoCore.Database.World.Models;

[TestClass]
public class WorldContextModelTests
{
    private static WorldContext CreateContext(string? name = null)
        => new(TestHelpers.CreateInMemoryOptions<WorldContext>(name));

    [TestMethod]
    public void EnsureCreated_CreatesSchema()
    {
        var options = TestHelpers.CreateInMemoryOptions<WorldContext>();
        WorldContext.EnsureCreated(options);

        using var context = new WorldContext(options);
        Assert.IsTrue(context.Database.CanConnect());
        Assert.IsNotNull(context.Model.FindEntityType(typeof(ConfigNewCharacter)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(ContinentArea)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(ContinentObject)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(ExperienceLevel)));
    }

    [TestMethod]
    public void OnModelCreating_ConfiguresCompositeKeys()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        var config = context.Model.FindEntityType(typeof(ConfigNewCharacter));
        Assert.IsNotNull(config);
        CollectionAssert.AreEqual(
            new[] { nameof(ConfigNewCharacter.Race), nameof(ConfigNewCharacter.Class) },
            config!.FindPrimaryKey()!.Properties.Select(p => p.Name).ToArray());

        var area = context.Model.FindEntityType(typeof(ContinentArea));
        Assert.IsNotNull(area);
        CollectionAssert.AreEqual(
            new[] { nameof(ContinentArea.ContinentObjectId), nameof(ContinentArea.Area) },
            area!.FindPrimaryKey()!.Properties.Select(p => p.Name).ToArray());
    }

    [TestMethod]
    public void TableNames_MatchRetailSchema()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        Assert.IsNotNull(context.Model.FindEntityType(typeof(ConfigNewCharacter)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(ContinentArea)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(ContinentObject)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(ExperienceLevel)));

        Assert.AreEqual("config_new_character", typeof(ConfigNewCharacter).GetCustomAttribute<TableAttribute>()!.Name);
        Assert.AreEqual("continent_area", typeof(ContinentArea).GetCustomAttribute<TableAttribute>()!.Name);
        Assert.AreEqual("continent_object", typeof(ContinentObject).GetCustomAttribute<TableAttribute>()!.Name);
        Assert.AreEqual("experience_level", typeof(ExperienceLevel).GetCustomAttribute<TableAttribute>()!.Name);
        Assert.AreEqual("creature_experience_level", typeof(CreatureExperienceLevel).GetCustomAttribute<TableAttribute>()!.Name);
        Assert.AreEqual("quest_xp_lookup", typeof(QuestXpLookup).GetCustomAttribute<TableAttribute>()!.Name);
    }

    [TestMethod]
    public void ConfigNewCharacter_RoundTrip()
    {
        var options = TestHelpers.CreateInMemoryOptions<WorldContext>();
        using (var context = new WorldContext(options))
        {
            context.Database.EnsureCreated();
            context.ConfigNewCharacters.Add(new ConfigNewCharacter
            {
                Race = 1,
                Class = 2,
                OptionCode = 3,
                PowerPlant = 100,
                Armor = 101,
                RaceItem = 102,
                SkillBattleMode1 = 1,
                SkillBattleMode2 = 2,
                SkillBattleMode3 = 3,
                StartSkill = 4,
                StartTown = 50,
                Trailer = 60,
                Vehicle = 70,
                Weapon = 80,
            });
            context.SaveChanges();
        }

        using (var context = new WorldContext(options))
        {
            var row = context.ConfigNewCharacters.Single(c => c.Race == 1 && c.Class == 2);
            Assert.AreEqual(100, row.PowerPlant);
            Assert.AreEqual(50, row.StartTown);
            Assert.AreEqual(80, row.Weapon);
            Assert.AreEqual(4u, row.StartSkill);
        }
    }

    [TestMethod]
    public void ContinentArea_RoundTrip()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        context.ContinentAreas.Add(new ContinentArea
        {
            ContinentObjectId = 12,
            Area = 3,
            XPLevel = 25,
            AreaName = "Wasteland",
        });
        context.SaveChanges();

        var loaded = context.ContinentAreas.Single();
        Assert.AreEqual(25, loaded.XPLevel);
        Assert.AreEqual("Wasteland", loaded.AreaName);
    }

    [TestMethod]
    public void ContinentObject_RoundTrip()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        context.ContinentObjects.Add(new ContinentObject
        {
            Id = 1,
            ContestedMission = 2,
            Coordinates = 3,
            DisplayName = "Plateau",
            Image = 4,
            MapFileName = "plateau.map",
            MinLevel = 1,
            MaxLevel = 50,
            MaxPlayers = 100,
            MinVersion = 0,
            MaxVersion = 99,
            Objective = 5,
            OwningFaction = 6,
            PositionX = 1.5f,
            PositionZ = 2.5f,
            Rotation = 0.25f,
            IsPersistent = true,
            IsTown = true,
            IsClientOnly = false,
            IsArena = false,
            PlayCreateSounds = true,
            DropCommodities = true,
            DropBrokenItems = false,
        });
        context.SaveChanges();

        var loaded = context.ContinentObjects.Single(c => c.Id == 1);
        Assert.AreEqual("Plateau", loaded.DisplayName);
        Assert.AreEqual("plateau.map", loaded.MapFileName);
        Assert.IsTrue(loaded.IsPersistent);
        Assert.IsTrue(loaded.IsTown);
        Assert.AreEqual(1.5f, loaded.PositionX);
        Assert.AreEqual(2.5f, loaded.PositionZ);
    }

    [TestMethod]
    public void ExperienceLevel_RoundTrip()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        context.ExperienceLevels.Add(new ExperienceLevel
        {
            Level = 5,
            Experience = 12000,
            SkillPoints = 2,
            AttributePoints = 1,
            ResearchPoints = 0,
        });
        context.SaveChanges();

        var loaded = context.ExperienceLevels.Single(e => e.Level == 5);
        Assert.AreEqual(12000u, loaded.Experience);
        Assert.AreEqual((byte)2, loaded.SkillPoints);
        Assert.AreEqual((byte)1, loaded.AttributePoints);
    }

    [TestMethod]
    public void ExperienceLevel_PrimaryKey_IsLevel()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        var entity = context.Model.FindEntityType(typeof(ExperienceLevel));
        Assert.IsNotNull(entity);
        Assert.AreEqual(nameof(ExperienceLevel.Level), entity!.FindPrimaryKey()!.Properties[0].Name);
    }

    [TestMethod]
    public void OptionsConstructor_SkipsMySqlOnConfiguring()
    {
        using var context = CreateContext();
        Assert.IsTrue(context.Database.IsInMemory());
        context.Database.EnsureCreated();
    }

    [TestMethod]
    public void OptionsConstructor_ExposesDbSets()
    {
        using var context = CreateContext();
        Assert.IsNotNull(context.ConfigNewCharacters);
        Assert.IsNotNull(context.ContinentObjects);
        Assert.IsNotNull(context.ContinentAreas);
        Assert.IsNotNull(context.ExperienceLevels);
    }

    [TestMethod]
    public void WorldModels_NotOnContext_HaveKeysAndDefaults()
    {
        // These map classes exist for loaders / docs; not currently DbSet on WorldContext.
        var creature = new CreatureExperienceLevel { CreatureLevel = 10, Experience = 250 };
        Assert.AreEqual(10, creature.CreatureLevel);
        Assert.AreEqual(250, creature.Experience);

        var quest = new QuestXpLookup { Index = 3, LevelXpFraction = 0.25f };
        Assert.AreEqual(3, quest.Index);
        Assert.AreEqual(0.25f, quest.LevelXpFraction);

        var weight = new LootWeight { DestroyedCbid = 1, LootCbid = 2, Weight = 5 };
        Assert.AreEqual(1, weight.DestroyedCbid);
        Assert.AreEqual(2, weight.LootCbid);
        Assert.AreEqual((short)5, weight.Weight);

        var consumable = new ConsumableLootEntry
        {
            Cbid = 99,
            LevelMin = 1,
            LevelMax = 20,
            Offset = 7,
        };
        Assert.AreEqual(99, consumable.Cbid);
        Assert.AreEqual((short)1, consumable.LevelMin);
        Assert.AreEqual((short)20, consumable.LevelMax);
        Assert.AreEqual(7, consumable.Offset);
    }
}
