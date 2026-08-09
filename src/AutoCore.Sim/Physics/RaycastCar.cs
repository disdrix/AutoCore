using AutoCore.Game.Npc;
using AutoCore.Game.Structures;

namespace AutoCore.Sim.Physics;

/// <summary>Driver inputs for one frame. Throttle −1..1 (negative = brake/reverse pedal).</summary>
public readonly record struct DriveInputs(float Throttle, float Steering, bool Handbrake);

/// <summary>
/// Deterministic raycast-car approximation of the client's Havok vehicle behavior, built to the
/// behavioral spec sheet in docs/reconstruction/physics/ (NOT the bit-exact port in
/// AutoCore.Game/Physics/Vehicle — deliberate separate implementation):
/// - fixed 1/60 s substeps behind an accumulator (0.1-step-rate.md),
/// - suspension heave F = (strength·compression/length − damp·closing)·mass (0.4-suspension.md),
/// - traction-limited drive with the retail low-speed boost and gearing governor,
/// - quadratic steering falloff above SteeringFullSpeedLimit (steering-spec.md),
/// - friction-circle coupling of longitudinal/lateral tire force (0.3-friction-solver.md),
/// - forward-speed-only aero drag (0.6-aerodynamics.md), ballistic when airborne.
/// State is x/y/z + yaw with terrain-aligned pitch/roll for presentation; a full 6-DOF body is
/// deliberately out of scope for this tier.
///
/// Cornering status (live session 2026-08-09): with wheelset-data friction the turning was
/// judged "much better — good enough for now"; further parity work (per-axle grip split,
/// retail circle-projection LUT, steering ramp shape) is DEFERRED until the user asks.
/// </summary>
public sealed class RaycastCar
{
    public const float SubstepDt = 1f / 60f;
    public const int MaxSubstepsPerAdvance = 8;

    /// <summary>Retail low-speed traction boost: μ·((15−v)·0.2+1), max ×4 at rest.</summary>
    private const float LowSpeedBoostThreshold = 15f;
    private const float LowSpeedBoostSlope = 0.2f;
    private const float MaxLowSpeedBoost = 4f;

    /// <summary>Steering rate stage-2 step per substep (applyAction: ±0.05 per tick).</summary>
    private const float SteeringStepPerTick = 0.05f;

    /// <summary>Reverse governor as a fraction of forward top speed (single reverse gear).</summary>
    private const float ReverseTopSpeedFraction = 0.35f;

    private readonly SimVehicleParams _params;
    private float _dtAccumulator;
    private float _steeringActual;

    public RaycastCar(SimVehicleParams parameters)
    {
        _params = parameters ?? throw new ArgumentNullException(nameof(parameters));
    }

    public SimVehicleParams Params => _params;
    public Vector3 Position { get; private set; }
    public Vector3 Velocity { get; private set; }
    public float Yaw { get; private set; }
    public float YawRate { get; private set; }
    public bool Grounded { get; private set; }
    public Quaternion Rotation { get; private set; } = new(0, 0, 0, 1);

    /// <summary>Current steering wheel angle actually applied (radians), for wire animation.</summary>
    public float AppliedSteering => _steeringActual;

    public void SetPose(Vector3 position, float yaw)
    {
        Position = position;
        Yaw = yaw;
        Velocity = default;
        YawRate = 0f;
        _steeringActual = 0f;
        _dtAccumulator = 0f;
        Rotation = TerrainContactPlane.FromYawPitchRoll(yaw, 0f, 0f);
    }

    internal void SetVelocityForTests(Vector3 velocity) => Velocity = velocity;

    public void Advance(float frameDt, DriveInputs inputs, TerrainContactPlane.HeightSample ground)
    {
        if (!float.IsFinite(frameDt) || frameDt <= 0f)
            return;

        _dtAccumulator = MathF.Min(_dtAccumulator + frameDt, MaxSubstepsPerAdvance * SubstepDt);
        while (_dtAccumulator >= SubstepDt)
        {
            _dtAccumulator -= SubstepDt;
            Substep(inputs, ground);
        }
    }

