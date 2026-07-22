namespace AutoCore.Launcher.Bootstrap;

/// <summary>
/// Ordered Launcher shutdown: Sector → Global → Auth (reverse of start order).
/// Pure coordination — never binds ports.
/// </summary>
public static class LauncherShutdownCoordinator
{
    public static IReadOnlyList<string> ExpectedShutdownOrder { get; } =
        ["Sector", "Global", "Auth"];

    /// <summary>
    /// Shuts down hosts in reverse start order. Honors cancellation between hosts so callers
    /// never hang waiting on remaining hosts after cancel. Does not start or bind sockets.
    /// </summary>
    public static LauncherShutdownResult Shutdown(
        ILauncherServerHost sectorHost,
        ILauncherServerHost globalHost,
        ILauncherServerHost authHost,
        CancellationToken cancellationToken = default)
    {
        ArgumentNullException.ThrowIfNull(sectorHost);
        ArgumentNullException.ThrowIfNull(globalHost);
        ArgumentNullException.ThrowIfNull(authHost);

        var shutDown = new List<string>(ExpectedShutdownOrder.Count);

        try
        {
            ShutdownOne(sectorHost, shutDown, cancellationToken);
            ShutdownOne(globalHost, shutDown, cancellationToken);
            ShutdownOne(authHost, shutDown, cancellationToken);
            return LauncherShutdownResult.CreateCompleted(shutDown);
        }
        catch (OperationCanceledException)
        {
            return LauncherShutdownResult.CreateCancelled(shutDown);
        }
    }

    private static void ShutdownOne(
        ILauncherServerHost host,
        List<string> shutDown,
        CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        host.Shutdown();
        shutDown.Add(host.Name);
    }
}

public sealed class LauncherShutdownResult
{
    private LauncherShutdownResult(bool completed, bool cancelled, IReadOnlyList<string> shutDownHosts)
    {
        Completed = completed;
        Cancelled = cancelled;
        ShutDownHosts = shutDownHosts;
    }

    public bool Completed { get; }

    public bool Cancelled { get; }

    public IReadOnlyList<string> ShutDownHosts { get; }

    public static LauncherShutdownResult CreateCompleted(IReadOnlyList<string> shutDownHosts)
        => new(completed: true, cancelled: false, shutDownHosts);

    public static LauncherShutdownResult CreateCancelled(IReadOnlyList<string> shutDownHosts)
        => new(completed: false, cancelled: true, shutDownHosts);
}
