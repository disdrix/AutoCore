using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using AutoCore.Sim.Collision;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

/// <summary>
/// Vehicle-vs-vehicle avoidance: dodge other vehicles when possible, but NEVER at the cost of
/// hitting a static object (static avoidance has priority).
/// </summary>
[TestClass]
public class DynamicAvoidanceTests
{
    private static readonly TerrainContactPlane.HeightSample Flat =
        (float x, float z, out float y) => { y = 0f; return true; };

    private static SimVehicleParams Params() => SimVehicleParams.CreateForTests(
        massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
        muBase: 3.0f, suspensionLength: 0.35f, suspensionStrength: 60f,
        suspensionDampCompression: 6f, suspensionDampExtension: 7f,
        wheelRadius: 0.45f, wheelBase: 3.0f, dragHalfRhoCdA: 0.6f);

    private static readonly CloneDriveBrain.DynamicObstacle[] SingleObstacleBuffer =
        new CloneDriveBrain.DynamicObstacle[4];

    [TestMethod]
    public void ParkedVehicleInPath_IsAvoided()
    {
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning());
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        brain.SetPathRoute(new[] { new Vector3(0f, 0f, 60f), new Vector3(0f, 0f, 120f) }, loop: false);

        var parked = new Vector3(0f, 0f, 35f); // dead ahead on the lane
        var minDistance = float.MaxValue;
        for (var i = 0; i < 300; i++)
        {
            SingleObstacleBuffer[0] = new CloneDriveBrain.DynamicObstacle
            {
                Position = parked,
                Velocity = default,
            };
            brain.SetDynamicObstacles(SingleObstacleBuffer, 1);
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);

            var dx = brain.Car.Position.X - parked.X;
            var dz = brain.Car.Position.Z - parked.Z;
            minDistance = MathF.Min(minDistance, MathF.Sqrt(dx * dx + dz * dz));
        }

        Assert.IsTrue(minDistance > 2.2f,
            $"clone must swerve around a parked vehicle; closest approach {minDistance} m");
        Assert.IsTrue(brain.Car.Position.Z > 55f, "and still make progress down the route");
    }

    /// <summary>/clone N &lt;spacing&gt; widens the vehicle-vs-vehicle standoff radius.</summary>
    [TestMethod]
    public void WiderStandoffRadius_KeepsMoreDistanceFromParkedVehicle()
    {
        float RunWithStandoff(float standoff)
        {
            var brain = new CloneDriveBrain(Params(), new CloneAiTuning())
            {
                DynamicStandoffRadius = standoff,
            };
            brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
            brain.SetPathRoute(new[] { new Vector3(0f, 0f, 60f), new Vector3(0f, 0f, 120f) }, loop: false);

            var parked = new Vector3(0f, 0f, 35f);
            var minDistance = float.MaxValue;
            for (var i = 0; i < 300; i++)
            {
                SingleObstacleBuffer[0] = new CloneDriveBrain.DynamicObstacle
                {
                    Position = parked,
                    Velocity = default,
                };
                brain.SetDynamicObstacles(SingleObstacleBuffer, 1);
                brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);

                var dx = brain.Car.Position.X - parked.X;
                var dz = brain.Car.Position.Z - parked.Z;
                minDistance = MathF.Min(minDistance, MathF.Sqrt(dx * dx + dz * dz));
            }

            return minDistance;
        }

        var tight = RunWithStandoff(4f);
        var wide = RunWithStandoff(9f);
        Assert.IsTrue(wide > tight + 0.5f,
            $"a 9 m standoff must clear a parked vehicle wider than a 4 m one (got {tight:F2} vs {wide:F2})");
    }

    [TestMethod]
    public void DodgeBlockedByWall_BrakesInsteadOfSwervingIntoIt()
    {
        // Corridor: wall along the LEFT of the lane. A vehicle ahead would normally be dodged
        // left (its offset is slightly right), but that side is a wall — the clone must brake
        // and squeeze/queue rather than hit the static.
        var box = CacheHullParser.Parse(File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache")));
        var world = new StaticCollisionWorld();
        for (var z = 0f; z <= 80f; z += 10f)
            world.Add(box, new Vector3(-4f, 0f, z), new Quaternion(0f, 0f, 0f, 1f), scale: 10f, "wall");
        world.Build();

        var messages = new List<string>();
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning())
        {
            Obstacles = world,
            DebugLog = messages.Add,
        };
        brain.Reset(new Vector3(2f, 0f, 0f), yaw: 0f);
        brain.SetPathRoute(new[] { new Vector3(2f, 0f, 60f), new Vector3(2f, 0f, 120f) }, loop: false);

        var blocker = new Vector3(1.2f, 0f, 30f); // slightly LEFT of the clone → dodge would go left, into the wall
        for (var i = 0; i < 200; i++)
        {
            SingleObstacleBuffer[0] = new CloneDriveBrain.DynamicObstacle
            {
                Position = blocker,
                Velocity = default,
            };
            brain.SetDynamicObstacles(SingleObstacleBuffer, 1);
            brain.Step(new Vector3(500f, 0f, 500f), default, 0f, Flat, dt: 0.05f);

            Assert.IsFalse(world.SphereOverlap(brain.Car.Position, 0.4f),
                $"dynamic dodge must never push the clone into a static wall (step {i}, {brain.Car.Position})");
        }
    }
}
