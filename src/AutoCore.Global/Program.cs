using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;

namespace AutoCore.Global;

using AutoCore.Database.Char;
using AutoCore.Database.World;
using AutoCore.Game.Constants;
using AutoCore.Game.Managers;
using AutoCore.Global.Config;
using AutoCore.Global.Network;
using AutoCore.Utils;
using AutoCore.Utils.Reliability;
using Microsoft.Extensions.Configuration;

public class Program : ExitableProgram
{
    private static GlobalServer Server { get; } = new();

    /// <summary>
    /// Process host entry: binds ports, MySQL, and assets. Config validation is covered by
    /// <see cref="GlobalConfigValidator"/> unit tests; live Main is a deliberate §4 exclusion.
    /// </summary>
    [ExcludeFromCodeCoverage(Justification = "Process host entry — DB/ports/assets; validated via GlobalConfigValidator.")]
    public static int Main()
    {
        // SS-07: register last-resort diagnostics before anything can fail.
        CrashHandler.Install("Global");

        try
        {
            Run();
            return 0;
        }
        catch (Exception ex)
        {
            // Startup failures (invalid config, DB unreachable, missing assets) are genuinely
            // unrecoverable and must still terminate — but diagnosably.
            Logger.WriteException(LogType.Fatal, "Global server startup", ex);
            return 1;
        }
    }

    private static void Run()
    {
        Initialize(ExitHandlerProc);

        var builder = new ConfigurationBuilder()
            .AddJsonFile("appsettings.global.json")
            .AddJsonFile("appsettings.global.env.json", true);

        var config = new GlobalConfig();
        var configRoot = builder.Build();
        configRoot.Bind(config);

        // SS-07: Global declared LoggerConfig but never applied it, so its configured file
        // logging was silently inert and crash diagnostics went to the console only.
        Logger.UpdateConfig(config.LoggerConfig);

        if (!GlobalConfigValidator.TryValidate(config, out var configErrors))
        {
            foreach (var error in configErrors)
                Logger.WriteLog(LogType.Error, error);

            throw new InvalidOperationException("Invalid Global configuration.");
        }

        CharContext.InitializeConnectionString(config.CharDatabaseConnectionString);
        WorldContext.InitializeConnectionString(config.WorldDatabaseConnectionString);

        CharContext.EnsureCreated();
        WorldContext.EnsureCreated();

        Server.InitConsole();
        Server.Setup(config);

        if (!AssetManager.Instance.Initialize(config.GamePath, ServerType.Global, config.GameConfig.AllowMissingCBID))
        {
            Logger.WriteLog(LogType.Error, "Unable to initialize Asset Manager! Check the GamePath configuration.");
            throw new Exception("Unable to initialize Asset Manager!");
        }

        if (!AssetManager.Instance.LoadAllData())
        {
            Logger.WriteLog(LogType.Error, "Critical asset loading failed! Cannot continue without WAD or GLM files.");
            throw new Exception("Critical asset loading failed!");
        }

        if (!MapManager.Instance.Initialize())
        {
            Logger.WriteLog(LogType.Error, "MapManager initialization failed. Continuing anyway.");
        }

        if (!Server.Start())
        {
            Logger.WriteLog(LogType.Error, "Unable to start the server!");

            return;
        }

        Server.ProcessCommands();

        GC.Collect();

        Process.GetCurrentProcess().WaitForExit();
    }

    [ExcludeFromCodeCoverage(Justification = "Process-exit handler tied to live Server singleton.")]
    private static bool ExitHandlerProc(byte sig)
    {
        Logger.WriteLog(LogType.Initialize, "Shutting down the server...");

        // SS-07: this runs on the console control-handler thread. An exception escaping here
        // is unhandled and would turn an orderly shutdown into a crash.
        Guard.Run("Global server shutdown", Server.Shutdown);

        Logger.WriteLog(LogType.Initialize, "Server shutdown completed!");

        Logger.WriteLog(LogType.Error, "Press any key to exit...");

        return false;
    }
}
