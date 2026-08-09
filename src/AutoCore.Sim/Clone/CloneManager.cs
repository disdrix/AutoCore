using System.Collections.Concurrent;
using AutoCore.Game.Entities;
using AutoCore.Game.Npc;
using AutoCore.Sim.Ai;
using AutoCore.Utils;

namespace AutoCore.Sim.Clone;

/// <summary>
/// One simulated clone vehicle per player, toggled by /clone. Owns spawn/despawn lifecycle;
/// the per-tick lifecycle check despawns clones whose owner left the map (logout, warp, death
/// respawn to town) without needing new events on Character.
/// </summary>
public sealed class CloneManager
{
    private readonly ConcurrentDictionary<long, CloneHandle> _clones = new();

    /// <summary>
    /// Global publish-height trim (metres), live-tuned via /clonetrim to dial out the residual
    /// per-map body height that formulas and calibration leave behind.
    /// </summary>
    public static float HeightTrim { get; set; }

    public int ActiveCloneCount => _clones.Count;

    public string Toggle(Character character)
    {
        if (character == null)
            return "No character loaded.";

        if (_clones.TryRemove(character.ObjectId.Coid, out var existing))
        {
            CloneSpawner.Despawn(existing.Clone);
            return "Clone despawned.";
        }

        var map = character.Map;
        var vehicle = character.CurrentVehicle;
        if (map == null || vehicle == null || map.MapData?.ContinentObject?.IsTown != false)
            return "You need to be driving to use /clone.";

        var clone = CloneSpawner.Spawn(character);
        _clones[character.ObjectId.Coid] = new CloneHandle(character, clone);
        return "Clone spawned.";
    }

    internal static CloneDriveBrain BuildBrainForHandle(Vehicle clone)
    {
        var wheelSet = clone.WheelSet?.CloneBaseObject as AutoCore.Game.CloneBases.CloneBaseWheelSet;
        var parameters = clone.CloneBaseObject is AutoCore.Game.CloneBases.CloneBaseVehicle cb
            ? Physics.SimVehicleParams.FromCloneBase(cb, wheelSet)
            : Physics.SimVehicleParams.CreateForTests(
                massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
                muBase: 1f, suspensionLength: 0.35f, suspensionStrength: 60f,
                suspensionDampCompression: 6f, suspensionDampExtension: 7f,
                wheelRadius: 0.45f, wheelBase: 3f, dragHalfRhoCdA: 0.6f);

        var brain = new CloneDriveBrain(parameters, new CloneAiTuning());
        var forward = TerrainContactPlane.ForwardFromQuaternion(clone.Rotation);
        brain.Reset(clone.Position, MathF.Atan2(forward.X, forward.Z));
        return brain;
    }

    /// <summary>Despawns clones whose owner is gone or changed maps. Called every sector tick.</summary>
    public void Tick(long nowMs, float dt)
    {
        foreach (var (ownerCoid, handle) in _clones)
        {
            // Alive only while owner and clone share a live map. Both-null is NOT alive: the
            // map's last-player-left reset (SectorMap.ResetLocalWorldToAuthored) tears down the
            // clone entity, and the handle must not linger as a zombie.
            var ownerMap = handle.Owner.Map;
            if (ownerMap != null && ownerMap == handle.Clone.Map)
            {
                MoveClone(handle, dt);
                continue;
            }

            if (_clones.TryRemove(ownerCoid, out var removed))
                CloneSpawner.Despawn(removed.Clone);
        }
    }

