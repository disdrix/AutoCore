namespace AutoCore.Utils.Reliability;

/// <summary>
/// The sanctioned way to detach work from the caller.
/// <para>
/// SS-17: a bare <c>_ = SomethingAsync()</c> discards the returned <see cref="Task"/>. If that
/// task faults, nothing observes the exception — it surfaces later (if at all) through
/// <see cref="TaskScheduler.UnobservedTaskException"/> when the GC finalizes the task, by which
/// point the context is gone. <see cref="FireAndForget"/> attaches a continuation that observes
/// the fault and reports it immediately, with the operation name attached.
/// </para>
/// <para>
/// Prefer awaiting. Use this only where the caller genuinely must not block — timer-driven
/// delayed work, per-connection handlers, socket pump loops.
/// </para>
/// </summary>
public static class SafeTask
{
    /// <summary>
    /// Observes <paramref name="task"/> and reports any failure. Returns immediately.
    /// </summary>
    /// <param name="task">The detached task. Null is a no-op.</param>
    /// <param name="operation">What the task is doing, for diagnostics. Include identifiers
    /// but never secrets (e.g. <c>"DevControlServer.HandleClient(127.0.0.1)"</c>).</param>
    /// <param name="onError">Optional failure sink, called once per underlying exception.
    /// Defaults to logging via <see cref="Logger.WriteException"/> at <see cref="LogType.Error"/>.</param>
    /// <param name="onCompleted">Optional completion hook, called after success, cancellation
    /// or failure. Intended for tests and lifecycle bookkeeping.</param>
    public static void FireAndForget(
        Task task,
        string operation,
        Action<Exception> onError = null,
        Action onCompleted = null)
    {
        if (task == null)
        {
            InvokeSafely(onCompleted, operation);
            return;
        }

        task.ContinueWith(
            completed =>
            {
                try
                {
                    if (completed.IsFaulted)
                        ReportFailures(completed, operation, onError);
                    else if (completed.IsCanceled)
                        Logger.WriteLog(LogType.Debug, $"{operation} was cancelled.");
                }
                finally
                {
                    InvokeSafely(onCompleted, operation);
                }
            },
            CancellationToken.None,
            TaskContinuationOptions.ExecuteSynchronously,
            TaskScheduler.Default);
    }

    /// <summary>
    /// Reports every underlying failure. Reading <c>task.Exception</c> is what marks the task
    /// observed; <see cref="AggregateException.Flatten"/> is used because <c>Task.WhenAll</c>
    /// hides all but the first failure behind <c>await</c>.
    /// </summary>
    private static void ReportFailures(Task completed, string operation, Action<Exception> onError)
    {
        var aggregate = completed.Exception;

        if (aggregate == null)
        {
            Logger.WriteLog(LogType.Error, $"{operation} faulted but exposed no exception.");
            return;
        }

        var inner = aggregate.Flatten().InnerExceptions;

        if (inner.Count == 0)
        {
            Report(operation, aggregate, onError);
            return;
        }

        foreach (var ex in inner)
        {
            // Cancellation surfacing as a fault is still cancellation, not an error.
            if (ex is OperationCanceledException)
            {
                Logger.WriteLog(LogType.Debug, $"{operation} was cancelled.");
                continue;
            }

            Report(operation, ex, onError);
        }
    }

    private static void Report(string operation, Exception ex, Action<Exception> onError)
    {
        if (onError == null)
        {
            Logger.WriteException(LogType.Error, operation, ex);
            return;
        }

        try
        {
            onError(ex);
        }
        catch (Exception sinkFailure)
        {
            // The reporting path must never fault the continuation, which would itself
            // become an unobserved task exception — exactly what this class exists to prevent.
            Logger.WriteException(LogType.Error, operation, ex);
            Logger.WriteException(LogType.Error, $"{operation} (error sink also failed)", sinkFailure);
        }
    }

    private static void InvokeSafely(Action action, string operation)
    {
        if (action == null)
            return;

        try
        {
            action();
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error, $"{operation} (completion hook failed)", ex);
        }
    }
}
