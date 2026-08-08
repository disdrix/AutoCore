namespace AutoCore.Discord.Abstractions;

using AutoCore.Utils;
using AutoCore.Utils.Reliability;
using global::Discord;
using global::Discord.Net;
using global::Discord.WebSocket;

/// <summary>
/// Production Discord.Net adapter. Gateway callbacks are isolated (SS-25).
/// </summary>
public sealed class DiscordNetGateway : IDiscordGateway
{
    private readonly DiscordSocketClient _client;
    private readonly bool _ownsClient;
    private CancellationTokenSource? _runCts;
    private Task? _runTask;
    private bool _disposed;

    public DiscordNetGateway()
        : this(new DiscordSocketClient(new DiscordSocketConfig
        {
            GatewayIntents = GatewayIntents.Guilds,
            LogGatewayIntentWarnings = false,
        }), ownsClient: true)
    {
    }

    /// <summary>Test / DI constructor.</summary>
    public DiscordNetGateway(DiscordSocketClient client, bool ownsClient = false)
    {
        _client = client ?? throw new ArgumentNullException(nameof(client));
        _ownsClient = ownsClient;
        _client.Ready += OnReadyAsync;
        _client.SlashCommandExecuted += OnSlashCommandExecutedAsync;
        _client.Log += OnLogAsync;
    }

    public bool IsConnected => _client.ConnectionState == ConnectionState.Connected;

    public event Func<Task>? Ready;
    public event Func<DiscordSlashCommandContext, Task>? SlashCommandReceived;

    public async Task StartAsync(string botToken, CancellationToken cancellationToken = default)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(botToken);

        _runCts = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        await _client.LoginAsync(TokenType.Bot, botToken).ConfigureAwait(false);
        await _client.StartAsync().ConfigureAwait(false);

