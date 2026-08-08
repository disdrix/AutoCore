namespace AutoCore.Launcher.Bootstrap;

using AutoCore.Sector.Config;
using AutoCore.Utils;

/// <summary>
/// Applies logging configuration for the Launcher process.
/// <para>
/// The Launcher hosts Auth, Global and Sector in one process, but <see cref="Logger"/> is
/// process-global, so exactly one LoggerConfig can win. The sector config drives it because
/// Sector is the gameplay-bearing server. Before this existed the Launcher never called
/// <see cref="Logger.UpdateConfig"/> at all, leaving every appsettings logging option dead.
/// </para>
/// </summary>
public static class LauncherLoggerSetup
{
    public static void Apply(SectorConfig? sectorConfig)
    {
        var loggerConfig = sectorConfig?.LoggerConfig;

        if (loggerConfig == null)
            return;

        Logger.UpdateConfig(loggerConfig);
    }
}
