using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

[TestClass]
public class CloneAiStateMachineTests
{
    [TestMethod]
    public void StartsInFollow_DropsToOrbitAfterHold()
    {
        var sm = new CloneAiStateMachine(new CloneAiTuning());

        sm.Update(playerSpeed: 0f, dt: 1.0f);
        Assert.AreEqual(CloneAiMode.Follow, sm.Mode, "hold time not yet met");
        sm.Update(playerSpeed: 0f, dt: 1.0f);
        Assert.AreEqual(CloneAiMode.Orbit, sm.Mode);
    }

    [TestMethod]
    public void OrbitToFollow_RequiresSustainedSpeed()
    {
        var sm = new CloneAiStateMachine(new CloneAiTuning());
        sm.Update(0f, 2f); // -> Orbit

        sm.Update(playerSpeed: 10f, dt: 0.2f);
        Assert.AreEqual(CloneAiMode.Orbit, sm.Mode, "a 0.2s blip must not flip the mode");
        sm.Update(playerSpeed: 10f, dt: 0.4f);
        Assert.AreEqual(CloneAiMode.Follow, sm.Mode);
    }

    [TestMethod]
    public void ThresholdSpeed_NeverFlaps()
    {
        var tuning = new CloneAiTuning();
        var sm = new CloneAiStateMachine(tuning);
        var flips = 0;
        var last = sm.Mode;
        // Speed dithering between the two thresholds must not toggle the mode.
        for (var i = 0; i < 200; i++)
        {
            var speed = i % 2 == 0 ? tuning.OrbitEnterSpeed + 0.1f : tuning.FollowEnterSpeed - 0.1f;
            sm.Update(speed, 0.05f);
            if (sm.Mode != last) { flips++; last = sm.Mode; }
        }
        Assert.IsTrue(flips <= 1, $"mode flapped {flips} times in the hysteresis band");
    }
}

[TestClass]
public class StuckDetectorTests
{
    [TestMethod]
    public void Triggers_OnlyWhenDrivingHardWithoutDisplacement()
    {
        var detector = new StuckDetector();
        var pos = new Vector3(10f, 0f, 10f);

        for (var i = 0; i < 45; i++) // 2.25 s pinned at full throttle
        {
            if (detector.Update(pos, throttle: 1f, dt: 0.05f))
                return; // triggered as expected
        }
        Assert.Fail("stuck detector must trigger after ~2s of no displacement at high throttle");
    }

    [TestMethod]
    public void DoesNotTrigger_WhenMovingOrCoasting()
    {
        var detector = new StuckDetector();
        var pos = new Vector3(0f, 0f, 0f);

        for (var i = 0; i < 100; i++)
        {
            pos = new Vector3(pos.X, pos.Y, pos.Z + 0.5f); // moving
            Assert.IsFalse(detector.Update(pos, throttle: 1f, dt: 0.05f));
        }
        for (var i = 0; i < 100; i++)
            Assert.IsFalse(detector.Update(pos, throttle: 0f, dt: 0.05f)); // parked, no throttle
    }
}

[TestClass]
public class CloneDriveBrainClosedLoopTests
{
    private static readonly TerrainContactPlane.HeightSample Flat =
        (float x, float z, out float y) => { y = 0f; return true; };

    private static SimVehicleParams Params() => SimVehicleParams.CreateForTests(
        massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
        muBase: 1.0f, suspensionLength: 0.35f, suspensionStrength: 60f,
        suspensionDampCompression: 6f, suspensionDampExtension: 7f,
        wheelRadius: 0.45f, wheelBase: 3.0f, dragHalfRhoCdA: 0.6f);

