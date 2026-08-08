using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;
using AutoCore.Discord.Config;
using AutoCore.Discord.Services;
using Microsoft.EntityFrameworkCore;

namespace AutoCore.Discord.Tests;

[TestClass]
public class AccountLinkServiceTests
{
    private static (Func<AuthContext> factory, string dbName) CreateFactory()
    {
        var dbName = Guid.NewGuid().ToString("N");
        var options = new DbContextOptionsBuilder<AuthContext>()
            .UseInMemoryDatabase(dbName)
            .Options;

        using (var ctx = new AuthContext(options))
            ctx.Database.EnsureCreated();

        return (() => new AuthContext(options), dbName);
    }

    private static DiscordConfig DefaultConfig(int maxAccounts = 1) => new()
    {
        Enabled = true,
        BotToken = "x",
        GuildId = 1,
        MaxAccountsPerDiscordUser = maxAccounts,
        MinPasswordLength = 6,
        MinUsernameLength = 3,
        MaxUsernameLength = 32,
        AllowAccountCreation = true,
    };

    [TestMethod]
    public void CreateAccount_Success_LinksDiscordUser()
    {
        var (factory, _) = CreateFactory();
        var svc = new AccountLinkService(factory, DefaultConfig());

        var result = svc.CreateAccount(99, "discuser", "a@b.c", "player1", "secret1");

        Assert.IsTrue(result.Success, result.Message);
        Assert.AreEqual("player1", result.Username);
        Assert.IsFalse((result.Message).Contains("secret1"), "Expected not to contain: " + ("secret1").ToString());

        using var ctx = factory();
        Assert.AreEqual(1, ctx.Accounts.Count());
        Assert.AreEqual(1, ctx.DiscordAccountLinks.Count());
        var link = ctx.DiscordAccountLinks.Single();
        Assert.AreEqual(99UL, link.DiscordUserId);
        Assert.AreEqual("discuser", link.CreatedByUsername);
        Assert.IsTrue(ctx.Accounts.Single().CheckPassword("secret1"));
        Assert.IsTrue(ctx.Accounts.Single().Validated);
    }

    [TestMethod]
    public void CreateAccount_QuotaExceeded_DefaultMaxOne()
    {
        var (factory, _) = CreateFactory();
        var svc = new AccountLinkService(factory, DefaultConfig(maxAccounts: 1));

        Assert.IsTrue(svc.CreateAccount(1, "u", "a@b.c", "one", "secret1").Success);
        var second = svc.CreateAccount(1, "u", "b@b.c", "two", "secret1");

        Assert.IsFalse(second.Success);
        Assert.AreEqual(AccountLinkCreateError.QuotaExceeded, second.Error);
        using var ctx = factory();
        Assert.AreEqual(1, ctx.Accounts.Count());
    }

    [TestMethod]
    public void CreateAccount_AllowsConfiguredQuota()
    {
        var (factory, _) = CreateFactory();
        var svc = new AccountLinkService(factory, DefaultConfig(maxAccounts: 2));

        Assert.IsTrue(svc.CreateAccount(1, "u", "a@b.c", "one", "secret1").Success);
        Assert.IsTrue(svc.CreateAccount(1, "u", "b@b.c", "two", "secret1").Success);
        var third = svc.CreateAccount(1, "u", "c@b.c", "three", "secret1");
        Assert.AreEqual(AccountLinkCreateError.QuotaExceeded, third.Error);
    }

    [TestMethod]
    public void CreateAccount_DuplicateUsername_Fails()
    {
        var (factory, _) = CreateFactory();
        var svc = new AccountLinkService(factory, DefaultConfig(maxAccounts: 5));

        Assert.IsTrue(svc.CreateAccount(1, "u", "a@b.c", "same", "secret1").Success);
        var dup = svc.CreateAccount(2, "u2", "b@b.c", "same", "secret1");
        Assert.AreEqual(AccountLinkCreateError.DuplicateUsernameOrEmail, dup.Error);
    }

    [TestMethod]
    public void CreateAccount_WhenDisabled_Fails()
    {
        var (factory, _) = CreateFactory();
        var cfg = DefaultConfig();
        cfg.AllowAccountCreation = false;
        var svc = new AccountLinkService(factory, cfg);

        var result = svc.CreateAccount(1, "u", "a@b.c", "user", "secret1");
        Assert.AreEqual(AccountLinkCreateError.CreationDisabled, result.Error);
    }

    [TestMethod]
    public void ChangePassword_WhenLinked_Succeeds()
    {
        var (factory, _) = CreateFactory();
        var svc = new AccountLinkService(factory, DefaultConfig());
        Assert.IsTrue(svc.CreateAccount(7, "u", "a@b.c", "player", "oldpass1").Success);

        var change = svc.ChangePassword(7, "player", "newpass1");

        Assert.IsTrue(change.Success, change.Message);
        Assert.IsFalse((change.Message).Contains("newpass1"), "Expected not to contain: " + ("newpass1").ToString());
        using var ctx = factory();
        Assert.IsTrue(ctx.Accounts.Single().CheckPassword("newpass1"));
    }

    [TestMethod]
    public void ChangePassword_WhenNotLinked_Fails()
    {
        var (factory, _) = CreateFactory();
        var svc = new AccountLinkService(factory, DefaultConfig(maxAccounts: 5));
        Assert.IsTrue(svc.CreateAccount(1, "u", "a@b.c", "player", "oldpass1").Success);

        // Different Discord user tries to change the password.
        var change = svc.ChangePassword(999, "player", "newpass1");

        Assert.IsFalse(change.Success);
        Assert.AreEqual(AccountLinkPasswordError.NotLinked, change.Error);
        using var ctx = factory();
        Assert.IsTrue(ctx.Accounts.Single().CheckPassword("oldpass1"));
    }

    [TestMethod]
    public void ChangePassword_UnknownUser_Fails()
    {
        var (factory, _) = CreateFactory();
        var svc = new AccountLinkService(factory, DefaultConfig());

        var change = svc.ChangePassword(1, "nope", "newpass1");
        Assert.AreEqual(AccountLinkPasswordError.AccountNotFound, change.Error);
    }

    [TestMethod]
    public void ChangePassword_UnlinkedConsoleAccount_CannotBeChanged()
    {
        var (factory, _) = CreateFactory();
        using (var ctx = factory())
        {
            var salt = Account.CreateSalt();
            ctx.Accounts.Add(new Account
            {
                Email = "console@test.local",
                Username = "console",
                Password = Account.Hash("oldpass1", salt),
                Salt = salt,
                JoinDate = DateTime.UtcNow,
            });
            ctx.SaveChanges();
        }

        var svc = new AccountLinkService(factory, DefaultConfig());
        var change = svc.ChangePassword(1, "console", "newpass1");
        Assert.AreEqual(AccountLinkPasswordError.NotLinked, change.Error);
    }
}
