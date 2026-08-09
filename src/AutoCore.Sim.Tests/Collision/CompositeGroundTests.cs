using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Collision;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Collision;

[TestClass]
public class CompositeGroundTests
{
    private static readonly TerrainContactPlane.HeightSample FlatZero =
        (float x, float z, out float y) => { y = 0f; return true; };

    /// <summary>Axis-aligned slab: x∈[-hx,hx], y∈[y0,y1], z∈[z0,z1].</summary>
    internal static ConvexHull Slab(float hx, float y0, float y1, float z0, float z1)
        => new(
            new[]
            {
                new HullPlane(-1f, 0f, 0f, -hx),
                new HullPlane(1f, 0f, 0f, -hx),
                new HullPlane(0f, -1f, 0f, y0),
                new HullPlane(0f, 1f, 0f, -y1),
                new HullPlane(0f, 0f, -1f, z0),
                new HullPlane(0f, 0f, 1f, -z1),
            },
            new[]
            {
                new Vector3(-hx, y0, z0), new Vector3(hx, y0, z0),
                new Vector3(-hx, y0, z1), new Vector3(hx, y0, z1),
                new Vector3(-hx, y1, z0), new Vector3(hx, y1, z0),
                new Vector3(-hx, y1, z1), new Vector3(hx, y1, z1),
            });

    private static StaticCollisionWorld BridgeDeck(float top)
    {
        // 8 m wide deck from z=20 to z=60, 0.6 m thick, top surface at `top`.
        var world = new StaticCollisionWorld();
        world.Add(Slab(4f, top - 0.6f, top, 20f, 60f), new Vector3(0f, 0f, 0f),
            new Quaternion(0f, 0f, 0f, 1f), 1f);
        world.Build();
        return world;
    }

    [TestMethod]
    public void OnTheDeck_GroundIsTheDeckTop()
    {
        var world = BridgeDeck(top: 5f);
        var sample = CompositeGround.Wrap(FlatZero, world, referenceY: 5f);

        Assert.IsTrue(sample(0f, 40f, out var y));
        Assert.AreEqual(5f, y, 0.01f, "standing on the deck, the deck top is the ground");
    }

    [TestMethod]
    public void UnderTheDeck_GroundStaysTerrain()
    {
        var world = BridgeDeck(top: 5f);
        var sample = CompositeGround.Wrap(FlatZero, world, referenceY: 0f);

        Assert.IsTrue(sample(0f, 40f, out var y));
        Assert.AreEqual(0f, y, 0.01f, "driving under the bridge must not snap onto the deck");
    }

    [TestMethod]
    public void LowLedgeWithinStepUp_BecomesGround()
    {
        var world = BridgeDeck(top: 0.5f);
        var sample = CompositeGround.Wrap(FlatZero, world, referenceY: 0f);

        Assert.IsTrue(sample(0f, 40f, out var y));
        Assert.AreEqual(0.5f, y, 0.01f, "a ledge within step-up height is drivable ground");
    }

    [TestMethod]
    public void BesideTheDeck_GroundIsTerrain()
    {
        var world = BridgeDeck(top: 5f);
        var sample = CompositeGround.Wrap(FlatZero, world, referenceY: 5f);

        Assert.IsTrue(sample(20f, 40f, out var y));
        Assert.AreEqual(0f, y, 0.01f);
    }
}
