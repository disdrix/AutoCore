using AutoCore.Database.Auth;
using AutoCore.Discord;
using AutoCore.Discord.Abstractions;
using AutoCore.Discord.Commands;
using AutoCore.Discord.Config;
using AutoCore.Discord.Services;
using Microsoft.EntityFrameworkCore;

namespace AutoCore.Discord.Tests;

[TestClass]
public class DiscordBotServiceTests
{
    private static Func<AuthContext> InMemoryFactory()
    {
        var options = new DbContextOptionsBuilder<AuthContext>()
            .UseInMemoryDatabase(Guid.NewGuid().ToString("N"))
            .Options;
        using (var ctx = new AuthContext(options))
            ctx.Database.EnsureCreated();
        return () => new AuthContext(options);
    }

    [TestMethod]
    public async Task StartAsync_WhenDisabled_SucceedsWithoutConnecting()
    {
        var gateway = new FakeDiscordGateway();
        await using var bot = new DiscordBotService(
            new DiscordConfig { Enabled = false },
            InMemoryFactory(),
            new StaticPlayerCountSource(0),
            gateway);

        Assert.IsTrue(await bot.StartAsync());
        Assert.AreEqual(0, gateway.StartCount);
    }

    [TestMethod]
    public async Task StartAsync_WhenEnabled_ConnectsAndRegistersOnReady()
    {
        var gateway = new FakeDiscordGateway();
        var config = new DiscordConfig
        {
            Enabled = true,
            BotToken = "test-token-value",
            GuildId = 12345,
            PresenceUpdateIntervalSeconds = 60,
            StatusTemplate = "{players} online",
        };

        await using var bot = new DiscordBotService(
            config,
            InMemoryFactory(),
            new StaticPlayerCountSource(3),
            gateway);

        Assert.IsTrue(await bot.StartAsync());
        Assert.AreEqual(1, gateway.StartCount);
        Assert.AreEqual("test-token-value", gateway.LastToken);
        Assert.IsTrue(gateway.IsConnected);

        await gateway.RaiseReadyAsync();

        Assert.AreEqual(12345UL, gateway.LastRegisteredGuildId);
        Assert.AreEqual(2, gateway.RegisteredCommands.Count);
        Assert.IsTrue(gateway.RegisteredCommands.Any(c => c.Name == DiscordAccountCommands.NewAccountCommandName));
        Assert.IsTrue(gateway.Activities.Count >= 1);
        Assert.AreEqual("3 online", gateway.Activities[^1]);
    }

    [TestMethod]
    public async Task StartAsync_WhenConfigInvalid_ReturnsFalse()
    {
        var gateway = new FakeDiscordGateway();
        await using var bot = new DiscordBotService(
            new DiscordConfig { Enabled = true, BotToken = "", GuildId = 0 },
            InMemoryFactory(),
            new StaticPlayerCountSource(0),
            gateway);

        Assert.IsFalse(await bot.StartAsync());
        Assert.AreEqual(0, gateway.StartCount);
    }

    [TestMethod]
    public async Task StopAsync_IsIdempotent()
    {
        var gateway = new FakeDiscordGateway();
        await using var bot = new DiscordBotService(
            new DiscordConfig
            {
                Enabled = true,
                BotToken = "t",
                GuildId = 1,
                PresenceUpdateIntervalSeconds = 60,
            },
            InMemoryFactory(),
            new StaticPlayerCountSource(0),
            gateway);

        Assert.IsTrue(await bot.StartAsync());
        await bot.StopAsync();
        await bot.StopAsync();
        Assert.IsTrue(gateway.StopCount >= 1);
        Assert.IsFalse(bot.IsStarted);
    }

    [TestMethod]
    public async Task SlashCommand_EndToEnd_ThroughGatewayEvent()
    {
        var options = new DbContextOptionsBuilder<AuthContext>()
            .UseInMemoryDatabase(Guid.NewGuid().ToString("N"))
            .Options;
        using (var ctx = new AuthContext(options))
            ctx.Database.EnsureCreated();

        var gateway = new FakeDiscordGateway();
        await using var bot = new DiscordBotService(
            new DiscordConfig
            {
                Enabled = true,
                BotToken = "t",
                GuildId = 1,
                MaxAccountsPerDiscordUser = 1,
                MinPasswordLength = 6,
                MinUsernameLength = 3,
                MaxUsernameLength = 32,
                PresenceUpdateIntervalSeconds = 60,
            },
            () => new AuthContext(options),
            new StaticPlayerCountSource(0),
            gateway);

        Assert.IsTrue(await bot.StartAsync());
        await gateway.RaiseReadyAsync();

        var replies = new List<string>();
        await gateway.RaiseSlashAsync(new DiscordSlashCommandContext
        {
            CommandName = DiscordAccountCommands.NewAccountCommandName,
            UserId = 55,
            Username = "u",
            IsPrivateMessage = true,
            Options = new Dictionary<string, string>
            {
                ["email"] = "e@x.com",
                ["username"] = "gamer",
                ["password"] = "hunter2",
            },
            RespondAsync = msg =>
            {
                replies.Add(msg);
                return Task.CompletedTask;
            },
        });

        Assert.AreEqual(1, replies.Count);
        Assert.IsFalse((replies[0]).Contains("hunter2"), "Expected not to contain: " + ("hunter2").ToString());
        using var verify = new AuthContext(options);
        Assert.AreEqual(1, verify.Accounts.Count(a => a.Username == "gamer"));
    }
}
