using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Physics;

/// <summary>
/// Characterization tests for the AutoCore.Sim raycast-car approximation. Tolerances are
/// behavioral, not bit-exact; formulas and constants come from the client RE spec sheet in
/// docs/reconstruction/physics/ (steering-spec.md, brake-spec.md, 0.4-suspension.md,
/// 0.6-aerodynamics.md, verified/fn_005fd390_speedGovernor.md).
/// </summary>
[TestClass]
public class RaycastCarTests
{
    private static readonly TerrainContactPlane.HeightSample Flat =
        (float x, float z, out float y) => { y = 0f; return true; };

    /// <summary>Plausible mid-tier chassis: 1500 kg, 0.6 rad steering, 15 m/s FSL, 30 m/s top.</summary>
    private static SimVehicleParams TestParams() => SimVehicleParams.CreateForTests(
        massKg: 1500f,
        steeringMaxAngleRad: 0.6f,
        steeringFullSpeedLimit: 15f,
        topSpeed: 30f,
        muBase: 1.0f,
        suspensionLength: 0.35f,
        suspensionStrength: 60f,
        suspensionDampCompression: 6f,
        suspensionDampExtension: 7f,
        wheelRadius: 0.45f,
        wheelBase: 3.0f,
        dragHalfRhoCdA: 0.5f * 1.2f * 0.4f * 2.5f);

    private static RaycastCar CarAt(float x, float y, float z, float yaw = 0f)
    {
        var car = new RaycastCar(TestParams());
        car.SetPose(new Vector3(x, y, z), yaw);
        return car;
    }

    private static void Run(RaycastCar car, float seconds, DriveInputs inputs,
        TerrainContactPlane.HeightSample ground = null)
    {
        var steps = (int)MathF.Round(seconds / 0.05f);
        for (var i = 0; i < steps; i++)
            car.Advance(0.05f, inputs, ground ?? Flat);
    }

    private static float Speed(RaycastCar car) =>
        MathF.Sqrt(car.Velocity.X * car.Velocity.X + car.Velocity.Z * car.Velocity.Z);

    // --- Suspension (0.4-suspension.md: F = (strength·compression/length − damp·closing) · mass) ---

    [TestMethod]
    public void AtRest_SettlesAtTerrainHeight()
    {
        var car = CarAt(0f, 2f, 0f); // dropped from above

        Run(car, seconds: 6f, new DriveInputs(0f, 0f, false));

        // Wire convention (NpcTicker.SnapToTerrain, live float report 2026-08-08): vehicle
        // Position.Y sits AT the terrain height; the client renders wheels/suspension itself.
        Assert.AreEqual(0f, car.Position.Y, 0.08f,
            $"rest height {car.Position.Y} must sit at terrain level, not float above it");
        Assert.IsTrue(MathF.Abs(car.Velocity.Y) < 0.05f, "vertical oscillation must decay");
    }

    [TestMethod]
    public void ModerateSpeed_FullSteer_TurnsTightly()
    {
        // Live report 2026-08-08: clone turned far wider than the player. At 10 m/s (below
        // FSL=15, low-speed grip boost ~2x) the kinematic bicycle limit v·tan(0.6)/3 ≈ 2.28
        // rad/s should dominate — require most of it.
        var car = CarAt(0f, 0.5f, 0f);
        car.SetVelocityForTests(new Vector3(0f, 0f, 10f));

        var yawStart = float.NaN;
        for (var i = 0; i < 60; i++)
        {
            var throttle = Speed(car) < 10f ? 0.6f : 0f;
            car.Advance(0.05f, new DriveInputs(throttle, 1f, false), Flat);
            if (i == 39) yawStart = car.Yaw;
        }
        var yawRate = MathF.Abs(NormalizeAngle(car.Yaw - yawStart)) / 1.0f;

        Assert.IsTrue(yawRate > 1.6f,
            $"full-lock yaw rate at 10 m/s is {yawRate} rad/s; must be near the kinematic 2.28");
    }

