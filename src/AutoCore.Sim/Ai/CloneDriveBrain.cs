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

    /// <summary>
    /// /clonestop: brake to a halt and stay put — no follow, no orbit, and no catch-up
    /// teleport no matter how far the owner drives. /clonefollow clears it.
    /// </summary>
    public bool Hold { get; set; }

    private bool _catchUpRequested;

    /// <summary>/cloneteleport: jump behind the player on the next step.</summary>
    public void RequestCatchUp() => _catchUpRequested = true;

    // --- /clonestartpath: waypoint route (map path) instead of follow/orbit ---
    private IReadOnlyList<Vector3> _pathWaypoints;
    private bool _pathLoops;
    private int _pathIndex;
    private int _pathDirection = 1; // +1 forward, −1 for the ping-pong return leg

    public bool HasPathRoute => _pathWaypoints != null;

    public int PathWaypointIndex => _pathIndex;

    /// <summary>
    /// Navigate the given waypoints with the sim (physics + avoidance, no snapping): loop
    /// routes wrap; open A→B routes ping-pong. Starts at the nearest waypoint. Clears a hold.
    /// </summary>
    public void SetPathRoute(IReadOnlyList<Vector3> waypoints, bool loop)
    {
        if (waypoints == null || waypoints.Count < 2)
            return;

        _pathWaypoints = waypoints;
        _pathLoops = loop;
        _pathDirection = 1;
        Hold = false;

        var best = 0;
        var bestDist = float.MaxValue;
        for (var i = 0; i < waypoints.Count; i++)
        {
            var d = DistXZ(waypoints[i], _car.Position);
            if (d < bestDist)
            {
                bestDist = d;
                best = i;
            }
        }

        _pathIndex = best;
    }

    public void ClearPathRoute() => _pathWaypoints = null;

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

        // Hull tops are drivable ground (bridges/decks/ramps); see CompositeGround.
        ground = CompositeGround.Wrap(ground, Obstacles, _car.Position.Y);

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
            inputs = new DriveInputs(-0.8f, _recoverSteer, false);
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
                _consecutiveRecoveries++;
                _sinceLastRecovery = 0f;
                // Escalate: alternate the reverse-turn side each attempt (the same arc into
                // the same obstacle ping-ponged forever), reverse a little longer each time.
                _recoverRemaining = _tuning.RecoverDuration * (1f + 0.5f * (_consecutiveRecoveries - 1));
                var baseSign = -MathF.Sign(inputs.Steering is 0f ? 1f : inputs.Steering);
                _recoverSteer = _consecutiveRecoveries % 2 == 1 ? baseSign : -baseSign;
                Debug($"STUCK #{_consecutiveRecoveries} at ({_car.Position.X:F0},{_car.Position.Z:F0}) " +
                      $"speed={PlanarSpeed():F1} -> reverse {_recoverRemaining:F1}s steer={_recoverSteer:+0;-0}");

                // Path mode: an unreachable waypoint (buried in a hull, walled off) would
                // recover forever — skip it after repeated failures and keep the route alive.
                if (_pathWaypoints != null && _consecutiveRecoveries >= 3)
                {
                    Debug($"waypoint {_pathIndex} unreachable after {_consecutiveRecoveries} recoveries — SKIPPING");
                    AdvanceWaypoint();
                    _consecutiveRecoveries = 0;
                }

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
            if (Obstacles.SphereOverlap(probe, HardBlockRadius))
            {
                if (!_wasHardBlocked)
                    Debug($"hard BLOCK at ({_car.Position.X:F0},{_car.Position.Z:F0})");
                _wasHardBlocked = true;
                _car.BlockAt(prePosition);
            }
            else
            {
                _wasHardBlocked = false;
            }
        }
    }

    private bool _wasHardBlocked;

    private const float HardBlockRadius = 0.85f;

    /// <summary>
    /// Three forward feelers (center, ±25°). Side hits bias the steering away; a close center
    /// hit brakes proportionally. Classic feeler avoidance — good enough to route around props
    /// and buildings; the hard block above guarantees no penetration.
    /// </summary>
    private DriveInputs ApplyObstacleAvoidance(DriveInputs inputs)
    {
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

        var centerHit = Feel(world, origin, _car.Position.Y, _car.Yaw, feelerLength, out var centerDist);
        var leftHit = Feel(world, origin, _car.Position.Y, _car.Yaw - feelerAngle, sideLength, out var leftDist);
        var rightHit = Feel(world, origin, _car.Position.Y, _car.Yaw + feelerAngle, sideLength, out var rightDist);

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

    /// <summary>Waypoint pursuit: aim at the current point, advance inside the accept radius.</summary>
    private DriveInputs PathInputs()
    {
        var target = _pathWaypoints[_pathIndex];
        if (DistXZ(target, _car.Position) < _tuning.PathAcceptDistance)
        {
            AdvanceWaypoint();
            target = _pathWaypoints[_pathIndex];
        }

        var steer = PurePursuitSteer(target.X, target.Z);
        var throttle = SpeedControl(_tuning.EffectivePathSpeed);
        return new DriveInputs(throttle, steer, Handbrake: false);
    }

    private void AdvanceWaypoint()
    {
        var waypoints = _pathWaypoints;
        var next = _pathIndex + _pathDirection;
        if (_pathLoops)
        {
            next = (next + waypoints.Count) % waypoints.Count;
        }
        else if (next < 0 || next >= waypoints.Count)
        {
            _pathDirection = -_pathDirection; // A→B line: ping-pong at the ends
            next = _pathIndex + _pathDirection;
            Debug($"path end reached — ping-pong, now heading {(_pathDirection > 0 ? "forward" : "back")}");
        }

        Debug($"waypoint advance {_pathIndex} -> {next} ({waypoints.Count} total)");
        _pathIndex = next;
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

        var target = _pathWaypoints[_pathIndex];
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
