using System.Runtime.CompilerServices;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Utils;
using AutoCore.Utils.Reliability;

namespace AutoCore.Sim.Collision;

/// <summary>
/// Lazy per-map hull-world cache. First request kicks a background build (SafeTask — a map can
/// have thousands of placements) and returns null; callers stay terrain-only until the world
/// flips in, and forever if the build fails (graceful degradation). Keyed weakly so disposed
/// map instances release their worlds.
/// </summary>
public sealed class MapCollisionWorlds
{
    private sealed class Slot
    {
        public volatile StaticCollisionWorld World;
        public int BuildState; // 0 = idle, 1 = building, 2 = done/failed
    }

    private readonly ConditionalWeakTable<SectorMap, Slot> _slots = new();

    /// <summary>Test seam: swap the data sources (defaults read AssetManager WAD/GLM state).</summary>
    internal Func<int, string> PhysicsNameByCbid { get; set; } = cbid =>
        (AssetManager.Instance.GetCloneBase(cbid) as AutoCore.Game.CloneBases.CloneBaseObject)
            ?.SimpleObjectSpecific.PhysicsName;

    internal Func<IEnumerable<string>> HullEntryNames { get; set; } = () =>
        AssetManager.Instance.EnumerateGLMFileNames();

    internal Func<string, byte[]> HullBytesByName { get; set; } = name =>
    {
        using var stream = AssetManager.Instance.GetFileStreamFromGLMs(name);
        return stream?.ToArray();
    };

    internal Func<int, bool> IsSoftDestructibleByCbid { get; set; } = cbid =>
        AutoCore.Game.Combat.VehicleMapPropRam.IsSoftDestructibleCloneBase(
            AssetManager.Instance.GetCloneBase(cbid) as AutoCore.Game.CloneBases.CloneBaseObject);

    /// <summary>Returns the built world for this map, or null while building/unavailable.</summary>
    public StaticCollisionWorld GetOrRequest(SectorMap map)
    {
        if (map?.MapData == null)
            return null;

        var slot = _slots.GetOrCreateValue(map);
        var world = slot.World;
        if (world != null || Interlocked.CompareExchange(ref slot.BuildState, 1, 0) != 0)
            return world;

        var placements = map.MapData.Templates.Values.ToList();
        var mapName = map.MapData.ContinentObject?.MapFileName ?? "?";
        SafeTask.FireAndForget(
            Task.Run(() =>
            {
                try
                {
                    var builder = new MapCollisionWorldBuilder(
                        PhysicsNameByCbid, HullEntryNames(), HullBytesByName, IsSoftDestructibleByCbid);
                    slot.World = builder.Build(placements);
                    Logger.WriteLog(LogType.Debug,
                        $"MapCollisionWorlds: '{mapName}' ready with {slot.World.InstanceCount} hull instances");
                }
                finally
                {
                    slot.BuildState = 2;
                }
            }),
            $"clone sim: build hull world for {mapName}");

        return null;
    }
}
