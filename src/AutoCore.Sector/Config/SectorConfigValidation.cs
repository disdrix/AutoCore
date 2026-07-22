namespace AutoCore.Sector.Config;

using Microsoft.Extensions.Configuration;

/// <summary>
/// Pure config bind/validate for Sector host startup. Extracted so unit tests can cover
/// validation without binding shared ports or opening MySQL.
/// </summary>
public static class SectorConfigValidation
{
    public static SectorConfig Bind(IConfiguration configuration)
    {
        if (configuration == null)
            throw new ArgumentNullException(nameof(configuration));

        var config = new SectorConfig();
        configuration.Bind(config);
        return config;
    }

    /// <summary>
    /// Fails fast on missing required settings before DB/asset/network init.
    /// Auth connection string is optional (standalone sector /addplayer only).
    /// </summary>
    public static void Validate(SectorConfig config)
    {
        if (config == null)
            throw new ArgumentNullException(nameof(config));

        if (config.GameConfig == null)
            throw new InvalidOperationException("GameConfig is required.");

        if (config.GameConfig.Port <= 0)
            throw new InvalidOperationException("GameConfig.Port must be a positive port number.");

        if (string.IsNullOrWhiteSpace(config.GameConfig.PublicAddress))
            throw new InvalidOperationException("GameConfig.PublicAddress is required.");

        if (string.IsNullOrWhiteSpace(config.CharDatabaseConnectionString))
            throw new InvalidOperationException("CharDatabaseConnectionString is required.");

        if (string.IsNullOrWhiteSpace(config.WorldDatabaseConnectionString))
            throw new InvalidOperationException("WorldDatabaseConnectionString is required.");

        if (string.IsNullOrWhiteSpace(config.GamePath))
            throw new InvalidOperationException("GamePath is required.");

        if (config.GameConfig.DevControlPort < 0)
            throw new InvalidOperationException("GameConfig.DevControlPort cannot be negative.");
    }
}