    private static float NormalizeAngle(float a)
    {
        while (a > MathF.PI) a -= 2f * MathF.PI;
        while (a < -MathF.PI) a += 2f * MathF.PI;
        return a;
    }

    // --- Drive / top speed (verified/fn_005fd390_speedGovernor.md) ---

    [TestMethod]
    public void FullThrottle_ReachesTopSpeedWithinTolerance()
    {
        var car = CarAt(0f, 0.8f, 0f);
        Run(car, seconds: 30f, new DriveInputs(1f, 0f, false));

        Assert.AreEqual(30f, Speed(car), 30f * 0.05f,
            $"steady-state speed {Speed(car)} should be within 5% of the 30 m/s governor");
    }

    [TestMethod]
    public void Launch_AccelerationIsTractionLimited()
    {
        var car = CarAt(0f, 0.8f, 0f);
        Run(car, seconds: 1f, new DriveInputs(1f, 0f, false));

        // Friction-circle bound: a <= muMax·g·(low-speed boost <= 4). Must move decisively but
        // never exceed the boosted traction ceiling.
        var speed = Speed(car);
        Assert.IsTrue(speed > 5f, $"car should launch (speed after 1s = {speed})");
        Assert.IsTrue(speed < 4f * 1.5f * 9.81f, $"speed {speed} exceeds boosted traction ceiling");
    }

    // --- Steering (steering-spec.md: quadratic authority falloff above FSL) ---

    [TestMethod]
    public void Steering_YawAuthorityFallsQuadraticallyAboveFullSpeedLimit()
    {
        var lowRate = SteadyStateYawRate(atSpeed: 10f);   // below FSL=15 → full authority
        var highRate = SteadyStateYawRate(atSpeed: 30f);  // 2×FSL → (15/30)² = 0.25 authority

        Assert.IsTrue(lowRate > 0.1f, $"low-speed yaw rate too small: {lowRate}");
        // Kinematic yaw rate scales with v·angle: high = low · (30/10) · 0.25 = low · 0.75.
        // Grip limits also bind at 30 m/s, so only require the high-speed rate to be clearly
        // reduced below the unscaled kinematic prediction (which would be 3× the low rate).
        Assert.IsTrue(highRate < lowRate * 1.5f,
            $"yaw authority must fall off above FSL: low={lowRate}, high={highRate}");
    }

    private static float SteadyStateYawRate(float atSpeed)
    {
        var car = CarAt(0f, 0.8f, 0f);
        car.SetVelocityForTests(new Vector3(0f, 0f, atSpeed));
        var yawBefore = 0f;
        var yawAfter = 0f;
        for (var i = 0; i < 40; i++)
        {
            // Hold speed with proportional throttle so the comparison isolates steering.
            var throttle = Speed(car) < atSpeed ? 1f : 0f;
            car.Advance(0.05f, new DriveInputs(throttle, 0.5f, false), Flat);
            if (i == 19) yawBefore = car.Yaw;
            if (i == 39) yawAfter = car.Yaw;
        }
        return MathF.Abs(yawAfter - yawBefore) / 1.0f; // rad/s over the last second
    }

    // --- Brake (brake-spec.md: friction-circle limited => decel ≈ mu·g) ---

    [TestMethod]
    public void FullBrake_StopsWithinFrictionLimitedDistance()
    {
        var car = CarAt(0f, 0.8f, 0f);
        car.SetVelocityForTests(new Vector3(0f, 0f, 20f));
        var startZ = car.Position.Z;

        // Hold the brake until stopped (sustained input would then become reverse).
        var stopped = false;
        for (var i = 0; i < 120 && !stopped; i++)
        {
            car.Advance(0.05f, new DriveInputs(-1f, 0f, false), Flat);
            stopped = Speed(car) < 0.5f;
        }

        Assert.IsTrue(stopped, $"car must stop within 6s, speed={Speed(car)}");
        var distance = car.Position.Z - startZ;
        // v²/(2·mu·g): mu in [1.0 base .. 1.5 max] with low-speed boost => 13.6..20.4 m ideal;
        // allow integration slack either side.
        Assert.IsTrue(distance > 3f && distance < 35f,
            $"braking distance {distance} outside friction-limited window");
    }

