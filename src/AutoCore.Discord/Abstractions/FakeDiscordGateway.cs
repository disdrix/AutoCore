namespace AutoCore.Discord.Abstractions;

/// <summary>In-memory gateway for unit tests — no network I/O.</summary>
public sealed class FakeDiscordGateway : IDiscordGateway
{
    private readonly List<string> _activities = new();
    private readonly List<DiscordSlashCommandRegistration> _registered = new();

    public bool IsConnected { get; private set; }
    public string? LastToken { get; private set; }
    public ulong LastRegisteredGuildId { get; private set; }
    public IReadOnlyList<string> Activities => _activities;
    public IReadOnlyList<DiscordSlashCommandRegistration> RegisteredCommands => _registered;
    public int StartCount { get; private set; }
    public int StopCount { get; private set; }

    public event Func<Task>? Ready;
    public event Func<DiscordSlashCommandContext, Task>? SlashCommandReceived;

    public Task StartAsync(string botToken, CancellationToken cancellationToken = default)
    {
        // Never store the full token in logs; tests may assert it was received without printing it.
        LastToken = botToken;
        StartCount++;
        IsConnected = true;
        return Task.CompletedTask;
    }

    public Task StopAsync()
    {
        StopCount++;
        IsConnected = false;
        return Task.CompletedTask;
    }

    public Task SetActivityAsync(string text)
    {
        SetActivity(text);
        return Task.CompletedTask;
    }

    public void SetActivity(string text) => _activities.Add(text ?? string.Empty);

    public Task RegisterGuildCommandsAsync(ulong guildId, IReadOnlyList<DiscordSlashCommandRegistration> commands)
    {
        LastRegisteredGuildId = guildId;
        _registered.Clear();
        _registered.AddRange(commands);
        return Task.CompletedTask;
    }

    public Task RaiseReadyAsync() => Ready?.Invoke() ?? Task.CompletedTask;

    public Task RaiseSlashAsync(DiscordSlashCommandContext context)
        => SlashCommandReceived?.Invoke(context) ?? Task.CompletedTask;

    public ValueTask DisposeAsync()
    {
        IsConnected = false;
        return ValueTask.CompletedTask;
    }
}
