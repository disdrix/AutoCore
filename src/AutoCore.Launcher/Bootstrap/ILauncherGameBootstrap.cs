namespace AutoCore.Launcher.Bootstrap;

using AutoCore.Auth.Config;
using AutoCore.Global.Config;

/// <summary>
/// Game/DB side effects of Launcher init, injectable for ordered-handoff tests.
/// </summary>
public interface ILauncherGameBootstrap
{
    void InitializeConnectionStrings(AuthConfig auth, GlobalConfig global);

    void EnsureDatabasesCreated();

    bool InitializeAssetManager(string gamePath, bool allowMissingCbid);

    bool LoadAllAssetData();

    /// <summary>
    /// Applies loot.tuning.json and serverConfig.yaml (before LootManager / MapManager).
    /// </summary>
    void ApplyEarlyRuntimeConfig();

    void InitializeLootManager();

    /// <summary>
    /// Returns false when map init fails; orchestrator continues anyway (matches production).
    /// </summary>
    bool InitializeMapManager();

    /// <summary>
    /// Applies wire isolation levers and log filters (after MapManager, before servers start).
    /// </summary>
    void ApplyLateRuntimeConfig();
}
