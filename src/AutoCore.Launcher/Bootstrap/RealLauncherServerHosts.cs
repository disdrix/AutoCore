namespace AutoCore.Launcher.Bootstrap;

using AutoCore.Auth.Config;
using AutoCore.Auth.Network;
using AutoCore.Global.Config;
using AutoCore.Global.Network;
using AutoCore.Sector.Config;
using AutoCore.Sector.Network;

/// <summary>
/// Thin adapters wrapping production Auth/Global/Sector servers for the init orchestrator.
/// </summary>
public sealed class AuthLauncherServerHost : ILauncherServerHost
{
    private readonly AuthServer _server;
    private readonly AuthConfig _config;

    public AuthLauncherServerHost(AuthServer server, AuthConfig config)
    {
        _server = server ?? throw new ArgumentNullException(nameof(server));
        _config = config ?? throw new ArgumentNullException(nameof(config));
    }

    public string Name => "Auth";
    public bool IsStarted { get; private set; }
    public bool IsShutdown { get; private set; }

    public void Setup() => _server.Setup(_config);

    public bool Start()
    {
        var ok = _server.Start();
        IsStarted = ok;
        return ok;
    }

    public void Shutdown()
    {
        _server.Shutdown();
        IsShutdown = true;
        IsStarted = false;
    }
}

public sealed class GlobalLauncherServerHost : ILauncherServerHost
{
    private readonly GlobalServer _server;
    private readonly GlobalConfig _config;

    public GlobalLauncherServerHost(GlobalServer server, GlobalConfig config)
    {
        _server = server ?? throw new ArgumentNullException(nameof(server));
        _config = config ?? throw new ArgumentNullException(nameof(config));
    }

    public string Name => "Global";
    public bool IsStarted { get; private set; }
    public bool IsShutdown { get; private set; }

    public void Setup() => _server.Setup(_config);

    public bool Start()
    {
        var ok = _server.Start();
        IsStarted = ok;
        return ok;
    }

    public void Shutdown()
    {
        _server.Shutdown();
        IsShutdown = true;
        IsStarted = false;
    }
}

public sealed class SectorLauncherServerHost : ILauncherServerHost
{
    private readonly SectorServer _server;
    private readonly SectorConfig _config;

    public SectorLauncherServerHost(SectorServer server, SectorConfig config)
    {
        _server = server ?? throw new ArgumentNullException(nameof(server));
        _config = config ?? throw new ArgumentNullException(nameof(config));
    }

    public string Name => "Sector";
    public bool IsStarted { get; private set; }
    public bool IsShutdown { get; private set; }

    public void Setup() => _server.Setup(_config);

    public bool Start()
    {
        var ok = _server.Start();
        IsStarted = ok;
        return ok;
    }

    public void Shutdown()
    {
        _server.Shutdown();
        IsShutdown = true;
        IsStarted = false;
    }
}
