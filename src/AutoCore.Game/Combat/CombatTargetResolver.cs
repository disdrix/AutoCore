namespace AutoCore.Game.Combat;

using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Utils;

/// <summary>
/// Combat/skill/reaction target resolution honoring the TFID Global flag.
/// Global player COIDs and authored local map COIDs share one numeric space (a fresh character
/// database restarts identity COIDs at 1), so COID-only lookups are ambiguous — SS-31.
/// </summary>
public static class CombatTargetResolver
{
    private static long _collisionResolvedCount;
    private static long _lastCollisionLogMs;
    private const long CollisionLogIntervalMs = 5000;

    /// <summary>
    /// Times a resolve ran while BOTH a local and a global entity shared the requested COID —
    /// direct live evidence the exact-TFID path chose differently than a COID-only scan could.
    /// </summary>
    public static long CollisionResolvedCount => Interlocked.Read(ref _collisionResolvedCount);

    /// <summary>
    /// Resolve a wire TFID to an entity: exact (COID, Global) map lookup first, then the global
    /// registry, then a legacy COID-only scan so flag-mismatch lookups keep working.
    /// </summary>
    public static ClonedObjectBase Resolve(SectorMap map, TFID id)
    {
        if (id == null || id.Coid <= 0)
            return null;

        // Exact (COID, Global) lookup first — the only collision-safe path.
        var exact = map?.GetObjectByTfid(id);
        NoteCollisionIfPresent(map, id);
        if (exact != null)
            return exact;

        // Global entities may live only in the global registry (e.g. vehicle not indexed on the map).
        if (id.Global)
        {
            var global = ObjectManager.Instance?.GetObject(id);
            if (global != null)
                return global;
        }

        // Legacy COID-only fallback keeps flag-mismatch lookups working; ambiguous under collision.
        return map?.GetObjectByCoid(id.Coid)
            ?? ObjectManager.Instance?.GetObject(id);
    }

    private static void NoteCollisionIfPresent(SectorMap map, TFID id)
    {
        // O(1): a collision exists when the same COID is also indexed under the opposite flag.
        if (map?.GetObjectByTfid(new TFID(id.Coid, !id.Global)) == null)
            return;

        Interlocked.Increment(ref _collisionResolvedCount);

        var now = Environment.TickCount64;
        var last = Interlocked.Read(ref _lastCollisionLogMs);
        if (now - last >= CollisionLogIntervalMs &&
            Interlocked.CompareExchange(ref _lastCollisionLogMs, now, last) == last)
        {
            Logger.WriteLog(LogType.Debug,
                "CombatTargetResolver: COID {0} is shared by local+global entities (global={1} requested); {2} collision resolves so far",
                id.Coid,
                id.Global,
                Interlocked.Read(ref _collisionResolvedCount));
        }
    }
}
