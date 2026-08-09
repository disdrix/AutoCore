using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Collision;
using AutoCore.Sim.Physics;

namespace AutoCore.Sim.Ai;

/// <summary>
/// Drives a RaycastCar to follow (player moving) or orbit (player stationary) its owner.
/// Pure pursuit: mode-specific aim point -> heading error -> steer/throttle inputs. Recovery:
/// reverse-and-turn when stuck, teleport catch-up beyond CatchUpDistance.
/// Deliberately entity-free (positions in, car state out) so closed-loop tests need no map.
/// </summary>
public sealed class CloneDriveBrain
{
    private readonly CloneAiTuning _tuning;
    private readonly CloneAiStateMachine _stateMachine;
    private readonly StuckDetector _stuckDetector = new();
    private readonly CompositeGround.Sampler _groundSampler = new();
    private readonly RaycastCar _car;
    private float _recoverRemaining;
    private float _recoverSteer;
    private int _consecutiveRecoveries;
    private float _sinceLastRecovery;
    private float _debugAccumulator;
    private float _orbitDirection = 1f; // +1 = clockwise when viewed from above (persistent)
    private float _avoidSign; // committed detour direction while feelers report obstacles
    private float _avoidClearTime; // seconds since the feelers last reported anything

    public CloneDriveBrain(SimVehicleParams parameters, CloneAiTuning tuning)
    {
        _tuning = tuning ?? throw new ArgumentNullException(nameof(tuning));
        _stateMachine = new CloneAiStateMachine(_tuning);
        _car = new RaycastCar(parameters);
    }

    public RaycastCar Car => _car;

    public CloneAiMode Mode => _stateMachine.Mode;

    /// <summary>Static hull world for feeler avoidance + hard blocking; null = terrain only.</summary>
    public StaticCollisionWorld Obstacles { get; set; }

    /// <summary>Another vehicle to steer around (position/velocity snapshot for this tick).</summary>
    public struct DynamicObstacle
    {
        public Vector3 Position;
        public Vector3 Velocity;
    }

    /// <summary>
    /// Minimum distance to keep from other vehicles (m). Default 4; /clone N &lt;spacing&gt;
    /// widens it per fleet so grouped clones hold formation gaps.
    /// </summary>
    public float DynamicStandoffRadius { get; set; } = 4.0f;

    private DynamicObstacle[] _dynObstacles;
    private int _dynObstacleCount;

    /// <summary>
    /// Per-tick snapshot of nearby vehicles (buffer owned by the caller, reused). The brain
    /// dodges them when possible — but never at the cost of steering into a static hull
    /// (static room is probed before committing a dodge side; both sides blocked = brake).
    /// </summary>
    public void SetDynamicObstacles(DynamicObstacle[] buffer, int count)
    {
        _dynObstacles = buffer;
        _dynObstacleCount = buffer == null ? 0 : Math.Min(count, buffer.Length);
    }

    /// <summary>
    /// /clonestop: brake to a halt and stay put — no follow, no orbit, and no catch-up
    /// teleport no matter how far the owner drives. /clonefollow clears it.
    /// </summary>
    public bool Hold { get; set; }

    private bool _catchUpRequested;

    /// <summary>/cloneteleport: jump behind the player on the next step.</summary>
    public void RequestCatchUp() => _catchUpRequested = true;

    // --- /clonestartpath: continuous arc-length route following (map path) ---
    // Retail semantics: the reference position moves ALONG the polyline; the vehicle chases
    // that moving reference. Point-to-point waypoint chasing chorded across geometry the
    // authored lane clears (brick-store alley, 2026-08-09) — vertices are never aim targets.
    private IReadOnlyList<Vector3> _pathWaypoints;
    private float[] _pathVertexArc; // cumulative arc length at each vertex (ascending index)
    private float _pathTotal;
    private float _pathRef; // car's current projected arc position
    private bool _pathLoops;
    private int _pathIndex;
    private int _pathDirection = 1; // +1 ascending indices, −1 for the ping-pong return leg

    public bool HasPathRoute => _pathWaypoints != null;

    /// <summary>True when the route wraps last→first (legacy ReverseDirection=false semantics).</summary>
    public bool PathLoops => _pathLoops;

    public int PathWaypointIndex => _pathIndex;

