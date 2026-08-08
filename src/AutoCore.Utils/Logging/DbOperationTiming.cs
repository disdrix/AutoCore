namespace AutoCore.Utils.Logging;

using System.Diagnostics;

/// <summary>
/// Thin timing wrapper for DB persistence call sites. Emits DbOperationSlow (WARN) when
/// duration exceeds the threshold and DbOperationFailed (ERROR) on exception (then rethrows).
/// </summary>
public static class DbOperationTiming
{
    /// <summary>Milliseconds above which a DB op is considered slow. Default 250.</summary>
    public static int SlowThresholdMs { get; set; } = 250;

    public static T Run<T>(string operation, Func<T> work)
    {
        var sw = Stopwatch.StartNew();
        try
        {
            var result = work();
            sw.Stop();
            if (sw.ElapsedMilliseconds >= SlowThresholdMs)
            {
                GameLog.Warn("DbOperationSlow", "DB-002",
                    ("Operation", operation),
                    ("DurationMs", sw.ElapsedMilliseconds));
            }
            return result;
        }
        catch (Exception ex)
        {
            sw.Stop();
            GameLog.Error("DbOperationFailed", "DB-003",
                ("Operation", operation),
                ("DurationMs", sw.ElapsedMilliseconds),
                ("ExceptionType", ex.GetType().Name));
            throw;
        }
    }

    public static void Run(string operation, Action work)
        => Run(operation, () => { work(); return 0; });
}
