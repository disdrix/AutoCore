namespace AutoCore.Game.Managers;

using AutoCore.Database.Char;
using AutoCore.Database.Char.Models;
using AutoCore.Game.Packets.Login;
using AutoCore.Game.TNL;
using AutoCore.Utils;
using AutoCore.Utils.Logging;
using AutoCore.Utils.Memory;
using AutoCore.Utils.Timer;

public class LoginManager : Singleton<LoginManager>
{
    private const int SessionTimeoutCheck = 5000;
    private const int LoginTimoutInMs = 10000;
    private const string SupersedeDisconnectReason = "Superseded by new login";
    private static readonly Func<CharContext> DefaultCreateContext = static () => new CharContext();
    private static readonly Action<TNLConnection, string> DefaultDisconnectSession = static (conn, reason) =>
    {
        try
        {
            conn.Disconnect(reason ?? SupersedeDisconnectReason);
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error,
                $"LoginManager: DisconnectSession failed for session {conn?.SessionId}", ex);
        }
    };

    private Dictionary<uint, GlobalLoginEntry> GlobalLogins { get; } = new();
    private readonly object _sessionsLock = new();
    private readonly Dictionary<uint, HashSet<TNLConnection>> _activeSessions = new();
    private Timer Timer { get; } = new();

    /// <summary>Factory for <see cref="CharContext"/>; overridable in unit tests (InMemory).</summary>
    internal Func<CharContext> CreateContext { get; set; } = DefaultCreateContext;

    /// <summary>
    /// Disconnects a superseded TNL connection. Production uses <see cref="TNLConnection.Disconnect"/>;
    /// tests inject a recorder so no live NetInterface is required.
    /// </summary>
    internal Action<TNLConnection, string> DisconnectSession { get; set; } = DefaultDisconnectSession;

    public LoginManager()
    {
        Timer.Add("LoginSessionExpire", SessionTimeoutCheck, true, () =>
        {
            // SS-23: select AND remove under the same lock. The selection used to enumerate
            // outside it, so a login arriving mid-enumeration threw "Collection was modified"
            // and aborted the whole pass — leaving expired sessions in place, which then makes
            // players who reconnect look like they are already logged in. The window scales
            // with the number of live sessions, so it is effectively invisible in a small test
            // and routine once player count rises.
            lock (GlobalLogins)
            {
                var now = DateTime.Now;

                var toRemove = GlobalLogins
                    .Where(gl => gl.Value.ExpireTime < now)
                    .Select(gl => gl.Key)
                    .ToList();

                foreach (var rem in toRemove)
                {
                    GlobalLogins.Remove(rem);

                    // An expired ticket explains a later "NoTicket" rejection for this account.
                    GameLog.Info("LoginTicketExpired", ("AccountId", rem));
                }
            }
        });
    }

    /// <summary>Clears pending logins / sessions and restores production factories.</summary>
    internal void ResetForTests()
    {
        lock (GlobalLogins)
            GlobalLogins.Clear();

        lock (_sessionsLock)
            _activeSessions.Clear();

        CreateContext = DefaultCreateContext;
        DisconnectSession = DefaultDisconnectSession;
    }

    /// <summary>Marks all pending global logins as expired so the next session-timeout tick removes them.</summary>
    internal void ExpireAllPendingLoginsForTests()
    {
        lock (GlobalLogins)
        {
            foreach (var entry in GlobalLogins.Values)
                entry.ExpireTime = DateTime.Now - TimeSpan.FromMilliseconds(1);
        }
    }

    /// <summary>True when a pending global login entry exists for the account (unit tests).</summary>
    internal bool HasPendingLoginForTests(uint accountId)
    {
        lock (GlobalLogins)
            return GlobalLogins.ContainsKey(accountId);
    }

    /// <summary>True when <paramref name="conn"/> is registered as an active session for the account.</summary>
    internal bool HasActiveSessionForTests(uint accountId, TNLConnection conn)
    {
        lock (_sessionsLock)
            return _activeSessions.TryGetValue(accountId, out var set) && set.Contains(conn);
    }

    /// <summary>Count of registered active sessions for the account (unit tests).</summary>
    internal int GetActiveSessionCountForTests(uint accountId)
    {
        lock (_sessionsLock)
            return _activeSessions.TryGetValue(accountId, out var set) ? set.Count : 0;
    }

    public bool ExpectLoginToGlobal(uint accountId, string username, uint authKey)
    {
        if (string.IsNullOrEmpty(username) || authKey == 0)
        {
            Logger.WriteLog(LogType.Error, $"ExpectLoginToGlobal: Invalid parameters for account {accountId} (username: '{username}', authKey: {authKey})");
            return false;
        }

        var replaced = false;
        lock (GlobalLogins)
        {
            // Single-session reconnect: a new redirect replaces any still-pending ticket
            // instead of rejecting (old clients never consume the stale key).
            replaced = GlobalLogins.ContainsKey(accountId);

            GlobalLogins[accountId] = new GlobalLoginEntry
            {
                ExpireTime = DateTime.Now + TimeSpan.FromMilliseconds(LoginTimoutInMs),
                Username = username,
                AuthKey = authKey
            };
        }

        if (replaced)
        {
            Logger.WriteLog(LogType.Network, $"ExpectLoginToGlobal: Replaced pending login entry for account {accountId} ({username})");
            GameLog.Info("LoginTicketReplaced", ("AccountId", accountId), ("Username", username));
        }
        else
        {
            Logger.WriteLog(LogType.Network, $"ExpectLoginToGlobal: Created login entry for account {accountId} ({username}), expires in {LoginTimoutInMs}ms");
            // NEVER log the auth key itself — it is a one-time credential.
            GameLog.Info("LoginTicketIssued", ("AccountId", accountId), ("Username", username));
        }

        return true;
    }

    public void Update(long delta)
    {
        Timer.Update(delta);
    }

    public bool LoginToGlobal(TNLConnection client, LoginRequestPacket packet)
    {
        lock (GlobalLogins)
        {
            if (!GlobalLogins.TryGetValue(packet.UserId, out var entry))
            {
                Logger.WriteLog(LogType.Error, $"LoginToGlobal: No login entry found for account {packet.UserId} (username: '{packet.Username}')");
                EmitLoginRejected(packet, "NoTicket");
                return false;
            }

            if (entry.AuthKey != packet.AuthKey)
            {
                Logger.WriteLog(LogType.Error, $"LoginToGlobal: AuthKey mismatch for account {packet.UserId}. Expected: {entry.AuthKey}, Got: {packet.AuthKey}");
                GlobalLogins.Remove(packet.UserId);
                EmitLoginRejected(packet, "KeyMismatch");
                return false;
            }

            if (entry.Username != packet.Username)
            {
                Logger.WriteLog(LogType.Error, $"LoginToGlobal: Username mismatch for account {packet.UserId}. Expected: '{entry.Username}', Got: '{packet.Username}'");
                GlobalLogins.Remove(packet.UserId);
                EmitLoginRejected(packet, "UserMismatch");
                return false;
            }

            // Remove the entry after successful validation to prevent reuse
            GlobalLogins.Remove(packet.UserId);
        }

        using var context = CreateContext();
        var account = context.Accounts.FirstOrDefault(a => a.Id == packet.UserId);
        if (account == null)
        {
            account = new Account()
            {
                Id = packet.UserId,
                Name = packet.Username,
                Level = 0,
                FirstFlags1 = 0,
                FirstFlags2 = 0,
                FirstFlags3 = 0,
                FirstFlags4 = 0
            };

            context.Accounts.Add(account);
            context.SaveChanges();
        }

        client.Account = account;

        // Single-session: kick every older Global/Sector connection for this account, then register.
        KickOtherSessions(account.Id, client, SupersedeDisconnectReason);
        RegisterSession(client);

        Logger.WriteLog(LogType.Network, $"LoginToGlobal: Successfully authenticated account {packet.UserId} ({packet.Username})");

        GameLog.Info("GlobalLoginSucceeded",
            ("AccountId", packet.UserId),
            ("SessionId", client.SessionId));
        return true;
    }

    /// <summary>Rejection event with a specific reason. NEVER logs the auth key value.</summary>
    private static void EmitLoginRejected(LoginRequestPacket packet, string reason)
    {
        GameLog.Warn("GlobalLoginRejected", "AUTH-002",
            ("Reason", reason),
            ("AccountId", packet.UserId),
            ("Username", packet.Username));
    }

    public bool LoginToSector(TNLConnection client, uint accountId)
    {
        // TODO: have some communicator register logins that will be incoming
        // and validate the current login against it

        using var context = CreateContext();
        var account = context.Accounts.FirstOrDefault(a => a.Id == accountId);
        if (account == null)
        {
            account = new Account()
            {
                Id = accountId,
                Name = "",
                Level = 10,
                FirstFlags1 = 0,
                FirstFlags2 = 0,
                FirstFlags3 = 0,
                FirstFlags4 = 0
            };

            context.Accounts.Add(account);
            context.SaveChanges();
        }

        client.Account = account;

        // Register only — do not kick here. A normal client keeps Global and Sector open
        // together; superseding happens on the next LoginToGlobal from another connection.
        RegisterSession(client);

        return true;
    }

    /// <summary>
    /// Records an authenticated TNL connection under its account. Idempotent for the same conn.
    /// </summary>
    internal void RegisterSession(TNLConnection conn)
    {
        if (conn?.Account == null)
            return;

        var accountId = conn.Account.Id;
        lock (_sessionsLock)
        {
            if (!_activeSessions.TryGetValue(accountId, out var set))
            {
                set = new HashSet<TNLConnection>();
                _activeSessions[accountId] = set;
            }

            set.Add(conn);
        }
    }

    /// <summary>
    /// Drops a connection from the active-session registry (disconnect / terminate). Idempotent.
    /// </summary>
    public void UnregisterSession(TNLConnection conn)
    {
        if (conn?.Account == null)
            return;

        var accountId = conn.Account.Id;
        lock (_sessionsLock)
        {
            if (!_activeSessions.TryGetValue(accountId, out var set))
                return;

            set.Remove(conn);
            if (set.Count == 0)
                _activeSessions.Remove(accountId);
        }
    }

    /// <summary>
    /// Disconnects every registered session for <paramref name="accountId"/> except
    /// <paramref name="except"/>. Snapshot under lock; disconnect outside to avoid re-entrancy
    /// with <see cref="UnregisterSession"/> from terminate handlers.
    /// </summary>
    internal void KickOtherSessions(uint accountId, TNLConnection except, string reason)
    {
        List<TNLConnection> toKick;
        lock (_sessionsLock)
        {
            if (!_activeSessions.TryGetValue(accountId, out var set) || set.Count == 0)
                return;

            toKick = set.Where(c => !ReferenceEquals(c, except)).ToList();
            foreach (var old in toKick)
                set.Remove(old);

            if (set.Count == 0)
                _activeSessions.Remove(accountId);
        }

        foreach (var old in toKick)
        {
            GameLog.Info("GameSessionSuperseded",
                ("AccountId", accountId),
                ("OldSessionId", old.SessionId),
                ("NewSessionId", except?.SessionId),
                ("Reason", reason ?? SupersedeDisconnectReason));

            DisconnectSession(old, reason ?? SupersedeDisconnectReason);
        }
    }

    private class GlobalLoginEntry
    {
        public DateTime ExpireTime { get; set; }
        public string Username { get; set; }
        public uint AuthKey { get; set; }
    }
}