    /// <summary>
    /// Navigate the given waypoints with the sim (physics + avoidance, no snapping): loop
    /// routes wrap; open A→B routes ping-pong. Starts at the nearest point ON the polyline.
    /// Clears a hold. Authored accept distances are accepted for API stability but arc
    /// following supersedes them (vertices are not arrival targets).
    /// </summary>
    public void SetPathRoute(IReadOnlyList<Vector3> waypoints, bool loop,
        IReadOnlyList<float> acceptDistances = null)
    {
        if (waypoints == null || waypoints.Count < 2)
            return;

        _pathWaypoints = waypoints;
        _pathLoops = loop;
        _pathDirection = 1;
        Hold = false;

        var segments = loop ? waypoints.Count : waypoints.Count - 1;
        _pathVertexArc = new float[waypoints.Count + (loop ? 1 : 0)];
        var arc = 0f;
        for (var i = 0; i < segments; i++)
        {
            _pathVertexArc[i] = arc;
            arc += DistXZ(waypoints[i], waypoints[(i + 1) % waypoints.Count]);
        }

        _pathVertexArc[segments] = arc;
        _pathTotal = arc;
        _pathRef = ProjectOntoPath(_car.Position, nearArc: null);
        _pathIndex = VertexAhead(_pathRef);
    }

    public void ClearPathRoute() => _pathWaypoints = null;

    /// <summary>
    /// Nearest arc position on the polyline. When <paramref name="nearArc"/> is given, only
    /// segments within ~40 m of it (wrap-aware on loops) are considered, so folded paths
    /// (out-and-back alleys) do not snap the reference to a parallel lane.
    /// </summary>
    private float ProjectOntoPath(Vector3 position, float? nearArc)
    {
        var waypoints = _pathWaypoints;
        var segments = _pathLoops ? waypoints.Count : waypoints.Count - 1;
        var bestArc = 0f;
        var bestDistSq = float.MaxValue;
        var found = false;

        for (var pass = 0; pass < 2 && !found; pass++)
        {
            for (var i = 0; i < segments; i++)
            {
                if (pass == 0 && nearArc.HasValue
                    && ArcDistance(_pathVertexArc[i], nearArc.Value) > 40f
                    && ArcDistance(_pathVertexArc[i + 1], nearArc.Value) > 40f)
                {
                    continue;
                }

                var a = waypoints[i];
                var b = waypoints[(i + 1) % waypoints.Count];
                var segX = b.X - a.X;
                var segZ = b.Z - a.Z;
                var lenSq = segX * segX + segZ * segZ;
                if (lenSq < 0.01f)
                    continue;

                var t = Math.Clamp(
                    ((position.X - a.X) * segX + (position.Z - a.Z) * segZ) / lenSq, 0f, 1f);
                var px = a.X + segX * t;
                var pz = a.Z + segZ * t;
                var dSq = (position.X - px) * (position.X - px) + (position.Z - pz) * (position.Z - pz);
                if (dSq < bestDistSq)
                {
                    bestDistSq = dSq;
                    bestArc = _pathVertexArc[i] + MathF.Sqrt(lenSq) * t;
                    found = true;
                }
            }

            if (pass == 0 && !nearArc.HasValue)
                break; // global pass already ran
        }

        return bestArc;
    }

    private float ArcDistance(float a, float b)
    {
        var d = MathF.Abs(a - b);
        return _pathLoops ? MathF.Min(d, _pathTotal - d) : d;
    }

    private Vector3 PointAtArc(float arc)
    {
        var waypoints = _pathWaypoints;
        var segments = _pathLoops ? waypoints.Count : waypoints.Count - 1;
        if (_pathLoops)
            arc = ((arc % _pathTotal) + _pathTotal) % _pathTotal;
        else
            arc = Math.Clamp(arc, 0f, _pathTotal);

        for (var i = 0; i < segments; i++)
        {
            var end = _pathVertexArc[i + 1];
            if (arc <= end || i == segments - 1)
            {
                var a = waypoints[i];
                var b = waypoints[(i + 1) % waypoints.Count];
                var len = end - _pathVertexArc[i];
                var t = len > 0.01f ? (arc - _pathVertexArc[i]) / len : 0f;
                return new Vector3(a.X + (b.X - a.X) * t, a.Y, a.Z + (b.Z - a.Z) * t);
            }
        }

        return waypoints[^1];
    }

    /// <summary>Index of the vertex the reference is travelling toward.</summary>
    private int VertexAhead(float arc)
    {
        var waypoints = _pathWaypoints;
        var segments = _pathLoops ? waypoints.Count : waypoints.Count - 1;
        if (_pathDirection > 0)
        {
            for (var i = 0; i < segments; i++)
            {
                if (arc < _pathVertexArc[i + 1] - 0.01f)
                    return (i + 1) % waypoints.Count;
            }

            return _pathLoops ? 0 : waypoints.Count - 1;
        }

        for (var i = segments; i >= 1; i--)
        {
            if (arc > _pathVertexArc[i - 1] + 0.01f)
                return i - 1;
        }

        return 0;
    }

    private static float DistXZ(Vector3 a, Vector3 b)
    {
        var dx = a.X - b.X;
        var dz = a.Z - b.Z;
        return MathF.Sqrt(dx * dx + dz * dz);
    }

    /// <summary>Set when the last Step teleported the car (entity must publish via SetPosition).</summary>
    public bool TeleportedThisStep { get; private set; }

