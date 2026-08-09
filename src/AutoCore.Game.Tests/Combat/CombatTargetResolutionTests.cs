using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Combat;

using AutoCore.Database.World.Models;
using AutoCore.Game.Combat;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Skills;
using AutoCore.Game.Structures;

/// <summary>
/// SS-31 tripwires: after a character-database wipe, global player COIDs collide with authored
/// local map COIDs. Combat target resolution must honor the TFID Global flag; COID-only
/// resolution routes damage/reactions/skills to the wrong entity (invincible-vehicle reports).
/// </summary>
[TestClass]
public class CombatTargetResolutionTests
{
    private const long CollidingCoid = 2;

    /// <summary>
    /// Post-wipe production shape: authored local prop and a global player vehicle share a COID.
    /// The global vehicle is registered on the map FIRST so legacy COID-order scans return it,
    /// mirroring the arbitrary-dictionary-order hazard.
    /// </summary>
    private static (SectorMap Map, Vehicle GlobalVehicle, GraphicsObject LocalProp) CreateCollidingMap(
        int continentId)
    {
        var continent = new ContinentObject
        {
            Id = continentId,
            MapFileName = $"tm_ctr_{continentId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));

        var vehicle = new Vehicle();
        vehicle.SetCoid(CollidingCoid, true);
        vehicle.SetMap(map);

        var prop = new GraphicsObject(GraphicsObjectType.Graphics);
        prop.InitializeHealthForTests(5);
        prop.SetCoid(CollidingCoid, false);
        prop.SetMap(map);

        return (map, vehicle, prop);
    }

    [TestMethod]
    public void Resolve_GlobalTfid_ResolvesGlobalVehicle_NotLocalProp()
    {
        var (map, vehicle, _) = CreateCollidingMap(97101);

        var resolved = CombatTargetResolver.Resolve(map, new TFID(CollidingCoid, true));

        Assert.AreSame(vehicle, resolved,
            "Global TFID must resolve the global vehicle even when a local object shares its COID");
    }

    [TestMethod]
    public void Resolve_LocalTfid_ResolvesLocalProp_NotGlobalVehicle()
    {
        var (map, _, prop) = CreateCollidingMap(97102);

        var resolved = CombatTargetResolver.Resolve(map, new TFID(CollidingCoid, false));

        Assert.AreSame(prop, resolved,
            "Local TFID must resolve the authored map object even when a global entity shares its COID");
    }

    [TestMethod]
    public void Resolve_FlagMismatch_FallsBackToLegacyCoidScan()
    {
        // Only a local object exists; a (wrongly) global-flagged TFID must still find it so
        // non-collision behavior is unchanged when the client misreports the flag.
        var continent = new ContinentObject
        {
            Id = 97103,
            MapFileName = "tm_ctr_97103",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
        var prop = new GraphicsObject(GraphicsObjectType.Graphics);
        prop.InitializeHealthForTests(5);
        prop.SetCoid(4242, false);
        prop.SetMap(map);

        var resolved = CombatTargetResolver.Resolve(map, new TFID(4242, true));

        Assert.AreSame(prop, resolved, "Legacy COID fallback must keep flag-mismatch lookups working");
    }

    [TestMethod]
    public void Resolve_NullMapNullIdNonPositiveCoid_ReturnsNull()
    {
        var (map, _, _) = CreateCollidingMap(97104);
        Assert.IsNull(CombatTargetResolver.Resolve(null, new TFID(CollidingCoid, true)));
        Assert.IsNull(CombatTargetResolver.Resolve(map, null));
        Assert.IsNull(CombatTargetResolver.Resolve(map, new TFID(0, true)));
        Assert.IsNull(CombatTargetResolver.Resolve(map, new TFID(-1, false)));
    }

    [TestMethod]
    public void Resolve_GlobalTfid_NotOnMap_FallsBackToObjectManager()
    {
        var continent = new ContinentObject
        {
            Id = 97105,
            MapFileName = "tm_ctr_97105",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));

        var vehicle = new Vehicle();
        vehicle.SetCoid(97155, true);
        Assert.IsTrue(ObjectManager.Instance.Add(vehicle));
        try
        {
            var resolved = CombatTargetResolver.Resolve(map, new TFID(97155, true));
            Assert.AreSame(vehicle, resolved);
        }
        finally
        {
            ObjectManager.Instance.Remove(vehicle);
        }
    }

    [TestMethod]
    public void VehicleTryResolveTarget_CoidCollision_HonorsGlobalFlag()
    {
        var (map, targetVehicle, prop) = CreateCollidingMap(97106);
        var shooter = new Vehicle();
        shooter.SetCoid(9, true);
        shooter.SetMap(map);

        Assert.IsTrue(shooter.TryResolveTarget(new TFID(CollidingCoid, true), out var resolvedGlobal));
        Assert.AreSame(targetVehicle, resolvedGlobal,
            "Weapon-hit resolution must land on the global vehicle, not the same-COID local prop");

        Assert.IsTrue(shooter.TryResolveTarget(new TFID(CollidingCoid, false), out var resolvedLocal));
        Assert.AreSame(prop, resolvedLocal);
    }

    [TestMethod]
    public void Resolve_UnderCollision_IncrementsCollisionResolvedCount()
    {
        var (map, _, _) = CreateCollidingMap(97109);
        var before = CombatTargetResolver.CollisionResolvedCount;

        CombatTargetResolver.Resolve(map, new TFID(CollidingCoid, true));

        Assert.AreEqual(before + 1, CombatTargetResolver.CollisionResolvedCount,
            "resolving a TFID whose COID is shared by both a local and a global entity must be counted");
    }

    [TestMethod]
    public void Resolve_NoCollision_DoesNotIncrementCollisionResolvedCount()
    {
        var continent = new ContinentObject
        {
            Id = 97110,
            MapFileName = "tm_ctr_97110",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
        var prop = new GraphicsObject(GraphicsObjectType.Graphics);
        prop.InitializeHealthForTests(5);
        prop.SetCoid(555, false);
        prop.SetMap(map);

        var before = CombatTargetResolver.CollisionResolvedCount;
        CombatTargetResolver.Resolve(map, new TFID(555, false));

        Assert.AreEqual(before, CombatTargetResolver.CollisionResolvedCount);
    }

    [TestMethod]
    public void MakeNotInvincible_CoidCollision_TargetsAuthoredLocalProp_NotGlobalVehicle()
    {
        var (map, vehicle, prop) = CreateCollidingMap(97107);
        vehicle.SetInvincible(true);
        prop.SetInvincible(true);

        var template = new ReactionTemplate { ActOnActivator = false };
        template.Objects.Add(CollidingCoid);

        // Activator only supplies the map; use a separate entity.
        var activator = new Vehicle();
        activator.SetCoid(9, true);
        activator.SetMap(map);

        Assert.IsTrue(ReactionObjectStateEffects.ApplyInvincible(template, activator, invincible: false));

        Assert.IsFalse(prop.IsInvincible,
            "Authored reaction target COIDs are local map objects — the prop must become damageable");
        Assert.IsTrue(vehicle.IsInvincible,
            "The colliding global vehicle must not have its invincibility cleared by a map reaction");
    }

    [TestMethod]
    public void SkillResolveTarget_CoidCollision_HonorsGlobalFlag()
    {
        var (map, vehicle, prop) = CreateCollidingMap(97108);
        var caster = new Vehicle();
        caster.SetCoid(9, true);
        caster.SetMap(map);

        var skill = new Skill();

        var resolvedGlobal = SkillService.ResolveTargetForTests(
            caster, skill, new TFID(CollidingCoid, true), hasDamage: true, hasHeal: false);
        Assert.AreSame(vehicle, resolvedGlobal,
            "Skill damage aimed at a global vehicle must not land on the same-COID local prop");

        var resolvedLocal = SkillService.ResolveTargetForTests(
            caster, skill, new TFID(CollidingCoid, false), hasDamage: true, hasHeal: false);
        Assert.AreSame(prop, resolvedLocal);
    }
}
