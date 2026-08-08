namespace AutoCore.Utils.Logging;

/// <summary>
/// Per-player elevated diagnostics: enrolled SessionId/CharacterId pass Debug/Trace
/// through the GameLog filter until auto-expiry.
/// </summary>
public static class PlayerDiagnostics
{
    private static readonly object Lock = new();
    private static readonly Dictionary<string, DateTime> BySession = new(StringComparer.Ordinal);
    private static readonly Dictionary<long, DateTime> ByCharacter = new();
    private static Func<DateTime> _utcNow = () => DateTime.UtcNow;

    internal static void SetClockForTests(Func<DateTime> utcNow) => _utcNow = utcNow ?? (() => DateTime.UtcNow);

    public static void EnrollSession(string sessionId, int minutes = 15)
    {
        if (string.IsNullOrWhiteSpace(sessionId))
            return;
        var until = _utcNow().AddMinutes(Math.Max(1, minutes));
        lock (Lock)
            BySession[sessionId] = until;
    }

    public static void EnrollCharacter(long characterId, int minutes = 15)
    {
        if (characterId == 0)
            return;
        var until = _utcNow().AddMinutes(Math.Max(1, minutes));
        lock (Lock)
            ByCharacter[characterId] = until;
    }

    public static void Clear()
    {
        lock (Lock)
        {
            BySession.Clear();
            ByCharacter.Clear();
        }
    }

    public static bool IsElevated()
    {
        var props = LogContext.CurrentProperties;
        if (props == null || props.Count == 0)
            return false;

        string sessionId = null;
        long characterId = 0;
        foreach (var pair in props)
        {
            if (pair.Key == "SessionId" && pair.Value is string s)
                sessionId = s;
            else if (pair.Key == "CharacterId" && pair.Value != null)
            {
                characterId = pair.Value switch
                {
                    long l => l,
                    int i => i,
                    _ => characterId
                };
            }
        }

        var now = _utcNow();
        lock (Lock)
        {
            Prune(now);
            if (!string.IsNullOrEmpty(sessionId)
                && BySession.TryGetValue(sessionId, out var untilS)
                && untilS > now)
                return true;
            if (characterId != 0
                && ByCharacter.TryGetValue(characterId, out var untilC)
                && untilC > now)
                return true;
            return false;
        }
    }

    private static void Prune(DateTime now)
    {
        foreach (var k in BySession.Where(kv => kv.Value <= now).Select(kv => kv.Key).ToList())
            BySession.Remove(k);
        foreach (var k in ByCharacter.Where(kv => kv.Value <= now).Select(kv => kv.Key).ToList())
            ByCharacter.Remove(k);
    }
}