    private void Substep(DriveInputs inputs, TerrainContactPlane.HeightSample ground)
    {
        const float dt = SubstepDt;

        var sinYaw = MathF.Sin(Yaw);
        var cosYaw = MathF.Cos(Yaw);
        // Chassis basis: forward = (sin yaw, 0, cos yaw), right = (cos yaw, 0, −sin yaw).
        var fwdSpeed = Velocity.X * sinYaw + Velocity.Z * cosYaw;
        var latSpeed = Velocity.X * cosYaw - Velocity.Z * sinYaw;
        var planarSpeed = MathF.Sqrt(fwdSpeed * fwdSpeed + latSpeed * latSpeed);

        // --- ground contact (wheel ray down from chassis) ---
        // Wire convention: Position.Y rests AT terrain height (client renders suspension), so
        // the spring equilibrium sits at groundY: compression there equals RestCompression and
        // strength·(x/L) exactly balances gravity.
        var groundY = 0f;
        var hasGround = ground != null && ground(Position.X, Position.Z, out groundY);
        var heightAboveGround = hasGround ? Position.Y - groundY : float.MaxValue;
        const float GroundContactMargin = 0.6f; // suspension travel window before airborne
        Grounded = hasGround && heightAboveGround < GroundContactMargin;

        var newVelY = Velocity.Y - SimVehicleParams.Gravity * dt;
        if (Grounded)
        {
            // Bidirectional within the contact window: compressed below rest pushes up, extended
            // above rest pulls DOWN (terrain adhesion). Without the down-pull the body surfed a
            // RestCompression-sized gap on every descent (live 2026-08-09, mean 0.5 m on a 12%
            // grade). Down-pull is capped at 2 g so cresting a jump still goes ballistic.
            // TODO(live 2026-08-09, deferred by user): cresting a climb still looks "low
            // gravity" — the body lags coming back down onto level ground after an ascent.
            // Likely fix: raise the down-pull cap (or scale it with forward speed) when the
            // contact gap opened from below (crest) rather than from terrain dropping away
            // (jump), so crests reseat fast while jumps stay ballistic.
            var compression = _params.RestCompression - heightAboveGround;
            var closing = -Velocity.Y; // positive when compressing
            var damp = closing >= 0f ? _params.SuspensionDampCompression : _params.SuspensionDampExtension;
            var suspensionAccel = _params.SuspensionStrength * (compression / _params.SuspensionLength)
                                  - damp * closing * -1f; // damping opposes motion: −damp·(dY/dt)
            suspensionAccel = MathF.Max(suspensionAccel, -2f * SimVehicleParams.Gravity);
            newVelY += suspensionAccel * dt;

            // Anti-sink (0.4-suspension.md): position-only correction, never below terrain.
            if (Position.Y + newVelY * dt < groundY - 0.1f)
                Position = new Vector3(Position.X, groundY - 0.1f, Position.Z);
        }

        // --- steering (steering-spec.md) ---
        var desired = Math.Clamp(inputs.Steering, -1f, 1f);
        var step = SteeringStepPerTick;
        if (MathF.Abs(desired - _steeringActual) <= step)
            _steeringActual = desired;
        else
            _steeringActual += MathF.Sign(desired - _steeringActual) * step;

        var authority = 1f;
        var absFwd = MathF.Abs(fwdSpeed);
        if (absFwd > _params.SteeringFullSpeedLimit && absFwd > 0.01f)
        {
            var ratio = _params.SteeringFullSpeedLimit / absFwd;
            authority = ratio * ratio;
        }
        var wheelAngle = _params.SteeringMaxAngleRad * _steeringActual * authority;

        // --- tire forces (grounded only) ---
        var accelFwd = 0f;
        var accelLat = 0f;
        if (Grounded)
        {
            var boost = planarSpeed < LowSpeedBoostThreshold
                ? MathF.Min((LowSpeedBoostThreshold - planarSpeed) * LowSpeedBoostSlope + 1f, MaxLowSpeedBoost)
                : 1f;
            // Retail's low-speed boost multiplies wheel μ, so it raises the lateral grip
            // budget too — without it the clone cornered far wider than the player.
            var muBudget = _params.MuMax * SimVehicleParams.Gravity * boost;
            var rearGrip = inputs.Handbrake ? 0.5f : 1f;

            // Longitudinal demand: drive toward the governor, brake against motion.
            var throttle = Math.Clamp(inputs.Throttle, -1f, 1f);
            if (throttle > 0f && fwdSpeed < _params.TopSpeed)
                accelFwd = throttle * _params.MuBase * SimVehicleParams.Gravity * MathF.Min(boost, 2f);
            else if (throttle < 0f)
            {
                if (fwdSpeed > 0.3f)
                    accelFwd = throttle * _params.MuMax * SimVehicleParams.Gravity * boost; // brake
                else
                    accelFwd = throttle * _params.MuBase * SimVehicleParams.Gravity; // reverse
            }

            // Yaw follows the kinematic bicycle toward v·tan(δ)/L, limited by lateral grip.
            var targetYawRate = MathF.Abs(fwdSpeed) > 0.05f
                ? fwdSpeed * MathF.Tan(wheelAngle) / _params.WheelBase
                : 0f;
            var latBudget = muBudget * rearGrip * _params.RearMuScale;
            var maxYawRate = MathF.Abs(fwdSpeed) > 0.5f ? latBudget / MathF.Abs(fwdSpeed) : 4f;
            targetYawRate = Math.Clamp(targetYawRate, -maxYawRate, maxYawRate);
            YawRate += (targetYawRate - YawRate) * MathF.Min(1f, 10f * dt);

            // Lateral tire force kills sideslip within the remaining friction-circle budget.
            var latDemand = -latSpeed / dt;
            var usedSq = accelFwd * accelFwd;
            var remaining = MathF.Sqrt(MathF.Max(muBudget * muBudget * rearGrip * rearGrip - usedSq, 0f));
            accelLat = Math.Clamp(latDemand, -remaining, remaining);
        }
        else
        {
            YawRate *= 1f - MathF.Min(1f, 0.5f * dt); // airborne: yaw momentum persists
        }

        // --- aero drag (forward component only, 0.6-aerodynamics.md) ---
        var dragAccel = _params.DragHalfRhoCdA * MathF.Abs(fwdSpeed) * fwdSpeed / _params.MassKg;

        // --- integrate ---
        var newFwd = fwdSpeed + (accelFwd - dragAccel) * dt;
        if (Grounded && inputs.Throttle > 0f && fwdSpeed <= _params.TopSpeed && newFwd > _params.TopSpeed)
            newFwd = _params.TopSpeed; // governor: drive never pushes past the precompute
        var reverseTop = _params.TopSpeed * ReverseTopSpeedFraction;
        if (Grounded && inputs.Throttle < 0f && newFwd < -reverseTop)
            newFwd = -reverseTop; // reverse gear governor
        var newLat = latSpeed + accelLat * dt;

        Yaw += YawRate * dt;
        if (Yaw > MathF.PI) Yaw -= 2f * MathF.PI;
        if (Yaw < -MathF.PI) Yaw += 2f * MathF.PI;

        var newSin = MathF.Sin(Yaw);
        var newCos = MathF.Cos(Yaw);
        Velocity = new Vector3(
            newFwd * newSin + newLat * newCos,
            newVelY, // spring + damping own the vertical; a velY>=0 clamp here caused descent surfing
            newFwd * newCos - newLat * newSin);

        Position = new Vector3(
            Position.X + Velocity.X * dt,
            Position.Y + Velocity.Y * dt,
            Position.Z + Velocity.Z * dt);

        // --- presentation rotation: terrain-aligned when grounded, yaw-only airborne ---
        if (Grounded && ground != null
            && TerrainContactPlane.TryAlign(Position, Yaw, ground, out _, out var aligned))
            Rotation = aligned;
        else
            Rotation = TerrainContactPlane.FromYawPitchRoll(Yaw, 0f, 0f);
    }
}
