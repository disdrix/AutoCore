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
    private readonly Collision.MapCollisionWorlds _collisionWorlds;

    public CloneManager(Collision.MapCollisionWorlds collisionWorlds = null)
    {
        _collisionWorlds = collisionWorlds ?? new Collision.MapCollisionWorlds();
    }

    /// <summary>
    /// Global publish-height trim (metres), live-tuned via /clonetrim to dial out the residual
    /// per-map body height that formulas and calibration leave behind.
    /// </summary>
    public static float HeightTrim { get; set; }

    public int ActiveCloneCount => _clones.Count;

    internal Ai.CloneDriveBrain BrainForTests(Character owner)
        => _clones.TryGetValue(owner.ObjectId.Coid, out var handle) ? handle.Brain : null;

    /// <summary>/clonestop / /clonefollow: park the caller's clone in place or resume the AI.</summary>
    public string SetHold(Character character, bool hold)
    {
        if (character == null)
            return "No character loaded.";
        if (!_clones.TryGetValue(character.ObjectId.Coid, out var handle))
            return "No clone active — use /clone first.";

        handle.Brain.Hold = hold;
        if (!hold)
            handle.Brain.ClearPathRoute(); // /clonefollow = resume following, from hold OR path
        return hold ? "Clone holding position." : "Clone resuming follow.";
    }

    /// <summary>
    /// /clonestartpath: navigate the map path nearest to the clone, waypoint by waypoint,
    /// using the sim (physics + avoidance — no pose snapping). Closed paths loop; open A→B
    /// paths ping-pong, matching typical fam path authoring.
    /// </summary>
    public string StartPath(Character character)
    {
        if (character == null)
            return "No character loaded.";
        if (!_clones.TryGetValue(character.ObjectId.Coid, out var handle))
            return "No clone active — use /clone first.";

        var templates = handle.Clone.Map?.MapData?.Templates;
        if (templates == null)
            return "No map data available.";

        AutoCore.Game.EntityTemplates.MapPathTemplate nearest = null;
        var nearestDist = float.MaxValue;
        var clonePos = handle.Clone.Position;
        foreach (var template in templates.Values)
        {
            if (template is not AutoCore.Game.EntityTemplates.MapPathTemplate path || path.Points.Count < 2)
                continue;

            foreach (var point in path.Points)
            {
                var dx = point.Position.X - clonePos.X;
                var dz = point.Position.Z - clonePos.Z;
                var d = MathF.Sqrt(dx * dx + dz * dz);
                if (d < nearestDist)
                {
                    nearestDist = d;
                    nearest = path;
                }
            }
        }

        if (nearest == null)
            return "No map paths on this map.";

        var waypoints = nearest.Points.Select(p => p.Position).ToArray();
        var accepts = nearest.Points.Select(p => p.AcceptDistance).ToArray();
        // Closed path (first ≈ last) → loop; otherwise ping-pong the A→B line.
        var dxEnds = waypoints[0].X - waypoints[^1].X;
        var dzEnds = waypoints[0].Z - waypoints[^1].Z;
        var loops = MathF.Sqrt(dxEnds * dxEnds + dzEnds * dzEnds) < 15f;

        handle.Brain.SetPathRoute(waypoints, loops, accepts);
        var label = string.IsNullOrWhiteSpace(nearest.PathName) ? $"#{nearest.COID}" : nearest.PathName;
        return $"Clone following path '{label}' ({waypoints.Length} waypoints, " +
               $"{(loops ? "loop" : "ping-pong")}, {nearestDist:0} m away).";
    }

    /// <summary>/cloneteleport: manual jump behind the caller (replaces the old auto-leash).</summary>
    public string Teleport(Character character)
    {
        if (character == null)
            return "No character loaded.";
        if (!_clones.TryGetValue(character.ObjectId.Coid, out var handle))
            return "No clone active — use /clone first.";

        handle.Brain.Hold = false;
        handle.Brain.RequestCatchUp();
        return "Clone teleporting to you.";
    }

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
        var coid = clone.ObjectId.Coid;
        brain.DebugLog = message =>
            Logger.WriteLog(LogType.Debug, $"CloneAI[{coid}]: {message}");
        var forward = TerrainContactPlane.ForwardFromQuaternion(clone.Rotation);
        brain.Reset(clone.Position, MathF.Atan2(forward.X, forward.Z));
        return brain;
    }

    /// <summary>Think phase runs in parallel above this fleet size (publish stays serial).</summary>
    public const int ParallelThinkThreshold = 8;

    private readonly List<CloneHandle> _aliveScratch = new();

    /// <summary>
    /// Per sector tick: lifecycle checks (serial), think phase — brain + physics against
    /// read-only world state — parallel at fleet scale, then a serial publish phase that
    /// mutates shared game state (pose, ghosts, ram damage). See DeferredWork.cs scale-out.
    /// </summary>
    public void Tick(long nowMs, float dt)
    {
        _aliveScratch.Clear();
        foreach (var (ownerCoid, handle) in _clones)
        {
            // Alive only while owner and clone share a live map. Both-null is NOT alive: the
            // map's last-player-left reset (SectorMap.ResetLocalWorldToAuthored) tears down the
            // clone entity, and the handle must not linger as a zombie.
            var ownerMap = handle.Owner.Map;
            if (ownerMap != null && ownerMap == handle.Clone.Map)
            {
                // Hull world attaches whenever the lazy background build completes; clones run
                // terrain-only until then (and forever if the build failed). Kept serial: it
                // touches the lazy-build table and may kick a SafeTask.
                handle.Brain.Obstacles ??= _collisionWorlds.GetOrRequest(ownerMap);
                _aliveScratch.Add(handle);
                continue;
            }

            if (_clones.TryRemove(ownerCoid, out var removed))
                CloneSpawner.Despawn(removed.Clone);
        }

        if (_aliveScratch.Count >= ParallelThinkThreshold)
        {
            var dtLocal = dt;
            Parallel.For(0, _aliveScratch.Count, i => ThinkClone(_aliveScratch[i], dtLocal));
        }
        else
        {
            foreach (var handle in _aliveScratch)
                ThinkClone(handle, dt);
        }

        foreach (var handle in _aliveScratch)
            PublishClone(handle, dt);
    }

    /// <summary>Parallel-safe: touches only the handle's brain/car and read-only world state.</summary>
    private static void ThinkClone(CloneHandle handle, float dt)
    {
        // Ground delegate cached per handle (a fresh method-group/closure per tick was
        // measurable GC load at fleet scale).
        var sample = handle.GroundSample;
        if (sample == null)
        {
            var heightfield = handle.Clone.Map?.MapData?.Heightfield;
            if (heightfield != null)
            {
                sample = heightfield.TrySample;
            }
            else
            {
                // No heightfield (test maps): flat plane pinned once in SIM space. Never derive
                // it from the published entity Y — that includes the ride-height offset and
                // feeds back as ever-rising ground.
                var flatY = handle.Brain.Car.Position.Y;
                sample = (float x, float z, out float y) => { y = flatY; return true; };
            }

            handle.GroundSample = sample;
        }

        var owner = handle.Owner.CurrentVehicle;
        var ownerForward = TerrainContactPlane.ForwardFromQuaternion(owner.Rotation);
        var ownerYaw = MathF.Atan2(ownerForward.X, ownerForward.Z);

        handle.Brain.Step(owner.Position, owner.Velocity, ownerYaw, sample, dt);
    }

    /// <summary>Serial: mutates shared game state (entity pose, ghost masks, ram damage).</summary>
    private static void PublishClone(CloneHandle handle, float dt)
    {
        var owner = handle.Owner.CurrentVehicle;
        var brain = handle.Brain;
        var sample = handle.GroundSample;
        var car = brain.Car;

        // Fully data-driven height (user decision 2026-08-09 — no owner calibration): the sim
        // grounds the chassis AT the heightfield, and publish adds the per-chassis ride height
        // (mean wheel radius − mean hardpoint Y, clonebase.wad via VehicleGroundMetricsCache)
        // plus the live /clonetrim knob.
        //
        // TODO(deferred by user until after the remaining phases — centimeter-perfect height
        // without any reference vehicle): the residual per-map wobble (±0.2–0.5 m, observed
        // live 2026-08-09 as owner deltas +0.46/+0.44/−0.19) comes from sampling geometry, not
        // scale: the server samples the height16 grid BILINEARLY, while the client renders a
        // TRIANGULATED terrain mesh from the same grid — between grid points the two surfaces
        // disagree by up to tens of centimeters depending on which diagonal the client splits
        // each quad on and the local slope. Fix plan: RE CVOGTerrain's mesh build (which
        // diagonal per cell — fixed, alternating, or data-driven), then replace
        // MapTerrainHeightfield.TrySample's bilinear blend with the matching two-triangle
        // barycentric interpolation. That makes server ground == client ground everywhere and
        // benefits every NPC, not just clones.
        var rideHeight = AutoCore.Game.Npc.VehicleGroundMetricsCache.GetRideHeight(handle.Clone.CBID);
        var heightOffset = rideHeight + HeightTrim;

        handle.DiagCountdown -= dt;
        if (handle.DiagCountdown <= 0f)
        {
            handle.DiagCountdown = 2f;
            var terrainAtClone = 0f;
            sample(car.Position.X, car.Position.Z, out terrainAtClone);
            Logger.WriteLog(LogType.Debug,
                $"CloneDiag: ownerY={owner.Position.Y:F2} cloneSimY={car.Position.Y:F2} " +
                $"terrainAtClone={terrainAtClone:F2} rideHeight={rideHeight:F2} " +
                $"trim={HeightTrim:F2} mode={handle.Brain.Mode} speed={PlanarSpeed(car):F1}");
        }
        // NOTE: heightOffset already includes HeightTrim (double-add fixed 2026-08-09).
        var publishPosition = new AutoCore.Game.Structures.Vector3(
            car.Position.X, car.Position.Y + heightOffset, car.Position.Z);

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
        // Ram-through destructibles: same pipeline as player vehicles (damage, loot,
        // destruction replication). Soft props are excluded from the hard collision world,
        // so the clone drives through them and this smashes them (live 2026-08-09 11:38:
        // it hard-blocked on a street light instead).
        var prePublishPosition = handle.Clone.Position;

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

        AutoCore.Game.Combat.VehicleMapPropRam.Process(handle.Clone, prePublishPosition, dt);
    }

    private static float PlanarSpeed(AutoCore.Sim.Physics.RaycastCar car)
        => MathF.Sqrt(car.Velocity.X * car.Velocity.X + car.Velocity.Z * car.Velocity.Z);

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

    /// <summary>Cached terrain sampler (heightfield delegate or pinned flat plane).</summary>
    public TerrainContactPlane.HeightSample GroundSample { get; set; }

    /// <summary>Seconds until the next CloneDiag log line.</summary>
    public float DiagCountdown { get; set; }
}
