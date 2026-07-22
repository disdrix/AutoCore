namespace AutoCore.Launcher.Bootstrap;

/// <summary>
/// Minimal host seam for Auth / Global / Sector handoff without binding real sockets in tests.
/// </summary>
public interface ILauncherServerHost
{
    string Name { get; }

    bool IsStarted { get; }

    bool IsShutdown { get; }

    void Setup();

    bool Start();

    void Shutdown();
}
