using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Managers.Asset;
using AutoCore.Game.CloneBases;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Exploration;

/// <summary>
/// Data probe (not a regression test): quantify hull coverage over real maps to explain the
/// live "clips through some statics" report. Skipped automatically when the client install is
/// absent.
/// </summary>
[TestClass]
public class HullCoverageProbeTests
{
    private const string InstallPath = @"C:\Program Files (x86)\NetDevil\Auto Assault";

    [TestMethod]
    [Ignore("Manual data probe against the real client install — loads the full WAD into the " +
            "AssetManager singleton, which would contaminate fake-clonebase tests in the same run. " +
            "Remove [Ignore] locally to re-measure hull coverage.")]
    public void Probe_PlacementHullCoverage_OnRealMaps()
    {
        if (!Directory.Exists(InstallPath))
            Assert.Inconclusive("client install not present");

        // Load into AssetManager's own WADLoader (get-only property) so AllocateTemplateFromCBID
        // inside MapData.Read resolves the same clonebases.
        var wad = (WADLoader)typeof(AutoCore.Game.Managers.AssetManager)
            .GetProperty("WADLoader", System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic)!
            .GetValue(AutoCore.Game.Managers.AssetManager.Instance)!;
        if (wad.CloneBases.Count == 0)
            Assert.IsTrue(wad.Load(Path.Combine(InstallPath, "clonebase.wad")), "WAD load failed");
        var glm = new GLMLoader();
        Assert.IsTrue(glm.Load(InstallPath), "GLM load failed");

        var cacheNames = new HashSet<string>(
            glm.EnumerateFileNames().Where(n => n.EndsWith(".cache", StringComparison.OrdinalIgnoreCase)),
            StringComparer.OrdinalIgnoreCase);

        var famNames = glm.EnumerateFileNames()
            .Where(n => n.EndsWith(".fam", StringComparison.OrdinalIgnoreCase))
            .Where(n => n.Contains("map_hwy", StringComparison.OrdinalIgnoreCase))
            .Take(3)
            .Select(n => n[..^4])
            .ToList();

        foreach (var mapName in famNames)
        {
            using var famStream = glm.GetStream($"{mapName}.fam");
            if (famStream == null)
            {
                Console.WriteLine($"=== {mapName}: no .fam in GLMs ===");
                continue;
            }

            var continent = new AutoCore.Database.World.Models.ContinentObject
            {
                Id = 1,
                MapFileName = mapName,
                DisplayName = mapName,
                IsTown = false,
                IsPersistent = true,
            };
            var mapData = new AutoCore.Game.Map.MapData(continent);
            using (var reader = new BinaryReader(famStream))
            {
                mapData.Read(reader);
            }

            int graphics = 0, graphicsWithHull = 0, graphicsEmptyPhysName = 0, graphicsNameNoEntry = 0;
            var byType = new Dictionary<string, int>();
            var missingEntries = new Dictionary<string, int>(StringComparer.OrdinalIgnoreCase);
            foreach (var tpl in mapData.Templates.Values)
            {
                var typeName = tpl.GetType().Name;
                byType[typeName] = byType.GetValueOrDefault(typeName) + 1;

                if (tpl is not GraphicsObjectTemplate g)
                    continue;
                graphics++;
                var physName = (wad.CloneBases.GetValueOrDefault(g.CBID) as CloneBaseObject)
                    ?.SimpleObjectSpecific.PhysicsName;
                if (string.IsNullOrWhiteSpace(physName))
                {
                    graphicsEmptyPhysName++;
                }
                else if (cacheNames.Contains(physName + ".cache"))
                {
                    graphicsWithHull++;
                }
                else
                {
                    graphicsNameNoEntry++;
                    missingEntries[physName] = missingEntries.GetValueOrDefault(physName) + 1;
                }
            }

            // Sample raw fields for the first few placements (active or not) to sanity-check
            // the C# PhysicsName parse against reality.
            var samples = mapData.Templates.Values.OfType<GraphicsObjectTemplate>()
                .GroupBy(t => t.CBID).Take(8);
            Console.WriteLine($"=== {mapName} ===");
            foreach (var group in samples)
            {
                var cb = wad.CloneBases.GetValueOrDefault(group.Key) as CloneBaseObject;
                Console.WriteLine(
                    $"  sample cbid={group.Key} n={group.Count()} active={group.First().OriginalIsActive} " +
                    $"type={(cb == null ? "?" : cb.CloneBaseSpecific.Type.ToString())} " +
                    $"phys='{cb?.SimpleObjectSpecific.PhysicsName}' fx='{cb?.CloneBaseSpecific.FxFileName}'");
            }
            Console.WriteLine($"templates by type: {string.Join(", ", byType.OrderByDescending(k => k.Value).Select(k => $"{k.Key}={k.Value}"))}");
            Console.WriteLine($"GraphicsObjectTemplates: {graphics}; with hull: {graphicsWithHull}; empty PhysicsName: {graphicsEmptyPhysName}; name-without-entry: {graphicsNameNoEntry}");
            foreach (var kvp in missingEntries.OrderByDescending(k => k.Value).Take(12))
                Console.WriteLine($"  MISSING entry: '{kvp.Key}' x{kvp.Value}");
        }
    }
}
