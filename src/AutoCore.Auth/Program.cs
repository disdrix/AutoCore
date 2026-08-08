using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;

using Microsoft.Extensions.Configuration;

namespace AutoCore.Auth;

using AutoCore.Auth.Config;
using AutoCore.Auth.Network;
using AutoCore.Database.Auth;
using AutoCore.Utils;
using AutoCore.Utils.Reliability;

public class Program : ExitableProgram
{
    private static AuthServer? Server { get; set; }

    /// <summary>
    /// Process host entry: binds ports and MySQL. Config validation is covered by
    /// <see cref="AuthServer.ValidateConfig"/> unit tests; live Main is a deliberate exclusion.
    /// </summary>
    [ExcludeFromCodeCoverage(Justification = "Process host entry — live ports/DB; config validated via AuthServer.ValidateConfig tests.")]
    public static int Main()
    {
        // SS-07: register last-resort diagnostics before anything can fail.
        CrashHandler.Install("Auth");

        try
        {
            Run();
            return 0;
        }
        catch (Exception ex)
        {
            // Startup failures (missing config, DB unreachable) are genuinely unrecoverable and
            // must still terminate — but diagnosably, rather than as a bare runtime stack dump.
            Logger.WriteException(LogType.Fatal, "Auth server startup", ex);
            return 1;
        }
    }

    private static void Run()
    {
        Initialize(ExitHandlerProc);

        var builder = new ConfigurationBuilder()
            .AddJsonFile("appsettings.auth.json")
            .AddJsonFile("appsettings.auth.env.json", true);

        var config = new AuthConfig();
        var configRoot = builder.Build();
        configRoot.Bind(config);

        AuthContext.InitializeConnectionString(config.AuthDatabaseConnectionString);

        // SS-20: bootstrap admin password comes from configuration; there is no built-in default.
        AuthContext.DefaultAdminPassword = config.DefaultAdminPassword;
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
        Logger.WriteLog(LogType.Initialize, "Shutting down the server...");

        // SS-07: this runs on the console control-handler thread. An exception escaping here
        // is unhandled and would turn an orderly shutdown into a crash.
        Guard.Run("Auth server shutdown", () => Server?.Shutdown());

        Logger.WriteLog(LogType.Initialize, "Server shutdown completed!");

        Logger.WriteLog(LogType.Error, "Press any key to exit...");

        return false;
    }
}
