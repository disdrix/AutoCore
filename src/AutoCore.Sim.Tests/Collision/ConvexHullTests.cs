using AutoCore.Game.Structures;
using AutoCore.Sim.Collision;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Collision;

/// <summary>
/// Parser + raycast tests against REAL physics.glm entries (Fixtures/hulls, format spec:
/// docs/reconstruction/physics/hull-format-findings.md).
/// </summary>
[TestClass]
public class ConvexHullTests
{
    private static string Fixture(string name) =>
        Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", name);

    private static ConvexHull LoadBox() =>
        CacheHullParser.Parse(File.ReadAllBytes(Fixture("box.cache")));

    [TestMethod]
    public void Parse_BoxCache_YieldsCanonicalUnitCube()
    {
        var hull = LoadBox();

        Assert.AreEqual(6, hull.Planes.Length);
        Assert.AreEqual(8, hull.Vertices.Length);
        // Editor cube: X/Z in [-0.5, 0.5], Y in [0, 1].
        Assert.AreEqual(-0.5f, hull.LocalBoundsMin.X, 1e-4f);
        Assert.AreEqual(0f, hull.LocalBoundsMin.Y, 1e-4f);
        Assert.AreEqual(0.5f, hull.LocalBoundsMax.Z, 1e-4f);
        Assert.AreEqual(1f, hull.LocalBoundsMax.Y, 1e-4f);
    }

    [TestMethod]
    public void Parse_RealEntries_AllVerticesSatisfyAllPlanes()
    {
        foreach (var name in new[] { "box.cache", "obj_gen_bj_mov_01_husk_sportscar-p2.cache", "obj_f_m_static_str_02_windmill.cache" })
        {
            var hull = CacheHullParser.Parse(File.ReadAllBytes(Fixture(name)));
            Assert.IsTrue(hull.Planes.Length >= 4, $"{name}: too few planes");
            Assert.IsTrue(hull.Vertices.Length >= 4, $"{name}: too few verts");

            foreach (var v in hull.Vertices)
            {
                foreach (var p in hull.Planes)
                {
                    var d = p.NormalX * v.X + p.NormalY * v.Y + p.NormalZ * v.Z + p.D;
                    Assert.IsTrue(d <= 1e-3f, $"{name}: vertex outside plane (d={d})");
                }
            }
        }
    }

    [TestMethod]
    public void Parse_CacheVertices_MatchTkSource()
    {
        var hull = CacheHullParser.Parse(
            File.ReadAllBytes(Fixture("obj_gen_bj_mov_01_husk_sportscar-p2.cache")));
        var tkVerts = TkHullParser.ParseVertices(
            File.ReadAllText(Fixture("obj_gen_bj_mov_01_husk_sportscar-p2.tk")));

        foreach (var v in hull.Vertices)
        {
            var matched = tkVerts.Any(t =>
                MathF.Abs(t.X - v.X) < 1e-3f && MathF.Abs(t.Y - v.Y) < 1e-3f && MathF.Abs(t.Z - v.Z) < 1e-3f);
            Assert.IsTrue(matched, $"cache vertex {v} not present in .tk source");
        }
    }

    [TestMethod]
    public void Raycast_ThroughBoxCenter_HitsNearFaceWithNormal()
    {
        var hull = LoadBox();

        // Ray from (0, 0.5, -5) along +Z: near face is z=-0.5 → distance 4.5.
        var hit = hull.Raycast(new Vector3(0f, 0.5f, -5f), new Vector3(0f, 0f, 1f), maxDistance: 10f,
            out var distance, out var normal);

        Assert.IsTrue(hit);
        Assert.AreEqual(4.5f, distance, 1e-3f);
        Assert.AreEqual(-1f, normal.Z, 1e-3f);
        Assert.AreEqual(0f, normal.X, 1e-3f);
    }

    [TestMethod]
    public void Raycast_MissesBesideBox()
    {
        var hull = LoadBox();

        var hit = hull.Raycast(new Vector3(2f, 0.5f, -5f), new Vector3(0f, 0f, 1f), 10f, out _, out _);

        Assert.IsFalse(hit);
    }

    [TestMethod]
    public void Raycast_StartingInside_ReportsZeroDistanceHit()
    {
        var hull = LoadBox();

        var hit = hull.Raycast(new Vector3(0f, 0.5f, 0f), new Vector3(0f, 0f, 1f), 10f,
            out var distance, out _);

        Assert.IsTrue(hit);
        Assert.AreEqual(0f, distance, 1e-3f);
    }
}
