using System.Net;
using System.Net.Sockets;
using System.Reflection;
using System.Text;
using AutoCore.Auth.Crypto;
using AutoCore.Auth.Data;
using AutoCore.Auth.Network;
using AutoCore.Auth.Packets.Server;
using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;
using AutoCore.Utils.Memory;
using AutoCore.Utils.Networking;
using AutoCore.Utils.Packets;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Auth.Tests.Network;

/// <summary>
/// Covers AuthClient socketing / queue residual without binding production ports 2106/2107.
/// Uses loopback ephemeral ports or pure in-memory buffers.
/// </summary>
[TestClass]
public class AuthClientSocketingTests
{
    private Func<AuthContext>? _prevClientFactory;
    private Func<AuthContext>? _prevServerFactory;

    [TestInitialize]
    public void Init()
    {
        _prevClientFactory = AuthClient.CreateAuthContext;
        _prevServerFactory = AuthServer.CreateAuthContext;
    }

    [TestCleanup]
    public void Cleanup()
    {
        AuthClient.CreateAuthContext = _prevClientFactory ?? (static () => new AuthContext());
        AuthServer.CreateAuthContext = _prevServerFactory ?? (static () => new AuthContext());
    }

    private static AuthContext CreateInMemory(string name) =>
        new(new DbContextOptionsBuilder<AuthContext>().UseInMemoryDatabase(name).Options);

