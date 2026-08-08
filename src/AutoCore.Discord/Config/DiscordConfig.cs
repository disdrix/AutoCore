namespace AutoCore.Discord.Config;

/// <summary>
/// Configuration for the optional Discord bot module. Disabled by default.
/// </summary>
public class DiscordConfig
{
    /// <summary>When false, Launcher skips Discord entirely.</summary>
    public bool Enabled { get; set; }

    /// <summary>Bot token from the Discord Developer Portal. Never log this value.</summary>
    public string BotToken { get; set; } = string.Empty;

    /// <summary>Guild (server) id used for instant slash-command registration.</summary>
    public ulong GuildId { get; set; }

    /// <summary>
    /// Text channel id where <c>/reportbug</c> zips are posted. 0 disables in-game bug reports.
    /// Bot needs Send Messages + Attach Files on this channel.
    /// </summary>
    public ulong BugReportChannelId { get; set; }

    /// <summary>Maximum game accounts a single Discord user may create/link. Default 1.</summary>
    public int MaxAccountsPerDiscordUser { get; set; } = 1;

    /// <summary>How often to refresh bot activity with the online player count.</summary>
    public int PresenceUpdateIntervalSeconds { get; set; } = 60;

    /// <summary>Activity text; <c>{players}</c> is replaced with the online count.</summary>
    public string StatusTemplate { get; set; } = "{players} online";

    /// <summary>When false, <c>/newAccount</c> is rejected.</summary>
    public bool AllowAccountCreation { get; set; } = true;

    public int MinPasswordLength { get; set; } = 6;
    public int MinUsernameLength { get; set; } = 3;
    public int MaxUsernameLength { get; set; } = 32;

    /// <summary>
    /// Validates config for startup. When <see cref="Enabled"/> is false, always succeeds.
    /// Never includes the bot token in error messages.
    /// </summary>
    public DiscordConfigValidationResult Validate()
    {
        if (!Enabled)
            return DiscordConfigValidationResult.Success();

        var errors = new List<string>();

        if (string.IsNullOrWhiteSpace(BotToken))
            errors.Add("Discord is enabled but BotToken is missing.");

        if (GuildId == 0)
            errors.Add("Discord is enabled but GuildId is missing or zero.");

        if (MaxAccountsPerDiscordUser < 1)
            errors.Add("MaxAccountsPerDiscordUser must be at least 1.");

        if (PresenceUpdateIntervalSeconds < 15)
            errors.Add("PresenceUpdateIntervalSeconds must be at least 15.");

        if (string.IsNullOrWhiteSpace(StatusTemplate))
            errors.Add("StatusTemplate must not be empty.");

        if (MinPasswordLength < 1)
            errors.Add("MinPasswordLength must be at least 1.");

        if (MinUsernameLength < 1 || MaxUsernameLength < MinUsernameLength)
            errors.Add("Username length bounds are invalid.");

        return errors.Count == 0
            ? DiscordConfigValidationResult.Success()
            : DiscordConfigValidationResult.Failure(errors);
    }
}

public sealed class DiscordConfigValidationResult
{
    private DiscordConfigValidationResult(bool isValid, IReadOnlyList<string> errors)
    {
        IsValid = isValid;
        Errors = errors;
    }

    public bool IsValid { get; }
    public IReadOnlyList<string> Errors { get; }

    public string FormatErrors() => string.Join(Environment.NewLine, Errors);

    public static DiscordConfigValidationResult Success()
        => new(true, Array.Empty<string>());

    public static DiscordConfigValidationResult Failure(IReadOnlyList<string> errors)
        => new(false, errors);
}
