namespace AutoCore.Launcher.Tests.Fakes;

using AutoCore.Auth.Config;
using AutoCore.Global.Config;
using AutoCore.Launcher.Bootstrap;

internal sealed class FakeLauncherGameBootstrap : ILauncherGameBootstrap
{
    private readonly List<string> _eventLog;
    private readonly bool _assetsInitialize;
    private readonly bool _assetsLoad;
    private readonly bool _mapInitialize;

    public FakeLauncherGameBootstrap(
        List<string> eventLog,
        bool assetsInitialize = true,
        bool assetsLoad = true,
        bool mapInitialize = true)
    {
        _eventLog = eventLog;
        _assetsInitialize = assetsInitialize;
        _assetsLoad = assetsLoad;
        _mapInitialize = mapInitialize;
    }

    public AuthConfig? LastAuthConfig { get; private set; }
    public GlobalConfig? LastGlobalConfig { get; private set; }
    public string? LastGamePath { get; private set; }
    public bool? LastAllowMissingCbid { get; private set; }

    public void InitializeConnectionStrings(AuthConfig auth, GlobalConfig global)
    {
        LastAuthConfig = auth;
        LastGlobalConfig = global;
        _eventLog.Add(nameof(InitializeConnectionStrings));
    }

    public void EnsureDatabasesCreated()
        => _eventLog.Add(nameof(EnsureDatabasesCreated));

    public bool InitializeAssetManager(string gamePath, bool allowMissingCbid)
    {
        LastGamePath = gamePath;
        LastAllowMissingCbid = allowMissingCbid;
        _eventLog.Add(nameof(InitializeAssetManager));
        return _assetsInitialize;
    }

    public bool LoadAllAssetData()
    {
        _eventLog.Add(nameof(LoadAllAssetData));
        return _assetsLoad;
    }

    public void ApplyEarlyRuntimeConfig()
        => _eventLog.Add(nameof(ApplyEarlyRuntimeConfig));

    public void InitializeLootManager()
        => _eventLog.Add(nameof(InitializeLootManager));

    public bool InitializeMapManager()
    {
        _eventLog.Add(nameof(InitializeMapManager));
        return _mapInitialize;
    }

    public void ApplyLateRuntimeConfig()
        => _eventLog.Add(nameof(ApplyLateRuntimeConfig));
}
