namespace AutoCore.Discord.BugReports;

using AutoCore.Discord.Abstractions;
using AutoCore.Discord.Config;
using AutoCore.Game.Diagnostics;
using AutoCore.Utils;

/// <summary>
/// Uploads player bug-report zips to a configured Discord text channel via the REST API
/// (multipart message + file). Uses the bot token from <see cref="DiscordConfig"/> —
/// never logs the token.
/// </summary>
public sealed class DiscordBugReportUploader : IBugReportUploader
{
    private readonly DiscordConfig _config;
    private readonly IDiscordGateway _gateway;
    private readonly Func<HttpClient> _httpClientFactory;
    private readonly bool _ownsClient;
    private readonly HttpClient? _ownedClient;

    public DiscordBugReportUploader(
        DiscordConfig config,
        IDiscordGateway gateway,
        Func<HttpClient>? httpClientFactory = null)
    {
        _config = config ?? throw new ArgumentNullException(nameof(config));
        _gateway = gateway ?? throw new ArgumentNullException(nameof(gateway));

        if (httpClientFactory != null)
        {
            _httpClientFactory = httpClientFactory;
            _ownsClient = false;
        }
        else
        {
            _ownedClient = new HttpClient { Timeout = TimeSpan.FromSeconds(60) };
            _httpClientFactory = () => _ownedClient;
            _ownsClient = true;
        }
    }

    /// <summary>
    /// True when channel + token are configured. Gateway connectivity is checked at upload
    /// time (bot may still be connecting when Launcher wires the bridge).
    /// </summary>
    public bool IsAvailable =>
        _config.Enabled
        && _config.BugReportChannelId != 0
        && !string.IsNullOrWhiteSpace(_config.BotToken);

    public async Task<BugReportSubmitResult> UploadAsync(
        BugReportPackage package,
        CancellationToken cancellationToken = default)
    {
        if (package == null)
            return BugReportSubmitResult.Fail("Internal error: empty package.");

        if (_config.BugReportChannelId == 0)
            return BugReportSubmitResult.Fail("Bug report channel is not configured.");

        if (string.IsNullOrWhiteSpace(_config.BotToken))
            return BugReportSubmitResult.Fail("Discord bot is not configured.");

        try
        {
            var client = _httpClientFactory();
            using var content = BuildMultipart(package);

            using var request = new HttpRequestMessage(
                HttpMethod.Post,
                $"https://discord.com/api/v10/channels/{_config.BugReportChannelId}/messages");
            // Never log Authorization.
            request.Headers.TryAddWithoutValidation("Authorization", "Bot " + _config.BotToken);
            request.Headers.TryAddWithoutValidation("User-Agent", "AutoCoreBugReport (game-server; 1.0)");
            request.Content = content;

            using var response = await client.SendAsync(request, cancellationToken).ConfigureAwait(false);
            var body = await response.Content.ReadAsStringAsync(cancellationToken).ConfigureAwait(false);

            if (!response.IsSuccessStatusCode)
            {
                Logger.WriteLog(LogType.Warning,
                    "Discord bug-report upload failed status={0} report={1} bodyLen={2}",
                    (int)response.StatusCode,
                    package.ReportId,
                    body?.Length ?? 0);
                return BugReportSubmitResult.Fail(
                    "Failed to deliver bug report to Discord.",
                    $"HTTP {(int)response.StatusCode}");
            }

            return BugReportSubmitResult.Ok();
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, $"Discord bug-report upload {package.ReportId}", ex);
            return BugReportSubmitResult.Fail(
                "Failed to deliver bug report to Discord.",
                ex.GetType().Name);
        }
    }

    internal static MultipartFormDataContent BuildMultipart(BugReportPackage package)
    {
        var content = new MultipartFormDataContent();
        var payload = new StringContent(
            System.Text.Json.JsonSerializer.Serialize(new { content = package.DiscordMessage }),
            System.Text.Encoding.UTF8,
            "application/json");
        content.Add(payload, "payload_json");

        var file = new ByteArrayContent(package.ZipBytes ?? Array.Empty<byte>());
        file.Headers.ContentType = new System.Net.Http.Headers.MediaTypeHeaderValue("application/zip");
        content.Add(file, "files[0]", package.FileName ?? "bugreport.zip");
        return content;
    }

    public void DisposeOwnedClient()
    {
        if (_ownsClient)
            _ownedClient?.Dispose();
    }
}
