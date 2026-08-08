using System.Text;
using AutoCore.Database.Auth;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.TNL;
using AutoCore.Utils;
using AutoCore.Utils.Logging;

namespace AutoCore.Game.Chat;

/// <summary>
/// GM moderation: list online players, kick, ban (auth Locked), unban.
/// Online scope is this process only. Ban persists via Auth Account.Locked.
/// </summary>
public sealed class PlayerModerationService
{
    private static readonly Func<AuthContext> DefaultCreateAuthContext = static () => new AuthContext();

    public static PlayerModerationService Instance { get; } = new();

    /// <summary>Factory for short-lived Auth contexts (tests inject InMemory).</summary>
    internal Func<AuthContext> CreateAuthContext { get; set; } = DefaultCreateAuthContext;

    /// <summary>Online players on this process. Tests inject a fixed list.</summary>
    internal Func<IReadOnlyList<OnlinePlayerSnapshot>> ListOnline { get; set; } = DefaultListOnline;

    /// <summary>Disconnect callback. Default uses the snapshot connection when present.</summary>
    internal Action<OnlinePlayerSnapshot, string> Disconnect { get; set; } = DefaultDisconnect;

    internal void ResetForTests()
    {
        CreateAuthContext = DefaultCreateAuthContext;
        ListOnline = DefaultListOnline;
        Disconnect = DefaultDisconnect;
    }

    public string ListPlayers()
    {
        var online = ListOnline() ?? Array.Empty<OnlinePlayerSnapshot>();
        if (online.Count == 0)
            return "No players online.";

        var sb = new StringBuilder();
        sb.Append("Online (").Append(online.Count).Append("):");
        foreach (var p in online.OrderBy(p => p.AccountId).ThenBy(p => p.CharacterCoid))
        {
            sb.AppendLine();
            sb.Append("acct=").Append(p.AccountId)
                .Append(" char=").Append(p.CharacterCoid)
                .Append(" account=").Append(p.AccountName)
                .Append(" character=").Append(p.CharacterName);
        }

        return sb.ToString();
    }

    public string Kick(string query, Character admin)
    {
        if (string.IsNullOrWhiteSpace(query))
            return "Usage: /kick <name>";

        var online = ListOnline() ?? Array.Empty<OnlinePlayerSnapshot>();
        var candidates = online.Select(ToCandidate).ToList();
        var match = PlayerNameMatcher.Resolve(query, candidates);
        if (match.Kind == PlayerNameMatchKind.None)
            return $"No player matching '{query.Trim()}'.";
        if (match.Kind == PlayerNameMatchKind.Ambiguous)
            return FormatAmbiguous(match);

        var best = match.Best;
        // Kick every online character on the matched account for a clean session drop.
        var toKick = online.Where(o => o.AccountId == best.AccountId).ToList();
        foreach (var snap in toKick)
            Disconnect(snap, "Kicked by GM");

        GameLog.Audit("PlayerKicked",
            ("AccountId", best.AccountId),
            ("CharacterId", best.CharacterCoid),
            ("Query", query.Trim()),
            ("AdminAccountId", admin?.OwningConnection?.Account?.Id ?? 0),
            ("AdminCharacterId", admin?.ObjectId.Coid ?? 0L));

        var label = string.IsNullOrEmpty(best.CharacterName)
            ? best.AccountName
            : best.CharacterName;
        return $"Kicked {label} (acct {best.AccountId}).";
    }

    public string Ban(string query, Character admin)
    {
        if (string.IsNullOrWhiteSpace(query))
            return "Usage: /ban <name>";

        var online = ListOnline() ?? Array.Empty<OnlinePlayerSnapshot>();
        var candidates = BuildBanCandidates(online);
        var match = PlayerNameMatcher.Resolve(query, candidates);
        if (match.Kind == PlayerNameMatchKind.None)
            return $"No player matching '{query.Trim()}'.";
        if (match.Kind == PlayerNameMatchKind.Ambiguous)
            return FormatAmbiguous(match);

        var best = match.Best;
        var accountId = best.AccountId;
        if (!TrySetLocked(accountId, locked: true, out var username, out var error))
            return error;

        var onlineOnAccount = online.Where(o => o.AccountId == accountId).ToList();
        var disconnected = onlineOnAccount.Count > 0;
        foreach (var snap in onlineOnAccount)
            Disconnect(snap, "Banned by GM");

        GameLog.Audit("PlayerBanned",
            ("AccountId", accountId),
            ("CharacterId", best.CharacterCoid),
            ("Query", query.Trim()),
            ("OnlineDisconnected", disconnected),
            ("AdminAccountId", admin?.OwningConnection?.Account?.Id ?? 0),
            ("AdminCharacterId", admin?.ObjectId.Coid ?? 0L));

        var name = !string.IsNullOrEmpty(username) ? username : best.AccountName;
        if (disconnected)
            return $"Banned {name} (acct {accountId}) and disconnected.";
        return $"Banned {name} (acct {accountId}).";
    }

    public string Unban(string query, Character admin)
    {
        if (string.IsNullOrWhiteSpace(query))
            return "Usage: /unban <name>";

        List<PlayerNameCandidate> candidates;
        try
        {
            using var ctx = CreateAuthContext();
            candidates = ctx.Accounts
                .AsEnumerable()
                .Select(a => new PlayerNameCandidate(a.Id, a.Username ?? string.Empty, 0, string.Empty))
                .ToList();
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error, "Unban: failed to load auth accounts", ex);
            return "Auth database unavailable.";
        }

