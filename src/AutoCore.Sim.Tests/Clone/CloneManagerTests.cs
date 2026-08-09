using System.Linq;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Sim.Clone;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Clone;

[TestClass]
public class CloneManagerTests
{
    private const int ChassisCbid = 810_001;
    private const int WheelsetCbid = 810_002;
    private const int DriverCbid = 810_003;

    [TestInitialize]
    public void Init()
    {
        AssetManagerTestHelper.ClearRegisteredCloneBases();
        AssetManagerTestHelper.RegisterCloneBase(WheelsetCbid, CloneBaseObjectType.WheelSet);
        AssetManagerTestHelper.RegisterVehicleCloneBase(
            ChassisCbid,
            defaultDriverCbid: DriverCbid,
            defaultWheelsetCbid: WheelsetCbid);
        AssetManagerTestHelper.RegisterCreatureCloneBase(DriverCbid, baseLevel: 5);
    }

    [TestCleanup]
    public void Cleanup()
    {
        AssetManagerTestHelper.ClearRegisteredCloneBases();
    }

    private static SectorMap CreateFieldMap(int continentId)
    {
        var continent = new AutoCore.Database.World.Models.ContinentObject
        {
            Id = continentId,
            MapFileName = $"tm_clone_{continentId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }

    private static Character DrivingCharacter(SectorMap map, long coid = 9001)
    {
        var vehicle = new Vehicle();
        vehicle.LoadCloneBase(ChassisCbid);
        vehicle.SetupCBFields();

        var character = new Character();
        character.GMLevel = 1;
        character.SetCoid(coid, true);
        character.SetCurrentVehicleForTests(vehicle);
        character.SetMap(map);
        return character;
    }

    [TestMethod]
    public void Toggle_NullCharacter_ReturnsNoCharacterMessage()
    {
        var manager = new CloneManager();

        var message = manager.Toggle(null);

        StringAssert.Contains(message, "No character");
    }

    [TestMethod]
    public void Toggle_OnFootInTown_ReturnsDrivingRequiredMessage()
    {
        var continent = new AutoCore.Database.World.Models.ContinentObject
        {
            Id = 8202,
            MapFileName = "tm_clone_town",
            DisplayName = "town",
            IsTown = true,
            IsPersistent = true,
        };
        var town = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
        var character = DrivingCharacter(town);
        var manager = new CloneManager();

        var message = manager.Toggle(character);

        StringAssert.Contains(message.ToLowerInvariant(), "driving");
        Assert.AreEqual(0, manager.ActiveCloneCount);
    }

    [TestMethod]
    public void Toggle_Driving_SpawnsCloneOnMap()
    {
        var map = CreateFieldMap(8203);
        var character = DrivingCharacter(map);
        var manager = new CloneManager();

        var message = manager.Toggle(character);

        Assert.AreEqual(1, manager.ActiveCloneCount, $"expected spawn, got: {message}");
        var clone = map.Objects.Values.OfType<Vehicle>().Single(v => v != character.CurrentVehicle);
        Assert.AreEqual(ChassisCbid, clone.CBID);
        Assert.IsNotNull(clone.WheelSet, "clone must carry a wheelset for the client renderer");
        Assert.IsTrue(MapNpcIdentity.IsMapNpcIdentity(clone.ObjectId),
            "clone must use the map-NPC global COID namespace");
        Assert.IsTrue(map.NpcAiEntities.Contains(clone),
            "clone must register in NpcAiEntities (NpcAi assigned before SetMap)");
        Assert.IsTrue(clone.IsInvincible, "clone must be excluded from combat damage");
    }

    [TestMethod]
    public void Toggle_SecondCall_DespawnsClone()
    {
        var map = CreateFieldMap(8204);
        var character = DrivingCharacter(map);
        var manager = new CloneManager();

        manager.Toggle(character);
        var message = manager.Toggle(character);

        Assert.AreEqual(0, manager.ActiveCloneCount, $"expected despawn, got: {message}");
        Assert.AreEqual(0, map.Objects.Values.OfType<Vehicle>().Count(v => v != character.CurrentVehicle));
        Assert.AreEqual(0, map.NpcAiEntities.OfType<Vehicle>().Count());
    }

    [TestMethod]
    public void Tick_OwnerLeftMap_DespawnsClone()
    {
        var map = CreateFieldMap(8205);
        var character = DrivingCharacter(map);
        var manager = new CloneManager();

        manager.Toggle(character);
        character.SetMap(null);
        manager.Tick(nowMs: 0, dt: 0.05f);

        Assert.AreEqual(0, manager.ActiveCloneCount);
        Assert.AreEqual(0, map.Objects.Values.OfType<Vehicle>().Count(v => v != character.CurrentVehicle));
    }

    [TestMethod]
    public void Toggle_TwoPlayers_HaveIndependentClones()
    {
        var map = CreateFieldMap(8206);
        var first = DrivingCharacter(map, coid: 9001);
        var second = DrivingCharacter(map, coid: 9002);
        var manager = new CloneManager();

        manager.Toggle(first);
        manager.Toggle(second);

        Assert.AreEqual(2, manager.ActiveCloneCount);

        manager.Toggle(first);

        Assert.AreEqual(1, manager.ActiveCloneCount);
    }
}