    /// <summary>Inputs applied on the last step, for the wire (throttle/steer animation).</summary>
    public DriveInputs LastInputs { get; private set; }

    /// <summary>
    /// Diagnostics sink (server log when wired by CloneManager): ~1 Hz status while pathing
    /// plus events — waypoint advances/skips, ping-pong flips, stuck/recovery, hard blocks.
    /// </summary>
    public Action<string> DebugLog { get; set; }

    private void Debug(string message) => DebugLog?.Invoke(message);

    public void Reset(Vector3 position, float yaw)
    {
        _car.SetPose(position, yaw);
        _stuckDetector.Reset();
        _recoverRemaining = 0f;
    }

    public void Step(
        Vector3 playerPosition,
        Vector3 playerVelocity,
        float playerYaw,
        TerrainContactPlane.HeightSample ground,
        float dt)
    {
        TeleportedThisStep = false;

        // Hull tops are drivable ground (bridges/decks/ramps); see CompositeGround. The
        // sampler instance is reused across steps (no per-step closure allocation).
        if (Obstacles != null)
        {
            _groundSampler.Update(ground, Obstacles, _car.Position.Y);
            ground = _groundSampler.Delegate;
        }

        // Teleport only on explicit request (/cloneteleport) — the automatic distance leash
        // was removed on user request 2026-08-09.
        if (_catchUpRequested)
        {
            _catchUpRequested = false;
            CatchUpTeleport(playerPosition, playerYaw, ground);
            return;
        }

        if (Hold)
        {
            // Brake against the SIGNED forward speed: a plain negative throttle becomes
            // reverse drive once speed crosses zero, which live sent the "stopped" clone
            // backing up forever. Inside the deadband, park with direct damping.
            var sin = MathF.Sin(_car.Yaw);
            var cos = MathF.Cos(_car.Yaw);
            var fwdSpeed = _car.Velocity.X * sin + _car.Velocity.Z * cos;
            DriveInputs holdInputs;
            if (fwdSpeed > 0.5f)
                holdInputs = new DriveInputs(-0.8f, 0f, false);
            else if (fwdSpeed < -0.5f)
                holdInputs = new DriveInputs(0.8f, 0f, false);
            else
            {
                holdInputs = new DriveInputs(0f, 0f, false);
                _car.ApplyParkingDamping(dt);
            }

            LastInputs = holdInputs;
            _car.Advance(dt, holdInputs, ground);
            return;
        }

        var toPlayerX = playerPosition.X - _car.Position.X;
        var toPlayerZ = playerPosition.Z - _car.Position.Z;
        var separation = MathF.Sqrt(toPlayerX * toPlayerX + toPlayerZ * toPlayerZ);

        var playerSpeed = MathF.Sqrt(
            playerVelocity.X * playerVelocity.X + playerVelocity.Z * playerVelocity.Z);
        _stateMachine.Update(playerSpeed, dt);

        DriveInputs inputs;
        if (_recoverRemaining > 0f)
        {
            _recoverRemaining -= dt;
            inputs = new DriveInputs(_recoverForward ? 0.8f : -0.8f, _recoverSteer, false);
            if (_recoverRemaining <= 0f)
                Debug($"recover end #{_consecutiveRecoveries} at ({_car.Position.X:F0},{_car.Position.Z:F0})");
        }
        else
        {
            _sinceLastRecovery += dt;
            if (_sinceLastRecovery > 4f)
                _consecutiveRecoveries = 0; // clean driving spell — reset escalation

            inputs = _pathWaypoints != null
                ? PathInputs()
                : _stateMachine.Mode == CloneAiMode.Orbit
                    ? OrbitInputs(playerPosition, playerSpeed)
                    : FollowInputs(playerPosition, playerVelocity, separation);

            inputs = ApplyObstacleAvoidance(inputs);

            if (_stuckDetector.Update(_car.Position, inputs.Throttle, dt))
            {
                StartRecovery(inputs.Steering);
                inputs = new DriveInputs(-0.8f, _recoverSteer, false);
            }
        }

        EmitPathTelemetry(dt);

        LastInputs = inputs;

        var prePosition = _car.Position;
        _car.Advance(dt, inputs, ground);

        // Hard block: whatever the feelers missed, the body may not enter a hull. The probe
        // sphere sits ABOVE step-up height so decks the car stands on / ledges it can climb
        // (CompositeGround handles those) never trigger — only genuine walls do. Revert the
        // planar move and kill speed — the stuck detector then drives the reverse-out.
        if (Obstacles != null)
        {
            var probe = new Vector3(
                _car.Position.X,
                _car.Position.Y + CompositeGround.StepUpHeight + HardBlockRadius,
                _car.Position.Z);
            if (Obstacles.SphereOverlap(probe, HardBlockRadius, out var blockLabel))
            {
                if (!_wasHardBlocked)
                    Debug($"hard BLOCK at ({_car.Position.X:F0},{_car.Position.Z:F0}) on '{blockLabel ?? "?"}'");
                _wasHardBlocked = true;
                _blockedTime += dt;
                // A block is not "clean driving": without this the recovery escalation counter
                // reset between ~6 s block-wander-block loops and STUCK #1 repeated forever,
                // so the unreachable-waypoint skip never fired.
                _sinceLastRecovery = 0f;
                _car.BlockAt(prePosition);

                if (_recoverRemaining > 0f && !_recoverForward)
                {
                    // Blocked while REVERSING (live trace 11:30:31: backed into a second
                    // obstacle and kept pushing) — flip the recovery to forward-turn.
                    _recoverForward = true;
                    Debug("recover blocked while reversing — FLIP to forward-turn");
                }
                else if (_recoverRemaining <= 0f && _blockedTime > 0.6f)
                {
                    // Pinned against a wall at full throttle: don't wait the ~2 s stuck
                    // window (live trace 11:30:24-26), recover now.
                    Debug($"BLOCKED {_blockedTime:F1}s on '{blockLabel ?? "?"}' — recovering immediately");
                    StartRecovery(LastInputs.Steering);
                    _blockedTime = 0f;
                }
            }
            else
            {
                _wasHardBlocked = false;
                _blockedTime = MathF.Max(0f, _blockedTime - dt * 2f);
            }
        }
    }