        // Keep a supervised run task so faults are observed (SS-17).
        _runTask = Task.Delay(Timeout.Infinite, _runCts.Token);
        SafeTask.FireAndForget(_runTask, "DiscordNetGateway run supervisor");
    }

    public async Task StopAsync()
    {
        try
        {
            _runCts?.Cancel();
        }
        catch (ObjectDisposedException)
        {
            // already torn down
        }

        try
        {
            await _client.SetStatusAsync(UserStatus.Invisible).ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Debug, "DiscordNetGateway set invisible on stop", ex);
        }

        try
        {
            await _client.StopAsync().ConfigureAwait(false);
            await _client.LogoutAsync().ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Warning, "DiscordNetGateway stop", ex);
        }
    }

    public Task SetActivityAsync(string text)
        => _client.SetGameAsync(text, type: ActivityType.Watching);

    public void SetActivity(string text)
        => SafeTask.FireAndForget(SetActivityAsync(text), "DiscordNetGateway.SetActivity");

    public async Task RegisterGuildCommandsAsync(ulong guildId, IReadOnlyList<DiscordSlashCommandRegistration> commands)
    {
        var guild = _client.GetGuild(guildId);
        if (guild == null)
        {
            // Guild may not be in cache yet; use REST create via client.
            Logger.WriteLog(LogType.Warning,
                $"Discord guild {guildId} not in cache; registering commands via application command API.");
        }

        var builders = commands.Select(ToBuilder).ToArray();
        try
        {
            await _client.Rest.BulkOverwriteGuildCommands(builders, guildId).ConfigureAwait(false);
            Logger.WriteLog(LogType.Initialize, $"Registered {builders.Length} Discord guild slash command(s).");
        }
        catch (HttpException ex)
        {
            Logger.WriteException(LogType.Error, $"register discord guild commands guild={guildId}", ex);
            throw;
        }
    }

    private static ApplicationCommandProperties ToBuilder(DiscordSlashCommandRegistration reg)
    {
        var builder = new SlashCommandBuilder()
            .WithName(reg.Name)
            .WithDescription(reg.Description);

        foreach (var opt in reg.Options)
        {
            builder.AddOption(
                opt.Name,
                MapOptionType(opt.Type),
                opt.Description,
                isRequired: opt.Required);
        }

        return builder.Build();
    }

    private static ApplicationCommandOptionType MapOptionType(DiscordSlashOptionType type) => type switch
    {
        DiscordSlashOptionType.String => ApplicationCommandOptionType.String,
        _ => ApplicationCommandOptionType.String,
    };

    private Task OnReadyAsync()
    {
        var handlers = Ready;
        if (handlers == null)
            return Task.CompletedTask;

        SafeTask.FireAndForget(InvokeReadyAsync(handlers), "DiscordNetGateway.Ready");
        return Task.CompletedTask;
    }

    private static async Task InvokeReadyAsync(Func<Task> handlers)
    {
        // SS-25: Ready is a boundary — isolate so a subscriber fault cannot kill the gateway.
        try
        {
            await handlers().ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, "DiscordNetGateway.Ready handlers", ex);
        }
    }

    private Task OnSlashCommandExecutedAsync(SocketSlashCommand command)
    {
        // SS-25: each interaction is isolated. Detach so Discord.Net's event loop is not blocked
        // on DB work, and observe the task.
        SafeTask.FireAndForget(HandleSlashAsync(command), $"DiscordNetGateway.Slash user={command.User?.Id}");
        return Task.CompletedTask;
    }

    private async Task HandleSlashAsync(SocketSlashCommand command)
    {
        var handlers = SlashCommandReceived;
        if (handlers == null)
        {
            await SafeRespondAsync(command, "Bot commands are not configured.").ConfigureAwait(false);
            return;
        }

        var options = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
        if (command.Data.Options != null)
        {
            foreach (var opt in command.Data.Options)
            {
                if (opt?.Name == null)
                    continue;
                options[opt.Name] = opt.Value?.ToString() ?? string.Empty;
            }
        }

        var isDm = command.Channel is IDMChannel || command.GuildId == null;

        var context = new DiscordSlashCommandContext
        {
            CommandName = command.Data.Name ?? string.Empty,
            UserId = command.User?.Id ?? 0,
            Username = command.User?.Username,
            IsPrivateMessage = isDm,
            Options = options,
            RespondAsync = async message => await SafeRespondAsync(command, message).ConfigureAwait(false),
        };

        try
        {
            await handlers(context).ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, $"DiscordNetGateway.Slash handler user={context.UserId}", ex);
            await SafeRespondAsync(command, "Something went wrong processing that command. Please try again later.")
                .ConfigureAwait(false);
        }
    }

    private static async Task SafeRespondAsync(SocketSlashCommand command, string message)
    {
        try
        {
            if (command.HasResponded)
                await command.FollowupAsync(message, ephemeral: true).ConfigureAwait(false);
            else
                await command.RespondAsync(message, ephemeral: true).ConfigureAwait(false);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Warning, "DiscordNetGateway.Respond", ex);
        }
    }

    private static Task OnLogAsync(LogMessage message)
    {
        // Never log the bot token. Discord.Net messages are generally safe; map severity.
        var type = message.Severity switch
        {
            LogSeverity.Critical => LogType.Error,
            LogSeverity.Error => LogType.Error,
            LogSeverity.Warning => LogType.Warning,
            _ => LogType.Debug,
        };

        if (message.Exception != null)
            Logger.WriteException(type, $"Discord.Net: {message.Source}", message.Exception);
        else
            Logger.WriteLog(type, $"Discord.Net [{message.Source}]: {message.Message}");

        return Task.CompletedTask;
    }

    public async ValueTask DisposeAsync()
    {
        if (_disposed)
            return;
        _disposed = true;

        await StopAsync().ConfigureAwait(false);

        _client.Ready -= OnReadyAsync;
        _client.SlashCommandExecuted -= OnSlashCommandExecutedAsync;
        _client.Log -= OnLogAsync;

        _runCts?.Dispose();

        if (_ownsClient)
            await _client.DisposeAsync().ConfigureAwait(false);
    }
}
