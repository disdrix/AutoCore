using System.Diagnostics;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Managers.Asset;
using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Sim.Ai;
using AutoCore.Sim.Collision;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Exploration;

/// <summary>
/// Manual perf baseline (run explicitly by filter): N clone brains driving an A→B ping-pong
/// route on real maps — real heightfields and full hull collision worlds. Measures wall time
/// per tick and managed allocations per vehicle-tick, single-threaded, exactly like the
/// current sector-loop wiring. Baseline for the scale-out work (see DeferredWork.cs).
/// </summary>
[TestClass]
public class SimPerfBenchmarkTests
{
    private const string InstallPath = @"C:\Program Files (x86)\NetDevil\Auto Assault";

    private static readonly string[] Maps =
    {
        "sec_f_b_map_hwy_a2_1_scrapvalley",
        "sec_f_b_map_hwy_a3_1_malachite",
        "sec_f_h_map_hwy_j2_01_militiabase_01",
    };

    private static readonly int[] FleetSizes = { 1, 10, 100, 250, 500, 1000 };

    [TestMethod]
    [Ignore("Manual perf benchmark against the real client install (~3 min). Baseline captured " +
            "2026-08-09 (24-core box, single-threaded): per-vehicle 8-79 us/tick depending on map " +
            "hull density; 1000 vehicles = 17% (scrapvalley) / 84% (militiabase) / 147% (malachite) " +
            "of the 50 ms budget; allocations 5-15 KB per vehicle-tick (closure garbage — the " +
            "first optimization target). Remove [Ignore] to re-measure.")]
    public void Benchmark_FleetTickCost_OnRealMaps()
    {
        if (!Directory.Exists(InstallPath))
            Assert.Inconclusive("client install not present");

        var wad = (WADLoader)typeof(AutoCore.Game.Managers.AssetManager)
            .GetProperty("WADLoader", System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic)!
            .GetValue(AutoCore.Game.Managers.AssetManager.Instance)!;
        if (wad.CloneBases.Count == 0)
            Assert.IsTrue(wad.Load(Path.Combine(InstallPath, "clonebase.wad")), "WAD load failed");
        var glm = new GLMLoader();
        Assert.IsTrue(glm.Load(InstallPath), "GLM load failed");

        var cacheNames = glm.EnumerateFileNames()
            .Where(n => n.EndsWith(".cache", StringComparison.OrdinalIgnoreCase))
            .ToList();

        Console.WriteLine($"machine: {Environment.ProcessorCount} cores; single-threaded tick (current wiring)");

        foreach (var mapName in Maps)
        {
            using var famStream = glm.GetStream($"{mapName}.fam");
            Assert.IsNotNull(famStream, $"{mapName}.fam missing");

            var mapData = new AutoCore.Game.Map.MapData(new AutoCore.Database.World.Models.ContinentObject
            {
                Id = 1, MapFileName = mapName, DisplayName = mapName, IsTown = false, IsPersistent = true,
            });
            using (var reader = new BinaryReader(famStream))
            {
                mapData.Read(reader);
            }

            // Heightfield, exactly as MapDataLoader attaches it.
            TerrainContactPlane.HeightSample ground;
            using (var tga = glm.GetStream($"{mapName}.tga"))
            {
                Assert.IsNotNull(tga, $"{mapName}.tga missing");
                Assert.IsTrue(AutoCore.Game.Map.MapTerrainHeightfield.TryLoad(
                    tga, mapData.TerrainWidth, mapData.TerrainHeight, mapData.GridSize,
                    out var field, out var error), error);
                ground = field.TrySample;
            }

            // Full hull world, synchronous build (also timed — it is the /clone map-entry cost).
            var buildSw = Stopwatch.StartNew();
            var builder = new MapCollisionWorldBuilder(
                cbid => (AutoCore.Game.Managers.AssetManager.Instance.GetCloneBase(cbid)
                    as AutoCore.Game.CloneBases.CloneBaseObject)?.SimpleObjectSpecific.PhysicsName,
                cacheNames,
                name => { using var s = glm.GetStream(name); return s?.ToArray(); },
                cbid => AutoCore.Game.Combat.VehicleMapPropRam.IsSoftDestructibleCloneBase(
                    AutoCore.Game.Managers.AssetManager.Instance.GetCloneBase(cbid)
                        as AutoCore.Game.CloneBases.CloneBaseObject));
            var world = builder.Build(mapData.Templates.Values);
            buildSw.Stop();

            // A→B route from the longest authored path (consistent, realistic terrain).
            var path = mapData.Templates.Values.OfType<MapPathTemplate>()
                .Where(p => p.Points.Count >= 2)
                .OrderByDescending(p => p.Points[0].Position.Dist(p.Points[^1].Position))
                .FirstOrDefault();
            Assert.IsNotNull(path, $"{mapName}: no paths");
            var a = path.Points[0].Position;
            var b = path.Points[^1].Position;

            Console.WriteLine($"=== {mapName} ===");
            Console.WriteLine($"hulls={world.InstanceCount} buildMs={buildSw.ElapsedMilliseconds} " +
                $"route A=({a.X:F0},{a.Z:F0}) B=({b.X:F0},{b.Z:F0}) len={a.Dist(b):F0}m");

            foreach (var fleet in FleetSizes)
            {
                var brains = new CloneDriveBrain[fleet];
                var p = SimVehicleParams.CreateForTests(
                    massKg: 1500f, steeringMaxAngleRad: 0.6f, steeringFullSpeedLimit: 15f, topSpeed: 30f,
                    muBase: 3.0f, suspensionLength: 0.35f, suspensionStrength: 60f,
                    suspensionDampCompression: 6f, suspensionDampExtension: 7f,
                    wheelRadius: 0.45f, wheelBase: 3.0f, dragHalfRhoCdA: 0.6f);
                for (var i = 0; i < fleet; i++)
                {
                    brains[i] = new CloneDriveBrain(p, new CloneAiTuning()) { Obstacles = world };
                    // Spread spawns in a grid around A so fleets don't tick identical states.
                    var ox = (i % 32) * 3f;
                    var oz = (i / 32) * 3f;
                    brains[i].Reset(new Vector3(a.X + ox, a.Y, a.Z + oz), yaw: 0f);
                    brains[i].SetPathRoute(new[] { a, b }, loop: false);
                }

                var warmup = 20;
                var measured = fleet >= 500 ? 100 : 200;
                var player = new Vector3(a.X, a.Y, a.Z);

                for (var t = 0; t < warmup; t++)
                    for (var i = 0; i < fleet; i++)
                        brains[i].Step(player, default, 0f, ground, 0.05f);

                var allocBefore = GC.GetAllocatedBytesForCurrentThread();
                var sw = Stopwatch.StartNew();
                for (var t = 0; t < measured; t++)
                    for (var i = 0; i < fleet; i++)
                        brains[i].Step(player, default, 0f, ground, 0.05f);
                sw.Stop();
                var allocAfter = GC.GetAllocatedBytesForCurrentThread();

                var msPerTick = sw.Elapsed.TotalMilliseconds / measured;
                var usPerVehicleTick = msPerTick * 1000.0 / fleet;
                var bytesPerVehicleTick = (allocAfter - allocBefore) / (double)(measured * (long)fleet);
                Console.WriteLine(
                    $"fleet={fleet,5}  tick={msPerTick,8:F3} ms  perVehicle={usPerVehicleTick,7:F1} us  " +
                    $"alloc={bytesPerVehicleTick,7:F0} B/veh-tick  budgetUse={msPerTick / 50.0 * 100.0,5:F1}%");
            }
        }
    }
}
