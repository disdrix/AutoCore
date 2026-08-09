using AutoCore.Game.Entities;
using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

[TestClass]
public class KinematicFollowerTests
{
    private static readonly TerrainContactPlane.HeightSample FlatGround =
        (float x, float z, out float y) => { y = 0f; return true; };

    private static Vehicle VehicleAt(float x, float y, float z)
    {
        var vehicle = new Vehicle();
        vehicle.Position = new Vector3(x, y, z);
        vehicle.Rotation = new Quaternion(0, 0, 0, 1);
        return vehicle;
    }

    private static void Simulate(KinematicFollower follower, Vehicle clone, Vehicle target, int steps, float dt = 0.05f,
        TerrainContactPlane.HeightSample sample = null)
    {
        for (var i = 0; i < steps; i++)
            follower.Step(clone, target, sample ?? FlatGround, dt);
    }

    [TestMethod]
    public void Step_ConvergesBehindStationaryTarget()
    {
        var target = VehicleAt(100f, 0f, 100f); // identity rotation faces +Z
        var clone = VehicleAt(130f, 0f, 140f);
        var follower = new KinematicFollower();

        Simulate(follower, clone, target, steps: 300);

        var goal = new Vector3(100f, 0f, 100f - KinematicFollower.FollowDistanceMeters);
        Assert.IsTrue(clone.Position.Dist(goal) < 1.5f,
            $"expected clone near {goal}, was {clone.Position}");
    }

    [TestMethod]
    public void Step_ApproachDoesNotOvershootGoal()
    {
        var target = VehicleAt(0f, 0f, 0f);
        var clone = VehicleAt(0f, 0f, -60f); // directly behind, straight-line approach
        var follower = new KinematicFollower();
        var goal = new Vector3(0f, 0f, -KinematicFollower.FollowDistanceMeters);

        var previous = clone.Position.Dist(goal);
        for (var i = 0; i < 400; i++)
        {
            follower.Step(clone, target, FlatGround, 0.05f);
            var current = clone.Position.Dist(goal);
            Assert.IsTrue(current <= previous + 0.05f,
                $"overshoot/oscillation at step {i}: {previous} -> {current}");
            previous = current;
        }
    }

    [TestMethod]
    public void Step_FollowsTerrainHeight()
    {
        TerrainContactPlane.HeightSample slope = (float x, float z, out float y) =>
        {
            y = 0.1f * x;
            return true;
        };
        var target = VehicleAt(200f, 20f, 0f);
        var clone = VehicleAt(150f, 0f, 0f);
        var follower = new KinematicFollower();

        Simulate(follower, clone, target, steps: 300, sample: slope);

        var expectedY = 0.1f * clone.Position.X;
        Assert.IsTrue(MathF.Abs(clone.Position.Y - expectedY) < 1.0f,
            $"clone Y {clone.Position.Y} should track terrain {expectedY} at X={clone.Position.X}");
    }

    [TestMethod]
    public void Step_MovingClone_PublishesNonZeroVelocity()
    {
        var target = VehicleAt(0f, 0f, 0f);
        var clone = VehicleAt(40f, 0f, 40f);
        var follower = new KinematicFollower();

        Simulate(follower, clone, target, steps: 20);

        var speed = MathF.Sqrt(
            clone.Velocity.X * clone.Velocity.X +
            clone.Velocity.Y * clone.Velocity.Y +
            clone.Velocity.Z * clone.Velocity.Z);
        Assert.IsTrue(speed > 1f, $"clone should report movement velocity, speed={speed}");
    }
}
