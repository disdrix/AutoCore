namespace AutoCore.Utils.Logging;

/// <summary>Severity of a structured log record. Distinct from the legacy facility-mixed
/// <see cref="LogType"/>; the mapping between them lives in the dual-write layer.</summary>
public enum StructuredLogLevel
{
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Fatal
}

/// <summary>Destination for structured log records. Implementations must never throw.</summary>
public interface ILogSink
{
    void Write(StructuredLogRecord record);
}

/// <summary>
/// One structured log event: envelope (timestamp, level, event name, audit flag) plus a
/// flat property list. The ambient <see cref="LogContext"/> is merged in at creation time,
/// with explicitly passed properties winning over ambient values for the same key.
/// <para>Creation is total (SS-06): hostile input degrades, it never throws.</para>
/// </summary>
public sealed class StructuredLogRecord
{
    public const string UnnamedEvent = "UnnamedEvent";

    public DateTime TimestampUtc { get; }
    public StructuredLogLevel Level { get; }
    public string EventName { get; }

    /// <summary>True for player-action audit-trail records; exempt from rate limiting and level filters.</summary>
    public bool Audit { get; }

    /// <summary>Optional free-text message (used by legacy Logger dual-write). Null for pure events.</summary>
    public string Message { get; }

    public IReadOnlyList<KeyValuePair<string, object>> Properties { get; }

    private StructuredLogRecord(
        DateTime timestampUtc,
        StructuredLogLevel level,
        string eventName,
        bool audit,
        string message,
        IReadOnlyList<KeyValuePair<string, object>> properties)
    {
        TimestampUtc = timestampUtc;
        Level = level;
        EventName = eventName;
        Audit = audit;
        Message = message;
        Properties = properties;
    }

    public static StructuredLogRecord Create(
        StructuredLogLevel level,
        string eventName,
        bool audit,
        params (string Key, object Value)[] properties)
    {
        return Create(level, eventName, audit, message: null, properties);
    }

    public static StructuredLogRecord Create(
        StructuredLogLevel level,
        string eventName,
        bool audit,
        string message,
        params (string Key, object Value)[] properties)
    {
        var name = string.IsNullOrWhiteSpace(eventName) ? UnnamedEvent : eventName;

        IReadOnlyList<KeyValuePair<string, object>> merged;

        try
        {
            merged = MergeAmbientAndExplicit(properties);
        }
        catch
        {
            // A record with lost properties still beats a throw out of a catch block.
            merged = Array.Empty<KeyValuePair<string, object>>();
        }

        return new StructuredLogRecord(DateTime.UtcNow, level, name, audit, message, merged);
    }

    /// <summary>Returns the value of a property (explicit or ambient) or null. For tests and filters.</summary>
    public object GetProperty(string key)
    {
        foreach (var pair in Properties)
        {
            if (string.Equals(pair.Key, key, StringComparison.Ordinal))
                return pair.Value;
        }

        return null;
    }

    private static IReadOnlyList<KeyValuePair<string, object>> MergeAmbientAndExplicit(
        (string Key, object Value)[] explicitProperties)
    {
        var result = new List<KeyValuePair<string, object>>();
        var explicitKeys = new HashSet<string>(StringComparer.Ordinal);

        if (explicitProperties != null)
        {
            foreach (var (key, value) in explicitProperties)
            {
                if (string.IsNullOrEmpty(key) || !explicitKeys.Add(key))
                    continue;

                result.Add(new KeyValuePair<string, object>(key, value));
            }
        }

        foreach (var pair in LogContext.CurrentProperties)
        {
            if (!explicitKeys.Contains(pair.Key))
                result.Add(pair);
        }

        return result;
    }
}
