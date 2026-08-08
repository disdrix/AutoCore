using System.ComponentModel.DataAnnotations.Schema;
using System.Reflection;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;

[TestClass]
public class AuthContextModelTests
{
    private static AuthContext CreateContext()
        => new(TestHelpers.CreateInMemoryOptions<AuthContext>());

    [TestMethod]
    public void EnsureCreated_CreatesSchema()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        AuthContext.EnsureCreated(options);

        using var context = new AuthContext(options);
        Assert.IsTrue(context.Database.CanConnect());
        Assert.IsNotNull(context.Model.FindEntityType(typeof(Account)));
        Assert.IsNotNull(context.Model.FindEntityType(typeof(GlobalServer)));
    }

    [TestCleanup]
    public void ResetSeedPassword() => AuthContext.DefaultAdminPassword = null;

    /// <summary>
    /// SS-20: the seed used to create admin/admin at Level 255, validated and unlocked, on any
    /// empty database — a live default administrator credential on a network-reachable auth
    /// server. With no password explicitly configured, nothing may be seeded.
    /// </summary>
    [TestMethod]
    public void EnsureCreated_WithNoConfiguredPassword_SeedsNoAccount()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        AuthContext.DefaultAdminPassword = null;

        AuthContext.EnsureCreated(options);

        using var context = new AuthContext(options);
        Assert.AreEqual(
            0,
            context.Accounts.Count(),
            "SS-20: no account may be created unless the operator supplied a password. " +
            "A built-in default credential is not acceptable on a reachable server.");
    }

    /// <summary>
    /// SS-20: a blank or whitespace password must be treated as "not configured", never as a
    /// valid credential.
    /// </summary>
    [TestMethod]
    public void EnsureCreated_WithBlankConfiguredPassword_SeedsNoAccount()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        AuthContext.DefaultAdminPassword = "   ";

        AuthContext.EnsureCreated(options);

        using var context = new AuthContext(options);
        Assert.AreEqual(0, context.Accounts.Count());
    }

    /// <summary>
    /// SS-20: when the operator explicitly supplies a password, the admin account is seeded
    /// with THAT password — never a built-in one.
    /// </summary>
    [TestMethod]
    public void EnsureCreated_WithConfiguredPassword_SeedsAdminUsingIt()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        AuthContext.DefaultAdminPassword = "operator-chosen-secret";

        AuthContext.EnsureCreated(options);

        using var context = new AuthContext(options);
        var admin = context.Accounts.SingleOrDefault(a => a.Username == "admin");
        Assert.IsNotNull(admin);
        Assert.AreEqual("admin@autocore.local", admin!.Email);
        Assert.AreEqual((byte)255, admin.Level);
        Assert.IsTrue(admin.Validated);
        Assert.IsFalse(admin.Locked);
        Assert.IsTrue(admin.CheckPassword("operator-chosen-secret"));
        Assert.IsFalse(
            admin.CheckPassword("admin"),
            "SS-20: the old built-in password must not work.");
        Assert.IsFalse(string.IsNullOrEmpty(admin.Salt));
        Assert.IsFalse(string.IsNullOrEmpty(admin.Password));
    }

    [TestMethod]
    public void EnsureCreated_DoesNotDuplicateDefaultAccount()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        AuthContext.DefaultAdminPassword = "operator-chosen-secret";

        AuthContext.EnsureCreated(options);
        AuthContext.EnsureCreated(options);

        using var context = new AuthContext(options);
        Assert.AreEqual(1, context.Accounts.Count());
    }

    [TestMethod]
    public void Account_PrimaryKey_IsId()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        var entity = context.Model.FindEntityType(typeof(Account));
        Assert.IsNotNull(entity);
        var key = entity!.FindPrimaryKey();
        Assert.IsNotNull(key);
        Assert.AreEqual(1, key!.Properties.Count);
        Assert.AreEqual(nameof(Account.Id), key.Properties[0].Name);
        Assert.AreEqual("account", typeof(Account).GetCustomAttribute<TableAttribute>()!.Name);
    }

    [TestMethod]
    public void GlobalServer_PrimaryKey_IsId()
    {
        using var context = CreateContext();
        context.Database.EnsureCreated();

        var entity = context.Model.FindEntityType(typeof(GlobalServer));
        Assert.IsNotNull(entity);
        var key = entity!.FindPrimaryKey();
        Assert.IsNotNull(key);
        Assert.AreEqual(nameof(GlobalServer.Id), key!.Properties[0].Name);
        Assert.AreEqual("global_server", typeof(GlobalServer).GetCustomAttribute<TableAttribute>()!.Name);
    }

    [TestMethod]
    public void Account_RoundTrip_PersistsAllFields()
    {
        var dbName = Guid.NewGuid().ToString();
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>(dbName);

        using (var context = new AuthContext(options))
        {
            context.Database.EnsureCreated();
            var salt = Account.CreateSalt();
            context.Accounts.Add(new Account
            {
                Email = "user@test.local",
                Username = "tester",
                Salt = salt,
                Password = Account.Hash("secret", salt),
                Level = 10,
                LastIP = "127.0.0.1",
                LastServerId = 2,
                LastLogin = new DateTime(2024, 1, 2, 3, 4, 5, DateTimeKind.Utc),
                JoinDate = new DateTime(2023, 6, 7, 8, 9, 10, DateTimeKind.Utc),
                Locked = true,
                Validated = false,
                ValidationToken = "tok-123",
            });
            context.SaveChanges();
        }

        using (var context = new AuthContext(options))
        {
            var account = context.Accounts.Single(a => a.Username == "tester");
            Assert.AreEqual("user@test.local", account.Email);
            Assert.AreEqual((byte)10, account.Level);
            Assert.AreEqual("127.0.0.1", account.LastIP);
            Assert.AreEqual((byte)2, account.LastServerId);
            Assert.IsTrue(account.Locked);
            Assert.IsFalse(account.Validated);
            Assert.AreEqual("tok-123", account.ValidationToken);
            Assert.IsTrue(account.CheckPassword("secret"));
            Assert.IsFalse(account.CheckPassword("wrong"));
        }
    }

    [TestMethod]
    public void GlobalServer_RoundTrip_PersistsFields()
    {
        var options = TestHelpers.CreateInMemoryOptions<AuthContext>();
        using var context = new AuthContext(options);
        context.Database.EnsureCreated();

        context.GlobalServers.Add(new GlobalServer
        {
            Id = 1,
            Password = "gs-pass",
            Enabled = true,
        });
        context.SaveChanges();

        var loaded = context.GlobalServers.Single(g => g.Id == 1);
        Assert.AreEqual("gs-pass", loaded.Password);
        Assert.IsTrue(loaded.Enabled);
    }

    [TestMethod]
    public void Account_Hash_IsDeterministicAndSalted()
    {
        var hash1 = Account.Hash("password", "salt-a");
        var hash2 = Account.Hash("password", "salt-a");
        var hash3 = Account.Hash("password", "salt-b");
        var hash4 = Account.Hash("other", "salt-a");

        Assert.AreEqual(hash1, hash2);
        Assert.AreNotEqual(hash1, hash3);
        Assert.AreNotEqual(hash1, hash4);
        Assert.AreEqual(64, hash1.Length); // SHA-256 hex
        Assert.IsTrue(hash1.All(c => char.IsDigit(c) || (c >= 'a' && c <= 'f')));
    }

    [TestMethod]
    public void Account_CreateSalt_ReturnsUniqueHexStrings()
    {
        var a = Account.CreateSalt();
        var b = Account.CreateSalt();

        Assert.AreEqual(40, a.Length); // 20 bytes → 40 hex chars
        Assert.AreEqual(40, b.Length);
        Assert.AreNotEqual(a, b);
        Assert.IsTrue(a.All(c => char.IsDigit(c) || (c >= 'a' && c <= 'f')));
    }

    [TestMethod]
    public void OptionsConstructor_SkipsMySqlOnConfiguring()
    {
        // Must not throw or attempt MySQL AutoDetect when options already configure the provider.
        using var context = CreateContext();
        Assert.IsTrue(context.Database.IsInMemory());
        context.Database.EnsureCreated();
    }

    [TestMethod]
    public void OptionsConstructor_ExposesDbSets()
    {
        using var context = CreateContext();
        Assert.IsNotNull(context.Accounts);
        Assert.IsNotNull(context.GlobalServers);
    }
}
