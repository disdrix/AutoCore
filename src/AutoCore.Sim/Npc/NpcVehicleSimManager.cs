using System.Collections.Concurrent;
using AutoCore.Game.CloneBases;
using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Npc;
using AutoCore.Sim.Ai;
using AutoCore.Utils;

namespace AutoCore.Sim.Npc;

/// <summary>
/// Drives map NPC VEHICLES (never creatures) with the AutoCore.Sim physics engine — the same
/// RaycastCar + CloneDriveBrain stack the /clone feature uses. NpcTicker offers every pathed
/// idle-patrol vehicle through <see cref="AutoCore.Game.Npc.NpcVehicleSimControl"/>; adopted
/// vehicles follow their authored MapPath with real physics, static-hull + vehicle avoidance,
/// authored waypoint waits and reactions. Gated by serverConfig <c>sim.npcVehicles</c>
/// (default ON — the legacy movers are the fallback).
/// </summary>
public sealed class NpcVehicleSimManager
{
    private readonly Collision.MapCollisionWorlds _collisionWorlds;
    private readonly ConcurrentDictionary<long, NpcSimHandle> _handles = new();
    private readonly List<NpcSimHandle> _aliveScratch = new();

    public NpcVehicleSimManager(Collision.MapCollisionWorlds collisionWorlds = null)
    {
        _collisionWorlds = collisionWorlds ?? new Collision.MapCollisionWorlds();
    }

    public int ActiveVehicleCount => _handles.Count;

    /// <summary>Test seam: intercepts authored waypoint reaction firing (default = map.TriggerReactions).</summary>
    internal Action<Vehicle, long> FireReactionOverride { get; set; }

    internal CloneDriveBrain BrainForTests(Vehicle vehicle)
        => _handles.TryGetValue(vehicle.ObjectId.Coid, out var handle) ? handle.Brain : null;

    /// <summary>
    /// Called from NpcTicker (serial, under the interface lock) for each pathed NPC vehicle.
    /// Adopts on first sight; true = the Sim owns this vehicle's movement.
    /// </summary>
    public bool TryAdopt(Vehicle vehicle)
    {
        if (!ServerConfig.SimNpcVehiclesEnabled || vehicle == null)
            return false;

        if (_handles.ContainsKey(vehicle.ObjectId.Coid))
            return true;

        var map = vehicle.Map;
        if (map == null
            || !map.TryGetMapPath(vehicle.CoidCurrentPath, out var path)
            || path.Points.Count < 2)
        {
            return false;
        }

        var handle = new NpcSimHandle(vehicle, path);

        var waypoints = path.Points.Select(p => p.Position).ToArray();
        var accepts = path.Points.Select(p => p.AcceptDistance).ToArray();
        // Closed path (first ≈ last) → loop; otherwise ping-pong — same authoring heuristic
        // as CloneManager.StartPath.
        var dx = waypoints[0].X - waypoints[^1].X;
        var dz = waypoints[0].Z - waypoints[^1].Z;
        var loops = MathF.Sqrt(dx * dx + dz * dz) < 15f;
        handle.Brain.SetPathRoute(waypoints, loops, accepts);
        handle.LastVertexIndex = handle.Brain.PathWaypointIndex;

        _handles[vehicle.ObjectId.Coid] = handle;
        return true;
    }

