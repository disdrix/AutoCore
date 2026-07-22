namespace AutoCore.Launcher.Bootstrap;

using AutoCore.Auth.Config;
using AutoCore.Global.Config;
using AutoCore.Sector.Config;

/// <summary>
/// Ordered Launcher bootstrap: validate → DB → assets → runtime config → Auth → Global → Sector.
/// </summary>
public static class LauncherInitOrchestrator
{
    public static IReadOnlyList<LauncherInitStep> ExpectedSuccessfulOrder { get; } =
    [
        LauncherInitStep.ValidateConfig,
        LauncherInitStep.InitializeConnectionStrings,
        LauncherInitStep.EnsureDatabasesCreated,
        LauncherInitStep.InitializeAssets,
        LauncherInitStep.LoadAssets,
        LauncherInitStep.ApplyEarlyRuntimeConfig,
        LauncherInitStep.InitializeLootManager,
        LauncherInitStep.InitializeMapManager,
        LauncherInitStep.ApplyLateRuntimeConfig,
        LauncherInitStep.SetupAuth,
        LauncherInitStep.StartAuth,
        LauncherInitStep.SetupGlobal,
        LauncherInitStep.StartGlobal,
        LauncherInitStep.SetupSector,
        LauncherInitStep.StartSector,
    ];

    public static IReadOnlyList<string> ExpectedServerStartOrder { get; } =
        ["Auth", "Global", "Sector"];

    public static LauncherInitResult Run(
        AuthConfig auth,
        GlobalConfig global,
        SectorConfig sector,
        ILauncherGameBootstrap game,
        ILauncherServerHost authHost,
        ILauncherServerHost globalHost,
        ILauncherServerHost sectorHost,
        Func<string, bool>? pathExists = null,
        CancellationToken cancellationToken = default)
    {
        ArgumentNullException.ThrowIfNull(auth);
        ArgumentNullException.ThrowIfNull(global);
        ArgumentNullException.ThrowIfNull(sector);
        ArgumentNullException.ThrowIfNull(game);
        ArgumentNullException.ThrowIfNull(authHost);
        ArgumentNullException.ThrowIfNull(globalHost);
        ArgumentNullException.ThrowIfNull(sectorHost);

        var completed = new List<LauncherInitStep>(ExpectedSuccessfulOrder.Count);

        try
        {
            cancellationToken.ThrowIfCancellationRequested();

            var validation = LauncherConfigValidator.Validate(auth, global, sector, pathExists);
            completed.Add(LauncherInitStep.ValidateConfig);
            if (!validation.IsValid)
            {
                return LauncherInitResult.Failed(
                    LauncherInitStep.ValidateConfig,
                    validation.FormatErrors(),
                    completed);
            }

            cancellationToken.ThrowIfCancellationRequested();
            game.InitializeConnectionStrings(auth, global);
            completed.Add(LauncherInitStep.InitializeConnectionStrings);

            cancellationToken.ThrowIfCancellationRequested();
            game.EnsureDatabasesCreated();
            completed.Add(LauncherInitStep.EnsureDatabasesCreated);

            cancellationToken.ThrowIfCancellationRequested();
            var allowMissingCbid = global.GameConfig?.AllowMissingCBID ?? false;
            if (!game.InitializeAssetManager(global.GamePath, allowMissingCbid))
            {
                completed.Add(LauncherInitStep.InitializeAssets);
                return LauncherInitResult.Failed(
                    LauncherInitStep.InitializeAssets,
                    "Unable to initialize Asset Manager! Check the GamePath configuration.",
                    completed);
            }
            completed.Add(LauncherInitStep.InitializeAssets);

            cancellationToken.ThrowIfCancellationRequested();
            if (!game.LoadAllAssetData())
            {
                completed.Add(LauncherInitStep.LoadAssets);
                return LauncherInitResult.Failed(
                    LauncherInitStep.LoadAssets,
                    "Critical asset loading failed! Cannot continue without WAD or GLM files.",
                    completed);
            }
            completed.Add(LauncherInitStep.LoadAssets);

            cancellationToken.ThrowIfCancellationRequested();
            game.ApplyEarlyRuntimeConfig();
            completed.Add(LauncherInitStep.ApplyEarlyRuntimeConfig);

            cancellationToken.ThrowIfCancellationRequested();
            game.InitializeLootManager();
            completed.Add(LauncherInitStep.InitializeLootManager);

            cancellationToken.ThrowIfCancellationRequested();
            // MapManager failure is non-fatal in production.
            _ = game.InitializeMapManager();
            completed.Add(LauncherInitStep.InitializeMapManager);

            cancellationToken.ThrowIfCancellationRequested();
            game.ApplyLateRuntimeConfig();
            completed.Add(LauncherInitStep.ApplyLateRuntimeConfig);

            if (!StartHost(authHost, LauncherInitStep.SetupAuth, LauncherInitStep.StartAuth, completed, cancellationToken, out var authFail))
                return authFail!;

            if (!StartHost(globalHost, LauncherInitStep.SetupGlobal, LauncherInitStep.StartGlobal, completed, cancellationToken, out var globalFail))
                return globalFail!;

            if (!StartHost(sectorHost, LauncherInitStep.SetupSector, LauncherInitStep.StartSector, completed, cancellationToken, out var sectorFail))
                return sectorFail!;

            return LauncherInitResult.CreateSucceeded(completed);
        }
        catch (OperationCanceledException)
        {
            return LauncherInitResult.CreateCancelled(completed);
        }
    }

