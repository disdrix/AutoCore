using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Collision;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Collision;

[TestClass]
public class StaticCollisionWorldTests
{
    private static ConvexHull Box() =>
        CacheHullParser.Parse(File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache")));

    private static Quaternion Yaw(float radians) =>
        TerrainContactPlane.FromYawPitchRoll(radians, 0f, 0f);

    [TestMethod]
    public void Raycast_TranslatedInstance_HitsAtWorldDistance()
    {
        var world = new StaticCollisionWorld();
        world.Add(Box(), new Vector3(100f, 0f, 100f), Yaw(0f), scale: 1f);
        world.Build();

        // Box local Z spans [-0.5, 0.5] → world near face at z=99.5.
        var hit = world.Raycast(new Vector3(100f, 0.5f, 90f), new Vector3(0f, 0f, 1f), 20f,
            out var distance, out var normal);

        Assert.IsTrue(hit);
        Assert.AreEqual(9.5f, distance, 1e-2f);
        Assert.IsTrue(normal.Z < -0.99f, $"expected -Z world normal, got {normal}");
    }

    [TestMethod]
    public void Raycast_ScaledInstance_ScalesExtents()
    {
        var world = new StaticCollisionWorld();
        world.Add(Box(), new Vector3(0f, 0f, 0f), Yaw(0f), scale: 4f);
        world.Build();

        // Scaled near face at z=-2.
        var hit = world.Raycast(new Vector3(0f, 1f, -10f), new Vector3(0f, 0f, 1f), 20f,
            out var distance, out _);

        Assert.IsTrue(hit);
        Assert.AreEqual(8f, distance, 1e-2f);
    }

    [TestMethod]
    public void Raycast_RotatedInstance_UsesOrientedFaces()
    {
        var world = new StaticCollisionWorld();
        // 45° yaw: the box corner now points at -Z; a centered ray hits the rotated corner
        // at z = -0.5*sqrt(2) ≈ -0.707.
        world.Add(Box(), new Vector3(0f, 0f, 0f), Yaw(MathF.PI / 4f), scale: 1f);
        world.Build();

        var hit = world.Raycast(new Vector3(0f, 0.5f, -5f), new Vector3(0f, 0f, 1f), 10f,
            out var distance, out _);

        Assert.IsTrue(hit);
        Assert.AreEqual(5f - 0.7071f, distance, 1e-2f);
    }

    [TestMethod]
    public void Raycast_ReturnsNearestOfManyInstances_AndMissesFarAway()
    {
        var world = new StaticCollisionWorld();
        for (var i = 0; i < 50; i++)
            world.Add(Box(), new Vector3(i * 20f, 0f, 200f), Yaw(0f), scale: 1f);
        world.Add(Box(), new Vector3(0f, 0f, 50f), Yaw(0f), scale: 1f); // nearest on the ray
        world.Build();

        var hit = world.Raycast(new Vector3(0f, 0.5f, 0f), new Vector3(0f, 0f, 1f), 300f,
            out var distance, out _);
        Assert.IsTrue(hit);
        Assert.AreEqual(49.5f, distance, 1e-2f);

        var miss = world.Raycast(new Vector3(5000f, 0.5f, 0f), new Vector3(0f, 0f, 1f), 300f,
            out _, out _);
        Assert.IsFalse(miss);
    }

    [TestMethod]
    public void Queries_ReportTheHitInstanceLabel()
    {
        var world = new StaticCollisionWorld();
        world.Add(Box(), new Vector3(0f, 0f, 30f), Yaw(0f), 1f, "obj_gen_wall#4711");
        world.Build();

        Assert.IsTrue(world.Raycast(new Vector3(0f, 0.5f, 0f), new Vector3(0f, 0f, 1f), 50f,
            out _, out _, out var rayLabel));
        Assert.AreEqual("obj_gen_wall#4711", rayLabel);

        Assert.IsTrue(world.SphereOverlap(new Vector3(0f, 0.5f, 29.8f), 0.5f, out var sphereLabel));
        Assert.AreEqual("obj_gen_wall#4711", sphereLabel);
    }

    [TestMethod]
    public void SphereOverlap_DetectsNearbyInstanceOnly()
    {
        var world = new StaticCollisionWorld();
        world.Add(Box(), new Vector3(10f, 0f, 10f), Yaw(0f), scale: 1f);
        world.Build();

        Assert.IsTrue(world.SphereOverlap(new Vector3(10.8f, 0.5f, 10f), radius: 0.5f));
        Assert.IsFalse(world.SphereOverlap(new Vector3(15f, 0.5f, 10f), radius: 0.5f));
    }
}
