namespace AutoCore.Utils.Reliability;

/// <summary>
/// Isolates a unit of work so an unexpected failure is contained, reported and survivable
/// instead of tearing down the loop, tick or boundary that invoked it.
/// <para>
/// This generalises the per-COID isolation introduced by SS-02
/// (<c>SectorCombatTick.ProcessAll</c> / <c>SectorPlayerPoseTick.ProcessAll</c>), which were
/// two copies of the same pattern.
/// </para>
/// <para>
/// <b>Use this at architectural boundaries only</b> — tick stages, per-entity loops, event
/// dispatch, command handling, detached work. Do not wrap ordinary business logic in it:
/// expected failures belong in a specific <c>catch</c> close to the operation, and unexpected
/// ones should reach a boundary like this one rather than being silenced en route.
/// </para>
/// <para>
/// Exceptions deliberately <b>not</b> contained (see <see cref="IsUnrecoverable"/>):
/// <see cref="OperationCanceledException"/>, because cancellation is control flow rather than
/// failure and the surrounding loop must be allowed to stop; and
/// <see cref="OutOfMemoryException"/>, because continuing after memory exhaustion is not safe.
/// <see cref="StackOverflowException"/> cannot be caught in .NET at all and always terminates
/// the process.
/// </para>
/// </summary>
public static class Guard
{
    /// <summary>
    /// Runs <paramref name="work"/>, containing and reporting any unexpected failure.
    /// </summary>
    /// <param name="operation">What is being attempted, for diagnostics. Include identifiers
    /// but never secrets (e.g. <c>"sector tick: RebucketAllGrids"</c>).</param>
    /// <param name="work">The unit of work. Null is a no-op.</param>
    /// <param name="onError">Optional failure sink. Defaults to logging via
    /// <see cref="Logger.WriteException"/> at <see cref="LogType.Error"/>.</param>
    /// <returns><c>true</c> if the work completed; <c>false</c> if it failed and was contained.</returns>
    public static bool Run(string operation, Action work, Action<Exception> onError = null)
    {
        if (work == null)
            return true;

        try
        {
            work();
            return true;
        }
        catch (Exception ex) when (!IsUnrecoverable(ex))
        {
            Report(operation, ex, onError);
            return false;
        }
    }

    /// <summary>
    /// Runs <paramref name="work"/> for every item, isolating each one so a single bad item
    /// cannot skip the rest.
    /// </summary>
    /// <param name="items">Items to process. Null is a no-op.</param>
    /// <param name="operation">What is being attempted, for diagnostics.</param>
    /// <param name="work">Per-item work. Null is a no-op.</param>
    /// <param name="describe">Optional per-item identifier for diagnostics (e.g. an id).
    /// Defaults to the item's <c>ToString()</c>.</param>
    /// <param name="onError">Optional per-item failure sink. Defaults to logging.</param>
    /// <returns>The number of items that failed.</returns>
    public static int ForEach<T>(
        IEnumerable<T> items,
        string operation,
        Action<T> work,
        Func<T, string> describe = null,
        Action<T, Exception> onError = null)
    {
        if (items == null || work == null)
            return 0;

        var failures = 0;

        foreach (var item in items)
        {
            try
            {
                work(item);
            }
            catch (Exception ex) when (!IsUnrecoverable(ex))
            {
                failures++;

                var context = $"{operation} [{DescribeItem(item, describe)}]";

                if (onError == null)
                    Report(context, ex, null);
                else
                    ReportVia(() => onError(item, ex), context, ex);
            }
        }

        return failures;
    }

    /// <summary>
    /// Exceptions that must escape rather than be contained. Documented in
    /// <c>docs/exception-safety-audit.md</c> under "Deliberately unhandled".
    /// </summary>
    private static bool IsUnrecoverable(Exception ex) =>
        ex is OperationCanceledException || ex is OutOfMemoryException;

    private static string DescribeItem<T>(T item, Func<T, string> describe)
    {
        try
        {
            if (describe != null)
                return describe(item) ?? "null";

            return item?.ToString() ?? "null";
        }
        catch (Exception ex)
        {
            // Never let diagnostics generation become the failure.
            return $"<describe threw {ex.GetType().Name}>";
        }
    }

    private static void Report(string operation, Exception ex, Action<Exception> onError)
    {
        if (onError == null)
        {
            Logger.WriteException(LogType.Error, operation, ex);
            return;
        }

        ReportVia(() => onError(ex), operation, ex);
    }

    /// <summary>
    /// Invokes a caller-supplied error sink. If the sink itself throws, the original failure
    /// is still logged and neither exception is allowed to escape the guard.
    /// </summary>
    private static void ReportVia(Action sink, string operation, Exception original)
    {
        try
        {
            sink();
        }
        catch (Exception sinkFailure) when (!IsUnrecoverable(sinkFailure))
        {
            Logger.WriteException(LogType.Error, operation, original);
            Logger.WriteException(LogType.Error, $"{operation} (error sink also failed)", sinkFailure);
        }
    }
}
