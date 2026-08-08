using AutoCore.Database.Auth;
using AutoCore.Discord.Abstractions;
using AutoCore.Discord.Commands;
using AutoCore.Discord.Config;
using AutoCore.Discord.Presence;
using AutoCore.Discord.Services;
using Microsoft.EntityFrameworkCore;

namespace AutoCore.Discord.Tests;

[TestClass]
public class PresenceAndCommandTests
{
    [TestMethod]
    public void FormatStatus_ReplacesPlayersPlaceholder()
    {
        Assert.AreEqual("12 online", PlayerCountPresenceUpdater.FormatStatus("{players} online", 12));
        Assert.AreEqual("Players: 0", PlayerCountPresenceUpdater.FormatStatus("Players: {players}", -5));
        Assert.AreEqual("3 ONLINE", PlayerCountPresenceUpdater.FormatStatus("{PLAYERS} ONLINE", 3));
    }

    [TestMethod]
    public void PresenceUpdater_PushesFormattedActivity()
    {
        var gateway = new FakeDiscordGateway();
        var source = new StaticPlayerCountSource(7);
        var config = new DiscordConfig { StatusTemplate = "{players} pilots online" };
        var updater = new PlayerCountPresenceUpdater(source, gateway, config);

        updater.Update();

        Assert.AreEqual(1, gateway.Activities.Count);
        Assert.AreEqual("7 pilots online", gateway.Activities[0]);
        Assert.AreEqual(7, updater.LastPlayerCount);
    }

    [TestMethod]
    public async Task Commands_NewAccount_WorksInGuildChannel()
    {
        var (factory, commands) = CreateCommands();
        var replies = new List<string>();

        await commands.HandleAsync(new DiscordSlashCommandContext
        {
            CommandName = DiscordAccountCommands.NewAccountCommandName,
            UserId = 1,
            Username = "u",
            IsPrivateMessage = false,
            Options = new Dictionary<string, string>
            {
                ["email"] = "guild@b.c",
                ["username"] = "guildplayer",
                ["password"] = "secret1",
            },
            RespondAsync = msg =>
            {
                replies.Add(msg);
                return Task.CompletedTask;
            },
        });

        Assert.AreEqual(1, replies.Count);
        StringAssert.Contains(replies[0], "guildplayer");
        Assert.IsFalse(replies[0].Contains("secret1"), "Expected not to contain password");
        using var ctx = factory();
        Assert.AreEqual(1, ctx.Accounts.Count());
        Assert.AreEqual("guildplayer", ctx.Accounts.Single().Username);
    }

    [TestMethod]
    public async Task Commands_NewAccount_CreatesInDm()
    {
        var (factory, commands) = CreateCommands();
        var replies = new List<string>();

        await commands.HandleAsync(new DiscordSlashCommandContext
        {
            CommandName = DiscordAccountCommands.NewAccountCommandName,
            UserId = 42,
            Username = "disc",
            IsPrivateMessage = true,
            Options = new Dictionary<string, string>
            {
                ["email"] = "a@b.c",
                ["username"] = "player",
                ["password"] = "secret1",
            },
            RespondAsync = msg =>
            {
                replies.Add(msg);
                return Task.CompletedTask;
            },
        });

        Assert.AreEqual(1, replies.Count);
        StringAssert.Contains(replies[0], "player");
        Assert.IsFalse(replies[0].Contains("secret1"), "Expected not to contain password");
        using var ctx = factory();
        Assert.AreEqual(1, ctx.Accounts.Count());
    }

