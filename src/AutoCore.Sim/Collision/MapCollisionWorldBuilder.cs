using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Structures;
using AutoCore.Utils;

namespace AutoCore.Sim.Collision;

/// <summary>
/// Builds a map's StaticCollisionWorld from fam object placements:
/// placement CBID → clonebase SimpleObjectSpecific.PhysicsName → "{PhysicsName}.cache" in
/// physics.glm (case-insensitive — archive casing differs from clonebase casing; 100% match
/// rate on non-empty names, docs/reconstruction/physics/hull-format-findings.md). The base
/// hull is the whole-object hull; -pN/_partNN decomposition pieces are not needed for server
/// collision. Dependencies are injected as delegates so tests run without WAD/GLM data.
/// </summary>
public sealed class MapCollisionWorldBuilder
{
    private readonly Func<int, string> _physicsNameByCbid;
    private readonly Dictionary<string, string> _cacheEntryIndex;
    private readonly Func<string, byte[]> _hullBytesByName;
    private readonly Dictionary<string, ConvexHull[]> _hullCache = new(StringComparer.OrdinalIgnoreCase);

    public MapCollisionWorldBuilder(
        Func<int, string> physicsNameByCbid,
        IEnumerable<string> hullEntryNames,
        Func<string, byte[]> hullBytesByName)
    {
        _physicsNameByCbid = physicsNameByCbid ?? throw new ArgumentNullException(nameof(physicsNameByCbid));
        _hullBytesByName = hullBytesByName ?? throw new ArgumentNullException(nameof(hullBytesByName));

        // Case-insensitive name → exact archive entry name.
        _cacheEntryIndex = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
        foreach (var name in hullEntryNames ?? Enumerable.Empty<string>())
        {
            if (name.EndsWith(".cache", StringComparison.OrdinalIgnoreCase))
                _cacheEntryIndex.TryAdd(name, name);
        }
    }

    public StaticCollisionWorld Build(IEnumerable<ObjectTemplate> placements)
    {
        var world = new StaticCollisionWorld();
        var resolved = 0;
        var skippedNoHull = 0;

        foreach (var template in placements ?? Enumerable.Empty<ObjectTemplate>())
        {
            // NOTE: no IsActive filter. Real-map probe (2026-08-09): essentially all static
            // geometry — bridges, buildings, fences, invis_physics_* barrier walls — is
            // fam-authored IsActive=false (the flag is mission/server logic state, not
            // existence; the client renders statics regardless). Filtering on it produced an
            // EMPTY collision world on highway maps.
            if (template is not GraphicsObjectTemplate graphics || template.CBID <= 0)
                continue;

            var hulls = ResolveHulls(template.CBID);
            if (hulls == null || hulls.Length == 0)
            {
                skippedNoHull++;
                continue;
            }

            var label = $"{_physicsNameByCbid(template.CBID)}#{template.COID}";
            foreach (var hull in hulls)
            {
                world.Add(
                    hull,
                    new Vector3(graphics.Location.X, graphics.Location.Y, graphics.Location.Z),
                    graphics.Rotation,
                    graphics.Scale,
                    label);
            }

            resolved++;
        }

        world.Build();
        Logger.WriteLog(LogType.Debug,
            $"MapCollisionWorldBuilder: {resolved} hull instances, {skippedNoHull} placements without hulls");
        return world;
    }

    /// <summary>
    /// Resolves an object's collision hulls. Convex decomposition pieces ("Name-pN.cache") are
    /// preferred over the base "Name.cache": the base is ONE convex hull, and for concave
    /// objects (bridges: deck + side walls) that is a solid box to wall-top height — no walls,
    /// deck at parapet level (live 2026-08-09: clone veered through bridge walls). "_partNN"
    /// destruction chunks are never loaded.
    /// </summary>
    private ConvexHull[] ResolveHulls(int cbid)
    {
        var physicsName = _physicsNameByCbid(cbid);
        if (string.IsNullOrWhiteSpace(physicsName))
            return null;

        if (_hullCache.TryGetValue(physicsName, out var cached))
            return cached;

        var pieces = new List<ConvexHull>();
        for (var n = 1; ; n++)
        {
            if (!_cacheEntryIndex.TryGetValue($"{physicsName}-p{n}.cache", out var pieceEntry))
            {
                // Retail decompositions may start at -p2 (observed: sportscar husk -p2..-p11).
                if (n == 1)
                    continue;
                break;
            }

            var piece = TryParse(pieceEntry);
            if (piece != null)
                pieces.Add(piece);
        }

        if (pieces.Count == 0
            && _cacheEntryIndex.TryGetValue(physicsName + ".cache", out var baseEntry))
        {
            var baseHull = TryParse(baseEntry);
            if (baseHull != null)
                pieces.Add(baseHull);
        }

        var result = pieces.Count > 0 ? pieces.ToArray() : null;
        _hullCache[physicsName] = result; // negative results cached too
        return result;
    }

    private ConvexHull TryParse(string entryName)
    {
        try
        {
            var bytes = _hullBytesByName(entryName);
            return bytes == null ? null : CacheHullParser.Parse(bytes);
        }
        catch (Exception ex) when (ex is InvalidDataException or EndOfStreamException)
        {
            Logger.WriteLog(LogType.Error,
                $"MapCollisionWorldBuilder: malformed hull '{entryName}' — piece skipped: {ex.Message}");
            return null;
        }
    }
}