        var match = PlayerNameMatcher.Resolve(query, candidates);
        if (match.Kind == PlayerNameMatchKind.None)
            return $"No account matching '{query.Trim()}'.";
        if (match.Kind == PlayerNameMatchKind.Ambiguous)
            return FormatAmbiguous(match);

        var accountId = match.Best.AccountId;
        bool wasLocked;
        string username;
        try
        {
            using var ctx = CreateAuthContext();
            var account = ctx.Accounts.FirstOrDefault(a => a.Id == accountId);
            if (account == null)
                return $"No account matching '{query.Trim()}'.";

            username = account.Username ?? string.Empty;
            wasLocked = account.Locked;
            if (wasLocked)
            {
                account.Locked = false;
                ctx.SaveChanges();
            }
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error, $"Unban: failed for account {accountId}", ex);
            return "Failed to update auth database.";
        }

        if (!wasLocked)
            return $"Account '{username}' (acct {accountId}) is not banned.";

        GameLog.Audit("PlayerUnbanned",
            ("AccountId", accountId),
            ("Query", query.Trim()),
            ("AdminAccountId", admin?.OwningConnection?.Account?.Id ?? 0),
            ("AdminCharacterId", admin?.ObjectId.Coid ?? 0L));

        return $"Unbanned {username} (acct {accountId}).";
    }

    private List<PlayerNameCandidate> BuildBanCandidates(IReadOnlyList<OnlinePlayerSnapshot> online)
    {
        var list = new List<PlayerNameCandidate>();
        var onlineIds = new HashSet<uint>();

        foreach (var o in online)
        {
            onlineIds.Add(o.AccountId);
            list.Add(ToCandidate(o));
        }

        try
        {
            using var ctx = CreateAuthContext();
            foreach (var a in ctx.Accounts)
            {
                // Online rows already cover name matching for connected players; still add
                // auth username so offline accounts and empty sector account names resolve.
                if (onlineIds.Contains(a.Id))
                {
                    // Extra candidate with auth username / no character so account-name match works
                    // even when session Account.Name is empty.
                    list.Add(new PlayerNameCandidate(a.Id, a.Username ?? string.Empty, 0, string.Empty));
                    continue;
                }

                list.Add(new PlayerNameCandidate(a.Id, a.Username ?? string.Empty, 0, string.Empty));
            }
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error, "Ban: failed to load auth accounts for matching", ex);
        }

        return list;
    }

    private bool TrySetLocked(uint accountId, bool locked, out string username, out string error)
    {
        username = string.Empty;
        error = string.Empty;
        try
        {
            using var ctx = CreateAuthContext();
            var account = ctx.Accounts.FirstOrDefault(a => a.Id == accountId);
            if (account == null)
            {
                error = $"Auth account {accountId} not found.";
                return false;
            }

            username = account.Username ?? string.Empty;
            if (account.Locked != locked)
            {
                account.Locked = locked;
                ctx.SaveChanges();
            }

            return true;
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error, $"Ban/Unban: failed to set Locked={locked} for account {accountId}", ex);
            error = "Failed to update auth database.";
            return false;
        }
    }

    private static string FormatAmbiguous(PlayerNameMatchResult match)
    {
        var sb = new StringBuilder("Ambiguous:");
        foreach (var m in match.Matches.Take(8))
        {
            sb.Append(' ')
                .Append(m.AccountId).Append('/').Append(string.IsNullOrEmpty(m.AccountName) ? "?" : m.AccountName)
                .Append(' ')
                .Append(m.CharacterCoid).Append('/').Append(string.IsNullOrEmpty(m.CharacterName) ? "?" : m.CharacterName)
                .Append(';');
        }

        return sb.ToString().TrimEnd(';');
    }

    private static PlayerNameCandidate ToCandidate(OnlinePlayerSnapshot o)
        => new(o.AccountId, o.AccountName, o.CharacterCoid, o.CharacterName);

    private static IReadOnlyList<OnlinePlayerSnapshot> DefaultListOnline()
    {
        var list = new List<OnlinePlayerSnapshot>();
        foreach (var character in ObjectManager.Instance.GetOnlineCharacters())
        {
            var conn = character.OwningConnection;
            if (conn == null)
                continue;

            var acct = conn.Account;
            list.Add(new OnlinePlayerSnapshot(
                acct?.Id ?? character.AccountId,
                acct?.Name ?? string.Empty,
                character.ObjectId.Coid,
                character.Name ?? string.Empty,
                conn));
        }

        return list;
    }

    private static void DefaultDisconnect(OnlinePlayerSnapshot snap, string reason)
    {
        try
        {
            snap.Connection?.Disconnect(reason ?? "Disconnected by GM");
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error,
                $"Kick/Ban disconnect failed for acct {snap.AccountId} char {snap.CharacterCoid}", ex);
        }
    }
}

/// <summary>Process-local online session row for moderation list/kick.</summary>
public sealed class OnlinePlayerSnapshot
{
    public OnlinePlayerSnapshot(
        uint accountId,
        string accountName,
        long characterCoid,
        string characterName,
        TNLConnection connection = null)
    {
        AccountId = accountId;
        AccountName = accountName ?? string.Empty;
        CharacterCoid = characterCoid;
        CharacterName = characterName ?? string.Empty;
        Connection = connection;
    }

    public uint AccountId { get; }
    public string AccountName { get; }
    public long CharacterCoid { get; }
    public string CharacterName { get; }
    public TNLConnection Connection { get; }
}
