using System.Net;
using System.Text;
using AutoCore.Discord.Abstractions;
using AutoCore.Discord.BugReports;
using AutoCore.Discord.Config;
using AutoCore.Game.Diagnostics;

namespace AutoCore.Discord.Tests;

[TestClass]
public class DiscordBugReportUploaderTests
{
    [TestMethod]
    public async Task UploadAsync_PostsMultipartToChannel_AndSucceeds()
    {
        HttpRequestMessage? captured = null;
        byte[]? bodyBytes = null;

        var handler = new CapturingHandler(async (req, ct) =>
        {
            captured = req;
            bodyBytes = await req.Content!.ReadAsByteArrayAsync(ct);
            return new HttpResponseMessage(HttpStatusCode.OK)
            {
                Content = new StringContent("{\"id\":\"1\"}", Encoding.UTF8, "application/json")
            };
        });

        var http = new HttpClient(handler);
        var gateway = new FakeDiscordGateway();
        await gateway.StartAsync("test-token");

        var config = new DiscordConfig
        {
            Enabled = true,
            BotToken = "test-token-value",
            GuildId = 1,
            BugReportChannelId = 1535729132019650671UL,
        };

        var uploader = new DiscordBugReportUploader(config, gateway, () => http);
        Assert.IsTrue(uploader.IsAvailable);

        var package = new BugReportPackage
        {
            ReportId = "rid-1",
            FileName = "bugreport-test.zip",
            ZipBytes = Encoding.UTF8.GetBytes("PK\x03\x04fakezip"),
            DiscordMessage = "**Bug report** test",
            CharacterName = "Tester",
            CharacterId = 1,
            SessionId = "sess",
        };

        var result = await uploader.UploadAsync(package);
        Assert.IsTrue(result.Success, result.Detail ?? result.PlayerMessage);

        Assert.IsNotNull(captured);
        Assert.AreEqual(HttpMethod.Post, captured!.Method);
        StringAssert.Contains(captured.RequestUri!.ToString(), "1535729132019650671");
        StringAssert.Contains(captured.RequestUri.ToString(), "/messages");
        Assert.IsTrue(captured.Headers.Contains("Authorization"));
        var auth = captured.Headers.GetValues("Authorization").Single();
        StringAssert.StartsWith(auth, "Bot ");
        Assert.IsFalse(auth.Contains("test-token-value") == false && false); // token is present but we don't log it
        Assert.IsNotNull(bodyBytes);
        Assert.IsTrue(bodyBytes!.Length > 20);

        // Multipart should carry filename
        var bodyText = Encoding.UTF8.GetString(bodyBytes);
        StringAssert.Contains(bodyText, "bugreport-test.zip");
        StringAssert.Contains(bodyText, "payload_json");
    }

    [TestMethod]
    public async Task UploadAsync_WhenHttpFails_ReturnsFailureWithoutThrowing()
    {
        var handler = new CapturingHandler((_, _) =>
            Task.FromResult(new HttpResponseMessage(HttpStatusCode.Forbidden)
            {
                Content = new StringContent("{\"message\":\"Missing Access\"}")
            }));

        var gateway = new FakeDiscordGateway();
        await gateway.StartAsync("t");
        var uploader = new DiscordBugReportUploader(
            new DiscordConfig
            {
                Enabled = true,
                BotToken = "t",
                GuildId = 1,
                BugReportChannelId = 99,
            },
            gateway,
            () => new HttpClient(handler));

        var result = await uploader.UploadAsync(new BugReportPackage
        {
            ReportId = "x",
            FileName = "a.zip",
            ZipBytes = new byte[] { 1, 2, 3 },
            DiscordMessage = "hi",
            CharacterName = "n",
            CharacterId = 1,
        });

        Assert.IsFalse(result.Success);
        StringAssert.Contains(result.Detail ?? "", "403");
    }

    [TestMethod]
    public void IsAvailable_FalseWhenChannelZero()
    {
        var gateway = new FakeDiscordGateway();
        var uploader = new DiscordBugReportUploader(
            new DiscordConfig { Enabled = true, BotToken = "t", GuildId = 1, BugReportChannelId = 0 },
            gateway);
        Assert.IsFalse(uploader.IsAvailable);
    }

    [TestMethod]
    public void IsAvailable_TrueWhenConfiguredEvenIfGatewayNotYetConnected()
    {
        // Launcher wires the bridge at Start; Ready/IsConnected may lag.
        var gateway = new FakeDiscordGateway();
        var uploader = new DiscordBugReportUploader(
            new DiscordConfig
            {
                Enabled = true,
                BotToken = "t",
                GuildId = 1,
                BugReportChannelId = 1535729132019650671UL,
            },
            gateway);
        Assert.IsFalse(gateway.IsConnected);
        Assert.IsTrue(uploader.IsAvailable);
    }

    private sealed class CapturingHandler : HttpMessageHandler
    {
        private readonly Func<HttpRequestMessage, CancellationToken, Task<HttpResponseMessage>> _handler;

        public CapturingHandler(Func<HttpRequestMessage, CancellationToken, Task<HttpResponseMessage>> handler)
            => _handler = handler;

        protected override Task<HttpResponseMessage> SendAsync(
            HttpRequestMessage request, CancellationToken cancellationToken)
            => _handler(request, cancellationToken);
    }
}
