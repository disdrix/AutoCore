namespace AutoCore.Launcher.Bootstrap;

using AutoCore.Database.Auth;
using AutoCore.Discord;
using AutoCore.Discord.BugReports;
using AutoCore.Discord.Config;
using AutoCore.Discord.Services;
using AutoCore.Game.Diagnostics;
using AutoCore.Utils;
using AutoCore.Utils.Reliability;

/// <summary>
/// Launcher host adapter for the optional Discord bot module.
/// </summary>
public sealed class DiscordLauncherServerHost : ILauncherServerHost
{
    private readonly DiscordConfig _config;
    private readonly Func<AuthContext> _authContextFactory;
    private readonly IPlayerCountSource _playerCountSource;
    private DiscordBotService? _service;
    private DiscordBugReportUploader? _bugReportUploader;

    public DiscordLauncherServerHost(
        DiscordConfig config,
        Func<AuthContext> authContextFactory,
        IPlayerCountSource playerCountSource)
    {
        _config = config ?? throw new ArgumentNullException(nameof(config));
        _authContextFactory = authContextFactory ?? throw new ArgumentNullException(nameof(authContextFactory));
        _playerCountSource = playerCountSource ?? throw new ArgumentNullException(nameof(playerCountSource));
    }

    public string Name => "Discord";
    public bool IsStarted { get; private set; }
    public bool IsShutdown { get; private set; }

    public void Setup()
    {
        if (!_config.Enabled)
            return;

        var validation = _config.Validate();
        if (!validation.IsValid)
            throw new InvalidOperationException("Discord configuration is invalid: " + validation.FormatErrors());

        // Existing deployments may predate discord_account_link; EnsureCreated alone will not
        // add tables to an already-created MySQL database.
        AuthContext.EnsureDiscordAccountLinkTable();

        _service = new DiscordBotService(_config, _authContextFactory, _playerCountSource);
    }

    public bool Start()
    {
        if (!_config.Enabled)
        {
            IsStarted = true;
            return true;
        }

        if (_service == null)
            Setup();

        try
        {
            // Block briefly so a hard connect failure surfaces at Start.
            var ok = _service!.StartAsync().GetAwaiter().GetResult();
            IsStarted = ok;
            if (!ok)
            {
                Logger.WriteLog(LogType.Error, "Unable to start the Discord bot module.");
                return false;
            }

            // Wire /reportbug → Discord channel once the bot service is up.
            // Upload availability still requires gateway IsConnected (set on Ready).
            if (_config.BugReportChannelId != 0)
            {
                _bugReportUploader = new DiscordBugReportUploader(_config, _service.Gateway);
                BugReportUploadBridge.Uploader = _bugReportUploader;
                Logger.WriteLog(LogType.Initialize,
                    "Bug report upload wired to Discord channel {0}.", _config.BugReportChannelId);
            }
            else
            {
                Logger.WriteLog(LogType.Initialize,
                    "BugReportChannelId is 0; in-game /reportbug will be unavailable.");
            }

            return true;
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, "Discord host start", ex);
            IsStarted = false;
            return false;
        }
    }

    public void Shutdown()
    {
        BugReportUploadBridge.Clear();
        _bugReportUploader?.DisposeOwnedClient();
        _bugReportUploader = null;

        Guard.Run("Discord host shutdown", () =>
        {
            if (_service != null)
                _service.StopAsync().GetAwaiter().GetResult();
        });

        if (_service != null)
        {
            Guard.Run("Discord host dispose", () =>
                _service.DisposeAsync().AsTask().GetAwaiter().GetResult());
            _service = null;
        }

        IsShutdown = true;
        IsStarted = false;
    }
}
