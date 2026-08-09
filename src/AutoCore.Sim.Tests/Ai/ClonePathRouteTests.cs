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
    public void SetPathRoute_ClearsHold()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Hold = true };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);

        brain.SetPathRoute(new[] { new Vector3(0f, 0f, 30f), new Vector3(0f, 0f, 60f) }, loop: false);

        Assert.IsFalse(brain.Hold, "/clonestartpath must release a /clonestop hold");
    }
}
