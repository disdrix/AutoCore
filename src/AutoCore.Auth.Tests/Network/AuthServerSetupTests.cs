using System.Net;
using AutoCore.Auth.Config;
using AutoCore.Auth.Data;
using AutoCore.Auth.Network;
using AutoCore.Auth.Packets.Server;
using AutoCore.Communicator.Packets;
using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;
using AutoCore.Utils.Packets;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Comm = AutoCore.Communicator.Communicator;
using CommType = AutoCore.Communicator.CommunicatorType;
using ServerData = AutoCore.Communicator.ServerData;
using ServerInfo = AutoCore.Communicator.ServerInfo;

namespace AutoCore.Auth.Tests.Network;

[TestClass]
public class AuthServerSetupTests
{
    private Func<AuthContext>? _previousFactory;

    [TestInitialize]
    public void Init()
    {
        _previousFactory = AuthServer.CreateAuthContext;
    }

    [TestCleanup]
    public void Cleanup()
    {
        AuthServer.CreateAuthContext = _previousFactory ?? (static () => new AuthContext());
    }

    private static AuthContext CreateInMemoryContext(string dbName)
    {
        var options = new DbContextOptionsBuilder<AuthContext>()
            .UseInMemoryDatabase(dbName)
            .Options;
        return new AuthContext(options);
    }