    /// <summary>
    /// Per sector tick from SimHost: lifecycle (serial) → think (parallel at scale, read-only
    /// world state) → publish (serial, mutates entity pose / ghosts / reactions). Mirrors
    /// CloneManager.Tick.
    /// </summary>
    public void Tick(long nowMs, float dt)
    {
        _aliveScratch.Clear();
        foreach (var (coid, handle) in _handles)
        {
            var vehicle = handle.Vehicle;
            if (!ServerConfig.SimNpcVehiclesEnabled || vehicle.Map == null || vehicle.IsCorpse)
            {
                _handles.TryRemove(coid, out _);
                continue;
            }

            // Combat owns movement during pursuit/flee/return-home (NpcCombatAi lunges move
            // the entity directly). The sim stands down those ticks and reseats its physics
            // body at the live pose when combat releases, so the two never fight over pose.
            var ai = vehicle.NpcAi;
            if (ai != null && (ai.ReturningHome || nowMs < ai.FleeUntilMs || ai.PursuingThisTick))
            {
                handle.PausedForCombat = true;
                continue;
            }

            if (handle.PausedForCombat)
            {
                handle.PausedForCombat = false;
                var forward = TerrainContactPlane.ForwardFromQuaternion(vehicle.Rotation);
                handle.Brain.Reset(vehicle.Position, MathF.Atan2(forward.X, forward.Z));
            }

            handle.Brain.Obstacles ??= _collisionWorlds.GetOrRequest(vehicle.Map);
            _aliveScratch.Add(handle);
        }

        if (_aliveScratch.Count >= Clone.CloneManager.ParallelThinkThreshold)
        {
            var dtLocal = dt;
            Parallel.For(0, _aliveScratch.Count, i => Think(_aliveScratch[i], dtLocal));
        }
        else
        {
            foreach (var handle in _aliveScratch)
                Think(handle, dt);
        }

        foreach (var handle in _aliveScratch)
            Publish(handle, nowMs, dt);
    }

    /// <summary>Parallel-safe: touches only this handle's brain/car and read-only world state.</summary>
    private static void Think(NpcSimHandle handle, float dt)
    {
        var sample = handle.GroundSample;
        if (sample == null)
        {
            var heightfield = handle.Vehicle.Map?.MapData?.Heightfield;
            if (heightfield != null)
            {
                sample = heightfield.TrySample;
            }
            else
            {
                var flatY = handle.Brain.Car.Position.Y;
                sample = (float x, float z, out float y) => { y = flatY; return true; };
            }

            handle.GroundSample = sample;
        }

        CollectDynamicObstacles(handle);

        // Path mode ignores the "player" arguments; the vehicle's own pose keeps the state
        // machine well-defined.
        handle.Brain.Step(handle.Vehicle.Position, handle.Vehicle.Velocity, 0f, sample, dt);
    }

    private static void CollectDynamicObstacles(NpcSimHandle handle)
    {
        var map = handle.Vehicle.Map;
        if (map?.Grid == null)
        {
            handle.Brain.SetDynamicObstacles(null, 0);
            return;
        }

        var scratch = handle.QueryScratch;
        scratch.Clear();
        map.Grid.QueryRadius(handle.Vehicle.Position, 35f, scratch);

        var buffer = handle.DynamicBuffer;
        var count = 0;
        foreach (var obj in scratch)
        {
            if (count >= buffer.Length)
                break;
            if (obj is not Vehicle other || ReferenceEquals(other, handle.Vehicle) || other.IsCorpse)
                continue;

            buffer[count++] = new CloneDriveBrain.DynamicObstacle
            {
                Position = other.Position,
                Velocity = other.Velocity,
            };
        }

        handle.Brain.SetDynamicObstacles(buffer, count);
    }

    /// <summary>Serial: publishes pose to the ghost pipeline and services waypoint waits/reactions.</summary>
    private void Publish(NpcSimHandle handle, long nowMs, float dt)
    {
        var vehicle = handle.Vehicle;
        var brain = handle.Brain;
        var car = brain.Car;

        ServiceWaypointEvents(handle, nowMs);

        var rideHeight = VehicleGroundMetricsCache.GetRideHeight(vehicle.CBID);
        var publishPosition = new AutoCore.Game.Structures.Vector3(
            car.Position.X,
            car.Position.Y + rideHeight + Clone.CloneManager.HeightTrim,
            car.Position.Z);

        if (ServerConfig.SimDebugLogs)
        {
            handle.DiagCountdown -= dt;
            if (handle.DiagCountdown <= 0f)
            {
                handle.DiagCountdown = 2f;
                Logger.WriteLog(LogType.Debug,
                    $"NpcSimDiag[{vehicle.ObjectId.Coid}]: y={car.Position.Y:F2} " +
                    $"wp={brain.PathWaypointIndex} hold={brain.Hold} " +
                    $"speed={MathF.Sqrt(car.Velocity.X * car.Velocity.X + car.Velocity.Z * car.Velocity.Z):F1}");
            }
        }

        if (brain.TeleportedThisStep)
        {
            vehicle.SetPosition(publishPosition);
            vehicle.Rotation = car.Rotation;
            vehicle.Ghost?.SetMaskBits(AutoCore.Game.TNL.Ghost.GhostObject.PositionMask);
            return;
        }

        // Retail wire sign convention: negative throttle = forward, steer = baseDir·lateral
        // (see CloneManager.PublishClone).
        var prePublishPosition = vehicle.Position;
        var inputs = brain.LastInputs;
        vehicle.ApplyServerMove(
            publishPosition,
            car.Rotation,
            car.Velocity,
            dt,
            driveThrottle: -inputs.Throttle,
            driveSteering: -inputs.Steering,
            sharpTurn: inputs.Handbrake ? (byte)1 : (byte)0,
            angularVelocity: new AutoCore.Game.Structures.Vector3(0f, car.YawRate, 0f));

        AutoCore.Game.Combat.VehicleMapPropRam.Process(vehicle, prePublishPosition, dt);
    }

