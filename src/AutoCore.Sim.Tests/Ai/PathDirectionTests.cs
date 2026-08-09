using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

/// <summary>
/// Path routes are one-way: every vehicle travels the waypoints in ascending index order
/// (wrapping on loops), regardless of which way it happened to face when the route was set.
/// Live 2026-08-09: NPC vehicles adopted with arbitrary spawn facing ran their loops in
/// random directions — the arc reference simply followed a backwards-driving car.
/// </summary>
[TestClass]
public class PathDirectionTests
{
    private static readonly TerrainContactPlane.HeightSample Flat =
        (float x, float z, out float y) => { y = 0f; return true; };

    private static SimVehicleParams Params() => SimVehicleParams.CreateForTests(
        massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
        muBase: 3.0f, suspensionLength: 0.35f, suspensionStrength: 60f,
        suspensionDampCompression: 6f, suspensionDampExtension: 7f,
        wheelRadius: 0.45f, wheelBase: 3.0f, dragHalfRhoCdA: 0.6f);

    private static readonly Vector3[] SquareLoop =
    {
        new(0f, 0f, 0f),
        new(80f, 0f, 0f),
        new(80f, 0f, 80f),
        new(0f, 0f, 80f),
        new(0f, 0f, 0f),
    };

    [TestMethod]
    public void LoopRoute_CarFacingForward_TravelsAscendingWaypoints()
    {
        Assert.AreEqual(1, FirstWaypointReached(initialYaw: MathF.PI / 2f),
            "a car already facing along the route must head for waypoint 1");
    }

    [TestMethod]
    public void LoopRoute_CarFacingBackwards_StillTravelsAscendingWaypoints()
    {
        // Facing −X (against the ascending direction of the first leg): the brain must
        // turn the car around, not settle into driving the loop in reverse.
        Assert.AreEqual(1, FirstWaypointReached(initialYaw: -MathF.PI / 2f),
            "spawn facing must never decide the travel direction of a path route");
    }

    /// <summary>
    /// Runs a car from (30,0,0) on the first leg of the square loop and reports which vertex
    /// it physically reaches first (within 10 m): 1 = ascending (correct), 0 or 3 = reverse.
    /// </summary>
    private static int FirstWaypointReached(float initialYaw)
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        brain.Reset(new Vector3(30f, 0f, 0f), initialYaw);
        brain.SetPathRoute(SquareLoop, loop: true);

        for (var i = 0; i < 1200; i++)
        {
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);

            var pos = brain.Car.Position;
            if (Near(pos, SquareLoop[1]))
                return 1;
            if (Near(pos, SquareLoop[3]))
                return 3;
            if (Near(pos, SquareLoop[0]))
                return 0;
        }

        return -1;
    }

    private static bool Near(Vector3 pos, Vector3 vertex)
    {
        var dx = pos.X - vertex.X;
        var dz = pos.Z - vertex.Z;
        return MathF.Sqrt(dx * dx + dz * dz) < 10f;
    }
}
