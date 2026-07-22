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
using Microsoft.Extensions.Configuration;

public class Program : ExitableProgram
{
    private static GlobalServer Server { get; } = new();

    /// <summary>
    /// Process host entry: binds ports, MySQL, and assets. Config validation is covered by
    /// <see cref="GlobalConfigValidator"/> unit tests; live Main is a deliberate §4 exclusion.
    /// </summary>
    [ExcludeFromCodeCoverage(Justification = "Process host entry — DB/ports/assets; validated via GlobalConfigValidator.")]
    public static void Main()
    {
        Initialize(ExitHandlerProc);

        var builder = new ConfigurationBuilder()
            .AddJsonFile("appsettings.global.json")
            .AddJsonFile("appsettings.global.env.json", true);

        var config = new GlobalConfig();
        var configRoot = builder.Build();
        configRoot.Bind(config);

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
        Logger.WriteLog(LogType.Error, "Shutting down the server...");

        Server.Shutdown();

        Logger.WriteLog(LogType.Error, "Server shutdown completed!");

        Logger.WriteLog(LogType.Error, "Press any key to exit...");

        return false;
    }
}
