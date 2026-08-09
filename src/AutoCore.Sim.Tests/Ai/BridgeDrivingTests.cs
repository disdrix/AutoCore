using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using AutoCore.Sim.Collision;
using AutoCore.Sim.Tests.Collision;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

/// <summary>
/// Live 2026-08-09: the clone clipped through bridges instead of driving on top — hulls were
/// obstacles only, never support surfaces.
/// </summary>
[TestClass]
public class BridgeDrivingTests
{
    private static readonly TerrainContactPlane.HeightSample FlatZero =
        (float x, float z, out float y) => { y = 0f; return true; };

    private static AutoCore.Sim.Physics.SimVehicleParams Params() =>
        AutoCore.Sim.Physics.SimVehicleParams.CreateForTests(
            massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
            muBase: 3.0f, suspensionLength: 0.35f, suspensionStrength: 60f,
            suspensionDampCompression: 6f, suspensionDampExtension: 7f,
            wheelRadius: 0.45f, wheelBase: 3.0f, dragHalfRhoCdA: 0.6f);

    [TestMethod]
    public void Follow_CrossesALowBridgeDeck_OnTop()
    {
        // Ramped crossing modeled as ledges within step-up: 0.9 m deck from z=25..55 with a
        // wide footprint so the follow line goes straight across.
        var world = new StaticCollisionWorld();
        world.Add(CompositeGroundTests.Slab(10f, 0.3f, 0.9f, 25f, 55f),
            new Vector3(0f, 0f, 0f), new Quaternion(0f, 0f, 0f, 1f), 1f);
        world.Build();

        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Obstacles = world };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        var player = new Vector3(0f, 0f, 90f);

        var wasOnDeck = false;
        for (var i = 0; i < 400; i++)
        {
            brain.Step(player, new Vector3(0f, 0f, 0.01f), 0f, FlatZero, dt: 0.05f);
            var pos = brain.Car.Position;
            if (pos.Z is > 30f and < 50f && MathF.Abs(pos.X) < 9f)
            {
                Assert.IsTrue(pos.Y > 0.55f,
                    $"crossing the deck the body must ride ON it, was y={pos.Y} at z={pos.Z}");
                wasOnDeck = true;
            }
        }

        Assert.IsTrue(wasOnDeck, $"clone never crossed the deck (ended at {brain.Car.Position})");
        var dz = player.Z - brain.Car.Position.Z;
        Assert.IsTrue(MathF.Abs(dz) < 30f, $"clone must reach the player side, ended {dz} short");
    }

    [TestMethod]
    public void Feelers_IgnoreWalkableRamps_NoAvoidanceSwerve()
    {
        // Wedge ramp rising 2 m over 6 m (18°, top normal Y≈0.95) directly on the path.
        var ramp = new ConvexHull(
            new[]
            {
                new HullPlane(-1f, 0f, 0f, -3f),
                new HullPlane(1f, 0f, 0f, -3f),
                new HullPlane(0f, -1f, 0f, 0f),
                new HullPlane(0f, 0f, 1f, -26f),
                new HullPlane(0f, 0.9487f, -0.3162f, 0f - 0.9487f * 0f + 0.3162f * 20f), // slope through z=20,y=0
            },
            new[]
            {
                new Vector3(-3f, 0f, 20f), new Vector3(3f, 0f, 20f),
                new Vector3(-3f, 0f, 26f), new Vector3(3f, 0f, 26f),
                new Vector3(-3f, 2f, 26f), new Vector3(3f, 2f, 26f),
            });
        var world = new StaticCollisionWorld();
        world.Add(ramp, new Vector3(0f, 0f, 0f), new Quaternion(0f, 0f, 0f, 1f), 1f);
        world.Build();

        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Obstacles = world };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        var player = new Vector3(0f, 2f, 60f);

        for (var i = 0; i < 200; i++)
            brain.Step(player, new Vector3(0f, 0f, 0.01f), 0f, FlatZero, dt: 0.05f);

        Assert.IsTrue(MathF.Abs(brain.Car.Position.X) < 3f,
            $"a drivable ramp must not trigger avoidance swerve; drifted to X={brain.Car.Position.X}");
    }
}
