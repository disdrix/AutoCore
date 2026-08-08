namespace AutoCore.Sector.Dev;

using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
using AutoCore.Game.Chat;
using AutoCore.Game.Constants;
using AutoCore.Game.Inventory;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.TNL;
using AutoCore.Utils;
using AutoCore.Utils.Logging;
using AutoCore.Utils.Reliability;

public sealed class DevControlServer
{
    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        WriteIndented = false
    };

    private readonly Func<TNLInterface> _getInterface;
    private TcpListener _listener;
    private CancellationTokenSource _cts;
    private Task _loopTask;

    public DevControlServer(Func<TNLInterface> getInterface)
    {
        _getInterface = getInterface;
    }

    public bool IsRunning => _listener != null;
    public int Port { get; private set; }

    public void Start(int port)
    {
        if (IsRunning)
            return;

        _cts = new CancellationTokenSource();
        // Port 0 = OS-assigned ephemeral (tests / avoid fixed 27999 conflicts).
        _listener = new TcpListener(IPAddress.Loopback, port);
        _listener.Start();
        Port = ((IPEndPoint)_listener.LocalEndpoint).Port;
        _loopTask = Task.Run(() => AcceptLoop(_cts.Token));

        // SS-17: observe the accept loop. A fault here previously vanished until GC.
        SafeTask.FireAndForget(_loopTask, $"dev control accept loop (port {Port})");

        Logger.WriteLog(LogType.Network, "Dev control API listening on http://127.0.0.1:{0}", Port);
    }

    public void Stop()
    {
        if (!IsRunning)
            return;

        // SS-17: order matters. Cancel and null the listener under a try/finally so a throw
        // from Stop() cannot leave IsRunning permanently true with a dead listener.
        try
        {
            _cts.Cancel();
        }
        catch (ObjectDisposedException)
        {
            // Already torn down.
        }
        finally
        {
            try
            {
                _listener?.Stop();
            }
            catch (SocketException ex)
            {
                Logger.WriteException(LogType.Warning, "stopping dev control listener", ex);
            }

            _listener = null;
        }

        try
        {
            _loopTask?.Wait(TimeSpan.FromSeconds(2));
        }
        catch (AggregateException ex)
        {
            // SS-17: was an empty bare catch, so a faulted accept loop was invisible on shutdown.
            var real = ex.Flatten().InnerExceptions
                .Where(inner => inner is not OperationCanceledException)
                .ToList();

            if (real.Count > 0)
                Logger.WriteException(LogType.Warning, "dev control accept loop shutdown", ex);
        }

        // The loop task may still be unwinding; disposing the CTS underneath it would race.
        _cts = null;
        _loopTask = null;
    }

    private async Task AcceptLoop(CancellationToken token)
    {
        // SS-17: an unconditional `continue` on error spins at 100% CPU when the failure is
        // persistent (for example the process is out of file handles). Back off, and give up
        // after a bounded number of consecutive failures rather than retrying forever.
        var backoff = new BackoffPolicy();

        while (!token.IsCancellationRequested)
        {
            TcpClient client;
            try
            {
                client = await _listener.AcceptTcpClientAsync(token).ConfigureAwait(false);
            }
            catch (OperationCanceledException)
            {
                break;
            }
            catch (ObjectDisposedException)
            {
                break;
            }
            catch (Exception ex)
            {
                if (!backoff.TryRecordFailure(out var delay))
                {
                    Logger.WriteException(LogType.Error,
                        $"dev control accept failed {backoff.MaxConsecutiveFailures} times consecutively; stopping the dev API",
                        ex);
                    break;
                }

                Logger.WriteException(LogType.Warning,
                    $"dev control accept (attempt {backoff.ConsecutiveFailures}/{backoff.MaxConsecutiveFailures}, retrying in {delay.TotalMilliseconds:F0}ms)",
                    ex);

                try
                {
                    await Task.Delay(delay, token).ConfigureAwait(false);
                }
                catch (OperationCanceledException)
                {
                    break;
                }

                continue;
            }

            backoff.Reset();

            // SS-17: per-connection handler, detached deliberately so a slow client cannot
            // block the accept loop. Routed through SafeTask so its failures are observed.
            SafeTask.FireAndForget(
                Task.Run(() => HandleClient(client, token), token),
                "dev control client handler");
        }
    }

    private async Task HandleClient(TcpClient client, CancellationToken token)
    {
        using var _ = client;

        try
        {
            using var stream = client.GetStream();
            var request = await DevHttpRequest.ReadAsync(stream, token).ConfigureAwait(false);
            if (request == null)
                return;

            var response = HandleRequest(request);
            await response.WriteAsync(stream, token).ConfigureAwait(false);
        }
        catch (Exception ex)
        {
            // SS-17: this failure was previously reported ONLY in the HTTP response, so if no
            // client was reading it the error vanished entirely. Log it server-side first.
            Logger.WriteException(LogType.Warning, "dev control request handling", ex);

            try
            {
                using var stream = client.GetStream();
                await DevHttpResponse.Json(500, new { error = ex.Message }).WriteAsync(stream, token).ConfigureAwait(false);
            }
            catch (Exception replyEx)
            {
                // SS-17: was an empty bare catch. The peer is usually just gone; record it at
                // Debug so a genuine write problem is still traceable.
                Logger.WriteLog(LogType.Debug,
                    $"Could not send dev control 500 response: {replyEx.GetType().Name}: {replyEx.Message}");
            }
        }
    }

    /// <summary>Request routing (unit-testable without TCP accept).</summary>
    internal DevHttpResponse HandleRequest(DevHttpRequest request)
    {
        var path = request.Path;

        // Security event: path/method only — never request bodies (may contain chat-command payloads).
        GameLog.Info("DevControlRequest",
            ("Method", request.Method ?? ""),
            ("Path", path ?? ""));

        try
        {
            if (request.Method == "GET" && path == "/health")
                return DevHttpResponse.Json(200, CreateHealthResponse());

            if (request.Method == "GET" && path == "/inventory")
                return DevHttpResponse.Json(200, CreateInventoryResponse(GetSelectedCharacter(request.Query("character"))));

            if (request.Method == "GET" && path == "/inventory-grab-log")
                return DevHttpResponse.Json(200, new { entries = InventoryGrabDebugLog.Snapshot() });

            if (request.Method == "DELETE" && path == "/inventory-grab-log")
            {
                InventoryGrabDebugLog.Clear();
                return DevHttpResponse.Json(200, new { ok = true });
            }

            if (request.Method == "GET" && path == "/inventory-drop-log")
                return DevHttpResponse.Json(200, new { entries = InventoryDropDebugLog.Snapshot() });

            if (request.Method == "DELETE" && path == "/inventory-drop-log")
            {
                InventoryDropDebugLog.Clear();
                return DevHttpResponse.Json(200, new { ok = true });
            }

            if (request.Method == "POST" && path == "/chat-command")
            {
                var commandRequest = JsonSerializer.Deserialize<DevChatCommandRequest>(request.Body, JsonOptions)
                    ?? throw new InvalidOperationException("Invalid chat-command request body.");

                return DevHttpResponse.Json(200, ExecuteCommand(commandRequest));
            }

            return DevHttpResponse.Json(404, new { error = "Unknown dev endpoint." });
        }
        catch (Exception ex)
        {
            // Loopback-only dev API: returning the message is useful and not an exposure risk,
            // but the failure must also be recorded server-side rather than existing only in a
            // response body nobody may read.
            Logger.WriteException(LogType.Warning, $"dev control endpoint {request.Method} {path}", ex);

            return DevHttpResponse.Json(400, new { error = ex.Message });
        }
    }

    /// <summary>Build a request for pure handler unit tests (no socket I/O).</summary>
    internal static DevHttpRequest CreateRequestForTests(string method, string path, string body = null, string query = null)
    {
        var queryMap = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
        if (!string.IsNullOrEmpty(query))
        {
            foreach (var part in query.TrimStart('?').Split('&', StringSplitOptions.RemoveEmptyEntries))
            {
                var kv = part.Split('=', 2);
                queryMap[WebUtility.UrlDecode(kv[0])] =
                    kv.Length == 2 ? WebUtility.UrlDecode(kv[1]) : string.Empty;
            }
        }

        return new DevHttpRequest(method.ToUpperInvariant(), path, queryMap, body ?? string.Empty);
    }

    private object CreateHealthResponse()
    {
        var characters = GetConnectedCharacters()
            .Select(c => new
            {
                c.ConnectionId,
                c.AccountName,
                c.CharacterName,
                c.CharacterCoid,
                inventoryCount = c.Connection.CurrentCharacter.Inventory.Items.Count
            })
            .ToArray();

        return new
        {
            ok = true,
            port = Port,
            connectedCharacters = characters
        };
    }

    private object CreateInventoryResponse(DevConnectedCharacter selected)
    {
        return new
        {
            selected.ConnectionId,
            selected.AccountName,
            selected.CharacterName,
            selected.CharacterCoid,
            items = selected.Connection.CurrentCharacter.Inventory.Items.Select(ToDto).ToArray()
        };
    }

    private object ExecuteCommand(DevChatCommandRequest request)
    {
        if (string.IsNullOrWhiteSpace(request.Command))
            throw new InvalidOperationException("Command is required.");

        var selected = GetSelectedCharacter(request.Character);
        var result = ChatCommandService.Instance.Execute(selected.Connection.CurrentCharacter, request.Command);
        if (!result.Handled)
            throw new InvalidOperationException($"Unsupported dev chat command '{request.Command}'.");

        foreach (var packet in result.Packets)
            selected.Connection.SendGamePacket(packet);

        selected.Connection.SendGamePacket(new BroadcastPacket
        {
            IsGM = false,
            Sender = "System",
            ChatType = ChatType.SystemMessage,
            Message = result.Message
        });

        return new
        {
            selected.ConnectionId,
            selected.AccountName,
            selected.CharacterName,
            selected.CharacterCoid,
            command = request.Command,
            result.Message,
            addedItem = result.AddedItem == null ? null : ToDto(result.AddedItem),
            inventory = selected.Connection.CurrentCharacter.Inventory.Items.Select(ToDto).ToArray()
        };
    }

    private DevConnectedCharacter GetSelectedCharacter(string characterName)
    {
        return DevPlayerSelector.Select(GetConnectedCharacters(), characterName);
    }

    private IReadOnlyList<DevConnectedCharacter> GetConnectedCharacters()
    {
        var tnlInterface = _getInterface();
        if (tnlInterface == null)
            return Array.Empty<DevConnectedCharacter>();

        return tnlInterface.MapConnections
            .Select(kvp => new { kvp.Key, Connection = kvp.Value, Character = kvp.Value.CurrentCharacter })
            .Where(x => x.Connection != null && x.Character != null)
            .Select(x => new DevConnectedCharacter(
                x.Key,
                x.Connection.Account?.Name ?? string.Empty,
                x.Character.Name,
                x.Character.ObjectId.Coid,
                x.Connection))
            .ToArray();
    }

    private static object ToDto(CharacterInventoryItem item)
    {
        return new
        {
            item.Cbid,
            type = item.Type.ToString(),
            item.DisplayName,
            item.Coid,
            x = item.InventoryPositionX,
            y = item.InventoryPositionY,
            item.Quantity
        };
    }

    private sealed class DevChatCommandRequest
    {
        public string Character { get; set; }
        public string Command { get; set; }
    }

    internal sealed class DevHttpRequest
    {
        private readonly Dictionary<string, string> _query;

        internal DevHttpRequest(string method, string path, Dictionary<string, string> query, string body)
        {
            Method = method;
            Path = path;
            _query = query;
            Body = body;
        }

        public string Method { get; }
        public string Path { get; }
        public string Body { get; }

        public string Query(string key)
        {
            return _query.TryGetValue(key, out var value) ? value : null;
        }

        public static async Task<DevHttpRequest> ReadAsync(Stream stream, CancellationToken token)
        {
            var headerBytes = new List<byte>();
            var buffer = new byte[1];
            while (headerBytes.Count < 32 * 1024)
            {
                var read = await stream.ReadAsync(buffer.AsMemory(0, 1), token).ConfigureAwait(false);
                if (read == 0)
                    return null;

                headerBytes.Add(buffer[0]);
                var count = headerBytes.Count;
                if (count >= 4
                    && headerBytes[count - 4] == '\r'
                    && headerBytes[count - 3] == '\n'
                    && headerBytes[count - 2] == '\r'
                    && headerBytes[count - 1] == '\n')
                    break;
            }

            var headerText = Encoding.ASCII.GetString(headerBytes.ToArray());
            var lines = headerText.Split("\r\n", StringSplitOptions.None);
            var requestLine = lines[0].Split(' ', 3);
            if (requestLine.Length < 2)
                return null;

            var contentLength = 0;
            foreach (var line in lines.Skip(1))
            {
                if (line.StartsWith("Content-Length:", StringComparison.OrdinalIgnoreCase))
                    int.TryParse(line["Content-Length:".Length..].Trim(), out contentLength);
            }

            var bodyBytes = new byte[contentLength];
            var offset = 0;
            while (offset < contentLength)
            {
                var read = await stream.ReadAsync(bodyBytes.AsMemory(offset, contentLength - offset), token).ConfigureAwait(false);
                if (read == 0)
                    break;

                offset += read;
            }

            var uri = new Uri("http://localhost" + requestLine[1]);
            var query = uri.Query.TrimStart('?')
                .Split('&', StringSplitOptions.RemoveEmptyEntries)
                .Select(part => part.Split('=', 2))
                .ToDictionary(
                    part => WebUtility.UrlDecode(part[0]),
                    part => part.Length == 2 ? WebUtility.UrlDecode(part[1]) : string.Empty,
                    StringComparer.OrdinalIgnoreCase);

            return new DevHttpRequest(
                requestLine[0].ToUpperInvariant(),
                uri.AbsolutePath,
                query,
                Encoding.UTF8.GetString(bodyBytes, 0, offset));
        }
    }

    internal sealed class DevHttpResponse
    {
        private readonly int _statusCode;
        private readonly string _body;

        private DevHttpResponse(int statusCode, string body)
        {
            _statusCode = statusCode;
            _body = body;
        }

        public int StatusCode => _statusCode;
        public string Body => _body;

        public static DevHttpResponse Json(int statusCode, object body)
        {
            return new DevHttpResponse(statusCode, JsonSerializer.Serialize(body, JsonOptions));
        }

        public async Task WriteAsync(Stream stream, CancellationToken token)
        {
            var bodyBytes = Encoding.UTF8.GetBytes(_body);
            var header = $"HTTP/1.1 {_statusCode} {ReasonPhrase(_statusCode)}\r\nContent-Type: application/json; charset=utf-8\r\nContent-Length: {bodyBytes.Length}\r\nConnection: close\r\n\r\n";
            var headerBytes = Encoding.ASCII.GetBytes(header);
            await stream.WriteAsync(headerBytes.AsMemory(0, headerBytes.Length), token).ConfigureAwait(false);
            await stream.WriteAsync(bodyBytes.AsMemory(0, bodyBytes.Length), token).ConfigureAwait(false);
        }

        private static string ReasonPhrase(int statusCode)
        {
            return statusCode switch
            {
                200 => "OK",
                400 => "Bad Request",
                404 => "Not Found",
                500 => "Internal Server Error",
                _ => "OK"
            };
        }
    }
}
