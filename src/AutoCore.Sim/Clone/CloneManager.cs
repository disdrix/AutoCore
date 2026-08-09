using System.Collections.Concurrent;
using AutoCore.Game.Entities;

namespace AutoCore.Sim.Clone;

/// <summary>
/// One simulated clone vehicle per player, toggled by /clone. Owns spawn/despawn lifecycle;
/// the per-tick lifecycle check despawns clones whose owner left the map (logout, warp, death
/// respawn to town) without needing new events on Character.
/// </summary>
public sealed class CloneManager
{
    private readonly ConcurrentDictionary<long, CloneHandle> _clones = new();

    public int ActiveCloneCount => _clones.Count;

    public string Toggle(Character character)
    {
        if (character == null)
            return "No character loaded.";

        if (_clones.TryRemove(character.ObjectId.Coid, out var existing))
        {
            CloneSpawner.Despawn(existing.Clone);
            return "Clone despawned.";
        }

        var map = character.Map;
        var vehicle = character.CurrentVehicle;
        if (map == null || vehicle == null || map.MapData?.ContinentObject?.IsTown != false)
            return "You need to be driving to use /clone.";

        var clone = CloneSpawner.Spawn(character);
        _clones[character.ObjectId.Coid] = new CloneHandle(character, clone);
        return "Clone spawned.";
    }

    /// <summary>Despawns clones whose owner is gone or changed maps. Called every sector tick.</summary>
    public void Tick(long nowMs, float dt)
    {
        foreach (var (ownerCoid, handle) in _clones)
        {
            // Alive only while owner and clone share a live map. Both-null is NOT alive: the
            // map's last-player-left reset (SectorMap.ResetLocalWorldToAuthored) tears down the
            // clone entity, and the handle must not linger as a zombie.
            var ownerMap = handle.Owner.Map;
            if (ownerMap != null && ownerMap == handle.Clone.Map)
                continue;

            if (_clones.TryRemove(ownerCoid, out var removed))
                CloneSpawner.Despawn(removed.Clone);
        }
    }
}

/// <summary>Live pairing of a player and their simulated clone vehicle.</summary>
public sealed class CloneHandle
{
    public CloneHandle(Character owner, Vehicle clone)
    {
        Owner = owner;
        Clone = clone;
    }

    public Character Owner { get; }
    public Vehicle Clone { get; }
}
