using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
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

    public CloneDriveBrain(SimVehicleParams parameters, CloneAiTuning tuning)
    {
        _tuning = tuning ?? throw new ArgumentNullException(nameof(tuning));
        _stateMachine = new CloneAiStateMachine(_tuning);
        _car = new RaycastCar(parameters);
    }

    public RaycastCar Car => _car;

    public CloneAiMode Mode => _stateMachine.Mode;

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

        var toPlayerX = playerPosition.X - _car.Position.X;
        var toPlayerZ = playerPosition.Z - _car.Position.Z;
        var separation = MathF.Sqrt(toPlayerX * toPlayerX + toPlayerZ * toPlayerZ);
        if (separation > _tuning.CatchUpDistance)
        {
            CatchUpTeleport(playerPosition, playerYaw, ground);
            return;
        }

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

            if (_stuckDetector.Update(_car.Position, inputs.Throttle, dt))
            {
                _recoverRemaining = _tuning.RecoverDuration;
                _recoverSteer = -MathF.Sign(inputs.Steering is 0f ? 1f : inputs.Steering);
                inputs = new DriveInputs(-0.8f, _recoverSteer, false);
            }
        }

        LastInputs = inputs;
        _car.Advance(dt, inputs, ground);
    }

    private DriveInputs FollowInputs(Vector3 playerPosition, Vector3 playerVelocity, float separation)
    {
        // Aim at the predicted player position, offset behind their motion so the clone trails.
        var speed = MathF.Sqrt(playerVelocity.X * playerVelocity.X + playerVelocity.Z * playerVelocity.Z);
        float behindX = 0f, behindZ = 0f;
        if (speed > 0.5f)
        {
            behindX = -playerVelocity.X / speed * _tuning.FollowDistance;
            behindZ = -playerVelocity.Z / speed * _tuning.FollowDistance;
        }
        var aimX = playerPosition.X + playerVelocity.X * _tuning.LookaheadSeconds + behindX;
        var aimZ = playerPosition.Z + playerVelocity.Z * _tuning.LookaheadSeconds + behindZ;

        var steer = PurePursuitSteer(aimX, aimZ);

        // Speed matching: player speed plus a distance-error term, capped at the governor.
        var distanceError = separation - _tuning.FollowDistance;
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
