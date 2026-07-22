using System.Reflection;
using System.Runtime.CompilerServices;
using AutoCore.Database.World.Models;
using AutoCore.Game.CloneBases;
using AutoCore.Game.Constants;
using AutoCore.Game.Managers;
using AutoCore.Game.Managers.Asset;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Inventory.Fakes;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using GameMission = AutoCore.Game.Mission.Mission;
using GameMissionObjective = AutoCore.Game.Mission.MissionObjective;

namespace AutoCore.Game.Tests.Managers.Asset;

/// <summary>
/// Soft-fail / test-helper paths on <see cref="AssetManager"/> without loading full WAD/GLM.
/// </summary>
[TestClass]
public class AssetManagerSoftPathTests
{
    private string _savedGamePath;
    private ServerType _savedServerType;
    private bool _savedDataLoaded;
    private bool _savedAllowMissing;

    [TestInitialize]
    public void SetUp()
    {
        var am = AssetManager.Instance;
        _savedGamePath = am.GamePath;
        _savedServerType = am.ServerType;
        _savedAllowMissing = am.AllowMissingCBID;
        _savedDataLoaded = GetDataLoaded();

        AssetManagerTestHelper.ClearRegisteredCloneBases();
        am.ClearTestNpcData();
        am.ClearTestMissions();
        am.ClearTestSkills();
        ClearWorldDbTables();
    }

    [TestCleanup]
    public void TearDown()
    {
        var am = AssetManager.Instance;
        AssetManagerTestHelper.ClearRegisteredCloneBases();
        am.ClearTestNpcData();
        am.ClearTestMissions();
        am.ClearTestSkills();
        ClearWorldDbTables();

        SetGamePath(_savedGamePath);
        SetServerType(_savedServerType);
        am.AllowMissingCBID = _savedAllowMissing;
        SetDataLoaded(_savedDataLoaded);
    }

    // --- Initialize soft-fail ---

    [TestMethod]
    public void Initialize_MissingDirectory_ReturnsFalse()
    {
        var path = Path.Combine(Path.GetTempPath(), "autocore-missing-" + Guid.NewGuid().ToString("N"));
        Assert.IsFalse(AssetManager.Instance.Initialize(path, ServerType.Sector));
    }

