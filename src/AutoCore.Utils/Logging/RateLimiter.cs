namespace AutoCore.Utils.Logging;

/// <summary>
/// Sink-level token bucket per (EventName, Level). Suppresses WARN+ spam while never
/// dropping Audit/Fatal/lifecycle events. On window reopen emits a summary with Suppressed=N.
/// </summary>
public sealed class RateLimiter
{
    public static readonly HashSet<string> LifecycleExempt = new(StringComparer.Ordinal)
    {
        "ServerStarting", "ServerReady", "ServerShutdownRequested", "ServerStopped",
        "ConnectionAccepted", "ConnectionClosed", "SessionEnded", "CharacterSpawned",
        "CharacterSelected", "SectorHandshakeStarted", "HealthSummary", "TickOverrun",
    };

    private readonly object _lock = new();
    private readonly Dictionary<(string Event, StructuredLogLevel Level), Bucket> _buckets = new();
    private readonly int _limit;
    private readonly TimeSpan _window;
    private Func<DateTime> _utcNow;

    public RateLimiter(int limit = 20, TimeSpan? window = null, Func<DateTime> utcNow = null)
    {
        _limit = Math.Max(1, limit);
        _window = window ?? TimeSpan.FromSeconds(10);
        _utcNow = utcNow ?? (() => DateTime.UtcNow);
    }

    /// <summary>Test seam for deterministic clocks.</summary>
    internal void SetClockForTests(Func<DateTime> utcNow) => _utcNow = utcNow ?? (() => DateTime.UtcNow);

    /// <summary>
    /// Returns true when the event should be written. When a suppressed window reopens,
    /// <paramref name="suppressionSummary"/> is set so the caller can emit a summary record first.
    /// </summary>
    public bool Allow(StructuredLogRecord record, out StructuredLogRecord suppressionSummary)
    {
        suppressionSummary = null;
        if (record == null)
            return false;

        if (record.Audit || record.Level >= StructuredLogLevel.Fatal)
            return true;

        if (record.Level < StructuredLogLevel.Warning)
            return true;

        if (!string.IsNullOrEmpty(record.EventName) && LifecycleExempt.Contains(record.EventName))
            return true;

        var key = (record.EventName ?? "", record.Level);
        var now = _utcNow();

        lock (_lock)
        {
            if (!_buckets.TryGetValue(key, out var bucket))
            {
                bucket = new Bucket { WindowStart = now, Count = 0, Suppressed = 0 };
                _buckets[key] = bucket;
            }

            if (now - bucket.WindowStart >= _window)
            {
                if (bucket.Suppressed > 0)
                {
                    suppressionSummary = StructuredLogRecord.Create(
                        StructuredLogLevel.Warning,
                        record.EventName + "RateLimited",
                        audit: false,
                        message: null,
                        ("Suppressed", bucket.Suppressed),
                        ("EventName", record.EventName),
                        ("Level", record.Level.ToString()));
                }

                bucket.WindowStart = now;
                bucket.Count = 0;
                bucket.Suppressed = 0;
            }

            if (bucket.Count < _limit)
            {
                bucket.Count++;
                return true;
            }

            bucket.Suppressed++;
            return false;
        }
    }

    private sealed class Bucket
    {
        public DateTime WindowStart;
        public int Count;
        public int Suppressed;
    }
}
