using System.Net;
using System.Linq;

namespace AutoCore.Auth.Network;

using AutoCore.Communicator;
using AutoCore.Auth.Config;
using AutoCore.Auth.Data;
using AutoCore.Database.Auth;
using AutoCore.Auth.Packets.Server;
using AutoCore.Utils;
using AutoCore.Utils.Logging;
using AutoCore.Utils.Networking;
using AutoCore.Utils.Reliability;
using AutoCore.Utils.Server;
using AutoCore.Utils.Threading;
using AutoCore.Utils.Timer;

public partial class AuthServer : BaseServer, ILoopable
{
    public const int MainLoopTime = 100; // Milliseconds

    private List<AuthClient> ClientsToRemove { get; } = new();

    public AuthConfig Config { get; private set; } = new();
    public Communicator Communicator { get; } = new(CommunicatorType.Server);
    public AsyncLengthedSocket ListenerSocket { get; }
    public List<AuthClient> Clients { get; } = new();
    public Dictionary<byte, ServerInfo> Servers { get; } = new();
    public MainLoop Loop { get; }
    public Timer Timer { get; }
    public override bool IsRunning => Loop != null && Loop.Running;

    public AuthServer()
        : base("Auth")
    {
        Logger.WriteLog(LogType.Initialize, "Initializing the Auth server...");

        Loop = new MainLoop(this, MainLoopTime);
        Timer = new Timer();
        ListenerSocket = new AsyncLengthedSocket(AsyncLengthedSocket.HeaderSizeType.Word);

        RegisterConsoleCommands();

        Logger.WriteLog(LogType.Initialize, "The Auth server has been initialized!");
    }

    /// <summary>
    /// SS-16: a finalizer runs on the GC finalizer thread, where an escaping exception is
    /// <b>uncatchable and terminates the process</b>. Shutdown() closes sockets and stops the
    /// main loop, any of which can throw during teardown, so it is isolated here.
    /// Explicit <see cref="Shutdown"/> from the exit handler remains the normal path.
    /// </summary>
    ~AuthServer() => Guard.Run("AuthServer finalizer shutdown", Shutdown);

    public void Setup(AuthConfig? config)
    {
        if (config != null)
            Config = config;

        SetupServerList();
    }

    /// <summary>Validates port configuration without binding sockets (unit-testable).</summary>
    public static bool ValidateConfig(AuthConfig config) =>
        config.AuthSocketPort != 0 && config.CommunicatorPort != 0;

    public bool Start()
    {
        // Check the configuration
        if (!ValidateConfig(Config))
        {
            Logger.WriteLog(LogType.Error, "Invalid config values!");
            return false;
        }

        StartListening();
        StartCommunicator();

        // Start the main loop
        Loop.Start();

        // TODO: Set up timed events (query stuff, internal communication, etc...)

        return true;
    }

    public void Disconnect(AuthClient client)
    {
        lock (ClientsToRemove)
            ClientsToRemove.Add(client);
    }

    /// <summary>
    /// Single-session Auth: when <paramref name="except"/> logs in, every other live Auth
    /// client bound to the same account is told <see cref="AccountKickedPacket"/> and closed.
    /// </summary>
    public void KickOtherSessions(uint accountId, AuthClient except)
    {
        List<AuthClient> toKick;
        lock (Clients)
        {
            toKick = Clients
                .Where(c =>
                    !ReferenceEquals(c, except)
                    && c.State != ClientState.Disconnected
                    && c.Account != null
                    && c.Account.Id == accountId)
                .ToList();
        }

        foreach (var old in toKick)
        {
            try
            {
                old.SendPacket(new AccountKickedPacket((byte)FailReason.Kicked));
            }
            catch (Exception ex)
            {
                Logger.WriteException(LogType.Error,
                    $"KickOtherSessions: failed to send AccountKicked for account {accountId}", ex);
            }

            GameLog.Info("AuthSessionSuperseded",
                ("AccountId", accountId),
                ("OldSessionId", old.SessionId),
                ("NewSessionId", except.SessionId));

            old.Close();
        }
    }

    /// <summary>Factory for Auth DB access during Setup; override in unit tests.</summary>
    internal static Func<AuthContext> CreateAuthContext { get; set; } = static () => new AuthContext();

    internal void SetupServerList()
    {
        using var context = CreateAuthContext();

        // If no servers exist in the database, create a default server slot
        if (!context.GlobalServers.Any())
        {
            Logger.WriteLog(LogType.Initialize, "No server slots found in database. Creating default server slot (ID: 1, Password: test)...");
            
            context.GlobalServers.Add(new()
            {
                Id = 1,
                Password = "test",
                Enabled = true
            });
            
            context.SaveChanges();
            Logger.WriteLog(LogType.Initialize, "Default server slot created successfully.");
        }

        // TODO: if new server -> add
        // if update server -> change PW maybe? then DC communicator for it to retry connecting with new password?
        // if remove server -> remove and DC active communicator

        foreach (var globalServer in context.GlobalServers.Where(s => s.Enabled))
        {
            if (Servers.TryGetValue(globalServer.Id, out var server))
            {
                server.Password = globalServer.Password;
            }
            else
            {
                Servers.Add(globalServer.Id, new()
                {
                    ServerId = globalServer.Id,
                    Password = globalServer.Password
                });
            }
        }
    }

    public void Shutdown()
    {
        ListenerSocket.Close();

        if (Loop.Running)
            Loop.Stop();
    }

    public void MainLoop(long delta)
    {
        Communicator.Update();
        Timer.Update(delta);

        if (Clients.Count == 0)
            return;

        lock (Clients)
        {
            foreach (var c in Clients)
                c.Update(delta);

            if (ClientsToRemove.Count > 0)
            {
                lock (ClientsToRemove)
                {
                    foreach (var client in ClientsToRemove)
                        Clients.Remove(client);

                    ClientsToRemove.Clear();
                }
            }
        }
    }

    public void BroadcastServerList()
    {
        lock (Clients)
        {
            foreach (var c in Clients)
                if (c.State == ClientState.ServerList)
                    c.SendPacket(new SendServerListExtPacket(Servers.Values.Where(s => s.Ip != IPAddress.Any), c.Account!.LastServerId));
        }
    }
}
