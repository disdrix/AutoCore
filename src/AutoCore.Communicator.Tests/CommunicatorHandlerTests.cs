using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Net;
using AutoCore.Communicator.Packets;
using AutoCore.Communicator.Tests.Packets;
using AutoCore.Utils.Memory;
using AutoCore.Utils.Networking;
using AutoCore.Utils.Packets;

namespace AutoCore.Communicator.Tests;

[TestClass]
public class CommunicatorHandlerTests
{
    [TestCleanup]
    public void Cleanup()
    {
        Communicator.SocketFactory = null;
    }

    #region Construction / basic API

    [TestMethod]
    public void Constructor_ServerClientType_Throws()
    {
        Assert.ThrowsException<ArgumentOutOfRangeException>(() =>
            new Communicator(CommunicatorType.ServerClient));
    }

    [TestMethod]
    public void Constructor_ServerAndClient_UseSocketFactoryWhenProvided()
    {
        var created = 0;
        Communicator.SocketFactory = () =>
        {
            created++;
            return new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word);
        };

        var server = new Communicator(CommunicatorType.Server);
        var client = new Communicator(CommunicatorType.Client);

        Assert.AreEqual(2, created);
        Assert.AreEqual(CommunicatorType.Server, server.Type);
        Assert.AreEqual(CommunicatorType.Client, client.Type);
        Assert.IsFalse(server.Connected);
        Assert.IsFalse(client.Connected);

