namespace AutoCore.Discord.Abstractions;

/// <summary>
/// Test seam over Discord.Net. Production uses <see cref="DiscordNetGateway"/>.
/// </summary>
public interface IDiscordGateway : IAsyncDisposable
{
    bool IsConnected { get; }

    /// <summary>Raised when the gateway is ready to accept work (commands registered).</summary>
    event Func<Task>? Ready;

    /// <summary>
    /// Raised for slash-command interactions. Implementations must isolate handler failures
    /// (SS-25) so a single bad interaction cannot tear down the gateway task.
    /// </summary>
    event Func<DiscordSlashCommandContext, Task>? SlashCommandReceived;

    Task StartAsync(string botToken, CancellationToken cancellationToken = default);

    Task StopAsync();

    Task SetActivityAsync(string text);

    /// <summary>Synchronous convenience used by the presence timer.</summary>
    void SetActivity(string text);

    Task RegisterGuildCommandsAsync(ulong guildId, IReadOnlyList<DiscordSlashCommandRegistration> commands);
}

public sealed class DiscordSlashCommandRegistration
{
    public required string Name { get; init; }
    public required string Description { get; init; }
    public IReadOnlyList<DiscordSlashCommandOption> Options { get; init; } = Array.Empty<DiscordSlashCommandOption>();
}

public sealed class DiscordSlashCommandOption
{
    public required string Name { get; init; }
    public required string Description { get; init; }
    public DiscordSlashOptionType Type { get; init; } = DiscordSlashOptionType.String;
    public bool Required { get; init; } = true;
}

public enum DiscordSlashOptionType
{
    String = 3,
}

public sealed class DiscordSlashCommandContext
{
    public required string CommandName { get; init; }
    public required ulong UserId { get; init; }
    public string? Username { get; init; }
    public bool IsPrivateMessage { get; init; }
    public IReadOnlyDictionary<string, string> Options { get; init; }
        = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);

    /// <summary>Replies to the interaction. Must not throw out of the gateway boundary.</summary>
    public required Func<string, Task> RespondAsync { get; init; }

    public string? GetOption(string name)
        => Options.TryGetValue(name, out var value) ? value : null;
}
