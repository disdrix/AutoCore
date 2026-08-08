using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;

[TestClass]
public class AccountServiceTests
{
    private static AuthContext CreateContext(string? name = null)
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>(name);
        var ctx = new AuthContext(options);
        ctx.Database.EnsureCreated();
        return ctx;
    }

    [TestMethod]
    public void TryCreate_ValidInput_CreatesAccountWithHashedPassword()
    {
        using var ctx = CreateContext();

        var result = AccountService.TryCreate(ctx, "user@test.local", "newuser", "hunter2");

        Assert.IsTrue(result.Success, result.Message);
        Assert.IsNotNull(result.Account);
        Assert.AreEqual("newuser", result.Account!.Username);
        Assert.AreEqual("user@test.local", result.Account.Email);
        Assert.IsTrue(result.Account.CheckPassword("hunter2"));
        Assert.IsFalse(result.Account.CheckPassword("wrong"));
        Assert.AreEqual(1, ctx.Accounts.Count());
    }

    [TestMethod]
    public void TryCreate_DuplicateUsername_Fails()
    {
        using var ctx = CreateContext();
        Assert.IsTrue(AccountService.TryCreate(ctx, "a@test.local", "same", "pw1").Success);

        var result = AccountService.TryCreate(ctx, "b@test.local", "same", "pw2");

        Assert.IsFalse(result.Success);
        Assert.AreEqual(AccountCreateError.DuplicateUsernameOrEmail, result.Error);
        Assert.AreEqual(1, ctx.Accounts.Count());
    }

    [TestMethod]
    public void TryCreate_DuplicateEmail_Fails()
    {
        using var ctx = CreateContext();
        Assert.IsTrue(AccountService.TryCreate(ctx, "same@test.local", "user1", "pw1").Success);

        var result = AccountService.TryCreate(ctx, "same@test.local", "user2", "pw2");

        Assert.IsFalse(result.Success);
        Assert.AreEqual(AccountCreateError.DuplicateUsernameOrEmail, result.Error);
    }

    [TestMethod]
    public void TryCreate_InvalidEmail_Fails()
    {
        using var ctx = CreateContext();

        Assert.AreEqual(AccountCreateError.InvalidEmail,
            AccountService.TryCreate(ctx, "not-an-email", "user", "password").Error);
        Assert.AreEqual(AccountCreateError.InvalidEmail,
            AccountService.TryCreate(ctx, "", "user", "password").Error);
        Assert.AreEqual(AccountCreateError.InvalidEmail,
            AccountService.TryCreate(ctx, "@nodomain", "user", "password").Error);
    }

    [TestMethod]
    public void TryCreate_InvalidUsername_Fails()
    {
        using var ctx = CreateContext();
        var opts = new AccountCreateOptions { MinUsernameLength = 3, MaxUsernameLength = 8 };

        Assert.AreEqual(AccountCreateError.InvalidUsername,
            AccountService.TryCreate(ctx, "a@b.c", "ab", "password", opts).Error);
        Assert.AreEqual(AccountCreateError.InvalidUsername,
            AccountService.TryCreate(ctx, "a@b.c", "toolongname", "password", opts).Error);
        Assert.AreEqual(AccountCreateError.InvalidUsername,
            AccountService.TryCreate(ctx, "a@b.c", "   ", "password", opts).Error);
    }

    [TestMethod]
    public void TryCreate_PasswordTooShort_Fails()
    {
        using var ctx = CreateContext();
        var opts = new AccountCreateOptions { MinPasswordLength = 6 };

        var result = AccountService.TryCreate(ctx, "a@b.c", "user", "short", opts);

        Assert.IsFalse(result.Success);
        Assert.AreEqual(AccountCreateError.PasswordTooShort, result.Error);
    }

    [TestMethod]
    public void TryCreate_WithValidatedAndLevel_AppliesOptions()
    {
        using var ctx = CreateContext();
        var opts = new AccountCreateOptions { Validated = true, Level = 5 };

        var result = AccountService.TryCreate(ctx, "a@b.c", "user", "password", opts);

        Assert.IsTrue(result.Success);
        Assert.IsTrue(result.Account!.Validated);
        Assert.AreEqual((byte)5, result.Account.Level);
    }

    [TestMethod]
    public void TryChangePassword_UpdatesHash()
    {
        using var ctx = CreateContext();
        var create = AccountService.TryCreate(ctx, "a@b.c", "user", "oldpass");
        Assert.IsTrue(create.Success);

        var change = AccountService.TryChangePassword(ctx, create.Account!, "newpass");

        Assert.IsTrue(change.Success, change.Message);
        Assert.IsTrue(create.Account!.CheckPassword("newpass"));
        Assert.IsFalse(create.Account.CheckPassword("oldpass"));
    }

    [TestMethod]
    public void TryChangePassword_TooShort_Fails()
    {
        using var ctx = CreateContext();
        var create = AccountService.TryCreate(ctx, "a@b.c", "user", "oldpass");

        var change = AccountService.TryChangePassword(ctx, create.Account!, "x", minPasswordLength: 6);

        Assert.IsFalse(change.Success);
        Assert.AreEqual(AccountPasswordChangeError.PasswordTooShort, change.Error);
        Assert.IsTrue(create.Account!.CheckPassword("oldpass"));
    }

    [TestMethod]
    public void DiscordAccountLink_RoundTrip_PersistsFields()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        using var ctx = new AuthContext(options);
        ctx.Database.EnsureCreated();

        var create = AccountService.TryCreate(ctx, "link@test.local", "linked", "pw");
        Assert.IsTrue(create.Success);

        ctx.DiscordAccountLinks.Add(new DiscordAccountLink
        {
            DiscordUserId = 123456789012345678UL,
            AccountId = create.Account!.Id,
            CreatedAt = new DateTime(2026, 1, 2, 3, 4, 5, DateTimeKind.Utc),
            CreatedByUsername = "discorduser",
        });
        ctx.SaveChanges();

        var link = ctx.DiscordAccountLinks.Single();
        Assert.AreEqual(123456789012345678UL, link.DiscordUserId);
        Assert.AreEqual(create.Account.Id, link.AccountId);
        Assert.AreEqual("discorduser", link.CreatedByUsername);
    }

    [TestMethod]
    public void EnsureCreated_IncludesDiscordAccountLinkEntity()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        AuthContext.EnsureCreated(options);

        using var context = new AuthContext(options);
        Assert.IsNotNull(context.Model.FindEntityType(typeof(DiscordAccountLink)));
        Assert.IsNotNull(context.DiscordAccountLinks);
    }
}
