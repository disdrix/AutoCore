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
    private float _orbitDirection = 1f; // +1 = clockwise when viewed from above (persistent)
    private float _avoidSign; // committed detour direction while feelers report obstacles

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

    /// <summary>Set when the last Step teleported the car (entity must publish via SetPosition).</summary>
    public bool TeleportedThisStep { get; private set; }

    /// <summary>Inputs applied on the last step, for the wire (throttle/steer animation).</summary>
    public DriveInputs LastInputs { get; private set; }

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
        }
        else
        {
            inputs = _stateMachine.Mode == CloneAiMode.Orbit
                ? OrbitInputs(playerPosition, playerSpeed)
                : FollowInputs(playerPosition, playerVelocity, separation);

            inputs = ApplyObstacleAvoidance(inputs);

            if (_stuckDetector.Update(_car.Position, inputs.Throttle, dt))
            {
                _recoverRemaining = _tuning.RecoverDuration;
                _recoverSteer = -MathF.Sign(inputs.Steering is 0f ? 1f : inputs.Steering);
                inputs = new DriveInputs(-0.8f, _recoverSteer, false);
            }
        }

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
                _car.BlockAt(prePosition);
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
        var world = Obstacles;
        if (world == null)
            return inputs;

        var speed = MathF.Sqrt(_car.Velocity.X * _car.Velocity.X + _car.Velocity.Z * _car.Velocity.Z);
        var feelerLength = speed * 1.2f + 5f;
        var origin = new Vector3(_car.Position.X, _car.Position.Y + 0.6f, _car.Position.Z);

        var steer = inputs.Steering;
        var throttle = inputs.Throttle;
        const float feelerAngle = 25f * MathF.PI / 180f;

        var centerHit = Feel(world, origin, _car.Position.Y, _car.Yaw, feelerLength, out var centerDist);
        var leftHit = Feel(world, origin, _car.Position.Y, _car.Yaw - feelerAngle, feelerLength, out var leftDist);
        var rightHit = Feel(world, origin, _car.Position.Y, _car.Yaw + feelerAngle, feelerLength, out var rightDist);

        if (leftHit || rightHit || centerHit)
        {
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

            var urgency = 1f - MathF.Min(centerHit ? centerDist : MathF.Min(leftDist, rightDist), feelerLength) / feelerLength;
            steer = Math.Clamp(steer + _avoidSign * (0.7f + 0.9f * urgency), -1f, 1f);

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
        return Math.Clamp(error / _car.Params.SteeringMaxAngleRad, -1f, 1f);
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
