using System.ComponentModel.DataAnnotations.Schema;
using System.Reflection;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.Char;
using AutoCore.Database.Char.Models;

[TestClass]
public class CharContextModelTests
{
    private static CharContext CreateContext(string? name = null)
        => new(TestHelpers.CreateInMemoryOptions<CharContext>(name));

    [TestMethod]
    public void EnsureCreated_CreatesSchemaAndRunsMigrationsSafely()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();
        // Schema ALTER/CREATE SQL is MySQL-specific; InMemory path is swallowed by TryExecute.
        CharContext.EnsureCreated(options);

        using var context = new CharContext(options);
        Assert.IsTrue(context.Database.CanConnect());
        Assert.IsNotNull(context.Model.FindEntityType(typeof(CharacterData)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(VehicleData)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(SimpleObjectData)));
    }

    [TestMethod]
    public void EnsureSchemaMethods_AreIdempotent_OnInMemory()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        context.EnsureInventorySchema();
        context.EnsureCharacterEconomySchema();
        context.EnsureCharacterProgressSchema();
        context.EnsureMissionSchema();
        context.EnsureSkillSchema();
        context.EnsureVehicleCombatStateSchema();

        // Second pass still must not throw (duplicate-column path).
        context.EnsureInventorySchema();
        context.EnsureCharacterEconomySchema();
        context.EnsureCharacterProgressSchema();
        context.EnsureMissionSchema();
        context.EnsureSkillSchema();
        context.EnsureVehicleCombatStateSchema();
    }

    [TestMethod]
    public void OnModelCreating_ConfiguresCompositeKeys()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        AssertCompositeKey(context, typeof(CharacterExploration),
            nameof(CharacterExploration.CharacterCoid), nameof(CharacterExploration.ContinentId));
        AssertCompositeKey(context, typeof(CharacterQuestData),
            nameof(CharacterQuestData.CharacterCoid), nameof(CharacterQuestData.MissionId));
        AssertCompositeKey(context, typeof(CharacterCompletedMissionData),
            nameof(CharacterCompletedMissionData.CharacterCoid), nameof(CharacterCompletedMissionData.MissionId));
        AssertCompositeKey(context, typeof(CharacterSocial),
            nameof(CharacterSocial.CharacterCoid), nameof(CharacterSocial.TargetCoid));
        AssertCompositeKey(context, typeof(ClanMember),
            nameof(ClanMember.ClanId), nameof(ClanMember.CharacterCoid));
        AssertCompositeKey(context, typeof(CharacterLearnedSkillData),
            nameof(CharacterLearnedSkillData.CharacterCoid), nameof(CharacterLearnedSkillData.SkillId));
        AssertCompositeKey(context, typeof(CharacterQuickBarSlotData),
            nameof(CharacterQuickBarSlotData.CharacterCoid), nameof(CharacterQuickBarSlotData.Slot));
    }

    [TestMethod]
    public void OnModelCreating_ConfiguresInventoryIndexes()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        var entity = context.Model.FindEntityType(typeof(CharacterInventoryData));
        Assert.IsNotNull(entity);

        var indexes = entity!.GetIndexes().ToList();
        Assert.IsTrue(
            indexes.Any(i => i.IsUnique && i.Properties.Count == 1 && i.Properties[0].Name == nameof(CharacterInventoryData.ItemCoid)),
            "Expected unique index on ItemCoid.");
        Assert.IsTrue(
            indexes.Any(i => !i.IsUnique && i.Properties.Count == 1 && i.Properties[0].Name == nameof(CharacterInventoryData.CharacterCoid)),
            "Expected non-unique index on CharacterCoid.");
    }

    [TestMethod]
    public void TableNames_MatchRetailSchema()
    {
        // InMemory does not always surface relational table names; assert [Table] attributes
        // (what EF uses under MySQL) and that each type is present on the model.
        using var context = CreateContext();
        context.Database.EnsureCreated();

        AssertTable(context, typeof(CharacterData), "character");
        AssertTable(context, typeof(VehicleData), "vehicle");
        AssertTable(context, typeof(SimpleObjectData), "simple_object");
        AssertTable(context, typeof(CharacterInventoryData), "character_inventory");
        AssertTable(context, typeof(CharacterQuestData), "character_mission");
        AssertTable(context, typeof(CharacterCompletedMissionData), "character_mission_completed");
        AssertTable(context, typeof(CharacterExploration), "character_exploration");
        AssertTable(context, typeof(CharacterSocial), "character_social");
        AssertTable(context, typeof(CharacterLearnedSkillData), "character_learned_skill");
        AssertTable(context, typeof(CharacterQuickBarSlotData), "character_quickbar");
        AssertTable(context, typeof(Clan), "clan");
        AssertTable(context, typeof(ClanMember), "clan_member");
        AssertTable(context, typeof(Account), "account");
    }

    private static void AssertTable(DbContext context, Type clrType, string tableName)
    {
        Assert.IsNotNull(context.Model.FindEntityType(clrType), $"Missing entity {clrType.Name}");
        Assert.AreEqual(tableName, clrType.GetCustomAttribute<TableAttribute>()!.Name, clrType.Name);
    }

    [TestMethod]
    public void Account_RoundTrip()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        context.Accounts.Add(new Account
        {
            Id = 42,
            Name = "player1",
            Level = 5,
            FirstFlags1 = 1,
            FirstFlags2 = 2,
            FirstFlags3 = 3,
            FirstFlags4 = 4,
        });
        context.SaveChanges();

        var loaded = context.Accounts.Single(a => a.Id == 42);
        Assert.AreEqual("player1", loaded.Name);
        Assert.AreEqual((byte)5, loaded.Level);
        Assert.AreEqual(1u, loaded.FirstFlags1);
    }

    [TestMethod]
    public void CompositeKeyEntities_RoundTrip()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();
        using (var context = new CharContext(options))
        {
            context.Database.EnsureCreated();

            context.CharacterExplorations.Add(new CharacterExploration
            {
                CharacterCoid = 100,
                ContinentId = 7,
                ExploredBits = 0xF00Du,
            });
            context.CharacterQuests.Add(new CharacterQuestData
            {
                CharacterCoid = 100,
                MissionId = 55,
                ActiveObjectiveSequence = 2,
                State = 1,
                ObjectiveProgress = new byte[] { 1, 0, 0, 0 },
            });
            context.CharacterCompletedMissions.Add(new CharacterCompletedMissionData
            {
                CharacterCoid = 100,
                MissionId = 10,
            });
            context.CharacterLearnedSkills.Add(new CharacterLearnedSkillData
            {
                CharacterCoid = 100,
                SkillId = 9001,
                Rank = 3,
            });
            context.CharacterQuickBarSlots.Add(new CharacterQuickBarSlotData
            {
                CharacterCoid = 100,
                Slot = 4,
                ItemCoid = 555,
                SkillId = 12,
            });
            context.SaveChanges();
        }

        using (var context = new CharContext(options))
        {
            var exploration = context.CharacterExplorations.Single();
            Assert.AreEqual(0xF00Du, exploration.ExploredBits);

            var quest = context.CharacterQuests.Single();
            Assert.AreEqual((byte)2, quest.ActiveObjectiveSequence);
            Assert.AreEqual((byte)1, quest.State);
            CollectionAssert.AreEqual(new byte[] { 1, 0, 0, 0 }, quest.ObjectiveProgress);

            Assert.AreEqual(10, context.CharacterCompletedMissions.Single().MissionId);
            Assert.AreEqual((byte)3, context.CharacterLearnedSkills.Single().Rank);
            Assert.AreEqual(555L, context.CharacterQuickBarSlots.Single().ItemCoid);
        }
    }

    [TestMethod]
    public void ClanAndMember_RoundTrip_WithRelationship()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();
        using (var context = new CharContext(options))
        {
            context.Database.EnsureCreated();

            var clan = new Clan
            {
                Id = 9,
                Name = "Raiders",
                MOTD = "hello",
                Rank1 = "Recruit",
                Rank2 = "Officer",
                Rank3 = "Leader",
                MonthlyDues = 100,
                MonthlyUpkeep = 50,
            };
            context.Clans.Add(clan);
            context.ClanMembers.Add(new ClanMember
            {
                ClanId = 9,
                CharacterCoid = 1001,
                Rank = 2,
            });
            context.SaveChanges();
        }

        using (var context = new CharContext(options))
        {
            var clan = context.Clans.Include(c => c.Members).Single(c => c.Id == 9);
            Assert.AreEqual("Raiders", clan.Name);
            Assert.AreEqual("hello", clan.MOTD);
            Assert.AreEqual(1, clan.Members.Count);
            Assert.AreEqual(1001L, clan.Members[0].CharacterCoid);
            Assert.AreEqual(2, clan.Members[0].Rank);
        }
    }

    [TestMethod]
    public void CharacterSocial_SocialType_MapsToByte()
    {
        var social = new CharacterSocial
        {
            CharacterCoid = 1,
            TargetCoid = 2,
            SocialType = SocialType.Enemy,
        };

        Assert.AreEqual((byte)SocialType.Enemy, social.Type);
        social.Type = (byte)SocialType.Friend;
        Assert.AreEqual(SocialType.Friend, social.SocialType);
    }

    [TestMethod]
    public void CharacterSocial_RoundTrip()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();
        using (var context = new CharContext(options))
        {
            context.Database.EnsureCreated();
            // Avoid circular FK graph: seed social without navigation materialization.
            context.CharacterSocials.Add(new CharacterSocial
            {
                CharacterCoid = 10,
                TargetCoid = 20,
                Type = (byte)SocialType.Friend,
            });
            context.SaveChanges();
        }

        using (var context = new CharContext(options))
        {
            var social = context.CharacterSocials.Single();
            Assert.AreEqual(SocialType.Friend, social.SocialType);
            Assert.AreEqual(10L, social.CharacterCoid);
            Assert.AreEqual(20L, social.TargetCoid);
        }
    }

    [TestMethod]
    public void Clan_DefaultConstructor_SetsSentinels()
    {
        var clan = new Clan();
        Assert.AreEqual(-1, clan.Id);
        Assert.AreEqual("", clan.Name);

        var member = new ClanMember();
        Assert.AreEqual(-1, member.ClanId);
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
        Assert.IsNotNull(context.Characters);
        Assert.IsNotNull(context.Vehicles);
        Assert.IsNotNull(context.SimpleObjects);
        Assert.IsNotNull(context.CharacterInventories);
        Assert.IsNotNull(context.Clans);
    }

    private static void AssertCompositeKey(DbContext context, Type clrType, params string[] propertyNames)
    {
        var entity = context.Model.FindEntityType(clrType);
        Assert.IsNotNull(entity, $"Missing entity type {clrType.Name}");
        var key = entity!.FindPrimaryKey();
        Assert.IsNotNull(key, $"Missing PK for {clrType.Name}");
        CollectionAssert.AreEqual(
            propertyNames,
            key!.Properties.Select(p => p.Name).ToArray(),
            $"Unexpected PK for {clrType.Name}");
    }
}
