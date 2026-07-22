using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;

using Microsoft.Extensions.Configuration;

namespace AutoCore.Auth;

using AutoCore.Auth.Config;
using AutoCore.Auth.Network;
using AutoCore.Database.Auth;
using AutoCore.Utils;

public class Program : ExitableProgram
{
    private static AuthServer? Server { get; set; }

    /// <summary>
    /// Process host entry: binds ports and MySQL. Config validation is covered by
    /// <see cref="AuthServer.ValidateConfig"/> unit tests; live Main is a deliberate exclusion.
    /// </summary>
    [ExcludeFromCodeCoverage(Justification = "Process host entry — live ports/DB; config validated via AuthServer.ValidateConfig tests.")]
    public static void Main()
    {
        Initialize(ExitHandlerProc);

        var builder = new ConfigurationBuilder()
            .AddJsonFile("appsettings.auth.json")
            .AddJsonFile("appsettings.auth.env.json", true);

        var config = new AuthConfig();
        var configRoot = builder.Build();
        configRoot.Bind(config);

        AuthContext.InitializeConnectionString(config.AuthDatabaseConnectionString);
        AuthContext.EnsureCreated();

        Logger.UpdateConfig(config.LoggerConfig);

        Server = new AuthServer();
        Server.InitConsole();
        Server.Setup(config);

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

        Server?.Shutdown();

        Logger.WriteLog(LogType.Error, "Server shutdown completed!");

        Logger.WriteLog(LogType.Error, "Press any key to exit...");

        return false;
    }
}
