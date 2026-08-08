using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.TNL;

/// <summary>
/// Entry choke points: TransferCharacterToMap must resolve instanced continents through
/// GetMapForCharacter (private copy per player), dispose the source instance on the way out,
/// rebind the logic-variable store, and reset the presence ledger on instance switch.
/// </summary>
[TestClass]
public class MapInstancingEntryTests
{
    private const int SharedContId = 9991;
    private const int InstancedContId = 9992;

    private static SectorMap CreateTestMap(int continentId) =>
        SectorMap.CreateForTests(
            new ContinentObject
            {
                Id = continentId,
                MapFileName = $"tm_instancing_entry_{continentId}",
                DisplayName = "test",
                IsTown = false,
                IsPersistent = true,
            },
            new Vector4(1f, 2f, 3f, 0f));

    private static Character CreateCharacterWithVehicle(long charCoid, long vehicleCoid)
    {
        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);

        var character = new Character();
        character.SetCoid(charCoid, true);
        character.SetOwningConnection(connection);
        character.AttachTestDataForTests();
        connection.CurrentCharacter = character;

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
        MapManager.Instance.ResolveMapForTests = null;
        MapManager.Instance.SuppressCreatePacketsForTests = true;
    }

    [TestCleanup]
    public void Cleanup()
    {
        TNLConnection.TestPacketSink = null;
        MapManager.Instance.SuppressCreatePacketsForTests = false;
        MapManager.Instance.ResolveMapForTests = null;
        MapManager.Instance.CreateInstanceForTests = null;
        InstancedContinents.SetForTests(null);
        MapManager.Instance.ClearMapsForTests();
    }

    [TestMethod]
    public void Transfer_IntoInstancedContinent_YieldsOwnedInstance()
    {
        var shared = CreateTestMap(SharedContId);
        MapManager.Instance.RegisterMapForTests(shared);
        var character = CreateCharacterWithVehicle(5001, 5002);
        character.SetMap(shared);
        character.CurrentVehicle.SetMap(shared);

        Assert.IsTrue(MapManager.Instance.TransferCharacterToMap(character, InstancedContId));

        Assert.IsTrue(character.Map.IsInstance, "Transfer into an instanced continent must land in a private copy.");
        Assert.AreEqual(character.ObjectId.Coid, character.Map.InstanceOwnerCoid);
        Assert.AreEqual(InstancedContId, character.Map.ContinentId);
        Assert.AreSame(character.Map, character.CurrentVehicle.Map);
    }

    [TestMethod]
    public void Transfer_IntoSharedContinent_UsesTheSharedMap()
    {
        var sharedA = CreateTestMap(SharedContId);
        var sharedB = CreateTestMap(SharedContId + 100);
        MapManager.Instance.RegisterMapForTests(sharedA);
        MapManager.Instance.RegisterMapForTests(sharedB);
        var character = CreateCharacterWithVehicle(5003, 5004);
        character.SetMap(sharedA);
        character.CurrentVehicle.SetMap(sharedA);

        Assert.IsTrue(MapManager.Instance.TransferCharacterToMap(character, sharedB.ContinentId));

        Assert.AreSame(sharedB, character.Map, "Shared continents keep the one shared map.");
        Assert.IsFalse(character.Map.IsInstance);
    }

    [TestMethod]
    public void Transfer_OutOfAnInstance_DisposesIt()
    {
        var shared = CreateTestMap(SharedContId);
        MapManager.Instance.RegisterMapForTests(shared);
        var character = CreateCharacterWithVehicle(5005, 5006);
        var instance = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        character.SetMap(instance);
        character.CurrentVehicle.SetMap(instance);

        Assert.IsTrue(MapManager.Instance.TransferCharacterToMap(character, SharedContId));

        Assert.AreSame(shared, character.Map);
        CollectionAssert.DoesNotContain(MapManager.Instance.AllMapsForTests(), instance,
            "Leaving the instance via transfer must dispose it.");
    }

    [TestMethod]
    public void InstanceSwitch_RebindsLogicVariables_AndResetsPresence()
    {
        var character = CreateCharacterWithVehicle(5007, 5008);
        var first = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        character.SetMap(first);
        character.CurrentVehicle.SetMap(first);

        var storeOnFirst = character.EnsureLogicVariables();
        character.MapPresence.Suppress(4242);
        Assert.IsTrue(character.MapPresence.IsSuppressed(4242));

        // Simulate relog: leave (disposes), then enter a fresh instance of the same continent.
        character.CurrentVehicle.SetMap(null);
        character.SetMap(null);
        var second = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        Assert.AreNotSame(first, second);
        character.SetMap(second);

        var storeOnSecond = character.EnsureLogicVariables();
        Assert.AreNotSame(storeOnFirst, storeOnSecond,
            "LogicVariableStore must rebind on map-object change (Character.cs object-identity check).");
        Assert.AreSame(second, storeOnSecond.Map);
        Assert.IsFalse(character.MapPresence.IsSuppressed(4242),
            "Presence ledger must reset when entering a different instance of the same continent.");
    }
}