    private bool _wasHardBlocked;
    private float _blockedTime;
    private bool _recoverForward;

    /// <summary>Shared recovery entry: escalation, side alternation, path-waypoint skip.</summary>
    private void StartRecovery(float steerHint)
    {
        _consecutiveRecoveries++;
        _sinceLastRecovery = 0f;
        _recoverRemaining = _tuning.RecoverDuration * (1f + 0.5f * (_consecutiveRecoveries - 1));
        _recoverForward = false;
        var baseSign = -MathF.Sign(steerHint is 0f ? 1f : steerHint);
        _recoverSteer = _consecutiveRecoveries % 2 == 1 ? baseSign : -baseSign;
        Debug($"STUCK #{_consecutiveRecoveries} at ({_car.Position.X:F0},{_car.Position.Z:F0}) " +
              $"speed={PlanarSpeed():F1} -> reverse {_recoverRemaining:F1}s steer={_recoverSteer:+0;-0}");

        if (_pathWaypoints != null && _consecutiveRecoveries >= 3)
        {
            Debug($"stretch toward vertex {_pathIndex} unreachable after {_consecutiveRecoveries} recoveries — SKIPPING past it");
            SkipPastNextVertex();
            _consecutiveRecoveries = 0;
        }
    }

    private const float HardBlockRadius = 0.85f;

