using AutoCore.Game.Entities;
using AutoCore.Game.Npc;
using AutoCore.Game.Structures;

namespace AutoCore.Sim.Ai;

/// <summary>
/// Phase-2 mover and permanent debug fallback: critically-damped chase of a point behind the
/// target vehicle, yaw toward motion, terrain-aligned pose. Publishes through
/// Vehicle.ApplyServerMove so the ghost PositionMask dirties every tick. No physics — the
/// raycast-car engine replaces this as the default in Phase 3.
/// </summary>
public sealed class KinematicFollower
{
    public const float FollowDistanceMeters = 6f;

    /// <summary>Natural frequency of the critically damped chase spring (rad/s).</summary>
    public const float SpringOmega = 2.0f;

    private Vector3 _velocity;
    private float _yaw;
    private bool _yawInitialized;

    public void Step(Vehicle clone, Vehicle target, TerrainContactPlane.HeightSample sample, float dt)
    {
        if (clone == null || target == null || dt <= 0f)
            return;

        var forward = TerrainContactPlane.ForwardFromQuaternion(target.Rotation);
        var goalX = target.Position.X - forward.X * FollowDistanceMeters;
        var goalZ = target.Position.Z - forward.Z * FollowDistanceMeters;

        // Critically damped spring in XZ: a = w^2 * (goal - p) - 2w * v. No overshoot by
        // construction; velocity falls out for the wire.
        var ax = (SpringOmega * SpringOmega) * (goalX - clone.Position.X) - 2f * SpringOmega * _velocity.X;
        var az = (SpringOmega * SpringOmega) * (goalZ - clone.Position.Z) - 2f * SpringOmega * _velocity.Z;
        _velocity.X += ax * dt;
        _velocity.Z += az * dt;

        var newX = clone.Position.X + _velocity.X * dt;
        var newZ = clone.Position.Z + _velocity.Z * dt;

        if (!_yawInitialized)
        {
            _yaw = MathF.Atan2(forward.X, forward.Z);
            _yawInitialized = true;
        }

        var speed = MathF.Sqrt(_velocity.X * _velocity.X + _velocity.Z * _velocity.Z);
        if (speed > 0.5f)
            _yaw = MathF.Atan2(_velocity.X, _velocity.Z);

        var position = new Vector3(newX, clone.Position.Y, newZ);
        var rotation = clone.Rotation;
        if (sample != null
            && TerrainContactPlane.TryAlign(position, _yaw, sample, out var grounded, out var aligned))
        {
            position = grounded;
            rotation = aligned;
        }

        _velocity.Y = dt > 0f ? (position.Y - clone.Position.Y) / dt : 0f;

        clone.ApplyServerMove(
            position,
            rotation,
            _velocity,
            dt,
            driveThrottle: null,
            driveSteering: null,
            sharpTurn: 0,
            angularVelocity: null);
    }
}
