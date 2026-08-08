namespace AutoCore.Discord.Presence;

using AutoCore.Discord.Abstractions;
using AutoCore.Discord.Config;
using AutoCore.Discord.Services;
using AutoCore.Utils;

/// <summary>
/// Formats and pushes the online player count into Discord bot activity text.
/// </summary>
public sealed class PlayerCountPresenceUpdater
{
    public const string PlayersPlaceholder = "{players}";

    private readonly IPlayerCountSource _playerCountSource;
    private readonly IDiscordGateway _gateway;
    private readonly DiscordConfig _config;

    public PlayerCountPresenceUpdater(
        IPlayerCountSource playerCountSource,
        IDiscordGateway gateway,
        DiscordConfig config)
    {
        _playerCountSource = playerCountSource ?? throw new ArgumentNullException(nameof(playerCountSource));
        _gateway = gateway ?? throw new ArgumentNullException(nameof(gateway));
        _config = config ?? throw new ArgumentNullException(nameof(config));
    }

    /// <summary>Builds activity text from the template and current player count.</summary>
    public static string FormatStatus(string template, int playerCount)
    {
        template ??= string.Empty;
        var safeCount = playerCount < 0 ? 0 : playerCount;
        return template.Replace(PlayersPlaceholder, safeCount.ToString(), StringComparison.OrdinalIgnoreCase);
    }

    /// <summary>Reads the player count and updates gateway activity. Safe to call on a timer.</summary>
    public void Update()
    {
        try
        {
            var count = _playerCountSource.GetOnlinePlayerCount();
            var text = FormatStatus(_config.StatusTemplate, count);
            _gateway.SetActivity(text);
            LastPlayerCount = count;
            LastStatusText = text;
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            // Presence is best-effort; never take down the bot host for a failed update.
            Logger.WriteException(LogType.Warning, "discord presence update", ex);
        }
    }

    public int LastPlayerCount { get; private set; }
    public string LastStatusText { get; private set; } = string.Empty;
}
