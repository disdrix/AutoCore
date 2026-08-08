namespace AutoCore.Discord;

using AutoCore.Database.Auth;
using AutoCore.Discord.Abstractions;
using AutoCore.Discord.Commands;
using AutoCore.Discord.Config;
using AutoCore.Discord.Presence;
using AutoCore.Discord.Services;
using AutoCore.Utils;
using AutoCore.Utils.Reliability;

/// <summary>
/// Owns Discord gateway lifecycle, slash-command wiring, and presence updates.
/// Hosted by the Launcher when <see cref="DiscordConfig.Enabled"/> is true.
/// </summary>
public sealed class DiscordBotService : IAsyncDisposable
{
    private readonly DiscordConfig _config;
    private readonly IDiscordGateway _gateway;
    private readonly AccountLinkService _accountLinks;
    private readonly DiscordAccountCommands _commands;
    private readonly PlayerCountPresenceUpdater _presence;
    private readonly bool _ownsGateway;

    private CancellationTokenSource? _cts;
    private Timer? _presenceTimer;
    private bool _started;
    private bool _disposed;

    public DiscordBotService(
        DiscordConfig config,
        Func<AuthContext> authContextFactory,
        IPlayerCountSource playerCountSource,
        IDiscordGateway? gateway = null)
    {
        _config = config ?? throw new ArgumentNullException(nameof(config));
        ArgumentNullException.ThrowIfNull(authContextFactory);
        ArgumentNullException.ThrowIfNull(playerCountSource);

        if (gateway != null)
        {
            _gateway = gateway;
            _ownsGateway = false;
        }
        else
        {
            _gateway = new DiscordNetGateway();
            _ownsGateway = true;
        }

        _accountLinks = new AccountLinkService(authContextFactory, _config);
        _commands = new DiscordAccountCommands(_accountLinks);
        _presence = new PlayerCountPresenceUpdater(playerCountSource, _gateway, _config);
    }

    public bool IsStarted => _started;
    public IDiscordGateway Gateway => _gateway;
    public PlayerCountPresenceUpdater Presence => _presence;

    /// <summary>
    /// Connects the bot, registers slash commands, and starts the presence timer.
    /// Returns false when config is disabled or invalid (without throwing for disabled).
    /// </summary>
    public async Task<bool> StartAsync(CancellationToken cancellationToken = default)
    {
        if (_started)
            return true;

        if (!_config.Enabled)
        {
            Logger.WriteLog(LogType.Initialize, "Discord module is disabled; not starting.");
            return true;
        }

        var validation = _config.Validate();
        if (!validation.IsValid)
        {
            Logger.WriteLog(LogType.Error, "Discord config invalid: " + validation.FormatErrors());
            return false;
        }

        _cts = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);

        _gateway.Ready += OnReadyAsync;
        _gateway.SlashCommandReceived += OnSlashAsync;

        try
        {
            // Token is passed to the gateway only — never logged.
            await _gateway.StartAsync(_config.BotToken, _cts.Token).ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, "Discord bot start", ex);
            return false;
        }

        // Presence timer starts immediately; first Ready also triggers an update + command reg.
        var intervalMs = Math.Max(15, _config.PresenceUpdateIntervalSeconds) * 1000;
        _presenceTimer = new Timer(
            _ => SafeTask.FireAndForget(Task.Run(() => _presence.Update()), "Discord presence timer"),
            state: null,
            dueTime: TimeSpan.FromSeconds(5),
            period: TimeSpan.FromMilliseconds(intervalMs));

        _started = true;
        Logger.WriteLog(LogType.Initialize, "Discord bot start requested (awaiting Ready).");
        return true;
    }

    public async Task StopAsync()
    {
        if (!_started && _cts == null)
            return;

        try
        {
            _cts?.Cancel();
        }
        catch (ObjectDisposedException)
        {
            // ignore
        }

        if (_presenceTimer != null)
        {
            await _presenceTimer.DisposeAsync().ConfigureAwait(false);
            _presenceTimer = null;
        }

        _gateway.Ready -= OnReadyAsync;
        _gateway.SlashCommandReceived -= OnSlashAsync;

        try
        {
            await _gateway.StopAsync().ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Warning, "Discord bot stop", ex);
        }

        _started = false;
        Logger.WriteLog(LogType.Initialize, "Discord bot stopped.");
    }

    private async Task OnReadyAsync()
    {
        // SS-25: Ready boundary — command registration failure must not kill the gateway task.
        try
        {
            await _gateway.RegisterGuildCommandsAsync(
                _config.GuildId,
                DiscordAccountCommands.BuildRegistrations()).ConfigureAwait(false);

            _presence.Update();
            Logger.WriteLog(LogType.Initialize, "Discord bot Ready: commands registered, presence updated.");
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, "Discord bot Ready handler", ex);
        }
    }

    private Task OnSlashAsync(DiscordSlashCommandContext context)
        => _commands.HandleAsync(context);

    public async ValueTask DisposeAsync()
    {
        if (_disposed)
            return;
        _disposed = true;

        await StopAsync().ConfigureAwait(false);
        _cts?.Dispose();

        if (_ownsGateway)
            await _gateway.DisposeAsync().ConfigureAwait(false);
    }
}
