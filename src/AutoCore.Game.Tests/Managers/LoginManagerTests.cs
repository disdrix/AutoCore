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
    public void ExpectLoginToGlobal_Success_ThenDuplicateReplacesTicket()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(10, "alice", 0xABCDu));
        Assert.IsTrue(_login.HasPendingLoginForTests(10));

        // Second redirect must replace the pending ticket (kick-older reconnect path),
        // not reject with "already has a pending login entry".
        Assert.IsTrue(_login.ExpectLoginToGlobal(10, "alice", 0xEEEEu));
        Assert.IsTrue(_login.HasPendingLoginForTests(10));

        // Only the replacement key is valid.
        Assert.IsTrue(_login.LoginToGlobal(CreateClient(), new LoginRequestPacket
        {
            Username = "alice",
            UserId = 10,
            AuthKey = 0xEEEEu
        }));
    }

    [TestMethod]
    public void ExpectLoginToGlobal_ReplacedTicket_OldKeyFails()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(11, "alice2", 0x1111u));
        Assert.IsTrue(_login.ExpectLoginToGlobal(11, "alice2", 0x2222u));

        Assert.IsFalse(_login.LoginToGlobal(CreateClient(), new LoginRequestPacket
        {
            Username = "alice2",
            UserId = 11,
            AuthKey = 0x1111u
        }));
        // Key mismatch consumes the pending entry (existing security behavior).
        Assert.IsFalse(_login.HasPendingLoginForTests(11));
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

    [TestMethod]
    public void LoginToGlobal_WhenAccountAlreadyHasSession_DisconnectsOlderConnection()
    {
        var disconnected = new List<(TNLConnection Conn, string Reason)>();
        _login.DisconnectSession = (c, r) => disconnected.Add((c, r));

        Assert.IsTrue(_login.ExpectLoginToGlobal(60, "multi", 1001));
        var older = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(older, new LoginRequestPacket
        {
            Username = "multi",
            UserId = 60,
            AuthKey = 1001
        }));
        Assert.IsTrue(_login.HasActiveSessionForTests(60, older));

        Assert.IsTrue(_login.ExpectLoginToGlobal(60, "multi", 1002));
        var newer = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(newer, new LoginRequestPacket
        {
            Username = "multi",
            UserId = 60,
            AuthKey = 1002
        }));

        Assert.AreEqual(1, disconnected.Count);
        Assert.AreSame(older, disconnected[0].Conn);
        StringAssert.Contains(disconnected[0].Reason.ToLowerInvariant(), "supersed");
        Assert.IsFalse(_login.HasActiveSessionForTests(60, older));
        Assert.IsTrue(_login.HasActiveSessionForTests(60, newer));
        Assert.AreEqual(1, _login.GetActiveSessionCountForTests(60));
    }

    [TestMethod]
    public void LoginToSector_AlongsideGlobal_KeepsBothRegistered()
    {
        // Retail keeps Global + Sector open for one client; sector entry must not kick Global.
        var disconnected = new List<TNLConnection>();
        _login.DisconnectSession = (c, _) => disconnected.Add(c);

        Assert.IsTrue(_login.ExpectLoginToGlobal(61, "both", 2001));
        var global = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(global, new LoginRequestPacket
        {
            Username = "both",
            UserId = 61,
            AuthKey = 2001
        }));

        var sector = CreateClient();
        Assert.IsTrue(_login.LoginToSector(sector, 61));

        Assert.AreEqual(0, disconnected.Count);
        Assert.IsTrue(_login.HasActiveSessionForTests(61, global));
        Assert.IsTrue(_login.HasActiveSessionForTests(61, sector));
        Assert.AreEqual(2, _login.GetActiveSessionCountForTests(61));
    }

    [TestMethod]
    public void LoginToGlobal_WhenAccountHasSectorSession_DisconnectsAllOlder()
    {
        var disconnected = new List<TNLConnection>();
        _login.DisconnectSession = (c, _) => disconnected.Add(c);

        Assert.IsTrue(_login.ExpectLoginToGlobal(63, "world", 4001));
        var global = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(global, new LoginRequestPacket
        {
            Username = "world",
            UserId = 63,
            AuthKey = 4001
        }));
        var sector = CreateClient();
        Assert.IsTrue(_login.LoginToSector(sector, 63));

        Assert.IsTrue(_login.ExpectLoginToGlobal(63, "world", 4002));
        var newer = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(newer, new LoginRequestPacket
        {
            Username = "world",
            UserId = 63,
            AuthKey = 4002
        }));

        Assert.AreEqual(2, disconnected.Count);
        CollectionAssert.Contains(disconnected, global);
        CollectionAssert.Contains(disconnected, sector);
        Assert.IsTrue(_login.HasActiveSessionForTests(63, newer));
        Assert.AreEqual(1, _login.GetActiveSessionCountForTests(63));
    }

    [TestMethod]
    public void UnregisterSession_RemovesActiveSession()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(62, "unreg", 3001));
        var client = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(client, new LoginRequestPacket
        {
            Username = "unreg",
            UserId = 62,
            AuthKey = 3001
        }));
        Assert.IsTrue(_login.HasActiveSessionForTests(62, client));

        _login.UnregisterSession(client);

        Assert.IsFalse(_login.HasActiveSessionForTests(62, client));
        Assert.AreEqual(0, _login.GetActiveSessionCountForTests(62));
    }

    [TestMethod]
    public void LoginToGlobal_DoesNotDisconnectOtherAccounts()
    {
        var disconnected = new List<TNLConnection>();
        _login.DisconnectSession = (c, _) => disconnected.Add(c);

        Assert.IsTrue(_login.ExpectLoginToGlobal(70, "a", 1));
        Assert.IsTrue(_login.ExpectLoginToGlobal(71, "b", 2));
        var a = CreateClient();
        var b = CreateClient();
        Assert.IsTrue(_login.LoginToGlobal(a, new LoginRequestPacket { Username = "a", UserId = 70, AuthKey = 1 }));
        Assert.IsTrue(_login.LoginToGlobal(b, new LoginRequestPacket { Username = "b", UserId = 71, AuthKey = 2 }));

        Assert.AreEqual(0, disconnected.Count);
        Assert.IsTrue(_login.HasActiveSessionForTests(70, a));
        Assert.IsTrue(_login.HasActiveSessionForTests(71, b));
    }

    // Must match LoginManager.SessionTimeoutCheck (private).
    private const int SessionTimeoutCheckMs = 5000;
}
