using AutoCore.Auth.Data;
using AutoCore.Auth.Network;
using AutoCore.Auth.Packets.Client;
using AutoCore.Auth.Packets.Server;
using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;
using AutoCore.Utils;
using AutoCore.Utils.Logging;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using InMemoryLogSink = AutoCore.Auth.Tests.Fakes.InMemoryLogSink;

namespace AutoCore.Auth.Tests.Network;

/// <summary>
/// Phase 2 auth lifecycle events + SS-26 dispatch boundary: auth login success/failure
/// reasons, redirect requests, server-generated auth SessionId, and containment of a
/// throwing handler inside HandlePacket.
/// </summary>
[TestClass]
public class AuthClientLoggingTests
{
    private Func<AuthContext>? _prevClientFactory;
    private Func<AuthContext>? _prevServerFactory;
    private InMemoryLogSink _sink = null!;

    [TestInitialize]
    public void Init()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        _prevClientFactory = AuthClient.CreateAuthContext;
        _prevServerFactory = AuthServer.CreateAuthContext;
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        AuthClient.CreateAuthContext = _prevClientFactory ?? (static () => new AuthContext());
        AuthServer.CreateAuthContext = _prevServerFactory ?? (static () => new AuthContext());
    }

    private static AuthContext CreateInMemory(string name) =>
        new(new DbContextOptionsBuilder<AuthContext>().UseInMemoryDatabase(name).Options);

    private static (AuthServer Server, AuthClient Client) CreateHarness(
        string dbName, uint session1 = 10, uint session2 = 20)
    {
        AuthServer.CreateAuthContext = () => CreateInMemory(dbName);
        AuthClient.CreateAuthContext = () => CreateInMemory(dbName);

        var server = new AuthServer();
        var client = new AuthClient(server, oneTimeKey: 77, sessionId1: session1, sessionId2: session2)
        {
            TestSendHook = _ => { }
        };
        return (server, client);
    }

    private static void SeedAccount(string db, string user, string password, bool locked)
    {
        using var ctx = CreateInMemory(db);
        var salt = Account.CreateSalt();
        ctx.Accounts.Add(new Account
        {
            Username = user,
            Email = $"{user}@test.local",
            Salt = salt,
            Password = Account.Hash(password, salt),
            JoinDate = DateTime.UtcNow,
            Locked = locked,
            Validated = true
        });
        ctx.SaveChanges();
    }

    // ---- SS-26 tripwire ----

    /// <summary>
    /// SS-26 tripwire: <c>AuthClient.HandlePacket</c> is the auth-server dispatch boundary for
    /// client-controlled TCP input. A malformed packet whose handler throws (here: a Logout with
    /// an invalid session while no account is bound, which dereferences <c>Account!</c>) must be
    /// contained by the Guard.Run boundary instead of propagating into the socket receive path
    /// and tearing down the auth server's pump. This test fails if the guard is removed.
    /// </summary>
    [TestMethod]
    public void HandlePacket_ThrowingHandler_IsContainedAtDispatchBoundary()
    {
        var db = Guid.NewGuid().ToString("N");
        var (server, client) = CreateHarness(db, session1: 1, session2: 2);
        try
        {
            // Account is null and the session ids mismatch → MsgLogout's security log
            // dereferences Account! and throws NullReferenceException without the boundary.
            client.HandlePacket(new LogoutPacket { SessionId1 = 999, SessionId2 = 999 });

            Assert.AreEqual(ClientState.Connected, client.State,
                "A contained handler failure must not alter connection state as a side effect.");
            Assert.IsTrue(
                _sink.Records.Any(r => r.EventName == "Legacy" && r.Level == StructuredLogLevel.Error),
                "The contained failure must be reported, not swallowed silently (SS-26).");
        }
        finally
        {
            server.Shutdown();
        }
    }

    // ---- Session identity ----

    [TestMethod]
    public void SessionId_IsServerGenerated_AndUniquePerClient()
    {
        var db = Guid.NewGuid().ToString("N");
        var (server, a) = CreateHarness(db);
        try
        {
            var b = new AuthClient(server, oneTimeKey: 1, sessionId1: 2, sessionId2: 3);

            Assert.AreEqual(16, a.SessionId.Length,
                "Auth SessionId mirrors the TNL format: 16-char GUID prefix.");
            Assert.IsTrue(a.SessionId.All(Uri.IsHexDigit),
                "Auth SessionId must be hex, never derived from client input.");
            Assert.AreNotEqual(a.SessionId, b.SessionId,
                "Each auth client must get its own server-generated identity.");
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void HandlePacket_LegacyLinesInsideDispatch_CarrySessionScope()
    {
        var db = Guid.NewGuid().ToString("N");
        SeedAccount(db, "scoped", "pw", locked: false);
        var (server, client) = CreateHarness(db);
        try
        {
            client.HandlePacket(new LoginPacket { UserName = "scoped", Password = "pw" });

            var loggedIn = _sink.Records.Single(r =>
                r.EventName == "Legacy" && (r.Message?.Contains("logged in") ?? false));
            Assert.AreEqual(client.SessionId, loggedIn.GetProperty("SessionId"),
                "Legacy log lines inside auth dispatch must be attributable to the auth session.");
        }
        finally
        {
            server.Shutdown();
        }
    }

    // ---- Login lifecycle events ----

    [TestMethod]
    public void MsgLogin_UnknownAccount_EmitsAuthLoginFailed_ReasonUnknownAccount()
    {
        var db = Guid.NewGuid().ToString("N");
        var (server, client) = CreateHarness(db);
        try
        {
            client.HandlePacket(new LoginPacket { UserName = "ghost", Password = "x" });

            var record = _sink.Single("AuthLoginFailed");
            Assert.AreEqual(StructuredLogLevel.Warning, record.Level,
                "A failed login is hostile-but-expected input: Warning, not Error.");
            Assert.AreEqual("AUTH-001", record.GetProperty("ErrorCode"),
                "Auth failures carry the stable AUTH-001 code for alerting.");
            Assert.AreEqual("UnknownAccount", record.GetProperty("Reason"),
                "Unknown account and bad password must be distinguishable server-side.");
            Assert.AreEqual("ghost", record.GetProperty("Username"),
                "The claimed username identifies brute-force targets.");
            Assert.IsNull(record.GetProperty("Password"),
                "The password must never be logged.");
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void MsgLogin_BadPassword_EmitsAuthLoginFailed_ReasonBadPassword()
    {
        var db = Guid.NewGuid().ToString("N");
        SeedAccount(db, "bob", "correct", locked: false);
        var (server, client) = CreateHarness(db);
        try
        {
            client.HandlePacket(new LoginPacket { UserName = "bob", Password = "wrong" });

            var record = _sink.Single("AuthLoginFailed");
            Assert.AreEqual("BadPassword", record.GetProperty("Reason"),
                "Bad password on a real account is the brute-force signature ops must see.");
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void MsgLogin_LockedAccount_EmitsAuthLoginFailed_ReasonLocked()
    {
        var db = Guid.NewGuid().ToString("N");
        SeedAccount(db, "jail", "pw", locked: true);
        var (server, client) = CreateHarness(db);
        try
        {
            client.HandlePacket(new LoginPacket { UserName = "jail", Password = "pw" });

            var record = _sink.Single("AuthLoginFailed");
            Assert.AreEqual("Locked", record.GetProperty("Reason"),
                "A locked account attempting login is an admin-actioned signal, not noise.");
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void MsgLogin_Success_EmitsAuthLoginSucceeded_WithoutPassword()
    {
        var db = Guid.NewGuid().ToString("N");
        SeedAccount(db, "alice", "secret", locked: false);
        var (server, client) = CreateHarness(db);
        try
        {
            client.HandlePacket(new LoginPacket { UserName = "alice", Password = "secret" });

            var record = _sink.Single("AuthLoginSucceeded");
            Assert.AreEqual(client.Account!.Id, record.GetProperty("AccountId"),
                "The success event must name the authenticated account.");
            Assert.AreEqual("alice", record.GetProperty("Username"),
                "Username makes the audit trail searchable by name.");
            Assert.AreEqual(client.SessionId, record.GetProperty("SessionId"),
                "The success event binds the account to the server-generated auth session.");
            Assert.IsNull(record.GetProperty("Password"),
                "The password must never be logged.");
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void MsgAboutToPlay_ValidSession_EmitsAuthRedirectRequested()
    {
        var db = Guid.NewGuid().ToString("N");
        var (server, client) = CreateHarness(db, session1: 1, session2: 2);
        try
        {
            client.Account = new Account { Id = 42, Username = "u", Email = "e@e" };
            client.HandlePacket(new AboutToPlayPacket { SessionId1 = 1, SessionId2 = 2, ServerId = 3 });

            var record = _sink.Single("AuthRedirectRequested");
            Assert.AreEqual(42u, record.GetProperty("AccountId"),
                "The redirect must be attributable to the account.");
            Assert.AreEqual((byte)3, record.GetProperty("ServerId"),
                "The redirect must record which game server was requested.");
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void MsgAboutToPlay_InvalidSession_DoesNotEmitRedirectRequested()
    {
        var db = Guid.NewGuid().ToString("N");
        var (server, client) = CreateHarness(db, session1: 1, session2: 2);
        try
        {
            client.Account = new Account { Id = 42, Username = "u", Email = "e@e" };
            client.HandlePacket(new AboutToPlayPacket { SessionId1 = 0, SessionId2 = 0, ServerId = 3 });

            Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "AuthRedirectRequested"),
                "A session-validation failure must not be reported as a redirect request.");
        }
        finally
        {
            server.Shutdown();
        }
    }
}
