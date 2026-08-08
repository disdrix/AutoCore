using System.Buffers;
using System.Diagnostics;
using System.Net;
using System.Net.Sockets;

namespace AutoCore.Utils.Networking;

using AutoCore.Utils.Memory;
using AutoCore.Utils.Reliability;

public sealed class AsyncLengthedSocket : IDisposable
{
    public enum HeaderSizeType
    {
        Byte = 1,
        Word = 2,
        Dword = 4,
    }

    public const int MaxDataSize = 0x400;

    private Socket Socket { get; }
    private NonContiguousMemoryStream ReceiveStream { get; set; }
    private NonContiguousMemoryStream SendStream { get; set; }
    private Task ListenTask { get; set; }
    private Task ReceiveTask { get; set; }
    private Task SendTask { get; set; }
    private Task ConnectTask { get; set; }
    private SemaphoreSlim SendDelaySemaphore { get; set; }
    private bool Running { get; set; }
    private CancellationTokenSource CloseCancellationTokenSource { get; } = new();
    private HeaderSizeType HeaderSize { get; }
    private bool CountHeaderSize { get; }
    private int HeaderSizeInBytes => (int)HeaderSize;
    private int MaxPacketSize => MaxDataSize + (int)HeaderSize;

    public Action OnError { get; set; }
    public Action OnDisconnect { get; set; }
    public Action OnConnect { get; set; }
    public Action<AsyncLengthedSocket> OnAccept { get; set; }
    public Action<NonContiguousMemoryStream, int> OnReceive { get; set; }

    public EndPoint RemoteAddress => Socket.RemoteEndPoint;
    public bool Connected => Socket.Connected;

