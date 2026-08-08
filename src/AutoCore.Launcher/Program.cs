using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;

namespace AutoCore.Sector;

using AutoCore.Auth.Network;
using AutoCore.Database.Auth;
using AutoCore.Global.Network;
using AutoCore.Launcher.Bootstrap;
using AutoCore.Sector.Network;
using AutoCore.Utils;
using AutoCore.Utils.Commands;
using AutoCore.Utils.Logging;
using AutoCore.Utils.Reliability;

public class Program : ExitableProgram
{
    private static AuthServer AuthServer { get; } = new();
    private static GlobalServer GlobalServer { get; } = new();
    private static SectorServer SectorServer { get; } = new();

    private static ILauncherServerHost? AuthHost { get; set; }
    private static ILauncherServerHost? GlobalHost { get; set; }
    private static ILauncherServerHost? SectorHost { get; set; }
    private static ILauncherServerHost? DiscordHost { get; set; }

    /// <summary>
    /// Process host entry: loads configs and starts Auth/Global/Sector. Config validation is
    /// covered by LauncherConfigValidator unit tests; live Main is a deliberate §4 exclusion.
    /// </summary>
    [ExcludeFromCodeCoverage(Justification = "Process host entry — binds shared ports/DB; validated via LauncherConfigValidator.")]
    public static int Main()
    {
        // SS-07: register last-resort diagnostics before anything can fail. This process hosts
        // Auth, Global and Sector together, so an unhandled exception here takes down all three.
        CrashHandler.Install("Launcher");

        try
        {
            Run();
            return 0;
        }
        catch (Exception ex)
        {
            // Startup failures (invalid config, DB unreachable, missing assets) are genuinely
            // unrecoverable and must still terminate — but diagnosably.
            Logger.WriteException(LogType.Fatal, "Launcher startup", ex);
            return 1;
        }
    }

    private static void Run()
    {
        // Disable scope trimming so commands remain scoped (auth.exit, global.exit, sector.exit)
        CommandProcessor.UseScopes();

        Initialize(ExitHandlerProc);

        var authConfig = LauncherConfigLoader.LoadAuthConfig();
        var globalConfig = LauncherConfigLoader.LoadGlobalConfig();
        var sectorConfig = LauncherConfigLoader.LoadSectorConfig();
        var discordConfig = LauncherConfigLoader.LoadDiscordConfig();

        LauncherConfigValidator.ValidateOrThrow(authConfig, globalConfig, sectorConfig);

        // Apply logging configuration for the whole hosted process (the Launcher previously
        // never did this, leaving LoggerConfig in appsettings dead and structured logging off).
        LauncherLoggerSetup.Apply(sectorConfig);

        AuthHost = new AuthLauncherServerHost(AuthServer, authConfig);
        GlobalHost = new GlobalLauncherServerHost(GlobalServer, globalConfig);
        SectorHost = new SectorLauncherServerHost(SectorServer, sectorConfig);

        if (discordConfig.Enabled)
        {
            DiscordHost = new DiscordLauncherServerHost(
                discordConfig,
                static () => new AuthContext(),
                new AuthServerPlayerCountSource(AuthServer));
        }

        var initResult = LauncherInitOrchestrator.Run(
            authConfig,
            globalConfig,
            sectorConfig,
            new DefaultLauncherGameBootstrap(),
            AuthHost,
            GlobalHost,
            SectorHost,
            discordHost: DiscordHost);

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

        GameLog.Info("ServerReady",
            ("ServerName", "Launcher"),
            ("BuildVersion", ServerIdentity.BuildVersion),
            ("CommitHash", ServerIdentity.CommitHash),
            ("ServerInstanceId", ServerIdentity.ServerInstanceId));

        AuthServer.ProcessCommands();

        GC.Collect();

        Process.GetCurrentProcess().WaitForExit();
    }

    [ExcludeFromCodeCoverage(Justification = "Process-exit handler tied to live server hosts.")]
    private static bool ExitHandlerProc(byte sig)
    {
        Logger.WriteLog(LogType.Initialize, "Shutting down the servers...");
        GameLog.Info("ServerShutdownRequested", ("ServerName", "Launcher"));

        // SS-07: this runs on the console control-handler thread. Each server is isolated so a
        // failure shutting one down still lets the other two release their ports and sockets.
        if (SectorHost is not null && GlobalHost is not null && AuthHost is not null)
        {
            Guard.Run("Launcher shutdown", () =>
                LauncherShutdownCoordinator.Shutdown(SectorHost, GlobalHost, AuthHost, discordHost: DiscordHost));
        }
        else
        {
            if (DiscordHost is not null)
                Guard.Run("Discord bot shutdown", DiscordHost.Shutdown);
            Guard.Run("Sector server shutdown", SectorServer.Shutdown);
            Guard.Run("Global server shutdown", GlobalServer.Shutdown);
            Guard.Run("Auth server shutdown", AuthServer.Shutdown);
        }

        Logger.WriteLog(LogType.Initialize, "Server shutdowns completed!");
        GameLog.Info("ServerStopped", ("ServerName", "Launcher"));
        GameLog.Flush(TimeSpan.FromSeconds(5));

        Logger.WriteLog(LogType.Error, "Press any key to exit...");

        return false;
    }
}