    [TestMethod]
    public async Task Commands_ChangePassword_LinkedOnly()
    {
        var (factory, commands) = CreateCommands();

        await commands.HandleAsync(MakeNewAccountContext(1, "player", "secret1", _ => Task.CompletedTask));

        var replies = new List<string>();
        await commands.HandleAsync(new DiscordSlashCommandContext
        {
            CommandName = DiscordAccountCommands.ChangePasswordCommandName,
            UserId = 1,
            IsPrivateMessage = true,
            Options = new Dictionary<string, string>
            {
                ["username"] = "player",
                ["new_password"] = "newer99",
            },
            RespondAsync = msg =>
            {
                replies.Add(msg);
                return Task.CompletedTask;
            },
        });

        Assert.IsTrue(replies[0].Contains("updated", StringComparison.OrdinalIgnoreCase)
            || replies[0].Contains("Password", StringComparison.OrdinalIgnoreCase));
        Assert.IsFalse((replies[0]).Contains("newer99"), "Expected not to contain: " + ("newer99").ToString());
        using var ctx = factory();
        Assert.IsTrue(ctx.Accounts.Single().CheckPassword("newer99"));
    }

    /// <summary>
    /// SS-25: a throwing domain path must still produce a user-facing reply and must not
    /// escape the interaction boundary.
    /// </summary>
    [TestMethod]
    public async Task Commands_HandleAsync_WhenDispatchThrows_StillRepliesGenericError()
    {
        // Force a null service path via a sabotaged factory that throws on use.
        Func<AuthContext> badFactory = () => throw new InvalidOperationException("boom");
        var cfg = new DiscordConfig
        {
            Enabled = true,
            BotToken = "t",
            GuildId = 1,
            AllowAccountCreation = true,
            MinPasswordLength = 6,
            MinUsernameLength = 3,
            MaxUsernameLength = 32,
            MaxAccountsPerDiscordUser = 1,
        };
        var commands = new DiscordAccountCommands(new AccountLinkService(badFactory, cfg));
        var replies = new List<string>();

        await commands.HandleAsync(new DiscordSlashCommandContext
        {
            CommandName = DiscordAccountCommands.NewAccountCommandName,
            UserId = 1,
            IsPrivateMessage = true,
            Options = new Dictionary<string, string>
            {
                ["email"] = "a@b.c",
                ["username"] = "player",
                ["password"] = "secret1",
            },
            RespondAsync = msg =>
            {
                replies.Add(msg);
                return Task.CompletedTask;
            },
        });

        Assert.AreEqual(1, replies.Count);
        // AccountLinkService catches and returns a message; either way user gets a reply.
        Assert.IsFalse(string.IsNullOrWhiteSpace(replies[0]));
        Assert.IsFalse((replies[0]).Contains("secret1"), "Expected not to contain: " + ("secret1").ToString());
    }

    [TestMethod]
    public void BuildRegistrations_IncludesBothCommands()
    {
        var regs = DiscordAccountCommands.BuildRegistrations();
        Assert.AreEqual(2, regs.Count);
        Assert.IsTrue(regs.Any(r => r.Name == DiscordAccountCommands.NewAccountCommandName));
        Assert.IsTrue(regs.Any(r => r.Name == DiscordAccountCommands.ChangePasswordCommandName));
    }

    private static (Func<AuthContext> factory, DiscordAccountCommands commands) CreateCommands()
    {
        var dbName = Guid.NewGuid().ToString("N");
        var options = new DbContextOptionsBuilder<AuthContext>()
            .UseInMemoryDatabase(dbName)
            .Options;
        using (var ctx = new AuthContext(options))
            ctx.Database.EnsureCreated();

        Func<AuthContext> factory = () => new AuthContext(options);
        var cfg = new DiscordConfig
        {
            Enabled = true,
            BotToken = "t",
            GuildId = 1,
            AllowAccountCreation = true,
            MinPasswordLength = 6,
            MinUsernameLength = 3,
            MaxUsernameLength = 32,
            MaxAccountsPerDiscordUser = 1,
        };
        return (factory, new DiscordAccountCommands(new AccountLinkService(factory, cfg)));
    }

    private static DiscordSlashCommandContext MakeNewAccountContext(
        ulong userId,
        string username,
        string password,
        Func<string, Task> respond) => new()
    {
        CommandName = DiscordAccountCommands.NewAccountCommandName,
        UserId = userId,
        IsPrivateMessage = true,
        Options = new Dictionary<string, string>
        {
            ["email"] = $"{username}@test.local",
            ["username"] = username,
            ["password"] = password,
        },
        RespondAsync = respond,
    };
}