    public AsyncLengthedSocket(HeaderSizeType headerSize, bool countHeaderSize = true)
        : this(new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp), headerSize, countHeaderSize)
    {
    }

    public AsyncLengthedSocket(Socket socket, HeaderSizeType headerSize, bool countHeaderSize = true)
    {
        Socket = socket;
        HeaderSize = headerSize;
        CountHeaderSize = countHeaderSize;
    }

    public void StartListening(EndPoint endPoint, int backlog = int.MaxValue)
    {
        ArgumentNullException.ThrowIfNull(endPoint);

        try
        {
            Socket.Bind(endPoint);
            Socket.Listen(backlog);

            ListenTask = DoListen();
            SafeTask.FireAndForget(ListenTask, $"socket listen loop ({Describe(endPoint)})");
        }
        catch (Exception ex) when (ex is SocketException or ObjectDisposedException or InvalidOperationException)
        {
            RaiseError();

            Logger.WriteException(LogType.Error, $"start listening on {Describe(endPoint)}", ex);
        }
    }

    /// <summary>
    /// Accept loop.
    /// <para>
    /// SS-10: previously any error here — including a throwing <see cref="OnAccept"/> callback,
    /// or a client aborting mid-handshake — escaped to a single outer catch that ended the loop
    /// for good. The process stayed alive while silently refusing every subsequent connection.
    /// Now terminal conditions exit cleanly, the accept callback is isolated, and transient
    /// failures back off and retry a bounded number of times before escalating.
    /// </para>
    /// </summary>
    private async Task DoListen()
    {
        Debug.Assert(OnAccept != null, "No callback is set to handle incoming socket connections!");

        var token = CloseCancellationTokenSource.Token;
        var backoff = new BackoffPolicy();

        while (!token.IsCancellationRequested)
        {
            Socket socket;

            try
            {
                socket = await Socket.AcceptAsync(token);
            }
            catch (OperationCanceledException)
            {
                break; // Shutdown; not a failure.
            }
            catch (ObjectDisposedException)
            {
                break; // Listener closed underneath us; nothing left to accept on.
            }
            catch (Exception ex)
            {
                if (!TryBackoff(backoff, ex, $"accept on {DescribeLocal()}", token))
                    break;

                continue;
            }

            backoff.Reset();

            // A throwing accept handler must fail that connection only, never the listener.
            Guard.Run(
                $"accept callback for {Describe(SafeRemoteEndPoint(socket))}",
                () => OnAccept?.Invoke(new AsyncLengthedSocket(socket, HeaderSize)));
        }
    }

    public void Start()
    {
        try
        {
            Running = true;
            ReceiveStream = new();
            SendStream = new();
            SendDelaySemaphore = new(1);

            ReceiveTask = DoReceive();
            SendTask = DoSend();

            // SS-17: these were bare fire-and-forget assignments. Nothing ever observed them,
            // so a fault in either pump was invisible until GC finalized the task.
            SafeTask.FireAndForget(ReceiveTask, $"socket receive loop ({DescribeRemote()})");
            SafeTask.FireAndForget(SendTask, $"socket send loop ({DescribeRemote()})");
        }
        catch (Exception ex) when (ex is SocketException or ObjectDisposedException or InvalidOperationException)
        {
            RaiseError();

            Logger.WriteException(LogType.Error, $"start communicating on {DescribeRemote()}", ex);
        }
    }

    public void ConnectAsync(EndPoint remote)
    {
        try
        {
            ConnectTask = DoConnect(remote);
            SafeTask.FireAndForget(ConnectTask, $"socket connect ({Describe(remote)})");
        }
        catch (Exception ex) when (ex is SocketException or ObjectDisposedException or InvalidOperationException)
        {
            RaiseError();

            Logger.WriteException(LogType.Error, $"connect to {Describe(remote)}", ex);
        }
    }

    public void Send(byte[] data, int offset, int count)
    {
        Debug.Assert(SendStream != null, "The socket must be started before sending data to it!");
        Debug.Assert(SendDelaySemaphore != null, "The socket must be started before sending data to it!");

        var sizeToWrite = count;
        if (CountHeaderSize)
            sizeToWrite += HeaderSizeInBytes;

        var sizeHolder = ArrayPool<byte>.Shared.Rent(HeaderSizeInBytes);

        try
        {
            BitConverter.TryWriteBytes(sizeHolder, sizeToWrite);

            SendStream.Write(sizeHolder, 0, HeaderSizeInBytes);
            SendStream.Write(data, offset, count);
        }
        finally
        {
            ArrayPool<byte>.Shared.Return(sizeHolder);
        }

        SendDelaySemaphore.Release();
    }

    private async Task DoConnect(EndPoint remote)
    {
        try
        {
            await Socket.ConnectAsync(remote, CloseCancellationTokenSource.Token);
        }
        catch (OperationCanceledException)
        {
            return; // Shutdown during connect; not a failure.
        }
        catch (Exception ex) when (ex is SocketException or ObjectDisposedException)
        {
            RaiseError();

            Logger.WriteException(LogType.Warning, $"connect to {Describe(remote)}", ex);
            return;
        }

        // Isolated separately: a throwing OnConnect handler is a consumer bug, not a
        // connection failure, and must not be reported as one.
        Guard.Run($"connect callback for {Describe(remote)}", () => OnConnect?.Invoke());
    }

    /// <summary>
    /// Receive/framing loop.
    /// <para>
    /// SS-11: <see cref="OnReceive"/> is where packet parsing happens, so malformed peer input
    /// throws here (unknown opcode, over/under-read). That previously escaped to a single outer
    /// catch which ended the receive loop permanently — the socket stayed open but the
    /// connection was deaf forever. Now the handler is isolated per packet, and the packet is
    /// always consumed so a malformed one cannot be re-parsed in a hot loop.
    /// </para>
    /// </summary>
    private async Task DoReceive()
    {
        var receiveBuffer = ArrayPool<byte>.Shared.Rent(MaxPacketSize);
        var token = CloseCancellationTokenSource.Token;

        try
        {
            while (Running && !token.IsCancellationRequested)
            {
                int received;

                try
                {
                    received = await Socket.ReceiveAsync(receiveBuffer, token);
                }
                catch (OperationCanceledException)
                {
                    break;
                }
                catch (Exception ex) when (ex is SocketException or ObjectDisposedException)
                {
                    // Peer reset or local teardown: the connection is gone, not retryable.
                    Logger.WriteLog(LogType.Debug,
                        $"Receive ended on {DescribeRemote()}: {ex.GetType().Name}: {ex.Message}");

                    RaiseDisconnect();
                    Close();
                    return;
                }

                if (received == 0)
                {
                    RaiseDisconnect();

                    Close();
                    return;
                }

                ReceiveStream.Write(receiveBuffer, 0, received);

                DrainCompletePackets();
            }
        }
        finally
        {
            ArrayPool<byte>.Shared.Return(receiveBuffer);
        }
    }

    /// <summary>
    /// Dispatches every whole packet currently buffered.
    /// <para>
    /// Loops rather than handling one packet per receive: a single TCP read can carry several
    /// packets, and the original code only ever dispatched the first, leaving the rest stalled
    /// until more bytes happened to arrive.
    /// </para>
    /// </summary>
    private void DrainCompletePackets()
    {
        while (true)
        {
            var dataSize = PeekIncomingPacketDataSize();

            if (dataSize == -1)
                return; // Header not yet complete.

            // SS-11: the length prefix is attacker-controlled. A negative or oversized value
            // would corrupt the stream bookkeeping (RemoveBytes with a negative count) or let a
            // peer claim an unbounded payload. Framing cannot be resynchronised after a bad
            // length, so the connection is dropped rather than guessed at.
            if (dataSize < 0 || dataSize > MaxDataSize)
            {
                Logger.WriteLog(LogType.Warning,
                    $"Dropping connection {DescribeRemote()}: declared packet size {dataSize} is outside 0..{MaxDataSize}.");

                RaiseError();
                Close();
                return;
            }

            if (ReceiveStream.AvailableBytesToRead < dataSize + HeaderSizeInBytes)
                return; // Body not yet complete.

            ReceiveStream.RemoveBytes(HeaderSizeInBytes);

            try
            {
                Guard.Run(
                    $"packet handler ({DescribeRemote()}, {dataSize} bytes)",
                    () => OnReceive?.Invoke(ReceiveStream, dataSize));
            }
            finally
            {
                // Always consume the packet — including when the handler threw or read only
                // part of it. Otherwise the same malformed packet is re-parsed forever.
                ReceiveStream.RemoveBytes(dataSize);
            }
        }
    }

    private int PeekIncomingPacketDataSize()
    {
        if (ReceiveStream.AvailableBytesToRead < HeaderSizeInBytes)
            return -1;

        var readPosition = ReceiveStream.Position;
        var sizeHolder = ArrayPool<byte>.Shared.Rent(HeaderSizeInBytes);

        try
        {
            // CA2022: Stream.Read may return fewer bytes than requested. NonContiguousMemoryStream
            // is an in-memory buffer and the caller already checked AvailableBytesToRead, so a
            // short read here means the stream's invariant broke — assert it rather than
            // silently decoding a partial header.
            var headerRead = ReceiveStream.Read(sizeHolder, 0, HeaderSizeInBytes);
            if (headerRead != HeaderSizeInBytes)
            {
                Logger.WriteLog(LogType.Warning,
                    $"Short header read on {DescribeRemote()}: wanted {HeaderSizeInBytes} bytes, got {headerRead}.");
                return -1;
            }

            var packetSize = HeaderSize switch
            {
                HeaderSizeType.Byte => sizeHolder[0],
                HeaderSizeType.Word => BitConverter.ToInt16(sizeHolder, 0),
                HeaderSizeType.Dword => BitConverter.ToInt32(sizeHolder, 0),
                _ => throw new Exception($"Unknown HeaderSizeType: {HeaderSize}!")
            };

            if (CountHeaderSize)
                packetSize -= HeaderSizeInBytes;

            return packetSize;
        }
        finally
        {
            ReceiveStream.Position = readPosition;

            ArrayPool<byte>.Shared.Return(sizeHolder);
        }
    }

    private async Task DoSend()
    {
        var sendBuffer = ArrayPool<byte>.Shared.Rent(MaxPacketSize);
        var token = CloseCancellationTokenSource.Token;

        try
        {
            while (Running && !token.IsCancellationRequested)
            {
                if (SendStream.AvailableBytesToRead > 0)
                {
                    var sizeToSend = Math.Min(MaxPacketSize, SendStream.AvailableBytesToRead);

                    // CA2022: never send more than was actually read — a short read would
                    // otherwise transmit stale pooled-buffer bytes to the peer.
                    sizeToSend = SendStream.Read(sendBuffer, 0, sizeToSend);

                    if (sizeToSend <= 0)
                        continue;

                    int sentBytes;

                    try
                    {
                        sentBytes = await Socket.SendAsync(new ArraySegment<byte>(sendBuffer, 0, sizeToSend), token);
                    }
                    catch (OperationCanceledException)
                    {
                        break;
                    }
                    catch (Exception ex) when (ex is SocketException or ObjectDisposedException)
                    {
                        Logger.WriteLog(LogType.Debug,
                            $"Send ended on {DescribeRemote()}: {ex.GetType().Name}: {ex.Message}");

                        RaiseError();
                        Close();
                        return;
                    }

                    if (sentBytes == 0)
                    {
                        RaiseError();

                        Close();
                        return;
                    }

                    SendStream.RemoveBytes(sentBytes);
                }
                else
                {
                    try
                    {
                        await SendDelaySemaphore.WaitAsync(token);
                    }
                    catch (OperationCanceledException)
                    {
                        // SS-10: this catch used to be empty. With Running still true that is
                        // an unbounded hot spin on a cancelled token; break out instead.
                        break;
                    }
                    catch (ObjectDisposedException)
                    {
                        break;
                    }
                }
            }
        }
        finally
        {
            ArrayPool<byte>.Shared.Return(sendBuffer);
        }
    }

    private int _closed;

    public void Close()
    {
        // Idempotent: peer disconnect, Dispose, and error paths may all call Close.
        if (Interlocked.Exchange(ref _closed, 1) != 0)
            return;

        Running = false;

        try
        {
            CloseCancellationTokenSource.Cancel();
        }
        catch (ObjectDisposedException)
        {
            // Already torn down; cancellation is moot.
        }
        catch (AggregateException ex)
        {
            // Cancel() surfaces exceptions thrown by callbacks registered on the token.
            Logger.WriteException(LogType.Warning, $"cancelling socket operations for {DescribeRemote()}", ex);
        }

        // SS-10: the CTS is deliberately NOT disposed here. The receive/send/listen loops may
        // still be awaiting on its token, and disposing underneath them raced into
        // ObjectDisposedException on a shutdown path. A CTS with no timer or linked
        // registrations holds no unmanaged resources, so letting the GC reclaim it is safe.

        try
        {
            Socket.Close();
        }
        catch (Exception ex) when (ex is SocketException or ObjectDisposedException)
        {
            // Was already closed or never opened; nothing further to release.
            Logger.WriteLog(LogType.Debug, $"Socket close: {ex.GetType().Name}: {ex.Message}");
        }

        ReceiveStream?.Dispose();
        SendStream?.Dispose();
    }

    public void Dispose() => Close();

    /// <summary>
    /// Applies the backoff policy to a transient loop failure.
    /// </summary>
    /// <returns><c>false</c> when the loop must stop: either the retry budget is exhausted or
    /// shutdown was requested during the delay.</returns>
    private bool TryBackoff(BackoffPolicy backoff, Exception ex, string operation, CancellationToken token)
    {
        if (!backoff.TryRecordFailure(out var delay))
        {
            Logger.WriteException(LogType.Fatal,
                $"{operation} failed {backoff.MaxConsecutiveFailures} times consecutively; giving up",
                ex);

            RaiseError();
            return false;
        }

        Logger.WriteException(LogType.Warning,
            $"{operation} (attempt {backoff.ConsecutiveFailures}/{backoff.MaxConsecutiveFailures}, retrying in {delay.TotalMilliseconds:F0}ms)",
            ex);

        try
        {
            Task.Delay(delay, token).GetAwaiter().GetResult();
        }
        catch (OperationCanceledException)
        {
            return false;
        }

        return true;
    }

    private void RaiseError() => Guard.Run($"OnError callback ({DescribeRemote()})", () => OnError?.Invoke());

    private void RaiseDisconnect() =>
        Guard.Run($"OnDisconnect callback ({DescribeRemote()})", () => OnDisconnect?.Invoke());

    /// <summary>Endpoint description for diagnostics; never throws on a closed socket.</summary>
    private string DescribeRemote() => Describe(SafeRemoteEndPoint(Socket));

    private string DescribeLocal()
    {
        try
        {
            return Describe(Socket.LocalEndPoint);
        }
        catch (Exception ex) when (ex is SocketException or ObjectDisposedException)
        {
            return "<unavailable>";
        }
    }

    private static EndPoint SafeRemoteEndPoint(Socket socket)
    {
        try
        {
            return socket?.RemoteEndPoint;
        }
        catch (Exception ex) when (ex is SocketException or ObjectDisposedException)
        {
            return null;
        }
    }

    private static string Describe(EndPoint endPoint) => endPoint?.ToString() ?? "<unknown endpoint>";
}