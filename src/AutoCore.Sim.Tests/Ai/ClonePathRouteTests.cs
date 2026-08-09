using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

/// <summary>/clonestartpath: the clone navigates map-path waypoints with the sim (no snapping).</summary>
[TestClass]
public class ClonePathRouteTests
{
    private static readonly TerrainContactPlane.HeightSample Flat =
        (float x, float z, out float y) => { y = 0f; return true; };

    private static SimVehicleParams Params() => SimVehicleParams.CreateForTests(
        massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
        muBase: 3.0f, suspensionLength: 0.35f, suspensionStrength: 60f,
        suspensionDampCompression: 6f, suspensionDampExtension: 7f,
        wheelRadius: 0.45f, wheelBase: 3.0f, dragHalfRhoCdA: 0.6f);

    private static int StepUntilNear(CloneDriveBrain brain, Vector3 target, int maxSteps)
    {
        for (var i = 0; i < maxSteps; i++)
        {
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);
            var dx = brain.Car.Position.X - target.X;
            var dz = brain.Car.Position.Z - target.Z;
            if (MathF.Sqrt(dx * dx + dz * dz) < 6f)
                return i;
        }

        return -1;
    }

    [TestMethod]
    public void LoopRoute_VisitsAllWaypointsAndWrapsAround()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        var square = new[]
        {
            new Vector3(0f, 0f, 40f),
            new Vector3(40f, 0f, 40f),
            new Vector3(40f, 0f, 0f),
            new Vector3(0f, 0f, 0f),
        };

        brain.SetPathRoute(square, loop: true);

        foreach (var corner in square)
            Assert.IsTrue(StepUntilNear(brain, corner, 400) >= 0,
                $"clone never reached waypoint {corner}");
        // Wraps: first corner again after completing the lap.
        Assert.IsTrue(StepUntilNear(brain, square[0], 400) >= 0, "loop route must wrap around");
        Assert.IsTrue(brain.HasPathRoute, "route persists until cleared");
    }

    [TestMethod]
    public void LineRoute_PingPongsBetweenEnds()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        brain.Reset(new Vector3(0f, 0f, -10f), yaw: 0f);
        var line = new[] { new Vector3(0f, 0f, 0f), new Vector3(0f, 0f, 80f) };

        brain.SetPathRoute(line, loop: false);

        Assert.IsTrue(StepUntilNear(brain, line[1], 500) >= 0, "must reach the far end");
        Assert.IsTrue(StepUntilNear(brain, line[0], 500) >= 0, "must ping-pong back to the start");
    }

    [TestMethod]
    public void ClearPathRoute_ResumesFollowingThePlayer()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        brain.SetPathRoute(new[] { new Vector3(0f, 0f, 60f), new Vector3(60f, 0f, 60f) }, loop: false);
        var player = new Vector3(-80f, 0f, -80f);

        for (var i = 0; i < 100; i++)
            brain.Step(player, new Vector3(-5f, 0f, -5f), 0f, Flat, dt: 0.05f);
        var beforeClear = player.Dist(brain.Car.Position);

        brain.ClearPathRoute();
        for (var i = 0; i < 300; i++)
            brain.Step(player, new Vector3(0f, 0f, 0.01f), 0f, Flat, dt: 0.05f);

        Assert.IsFalse(brain.HasPathRoute);
        Assert.IsTrue(player.Dist(brain.Car.Position) < beforeClear * 0.6f,
            "after clearing the route the clone must head back toward the player");
    }

    [TestMethod]
    public void PathSpeedOverride_ChangesCruiseSpeed()
    {
        CloneAiTuning.PathSpeedOverride = 6f;
        try
        {
            var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
            brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
            brain.SetPathRoute(new[] { new Vector3(0f, 0f, 200f), new Vector3(0f, 0f, 400f) }, loop: false);

            for (var i = 0; i < 200; i++)
                brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);

            var speed = MathF.Sqrt(
                brain.Car.Velocity.X * brain.Car.Velocity.X + brain.Car.Velocity.Z * brain.Car.Velocity.Z);
            Assert.AreEqual(6f, speed, 2f, "/clonepathspeed override must govern path cruise speed");
        }
        finally
        {
            CloneAiTuning.PathSpeedOverride = null;
        }
    }

    /// <summary>
    /// Live 2026-08-09: "sometimes it just stops at a waypoint" — recovery ping-ponged
    /// against an obstacle near the waypoint forever. After repeated failed recoveries the
    /// route must SKIP the unreachable waypoint and continue.
    /// </summary>
    [TestMethod]
    public void UnreachableWaypoint_IsSkippedAfterRepeatedRecoveries()
    {
        var box = AutoCore.Sim.Collision.CacheHullParser.Parse(File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache")));
        var world = new AutoCore.Sim.Collision.StaticCollisionWorld();
        world.Add(box, new Vector3(0f, 0f, 30f), new Quaternion(0f, 0f, 0f, 1f), scale: 12f); // waypoint buried inside
        world.Build();

        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Obstacles = world };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        brain.SetPathRoute(new[]
        {
            new Vector3(0f, 0f, 30f),   // inside the hull — unreachable
            new Vector3(40f, 0f, 60f),  // reachable
        }, loop: false);

        var reachedSecond = false;
        for (var i = 0; i < 1200 && !reachedSecond; i++) // 60 s budget
        {
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);
            var dx = brain.Car.Position.X - 40f;
            var dz = brain.Car.Position.Z - 60f;
            reachedSecond = MathF.Sqrt(dx * dx + dz * dz) < 8f;
        }

        Assert.IsTrue(reachedSecond,
            $"clone must skip the buried waypoint and reach the next one; ended at {brain.Car.Position}");
    }

    [TestMethod]
    public void PathMode_EmitsTelemetryAndEvents()
    {
        var messages = new List<string>();
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { DebugLog = messages.Add };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        brain.SetPathRoute(new[] { new Vector3(0f, 0f, 25f), new Vector3(0f, 0f, 60f) }, loop: false);

        for (var i = 0; i < 300; i++)
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);

        Assert.IsTrue(messages.Any(m => m.Contains("waypoint", StringComparison.OrdinalIgnoreCase)),
            "periodic path telemetry must be emitted");
        Assert.IsTrue(messages.Any(m => m.Contains("advance", StringComparison.OrdinalIgnoreCase)),
            "waypoint-advance events must be emitted");
    }

    [TestMethod]
    public void SetPathRoute_ClearsHold()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Hold = true };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);

        brain.SetPathRoute(new[] { new Vector3(0f, 0f, 30f), new Vector3(0f, 0f, 60f) }, loop: false);

        Assert.IsFalse(brain.Hold, "/clonestartpath must release a /clonestop hold");
    }
}