    /// <summary>
    /// Three forward feelers (center, ±25°). Side hits bias the steering away; a close center
    /// hit brakes proportionally. Classic feeler avoidance — good enough to route around props
    /// and buildings; the hard block above guarantees no penetration.
    /// </summary>
    private DriveInputs ApplyObstacleAvoidance(DriveInputs inputs)
    {
        inputs = ApplyDynamicAvoidance(inputs);

        var world = Obstacles;
        if (world == null)
            return inputs;

        var speed = MathF.Sqrt(_car.Velocity.X * _car.Velocity.X + _car.Velocity.Z * _car.Velocity.Z);
        // Live 2026-08-09: speed·1.2+5 (≈41 m at cruise) at ±25° swept ±17 m of roadside and
        // caused constant phantom avoidance. Short center feeler, shorter side feelers,
        // narrow cone — react to what is actually in the driving corridor.
        var feelerLength = MathF.Min(speed * 0.8f + 4f, 20f);
        var sideLength = feelerLength * 0.6f;
        var origin = new Vector3(_car.Position.X, _car.Position.Y + 0.6f, _car.Position.Z);

        var steer = inputs.Steering;
        var throttle = inputs.Throttle;
        const float feelerAngle = 15f * MathF.PI / 180f;

        // Scan where the car is GOING, not just where the nose points: aligning the fan with
        // the velocity heading catches walls on the inside of a turn arc (live 2026-08-09
        // 11:47: repeated corner-cut into the same brick store the nose-only fan never saw).
        // Velocity is used rather than the steer command — steer-based rotation fed back into
        // avoidance bias and oscillated in tight detours.
        var scanYaw = speed > 3f
            ? MathF.Atan2(_car.Velocity.X, _car.Velocity.Z)
            : _car.Yaw;
        var centerHit = Feel(world, origin, _car.Position.Y, scanYaw, feelerLength, out var centerDist);
        var leftHit = Feel(world, origin, _car.Position.Y, scanYaw - feelerAngle, sideLength, out var leftDist);
        var rightHit = Feel(world, origin, _car.Position.Y, scanYaw + feelerAngle, sideLength, out var rightDist);

        if (leftHit || rightHit || centerHit)
        {
            _avoidClearTime = 0f;

            // Commit to one detour side and KEEP it until the path clears — re-choosing every
            // tick flip-flopped between sides and stalled the clone nose-in against walls.
            if (_avoidSign == 0f)
            {
                if (leftHit && rightHit)
                    _avoidSign = leftDist < rightDist ? 1f : -1f;
                else if (leftHit)
                    _avoidSign = 1f;
                else if (rightHit)
                    _avoidSign = -1f;
                else
                    _avoidSign = steer >= 0f ? 1f : -1f;
            }

            // Strength scales with urgency² — a distant side graze nudges, a close wall
            // shoves. The old constant 0.7 floor slammed the wheel for anything the feelers
            // grazed, which read as violent weaving on open roads.
            var nearest = centerHit ? centerDist : MathF.Min(leftDist, rightDist);
            var urgency = 1f - MathF.Min(nearest, feelerLength) / feelerLength;
            var strength = centerHit ? 0.35f + 0.85f * urgency * urgency : 0.5f * urgency * urgency;
            steer = Math.Clamp(steer + _avoidSign * strength, -1f, 1f);

            if (centerHit)
            {
                // Slow for the turn but never stall: pure braking parked the clone facing the
                // wall forever. Keep rolling so the committed side-steer carries it around.
                var brakingDistance = speed * speed / (2f * _car.Params.MuMax * SimVehicleParams.Gravity) + 2.5f;
                if (centerDist < brakingDistance && speed > 6f)
                    throttle = -0.4f;
                else if (throttle > 0f)
                    throttle = MathF.Max(throttle, 0.5f);
                else if (throttle <= 0f)
                    throttle = 0.5f;
            }
        }
        else
        {
            // Release the committed side only after a short clear spell — instant release
            // re-armed the opposite feeler next tick and ping-ponged the wheel.
            _avoidClearTime += RaycastCar.SubstepDt * 3f; // ~tick scale; exactness irrelevant
            if (_avoidClearTime > 0.5f)
                _avoidSign = 0f;
        }

        return new DriveInputs(throttle, steer, inputs.Handbrake);
    }

    /// <summary>
    /// Vehicle-vs-vehicle avoidance. Runs BEFORE the static stage so static corrections are
    /// applied on top (static wins); additionally the dodge side itself is probed against the
    /// static world first — a dodge that would hit a wall flips side, and if both sides are
    /// walled the clone only brakes (user requirement: avoid vehicles when possible, never at
    /// the cost of hitting a static object).
    /// </summary>
    private DriveInputs ApplyDynamicAvoidance(DriveInputs inputs)
    {
        if (_dynObstacleCount == 0)
            return inputs;

        var sin = MathF.Sin(_car.Yaw);
        var cos = MathF.Cos(_car.Yaw);
        var worstUrgency = 0f;
        var worstLateral = 0f;
        var worstDistance = float.MaxValue;
        var worstClosing = false;

        for (var i = 0; i < _dynObstacleCount; i++)
        {
            var relX = _dynObstacles[i].Position.X - _car.Position.X;
            var relZ = _dynObstacles[i].Position.Z - _car.Position.Z;
            var distNow = MathF.Sqrt(relX * relX + relZ * relZ);
            if (distNow > 35f || distNow < 0.01f)
                continue;

            // Ignore traffic clearly behind us.
            var forwardDot = relX * sin + relZ * cos;
            if (forwardDot < -3f)
                continue;

            // Closest approach within a 2.5 s horizon (constant-velocity prediction).
            var relVx = _dynObstacles[i].Velocity.X - _car.Velocity.X;
            var relVz = _dynObstacles[i].Velocity.Z - _car.Velocity.Z;
            var vv = relVx * relVx + relVz * relVz;
            var t = vv > 0.01f ? Math.Clamp(-(relX * relVx + relZ * relVz) / vv, 0f, 2.5f) : 0f;
            var cxX = relX + relVx * t;
            var cxZ = relZ + relVz * t;
            var closest = MathF.Sqrt(cxX * cxX + cxZ * cxZ);
            var clearRadius = DynamicStandoffRadius;
            if (closest >= clearRadius)
                continue;

            var urgency = (clearRadius - closest) / clearRadius * (1f - t / 3.5f);
            if (urgency <= worstUrgency)
                continue;

            worstUrgency = urgency;
            worstDistance = distNow;
            worstClosing = (relX * relVx + relZ * relVz) < -0.1f || vv <= 0.01f;
            // Lateral offset of the predicted closest point: dodge away from that side.
            worstLateral = cxX * cos - cxZ * sin;
        }

        if (worstUrgency <= 0f)
            return inputs;

        // Dodge away from where the threat will be; near-zero lateral (dead ahead) defaults right.
        var dodgeSign = worstLateral > 0.2f ? -1f : worstLateral < -0.2f ? 1f : 1f;

        // Static priority: never dodge into a wall. Probe the dodge side; flip if blocked;
        // both blocked -> no steering dodge at all, brake only.
        var canDodge = true;
        if (Obstacles != null)
        {
            const float ProbeAngle = 0.45f; // rad off the nose toward the dodge side
            const float ProbeLength = 9f;
            if (StaticSideBlocked(dodgeSign * ProbeAngle, ProbeLength))
            {
                if (StaticSideBlocked(-dodgeSign * ProbeAngle, ProbeLength))
                    canDodge = false;
                else
                    dodgeSign = -dodgeSign;
            }
        }

        var steer = inputs.Steering;
        var throttle = inputs.Throttle;
        if (canDodge)
            steer = Math.Clamp(steer + dodgeSign * (0.3f + 0.6f * worstUrgency), -1f, 1f);

        // Brake for imminent conflicts (always; harder when a steering dodge is unavailable).
        var speed = MathF.Sqrt(_car.Velocity.X * _car.Velocity.X + _car.Velocity.Z * _car.Velocity.Z);
        if (worstClosing && worstDistance < (canDodge ? 8f : 14f) && speed > 4f)
            throttle = MathF.Min(throttle, canDodge ? -0.3f : -0.7f);

        return new DriveInputs(throttle, steer, inputs.Handbrake);
    }

