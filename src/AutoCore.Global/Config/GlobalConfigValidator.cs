using System.Net;

namespace AutoCore.Global.Config;

/// <summary>
/// Pure validation for <see cref="GlobalConfig"/> so host startup can fail fast
/// without binding ports or opening databases.
/// </summary>
public static class GlobalConfigValidator
{
    public static bool TryValidate(GlobalConfig? config, out IReadOnlyList<string> errors)
    {
        var list = new List<string>();

        if (config is null)
        {
            list.Add("GlobalConfig is required.");
            errors = list;
            return false;
        }

        if (string.IsNullOrWhiteSpace(config.CharDatabaseConnectionString))
            list.Add("CharDatabaseConnectionString is required.");

        if (string.IsNullOrWhiteSpace(config.WorldDatabaseConnectionString))
            list.Add("WorldDatabaseConnectionString is required.");

        if (string.IsNullOrWhiteSpace(config.GamePath))
            list.Add("GamePath is required.");

        if (string.IsNullOrWhiteSpace(config.CommunicatorAddress) ||
            !IPAddress.TryParse(config.CommunicatorAddress, out _))
        {
            list.Add("CommunicatorAddress must be a valid IP address.");
        }

        if (config.CommunicatorPort is <= 0 or > 65535)
            list.Add("CommunicatorPort must be between 1 and 65535.");

        if (config.GameConfig is null)
        {
            list.Add("GameConfig is required.");
        }
        else
        {
            if (config.GameConfig.Port is <= 0 or > 65535)
                list.Add("GameConfig.Port must be between 1 and 65535.");

            if (string.IsNullOrWhiteSpace(config.GameConfig.PublicAddress) ||
                !IPAddress.TryParse(config.GameConfig.PublicAddress, out _))
            {
                list.Add("GameConfig.PublicAddress must be a valid IP address.");
            }

            if (config.GameConfig.ExpectedVersion < 0)
                list.Add("GameConfig.ExpectedVersion must be non-negative.");
        }

        if (config.ServerInfoConfig is null)
        {
            list.Add("ServerInfoConfig is required.");
        }
        else
        {
            if (string.IsNullOrEmpty(config.ServerInfoConfig.Password))
                list.Add("ServerInfoConfig.Password is required.");

            if (config.ServerInfoConfig.MaxPlayers == 0)
                list.Add("ServerInfoConfig.MaxPlayers must be greater than 0.");
        }

        errors = list;
        return list.Count == 0;
    }
}