    /// <summary>
    /// Authored waypoint waits and reactions: when the arc reference passes a vertex
    /// (PathWaypointIndex advanced), fire that vertex's ReactionCoid and engage its WaitTime
    /// as a brain hold. Legacy NpcPathFollower behaviour, preserved under the sim mover.
    /// </summary>
    private void ServiceWaypointEvents(NpcSimHandle handle, long nowMs)
    {
        var brain = handle.Brain;

        if (brain.Hold)
        {
            if (handle.HoldUntilMs > 0 && nowMs >= handle.HoldUntilMs)
            {
                handle.HoldUntilMs = 0;
                brain.Hold = false;
            }

            return;
        }

        var index = brain.PathWaypointIndex;
        if (index == handle.LastVertexIndex)
            return;

        var passed = handle.LastVertexIndex;
        handle.LastVertexIndex = index;
        var points = handle.Path.Points;
        if (passed < 0 || passed >= points.Count)
            return;

        var point = points[passed];
        if (point.ReactionCoid > 0)
        {
            var fire = FireReactionOverride;
            if (fire != null)
                fire(handle.Vehicle, point.ReactionCoid);
            else
                handle.Vehicle.Map?.TriggerReactions(
                    handle.Vehicle, new List<long> { point.ReactionCoid });
        }

        if (point.WaitTime > 0)
        {
            brain.Hold = true;
            handle.HoldUntilMs = nowMs + point.WaitTime;
        }
    }
}

/// <summary>Live pairing of a map NPC vehicle and its sim brain.</summary>
internal sealed class NpcSimHandle
{
    public NpcSimHandle(Vehicle vehicle, MapPathTemplate path)
    {
        Vehicle = vehicle;
        Path = path;
        Brain = Clone.CloneManager.BuildBrainForHandle(vehicle, new CloneAiTuning
        {
            PathSpeed = ResolvePatrolSpeed(vehicle),
        });
    }

    /// <summary>Authored patrol speed: driver creature clonebase Speed, else the legacy 12 u/s.</summary>
    private static float ResolvePatrolSpeed(Vehicle vehicle)
    {
        var driver = vehicle.Owner?.GetAsCreature();
        var speed = (driver?.CloneBaseObject as CloneBaseCreature)?.CreatureSpecific.Speed ?? 0f;
        return speed > 0f ? speed : NpcTicker.DefaultVehicleSpeed;
    }

    public Vehicle Vehicle { get; }
    public MapPathTemplate Path { get; }
    public CloneDriveBrain Brain { get; }
    public TerrainContactPlane.HeightSample GroundSample { get; set; }
    public List<ClonedObjectBase> QueryScratch { get; } = new(32);
    public CloneDriveBrain.DynamicObstacle[] DynamicBuffer { get; } =
        new CloneDriveBrain.DynamicObstacle[16];

    /// <summary>Brain's next-vertex index last tick; a change means a vertex was passed.</summary>
    public int LastVertexIndex { get; set; }

    /// <summary>Authored WaitTime hold deadline (ms); 0 = no wait pending.</summary>
    public long HoldUntilMs { get; set; }

    /// <summary>True while combat (pursuit/flee/return-home) owns this vehicle's movement.</summary>
    public bool PausedForCombat { get; set; }

    /// <summary>Seconds until the next NpcSimDiag log line (gated by sim.debugLogs).</summary>
    public float DiagCountdown { get; set; }
}
