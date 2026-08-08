namespace AutoCore.Utils.Logging;

/// <summary>
/// In-memory ring of recent structured events for bug reports. Keeps the last
/// <see cref="Capacity"/> records that carry SessionId/CharacterId (or Audit).
/// Never throws; safe on the emit path.
/// </summary>
public static class PlayerActionTraceBuffer
{
    /// <summary>Global ring size across all players (high-fidelity combat/interact volume).</summary>
    public const int DefaultCapacity = 8000;

    /// <summary>Events included per /reportbug zip (last N for that player).</summary>
    public const int DefaultReportLimit = 500;

    private static readonly object Lock = new();
    private static StructuredLogRecord[] _ring = new StructuredLogRecord[DefaultCapacity];
    private static int _next;
    private static int _count;
    private static int _capacity = DefaultCapacity;

    /// <summary>Maximum records retained globally (all players).</summary>
    public static int Capacity
    {
        get { lock (Lock) return _capacity; }
        set
        {
            var cap = Math.Max(10, value);
            lock (Lock)
            {
                if (cap == _capacity)
                    return;
                var snapshot = SnapshotAllUnlocked();
                _capacity = cap;
                _ring = new StructuredLogRecord[cap];
                _next = 0;
                _count = 0;
                foreach (var r in snapshot.TakeLast(cap))
                    WriteUnlocked(r);
            }
        }
    }

    public static void Record(StructuredLogRecord record)
    {
        if (record == null)
            return;

        // Keep session-bound, character-bound, and audit events — enough for /reportbug.
        if (!ShouldRetain(record))
            return;

        lock (Lock)
            WriteUnlocked(record);
    }

    public static IReadOnlyList<StructuredLogRecord> SnapshotForPlayer(
        string sessionId,
        long characterId,
        int limit = DefaultReportLimit)
    {
        limit = Math.Max(1, limit);
        lock (Lock)
        {
            var all = SnapshotAllUnlocked();
            var matched = new List<StructuredLogRecord>(Math.Min(limit, all.Count));
            for (var i = all.Count - 1; i >= 0 && matched.Count < limit; i--)
            {
                var r = all[i];
                if (MatchesPlayer(r, sessionId, characterId))
                    matched.Add(r);
            }
            matched.Reverse();
            return matched;
        }
    }

    public static void Clear()
    {
        lock (Lock)
        {
            Array.Clear(_ring, 0, _ring.Length);
            _next = 0;
            _count = 0;
        }
    }

    private static void WriteUnlocked(StructuredLogRecord record)
    {
        _ring[_next] = record;
        _next = (_next + 1) % _capacity;
        if (_count < _capacity)
            _count++;
    }

    private static List<StructuredLogRecord> SnapshotAllUnlocked()
    {
        var list = new List<StructuredLogRecord>(_count);
        if (_count == 0)
            return list;

        var start = _count < _capacity ? 0 : _next;
        for (var i = 0; i < _count; i++)
        {
            var idx = (start + i) % _capacity;
            var r = _ring[idx];
            if (r != null)
                list.Add(r);
        }
        return list;
    }

    /// <summary>
    /// Whether a record is relevant to per-player bug reports. Public so <see cref="GameLog"/>
    /// can decide before the NDJSON min-level filter drops Debug dual-writes.
    /// </summary>
    public static bool ShouldRetain(StructuredLogRecord record)
    {
        if (record == null)
            return false;

        if (record.Audit)
            return true;

        // First-class gameplay breadcrumbs (GameLog.Action / named events).
        if (!string.IsNullOrEmpty(record.EventName)
            && record.EventName is not "Legacy" and not "UnnamedEvent" and not "HealthSummary"
            and not "TickOverrun")
        {
            // Prefer identity-tagged records, but keep named gameplay events that carry
            // actor/target ids even if SessionId was missing on a combat-tick path.
            foreach (var p in record.Properties)
            {
                if (p.Key is "SessionId" or "CharacterId" or "CharacterName" or "AccountId"
                    or "ActorCharacterId" or "VictimCharacterId" or "KillerCharacterId"
                    or "CasterCharacterId" or "TargetCoid" or "NpcCoid" or "SkillId"
                    or "MissionId" or "Handler" or "Damage" or "Amount")
                    return true;
            }
        }

        foreach (var p in record.Properties)
        {
            if (p.Key is "SessionId" or "CharacterId" or "CharacterName" or "AccountId")
                return true;
        }

        // Legacy dual-write lines under an ambient session scope still carry SessionId via merge.
        return false;
    }

    private static bool MatchesPlayer(StructuredLogRecord record, string sessionId, long characterId)
    {
        string sid = null;
        long cid = 0;
        long actorCid = 0;
        long victimCid = 0;
        long killerCid = 0;
        long casterCid = 0;

        foreach (var p in record.Properties)
        {
            if (p.Key == "SessionId" && p.Value is string s)
                sid = s;
            else if (p.Value != null)
            {
                var asLong = ToLong(p.Value);
                switch (p.Key)
                {
                    case "CharacterId": cid = asLong != 0 ? asLong : cid; break;
                    case "ActorCharacterId": actorCid = asLong; break;
                    case "VictimCharacterId": victimCid = asLong; break;
                    case "KillerCharacterId": killerCid = asLong; break;
                    case "CasterCharacterId": casterCid = asLong; break;
                }
            }
        }

        if (characterId != 0)
        {
            if (cid == characterId || actorCid == characterId || victimCid == characterId
                || killerCid == characterId || casterCid == characterId)
                return true;
        }

        if (!string.IsNullOrEmpty(sessionId) && string.Equals(sid, sessionId, StringComparison.Ordinal))
            return true;
        return false;
    }

    private static long ToLong(object value) => value switch
    {
        long l => l,
        int i => i,
        short s => s,
        byte b => b,
        uint u => u,
        ulong ul when ul <= long.MaxValue => (long)ul,
        _ => 0
    };
}