    [TestMethod]
    public void Initialize_MissingExe_ReturnsFalse()
    {
        var path = Path.Combine(Path.GetTempPath(), "autocore-noexe-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(path);
        try
        {
            Assert.IsFalse(AssetManager.Instance.Initialize(path, ServerType.Global, allowMissingCBID: true));
            Assert.IsTrue(AssetManager.Instance.AllowMissingCBID);
        }
        finally
        {
            Directory.Delete(path, recursive: true);
        }
    }

    [TestMethod]
    public void Initialize_ValidLayout_ReturnsTrue()
    {
        var path = Path.Combine(Path.GetTempPath(), "autocore-valid-" + Guid.NewGuid().ToString("N"));
        var exeDir = Path.Combine(path, "exe");
        Directory.CreateDirectory(exeDir);
        File.WriteAllText(Path.Combine(exeDir, "autoassault.exe"), "stub");
        try
        {
            Assert.IsTrue(AssetManager.Instance.Initialize(path, ServerType.Both));
            Assert.AreEqual(path, AssetManager.Instance.GamePath);
            Assert.AreEqual(ServerType.Both, AssetManager.Instance.ServerType);
        }
        finally
        {
            Directory.Delete(path, recursive: true);
        }
    }

    [TestMethod]
    public void LoadAllData_WhenAlreadyLoaded_ReturnsFalse()
    {
        SetDataLoaded(true);
        Assert.IsFalse(AssetManager.Instance.LoadAllData());
    }

    // --- Skill / mission test overrides ---

    [TestMethod]
    public void SetTestSkill_TakesPrecedence()
    {
        var skill = new Skill { Id = 2103 };
        AssetManager.Instance.SetTestSkill(skill);
        AssetManager.Instance.SetTestSkill(null); // ignored

        Assert.AreSame(skill, AssetManager.Instance.GetSkill(2103));
        Assert.IsNull(AssetManager.Instance.GetSkill(999));

        AssetManager.Instance.ClearTestSkills();
        Assert.IsNull(AssetManager.Instance.GetSkill(2103));
    }

    [TestMethod]
    public void SetTestMission_LookupByIdAndObjective()
    {
        var objective = GameMissionObjective.CreateForTests(501, sequence: 0, questId: 500);
        var mission = GameMission.CreateForTests(500, objective);
        AssetManager.Instance.SetTestMission(mission);
        AssetManager.Instance.SetTestMission(null); // ignored

        Assert.AreSame(mission, AssetManager.Instance.GetMission(500));
        Assert.AreSame(mission, AssetManager.Instance.GetMissionByObjectiveId(501));
        Assert.AreSame(objective, AssetManager.Instance.GetObjectiveById(501));
        Assert.IsNull(AssetManager.Instance.GetMission(404));
        Assert.IsNull(AssetManager.Instance.GetMissionByObjectiveId(404));
        Assert.IsNull(AssetManager.Instance.GetObjectiveById(404));

        var all = AssetManager.Instance.GetAllMissions().ToList();
        Assert.IsTrue(all.Any(m => m.Id == 500));
    }

    // --- CloneBase accessors ---

    [TestMethod]
    public void GetCloneBase_Registered_ReturnsTyped()
    {
        AssetManagerTestHelper.RegisterCloneBase(12001, CloneBaseObjectType.Item);
        Assert.IsNotNull(AssetManager.Instance.GetCloneBase(12001));
        Assert.IsNotNull(AssetManager.Instance.GetCloneBase<CloneBaseObject>(12001));
        Assert.IsNull(AssetManager.Instance.GetCloneBase(12002));
        Assert.IsNull(AssetManager.Instance.GetCloneBase<CloneBaseVehicle>(12001));
    }

    [TestMethod]
    public void GetAllCharacterCBIDs_IncludesRegisteredCharacter()
    {
        AssetManagerTestHelper.RegisterCharacterCloneBase(12100, race: 0, classId: 1);
        var ids = AssetManager.Instance.GetAllCharacterCBIDs();
        Assert.IsTrue(ids.Contains(12100));
    }

    [TestMethod]
    public void GetAllCloneBases_ContainsRegistered()
    {
        AssetManagerTestHelper.RegisterCloneBase(12200, CloneBaseObjectType.Item);
        Assert.IsTrue(AssetManager.Instance.GetAllCloneBases().ContainsKey(12200));
    }

    // --- WorldDB soft nulls ---

    [TestMethod]
    public void WorldDbAccessors_NullTables_ReturnDefaults()
    {
        ClearWorldDbTables();

        Assert.IsNull(AssetManager.Instance.GetContinentObject(1));
        Assert.IsNull(AssetManager.Instance.GetExperienceLevel(1));
        Assert.AreEqual(0u, AssetManager.Instance.GetExperienceThreshold(1));
        Assert.AreEqual(0, AssetManager.Instance.GetCreatureExperience(1));
        Assert.AreEqual(0f, AssetManager.Instance.GetQuestXpFraction(1));
        Assert.AreEqual(0f, AssetManager.Instance.GetQuestCreditsFraction(1));
        Assert.AreEqual(0, AssetManager.Instance.GetQuestBaseCredits(1));
        Assert.AreEqual(0, AssetManager.Instance.GetContinentAreaXpLevel(1, 1));
        Assert.IsFalse(AssetManager.Instance.GetContinentObjects().Any());
        Assert.IsNull(AssetManager.Instance.GetMapData(1));
        Assert.IsFalse(AssetManager.Instance.GetAllLootTables().Any());
        Assert.IsNull(AssetManager.Instance.GetLootTable(1));
        Assert.IsNull(AssetManager.Instance.GetVehicleTemplate(1));
        Assert.IsNull(AssetManager.Instance.GetCreatureAiProfile(1));
        Assert.AreEqual(0, AssetManager.Instance.GetLootWeightsForDestroyed(1).Count);
        Assert.AreEqual(0, AssetManager.Instance.GetConsumables().Count);
        Assert.AreEqual(0, AssetManager.Instance.GetAllAvailableConfigs().Count);
    }

    [TestMethod]
    public void WorldDbAccessors_WhenSeeded_ReturnValues()
    {
        var loader = GetWorldDbLoader();
        loader.ContinentObjects = new Dictionary<int, ContinentObject>
        {
            [10] = new ContinentObject { Id = 10, MapFileName = "tm_test", DisplayName = "t" },
        };
        loader.ExperienceLevels = new Dictionary<byte, ExperienceLevel>
        {
            [2] = new ExperienceLevel { Level = 2, Experience = 500 },
        };
        loader.CreatureExperienceLevels = new Dictionary<int, int> { [3] = 42 };
        loader.QuestXpLookup = new Dictionary<int, float> { [4] = 0.5f };
        loader.QuestCreditsLookup = new Dictionary<int, float> { [5] = 1.25f };
        loader.QuestBaseCredits = new Dictionary<int, int> { [6] = 99 };
        loader.ContinentAreas = new Dictionary<Tuple<int, byte>, ContinentArea>
        {
            [Tuple.Create(10, (byte)1)] = new ContinentArea { ContinentObjectId = 10, Area = 1, XPLevel = 2 },
        };
        loader.LootTables = new Dictionary<int, LootTable>
        {
            [7] = new LootTable { Id = 7, Name = "t" },
        };
        loader.VehicleTemplates = new Dictionary<int, VehicleTemplate>
        {
            [8] = new VehicleTemplate { Id = 8 },
        };
        loader.CreatureAiProfiles = new Dictionary<int, CreatureAiProfile>
        {
            [9] = new CreatureAiProfile { AiId = 9 },
        };
        loader.LootWeights = new Dictionary<int, IReadOnlyList<LootWeight>>
        {
            [11] = new List<LootWeight> { new() { DestroyedCbid = 11, LootCbid = 12, Weight = 1 } },
        };
        loader.Consumables = new List<ConsumableLootEntry>
        {
            new() { Cbid = 13, LevelMin = 1, LevelMax = 10, Offset = 1 },
        };
        loader.ConfigNewCharacters = new Dictionary<Tuple<byte, byte>, ConfigNewCharacter>
        {
            [Tuple.Create((byte)0, (byte)1)] = new ConfigNewCharacter { Race = 0, Class = 1, Vehicle = 1 },
        };

        Assert.AreEqual(10, AssetManager.Instance.GetContinentObject(10)!.Id);
        Assert.AreEqual(500u, AssetManager.Instance.GetExperienceThreshold(2));
        Assert.AreEqual(42, AssetManager.Instance.GetCreatureExperience(3));
        Assert.AreEqual(0.5f, AssetManager.Instance.GetQuestXpFraction(4));
        Assert.AreEqual(1.25f, AssetManager.Instance.GetQuestCreditsFraction(5));
        Assert.AreEqual(99, AssetManager.Instance.GetQuestBaseCredits(6));
        Assert.AreEqual(2, AssetManager.Instance.GetContinentAreaXpLevel(10, 1));
        Assert.IsTrue(AssetManager.Instance.GetContinentObjects().Any());
        Assert.AreEqual(7, AssetManager.Instance.GetLootTable(7)!.Id);
        Assert.IsTrue(AssetManager.Instance.GetAllLootTables().Any());
        Assert.AreEqual(8, AssetManager.Instance.GetVehicleTemplate(8)!.Id);
        Assert.AreEqual(9, AssetManager.Instance.GetCreatureAiProfile(9)!.AiId);
        Assert.AreEqual(1, AssetManager.Instance.GetLootWeightsForDestroyed(11).Count);
        Assert.AreEqual(1, AssetManager.Instance.GetConsumables().Count);
        Assert.IsTrue(AssetManager.Instance.GetAllAvailableConfigs().Count > 0);
    }

    [TestMethod]
    public void SetTestNpcData_OverridesWorldDb()
    {
        AssetManager.Instance.SetTestLootTables(new[] { new LootTable { Id = 70, Name = "x" } });
        AssetManager.Instance.SetTestVehicleTemplates(new[] { new VehicleTemplate { Id = 71 } });
        AssetManager.Instance.SetTestCreatureAiProfiles(new[] { new CreatureAiProfile { AiId = 72 } });
        AssetManager.Instance.SetTestLootWeights(new[]
        {
            new LootWeight { DestroyedCbid = 73, LootCbid = 74, Weight = 5 },
        });
        AssetManager.Instance.SetTestConsumables(new[]
        {
            new ConsumableLootEntry { Cbid = 75, LevelMin = 1, LevelMax = 5, Offset = 2 },
        });
        // null enumerables ignored
        AssetManager.Instance.SetTestLootTables(null);
        AssetManager.Instance.SetTestVehicleTemplates(null);
        AssetManager.Instance.SetTestCreatureAiProfiles(null);
        AssetManager.Instance.SetTestLootWeights(null);
        AssetManager.Instance.SetTestConsumables(null);

        Assert.AreEqual(70, AssetManager.Instance.GetLootTable(70)!.Id);
        Assert.AreEqual(71, AssetManager.Instance.GetVehicleTemplate(71)!.Id);
        Assert.AreEqual(72, AssetManager.Instance.GetCreatureAiProfile(72)!.AiId);
        Assert.AreEqual(1, AssetManager.Instance.GetLootWeightsForDestroyed(73).Count);
        Assert.AreEqual(1, AssetManager.Instance.GetConsumables().Count);

        AssetManager.Instance.ClearTestNpcData();
        Assert.IsNull(AssetManager.Instance.GetLootTable(70));
    }

    [TestMethod]
    public void GetContinentObjectFromWad_NoGamePath_ReturnsNull()
    {
        SetGamePath(null);
        Assert.IsNull(AssetManager.Instance.GetContinentObjectFromWad(1));

        SetGamePath(Path.Combine(Path.GetTempPath(), "no-wad-" + Guid.NewGuid().ToString("N")));
        Assert.IsNull(AssetManager.Instance.GetContinentObjectFromWad(1));
    }

    [TestMethod]
    public void GetConfigNewCharacterFor_WrongServerType_Throws()
    {
        SetServerType(ServerType.Sector);
        Assert.ThrowsException<Exception>(() =>
            AssetManager.Instance.GetConfigNewCharacterFor(0, 1));
        Assert.ThrowsException<Exception>(() =>
            AssetManager.Instance.GetConfigNewCharacterFallback(0, 1));
    }

    [TestMethod]
    public void GetConfigNewCharacterFor_Global_NullTables_ReturnsNull()
    {
        SetServerType(ServerType.Global);
        ClearWorldDbTables();
        Assert.IsNull(AssetManager.Instance.GetConfigNewCharacterFor(0, 1));
        Assert.IsNull(AssetManager.Instance.GetConfigNewCharacterFallback(0, 1));
    }

    [TestMethod]
    public void GetConfigNewCharacterFallback_PicksSameRaceThenAny()
    {
        SetServerType(ServerType.Both);
        var loader = GetWorldDbLoader();
        loader.ConfigNewCharacters = new Dictionary<Tuple<byte, byte>, ConfigNewCharacter>
        {
            [Tuple.Create((byte)1, (byte)9)] = new ConfigNewCharacter { Race = 1, Class = 9, Vehicle = 1 },
            [Tuple.Create((byte)2, (byte)3)] = new ConfigNewCharacter { Race = 2, Class = 3, Vehicle = 2 },
        };

        var sameRace = AssetManager.Instance.GetConfigNewCharacterFallback(1, 0);
        Assert.IsNotNull(sameRace);
        Assert.AreEqual(1, sameRace.Race);

        var sameClass = AssetManager.Instance.GetConfigNewCharacterFallback(99, 3);
        Assert.IsNotNull(sameClass);
        Assert.AreEqual(3, sameClass.Class);

        var any = AssetManager.Instance.GetConfigNewCharacterFallback(99, 99);
        Assert.IsNotNull(any);
    }

    [TestMethod]
    public void GenerateConfigFromGameData_MissingPieces_ReturnsNull()
    {
        // Empty clonebases (after clear) → null
        AssetManagerTestHelper.ClearRegisteredCloneBases();
        Assert.IsNull(AssetManager.Instance.GenerateConfigFromGameData(0, 1));
    }

    [TestMethod]
    public void GenerateConfigFromGameData_WithPartsButNoMaps_ReturnsNull()
    {
        AssetManagerTestHelper.RegisterVehicleCloneBase(13001);
        AssetManagerTestHelper.RegisterPowerPlantCloneBase(13002);
        AssetManagerTestHelper.RegisterArmorCloneBase(13003);
        AssetManagerTestHelper.RegisterCloneBase(13004, CloneBaseObjectType.Weapon);
        AssetManagerTestHelper.RegisterCloneBase(13005, CloneBaseObjectType.Item);

        // MapDatas empty → null after finding gear
        Assert.IsNull(AssetManager.Instance.GenerateConfigFromGameData(0, 1));
    }

    [TestMethod]
    public void GenerateConfigFromGameData_WithPartsAndMap_ReturnsConfig()
    {
        AssetManagerTestHelper.RegisterVehicleCloneBase(13101);
        AssetManagerTestHelper.RegisterPowerPlantCloneBase(13102);
        AssetManagerTestHelper.RegisterArmorCloneBase(13103);
        AssetManagerTestHelper.RegisterCloneBase(13104, CloneBaseObjectType.Weapon);
        AssetManagerTestHelper.RegisterCloneBase(13105, CloneBaseObjectType.Item);

        var mapLoader = GetMapDataLoader();
        var mapDatas = mapLoader.MapDatas;
        // MapDatas may be null or a dictionary — inject a dummy if possible
        if (mapDatas == null)
        {
            var dict = new Dictionary<int, MapData>();
            // MapData may be hard to construct — use RuntimeHelpers if needed
            try
            {
                var md = (MapData)RuntimeHelpers.GetUninitializedObject(typeof(MapData));
                dict[42] = md;
                typeof(MapDataLoader)
                    .GetProperty(nameof(MapDataLoader.MapDatas))!
                    .SetValue(mapLoader, dict);
            }
            catch
            {
                Assert.Inconclusive("Could not inject MapData for GenerateConfig test");
                return;
            }
        }
        else if (mapDatas.Count == 0)
        {
            try
            {
                var md = (MapData)RuntimeHelpers.GetUninitializedObject(typeof(MapData));
                // If MapDatas is IDictionary or Dictionary
                if (mapDatas is IDictionary<int, MapData> d)
                    d[42] = md;
                else
                {
                    Assert.Inconclusive("MapDatas not mutable");
                    return;
                }
            }
            catch
            {
                Assert.Inconclusive("Could not inject MapData");
                return;
            }
        }

        try
        {
            var config = AssetManager.Instance.GenerateConfigFromGameData(0, 1);
            Assert.IsNotNull(config);
            Assert.AreEqual(13101, config.Vehicle);
            Assert.AreEqual(13102, config.PowerPlant);
            Assert.AreEqual(13103, config.Armor);
            Assert.AreEqual(13104, config.Weapon);
            Assert.AreEqual(13105, config.RaceItem);
            Assert.IsTrue(config.StartTown >= 0);
        }
        finally
        {
            // Leave map loader as-is; other tests tolerate extra map ids.
        }
    }

    [TestMethod]
    public void GlmHelpers_MissingFile_Safe()
    {
        Assert.IsFalse(AssetManager.Instance.HasFileInGLMs("definitely-not-here.xyz"));
    }

    [TestMethod]
    public void GetMissionsForContinent_AndAutoAssign_EmptyWad_Empty()
    {
        // Without WAD missions these are empty enumerables
        Assert.IsNotNull(AssetManager.Instance.GetMissionsForContinent(1));
        Assert.IsNotNull(AssetManager.Instance.GetAutoAssignMissions());
    }

    // --- helpers ---

    private static bool GetDataLoaded()
    {
        var prop = typeof(AssetManager).GetProperty(
            "DataLoaded", BindingFlags.Instance | BindingFlags.NonPublic);
        return (bool)(prop?.GetValue(AssetManager.Instance) ?? false);
    }

    private static void SetDataLoaded(bool value)
    {
        var prop = typeof(AssetManager).GetProperty(
            "DataLoaded", BindingFlags.Instance | BindingFlags.NonPublic);
        prop?.SetValue(AssetManager.Instance, value);
    }

    private static void SetGamePath(string path)
    {
        var prop = typeof(AssetManager).GetProperty(
            nameof(AssetManager.GamePath),
            BindingFlags.Instance | BindingFlags.Public);
        prop?.SetValue(AssetManager.Instance, path);
    }

    private static void SetServerType(ServerType type)
    {
        var prop = typeof(AssetManager).GetProperty(
            nameof(AssetManager.ServerType),
            BindingFlags.Instance | BindingFlags.Public);
        prop?.SetValue(AssetManager.Instance, type);
    }

    private static WorldDBLoader GetWorldDbLoader()
    {
        var prop = typeof(AssetManager).GetProperty(
            "WorldDBLoader",
            BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
        return (WorldDBLoader)prop!.GetValue(AssetManager.Instance)!;
    }

    private static MapDataLoader GetMapDataLoader()
    {
        var prop = typeof(AssetManager).GetProperty(
            "MapDataLoader",
            BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
        return (MapDataLoader)prop!.GetValue(AssetManager.Instance)!;
    }

    private static void ClearWorldDbTables()
    {
        var loader = GetWorldDbLoader();
        loader.ContinentObjects = null;
        loader.ExperienceLevels = null;
        loader.CreatureExperienceLevels = null;
        loader.QuestXpLookup = null;
        loader.QuestCreditsLookup = null;
        loader.QuestBaseCredits = null;
        loader.ContinentAreas = null;
        loader.LootTables = null;
        loader.VehicleTemplates = null;
        loader.CreatureAiProfiles = null;
        loader.LootWeights = null;
        loader.Consumables = null;
        loader.ConfigNewCharacters = null;
    }
}
