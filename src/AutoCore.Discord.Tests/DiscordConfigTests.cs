using AutoCore.Discord.Config;

namespace AutoCore.Discord.Tests;

[TestClass]
public class DiscordConfigTests
{
    [TestMethod]
    public void Validate_WhenDisabled_SucceedsEvenWithoutToken()
    {
        var config = new DiscordConfig { Enabled = false, BotToken = "", GuildId = 0 };
        var result = config.Validate();
        Assert.IsTrue(result.IsValid);
    }

    [TestMethod]
    public void Validate_WhenEnabledWithoutToken_Fails()
    {
        var config = new DiscordConfig { Enabled = true, BotToken = "  ", GuildId = 1 };
        var result = config.Validate();
        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "BotToken");
        Assert.IsFalse((result.FormatErrors()).Contains("discord.com"), "Expected not to contain: " + ("discord.com").ToString());
    }

    [TestMethod]
    public void Validate_WhenEnabledWithoutGuild_Fails()
    {
        var config = new DiscordConfig { Enabled = true, BotToken = "token", GuildId = 0 };
        var result = config.Validate();
        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "GuildId");
    }

    [TestMethod]
    public void Validate_WhenEnabledWithValidValues_Succeeds()
    {
        var config = new DiscordConfig
        {
            Enabled = true,
            BotToken = "test-token",
            GuildId = 42,
            MaxAccountsPerDiscordUser = 1,
            PresenceUpdateIntervalSeconds = 60,
        };
        Assert.IsTrue(config.Validate().IsValid);
    }

    [TestMethod]
    public void Defaults_MatchPlan()
    {
        var config = new DiscordConfig();
        Assert.IsFalse(config.Enabled);
        Assert.AreEqual(1, config.MaxAccountsPerDiscordUser);
        Assert.AreEqual(60, config.PresenceUpdateIntervalSeconds);
        Assert.AreEqual("{players} online", config.StatusTemplate);
        Assert.IsTrue(config.AllowAccountCreation);
        Assert.AreEqual(6, config.MinPasswordLength);
        Assert.AreEqual(3, config.MinUsernameLength);
        Assert.AreEqual(32, config.MaxUsernameLength);
        Assert.AreEqual(0UL, config.BugReportChannelId);
    }

    [TestMethod]
    public void Validate_RejectsInvalidBounds()
    {
        var config = new DiscordConfig
        {
            Enabled = true,
            BotToken = "t",
            GuildId = 1,
            MaxAccountsPerDiscordUser = 0,
            PresenceUpdateIntervalSeconds = 5,
            StatusTemplate = "",
        };
        var result = config.Validate();
        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "MaxAccountsPerDiscordUser");
        StringAssert.Contains(result.FormatErrors(), "PresenceUpdateIntervalSeconds");
        StringAssert.Contains(result.FormatErrors(), "StatusTemplate");
    }
}
