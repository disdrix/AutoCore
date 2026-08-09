using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using AutoCore.Sim.Collision;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

[TestClass]
public class ObstacleAvoidanceTests
{
    private static readonly TerrainContactPlane.HeightSample Flat =
        (float x, float z, out float y) => { y = 0f; return true; };

    private static SimVehicleParams Params() => SimVehicleParams.CreateForTests(
        massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
        muBase: 3.0f, suspensionLength: 0.35f, suspensionStrength: 60f,
        suspensionDampCompression: 6f, suspensionDampExtension: 7f,
        wheelRadius: 0.45f, wheelBase: 3.0f, dragHalfRhoCdA: 0.6f);

    private static StaticCollisionWorld WallAt(float z, float halfWidth)
    {
        var box = CacheHullParser.Parse(File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache")));
        var world = new StaticCollisionWorld();
        // Unit box spans ±0.5 → scale gives a (2·halfWidth) wide, deep wall centered at (0, z).
        world.Add(box, new Vector3(0f, 0f, z), new Quaternion(0f, 0f, 0f, 1f), scale: halfWidth * 2f);
        world.Build();
        return world;
    }

    [TestMethod]
    public void Follow_SteersAroundABlockingWall()
    {
        var world = WallAt(z: 40f, halfWidth: 4f);
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Obstacles = world };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        var player = new Vector3(0f, 0f, 90f);

        for (var i = 0; i < 500; i++) // 25 s to cover 90 m with a detour
        {
            brain.Step(player, new Vector3(0f, 0f, 0.01f), 0f, Flat, dt: 0.05f);
            Assert.IsFalse(world.SphereOverlap(brain.Car.Position, 0.4f),
                $"clone drove into the wall at step {i}: {brain.Car.Position}");
        }

        var dx = brain.Car.Position.X - player.X;
        var dz = brain.Car.Position.Z - player.Z;
        Assert.IsTrue(MathF.Sqrt(dx * dx + dz * dz) < 25f,
            $"clone must get past the wall to the player; ended at {brain.Car.Position}");
    }

    /// <summary>
    /// Live 2026-08-09: with a clear road ahead, the clone weaved left/right constantly —
    /// 41 m feelers at ±25° were triggering hard avoidance on roadside props well off the
    /// path, and the proportional-only steering overshot into oscillation.
    /// </summary>
    [TestMethod]
    public void RoadsideProps_ClearPathAhead_DrivesStraightWithoutWeaving()
    {
        var box = CacheHullParser.Parse(File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache")));
        var world = new StaticCollisionWorld();
        // Lamp-post-ish props lining the road at x=±6 every 15 m — none on the path.
        for (var z = 15f; z <= 300f; z += 15f)
        {
            world.Add(box, new Vector3(-6f, 0f, z), new Quaternion(0f, 0f, 0f, 1f), scale: 2f);
            world.Add(box, new Vector3(6f, 0f, z), new Quaternion(0f, 0f, 0f, 1f), scale: 2f);
        }
        world.Build();

        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Obstacles = world };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);

        var steerFlips = 0;
        var prevSteerSign = 0;
        var maxAbsX = 0f;
        var playerZ = 30f;
        for (var i = 0; i < 400; i++) // 20 s cruise down the corridor
        {
            playerZ += 12f * 0.05f;
            brain.Step(new Vector3(0f, 0f, playerZ), new Vector3(0f, 0f, 12f), 0f, Flat, dt: 0.05f);

            maxAbsX = MathF.Max(maxAbsX, MathF.Abs(brain.Car.Position.X));
            var sign = brain.LastInputs.Steering > 0.15f ? 1 : brain.LastInputs.Steering < -0.15f ? -1 : 0;
            if (sign != 0 && prevSteerSign != 0 && sign != prevSteerSign)
                steerFlips++;
            if (sign != 0)
                prevSteerSign = sign;
        }

        Assert.IsTrue(maxAbsX < 3f, $"clone wandered {maxAbsX} m off a clear straight road");
        Assert.IsTrue(steerFlips <= 4, $"steering flip-flopped {steerFlips} times on a clear road");
    }

    [TestMethod]
    public void HardBlock_NeverPenetratesEvenWhenAimedStraightIn()
    {
        // Degenerate worst case: aim point INSIDE the wall (player parked in a building).
        var world = WallAt(z: 20f, halfWidth: 6f);
        var brain = new CloneDriveBrain(Params(), new CloneAiTuning()) { Obstacles = world };
        brain.Reset(new Vector3(0f, 0f, 0f), yaw: 0f);
        var player = new Vector3(0f, 0f, 26f); // inside the wall footprint

        for (var i = 0; i < 300; i++)
        {
            brain.Step(player, default, 0f, Flat, dt: 0.05f);
            Assert.IsFalse(world.SphereOverlap(brain.Car.Position, 0.3f),
                $"clone penetrated the hull at step {i}: {brain.Car.Position}");
        }
    }
}
