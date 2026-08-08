using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Combat;

using AutoCore.Database.World.Models;
using AutoCore.Game.Combat;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;

/// <summary>
/// Static combat state keyed by bare COIDs collides across per-player instances (identical
/// local COIDs). Corpse-despawn scheduling and ram cooldowns must be scoped per map instance.
/// </summary>
[TestClass]
public class CombatStaticInstanceIsolationTests
{
    private const int ContId = 9981;
    private const long PropCoid = 7301;

    [TestInitialize]
    public void SetUp() => MapPropCorpseDespawn.ResetForTests();

    [TestCleanup]
    public void Cleanup()
    {
        MapPropCorpseDespawn.ResetForTests();
        VehicleMapPropRam.ResetCooldownsForTests();
    }

    private static SectorMap CreateTestMap() =>
        SectorMap.CreateForTests(
            new ContinentObject
            {
                Id = ContId,
                MapFileName = $"tm_combat_iso_{ContId}",
                DisplayName = "test",
                IsTown = false,
                IsPersistent = true,
            },
            new Vector4(0, 0, 0, 0));

    private static GraphicsObject CreateProp(SectorMap map)
    {
        var prop = new SimpleObject(GraphicsObjectType.Graphics);
        prop.SetCoid(PropCoid, false);
        prop.SetMap(map);
        return prop;
    }

    [TestMethod]
    public void CorpseDespawn_SameCoidOnTwoMaps_BothStayScheduled()
    {
        var mapA = CreateTestMap();
        var mapB = CreateTestMap();
        var propA = CreateProp(mapA);
        var propB = CreateProp(mapB);

        MapPropCorpseDespawn.Schedule(propA, mapA, DeathType.Violent, murderer: null);
        MapPropCorpseDespawn.Schedule(propB, mapB, DeathType.Violent, murderer: null);

        Assert.AreEqual(2, MapPropCorpseDespawn.PendingCountForTests,
            "Scheduling the same prop coid in a sibling instance must not cancel the first entry.");
    }

    [TestMethod]
    public void CorpseDespawn_RescheduleOnSameMap_StillReplaces()
    {
        var map = CreateTestMap();
        var prop = CreateProp(map);

        MapPropCorpseDespawn.Schedule(prop, map, DeathType.Violent, murderer: null);
        MapPropCorpseDespawn.Schedule(prop, map, DeathType.Violent, murderer: null);

        Assert.AreEqual(1, MapPropCorpseDespawn.PendingCountForTests,
            "Same map + same coid must keep the replace-existing-schedule behavior.");
    }

    [TestMethod]
    public void CorpseDespawn_CancelForMap_RemovesOnlyThatMapsEntries()
    {
        var mapA = CreateTestMap();
        var mapB = CreateTestMap();
        MapPropCorpseDespawn.Schedule(CreateProp(mapA), mapA, DeathType.Violent, murderer: null);
        MapPropCorpseDespawn.Schedule(CreateProp(mapB), mapB, DeathType.Violent, murderer: null);

        MapPropCorpseDespawn.CancelForMap(mapA);

        Assert.AreEqual(1, MapPropCorpseDespawn.PendingCountForTests);
        // The survivor must finalize against map B (proves A's entry was the one removed).
        Assert.AreEqual(1, MapPropCorpseDespawn.FlushAllForTests());
        Assert.IsNull(mapB.GetObjectByCoid(PropCoid), "Map B's corpse must despawn.");
        Assert.IsNotNull(mapA.GetObjectByCoid(PropCoid), "Map A's corpse must be untouched after cancel.");
    }

    [TestMethod]
    public void RamCooldown_IsPerInstance()
    {
        const int now = 100_000;

        Assert.IsTrue(VehicleMapPropRam.TryConsumeHitCooldownForTests(1, 500, PropCoid, now));
        Assert.IsFalse(VehicleMapPropRam.TryConsumeHitCooldownForTests(1, 500, PropCoid, now + 1),
            "Same instance within cooldown must be gated.");
        Assert.IsTrue(VehicleMapPropRam.TryConsumeHitCooldownForTests(2, 500, PropCoid, now + 1),
            "The same vehicle/prop coids in a sibling instance must not share the cooldown.");
    }

    [TestMethod]
    public void RamCooldown_ClearForInstance_DropsOnlyThatSerial()
    {
        const int now = 200_000;
        VehicleMapPropRam.TryConsumeHitCooldownForTests(1, 500, PropCoid, now);
        VehicleMapPropRam.TryConsumeHitCooldownForTests(2, 500, PropCoid, now);

        VehicleMapPropRam.ClearForInstance(1);

        Assert.IsTrue(VehicleMapPropRam.TryConsumeHitCooldownForTests(1, 500, PropCoid, now + 1),
            "Cleared serial must be free to hit again.");
        Assert.IsFalse(VehicleMapPropRam.TryConsumeHitCooldownForTests(2, 500, PropCoid, now + 1),
            "Sibling serial's cooldown must survive the clear.");
    }
}