    private static void MoveClone(CloneHandle handle, float dt)
    {
        var heightfield = handle.Clone.Map?.MapData?.Heightfield;
        TerrainContactPlane.HeightSample sample = heightfield == null
            ? FlatAtCurrentHeight(handle.Clone)
            : heightfield.TrySample;

        var owner = handle.Owner.CurrentVehicle;
        var ownerForward = TerrainContactPlane.ForwardFromQuaternion(owner.Rotation);
        var ownerYaw = MathF.Atan2(ownerForward.X, ownerForward.Z);

        // Height convention is measured from the owner: whatever (Y − heightfield) delta the
        // player's grounded vehicle runs at is what the client renders as "on the ground".
        if (heightfield != null && heightfield.TrySample(owner.Position.X, owner.Position.Z, out var terrainAtOwner))
            handle.HeightCalibration.Observe(owner.Position.Y, terrainAtOwner, dt);

        var brain = handle.Brain;
        brain.Step(owner.Position, owner.Velocity, ownerYaw, sample, dt);

        var car = brain.Car;
        var heightOffset = heightfield != null ? handle.HeightCalibration.Offset : 0f;

        handle.DiagCountdown -= dt;
        if (handle.DiagCountdown <= 0f)
        {
            handle.DiagCountdown = 2f;
            var terrainAtClone = 0f;
            heightfield?.TrySample(car.Position.X, car.Position.Z, out terrainAtClone);
            Logger.WriteLog(LogType.Debug,
                $"CloneDiag: ownerY={owner.Position.Y:F2} cloneSimY={car.Position.Y:F2} " +
                $"terrainAtClone={terrainAtClone:F2} calibOffset={heightOffset:F2} " +
                $"trim={HeightTrim:F2} mode={handle.Brain.Mode} speed={PlanarSpeed(car):F1}");
        }
        var publishPosition = new AutoCore.Game.Structures.Vector3(
            car.Position.X, car.Position.Y + heightOffset + HeightTrim, car.Position.Z);

        if (brain.TeleportedThisStep)
        {
            // Discontinuous jump: SetPosition clears any stale physics bookkeeping, and the
            // ghost PositionMask still needs dirtying for the snap to reach clients.
            handle.Clone.SetPosition(publishPosition);
            handle.Clone.Rotation = car.Rotation;
            handle.Clone.Ghost?.SetMaskBits(AutoCore.Game.TNL.Ghost.GhostObject.PositionMask);
            return;
        }

        // Retail wire sign convention (VehicleDriveController.ComputeAxes: baseDir = −1 when
        // driving forward; brake-spec pedal = max(0, axis)): NEGATIVE throttle drives forward
        // and steer is baseDir·lateral. The sim brain uses positive-forward/positive-right, so
        // both axes flip here — publishing them raw animated the wheels backwards live.
        var inputs = brain.LastInputs;
        handle.Clone.ApplyServerMove(
            publishPosition,
            car.Rotation,
            car.Velocity,
            dt,
            driveThrottle: -inputs.Throttle,
            driveSteering: -inputs.Steering,
            sharpTurn: inputs.Handbrake ? (byte)1 : (byte)0,
            angularVelocity: new AutoCore.Game.Structures.Vector3(0f, car.YawRate, 0f));
    }

    private static float PlanarSpeed(AutoCore.Sim.Physics.RaycastCar car)
        => MathF.Sqrt(car.Velocity.X * car.Velocity.X + car.Velocity.Z * car.Velocity.Z);

    /// <summary>Maps without a heightfield (test maps, towns) drive on a flat plane at spawn height.</summary>
    private static TerrainContactPlane.HeightSample FlatAtCurrentHeight(Vehicle clone)
    {
        var y = clone.Position.Y;
        return (float x, float z, out float worldY) => { worldY = y; return true; };
    }
}

/// <summary>Live pairing of a player and their simulated clone vehicle.</summary>
public sealed class CloneHandle
{
    public CloneHandle(Character owner, Vehicle clone)
    {
        Owner = owner;
        Clone = clone;
        Brain = CloneManager.BuildBrainForHandle(clone);
    }

    public Character Owner { get; }
    public Vehicle Clone { get; }

    /// <summary>Physics-driven follow/orbit AI for this clone.</summary>
    public CloneDriveBrain Brain { get; }

    /// <summary>Learns the owner's wire-Y-vs-heightfield delta (client ground convention).</summary>
    public GroundOffsetCalibrator HeightCalibration { get; } = new();

    /// <summary>Seconds until the next CloneDiag log line.</summary>
    public float DiagCountdown { get; set; }
}
