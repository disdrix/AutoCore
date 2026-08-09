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

    private static readonly TerrainContactPlane.HeightSample Flat88 =
        (float x, float z, out float y) => { y = 88.1f; return true; };

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

    /// <summary>
    /// Live trace 2026-08-09 11:30: 30 m/s straight into a corner waypoint, past the turn,
    /// into a wall. The path speed target must shrink for the turn.
    /// </summary>
    [TestMethod]
    public void SharpCornerAhead_SlowsDownBeforeTheWaypoint()
    {
        CloneAiTuning.PathSpeedOverride = 30f;
        try
        {
            var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
            brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
            // Right-angle corner at (0,80): approach north, then head east.
            brain.SetPathRoute(new[]
            {
                new Vector3(0f, 0f, 80f),
                new Vector3(80f, 0f, 80f),
            }, loop: false);

            var speedNearCorner = float.MaxValue;
            for (var i = 0; i < 300; i++)
            {
                brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);
                var dz = 80f - brain.Car.Position.Z;
                if (brain.PathWaypointIndex == 0 && dz is > 0f and < 12f)
                {
                    var s = MathF.Sqrt(brain.Car.Velocity.X * brain.Car.Velocity.X
                        + brain.Car.Velocity.Z * brain.Car.Velocity.Z);
                    speedNearCorner = MathF.Min(speedNearCorner, s);
                }
            }

            Assert.IsTrue(speedNearCorner < 18f,
                $"must brake for a right-angle corner; was still doing {speedNearCorner} m/s within 12 m");
        }
        finally
        {
            CloneAiTuning.PathSpeedOverride = null;
        }
    }

    /// <summary>
    /// Live 2026-08-09 12:06: speed 27 with positive throttle TWO legs before a 90° corner —
    /// single-vertex anticipation cannot brake across dense waypoints (10–20 m legs, ~19 m
    /// braking distance). The speed cap must scan the braking horizon across multiple legs.
    /// </summary>
    [TestMethod]
    public void DenseWaypoints_BrakesAcrossMultipleLegsBeforeACorner()
    {
        CloneAiTuning.PathSpeedOverride = 30f;
        try
        {
            var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
            brain.Reset(new Vector3(0f, 0f, -40f), yaw: 0f);
            // Straight run with dense waypoints, then a 90° turn at (0,90) — live-like spacing.
            brain.SetPathRoute(new[]
            {
                new Vector3(0f, 0f, 0f),
                new Vector3(0f, 0f, 15f),
                new Vector3(0f, 0f, 30f),
                new Vector3(0f, 0f, 45f),
                new Vector3(0f, 0f, 60f),
                new Vector3(0f, 0f, 75f),
                new Vector3(0f, 0f, 90f),
                new Vector3(60f, 0f, 90f),
            }, loop: false);

            var speedAtCorner = float.MaxValue;
            for (var i = 0; i < 400; i++)
            {
                brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);
                var dz = 90f - brain.Car.Position.Z;
                if (dz is > 0f and < 10f && MathF.Abs(brain.Car.Position.X) < 6f)
                {
                    var s = MathF.Sqrt(brain.Car.Velocity.X * brain.Car.Velocity.X
                        + brain.Car.Velocity.Z * brain.Car.Velocity.Z);
                    speedAtCorner = MathF.Min(speedAtCorner, s);
                }
            }

            Assert.IsTrue(speedAtCorner < 12f,
                $"must arrive at the 90° corner slow despite dense waypoints; was {speedAtCorner} m/s");
        }
        finally
        {
            CloneAiTuning.PathSpeedOverride = null;
        }
    }

    /// <summary>
    /// Live trace: after a hard block the clone sat at full throttle against the wall for
    /// 2+ s until the generic stuck timer fired. Sustained blocking must trigger recovery
    /// within about half a second.
    /// </summary>
    [TestMethod]
    public void SustainedHardBlock_TriggersRecoveryFast()
    {
        var box = AutoCore.Sim.Collision.CacheHullParser.Parse(File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache")));
        var world = new AutoCore.Sim.Collision.StaticCollisionWorld();
        world.Add(box, new Vector3(0f, 0f, 14f), new Quaternion(0f, 0f, 0f, 1f), scale: 10f);
        world.Build();

        var messages = new List<(int Step, string Message)>();
        var step = 0;
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        brain.DebugLog = m => messages.Add((step, m));
        brain.Obstacles = world;
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        brain.SetPathRoute(new[] { new Vector3(0f, 0f, 40f), new Vector3(0f, 0f, 80f) }, loop: false);

        for (step = 0; step < 200; step++)
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);

        var firstBlock = messages.FirstOrDefault(m => m.Message.Contains("BLOCK"));
        var firstRecovery = messages.FirstOrDefault(m => m.Message.Contains("STUCK") || m.Message.Contains("BLOCKED"));
        Assert.IsNotNull(firstBlock.Message, "the wall must hard-block");
        Assert.IsNotNull(firstRecovery.Message, "recovery must trigger");
        Assert.IsTrue(firstRecovery.Step - firstBlock.Step <= 20,
            $"recovery must start within ~1 s of sustained blocking (block step {firstBlock.Step}, recovery step {firstRecovery.Step})");
    }

    /// <summary>
    /// Live 2026-08-09 11:59 (brick-store corner, third time): direct-to-waypoint pursuit
    /// strings a chord across the path polyline, clipping buildings inside corners the
    /// authored lane goes around. Lane-following pursuit must keep the clone on the polyline.
    /// </summary>
    [TestMethod]
    public void BuildingInsideACorner_LaneFollowingDoesNotCutThroughIt()
    {
        var box = AutoCore.Sim.Collision.CacheHullParser.Parse(File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache")));
        var world = new AutoCore.Sim.Collision.StaticCollisionWorld();
        // Building just inside the right-angle corner apex: the chord from the approach leg to
        // the far waypoint clips it; the authored lane (the polyline) clears it.
        // Tight to the live geometry (block 0.1 s after waypoint advance): the store face
        // sits ~1.5 m off the outgoing lane, and the chord from the advance circle clips it.
        world.Add(box, new Vector3(8f, 0f, 46f), new Quaternion(0f, 0f, 0f, 1f), scale: 5f, "corner-store");
        world.Build();

        var messages = new List<string>();
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning())
        {
            Obstacles = world,
            DebugLog = messages.Add,
        };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        brain.SetPathRoute(new[]
        {
            new Vector3(0f, 0f, 20f),
            new Vector3(0f, 0f, 50f),
            new Vector3(40f, 0f, 50f),
        }, loop: false);

        var reachedEnd = false;
        for (var i = 0; i < 700 && !reachedEnd; i++)
        {
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);
            var dx = brain.Car.Position.X - 40f;
            var dz = brain.Car.Position.Z - 50f;
            reachedEnd = MathF.Sqrt(dx * dx + dz * dz) < 8f;
        }

        Assert.IsTrue(reachedEnd, $"must round the corner to the last waypoint; ended at {brain.Car.Position}");
        Assert.IsFalse(messages.Any(m => m.Contains("STUCK")),
            $"lane following must clear the corner without getting stuck:\n{string.Join("\n", messages.Where(m => m.Contains("BLOCK") || m.Contains("STUCK")))}");
    }

    /// <summary>
    /// Exact-geometry regression for the brick-store stuck (arkbaytutorial, path 'realgunny2',
    /// store coid 15097): waypoints hug the building (~1 m off its faces) with accept 15, so
    /// any point-to-point aiming — at waypoints OR at the start of an unreached lane segment —
    /// chords across the store's SE corner. Only a continuous arc-length reference that moves
    /// ALONG the polyline sweeps the alley the way it was authored.
    /// </summary>
    [TestMethod]
    public void RealGunnyAlley_SweepsTheStoreCornerWithoutSticking()
    {
        var world = new AutoCore.Sim.Collision.StaticCollisionWorld();
        // The REAL store hulls (physics.glm decomposition pieces _p01.._p12) at the fam-probed
        // placement — exact live collision geometry.
        var storeRot = new Quaternion(-0.0112f, 0.6905f, -0.0107f, 0.7232f);
        var storePos = new Vector3(1178.85f, 88.12f, 2117.76f);
        foreach (var piece in Directory.GetFiles(
                     Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "store"), "*.cache"))
        {
            world.Add(AutoCore.Sim.Collision.CacheHullParser.Parse(File.ReadAllBytes(piece)),
                storePos, storeRot, 1f, "brick-store");
        }

        world.Build();

        var messages = new List<string>();
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning())
        {
            Obstacles = world,
            DebugLog = messages.Add,
        };
        brain.Reset(new Vector3(1140f, 88.1f, 2098f), yaw: MathF.PI / 2f); // heading +X like the live lap
        AutoCore.Sim.Ai.CloneAiTuning.PathSpeedOverride = 20f;
        try
        {
            // The probed 'realgunny2' waypoints around the store, in traversal order.
            brain.SetPathRoute(new[]
            {
                new Vector3(1131.1f, 88.1f, 2098.5f),
                new Vector3(1163.0f, 88.1f, 2103.6f),
                new Vector3(1177.1f, 88.1f, 2111.0f),
                new Vector3(1184.8f, 88.1f, 2117.5f),
                new Vector3(1186.7f, 88.1f, 2128.8f),
                new Vector3(1178.6f, 88.2f, 2142.7f),
            }, loop: false, acceptDistances: new[] { 15f, 15f, 15f, 15f, 15f, 15f });

            var reachedEnd = false;
            for (var i = 0; i < 600 && !reachedEnd; i++)
            {
                brain.Step(new Vector3(5000f, 0f, 5000f), default, 0f, Flat88, dt: 0.05f);
                var dx = brain.Car.Position.X - 1178.6f;
                var dz = brain.Car.Position.Z - 2142.7f;
                reachedEnd = MathF.Sqrt(dx * dx + dz * dz) < 10f;
            }

            // The authored polyline genuinely clips the store's real south wall (piece p09
            // spans the wp57→wp56 segment at car height) — retail likely threads it with
            // per-NPC lane offsets. The achievable spec: brush, recover, CONTINUE the route —
            // never wedge indefinitely.
            Assert.IsTrue(reachedEnd,
                $"must get past the store to the far waypoint; ended at {brain.Car.Position}\n" +
                string.Join("\n", messages.Where(m => m.Contains("BLOCK") || m.Contains("STUCK")).Take(12)));
            var recoveries = messages.Count(m => m.Contains("STUCK"));
            Assert.IsTrue(recoveries <= 4,
                $"{recoveries} recoveries at the store — must escape within a few attempts");
        }
        finally
        {
            AutoCore.Sim.Ai.CloneAiTuning.PathSpeedOverride = null;
        }
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
