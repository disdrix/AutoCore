namespace AutoCore.Utils.Reliability;

using System.Reflection;

/// <summary>
/// Last-resort process diagnostics.
/// <para>
/// SS-07: before this existed, an exception that escaped every boundary terminated the
/// process with only the runtime's default stack dump — and under <c>AutoCore.Launcher</c>
/// that takes Auth, Global and Sector down together. This wires the two process-global hooks
/// .NET provides so such a failure is at least recorded with full context first.
/// </para>
/// <para>
/// <b>This is a diagnostic layer, not a recovery mechanism.</b> It cannot stop a genuinely
/// unhandled exception from terminating the process — <c>AppDomain.UnhandledException</c> is
/// notification-only on .NET Core. Real containment belongs at the boundaries
/// (<see cref="Guard"/>, <see cref="SafeTask"/>); reaching this handler means one was missing.
/// </para>
/// </summary>
public static class CrashHandler
{
    private static readonly object InstallLock = new();
    private static bool _installed;

    /// <summary>The subsystem name recorded in crash reports; set by <see cref="Install"/>.</summary>
    public static string Subsystem { get; private set; } = "Unknown";

    /// <summary>
    /// Registers the process-global exception hooks. Idempotent — repeat calls are ignored so
    /// the in-process Launcher cannot double-register.
    /// </summary>
    /// <param name="subsystem">Which server this process is (e.g. "Sector", "Launcher").</param>
    /// <returns><c>true</c> if this call performed the registration.</returns>
    public static bool Install(string subsystem)
    {
        lock (InstallLock)
        {
            if (_installed)
                return false;

            Subsystem = string.IsNullOrWhiteSpace(subsystem) ? "Unknown" : subsystem;

            AppDomain.CurrentDomain.UnhandledException += OnUnhandledException;
            TaskScheduler.UnobservedTaskException += OnUnobservedTaskException;

            _installed = true;
            return true;
        }
    }

    /// <summary>Test seam: removes the hooks so a test process is not left mutated.</summary>
    internal static void Uninstall()
    {
        lock (InstallLock)
        {
            if (!_installed)
                return;

            AppDomain.CurrentDomain.UnhandledException -= OnUnhandledException;
            TaskScheduler.UnobservedTaskException -= OnUnobservedTaskException;

            _installed = false;
            Subsystem = "Unknown";
        }
    }

    private static void OnUnhandledException(object sender, UnhandledExceptionEventArgs e)
    {
        // Nothing above us will run if IsTerminating; this is the final chance to record it.
        var report = DescribeCrash(Subsystem, e.ExceptionObject, e.IsTerminating);

        Logger.WriteLog(e.IsTerminating ? LogType.Fatal : LogType.Error, report);
    }

    private static void OnUnobservedTaskException(object sender, UnobservedTaskExceptionEventArgs e)
    {
        var report = DescribeUnobservedTask(Subsystem, e.Exception);

        Logger.WriteLog(LogType.Error, report);

        // Mark observed: since .NET 4.5 this no longer terminates the process, but leaving it
        // unobserved keeps the exception pinned and hides it from anything watching for faults.
        e.SetObserved();
    }

    /// <summary>
    /// Builds the crash report. Pure and public-internal so it can be tested without
    /// registering process-global handlers.
    /// </summary>
    internal static string DescribeCrash(string subsystem, object exceptionObject, bool isTerminating)
    {
        var detail = exceptionObject switch
        {
            Exception ex => Describe(ex),

            // The CLR permits throwing non-Exception objects from other languages.
            null => "<no exception object supplied>",
            _ => $"<non-Exception object of type {exceptionObject.GetType().FullName}: {SafeToString(exceptionObject)}>"
        };

        return string.Join(
            Environment.NewLine,
            $"UNHANDLED EXCEPTION — {(isTerminating ? "process is terminating" : "process is continuing")}",
            $"  subsystem : {subsystem}",
            $"  version   : {BuildVersion()}",
            $"  thread    : {DescribeThread()}",
            $"  timestamp : {DateTime.UtcNow:yyyy-MM-dd HH:mm:ss.fff}Z",
            $"  detail    : {detail}");
    }

    /// <summary>
    /// Builds the unobserved-task report. Pure and internal for testability.
    /// </summary>
    internal static string DescribeUnobservedTask(string subsystem, AggregateException exception)
    {
        var flattened = exception?.Flatten();

        var detail = flattened == null
            ? "<no exception supplied>"
            : string.Join(
                Environment.NewLine,
                flattened.InnerExceptions.Count > 0
                    ? flattened.InnerExceptions.Select((ex, i) => $"    [{i}] {Describe(ex)}")
                    : new[] { $"    {Describe(flattened)}" });

        return string.Join(
            Environment.NewLine,
            "UNOBSERVED TASK EXCEPTION — a detached task faulted with nobody watching",
            $"  subsystem : {subsystem}",
            $"  version   : {BuildVersion()}",
            $"  timestamp : {DateTime.UtcNow:yyyy-MM-dd HH:mm:ss.fff}Z",
            "  hint      : route detached work through SafeTask.FireAndForget so failures are",
            "              reported at the point of failure instead of at GC time.",
            detail);
    }

    private static string Describe(Exception ex)
    {
        try
        {
            // ToString() carries type, message, stack trace and the whole inner chain.
            return ex.ToString();
        }
        catch (Exception formatFailure)
        {
            return $"<{ex.GetType().Name}.ToString() threw {formatFailure.GetType().Name}>";
        }
    }

    private static string SafeToString(object value)
    {
        try
        {
            return value.ToString() ?? "null";
        }
        catch (Exception ex)
        {
            return $"<ToString() threw {ex.GetType().Name}>";
        }
    }

    private static string DescribeThread()
    {
        try
        {
            var thread = Thread.CurrentThread;
            var name = string.IsNullOrEmpty(thread.Name) ? "<unnamed>" : thread.Name;

            return $"id={thread.ManagedThreadId} name={name} pool={thread.IsThreadPoolThread} background={thread.IsBackground}";
        }
        catch (Exception ex)
        {
            return $"<unavailable: {ex.GetType().Name}>";
        }
    }

    private static string BuildVersion()
    {
        try
        {
            var assembly = Assembly.GetEntryAssembly() ?? Assembly.GetExecutingAssembly();

            var informational = assembly
                .GetCustomAttribute<AssemblyInformationalVersionAttribute>()?
                .InformationalVersion;

            return informational ?? assembly.GetName().Version?.ToString() ?? "unknown";
        }
        catch (Exception ex)
        {
            return $"<unavailable: {ex.GetType().Name}>";
        }
    }
}
