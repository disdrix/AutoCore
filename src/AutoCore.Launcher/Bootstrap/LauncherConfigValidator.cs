namespace AutoCore.Launcher.Bootstrap;

using AutoCore.Auth.Config;
using AutoCore.Global.Config;
using AutoCore.Sector.Config;

/// <summary>
/// Fail-fast validation of Launcher settings before DB / asset / port binding work.
/// </summary>
public static class LauncherConfigValidator
{
    public static LauncherConfigValidationResult Validate(
        AuthConfig auth,
        GlobalConfig global,
        SectorConfig sector,
        Func<string, bool>? pathExists = null)
    {
        ArgumentNullException.ThrowIfNull(auth);
        ArgumentNullException.ThrowIfNull(global);
        ArgumentNullException.ThrowIfNull(sector);

        var errors = new List<string>();
        var exists = pathExists ?? Directory.Exists;

        ValidateConnectionString(auth.AuthDatabaseConnectionString, "Auth.AuthDatabaseConnectionString", errors);
        ValidateConnectionString(global.CharDatabaseConnectionString, "Global.CharDatabaseConnectionString", errors);
        ValidateConnectionString(global.WorldDatabaseConnectionString, "Global.WorldDatabaseConnectionString", errors);
        ValidateConnectionString(sector.CharDatabaseConnectionString, "Sector.CharDatabaseConnectionString", errors);
        ValidateConnectionString(sector.WorldDatabaseConnectionString, "Sector.WorldDatabaseConnectionString", errors);

        if (auth.AuthSocketPort <= 0)
            errors.Add("Auth.AuthSocketPort must be a positive port number.");
        if (auth.CommunicatorPort <= 0)
            errors.Add("Auth.CommunicatorPort must be a positive port number.");
        if (global.CommunicatorPort <= 0)
            errors.Add("Global.CommunicatorPort must be a positive port number.");
        if (global.GameConfig is null || global.GameConfig.Port <= 0)
            errors.Add("Global.GameConfig.Port must be a positive port number.");
        if (sector.GameConfig is null || sector.GameConfig.Port <= 0)
            errors.Add("Sector.GameConfig.Port must be a positive port number.");

        if (string.IsNullOrWhiteSpace(global.GamePath))
        {
            errors.Add("Global.GamePath is required.");
        }
        else if (!exists(global.GamePath))
        {
            errors.Add($"Global.GamePath does not exist: {global.GamePath}");
        }

        if (!string.IsNullOrWhiteSpace(sector.GamePath) && !exists(sector.GamePath))
            errors.Add($"Sector.GamePath does not exist: {sector.GamePath}");

        return errors.Count == 0
            ? LauncherConfigValidationResult.Success()
            : LauncherConfigValidationResult.Failure(errors);
    }

    /// <summary>
    /// Validates settings and throws <see cref="InvalidOperationException"/> on the first failure set.
    /// </summary>
    public static void ValidateOrThrow(
        AuthConfig auth,
        GlobalConfig global,
        SectorConfig sector,
        Func<string, bool>? pathExists = null)
    {
        var result = Validate(auth, global, sector, pathExists);
        if (!result.IsValid)
            throw new InvalidOperationException(result.FormatErrors());
    }

    private static void ValidateConnectionString(string? connectionString, string name, List<string> errors)
    {
        if (string.IsNullOrWhiteSpace(connectionString))
        {
            errors.Add($"{name} is required.");
            return;
        }

        // Minimal structural check so obviously bad values fail fast without opening MySQL.
        if (!connectionString.Contains('=', StringComparison.Ordinal))
            errors.Add($"{name} is not a valid connection string (missing key=value pairs).");
    }
}

public sealed class LauncherConfigValidationResult
{
    private LauncherConfigValidationResult(IReadOnlyList<string> errors)
    {
        Errors = errors;
    }

    public bool IsValid => Errors.Count == 0;

    public IReadOnlyList<string> Errors { get; }

    public static LauncherConfigValidationResult Success()
        => new(Array.Empty<string>());

    public static LauncherConfigValidationResult Failure(IEnumerable<string> errors)
        => new(errors.Where(static e => !string.IsNullOrWhiteSpace(e)).ToArray());

    public string FormatErrors()
        => Errors.Count == 0
            ? string.Empty
            : "Launcher configuration validation failed:" + Environment.NewLine +
              string.Join(Environment.NewLine, Errors.Select(static e => " - " + e));
}
