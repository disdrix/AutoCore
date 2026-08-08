using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Map;

using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;

/// <summary>
/// Per-player instance isolation and the LeaveMap disposal branch. Two live instances of the
/// same continent must never share entity state; when the owner leaves, the instance is torn
/// down and unregistered instead of rebuilt (shared maps keep ResetLocalWorldToAuthored), and
/// teardown failures must never propagate into the leaving player's logout/transfer (SS-30).
/// </summary>
[TestClass]
public class MapInstanceDisposalTests
{
    private const int InstancedContId = 9951;

    private static SectorMap CreateTestMap(int continentId) =>
        SectorMap.CreateForTests(
            new ContinentObject
            {
                Id = continentId,
                MapFileName = $"tm_instance_disposal_{continentId}",
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
    public void TwoInstances_PlayersListsAreDisjoint()
    {
        var a = CreateCharacter(3001);
        var b = CreateCharacter(3002);
        var mapA = MapManager.Instance.GetMapForCharacter(InstancedContId, a);
        var mapB = MapManager.Instance.GetMapForCharacter(InstancedContId, b);
        a.SetMap(mapA);
        b.SetMap(mapB);

        // Tier-1 interest scoping reads map.Players — disjoint lists means players never see
        // each other across instances, with no InterestSelector change.
        CollectionAssert.Contains(mapA.Players, a);
        CollectionAssert.DoesNotContain(mapA.Players, b);
        CollectionAssert.Contains(mapB.Players, b);
        CollectionAssert.DoesNotContain(mapB.Players, a);
    }

    [TestMethod]
    public void TwoInstances_SameCoidNpc_StateIsIndependent()
    {
        var a = CreateCharacter(3003);
        var b = CreateCharacter(3004);
        var mapA = MapManager.Instance.GetMapForCharacter(InstancedContId, a);
        var mapB = MapManager.Instance.GetMapForCharacter(InstancedContId, b);

        // Both instances mint identical local COIDs from the same authored data.
        const long npcCoid = 14090;
        var npcA = new Creature();
        npcA.SetCoid(npcCoid, false);
        npcA.SetMap(mapA);
        var npcB = new Creature();
        npcB.SetCoid(npcCoid, false);
        npcB.SetMap(mapB);

        npcA.Position = new Vector3(500f, 0f, 500f);

        Assert.AreEqual(500f, mapA.GetObjectByCoid(npcCoid).Position.X);
        Assert.AreEqual(0f, mapB.GetObjectByCoid(npcCoid).Position.X,
            "Mutating an NPC in one instance must not touch the same-coid NPC in a sibling instance.");
        Assert.AreNotSame(mapA.GetObjectByCoid(npcCoid), mapB.GetObjectByCoid(npcCoid));
    }

    [TestMethod]
    public void OwnerLeaves_InstanceIsTornDownAndUnregistered()
    {
        var character = CreateCharacter(3005);
        var instance = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        character.SetMap(instance);

        var npc = new Creature();
        npc.SetCoid(14090, false);
        npc.SetMap(instance);

        character.SetMap(null);

        CollectionAssert.DoesNotContain(MapManager.Instance.AllMapsForTests(), instance,
            "Instance must be unregistered when its owner leaves.");
        Assert.AreEqual(0, instance.Objects.Count, "Instance entities must be torn down.");
        Assert.IsNull(npc.Map, "Non-character entities must be released from the dead instance.");
    }

    [TestMethod]
    public void SharedMap_OwnerLeaves_KeepsResetBehavior_StaysRegistered()
    {
        var shared = CreateTestMap(9952);
        MapManager.Instance.RegisterMapForTests(shared);
        var character = CreateCharacter(3006);
        character.SetMap(shared);

        character.SetMap(null);

        CollectionAssert.Contains(MapManager.Instance.AllMapsForTests(), shared,
            "Shared maps must never be unregistered by the disposal branch.");
    }

    [TestMethod]
    public void InstanceDisposal_MustNotRestoreSharedTemplateState()
    {
        var character = CreateCharacter(3007);
        var instance = MapManager.Instance.GetMapForCharacter(InstancedContId, character);
        character.SetMap(instance);

        // Simulate a legacy Create/Activate write on the (process-global) template. The shared
        // ResetLocalWorldToAuthored restores this — instance disposal must NOT, because sibling
        // instances read the same MapData concurrently.
        var tpl = new SpawnPointTemplate { COID = 500, IsActive = true, OriginalIsActive = false };
        instance.MapData.Templates[500] = tpl;

        character.SetMap(null);

        Assert.IsTrue(tpl.IsActive,
            "Instance disposal must not write shared MapData templates (cross-instance leak).");
    }

    [TestMethod]
    public void SS30_Tripwire_EntityTeardownFaultDoesNotAbortDisposal()
    {
        // Character-level SetMap(null) faults at logout are already contained by
        // SafeTeardownStep (EndCharacterSession). The NEW surface is DisposeInstance: a single
        // corrupt entity must not abort the sweep, leak the registry entry, or throw out of the
        // owner's LeaveMap.
        var character = CreateCharacter(3008);
        var instance = MapManager.Instance.GetMapForCharacter(InstancedContId, character);

        var npc = new Creature();
        npc.SetCoid(14091, false);
        npc.SetMap(instance);

        // Sabotage the grid so every per-entity LeaveMap throws NRE during teardown.
        typeof(SectorMap).GetField($"<{nameof(SectorMap.Grid)}>k__BackingField",
            System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic)!
            .SetValue(instance, null);

        MapManager.Instance.DisposeInstance(instance, character.ObjectId.Coid);

        CollectionAssert.DoesNotContain(MapManager.Instance.AllMapsForTests(), instance,
            "The faulted instance must still be unregistered.");
        Assert.AreEqual(0, instance.Objects.Count,
            "Collections must be cleared even when per-entity teardown faults.");
    }
}