    private static bool StartHost(
        ILauncherServerHost host,
        LauncherInitStep setupStep,
        LauncherInitStep startStep,
        List<LauncherInitStep> completed,
        CancellationToken cancellationToken,
        out LauncherInitResult? failure)
    {
        cancellationToken.ThrowIfCancellationRequested();
        host.Setup();
        completed.Add(setupStep);

        cancellationToken.ThrowIfCancellationRequested();
        if (!host.Start())
        {
            completed.Add(startStep);
            failure = LauncherInitResult.Failed(
                startStep,
                $"Unable to start the {host.Name} server!",
                completed);
            return false;
        }

        completed.Add(startStep);
        failure = null;
        return true;
    }
}

public enum LauncherInitStep
{
    ValidateConfig,
    InitializeConnectionStrings,
    EnsureDatabasesCreated,
    InitializeAssets,
    LoadAssets,
    ApplyEarlyRuntimeConfig,
    InitializeLootManager,
    InitializeMapManager,
    ApplyLateRuntimeConfig,
    SetupAuth,
    StartAuth,
    SetupGlobal,
    StartGlobal,
    SetupSector,
    StartSector,
}

public sealed class LauncherInitResult
{
    private LauncherInitResult(
        bool success,
        bool cancelled,
        LauncherInitStep? failedStep,
        string? errorMessage,
        IReadOnlyList<LauncherInitStep> completedSteps)
    {
        Success = success;
        Cancelled = cancelled;
        FailedStep = failedStep;
        ErrorMessage = errorMessage;
        CompletedSteps = completedSteps;
    }

    public bool Success { get; }

    public bool Cancelled { get; }

    public LauncherInitStep? FailedStep { get; }

    public string? ErrorMessage { get; }

    public IReadOnlyList<LauncherInitStep> CompletedSteps { get; }

    public static LauncherInitResult CreateSucceeded(IReadOnlyList<LauncherInitStep> completed)
        => new(success: true, cancelled: false, failedStep: null, errorMessage: null, completed);

    public static LauncherInitResult Failed(
        LauncherInitStep failedStep,
        string errorMessage,
        IReadOnlyList<LauncherInitStep> completed)
        => new(success: false, cancelled: false, failedStep, errorMessage, completed);

    public static LauncherInitResult CreateCancelled(IReadOnlyList<LauncherInitStep> completed)
        => new(success: false, cancelled: true, failedStep: null, errorMessage: "Launcher init was cancelled.", completed);
}