    [TestMethod]
    public void StationaryPlayer_CloneOrbitsWithBoundedRadiusError()
    {
        var tuning = new CloneAiTuning();
        var brain = new CloneDriveBrain(Params(), tuning);
        var player = new Vector3(200f, 0f, 200f);
        brain.Reset(new Vector3(200f, 0.8f, 190f), yaw: 0f);

        var samples = 0;
        var radiusErrorSum = 0f;
        var angleCovered = 0f;
        var prevAngle = float.NaN;
        for (var i = 0; i < 900; i++) // 45 s
        {
            brain.Step(player, playerVelocity: default, playerYaw: 0f, Flat, dt: 0.05f);
            if (i < 300)
                continue; // settle-in

            var dx = brain.Car.Position.X - player.X;
            var dz = brain.Car.Position.Z - player.Z;
            var r = MathF.Sqrt(dx * dx + dz * dz);
            radiusErrorSum += MathF.Abs(r - tuning.OrbitRadius);
            samples++;

            var angle = MathF.Atan2(dx, dz);
            if (!float.IsNaN(prevAngle))
            {
                var d = angle - prevAngle;
                if (d > MathF.PI) d -= 2f * MathF.PI;
                if (d < -MathF.PI) d += 2f * MathF.PI;
                angleCovered += MathF.Abs(d);
            }
            prevAngle = angle;
        }

        var meanError = radiusErrorSum / samples;
        Assert.IsTrue(meanError < tuning.OrbitRadius * 0.4f,
            $"mean orbit radius error {meanError} exceeds 40% of R={tuning.OrbitRadius}");
        Assert.IsTrue(angleCovered > 2f * MathF.PI,
            $"clone must actually circle the player (covered {angleCovered} rad in 30s)");
    }

    [TestMethod]
    public void FollowDistance_DefaultsTripledForCombatTesting()
    {
        // User request 2026-08-09: 6 m was far too close to line the clone up on obstacles.
        Assert.AreEqual(18f, new CloneAiTuning().FollowDistance);
    }

    [TestMethod]
    public void FollowDistanceOverride_ChangesTrailingGapLive()
    {
        CloneAiTuning.FollowDistanceOverride = 35f;
        try
        {
            var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
            var playerPos = new Vector3(0f, 0f, 0f);
            var playerVel = new Vector3(0f, 0f, 12f);
            brain.Reset(new Vector3(0f, 0.5f, -30f), yaw: 0f);

            for (var i = 0; i < 600; i++)
            {
                playerPos = new Vector3(0f, 0f, playerPos.Z + playerVel.Z * 0.05f);
                brain.Step(playerPos, playerVel, 0f, Flat, dt: 0.05f);
            }

            var gap = playerPos.Z - brain.Car.Position.Z;
            Assert.IsTrue(gap is > 22f and < 50f,
                $"override 35 m should hold a wide trailing gap, was {gap}");
        }
        finally
        {
            CloneAiTuning.FollowDistanceOverride = null;
        }
    }

    [TestMethod]
    public void MovingPlayer_CloneFollowsBehind()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        var playerPos = new Vector3(0f, 0f, 0f);
        var playerVel = new Vector3(0f, 0f, 12f);
        brain.Reset(new Vector3(0f, 0.8f, -10f), yaw: 0f);

        for (var i = 0; i < 600; i++) // 30 s straight line at 12 m/s
        {
            playerPos = new Vector3(playerPos.X, playerPos.Y, playerPos.Z + playerVel.Z * 0.05f);
            brain.Step(playerPos, playerVel, playerYaw: 0f, Flat, dt: 0.05f);
        }

        var dx = brain.Car.Position.X - playerPos.X;
        var dz = brain.Car.Position.Z - playerPos.Z;
        var distance = MathF.Sqrt(dx * dx + dz * dz);
        Assert.IsTrue(distance < 20f, $"clone fell too far behind: {distance} m");
        Assert.IsTrue(dz < 0f, "clone should trail the player, not lead");
        var cloneSpeed = MathF.Sqrt(
            brain.Car.Velocity.X * brain.Car.Velocity.X + brain.Car.Velocity.Z * brain.Car.Velocity.Z);
        Assert.AreEqual(12f, cloneSpeed, 4f, "clone should match the player's cruise speed");
    }

    [TestMethod]
    public void HugeSeparation_TriggersCatchUpTeleport()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        var player = new Vector3(1000f, 0f, 1000f);
        brain.Reset(new Vector3(0f, 0.8f, 0f), yaw: 0f);

        brain.Step(player, default, 0f, Flat, dt: 0.05f);

        var dx = brain.Car.Position.X - player.X;
        var dz = brain.Car.Position.Z - player.Z;
        Assert.IsTrue(MathF.Sqrt(dx * dx + dz * dz) < 30f,
            "beyond CatchUpDistance the brain must teleport the clone near the player");
        Assert.IsTrue(brain.TeleportedThisStep, "teleport must be flagged so the entity uses SetPosition");
    }
}