    private bool StaticSideBlocked(float yawOffset, float length)
    {
        var yaw = _car.Yaw + yawOffset;
        var origin = new Vector3(_car.Position.X, _car.Position.Y + 0.6f, _car.Position.Z);
        var direction = new Vector3(MathF.Sin(yaw), 0f, MathF.Cos(yaw));
        return Obstacles.Raycast(origin, direction, length, out _, out var normal)
               && normal.Y <= 0.6f; // walkable slopes are not walls
    }

    private static bool Feel(StaticCollisionWorld world, Vector3 origin, float carY, float yaw, float length, out float distance)
    {
        var direction = new Vector3(MathF.Sin(yaw), 0f, MathF.Cos(yaw));
        if (!world.Raycast(origin, direction, length, out distance, out var normal))
            return false;

        // Walkable-facing surfaces (ramps, bridge-deck slopes) are drivable ground, not
        // obstacles — steering away from them kept the clone off every bridge approach.
        if (normal.Y > 0.6f)
            return false;

        // Wall-facing hit, but climbable? A ledge whose top just past the hit sits within
        // step-up height (low bridge decks, kerbs) is ground CompositeGround will lift us
        // onto — only report obstacles the car genuinely cannot mount.
        var probeX = origin.X + direction.X * (distance + 0.6f);
        var probeZ = origin.Z + direction.Z * (distance + 0.6f);
        var probeTop = carY + CompositeGround.StepUpHeight;
        if (world.Raycast(new Vector3(probeX, probeTop, probeZ), new Vector3(0f, -1f, 0f),
                CompositeGround.StepUpHeight + 2f, out var downDist, out var downNormal)
            && downNormal.Y > 0.3f)
        {
            var ledgeTop = probeTop - downDist;
            if (ledgeTop - carY <= CompositeGround.StepUpHeight)
                return false; // climbable — not an obstacle
        }

        return true;
    }

    /// <summary>Arc-length pursuit: chase a reference moving along the polyline.</summary>
    private DriveInputs PathInputs()
    {
        // Re-project near the previous reference (window keeps folded lanes from stealing it).
        _pathRef = ProjectOntoPath(_car.Position, _pathRef);

        // Ping-pong: flip direction when the CAR reaches an end of an open route.
        if (!_pathLoops)
        {
            if (_pathDirection > 0 && _pathTotal - _pathRef < 2f)
            {
                _pathDirection = -1;
                Debug("path end reached — ping-pong, now heading back");
            }
            else if (_pathDirection < 0 && _pathRef < 2f)
            {
                _pathDirection = 1;
                Debug("path start reached — ping-pong, now heading forward");
            }
        }

        var aimArc = _pathRef + _pathDirection * LaneLookaheadMeters;
        var aim = PointAtArc(aimArc);

        var newIndex = VertexAhead(_pathRef);
        if (newIndex != _pathIndex)
        {
            Debug($"waypoint advance {_pathIndex} -> {newIndex} ({_pathWaypoints.Count} total)");
            _pathIndex = newIndex;
        }

        var steer = PurePursuitSteer(aim.X, aim.Z);

        // Braking envelope across the horizon: every vertex within reach must be arrivable at
        // its corner speed (single-vertex anticipation could not brake across dense waypoints,
        // live 2026-08-09 12:06).
        var targetSpeed = _tuning.EffectivePathSpeed;
        const float BrakeDecel = 7f;
        var probeArc = _pathRef;
        for (var n = 0; n < 6; n++)
        {
            var vertex = NextVertexArc(probeArc);
            if (!vertex.HasValue)
                break;
            var distTo = ArcDistanceAlongDirection(_pathRef, vertex.Value);
            if (distTo > 45f)
                break;

            var sharp = VertexSharpness(vertex.Value);
            if (sharp > 0.05f)
            {
                var cornerSpeed = MathF.Max(6f, _tuning.EffectivePathSpeed * (1f - sharp));
                var allowed = MathF.Sqrt(cornerSpeed * cornerSpeed + 2f * BrakeDecel * MathF.Max(distTo, 0f));
                targetSpeed = MathF.Min(targetSpeed, allowed);
            }

            probeArc = vertex.Value + _pathDirection * 0.1f;
        }

        var headingError = MathF.Abs(HeadingErrorTo(aim.X, aim.Z));
        if (headingError > 0.4f)
            targetSpeed = MathF.Min(targetSpeed, MathF.Max(6f, _tuning.EffectivePathSpeed * (1.2f - headingError)));

        var throttle = SpeedControl(targetSpeed);
        return new DriveInputs(throttle, steer, Handbrake: false);
    }