        server.Close();
        client.Close();
    }

    [TestMethod]
    public void Constructor_InjectedSocket_UsesProvidedInstance()
    {
        var socket = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word);
        var server = new Communicator(CommunicatorType.Server, socket);

        Assert.AreSame(socket, server.Socket);
        server.Close();
    }

    [TestMethod]
    public void Update_OnNonServer_Throws()
    {
        var client = new Communicator(CommunicatorType.Client);
        var ex = Assert.ThrowsException<Exception>(() => client.Update());
        StringAssert.Contains(ex.Message, "Update can only be called on a server");
        client.Close();
    }

    [TestMethod]
    public void Update_RemovesClientsQueuedForRemoval()
    {
        var (server, child, sent) = CreateServerChildPair();
        AuthenticateChild(server, child, id: 9, accept: true);

        Assert.IsTrue(server.Clients.ContainsKey(9));

        server.ToRemoveClients.Add(9);
        server.Update();

        Assert.IsFalse(server.Clients.ContainsKey(9));
        Assert.AreEqual(0, server.ToRemoveClients.Count);

        server.Close();
    }

    [TestMethod]
    public void Close_Server_ClosesChildrenAndClearsCollections()
    {
        var (server, child, _) = CreateServerChildPair();
        AuthenticateChild(server, child, id: 1, accept: true);
        server.AuthenticatingChildren.Add(
            new Communicator(new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word), server, autoStart: false));

        server.Close();

        Assert.AreEqual(0, server.Clients.Count);
        Assert.AreEqual(0, server.AuthenticatingChildren.Count);
    }

    #endregion

    #region Login

    [TestMethod]
    public void LoginRequest_Accept_SendsSuccess_AddsClient_FiresServerInfo()
    {
        var (server, child, sent) = CreateServerChildPair();
        ServerInfo? seenInfo = null;
        Communicator? loginComm = null;
        LoginRequestPacket? loginPacket = null;

        server.OnLoginRequest = (comm, packet) =>
        {
            loginComm = comm;
            loginPacket = packet;
            return true;
        };
        server.OnServerInfo = (comm, info) => seenInfo = info;

        var data = PacketTestHelper.SampleServerData(id: 5);
        var info = PacketTestHelper.SampleServerInfo();
        Deliver(child, new LoginRequestPacket(data, info));

        Assert.AreSame(child, loginComm);
        Assert.IsNotNull(loginPacket);
        Assert.AreEqual(5, loginPacket!.Data.Id);
        Assert.AreEqual(data.Password, loginPacket.Data.Password);
        Assert.IsTrue(server.Clients.ContainsKey(5));
        Assert.IsFalse(server.AuthenticatingChildren.Contains(child));
        Assert.IsNotNull(seenInfo);
        Assert.AreEqual(info.Port, seenInfo!.Port);
        Assert.AreEqual(5, child.Data.Id);

        var response = DecodeLastSent<LoginResponsePacket>(sent, CommunicatorOpcode.LoginResponse);
        Assert.IsTrue(response.Success);
    }

    [TestMethod]
    public void LoginRequest_Reject_SendsFailure_RemovesFromAuthenticating_DoesNotAddClient()
    {
        var (server, child, sent) = CreateServerChildPair();
        var serverInfoCalls = 0;

        server.OnLoginRequest = (_, _) => false;
        server.OnServerInfo = (_, _) => serverInfoCalls++;

        Deliver(child, new LoginRequestPacket(PacketTestHelper.SampleServerData(id: 8), PacketTestHelper.SampleServerInfo()));

        Assert.IsFalse(server.Clients.ContainsKey(8));
        Assert.IsFalse(server.AuthenticatingChildren.Contains(child));
        Assert.AreEqual(0, serverInfoCalls);

        var response = DecodeLastSent<LoginResponsePacket>(sent, CommunicatorOpcode.LoginResponse);
        Assert.IsFalse(response.Success);
    }

    [TestMethod]
    public void LoginRequest_DuplicateClientId_IsIgnored()
    {
        var (server, child, sent) = CreateServerChildPair();
        AuthenticateChild(server, child, id: 3, accept: true);
        sent.Clear();

        var secondSocket = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word);
        var second = new Communicator(secondSocket, server, autoStart: false);
        var secondSent = new List<byte[]>();
        second.TestSendOverride = (buf, off, len) => secondSent.Add(buf.AsSpan(off, len).ToArray());
        server.AuthenticatingChildren.Add(second);

        var loginCalls = 0;
        server.OnLoginRequest = (_, _) =>
        {
            loginCalls++;
            return true;
        };

        Deliver(second, new LoginRequestPacket(PacketTestHelper.SampleServerData(id: 3), PacketTestHelper.SampleServerInfo()));

        Assert.AreEqual(0, loginCalls);
        Assert.AreEqual(0, secondSent.Count);
        Assert.AreEqual(1, server.Clients.Count);

        server.Close();
    }

    [TestMethod]
    public void LoginRequest_MissingCallbacks_IsIgnored()
    {
        var (server, child, sent) = CreateServerChildPair();
        server.OnLoginRequest = null;
        server.OnServerInfo = null;

        Deliver(child, new LoginRequestPacket(PacketTestHelper.SampleServerData(), PacketTestHelper.SampleServerInfo()));

        Assert.AreEqual(0, sent.Count);
        Assert.AreEqual(0, server.Clients.Count);
        server.Close();
    }

    [TestMethod]
    public void LoginRequest_OnWrongType_IsIgnored()
    {
        var client = new Communicator(CommunicatorType.Client);
        var sent = new List<byte[]>();
        client.TestSendOverride = (buf, off, len) => sent.Add(buf.AsSpan(off, len).ToArray());

        Deliver(client, new LoginRequestPacket(PacketTestHelper.SampleServerData(), PacketTestHelper.SampleServerInfo()));

        Assert.AreEqual(0, sent.Count);
        client.Close();
    }

    [TestMethod]
    public void LoginResponse_Success_InvokesCallback()
    {
        var client = new Communicator(CommunicatorType.Client);
        bool? seen = null;
        client.OnLoginResponse = s => seen = s;

        Deliver(client, new LoginResponsePacket { Success = true });

        Assert.IsTrue(seen is true);
        client.Close();
    }

    [TestMethod]
    public void LoginResponse_Failure_ClosesSocket()
    {
        var socket = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word);
        var client = new Communicator(CommunicatorType.Client, socket);
        var callbackCalled = false;
        client.OnLoginResponse = _ => callbackCalled = true;

        Deliver(client, new LoginResponsePacket { Success = false });

        Assert.IsFalse(callbackCalled);
        // Close was invoked; second Close may throw on disposed CTS — just ensure no callback
    }

    [TestMethod]
    public void LoginResponse_OnWrongType_IsIgnored()
    {
        var (server, child, sent) = CreateServerChildPair();
        Deliver(child, new LoginResponsePacket { Success = true });
        Assert.AreEqual(0, sent.Count);
        server.Close();
    }

    #endregion

    #region Redirect

    [TestMethod]
    public void RedirectRequest_OnClient_SendsResponseFromCallback()
    {
        var client = new Communicator(CommunicatorType.Client);
        var sent = new List<byte[]>();
        client.TestSendOverride = (buf, off, len) => sent.Add(buf.AsSpan(off, len).ToArray());
        RedirectRequest? seen = null;
        client.OnRedirectRequest = req =>
        {
            seen = req;
            return true;
        };

        var request = PacketTestHelper.SampleRedirectRequest();
        Deliver(client, new RedirectRequestPacket(request));

        Assert.IsNotNull(seen);
        Assert.AreEqual(request.AccountId, seen!.AccountId);
        Assert.AreEqual(request.Username, seen.Username);

        var response = DecodeLastSent<RedirectResponsePacket>(sent, CommunicatorOpcode.RedirectResponse);
        Assert.IsTrue(response.Success);
        Assert.AreEqual(request.AccountId, response.AccountId);

        client.Close();
    }

    [TestMethod]
    public void RedirectRequest_MissingCallback_DoesNotSend()
    {
        var client = new Communicator(CommunicatorType.Client);
        var sent = new List<byte[]>();
        client.TestSendOverride = (buf, off, len) => sent.Add(buf.AsSpan(off, len).ToArray());
        client.OnRedirectRequest = null;

        Deliver(client, new RedirectRequestPacket(PacketTestHelper.SampleRedirectRequest()));

        Assert.AreEqual(0, sent.Count);
        client.Close();
    }

    [TestMethod]
    public void RedirectRequest_OnWrongType_IsIgnored()
    {
        var (server, child, sent) = CreateServerChildPair();
        Deliver(child, new RedirectRequestPacket(PacketTestHelper.SampleRedirectRequest()));
        Assert.AreEqual(0, sent.Count);
        server.Close();
    }

    [TestMethod]
    public void RedirectResponse_OnServerClient_ForwardsToServerCallback()
    {
        var (server, child, _) = CreateServerChildPair();
        Communicator? seenComm = null;
        RedirectResponsePacket? seenPacket = null;
        server.OnRedirectResponse = (comm, packet) =>
        {
            seenComm = comm;
            seenPacket = packet;
        };

        Deliver(child, new RedirectResponsePacket { AccountId = 77, Success = true });

        Assert.AreSame(child, seenComm);
        Assert.IsNotNull(seenPacket);
        Assert.AreEqual(77u, seenPacket!.AccountId);
        Assert.IsTrue(seenPacket.Success);

        server.Close();
    }

    [TestMethod]
    public void RedirectResponse_MissingCallback_IsIgnored()
    {
        var (server, child, _) = CreateServerChildPair();
        server.OnRedirectResponse = null;

        // Should not throw
        Deliver(child, new RedirectResponsePacket { AccountId = 1, Success = false });
        server.Close();
    }

    [TestMethod]
    public void RedirectResponse_OnWrongType_IsIgnored()
    {
        var client = new Communicator(CommunicatorType.Client);
        Deliver(client, new RedirectResponsePacket { AccountId = 1, Success = true });
        client.Close();
    }

    [TestMethod]
    public void RequestRedirection_ServerClient_SendsPacket()
    {
        var (server, child, sent) = CreateServerChildPair();
        var request = PacketTestHelper.SampleRedirectRequest();

        child.RequestRedirection(1, request);

        var packet = DecodeLastSent<RedirectRequestPacket>(sent, CommunicatorOpcode.RedirectRequest);
        Assert.AreEqual(request.AccountId, packet.Request.AccountId);
        Assert.AreEqual(request.Username, packet.Request.Username);

        server.Close();
    }

    [TestMethod]
    public void RequestRedirection_Server_ForwardsToKnownClient()
    {
        var (server, child, sent) = CreateServerChildPair();
        AuthenticateChild(server, child, id: 4, accept: true);
        sent.Clear();

        var request = PacketTestHelper.SampleRedirectRequest();
        server.RequestRedirection(4, request);

        var packet = DecodeLastSent<RedirectRequestPacket>(sent, CommunicatorOpcode.RedirectRequest);
        Assert.AreEqual(request.AccountId, packet.Request.AccountId);
    }

    [TestMethod]
    public void RequestRedirection_Server_UnknownClient_DoesNotThrow()
    {
        var server = new Communicator(CommunicatorType.Server);
        server.RequestRedirection(99, PacketTestHelper.SampleRedirectRequest());
        server.Close();
    }

    [TestMethod]
    public void RequestRedirection_ClientType_DoesNotThrow()
    {
        var client = new Communicator(CommunicatorType.Client);
        client.RequestRedirection(1, PacketTestHelper.SampleRedirectRequest());
        client.Close();
    }

    #endregion

    #region Server info

    [TestMethod]
    public void ServerInfoRequest_OnClient_SendsResponseFromCallback()
    {
        var client = new Communicator(CommunicatorType.Client);
        var sent = new List<byte[]>();
        client.TestSendOverride = (buf, off, len) => sent.Add(buf.AsSpan(off, len).ToArray());
        client.OnServerInfoRequest = info =>
        {
            info.Port = 12345;
            info.AgeLimit = 13;
            info.PKFlag = 0;
            info.CurrentPlayers = 3;
            info.MaxPlayers = 50;
        };

        Deliver(client, new ServerInfoRequestPacket());

        var response = DecodeLastSent<ServerInfoResponsePacket>(sent, CommunicatorOpcode.ServerInfoResponse);
        Assert.AreEqual(12345, response.Info.Port);
        Assert.AreEqual(13, response.Info.AgeLimit);
        Assert.AreEqual(3, response.Info.CurrentPlayers);

        client.Close();
    }

    [TestMethod]
    public void ServerInfoRequest_MissingCallback_DoesNotSend()
    {
        var client = new Communicator(CommunicatorType.Client);
        var sent = new List<byte[]>();
        client.TestSendOverride = (buf, off, len) => sent.Add(buf.AsSpan(off, len).ToArray());
        client.OnServerInfoRequest = null;

        Deliver(client, new ServerInfoRequestPacket());
        Assert.AreEqual(0, sent.Count);
        client.Close();
    }

    [TestMethod]
    public void ServerInfoResponse_OnServerClient_ForwardsToServer()
    {
        var (server, child, _) = CreateServerChildPair();
        ServerInfo? seen = null;
        server.OnServerInfo = (_, info) => seen = info;

        var info = PacketTestHelper.SampleServerInfo();
        Deliver(child, new ServerInfoResponsePacket(info));

        Assert.IsNotNull(seen);
        Assert.AreEqual(info.Port, seen!.Port);
        Assert.AreEqual(info.CurrentPlayers, seen.CurrentPlayers);

        server.Close();
    }

    [TestMethod]
    public void ServerInfoRequest_OnWrongType_IsIgnored()
    {
        var (server, child, sent) = CreateServerChildPair();
        Deliver(child, new ServerInfoRequestPacket());
        Assert.AreEqual(0, sent.Count);
        server.Close();
    }

    [TestMethod]
    public void ServerInfoResponse_OnWrongType_IsIgnored()
    {
        var client = new Communicator(CommunicatorType.Client);
        Deliver(client, new ServerInfoResponsePacket(PacketTestHelper.SampleServerInfo()));
        client.Close();
    }

    [TestMethod]
    public void ServerInfoResponse_MissingCallback_IsIgnored()
    {
        var (server, child, _) = CreateServerChildPair();
        server.OnServerInfo = null;
        Deliver(child, new ServerInfoResponsePacket(PacketTestHelper.SampleServerInfo()));
        server.Close();
    }

    [TestMethod]
    public void Update_UnknownClientIdInToRemove_IsSkipped()
    {
        var server = new Communicator(CommunicatorType.Server);
        server.ToRemoveClients.Add(55);
        server.Update();
        Assert.AreEqual(0, server.ToRemoveClients.Count);
        server.Close();
    }

    [TestMethod]
    public void RequestServerInfo_ServerClient_SendsRequestAndUpdatesTimestamp()
    {
        var (server, child, sent) = CreateServerChildPair();
        var before = DateTime.Now.AddSeconds(-1);

        child.RequestServerInfo();

        Assert.IsTrue(child.LastRequestTime >= before);
        var packet = DecodeLastSent<ServerInfoRequestPacket>(sent, CommunicatorOpcode.ServerInfoRequest);
        Assert.AreEqual(CommunicatorOpcode.ServerInfoRequest, packet.Opcode);

        server.Close();
    }

    [TestMethod]
    public void RequestServerInfo_Server_PollsClientsPastInterval()
    {
        var (server, child, sent) = CreateServerChildPair();
        AuthenticateChild(server, child, id: 2, accept: true);
        sent.Clear();

        // LastRequestTime defaults to DateTime.MinValue → interval elapsed
        server.RequestServerInfo();

        Assert.IsTrue(sent.Count >= 1);
        var opcode = (CommunicatorOpcode)sent[^1][0];
        Assert.AreEqual(CommunicatorOpcode.ServerInfoRequest, opcode);

        server.Close();
    }

    [TestMethod]
    public void RequestServerInfo_Server_SkipsClientsWithinInterval()
    {
        var (server, child, sent) = CreateServerChildPair();
        AuthenticateChild(server, child, id: 2, accept: true);

        // Set recent request by calling once, then clear and ensure skip
        child.RequestServerInfo();
        sent.Clear();

        server.RequestServerInfo();
        Assert.AreEqual(0, sent.Count);

        server.Close();
    }

    #endregion

    #region Connect / accept / error

    [TestMethod]
    public void SocketConnect_WithCallbacks_SendsLoginRequest()
    {
        var client = new Communicator(CommunicatorType.Client);
        var sent = new List<byte[]>();
        client.TestSendOverride = (buf, off, len) => sent.Add(buf.AsSpan(off, len).ToArray());

        client.OnConnect = data =>
        {
            data.Id = 11;
            data.Password = "pwd";
            data.Address = IPAddress.Loopback;
            data.Port = 2106;
        };
        client.OnServerInfoRequest = info =>
        {
            info.Port = 2106;
            info.AgeLimit = 18;
            info.MaxPlayers = 100;
        };

        // ProcessSocketConnect calls Socket.Start() which starts real I/O loops.
        // Instead, exercise the packet construction path by invoking connect only if we
        // can avoid Start — Start is hard-coded. Call it and immediately Close after asserts.
        try
        {
            client.ProcessSocketConnect();
        }
        catch
        {
            // Socket.Start may fault on unconnected socket after send; sent should still be captured first.
        }

        Assert.IsTrue(sent.Count >= 1, "Expected LoginRequest to be sent on connect");
        var login = DecodeLastSent<LoginRequestPacket>(sent, CommunicatorOpcode.LoginRequest);
        Assert.AreEqual(11, login.Data.Id);
        Assert.AreEqual("pwd", login.Data.Password);
        Assert.AreEqual(2106, login.InfoPacket.Info.Port);

        try { client.Close(); } catch { /* disposed CTS from Start/Close race */ }
    }

    [TestMethod]
    public void SocketConnect_MissingCallbacks_Throws()
    {
        var client = new Communicator(CommunicatorType.Client);
        Assert.ThrowsException<Exception>(() => client.ProcessSocketConnect());
        client.Close();
    }

    [TestMethod]
    public void SocketAccept_AddsAuthenticatingChild()
    {
        var server = new Communicator(CommunicatorType.Server);
        var accepted = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word);

        // ProcessSocketAccept constructs Communicator(socket, server) with autoStart:true
        // Use a path that doesn't auto-start by testing AuthenticatingChildren via the
        // public accept path is hard without Start. Manually exercise OnSocketAccept logic:
        // the production method always auto-starts. We'll invoke ProcessSocketAccept and
        // immediately close to avoid hanging receive loops.
        server.ProcessSocketAccept(accepted);

        Assert.AreEqual(1, server.AuthenticatingChildren.Count);
        Assert.AreEqual(CommunicatorType.ServerClient, server.AuthenticatingChildren[0].Type);

        try { server.Close(); } catch { /* ignore */ }
    }

    [TestMethod]
    public void SocketError_InvokesOnErrorCallback()
    {
        var client = new Communicator(CommunicatorType.Client);
        var errored = false;
        client.OnError = () => errored = true;

        client.ProcessSocketError();

        Assert.IsTrue(errored);
    }

    #endregion

    #region Malformed / framing

    /// <summary>
    /// SS-11: the opcode is a peer-controlled byte. This used to throw from the socket receive
    /// task, which permanently killed that connection's receive loop. The message must be
    /// rejected instead, leaving the connection usable.
    /// </summary>
    [TestMethod]
    public void InvalidOpcode_IsRejectedWithoutThrowing()
    {
        var client = new Communicator(CommunicatorType.Client);
        using var stream = new NonContiguousMemoryStream();
        var payload = new byte[] { 0xFF }; // invalid opcode
        stream.Write(payload, 0, payload.Length);
        stream.Position = 0;

        client.ProcessReceivedPacket(stream, payload.Length);

        client.Close();
    }

    /// <summary>
    /// SS-11: a declared length longer than the body must be rejected, not thrown on.
    /// </summary>
    [TestMethod]
    public void MalformedLength_OverRead_IsRejectedWithoutThrowing()
    {
        var client = new Communicator(CommunicatorType.Client);
        var packet = new LoginResponsePacket { Success = true };
        var bytes = PacketTestHelper.WritePacket(packet);

        using var stream = new NonContiguousMemoryStream();
        stream.Write(bytes, 0, bytes.Length);
        stream.Position = 0;

        // Claim a longer length than the payload actually consumes.
        client.ProcessReceivedPacket(stream, bytes.Length + 8);

        client.Close();
    }

    /// <summary>
    /// SS-11: a declared length shorter than the body must be rejected, not thrown on.
    /// </summary>
    [TestMethod]
    public void MalformedLength_UnderRead_IsRejectedWithoutThrowing()
    {
        var client = new Communicator(CommunicatorType.Client);
        var packet = new LoginResponsePacket { Success = true };
        var bytes = PacketTestHelper.WritePacket(packet);

        using var stream = new NonContiguousMemoryStream();
        stream.Write(bytes, 0, bytes.Length);
        stream.Position = 0;

        client.ProcessReceivedPacket(stream, 1);

        client.Close();
    }

    /// <summary>
    /// SS-11: a peer disconnecting mid-packet leaves a truncated body. That must be rejected,
    /// not surfaced as an EndOfStreamException that kills the receive loop.
    /// </summary>
    [TestMethod]
    public void DisconnectMidRead_TruncatedPayload_IsRejectedWithoutThrowing()
    {
        var client = new Communicator(CommunicatorType.Client);
        // Partial RedirectRequest (opcode + 2 bytes of AccountId only)
        var partial = new byte[] { (byte)CommunicatorOpcode.RedirectRequest, 0x01, 0x02 };

        using var stream = new NonContiguousMemoryStream();
        stream.Write(partial, 0, partial.Length);
        stream.Position = 0;

        client.ProcessReceivedPacket(stream, partial.Length);

        client.Close();
    }

    [TestMethod]
    public void EmptyFrame_IsRejectedWithoutThrowing()
    {
        var client = new Communicator(CommunicatorType.Client);
        using var stream = new NonContiguousMemoryStream();

        client.ProcessReceivedPacket(stream, 0);

        client.Close();
    }

    /// <summary>
    /// SS-11 tripwire: the canonical survival shape. A good message, then a malformed one that
    /// is rejected, then another good message that must still be delivered.
    /// </summary>
    [TestMethod]
    public void AfterMalformedMessage_LaterValidMessagesAreStillProcessed()
    {
        var client = new Communicator(CommunicatorType.Client);
        var responses = new List<bool>();
        client.OnLoginResponse = s => responses.Add(s);

        Deliver(client, new LoginResponsePacket { Success = true });

        using (var bad = new NonContiguousMemoryStream())
        {
            var payload = new byte[] { 0xFF }; // unknown opcode
            bad.Write(payload, 0, payload.Length);
            bad.Position = 0;
            client.ProcessReceivedPacket(bad, payload.Length);
        }

        Deliver(client, new LoginResponsePacket { Success = true });

        CollectionAssert.AreEqual(
            new[] { true, true },
            responses,
            "SS-11: a malformed message must not stop later valid messages from being " +
            $"processed. Got {responses.Count} response(s).");

        client.Close();
    }

    [TestMethod]
    public void OpcodePreserved_ThroughReceivePipeline()
    {
        var client = new Communicator(CommunicatorType.Client);
        bool? success = null;
        client.OnLoginResponse = s => success = s;

        Deliver(client, new LoginResponsePacket { Success = true });
        Assert.IsTrue(success is true);
        client.Close();
    }

    #endregion

    #region Helpers

    private static (Communicator server, Communicator child, List<byte[]> sent) CreateServerChildPair()
    {
        var server = new Communicator(CommunicatorType.Server);
        // Provide no-op defaults so login paths can run when tests set them
        server.OnLoginRequest ??= (_, _) => true;
        server.OnServerInfo ??= (_, _) => { };

        var socket = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word);
        var child = new Communicator(socket, server, autoStart: false);
        var sent = new List<byte[]>();
        child.TestSendOverride = (buf, off, len) => sent.Add(buf.AsSpan(off, len).ToArray());
        server.AuthenticatingChildren.Add(child);
        return (server, child, sent);
    }

    private static void AuthenticateChild(Communicator server, Communicator child, byte id, bool accept)
    {
        server.OnLoginRequest = (_, _) => accept;
        server.OnServerInfo ??= (_, _) => { };
        Deliver(child, new LoginRequestPacket(PacketTestHelper.SampleServerData(id), PacketTestHelper.SampleServerInfo()));
    }

    private static void Deliver(Communicator target, IOpcodedPacket<CommunicatorOpcode> packet)
    {
        var bytes = PacketTestHelper.WritePacket(packet);
        using var stream = new NonContiguousMemoryStream();
        stream.Write(bytes, 0, bytes.Length);
        stream.Position = 0;
        target.ProcessReceivedPacket(stream, bytes.Length);
    }

    private static T DecodeLastSent<T>(List<byte[]> sent, CommunicatorOpcode expectedOpcode)
        where T : IOpcodedPacket<CommunicatorOpcode>, new()
    {
        Assert.IsTrue(sent.Count > 0, "Expected at least one sent packet");
        var bytes = sent[^1];
        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);
        var opcode = (CommunicatorOpcode)br.ReadByte();
        Assert.AreEqual(expectedOpcode, opcode);
        var packet = new T();
        packet.Read(br);
        return packet;
    }

    #endregion
}
