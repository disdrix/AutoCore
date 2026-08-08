using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.Char;
using AutoCore.Game.Managers;
using AutoCore.Game.Packets.Login;
using AutoCore.Game.TNL;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Utils;
using AutoCore.Utils.Logging;
using Microsoft.EntityFrameworkCore;

/// <summary>
/// Phase 2 login-ticket lifecycle events: issue, redeem (success + specific rejection
/// reasons), and expiry. The AuthKey/OneTimeKey value must never be logged.
/// </summary>
[TestClass]
public class LoginManagerLoggingTests
{
    private string _dbName;
    private LoginManager _login;
    private InMemoryLogSink _sink;

    [TestInitialize]
    public void Init()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);

        _dbName = "login-log-" + Guid.NewGuid().ToString("N");
        _login = LoginManager.Instance;
        _login.ResetForTests();
        _login.CreateContext = CreateContext;
        using var seed = CreateContext();
        seed.Database.EnsureCreated();
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        _login.ResetForTests();
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
        connection.SetGhostFrom(false);
        connection.SetGhostTo(false);
        connection.SetNetAddress(new System.Net.IPEndPoint(System.Net.IPAddress.Loopback, 0));
        return connection;
    }

    [TestMethod]
    public void ExpectLoginToGlobal_EmitsLoginTicketIssued_WithoutAuthKey()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(5, "user5", 12345));

        var record = _sink.Single("LoginTicketIssued");
        Assert.AreEqual(5u, record.GetProperty("AccountId"),
            "The ticket must be attributable to the account it was issued for.");
        Assert.AreEqual("user5", record.GetProperty("Username"),
            "Username lets ops search by name without an id join.");
        Assert.IsNull(record.GetProperty("AuthKey"),
            "The one-time auth key is a credential and must never be logged.");
    }

    [TestMethod]
    public void LoginToGlobal_Success_EmitsGlobalLoginSucceeded_WithSessionId()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(6, "user6", 42));
        var client = CreateClient();

        Assert.IsTrue(_login.LoginToGlobal(client, new LoginRequestPacket
        {
            UserId = 6,
            Username = "user6",
            AuthKey = 42
        }));

        var record = _sink.Single("GlobalLoginSucceeded");
        Assert.AreEqual(6u, record.GetProperty("AccountId"),
            "The success event must name the authenticated account.");
        Assert.AreEqual(client.SessionId, record.GetProperty("SessionId"),
            "The success event must bind the account to the server-generated session.");
    }

    [TestMethod]
    public void LoginToGlobal_NoTicket_EmitsGlobalLoginRejected_ReasonNoTicket()
    {
        var client = CreateClient();

        Assert.IsFalse(_login.LoginToGlobal(client, new LoginRequestPacket
        {
            UserId = 7,
            Username = "user7",
            AuthKey = 1
        }));

        var record = _sink.Single("GlobalLoginRejected");
        Assert.AreEqual(StructuredLogLevel.Warning, record.Level,
            "A rejected login is suspicious-but-expected input: Warning, not Error.");
        Assert.AreEqual("AUTH-002", record.GetProperty("ErrorCode"),
            "Rejections carry the stable AUTH-002 code for alerting.");
        Assert.AreEqual("NoTicket", record.GetProperty("Reason"),
            "The specific rejection reason distinguishes replay from expiry from mismatch.");
        Assert.AreEqual(7u, record.GetProperty("AccountId"),
            "The rejection must name the claimed account.");
    }

    [TestMethod]
    public void LoginToGlobal_KeyMismatch_EmitsReasonKeyMismatch_WithoutKeys()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(8, "user8", 111));
        var client = CreateClient();

        Assert.IsFalse(_login.LoginToGlobal(client, new LoginRequestPacket
        {
            UserId = 8,
            Username = "user8",
            AuthKey = 222
        }));

        var record = _sink.Single("GlobalLoginRejected");
        Assert.AreEqual("KeyMismatch", record.GetProperty("Reason"),
            "A wrong auth key is the signature of a replay/forgery attempt.");
        Assert.IsNull(record.GetProperty("AuthKey"),
            "Neither the expected nor the presented key may be logged.");
    }

    [TestMethod]
    public void LoginToGlobal_UserMismatch_EmitsReasonUserMismatch()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(9, "user9", 5));
        var client = CreateClient();

        Assert.IsFalse(_login.LoginToGlobal(client, new LoginRequestPacket
        {
            UserId = 9,
            Username = "somebody-else",
            AuthKey = 5
        }));

        var record = _sink.Single("GlobalLoginRejected");
        Assert.AreEqual("UserMismatch", record.GetProperty("Reason"),
            "A username/account-id mismatch is a distinct forgery signature from a bad key.");
    }

    [TestMethod]
    public void ExpirySweep_EmitsLoginTicketExpired_PerExpiredEntry()
    {
        Assert.IsTrue(_login.ExpectLoginToGlobal(10, "user10", 3));
        _login.ExpireAllPendingLoginsForTests();
        _sink.Clear();

        _login.Update(10_000); // > SessionTimeoutCheck (5000ms) so the sweep timer fires.

        var record = _sink.Single("LoginTicketExpired");
        Assert.AreEqual(10u, record.GetProperty("AccountId"),
            "An expired ticket explains a later NoTicket rejection for the same account.");
        Assert.IsFalse(_login.HasPendingLoginForTests(10),
            "The sweep must still remove the expired entry (SS-23 semantics unchanged).");
    }
}