    private const float LaneLookaheadMeters = 9f;

    /// <summary>Arc of the next vertex strictly ahead of <paramref name="arc"/>, if any.</summary>
    private float? NextVertexArc(float arc)
    {
        var segments = _pathLoops ? _pathWaypoints.Count : _pathWaypoints.Count - 1;
        if (_pathDirection > 0)
        {
            for (var i = 1; i <= segments; i++)
            {
                if (_pathVertexArc[i] > arc + 0.2f)
                    return _pathVertexArc[i];
            }

            return _pathLoops ? _pathVertexArc[1] + _pathTotal : null;
        }

        for (var i = segments - 1; i >= 0; i--)
        {
            if (_pathVertexArc[i] < arc - 0.2f)
                return _pathVertexArc[i];
        }

        return _pathLoops ? _pathVertexArc[segments - 1] - _pathTotal : null;
    }

    private float ArcDistanceAlongDirection(float from, float to)
        => MathF.Abs(to - from);

    /// <summary>0 = straight through the vertex at this arc, 1 = full U-turn.</summary>
    private float VertexSharpness(float vertexArc)
    {
        // Route ends of an open path are full turnarounds.
        var wrapped = _pathLoops
            ? ((vertexArc % _pathTotal) + _pathTotal) % _pathTotal
            : vertexArc;
        if (!_pathLoops && (wrapped <= 0.2f || wrapped >= _pathTotal - 0.2f))
            return 1f;

        var before = PointAtArc(wrapped - 2f);
        var at = PointAtArc(wrapped);
        var after = PointAtArc(wrapped + 2f);
        var inX = at.X - before.X;
        var inZ = at.Z - before.Z;
        var outX = after.X - at.X;
        var outZ = after.Z - at.Z;
        var inLen = MathF.Sqrt(inX * inX + inZ * inZ);
        var outLen = MathF.Sqrt(outX * outX + outZ * outZ);
        if (inLen < 0.2f || outLen < 0.2f)
            return 0f;

        var cos = (inX * outX + inZ * outZ) / (inLen * outLen);
        return MathF.Acos(Math.Clamp(cos, -1f, 1f)) / MathF.PI;
    }

    private float HeadingErrorTo(float x, float z)
    {
        var error = MathF.Atan2(x - _car.Position.X, z - _car.Position.Z) - _car.Yaw;
        if (error > MathF.PI) error -= 2f * MathF.PI;
        if (error < -MathF.PI) error += 2f * MathF.PI;
        return error;
    }

    /// <summary>Recovery escalation gave up on this stretch: jump the reference past the next
    /// vertex so the route continues beyond the unreachable pinch.</summary>
    private void SkipPastNextVertex()
    {
        var vertex = NextVertexArc(_pathRef);
        if (vertex.HasValue)
        {
            _pathRef = vertex.Value + _pathDirection * 3f;
            if (_pathLoops)
                _pathRef = ((_pathRef % _pathTotal) + _pathTotal) % _pathTotal;
            else
                _pathRef = Math.Clamp(_pathRef, 0f, _pathTotal);
        }
    }

    /// <summary>~1 Hz status while a path route is active.</summary>
    private void EmitPathTelemetry(float dt)
    {
        if (DebugLog == null || _pathWaypoints == null)
            return;

        _debugAccumulator += dt;
        if (_debugAccumulator < 1f)
            return;
        _debugAccumulator = 0f;

        var target = _pathWaypoints[Math.Clamp(_pathIndex, 0, _pathWaypoints.Count - 1)];
        var state = _recoverRemaining > 0f ? "RECOVERING" : Hold ? "HOLD" : "pathing";
        Debug($"path: waypoint {_pathIndex + 1}/{_pathWaypoints.Count} dist={DistXZ(target, _car.Position):F0}m " +
              $"{state} speed={PlanarSpeed():F1} thr={LastInputs.Throttle:F2} steer={LastInputs.Steering:F2} " +
              $"pos=({_car.Position.X:F0},{_car.Position.Y:F0},{_car.Position.Z:F0})");
    }

