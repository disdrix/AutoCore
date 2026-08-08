namespace AutoCore.Utils.Logging;

using System.Diagnostics;

/// <summary>
/// Periodic HealthSummary INFO event. Call <see cref="Tick"/> from a server main loop with
/// elapsed milliseconds; when the interval elapses, emits one structured record.
/// </summary>
public sealed class HealthSummaryReporter
{
    private readonly Func<IReadOnlyList<(string Key, object Value)>> _metrics;
    private readonly int _intervalMs;
    private long _accumMs;

    public HealthSummaryReporter(Func<IReadOnlyList<(string Key, object Value)>> metrics, int intervalMs = 60_000)
    {
        _metrics = metrics ?? (() => Array.Empty<(string, object)>());
        _intervalMs = Math.Max(1_000, intervalMs);
    }

    public void Tick(long deltaMs)
    {
        if (deltaMs < 0)
            deltaMs = 0;
        _accumMs += deltaMs;
        if (_accumMs < _intervalMs)
            return;
        _accumMs = 0;
        EmitNow();
    }

    public void EmitNow()
    {
        try
        {
            var props = new List<(string, object)>
            {
                ("BuildVersion", ServerIdentity.BuildVersion),
                ("WorkingSetBytes", Environment.WorkingSet),
                ("GcGen0", GC.CollectionCount(0)),
                ("GcGen1", GC.CollectionCount(1)),
                ("GcGen2", GC.CollectionCount(2)),
            };
            var extra = _metrics();
            if (extra != null)
                props.AddRange(extra);
            GameLog.Info("HealthSummary", props.ToArray());
        }
        catch
        {
            // total
        }
    }
}
