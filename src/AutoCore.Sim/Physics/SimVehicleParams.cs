using AutoCore.Game.CloneBases;

namespace AutoCore.Sim.Physics;

/// <summary>
/// Immutable per-chassis parameter snapshot for the sim raycast car, derived from the client's
/// VehicleSpecific + SimpleObjectSpecific data (docs/reconstruction/physics/ spec sheet).
/// Units: metres, seconds, radians, kilograms. Chassis basis: forward +Z, up +Y.
/// </summary>
public sealed class SimVehicleParams
{
    public float MassKg { get; private init; }

    /// <summary>Max steered wheel angle in radians (VehicleSpecific.SteeringMaxAngle).</summary>
    public float SteeringMaxAngleRad { get; private init; }

    /// <summary>Speed (m/s) above which steering authority falls off as (FSL/v)² (steering-spec.md).</summary>
    public float SteeringFullSpeedLimit { get; private init; }

    /// <summary>Governor speed (m/s): gearing precompute, clamped by AbsoluteTopSpeed when set.</summary>
    public float TopSpeed { get; private init; }

    /// <summary>Base tire friction coefficient; retail derives μmax = 1.5·μ0 (0.3-friction-solver.md).</summary>
    public float MuBase { get; private init; }

    public float MuMax => MuBase * 1.5f;

    /// <summary>Rear grip bias (VehicleSpecific.RearWheelFrictionScalar; 1 when unset).</summary>
    public float RearMuScale { get; private init; }

    public float SuspensionLength { get; private init; }
    public float SuspensionStrength { get; private init; }
    public float SuspensionDampCompression { get; private init; }
    public float SuspensionDampExtension { get; private init; }

    public float WheelRadius { get; private init; }
    public float WheelBase { get; private init; }

    /// <summary>Precombined 0.5·ρ·Cd·A for drag along forward axis (0.6-aerodynamics.md).</summary>
    public float DragHalfRhoCdA { get; private init; }

    /// <summary>
    /// Static suspension compression g·L/strength. The wire convention puts vehicle Position.Y
    /// AT terrain height (NpcTicker.SnapToTerrain; client renders wheels/suspension), so the
    /// spring equilibrium is tuned to rest exactly at ground level.
    /// </summary>
    public float RestCompression => Gravity * SuspensionLength / SuspensionStrength;

    public const float Gravity = 9.81f;

    /// <summary>Radians-per-second-per-rpm: π/30 (verified/fn_005fd390_speedGovernor.md).</summary>
    private const float RpmToRadPerSec = 0.104719758f;

    public static SimVehicleParams FromCloneBase(CloneBaseVehicle cloneBase)
    {
        var vs = cloneBase.VehicleSpecific;
        var mass = cloneBase.SimpleObjectSpecific.Mass;

        var wheelRadius = FirstPositive(vs.WheelRadius, 0.45f);
        var wheelBase = ComputeWheelBase(vs, fallback: 3.0f);

        return new SimVehicleParams
        {
            MassKg = mass > 0f ? mass : 1f,
            SteeringMaxAngleRad = vs.SteeringMaxAngle > 0f ? vs.SteeringMaxAngle : 0.6f,
            SteeringFullSpeedLimit = vs.SteeringFullSpeedLimit > 0f ? vs.SteeringFullSpeedLimit : 15f,
            TopSpeed = ComputeTopSpeed(vs, wheelRadius),
            MuBase = 1.0f,
            RearMuScale = vs.RearWheelFrictionScalar > 0f ? vs.RearWheelFrictionScalar : 1f,
            SuspensionLength = PositiveOr(vs.SuspensionLength.Front, 0.35f),
            SuspensionStrength = PositiveOr(vs.SuspensionStrength.Front, 60f),
            SuspensionDampCompression = PositiveOr(vs.SuspensionDampeningCoefficientCompression.Front, 6f),
            SuspensionDampExtension = PositiveOr(vs.SuspensionDampeningCoefficientExtension.Front, 7f),
            WheelRadius = wheelRadius,
            WheelBase = wheelBase,
            DragHalfRhoCdA = ComputeDrag(vs),
        };
    }

