using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Structures;
using AutoCore.Sim.Collision;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Collision;

[TestClass]
public class MapCollisionWorldBuilderTests
{
    private static byte[] BoxCache() => File.ReadAllBytes(
        Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache"));

    private static GraphicsObjectTemplate Placement(int cbid, float x, float z, bool active = true, float scale = 1f)
        => new(GraphicsObjectType.GraphicsPhysics)
        {
            CBID = cbid,
            COID = cbid * 10,
            Location = new Vector4(x, 0f, z, 0f),
            Rotation = new Quaternion(0f, 0f, 0f, 1f),
            Scale = scale,
            IsActive = active,
            OriginalIsActive = active,
        };

    [TestMethod]
    public void Build_ResolvesPlacementsThroughPhysicsNames_CaseInsensitive()
    {
        // CBID 100 → PhysicsName "obj_box" while the archive entry is "Obj_Box.cache"
        // (case mismatch is the R2-documented normal case).
        var hullSource = new Dictionary<string, byte[]> { ["Obj_Box.cache"] = BoxCache() };
        var builder = new MapCollisionWorldBuilder(
            physicsNameByCbid: cbid => cbid == 100 ? "obj_box" : null,
            hullEntryNames: hullSource.Keys,
            hullBytesByName: name => hullSource.TryGetValue(name, out var b) ? b : null);

        var world = builder.Build(new[]
        {
            Placement(100, 50f, 50f),
            Placement(100, 80f, 50f),
            Placement(999, 110f, 50f),            // no PhysicsName → no hull
            // Fam-authored IsActive=false MUST still collide: real map probe (2026-08-09,
            // scrapvalley/malachite/militiabase) shows essentially ALL static geometry —
            // bridges, buildings, fences, invisible barrier walls — is authored inactive;
            // the flag is server logic state, not existence.
            Placement(100, 140f, 50f, active: false),
        });

        Assert.AreEqual(3, world.InstanceCount);
        Assert.IsTrue(world.Raycast(new Vector3(50f, 0.5f, 40f), new Vector3(0f, 0f, 1f), 20f, out var d, out _));
        Assert.AreEqual(9.5f, d, 0.01f);
        Assert.IsFalse(world.Raycast(new Vector3(110f, 0.5f, 40f), new Vector3(0f, 0f, 1f), 20f, out _, out _),
            "placement without a physics hull must not collide");
    }

    [TestMethod]
    public void Build_BadHullBytes_SkipSilentlyAndKeepOthers()
    {
        var hullSource = new Dictionary<string, byte[]>
        {
            ["good.cache"] = BoxCache(),
            ["bad.cache"] = new byte[] { 1, 2, 3 },
        };
        var builder = new MapCollisionWorldBuilder(
            cbid => cbid == 1 ? "good" : "bad",
            hullSource.Keys,
            name => hullSource.TryGetValue(name, out var b) ? b : null);

        var world = builder.Build(new[] { Placement(1, 0f, 0f), Placement(2, 10f, 0f) });

        Assert.AreEqual(1, world.InstanceCount, "malformed hull must degrade to no-collision, not throw");
    }
}