    private float PlanarSpeed() =>
        MathF.Sqrt(_car.Velocity.X * _car.Velocity.X + _car.Velocity.Z * _car.Velocity.Z);

    private DriveInputs FollowInputs(Vector3 playerPosition, Vector3 playerVelocity, float separation)
    {
        // Aim at the predicted player position, offset behind their motion so the clone trails.
        var speed = MathF.Sqrt(playerVelocity.X * playerVelocity.X + playerVelocity.Z * playerVelocity.Z);
        float behindX = 0f, behindZ = 0f;
        if (speed > 0.5f)
        {
            behindX = -playerVelocity.X / speed * _tuning.EffectiveFollowDistance;
            behindZ = -playerVelocity.Z / speed * _tuning.EffectiveFollowDistance;
        }
        var aimX = playerPosition.X + playerVelocity.X * _tuning.LookaheadSeconds + behindX;
        var aimZ = playerPosition.Z + playerVelocity.Z * _tuning.LookaheadSeconds + behindZ;

        var steer = PurePursuitSteer(aimX, aimZ);

        // Speed matching: player speed plus a distance-error term, capped at the governor.
        var distanceError = separation - _tuning.EffectiveFollowDistance;
        var targetSpeed = Math.Clamp(speed + distanceError * 0.8f, 0f, _car.Params.TopSpeed);
        var throttle = SpeedControl(targetSpeed);
        return new DriveInputs(throttle, steer, Handbrake: false);
    }

    private DriveInputs OrbitInputs(Vector3 playerPosition, float playerSpeed)
    {
        // Aim at a point on the orbit circle a fixed arc ahead of the clone's current bearing.
        var relX = _car.Position.X - playerPosition.X;
        var relZ = _car.Position.Z - playerPosition.Z;
        var bearing = MathF.Atan2(relX, relZ);
        const float arcAhead = 0.55f; // rad ahead along the circle
        var aimBearing = bearing + arcAhead * _orbitDirection;
        var aimX = playerPosition.X + MathF.Sin(aimBearing) * _tuning.OrbitRadius;
        var aimZ = playerPosition.Z + MathF.Cos(aimBearing) * _tuning.OrbitRadius;

        var steer = PurePursuitSteer(aimX, aimZ);
        var throttle = SpeedControl(_tuning.OrbitSpeed);
        return new DriveInputs(throttle, steer, Handbrake: false);
    }

    private float PurePursuitSteer(float aimX, float aimZ)
    {
        var dx = aimX - _car.Position.X;
        var dz = aimZ - _car.Position.Z;
        if (dx * dx + dz * dz < 0.25f)
            return 0f;

        var headingToAim = MathF.Atan2(dx, dz);
        var error = headingToAim - _car.Yaw;
        if (error > MathF.PI) error -= 2f * MathF.PI;
        if (error < -MathF.PI) error += 2f * MathF.PI;

        // PD: the yaw-rate term damps the proportional-only overshoot that had the clone
        // weaving around the pursuit line on open ground (live 2026-08-09).
        const float YawRateDamping = 0.35f;
        return Math.Clamp((error - YawRateDamping * _car.YawRate) / _car.Params.SteeringMaxAngleRad, -1f, 1f);
    }

    private float SpeedControl(float targetSpeed)
    {
        var speed = MathF.Sqrt(
            _car.Velocity.X * _car.Velocity.X + _car.Velocity.Z * _car.Velocity.Z);
        var error = targetSpeed - speed;
        if (error > 0.3f)
            return MathF.Min(1f, error * 0.5f);
        if (error < -1.5f)
            return MathF.Max(-1f, error * 0.25f); // brake when clearly too fast
        return 0f;
    }

    private void CatchUpTeleport(
        Vector3 playerPosition, float playerYaw, TerrainContactPlane.HeightSample ground)
    {
        var behindX = playerPosition.X - MathF.Sin(playerYaw) * _tuning.OrbitRadius;
        var behindZ = playerPosition.Z - MathF.Cos(playerYaw) * _tuning.OrbitRadius;
        var y = playerPosition.Y;
        if (ground != null && ground(behindX, behindZ, out var groundY))
            y = groundY; // wire convention: vehicle Y sits at terrain height

        _car.SetPose(new Vector3(behindX, y, behindZ), playerYaw);
        _stateMachine.ForceMode(CloneAiMode.Follow);
        _stuckDetector.Reset();
        _recoverRemaining = 0f;
        TeleportedThisStep = true;
        LastInputs = default;
    }
}
