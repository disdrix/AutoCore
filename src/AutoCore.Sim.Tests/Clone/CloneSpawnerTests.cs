using System.Linq;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Sim.Clone;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Clone;

[TestClass]
public class CloneSpawnerTests
{
    private const int ChassisCbid = 820_001;
    private const int DefaultWheelsetCbid = 820_002;
    private const int PlayerWheelsetCbid = 820_003;
    private const int ArmorCbid = 820_004;
    private const int FrontWeaponCbid = 820_005;
    private const int DriverCbid = 820_006;

    [TestInitialize]
    public void Init()
    {
        AssetManagerTestHelper.ClearRegisteredCloneBases();
        AssetManagerTestHelper.RegisterVehicleCloneBase(
            ChassisCbid,
            defaultDriverCbid: DriverCbid,
            defaultWheelsetCbid: DefaultWheelsetCbid);
        AssetManagerTestHelper.RegisterCloneBase(DefaultWheelsetCbid, CloneBaseObjectType.WheelSet);
        AssetManagerTestHelper.RegisterCloneBase(PlayerWheelsetCbid, CloneBaseObjectType.WheelSet);
        AssetManagerTestHelper.RegisterArmorCloneBase(ArmorCbid);
        AssetManagerTestHelper.RegisterCloneBase(FrontWeaponCbid, CloneBaseObjectType.Weapon);
        AssetManagerTestHelper.RegisterCreatureCloneBase(DriverCbid, baseLevel: 7);
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
            MapFileName = $"tm_clone_spawner_{continentId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }

    private static Character DrivingCharacter(SectorMap map)
    {
        var vehicle = new Vehicle();
        vehicle.LoadCloneBase(ChassisCbid);
        vehicle.SetupCBFields();

        var character = new Character();
        character.GMLevel = 1;
        character.SetCoid(9101, true);
        character.SetCurrentVehicleForTests(vehicle);
        character.SetMap(map);
        return character;
    }

    private static void Equip(Vehicle vehicle, SectorMap map, VehicleEquipmentSlot slot, SimpleObject item, int cbid)
    {
        var counter = map.LocalCoidCounter;
        var id = MapNpcIdentity.AllocateCoid(ref counter);
        map.LocalCoidCounter = counter;
        item.SetCoid(id.Coid, id.Global);
        item.LoadCloneBase(cbid);
        item.SetupCBFields();
        Assert.IsTrue(vehicle.TryEquipItem(slot, item, out _), $"test setup: failed to equip {slot}");
    }

    [TestMethod]
    public void Spawn_CopiesPlayersEquippedLoadout()
    {
        var map = CreateFieldMap(8301);
        var character = DrivingCharacter(map);
        var source = character.CurrentVehicle;
        Equip(source, map, VehicleEquipmentSlot.WheelSet, new WheelSet(), PlayerWheelsetCbid);
        Equip(source, map, VehicleEquipmentSlot.Armor, new Armor(), ArmorCbid);
        Equip(source, map, VehicleEquipmentSlot.WeaponFront, new Weapon(), FrontWeaponCbid);

        var clone = CloneSpawner.Spawn(character);

        Assert.AreEqual(PlayerWheelsetCbid, clone.WheelSet?.CBID,
            "clone must wear the player's wheelset, not the chassis default");
        Assert.AreEqual(ArmorCbid, clone.GetEquippedItem(VehicleEquipmentSlot.Armor)?.CBID);
        Assert.AreEqual(FrontWeaponCbid, clone.GetEquippedItem(VehicleEquipmentSlot.WeaponFront)?.CBID);
    }

    [TestMethod]
    public void Spawn_EquipmentGetsFreshMapNpcCoids_NotThePlayersItemCoids()
    {
        var map = CreateFieldMap(8302);
        var character = DrivingCharacter(map);
        Equip(character.CurrentVehicle, map, VehicleEquipmentSlot.Armor, new Armor(), ArmorCbid);

        var clone = CloneSpawner.Spawn(character);

        var sourceArmor = character.CurrentVehicle.GetEquippedItem(VehicleEquipmentSlot.Armor);
        var cloneArmor = clone.GetEquippedItem(VehicleEquipmentSlot.Armor);
        Assert.IsNotNull(cloneArmor);
        Assert.AreNotEqual(sourceArmor.ObjectId.Coid, cloneArmor.ObjectId.Coid,
            "clone equipment must not reuse the player's item COIDs");
        Assert.IsTrue(MapNpcIdentity.IsMapNpcIdentity(cloneArmor.ObjectId));
    }

    [TestMethod]
    public void Spawn_PlacesCloneNearPlayer_NotAtOrigin()
    {
        var map = CreateFieldMap(8303);
        var character = DrivingCharacter(map);
        character.CurrentVehicle.Position = new Vector3(500f, 10f, 700f);

        var clone = CloneSpawner.Spawn(character);

        Assert.IsTrue(clone.Position.Dist(character.CurrentVehicle.Position) <= 20f,
            $"clone spawned too far away: {clone.Position}");
        Assert.IsTrue(clone.Position.Dist(new Vector3(0, 0, 0)) > 100f);
    }

    /// <summary>
    /// Live repro 2026-08-08: a player ornament materializes as a bare SimpleObject, which has
    /// no parameterless ctor — Activator.CreateInstance(GetType()) threw MissingMethodException
    /// and killed the whole /clone command.
    /// </summary>
    [TestMethod]
    public void Spawn_BareSimpleObjectEquipment_DoesNotThrowAndIsCopied()
    {
        var map = CreateFieldMap(8305);
        var character = DrivingCharacter(map);
        AssetManagerTestHelper.RegisterCloneBase(FrontWeaponCbid, CloneBaseObjectType.Item);

        var ornament = new SimpleObject(AutoCore.Game.Entities.GraphicsObjectType.Graphics);
        Equip(character.CurrentVehicle, map, VehicleEquipmentSlot.Ornament, ornament, FrontWeaponCbid);

        var clone = CloneSpawner.Spawn(character);

        var copied = clone.GetEquippedItem(VehicleEquipmentSlot.Ornament);
        Assert.IsNotNull(copied, "ornament must be copied, not crash the spawn");
        Assert.AreEqual(FrontWeaponCbid, copied.CBID);
    }

    [TestMethod]
    public void Spawn_DriverCreature_IsAttachedAsOwner()
    {
        var map = CreateFieldMap(8304);
        var character = DrivingCharacter(map);

        var clone = CloneSpawner.Spawn(character);

        Assert.IsNotNull(clone.Owner, "clone needs a driver creature for the client HBAIDriver contract");
        Assert.IsInstanceOfType(clone.Owner, typeof(Creature));
        Assert.AreEqual(DriverCbid, ((Creature)clone.Owner).CBID);
    }
}
