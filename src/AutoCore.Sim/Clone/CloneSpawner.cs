using AutoCore.Game.CloneBases;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Map;
using AutoCore.Game.Npc;
using AutoCore.Utils;

namespace AutoCore.Sim.Clone;

/// <summary>
/// Builds the NPC copy of a player's vehicle. Mirrors the SpawnPoint.SpawnVehicle ordering
/// (src/AutoCore.Game/Entities/SpawnPoint.cs): map-NPC identity -> LoadCloneBase ->
/// SetupCBFields -> pose -> wheelset -> driver -> NpcAi BEFORE SetMap -> CreateGhost.
/// </summary>
internal static class CloneSpawner
{
    private const float SpawnAheadMeters = 8f;

    public static Vehicle Spawn(Character owner) => Spawn(owner, fleetIndex: 0);

    /// <summary>Fleet spawns fan out in a 5-wide grid ahead of the player so /clone N does not stack.</summary>
    public static Vehicle Spawn(Character owner, int fleetIndex)
    {
        var map = owner.Map;
        var source = owner.CurrentVehicle;

        var clone = new Vehicle();
        AssignMapNpcIdentity(map, clone);
        clone.LoadCloneBase(source.CBID);
        clone.SetupCBFields();

        clone.Layer = source.Layer;
        var forward = TerrainContactPlane.ForwardFromQuaternion(source.Rotation);
        // Right vector in the ground plane for lateral fleet spread.
        var rightX = forward.Z;
        var rightZ = -forward.X;
        var aheadMeters = SpawnAheadMeters + (fleetIndex / 5) * 6f;
        var sideMeters = ((fleetIndex % 5) - 2) * 5f;
        var spawnPosition = new AutoCore.Game.Structures.Vector3(
            source.Position.X + forward.X * aheadMeters + rightX * sideMeters,
            source.Position.Y + forward.Y * aheadMeters,
            source.Position.Z + forward.Z * aheadMeters + rightZ * sideMeters);
        clone.Position = NpcTicker.SnapToTerrain(map, spawnPosition);
        clone.Rotation = source.Rotation;

        // Combat exclusion: the clone is scenery to weapons and aggro.
        clone.SetInvincible(true);

        EquipWheelSet(map, clone, source);
        CopyEquipment(map, clone, source);

        var driver = BuildDriver(map, clone);
        if (driver != null)
            clone.SetOwner(driver);

        // Bare NpcAiState (no combat profile): SetMap's HasNpcAi check then registers the clone
        // in Map.NpcAiEntities; NpcTicker's pathless early-return leaves the actual driving to
        // the sim tick. Must be assigned before SetMap.
        clone.NpcAi = new NpcAiState { HomePosition = clone.Position };
        clone.SetMap(map);
        clone.CreateGhost();

        return clone;
    }

    public static void Despawn(Vehicle clone)
    {
        if (clone == null)
            return;

        clone.SetMap(null);
        clone.ClearGhost();
    }

    private static void AssignMapNpcIdentity(SectorMap map, ClonedObjectBase entity)
    {
        var counter = map.LocalCoidCounter;
        var objectId = MapNpcIdentity.AllocateCoid(ref counter);
        map.LocalCoidCounter = counter;
        entity.SetCoid(objectId.Coid, objectId.Global);
    }

    /// <summary>
    /// The nested CreateVehicle payload must carry a wheelset or the client renderer crashes
    /// (see SpawnPoint.EquipDefaultWheelSet). Prefer the player's equipped wheelset CBID so the
    /// clone looks identical; fall back to the chassis default.
    /// </summary>
    private static void EquipWheelSet(SectorMap map, Vehicle clone, Vehicle source)
    {
        var wheelsetCbid = source.WheelSet?.CBID
            ?? (clone.CloneBaseObject as CloneBaseVehicle)?.VehicleSpecific.DefaultWheelset
            ?? 0;
        if (wheelsetCbid <= 0)
            return;

        var wheelSet = new WheelSet();
        AssignMapNpcIdentity(map, wheelSet);
        wheelSet.LoadCloneBase(wheelsetCbid);
        wheelSet.SetupCBFields();

        if (!clone.TryEquipItem(VehicleEquipmentSlot.WheelSet, wheelSet, out _))
        {
            Logger.WriteLog(LogType.Error,
                $"CloneSpawner: failed to equip wheelset cbid={wheelsetCbid} on clone of {source.CBID}");
        }
    }

    /// <summary>
    /// Copies every equipped item (weapons, armor, powerplant, ornament, ...) from the player's
    /// vehicle onto the clone as fresh instances with map-NPC COIDs — the client resolves nested
    /// CreateVehicle equipment TFIDs, so reusing the player's item COIDs would collide.
    /// </summary>
    private static void CopyEquipment(SectorMap map, Vehicle clone, Vehicle source)
    {
        foreach (var (slot, item) in source.EnumerateEquippedItems())
        {
            // Wheelset is handled by EquipWheelSet (needs the chassis-default fallback).
            if (slot == VehicleEquipmentSlot.WheelSet || item == null || item.CBID <= 0)
                continue;

            var copy = CreateCopyInstance(slot, item);
            AssignMapNpcIdentity(map, copy);
            copy.LoadCloneBase(item.CBID);
            copy.SetupCBFields();

            if (!clone.TryEquipItem(slot, copy, out _))
            {
                Logger.WriteLog(LogType.Error,
                    $"CloneSpawner: failed to copy equipment slot={slot} cbid={item.CBID} onto clone of {source.CBID}");
            }
        }
    }

    /// <summary>
    /// Fresh instance for an equipment copy, keyed by slot. Ornament/race-item slots hold bare
    /// SimpleObjects, which have no parameterless ctor — Activator.CreateInstance(GetType())
    /// crashed live on an equipped ornament (MissingMethodException), so construct explicitly.
    /// </summary>
    private static SimpleObject CreateCopyInstance(VehicleEquipmentSlot slot, SimpleObject source)
        => slot switch
        {
            VehicleEquipmentSlot.Armor => new Armor(),
            VehicleEquipmentSlot.PowerPlant => new PowerPlant(),
            VehicleEquipmentSlot.WheelSet => new WheelSet(),
            VehicleEquipmentSlot.WeaponMelee or VehicleEquipmentSlot.WeaponFront
                or VehicleEquipmentSlot.WeaponTurret or VehicleEquipmentSlot.WeaponRear => new Weapon(),
            _ => new SimpleObject(source.ObjectType),
        };

    /// <summary>
    /// Driver creature for the client HBAIDriver contract (level/faction chain); the clone is
    /// mis-rendered without one. Uses the chassis clonebase default driver.
    /// </summary>
    private static Creature BuildDriver(SectorMap map, Vehicle clone)
    {
        var driverCbid = (clone.CloneBaseObject as CloneBaseVehicle)?.VehicleSpecific.DefaultDriver ?? 0;
        if (driverCbid <= 0)
            return null;

        var driver = new Creature();
        AssignMapNpcIdentity(map, driver);
        driver.LoadCloneBase(driverCbid);
        driver.SetupCBFields();
        driver.Level = (byte)((driver.CloneBaseObject as CloneBaseCreature)?.CreatureSpecific.BaseLevel ?? 1);
        driver.Position = clone.Position;
        driver.Rotation = clone.Rotation;
        driver.Layer = clone.Layer;
        return driver;
    }
}
