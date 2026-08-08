using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.TNL;

/// <summary>
/// Respawn routing under per-player instancing: "same map" must mean the same map OBJECT, not
/// the same continent id (two instances of one continent compare equal by id but are different
/// worlds), and cross-continent respawn into an instanced continent must land in the player's
/// own fresh instance.
/// </summary>
[TestClass]
public class RespawnInstanceTests
{
    private const int SharedContId = 9971;
    private const int InstancedContId = 9972;

    private static SectorMap CreateTestMap(int continentId) =>
        SectorMap.CreateForTests(
            new ContinentObject
            {
                Id = continentId,
                MapFileName = $"tm_respawn_inst_{continentId}",
                DisplayName = "test",
                IsTown = false,
                IsPersistent = true,
            },
            new Vector4(3f, 4f, 5f, 0f));

    private static Character CreateCharacterWithVehicle(long charCoid, long vehicleCoid)
    {
        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);

        var character = new Character();
        character.SetCoid(charCoid, true);
        character.SetOwningConnection(connection);

        var vehicle = new Vehicle();
        vehicle.SetCoid(vehicleCoid, true);
        character.SetCurrentVehicleForTests(vehicle);

        return character;
    }

    [TestInitialize]
    public void SetUp()
    {
        MapManager.Instance.ClearMapsForTests();
        InstancedContinents.SetForTests(new HashSet<int> { InstancedContId });
        MapManager.Instance.CreateInstanceForTests = CreateTestMap;
        RespawnManager.Instance.ResolveMapForTests = null;
    }

    [TestCleanup]
    public void Cleanup()
    {
        TNLConnection.TestPacketSink = null;
        RespawnManager.Instance.ResolveMapForTests = null;
        MapManager.Instance.ResolveMapForTests = null;
        MapManager.Instance.SuppressCreatePacketsForTests = false;
        MapManager.Instance.CreateInstanceForTests = null;
        InstancedContinents.SetForTests(null);
        MapManager.Instance.ClearMapsForTests();
    }

    [TestMethod]
    public void SameContinentId_DifferentMapObject_TakesTheTransferPath()
    {
        // Bug tripwire: two maps with the SAME continent id are NOT the same world.
        var instanceA = CreateTestMap(SharedContId);
        var instanceB = CreateTestMap(SharedContId);
        var character = CreateCharacterWithVehicle(4001, 4002);
        character.SetMap(instanceA);
        character.CurrentVehicle.SetMap(instanceA);
        // Station recorded under a foreign map id so resolution goes through the resolver,
        // which hands back a DIFFERENT map object carrying the same continent id.
        character.SetLastRepairStation(1, 999, new Vector3(1f, 2f, 3f), Quaternion.Default);

        RespawnManager.Instance.ResolveMapForTests = _ => instanceB;
        MapManager.Instance.ResolveMapForTests = _ => instanceB;
        MapManager.Instance.SuppressCreatePacketsForTests = true;

        Assert.IsTrue(RespawnManager.Instance.TryRespawnInSector(
            character, character.ObjectId.Coid, out var reason));
        Assert.IsNull(reason);
        Assert.AreSame(instanceB, character.Map,
            "A different map object must be treated as cross-map (transfer), even with an equal continent id.");
    }

    [TestMethod]
    public void SameInstanceRespawn_StaysInside_InstanceNotDisposed()
    {
        var character = CreateCharacterWithVehicle(4003, 4004);
        var instance = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        character.SetMap(instance);
        character.CurrentVehicle.SetMap(instance);
        character.SetLastRepairStation(1, InstancedContId, new Vector3(7f, 8f, 9f), Quaternion.Default);

        Assert.IsTrue(RespawnManager.Instance.TryRespawnInSector(
            character, character.ObjectId.Coid, out var reason));
        Assert.IsNull(reason);
        Assert.AreSame(instance, character.Map, "Same-instance respawn must stay in the player's own instance.");
        CollectionAssert.Contains(MapManager.Instance.AllMapsForTests(), instance,
            "The live instance must not be disposed by an airlift respawn.");
        Assert.AreEqual(7f, character.Position.X);
    }

    [TestMethod]
    public void CrossContinentRespawn_IntoInstancedContinent_LandsInOwnInstance()
    {
        var shared = CreateTestMap(SharedContId);
        MapManager.Instance.RegisterMapForTests(shared);
        var character = CreateCharacterWithVehicle(4005, 4006);
        character.SetMap(shared);
        character.CurrentVehicle.SetMap(shared);
        character.SetLastRepairStation(1, InstancedContId, new Vector3(1f, 1f, 1f), Quaternion.Default);

        Assert.IsTrue(RespawnManager.Instance.TryResolveDestination(
            character, out var destMap, out _, out _, out var reason));

        Assert.IsNull(reason);
        Assert.IsTrue(destMap.IsInstance,
            "Cross-continent respawn into an instanced continent must resolve a private instance.");
        Assert.AreEqual(character.ObjectId.Coid, destMap.InstanceOwnerCoid);
        Assert.AreEqual(InstancedContId, destMap.ContinentId);
    }
}