    [TestMethod]
    public void Update_FlushesOutgoingQueue_ViaTestHook()
    {
        var db = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemory(db);
        AuthClient.CreateAuthContext = () => CreateInMemory(db);

        var server = new AuthServer();
        try
        {
            var sent = new List<IBasePacket>();
            var client = new AuthClient(server, oneTimeKey: 1, sessionId1: 2, sessionId2: 3)
            {
                TestSendHook = p => sent.Add(p)
            };

            var queueField = typeof(AuthClient).GetField("_packetQueue", BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsNotNull(queueField);
            var queue = (PacketQueue)queueField!.GetValue(client)!;
            queue.EnqueueOutgoing(new LoginOkPacket { SessionId1 = 2, SessionId2 = 3 });

            client.Update(0);

            Assert.AreEqual(1, sent.Count);
            Assert.IsInstanceOfType(sent[0], typeof(LoginOkPacket));
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void OnReceive_DecryptsPayload_EnqueuesAndResetsTimeout()
    {
        var db = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemory(db);
        AuthClient.CreateAuthContext = () => CreateInMemory(db);

        var server = new AuthServer();
        try
        {
            var client = new AuthClient(server, oneTimeKey: 1, sessionId1: 10, sessionId2: 20)
            {
                Account = new Account { Id = 1, Username = "u" }
            };
            // OnReceive resets "timeout" — register one so the path is meaningful
            client.Timer.Add("timeout", 300_000, false, () => { });

            // Build encrypted Logout payload (opcode + 2 session ids)
            var plain = new byte[32];
            using (var ms = new MemoryStream(plain, true))
            using (var w = new BinaryWriter(ms))
            {
                w.Write((byte)ClientOpcode.Logout);
                w.Write(10u);
                w.Write(20u);
            }

            var length = 9; // 1 + 4 + 4
            CryptoManager.Encrypt(plain, 0, ref length, plain.Length);

            var stream = new NonContiguousMemoryStream();
            stream.Write(plain, 0, length);
            stream.Position = 0;

            var onReceive = typeof(AuthClient).GetMethod(
                "OnReceive",
                BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsNotNull(onReceive);
            onReceive!.Invoke(client, new object[] { stream, length });

            client.Update(0);
            Assert.AreEqual(ClientState.Disconnected, client.State);
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void RealConstructor_SendsProtocolVersion_AndTimeoutClosesClient()
    {
        var db = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemory(db);
        AuthClient.CreateAuthContext = () => CreateInMemory(db);

        var server = new AuthServer();
        TcpListener? listener = null;
        Socket? peer = null;
        AuthClient? client = null;
        try
        {
            listener = new TcpListener(IPAddress.Loopback, 0);
            listener.Start();
            var port = ((IPEndPoint)listener.LocalEndpoint).Port;

            peer = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            var connectTask = peer.ConnectAsync(IPAddress.Loopback, port);
            var accepted = listener.AcceptSocket();
            connectTask.GetAwaiter().GetResult();

            // Drain peer so ProtocolVersion send does not block the send loop forever
            _ = Task.Run(() =>
            {
                var buf = new byte[512];
                try
                {
                    while (peer.Connected)
                    {
                        var n = peer.Receive(buf);
                        if (n == 0) break;
                    }
                }
                catch
                {
                    // peer closed
                }
            });

            var asyncSocket = new AsyncLengthedSocket(accepted, AsyncLengthedSocket.HeaderSizeType.Word);
            client = new AuthClient(asyncSocket, server);

            Assert.AreEqual(ClientState.Connected, client.State);
            Assert.AreNotEqual(0u, client.OneTimeKey);

            // Fire the 300s timeout callback installed by the real constructor
            client.Timer.Update(300_000);
            Assert.AreEqual(ClientState.Disconnected, client.State);
        }
        finally
        {
            try { client?.Close(); } catch { /* best effort */ }
            try { peer?.Close(); } catch { /* best effort */ }
            try { listener?.Stop(); } catch { /* best effort */ }
            server.Shutdown();
        }
    }

    [TestMethod]
    public void SendPacket_WithoutHook_EncryptsAndWritesToSocket()
    {
        var db = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemory(db);
        AuthClient.CreateAuthContext = () => CreateInMemory(db);

        var server = new AuthServer();
        TcpListener? listener = null;
        Socket? peer = null;
        AuthClient? client = null;
        try
        {
            listener = new TcpListener(IPAddress.Loopback, 0);
            listener.Start();
            var port = ((IPEndPoint)listener.LocalEndpoint).Port;

            peer = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            var connectTask = peer.ConnectAsync(IPAddress.Loopback, port);
            var accepted = listener.AcceptSocket();
            connectTask.GetAwaiter().GetResult();

            var received = new MemoryStream();
            var receiveDone = new ManualResetEventSlim(false);
            _ = Task.Run(() =>
            {
                var buf = new byte[1024];
                try
                {
                    // ProtocolVersion + one encrypted LoginOk
                    var total = 0;
                    while (total < 20)
                    {
                        var n = peer.Receive(buf);
                        if (n == 0) break;
                        received.Write(buf, 0, n);
                        total += n;
                    }
                }
                catch
                {
                    // closed
                }
                finally
                {
                    receiveDone.Set();
                }
            });

            var asyncSocket = new AsyncLengthedSocket(accepted, AsyncLengthedSocket.HeaderSizeType.Word);
            client = new AuthClient(asyncSocket, server);

            // No TestSendHook — exercises Encrypt + Socket.Send path
            client.SendPacket(new LoginOkPacket
            {
                SessionId1 = 1,
                SessionId2 = 2
            });

            Assert.IsTrue(receiveDone.Wait(TimeSpan.FromSeconds(3)), "peer should receive framed packets");
            Assert.IsTrue(received.Length > 0);
        }
        finally
        {
            try { client?.Close(); } catch { /* best effort */ }
            try { peer?.Close(); } catch { /* best effort */ }
            try { listener?.Stop(); } catch { /* best effort */ }
            server.Shutdown();
        }
    }

    [TestMethod]
    public void PlayFail_ToString_IncludesReason()
    {
        var packet = new PlayFailPacket(FailReason.ServerIsFull);
        Assert.IsTrue(packet.ToString().Contains("PlayFailPacket"));
        Assert.IsTrue(packet.ToString().Contains("ServerIsFull"));
    }
}
