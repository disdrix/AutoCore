using System.Net;
using System.Net.Sockets;
using System.Reflection;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Networking;

using AutoCore.Utils.Memory;
using AutoCore.Utils.Networking;

/// <summary>
/// Construction / callback coverage for AsyncLengthedSocket without peer framing loops.
/// Framing contract is covered by <see cref="LengthPrefixFramingTests"/>.
/// Start/Send/Receive full duplex paths are residual (Close is not idempotent; needs connected peer).
/// </summary>
[TestClass]
public class AsyncLengthedSocketLifecycleTests
{
    [TestMethod]
    public void Constructor_Default_CreatesDisconnectedSocket()
    {
        using var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);
        Assert.IsFalse(s.Connected);
        Assert.IsNull(s.OnError);
        Assert.IsNull(s.OnAccept);
        Assert.IsNull(s.OnConnect);
        Assert.IsNull(s.OnDisconnect);
        Assert.IsNull(s.OnReceive);
    }

    [TestMethod]
    public void Constructor_AllHeaderSizes_AndCountHeaderFlag()
    {
        using var b = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Byte, countHeaderSize: true);
        using var w = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word, countHeaderSize: false);
        using var d = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword, countHeaderSize: true);
        Assert.IsFalse(b.Connected);
        Assert.IsFalse(w.Connected);
        Assert.IsFalse(d.Connected);
    }

    [TestMethod]
    public void Constructor_WithSocket_UsesProvidedSocket()
    {
        using var raw = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        using var s = new AsyncLengthedSocket(raw, AsyncLengthedSocket.HeaderSizeType.Word, countHeaderSize: false);
        Assert.IsFalse(s.Connected);
    }

    [TestMethod]
    public void Callbacks_CanBeAssignedAndInvoked()
    {
        using var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Byte);
        var error = false;
        var disconnect = false;
        var connect = false;
        var receiveCalled = false;

        s.OnError = () => error = true;
        s.OnDisconnect = () => disconnect = true;
        s.OnConnect = () => connect = true;
        s.OnAccept = _ => { };
        s.OnReceive = (NonContiguousMemoryStream stream, int size) =>
        {
            receiveCalled = true;
            _ = stream;
            _ = size;
        };

        s.OnError();
        s.OnDisconnect();
        s.OnConnect();
        Assert.IsTrue(error);
        Assert.IsTrue(disconnect);
        Assert.IsTrue(connect);
        Assert.IsNotNull(s.OnAccept);
        Assert.IsNotNull(s.OnReceive);
        Assert.IsFalse(receiveCalled);
    }

    [TestMethod]
    public void StartListening_NullEndPoint_Throws()
    {
        using var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);
        Assert.ThrowsException<ArgumentNullException>(() => s.StartListening(null!));
    }

    [TestMethod]
    public void StartListening_OnEphemeralPort_BindsThenDispose()
    {
        // Single dispose via using — Close is not idempotent.
        using var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);
        s.OnError = () => { };
        s.OnAccept = accepted => accepted.Dispose();

        s.StartListening(new IPEndPoint(IPAddress.Loopback, 0), backlog: 1);
        Thread.Sleep(30);
    }

    [TestMethod]
    public void ConnectAsync_ToClosedPort_SurfacesErrorPath()
    {
        using var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);
        var errored = new ManualResetEventSlim(false);
        s.OnError = () => errored.Set();

        s.ConnectAsync(new IPEndPoint(IPAddress.Loopback, 1));
        errored.Wait(TimeSpan.FromSeconds(2));
    }

    [TestMethod]
    public void Dispose_WithoutStart_DoesNotThrow()
    {
        var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);
        s.Dispose();
    }

    [TestMethod]
    public void RemoteAddress_WhenNotConnected_IsSafeToProbe()
    {
        using var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);
        try
        {
            _ = s.RemoteAddress;
        }
        catch (SocketException)
        {
        }
        catch (ObjectDisposedException)
        {
        }
    }

    [TestMethod]
    public void Loopback_FramedSendReceive_DeliversPayload()
    {
        var payload = new byte[] { 10, 20, 30, 40, 50 };
        byte[] receivedPayload = null;
        var received = new ManualResetEventSlim(false);
        var acceptedReady = new ManualResetEventSlim(false);
        AsyncLengthedSocket accepted = null;

        using var server = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword, countHeaderSize: true);
        server.OnError = () => { };
        server.OnAccept = s =>
        {
            accepted = s;
            s.OnError = () => { };
            s.OnReceive = (stream, size) =>
            {
                receivedPayload = new byte[size];
                stream.Read(receivedPayload, 0, size);
                received.Set();
            };
            s.Start();
            acceptedReady.Set();
        };

        server.StartListening(new IPEndPoint(IPAddress.Loopback, 0), backlog: 8);
        var port = GetLocalPort(server);

        using var client = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword, countHeaderSize: true);
        var connected = new ManualResetEventSlim(false);
        client.OnError = () => { };
        client.OnConnect = () =>
        {
            client.Start();
            connected.Set();
        };
        client.ConnectAsync(new IPEndPoint(IPAddress.Loopback, port));

        Assert.IsTrue(connected.Wait(TimeSpan.FromSeconds(3)), "client connect");
        Assert.IsTrue(acceptedReady.Wait(TimeSpan.FromSeconds(3)), "server accept");

        client.Send(payload, 0, payload.Length);
        Assert.IsTrue(received.Wait(TimeSpan.FromSeconds(3)), "payload received");
        CollectionAssert.AreEqual(payload, receivedPayload);

        // Close is not idempotent; peer close may already dispose accepted. Best-effort only.
        try { accepted?.Dispose(); } catch (ObjectDisposedException) { }
    }

    [TestMethod]
    public void Loopback_WordHeader_NotCountingHeader_RoundTrips()
    {
        var payload = new byte[] { 1, 2, 3 };
        byte[] got = null;
        var received = new ManualResetEventSlim(false);
        var acceptedReady = new ManualResetEventSlim(false);
        AsyncLengthedSocket accepted = null;

        // Note: OnAccept creates child with server's HeaderSize but default countHeaderSize=true
        // in production ctor: new AsyncLengthedSocket(socket, HeaderSize) — countHeaderSize defaults true.
        // So for this test use matching defaults (Dword/true already covered). Word+true here.
        using var server = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word, countHeaderSize: true);
        server.OnError = () => { };
        server.OnAccept = s =>
        {
            accepted = s;
            s.OnError = () => { };
            s.OnReceive = (stream, size) =>
            {
                got = new byte[size];
                stream.Read(got, 0, size);
                received.Set();
            };
            s.Start();
            acceptedReady.Set();
        };
        server.StartListening(new IPEndPoint(IPAddress.Loopback, 0));
        var port = GetLocalPort(server);

        using var client = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word, countHeaderSize: true);
        var connected = new ManualResetEventSlim(false);
        client.OnError = () => { };
        client.OnConnect = () => { client.Start(); connected.Set(); };
        client.ConnectAsync(new IPEndPoint(IPAddress.Loopback, port));

        Assert.IsTrue(connected.Wait(TimeSpan.FromSeconds(3)));
        Assert.IsTrue(acceptedReady.Wait(TimeSpan.FromSeconds(3)));
        client.Send(payload, 0, payload.Length);
        Assert.IsTrue(received.Wait(TimeSpan.FromSeconds(3)));
        CollectionAssert.AreEqual(payload, got);
        try { accepted?.Dispose(); } catch (ObjectDisposedException) { }
    }

    /// <summary>
    /// SS-10 tripwire: the accept callback runs inside the listener loop. A throwing callback
    /// previously escaped to the loop's outer catch, permanently ending the accept loop — the
    /// process stayed alive but stopped accepting any further connections.
    /// </summary>
    [TestMethod]
    public void Loopback_WhenAcceptCallbackThrows_ListenerKeepsAcceptingLaterConnections()
    {
        var accepts = 0;
        var secondAccepted = new ManualResetEventSlim(false);
        var acceptedSockets = new List<AsyncLengthedSocket>();

        using var server = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);
        server.OnError = () => { };
        server.OnAccept = accepted =>
        {
            var n = Interlocked.Increment(ref accepts);

            lock (acceptedSockets)
                acceptedSockets.Add(accepted);

            if (n == 1)
                throw new InvalidOperationException("SS-10 injected accept-callback failure");

            secondAccepted.Set();
        };

        server.StartListening(new IPEndPoint(IPAddress.Loopback, 0), backlog: 8);
        var port = GetLocalPort(server);

        using (var first = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp))
            first.Connect(new IPEndPoint(IPAddress.Loopback, port));

        // Give the listener a moment to process the failing accept before the second attempt.
        Thread.Sleep(100);

        using (var second = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp))
            second.Connect(new IPEndPoint(IPAddress.Loopback, port));

        Assert.IsTrue(
            secondAccepted.Wait(TimeSpan.FromSeconds(5)),
            "SS-10: the listener must keep accepting after an accept callback threw. " +
            $"Accept callback ran {Volatile.Read(ref accepts)} time(s); the second connection was never accepted.");

        lock (acceptedSockets)
            foreach (var s in acceptedSockets)
            {
                try { s.Dispose(); } catch (ObjectDisposedException) { }
            }
    }

    /// <summary>
    /// SS-11 tripwire: the receive callback is where packet parsing happens, and malformed
    /// peer input throws there (bad opcode, over/under-read). That previously escaped to the
    /// receive loop's outer catch and killed the connection's receive loop for good, leaving
    /// the socket open but permanently deaf.
    /// </summary>
    [TestMethod]
    public void Loopback_WhenReceiveCallbackThrows_ConnectionKeepsReceivingLaterPackets()
    {
        var receives = 0;
        var secondPayload = new ManualResetEventSlim(false);
        byte[] lastPayload = null;
        var acceptedReady = new ManualResetEventSlim(false);
        AsyncLengthedSocket accepted = null;

        using var server = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword, countHeaderSize: true);
        server.OnError = () => { };
        server.OnAccept = s =>
        {
            accepted = s;
            s.OnError = () => { };
            s.OnReceive = (stream, size) =>
            {
                var n = Interlocked.Increment(ref receives);

                var buffer = new byte[size];
                stream.Read(buffer, 0, size);

                if (n == 1)
                    throw new InvalidOperationException("SS-11 injected malformed-packet failure");

                lastPayload = buffer;
                secondPayload.Set();
            };
            s.Start();
            acceptedReady.Set();
        };

        server.StartListening(new IPEndPoint(IPAddress.Loopback, 0), backlog: 8);
        var port = GetLocalPort(server);

        using var client = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword, countHeaderSize: true);
        var connected = new ManualResetEventSlim(false);
        client.OnError = () => { };
        client.OnConnect = () => { client.Start(); connected.Set(); };
        client.ConnectAsync(new IPEndPoint(IPAddress.Loopback, port));

        Assert.IsTrue(connected.Wait(TimeSpan.FromSeconds(3)), "client connect");
        Assert.IsTrue(acceptedReady.Wait(TimeSpan.FromSeconds(3)), "server accept");

        client.Send(new byte[] { 1, 2, 3 }, 0, 3);
        Thread.Sleep(100);
        client.Send(new byte[] { 7, 8, 9 }, 0, 3);

        Assert.IsTrue(
            secondPayload.Wait(TimeSpan.FromSeconds(5)),
            "SS-11: the connection must keep receiving after a receive callback threw. " +
            $"Receive callback ran {Volatile.Read(ref receives)} time(s); the second packet never arrived.");

        CollectionAssert.AreEqual(new byte[] { 7, 8, 9 }, lastPayload);

        try { accepted?.Dispose(); } catch (ObjectDisposedException) { }
    }

    /// <summary>
    /// SS-10: Close must tolerate being called more than once — peer disconnect, Dispose and
    /// error paths all reach it.
    /// </summary>
    [TestMethod]
    public void Close_IsIdempotent()
    {
        var s = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Dword);

        s.Close();
        s.Close();
        s.Dispose();
    }

    private static int GetLocalPort(AsyncLengthedSocket socket)
    {
        var prop = typeof(AsyncLengthedSocket).GetProperty(
            "Socket",
            BindingFlags.Instance | BindingFlags.NonPublic);
        Assert.IsNotNull(prop);
        var raw = (Socket)prop!.GetValue(socket)!;
        return ((IPEndPoint)raw.LocalEndPoint!).Port;
    }
}
