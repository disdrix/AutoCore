using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;

namespace AutoCore.Sector;

using AutoCore.Auth.Network;
using AutoCore.Global.Network;
using AutoCore.Launcher.Bootstrap;
using AutoCore.Sector.Network;
using AutoCore.Utils;
using AutoCore.Utils.Commands;

public class Program : ExitableProgram
{
    private static AuthServer AuthServer { get; } = new();
    private static GlobalServer GlobalServer { get; } = new();
    private static SectorServer SectorServer { get; } = new();

    private static ILauncherServerHost? AuthHost { get; set; }
    private static ILauncherServerHost? GlobalHost { get; set; }
    private static ILauncherServerHost? SectorHost { get; set; }

    /// <summary>
    /// Process host entry: loads configs and starts Auth/Global/Sector. Config validation is
    /// covered by LauncherConfigValidator unit tests; live Main is a deliberate §4 exclusion.
    /// </summary>
    [ExcludeFromCodeCoverage(Justification = "Process host entry — binds shared ports/DB; validated via LauncherConfigValidator.")]
    public static void Main()
    {
        // Disable scope trimming so commands remain scoped (auth.exit, global.exit, sector.exit)
        CommandProcessor.UseScopes();

        Initialize(ExitHandlerProc);

        var authConfig = LauncherConfigLoader.LoadAuthConfig();
        var globalConfig = LauncherConfigLoader.LoadGlobalConfig();
        var sectorConfig = LauncherConfigLoader.LoadSectorConfig();

        LauncherConfigValidator.ValidateOrThrow(authConfig, globalConfig, sectorConfig);

        AuthHost = new AuthLauncherServerHost(AuthServer, authConfig);
        GlobalHost = new GlobalLauncherServerHost(GlobalServer, globalConfig);
        SectorHost = new SectorLauncherServerHost(SectorServer, sectorConfig);

        var initResult = LauncherInitOrchestrator.Run(
            authConfig,
            globalConfig,
            sectorConfig,
            new DefaultLauncherGameBootstrap(),
            AuthHost,
            GlobalHost,
            SectorHost);

        if (!initResult.Success)
        {
            Logger.WriteLog(LogType.Error, initResult.ErrorMessage ?? "Launcher initialization failed.");

            if (initResult.FailedStep is LauncherInitStep.InitializeAssets
                or LauncherInitStep.LoadAssets)
            {
                throw new Exception(initResult.ErrorMessage);
            }

            return;
        }

        AuthServer.ProcessCommands();

        GC.Collect();

        Process.GetCurrentProcess().WaitForExit();
    }

    [ExcludeFromCodeCoverage(Justification = "Process-exit handler tied to live server hosts.")]
    private static bool ExitHandlerProc(byte sig)
    {
        Logger.WriteLog(LogType.Error, "Shutting down the servers...");

        if (SectorHost is not null && GlobalHost is not null && AuthHost is not null)
        {
            LauncherShutdownCoordinator.Shutdown(SectorHost, GlobalHost, AuthHost);
        }
        else
        {
            SectorServer.Shutdown();
            GlobalServer.Shutdown();
            AuthServer.Shutdown();
        }

        Logger.WriteLog(LogType.Error, "Server shutdowns completed!");

        Logger.WriteLog(LogType.Error, "Press any key to exit...");

        return false;
    }
}
