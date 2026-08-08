using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;

/// <summary>
/// Per-player instance registry: entering an instanced continent always yields a private
/// <see cref="SectorMap"/> owned by the character; re-entry after leave creates a FRESH copy
/// (retail tutorial relog policy); a same-continent warp while still on the live instance
/// must reuse it — never tear down an occupied map.
/// </summary>
[TestClass]
public class MapInstancingTests
{
    private const int SharedContId = 9931;
    private const int InstancedContId = 9932;

    private static SectorMap CreateTestMap(int continentId) =>
        SectorMap.CreateForTests(
            new ContinentObject
            {
                Id = continentId,
                MapFileName = $"tm_map_instancing_{continentId}",
                DisplayName = "test",
                IsTown = false,
                IsPersistent = true,
            },
            new Vector4(0, 0, 0, 0));

    private static Character CreateCharacter(long coid)
    {
        var character = new Character();
        character.SetCoid(coid, true);
        return character;
    }

    [TestInitialize]
    public void SetUp()
    {
        MapManager.Instance.ClearMapsForTests();
        InstancedContinents.SetForTests(new HashSet<int> { InstancedContId });
        MapManager.Instance.CreateInstanceForTests = CreateTestMap;
    }

    [TestCleanup]
    public void Cleanup()
    {
        MapManager.Instance.CreateInstanceForTests = null;
        InstancedContinents.SetForTests(null);
        MapManager.Instance.ClearMapsForTests();
    }

    [TestMethod]
    public void SharedContinent_ReturnsTheSameObjectAsGetMap()
    {
        var shared = CreateTestMap(SharedContId);
        MapManager.Instance.RegisterMapForTests(shared);
        var character = CreateCharacter(2001);

        var resolved = MapManager.Instance.GetMapForCharacter(SharedContId, character);

        Assert.AreSame(shared, resolved, "Non-instanced continents must keep the shared map path.");
        Assert.IsFalse(resolved.IsInstance);
    }

    [TestMethod]
    public void InstancedContinent_TwoCharacters_GetDistinctPrivateCopies()
    {
        var a = CreateCharacter(2002);
        var b = CreateCharacter(2003);

        var mapA = MapManager.Instance.GetMapForCharacter(InstancedContId, a);
        var mapB = MapManager.Instance.GetMapForCharacter(InstancedContId, b);

        Assert.AreNotSame(mapA, mapB);
        Assert.AreEqual(InstancedContId, mapA.ContinentId);
        Assert.AreEqual(InstancedContId, mapB.ContinentId);
        Assert.AreNotEqual(mapA.InstanceSerial, mapB.InstanceSerial);
        Assert.IsTrue(mapA.IsInstance);
        Assert.IsTrue(mapB.IsInstance);
        Assert.AreEqual(2002, mapA.InstanceOwnerCoid);
        Assert.AreEqual(2003, mapB.InstanceOwnerCoid);
    }

    [TestMethod]
    public void SameContinentReEntry_WhileStillOnTheLiveInstance_ReusesIt()
    {
        var character = CreateCharacter(2004);
        var first = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        character.SetMap(first);

        // /warp 9932 while already on 9932: must NOT create a fresh copy or tear down the
        // occupied instance.
        var second = MapManager.Instance.GetMapForCharacter(InstancedContId, character);

        Assert.AreSame(first, second);
        Assert.IsTrue(first.Objects.ContainsKey(character.ObjectId),
            "The occupied instance must not be torn down by re-resolution.");
    }

    [TestMethod]
    public void ReEntryAfterDispose_CreatesAFreshInstance()
    {
        var character = CreateCharacter(2005);
        var first = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        MapManager.Instance.DisposeInstance(first, character.ObjectId.Coid);

        var second = MapManager.Instance.GetMapForCharacter(InstancedContId, character);

        Assert.AreNotSame(first, second, "Relog must always land in a fresh instance.");
        Assert.AreNotEqual(first.InstanceSerial, second.InstanceSerial);
    }

    [TestMethod]
    public void StaleRegistryEntry_IsDisposedAndReplaced()
    {
        var character = CreateCharacter(2006);
        // Simulate a prior-fault leftover: registered but the character is no longer on it.
        var stale = CreateTestMap(InstancedContId);
        MapManager.Instance.RegisterInstanceForTests(stale, character.ObjectId.Coid);

        var fresh = MapManager.Instance.GetMapForCharacter(InstancedContId, character);

        Assert.AreNotSame(stale, fresh);
        CollectionAssert.DoesNotContain(MapManager.Instance.AllMapsForTests(), stale,
            "The stale entry must be unregistered.");
        CollectionAssert.Contains(MapManager.Instance.AllMapsForTests(), fresh);
    }

    [TestMethod]
    public void DisposeInstance_LateDisposeOfOldCopy_DoesNotUnregisterTheFreshOne()
    {
        var character = CreateCharacter(2007);
        var old = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        MapManager.Instance.DisposeInstance(old, character.ObjectId.Coid);
        var fresh = MapManager.Instance.GetMapForCharacter(InstancedContId, character);

        // A late/redundant dispose of the OLD object must not evict the fresh registration.
        MapManager.Instance.DisposeInstance(old, character.ObjectId.Coid);

        CollectionAssert.Contains(MapManager.Instance.AllMapsForTests(), fresh);
    }

    [TestMethod]
    public void AllMaps_CoversSharedAndInstanceRegistries()
    {
        var shared = CreateTestMap(SharedContId);
        MapManager.Instance.RegisterMapForTests(shared);
        var character = CreateCharacter(2008);
        var instance = MapManager.Instance.GetMapForCharacter(InstancedContId, character);

        var all = MapManager.Instance.AllMapsForTests();

        CollectionAssert.Contains(all, shared);
        CollectionAssert.Contains(all, instance);
    }
}
