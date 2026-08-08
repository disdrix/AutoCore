using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.TNL;

/// <summary>
/// TriggerManager latch isolation across per-player map instances. Instances of the same
/// continent mint IDENTICAL local COIDs, so every latch keyed by bare COIDs collides across
/// instances: player A latching a volume must never suppress the same-coid trigger for player B
/// in a sibling instance, and clearing one instance's latches must not touch the sibling's.
/// </summary>
[TestClass]
public class TriggerInstanceIsolationTests
{
    private const int ContId = 9961;
    private const long TriggerCoid = 6001;
    private const long WatchVarId = 50;
    private const long ConstOneVarId = 4;

    [TestInitialize]
    public void SetUp() => TriggerManager.Instance.ClearAllForTests();

    [TestCleanup]
    public void TearDown() => TriggerManager.Instance.ClearAllForTests();

    /// <summary>
    /// Two players with byte-identical coids (as two instances of one continent produce), each
    /// on their own map instance, both standing in the same-coid trigger volume.
    /// </summary>
    private static (Character Character, Vehicle Vehicle, SectorMap Map, Trigger Trigger) CreatePlayerOnOwnInstance()
    {
        var continent = new ContinentObject
        {
            Id = ContId,
            MapFileName = $"tm_trigger_iso_{ContId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));

        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);

        var character = new Character();
        character.SetCoid(150, true);
        character.SetOwningConnection(connection);
        connection.CurrentCharacter = character;

        var vehicle = new Vehicle();
        vehicle.SetCoid(151, true);
        character.SetCurrentVehicleForTests(vehicle);

        character.SetMap(map);
        vehicle.SetMap(map);

        var tpl = new TriggerTemplate
        {
            COID = (int)TriggerCoid,
            TargetType = TriggerTargetType.Players,
            Scale = 10f,
            DoCollision = true,
            ActivationCount = -1,
        };
        var trigger = new Trigger(tpl);
        trigger.SetCoid(TriggerCoid, false);
        trigger.Position = new Vector3(0, 0, 0);
        trigger.Scale = 10f;
        trigger.SetMap(map);

        vehicle.Position = new Vector3(0, 0, 0);
        return (character, vehicle, map, trigger);
    }

    [TestMethod]
    public void EnterLatch_LatchingInstanceA_DoesNotSuppressInstanceB()
    {
        var a = CreatePlayerOnOwnInstance();
        var b = CreatePlayerOnOwnInstance();

        TriggerManager.Instance.CheckTriggersFor(a.Vehicle);
        Assert.AreEqual(1, a.Trigger.FireCount);

        TriggerManager.Instance.CheckTriggersFor(b.Vehicle);
        Assert.AreEqual(1, b.Trigger.FireCount,
            "Instance A's enter-latch must not mark the same-coid volume as already-entered in instance B.");
    }

    [TestMethod]
    public void ClearTriggersFor_ClearsOnlyTheGivenInstance()
    {
        var a = CreatePlayerOnOwnInstance();
        var b = CreatePlayerOnOwnInstance();
        TriggerManager.Instance.CheckTriggersFor(a.Vehicle);
        TriggerManager.Instance.CheckTriggersFor(b.Vehicle);

        TriggerManager.Instance.ClearTriggersFor(a.Map, a.Vehicle.ObjectId.Coid);

        // A re-fires (latch cleared) …
        TriggerManager.Instance.CheckTriggersFor(a.Vehicle);
        Assert.AreEqual(2, a.Trigger.FireCount);
        // … B stays latched (still inside, no re-fire).
        TriggerManager.Instance.CheckTriggersFor(b.Vehicle);
        Assert.AreEqual(1, b.Trigger.FireCount,
            "Clearing instance A's latches must not wipe instance B's.");
    }

    [TestMethod]
    public void ClearTrigger_ClearsOnlyTheGivenInstance()
    {
        var a = CreatePlayerOnOwnInstance();
        var b = CreatePlayerOnOwnInstance();
        TriggerManager.Instance.CheckTriggersFor(a.Vehicle);
        TriggerManager.Instance.CheckTriggersFor(b.Vehicle);

        TriggerManager.Instance.ClearTrigger(a.Map, TriggerCoid);

        TriggerManager.Instance.CheckTriggersFor(a.Vehicle);
        Assert.AreEqual(2, a.Trigger.FireCount);
        TriggerManager.Instance.CheckTriggersFor(b.Vehicle);
        Assert.AreEqual(1, b.Trigger.FireCount);
    }

    [TestMethod]
    public void ClearInstance_WipesOnlyThatSerial()
    {
        var a = CreatePlayerOnOwnInstance();
        var b = CreatePlayerOnOwnInstance();
        TriggerManager.Instance.CheckTriggersFor(a.Vehicle);
        TriggerManager.Instance.CheckTriggersFor(b.Vehicle);

        TriggerManager.Instance.ClearInstance(a.Map.InstanceSerial);

        TriggerManager.Instance.CheckTriggersFor(a.Vehicle);
        Assert.AreEqual(2, a.Trigger.FireCount);
        TriggerManager.Instance.CheckTriggersFor(b.Vehicle);
        Assert.AreEqual(1, b.Trigger.FireCount);
    }

    [TestMethod]
    public void ConditionalLatch_FiringInInstanceA_DoesNotSuppressInstanceB()
    {
        var a = CreateConditionalWatcher();
        var b = CreateConditionalWatcher();

        a.Store.Set((int)WatchVarId, 1f);
        TriggerManager.Instance.OnVariableChanged(a.Vehicle, (int)WatchVarId);
        Assert.AreEqual(1, a.Trigger.FireCount);

        b.Store.Set((int)WatchVarId, 1f);
        TriggerManager.Instance.OnVariableChanged(b.Vehicle, (int)WatchVarId);
        Assert.AreEqual(1, b.Trigger.FireCount,
            "Instance A's conditional one-shot must not suppress the same actor+trigger in instance B.");
    }

    private (Character Character, Vehicle Vehicle, SectorMap Map, Trigger Trigger, LogicVariableStore Store)
        CreateConditionalWatcher()
    {
        var (character, vehicle, map, _) = CreatePlayerOnOwnInstance();

        map.MapData.Variables[(int)WatchVarId] = Variable.CreateForTests(
            (int)WatchVarId, 0, 0f, 0f, "watch_flag");
        map.MapData.Variables[(int)ConstOneVarId] = Variable.CreateForTests(
            (int)ConstOneVarId, LogicVariableStore.TypeConstant, 1f, 1f, "one");

        const long condTriggerCoid = 6002;
        var tpl = new TriggerTemplate
        {
            COID = (int)condTriggerCoid,
            TargetType = TriggerTargetType.Players,
            Scale = 1f,
            DoCollision = false,
            DoConditionals = true,
            AllConditionsNeeded = false,
            ActivationCount = -1,
        };
        tpl.Conditions.Add(new TriggerConditional
        {
            LeftId = (int)WatchVarId,
            RightId = (int)ConstOneVarId,
            Type = ConditionalType.EqualTo,
        });
        var trigger = new Trigger(tpl);
        trigger.SetCoid(condTriggerCoid, false);
        trigger.Position = new Vector3(0, 0, 0);
        trigger.Scale = 1f;
        trigger.SetMap(map);

        var store = character.EnsureLogicVariables();
        return (character, vehicle, map, trigger, store);
    }
}