    [TestMethod]
    public void Setup_NullConfig_KeepsExistingConfig()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.Config.AuthSocketPort = 9999;
        server.Instance.Setup(null);
        Assert.AreEqual(9999, server.Instance.Config.AuthSocketPort);
    }

    [TestMethod]
    public void Setup_AppliesConfig_AndSeedsDefaultServerSlot()
    {
        var dbName = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(dbName);

        using var server = new DisposableAuthServer();
        var config = new AuthConfig { AuthSocketPort = 2106, CommunicatorPort = 2107 };
        server.Instance.Setup(config);

        Assert.AreEqual(2106, server.Instance.Config.AuthSocketPort);
        Assert.AreEqual(2107, server.Instance.Config.CommunicatorPort);
        Assert.IsTrue(server.Instance.Servers.ContainsKey(1));
        Assert.AreEqual("test", server.Instance.Servers[1].Password);
    }

    [TestMethod]
    public void Setup_UpdatesPasswordForExistingServerSlot()
    {
        var dbName = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(dbName);

        using (var ctx = CreateInMemoryContext(dbName))
        {
            ctx.GlobalServers.Add(new GlobalServer { Id = 5, Password = "old", Enabled = true });
            ctx.SaveChanges();
        }

        using var server = new DisposableAuthServer();
        server.Instance.Servers[5] = new ServerInfo { ServerId = 5, Password = "old" };
        server.Instance.Setup(new AuthConfig());

        // After seed path with existing row, password should match DB
        using (var ctx = CreateInMemoryContext(dbName))
        {
            var row = ctx.GlobalServers.Single(s => s.Id == 5);
            row.Password = "newpw";
            ctx.SaveChanges();
        }

        server.Instance.SetupServerList();
        Assert.AreEqual("newpw", server.Instance.Servers[5].Password);
    }

    [TestMethod]
    public void Start_InvalidConfig_ReturnsFalseWithoutBinding()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.Setup(new AuthConfig { AuthSocketPort = 0, CommunicatorPort = 0 });
        Assert.IsFalse(server.Instance.Start());
        Assert.IsFalse(server.Instance.IsRunning);
    }

    [TestMethod]
    public void Disconnect_QueuesClientForRemoval_AndMainLoopRemovesIt()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        var client = new AuthClient(server.Instance, 1, 2, 3);
        server.Instance.Clients.Add(client);

        server.Instance.Disconnect(client);
        server.Instance.MainLoop(0);

        Assert.AreEqual(0, server.Instance.Clients.Count);
    }

    [TestMethod]
    public void MainLoop_EmptyClients_IsNoOp()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.MainLoop(16);
    }

    [TestMethod]
    public void AuthenticateGameServer_ValidPassword_SetsAddressAndReturnsTrue()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.Servers[1] = new ServerInfo { ServerId = 1, Password = "secret" };

        var comm = new Comm(CommType.Client);
        var packet = new LoginRequestPacket
        {
            Data = new ServerData
            {
                Id = 1,
                Password = "secret",
                Address = IPAddress.Parse("192.168.1.10"),
                Port = 27001
            }
        };

        Assert.IsTrue(server.Instance.AuthenticateGameServer(comm, packet));
        Assert.AreEqual(IPAddress.Parse("192.168.1.10"), server.Instance.Servers[1].Ip);
        Assert.AreEqual(27001, server.Instance.Servers[1].Port);
    }

    [TestMethod]
    public void AuthenticateGameServer_WrongPassword_ReturnsFalse()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.Servers[1] = new ServerInfo { ServerId = 1, Password = "secret" };

        var packet = new LoginRequestPacket
        {
            Data = new ServerData
            {
                Id = 1,
                Password = "wrong",
                Address = IPAddress.Loopback,
                Port = 1
            }
        };

        Assert.IsFalse(server.Instance.AuthenticateGameServer(new Comm(CommType.Client), packet));
    }

    [TestMethod]
    public void AuthenticateGameServer_UnknownSlot_ReturnsFalse()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        var packet = new LoginRequestPacket
        {
            Data = new ServerData { Id = 99, Password = "x", Address = IPAddress.Loopback, Port = 1 }
        };
        Assert.IsFalse(server.Instance.AuthenticateGameServer(new Comm(CommType.Client), packet));
    }

    [TestMethod]
    public void UpdateServerInfo_WithMatchingServerId_UpdatesSlot()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.Servers[2] = new ServerInfo { ServerId = 2, Password = "p", Ip = IPAddress.Loopback };

        var comm = new Comm(CommType.Client);
        comm.Data.Id = 2;

        server.Instance.UpdateServerInfo(comm, new ServerInfo
        {
            AgeLimit = 18,
            PKFlag = 1,
            CurrentPlayers = 5,
            MaxPlayers = 50
        });

        Assert.AreEqual((byte)18, server.Instance.Servers[2].AgeLimit);
        Assert.AreEqual((byte)1, server.Instance.Servers[2].PKFlag);
        Assert.AreEqual((ushort)5, server.Instance.Servers[2].CurrentPlayers);
        Assert.AreEqual((ushort)50, server.Instance.Servers[2].MaxPlayers);
    }

    [TestMethod]
    public void BroadcastServerList_SendsOnlyToServerListStateClients()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.Servers[1] = new ServerInfo
        {
            ServerId = 1,
            Ip = IPAddress.Parse("127.0.0.1"),
            Port = 27001
        };

        var sentA = new List<IBasePacket>();
        var sentB = new List<IBasePacket>();
        var a = new AuthClient(server.Instance, 1, 2, 3)
        {
            State = ClientState.ServerList,
            Account = new Account { Id = 1, LastServerId = 1 },
            TestSendHook = p => sentA.Add(p)
        };
        var b = new AuthClient(server.Instance, 4, 5, 6)
        {
            State = ClientState.LoggedIn,
            Account = new Account { Id = 2, LastServerId = 1 },
            TestSendHook = p => sentB.Add(p)
        };
        server.Instance.Clients.Add(a);
        server.Instance.Clients.Add(b);

        server.Instance.BroadcastServerList();

        Assert.AreEqual(1, sentA.Count);
        Assert.IsInstanceOfType(sentA[0], typeof(SendServerListExtPacket));
        Assert.AreEqual(0, sentB.Count);
    }

    [TestMethod]
    public void RedirectResponse_MissingClient_IsNoOp()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        var comm = new Comm(CommType.Client);
        comm.Data.Id = 1;
        server.Instance.RedirectResponse(comm, new RedirectResponsePacket { AccountId = 999, Success = true });
    }

    [TestMethod]
    public void RedirectResponse_FoundClient_CallsRedirectionResult()
    {
        var dbName = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(dbName);
        AuthClient.CreateAuthContext = () => CreateInMemoryContext(dbName);

        using (var ctx = CreateInMemoryContext(dbName))
        {
            ctx.Accounts.Add(new Account
            {
                Username = "red",
                Email = "r@t",
                Password = "x",
                Salt = "y",
                JoinDate = DateTime.UtcNow
            });
            ctx.SaveChanges();
        }

        uint accountId;
        using (var ctx = CreateInMemoryContext(dbName))
            accountId = ctx.Accounts.Single().Id;

        using var server = new DisposableAuthServer();
        var sent = new List<IBasePacket>();
        var client = new AuthClient(server.Instance, oneTimeKey: 99, sessionId1: 1, sessionId2: 2)
        {
            Account = new Account { Id = accountId, Username = "red" },
            TestSendHook = p => sent.Add(p)
        };
        server.Instance.Clients.Add(client);

        var comm = new Comm(CommType.Client);
        comm.Data.Id = 3;
        server.Instance.RedirectResponse(comm, new RedirectResponsePacket
        {
            AccountId = accountId,
            Success = false
        });

        Assert.IsTrue(sent.Any(p => p is PlayFailPacket));
        Assert.AreEqual(ClientState.Disconnected, client.State);
    }

    [TestMethod]
    public void RequestRedirection_UnknownServer_LogsWithoutThrow()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        var client = new AuthClient(server.Instance, 1, 2, 3)
        {
            Account = new Account { Id = 1, Username = "u", Email = "e@e" }
        };
        // No communicator clients registered — should log and return.
        server.Instance.RequestRedirection(client, 1);
    }

    [TestMethod]
    public void Shutdown_DoesNotThrowWhenNotStarted()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        using var server = new DisposableAuthServer();
        server.Instance.Shutdown();
    }

    /// <summary>Wraps AuthServer so tests always call Shutdown (finalizer also does).</summary>
    private sealed class DisposableAuthServer : IDisposable
    {
        public AuthServer Instance { get; } = new();

        public void Dispose()
        {
            try { Instance.Shutdown(); } catch { /* best effort */ }
        }
    }
}
