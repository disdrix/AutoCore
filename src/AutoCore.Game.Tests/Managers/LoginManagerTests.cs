using AutoCore.Database.Char;
using AutoCore.Database.Char.Models;
using AutoCore.Game.Managers;
using AutoCore.Game.Packets.Login;
using AutoCore.Game.TNL;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

[TestClass]
public class LoginManagerTests
{
    private string _dbName = null!;
    private LoginManager _login = null!;

    [TestInitialize]
    public void Init()
    {
        _dbName = "login-mgr-" + Guid.NewGuid().ToString("N");
        _login = LoginManager.Instance;
        _login.ResetForTests();
        _login.CreateContext = CreateContext;
        using var seed = CreateContext();
        seed.Database.EnsureCreated();
    }

    [TestCleanup]
    public void Cleanup()
    {
        _login.ResetForTests();
        TNLConnection.TestPacketSink = null;
    }

    private CharContext CreateContext()
    {
        var options = new DbContextOptionsBuilder<CharContext>()
            .UseInMemoryDatabase(_dbName)
            .Options;
        return new CharContext(options);
    }

    private static TNLConnection CreateClient()
    {
        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);
        connection.SetNetAddress(new System.Net.IPEndPoint(System.Net.IPAddress.Loopback, 0));
        return connection;
    }

    [TestMethod]
    public void ExpectLoginToGlobal_InvalidUsername_ReturnsFalse()
    {
        Assert.IsFalse(_login.ExpectLoginToGlobal(1, null!, 42));
        Assert.IsFalse(_login.ExpectLoginToGlobal(1, "", 42));
        Assert.IsFalse(_login.HasPendingLoginForTests(1));
    }

    [TestMethod]
    public void ExpectLoginToGlobal_ZeroAuthKey_ReturnsFalse()
    {
        Assert.IsFalse(_login.ExpectLoginToGlobal(2, "player", 0));
        Assert.IsFalse(_login.HasPendingLoginForTests(2));
    }

    [TestMethod]
    public void ExpectLoginToGlobal_Success_ThenDuplicateFails()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(10, "alice", 0xABCDu));
        Assert.IsTrue(_login.HasPendingLoginForTests(10));

        Assert.IsFalse(_login.ExpectLoginToGlobal(10, "alice", 0xABCDu));
        Assert.IsTrue(_login.HasPendingLoginForTests(10));
    }

    [TestMethod]
    public void LoginToGlobal_NoPendingEntry_ReturnsFalse()
    {
        var client = CreateClient();
        var packet = new LoginRequestPacket
        {
            Username = "nobody",
            UserId = 99,
            AuthKey = 1
        };

        Assert.IsFalse(_login.LoginToGlobal(client, packet));
        Assert.IsNull(client.Account);
    }

    [TestMethod]
    public void LoginToGlobal_AuthKeyMismatch_ReturnsFalseAndConsumesEntry()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(20, "bob", 111));

        var client = CreateClient();
        var packet = new LoginRequestPacket
        {
            Username = "bob",
            UserId = 20,
            AuthKey = 222
        };

        Assert.IsFalse(_login.LoginToGlobal(client, packet));
        Assert.IsNull(client.Account);
        Assert.IsFalse(_login.HasPendingLoginForTests(20), "Auth mismatch must remove the pending entry.");
    }

    [TestMethod]
    public void LoginToGlobal_UsernameMismatch_ReturnsFalseAndConsumesEntry()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(21, "carol", 333));

        var client = CreateClient();
        var packet = new LoginRequestPacket
        {
            Username = "CAROL",
            UserId = 21,
            AuthKey = 333
        };

        Assert.IsFalse(_login.LoginToGlobal(client, packet));
        Assert.IsFalse(_login.HasPendingLoginForTests(21));
    }

    [TestMethod]
    public void LoginToGlobal_Success_CreatesAccountAndClearsPending()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(30, "dave", 444));

        var client = CreateClient();
        var packet = new LoginRequestPacket
        {
            Username = "dave",
            UserId = 30,
            AuthKey = 444
        };

        Assert.IsTrue(_login.LoginToGlobal(client, packet));
        Assert.IsNotNull(client.Account);
        Assert.AreEqual(30u, client.Account.Id);
        Assert.AreEqual("dave", client.Account.Name);
        Assert.IsFalse(_login.HasPendingLoginForTests(30));

        using var verify = CreateContext();
        Assert.IsTrue(verify.Accounts.Any(a => a.Id == 30 && a.Name == "dave"));
    }

    [TestMethod]
    public void LoginToGlobal_Success_ReusesExistingAccount()
    {
        using (var seed = CreateContext())
        {
            seed.Accounts.Add(new Account
            {
                Id = 31,
                Name = "erin",
                Level = 5
            });
            seed.SaveChanges();
        }

        Assert.IsTrue(_login.ExpectLoginToGlobal(31, "erin", 555));
        var client = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(client, new LoginRequestPacket
        {
            Username = "erin",
            UserId = 31,
            AuthKey = 555
        }));

        Assert.AreEqual((byte)5, client.Account.Level);
        Assert.AreEqual(1, CreateContext().Accounts.Count(a => a.Id == 31));
    }

    [TestMethod]
    public void LoginToGlobal_CannotReuseEntryAfterSuccess()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(32, "frank", 666));
        var client = CreateClient();
        var packet = new LoginRequestPacket
        {
            Username = "frank",
            UserId = 32,
            AuthKey = 666
        };

        Assert.IsTrue(_login.LoginToGlobal(client, packet));
        Assert.IsFalse(_login.LoginToGlobal(CreateClient(), packet));
    }

    [TestMethod]
    public void ExpireTimeout_RemovesPendingLoginSoLoginFails()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(40, "grace", 777));
        Assert.IsTrue(_login.HasPendingLoginForTests(40));

        _login.ExpireAllPendingLoginsForTests();
        _login.Update(SessionTimeoutCheckMs);

        Assert.IsFalse(_login.HasPendingLoginForTests(40));

        var client = CreateClient();
        Assert.IsFalse(_login.LoginToGlobal(client, new LoginRequestPacket
        {
            Username = "grace",
            UserId = 40,
            AuthKey = 777
        }));
    }

    [TestMethod]
    public void LoginToSector_CreatesAccountWhenMissing()
    {
        var client = CreateClient();
        Assert.IsTrue(_login.LoginToSector(client, 50));
        Assert.IsNotNull(client.Account);
        Assert.AreEqual(50u, client.Account.Id);
        Assert.AreEqual((byte)10, client.Account.Level);
        Assert.AreEqual("", client.Account.Name);
    }

    [TestMethod]
    public void LoginToSector_LoadsExistingAccount()
    {
        using (var seed = CreateContext())
        {
            seed.Accounts.Add(new Account
            {
                Id = 51,
                Name = "sector-user",
                Level = 3
            });
            seed.SaveChanges();
        }

        var client = CreateClient();
        Assert.IsTrue(_login.LoginToSector(client, 51));
        Assert.AreEqual("sector-user", client.Account.Name);
        Assert.AreEqual((byte)3, client.Account.Level);
    }

    // Must match LoginManager.SessionTimeoutCheck (private).
    private const int SessionTimeoutCheckMs = 5000;
}