    [TestMethod]
    public void SustainedReverse_IsCappedWellBelowForwardTopSpeed()
    {
        var car = CarAt(0f, 0.8f, 0f);
        Run(car, seconds: 20f, new DriveInputs(-1f, 0f, false));

        Assert.IsTrue(Speed(car) < 30f * 0.6f,
            $"reverse speed {Speed(car)} must stay well below the forward governor");
    }

    // --- Airborne (ballistic; 0.1-step-rate.md gravity −9.81) ---

    [TestMethod]
    public void Airborne_FallsBallistically()
    {
        TerrainContactPlane.HeightSample cliff = (float x, float z, out float y) =>
        {
            y = z < 20f ? 0f : -60f;
            return true;
        };
        var car = CarAt(0f, 0.8f, 0f);
        car.SetVelocityForTests(new Vector3(0f, 0f, 25f));

        Run(car, seconds: 1.0f, new DriveInputs(0f, 0f, false), cliff); // clears the edge
        Assert.IsFalse(car.Grounded, "car should be airborne past the cliff edge");

        var vyBefore = car.Velocity.Y;
        Run(car, seconds: 0.5f, new DriveInputs(0f, 0f, false), cliff);
        var vyAfter = car.Velocity.Y;
        Assert.AreEqual(-9.81f * 0.5f, vyAfter - vyBefore, 1.0f,
            "airborne vertical velocity must integrate gravity");
    }

    // --- Determinism / substep accumulator ---

    [TestMethod]
    public void Advance_IsDeterministic()
    {
        var a = CarAt(0f, 0.8f, 0f);
        var b = CarAt(0f, 0.8f, 0f);
        for (var i = 0; i < 100; i++)
        {
            var inputs = new DriveInputs(1f, 0.3f, false);
            a.Advance(0.05f, inputs, Flat);
            b.Advance(0.05f, inputs, Flat);
        }

        Assert.AreEqual(a.Position.X, b.Position.X, 0f);
        Assert.AreEqual(a.Position.Z, b.Position.Z, 0f);
        Assert.AreEqual(a.Yaw, b.Yaw, 0f);
    }

    [TestMethod]
    public void Advance_VariableFrameDtMatchesFixed()
    {
        var fixedCar = CarAt(0f, 0.8f, 0f);
        var variableCar = CarAt(0f, 0.8f, 0f);
        var inputs = new DriveInputs(1f, 0.2f, false);

        for (var i = 0; i < 60; i++)
            fixedCar.Advance(0.05f, inputs, Flat);
        for (var i = 0; i < 30; i++)
        {
            variableCar.Advance(0.03f, inputs, Flat);
            variableCar.Advance(0.07f, inputs, Flat);
        }

        // Same total time on the same fixed-substep grid => identical trajectories.
        Assert.AreEqual(fixedCar.Position.X, variableCar.Position.X, 0.001f);
        Assert.AreEqual(fixedCar.Position.Z, variableCar.Position.Z, 0.001f);
    }

    [TestMethod]
    public void Advance_ClampsRunawaySubstepCount()
    {
        var car = CarAt(0f, 0.8f, 0f);
        // A pathological 10 s frame must not spiral; it advances at most MaxSubstepsPerAdvance.
        car.Advance(10f, new DriveInputs(1f, 0f, false), Flat);

        Assert.IsTrue(Speed(car) < 5f,
            $"a single clamped frame must not integrate 10 s of motion (speed={Speed(car)})");
    }
}