    /// <summary>Bypass for unit tests that want explicit, readable numbers.</summary>
    public static SimVehicleParams CreateForTests(
        float massKg,
        float steeringMaxAngleRad,
        float steeringFullSpeedLimit,
        float topSpeed,
        float muBase,
        float suspensionLength,
        float suspensionStrength,
        float suspensionDampCompression,
        float suspensionDampExtension,
        float wheelRadius,
        float wheelBase,
        float dragHalfRhoCdA,
        float rearMuScale = 1f)
        => new()
        {
            MassKg = massKg,
            SteeringMaxAngleRad = steeringMaxAngleRad,
            SteeringFullSpeedLimit = steeringFullSpeedLimit,
            TopSpeed = topSpeed,
            MuBase = muBase,
            RearMuScale = rearMuScale,
            SuspensionLength = suspensionLength,
            SuspensionStrength = suspensionStrength,
            SuspensionDampCompression = suspensionDampCompression,
            SuspensionDampExtension = suspensionDampExtension,
            WheelRadius = wheelRadius,
            WheelBase = wheelBase,
            DragHalfRhoCdA = dragHalfRhoCdA,
        };

    /// <summary>
    /// Gearing governor: v = R · MaxRPM·(π/30) / (TransmissionRatio · topGearRatio), clamped by
    /// AbsoluteTopSpeed (−1/0 = uncapped). Falls back to 30 m/s when gearing data is absent
    /// (test fakes, malformed rows).
    /// </summary>
    private static float ComputeTopSpeed(
        AutoCore.Game.CloneBases.Specifics.VehicleSpecific vs, float wheelRadius)
    {
        var topSpeed = 30f;
        var topGear = vs.NumberOfGears > 0 && vs.GearRatios != null && vs.GearRatios.Length >= vs.NumberOfGears
            ? vs.GearRatios[vs.NumberOfGears - 1]
            : 0f;
        if (topGear > 0f && vs.TransmissionRatio > 0f && vs.MaximumRPMMax > 0f)
            topSpeed = wheelRadius * vs.MaximumRPMMax * RpmToRadPerSec / (vs.TransmissionRatio * topGear);

        if (vs.AbsoluteTopSpeed > 0f)
            topSpeed = MathF.Min(topSpeed, vs.AbsoluteTopSpeed);

        return MathF.Max(topSpeed, 1f);
    }

    private static float ComputeDrag(AutoCore.Game.CloneBases.Specifics.VehicleSpecific vs)
    {
        var rho = vs.AerodynamicsAirDensity > 0f ? vs.AerodynamicsAirDensity : 1.2f;
        var area = vs.AerodynamicsFrontalArea > 0f ? vs.AerodynamicsFrontalArea : 2.5f;
        var cd = vs.AerodynamicsDrag > 0f ? vs.AerodynamicsDrag : 0.4f;
        return 0.5f * rho * area * cd;
    }

    private static float ComputeWheelBase(
        AutoCore.Game.CloneBases.Specifics.VehicleSpecific vs, float fallback)
    {
        if (vs.WheelHardPoints == null || vs.WheelHardPoints.Length == 0)
            return fallback;

        float minZ = float.MaxValue, maxZ = float.MinValue;
        foreach (var hp in vs.WheelHardPoints)
        {
            if (hp.X == 0f && hp.Y == 0f && hp.Z == 0f)
                continue;
            minZ = MathF.Min(minZ, hp.Z);
            maxZ = MathF.Max(maxZ, hp.Z);
        }

        var span = maxZ - minZ;
        return span > 0.5f && float.IsFinite(span) ? span : fallback;
    }

    private static float FirstPositive(float[] values, float fallback)
    {
        if (values == null)
            return fallback;
        foreach (var v in values)
            if (v > 0f && float.IsFinite(v))
                return v;
        return fallback;
    }

    private static float PositiveOr(float value, float fallback)
        => value > 0f && float.IsFinite(value) ? value : fallback;
}
