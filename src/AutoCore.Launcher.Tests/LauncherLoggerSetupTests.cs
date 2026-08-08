using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Launcher.Tests;

using AutoCore.Launcher.Bootstrap;
using AutoCore.Sector.Config;
using AutoCore.Utils;

[TestClass]
public class LauncherLoggerSetupTests
{
    [TestCleanup]
    public void Cleanup()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
    }

    /// <summary>
    /// The Launcher hosts Auth+Global+Sector in one process but historically never applied
    /// any LoggerConfig, so appsettings logging options were dead configuration and the
    /// process ran on defaults (log.txt). The sector config drives the shared Logger because
    /// Sector is the gameplay-bearing server.
    /// </summary>
    [TestMethod]
    public void Apply_UsesTheSectorLoggerConfig()
    {
        var sectorConfig = new SectorConfig
        {
            LoggerConfig = new Logger.LoggerConfig
            {
                LogToFile = false,
                IsDebugMode = false
            }
        };

        LauncherLoggerSetup.Apply(sectorConfig);

        Assert.AreSame(sectorConfig.LoggerConfig, Logger.Config,
            "The Launcher must actually apply the configured LoggerConfig.");
    }

    [TestMethod]
    public void Apply_NullConfig_DoesNotThrow_AndKeepsPreviousConfig()
    {
        var before = Logger.Config;

        LauncherLoggerSetup.Apply(null);

        Assert.AreSame(before, Logger.Config,
            "A missing config must not reset logging to defaults mid-flight.");
    }
}
