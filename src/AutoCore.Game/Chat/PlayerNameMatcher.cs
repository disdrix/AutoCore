namespace AutoCore.Game.Chat;

/// <summary>
/// Deterministic fuzzy name matching for GM moderation commands.
/// Scores: exact=100, starts-with=80, contains=60; ties at best score are ambiguous.
/// </summary>
public static class PlayerNameMatcher
{
    public const int ExactScore = 100;
    public const int StartsWithScore = 80;
    public const int ContainsScore = 60;
    public const int MinimumScore = ContainsScore;

    public static int Score(string query, string candidate)
    {
        if (string.IsNullOrWhiteSpace(query) || string.IsNullOrWhiteSpace(candidate))
            return 0;

        var q = query.Trim();
        var c = candidate.Trim();
        if (c.Length == 0)
            return 0;

        if (string.Equals(q, c, StringComparison.OrdinalIgnoreCase))
            return ExactScore;

        if (c.StartsWith(q, StringComparison.OrdinalIgnoreCase))
            return StartsWithScore;

        if (c.IndexOf(q, StringComparison.OrdinalIgnoreCase) >= 0)
            return ContainsScore;

        return 0;
    }

    /// <summary>
    /// Best-of account-name / character-name score for a single candidate row.
    /// </summary>
    public static int BestFieldScore(string query, PlayerNameCandidate candidate)
    {
        if (candidate == null)
            return 0;

        return Math.Max(Score(query, candidate.AccountName), Score(query, candidate.CharacterName));
    }

    public static PlayerNameMatchResult Resolve(string query, IEnumerable<PlayerNameCandidate> candidates)
    {
        if (string.IsNullOrWhiteSpace(query))
            return PlayerNameMatchResult.None();

        // Collapse to best score per account id.
        var bestByAccount = new Dictionary<uint, PlayerNameMatch>();
        foreach (var cand in candidates ?? Array.Empty<PlayerNameCandidate>())
        {
            if (cand == null)
                continue;

            var score = BestFieldScore(query, cand);
            if (score < MinimumScore)
                continue;

            if (!bestByAccount.TryGetValue(cand.AccountId, out var existing) || score > existing.Score)
            {
                bestByAccount[cand.AccountId] = new PlayerNameMatch(
                    cand.AccountId,
                    cand.AccountName ?? string.Empty,
                    cand.CharacterCoid,
                    cand.CharacterName ?? string.Empty,
                    score);
            }
        }

        if (bestByAccount.Count == 0)
            return PlayerNameMatchResult.None();

        var ordered = bestByAccount.Values
            .OrderByDescending(m => m.Score)
            .ThenBy(m => m.AccountId)
            .ToList();

        var topScore = ordered[0].Score;
        var top = ordered.Where(m => m.Score == topScore).ToList();
        if (top.Count == 1)
            return PlayerNameMatchResult.Unique(top[0], ordered);

        return PlayerNameMatchResult.Ambiguous(top);
    }
}

public sealed class PlayerNameCandidate
{
    public PlayerNameCandidate(uint accountId, string accountName, long characterCoid, string characterName)
    {
        AccountId = accountId;
        AccountName = accountName ?? string.Empty;
        CharacterCoid = characterCoid;
        CharacterName = characterName ?? string.Empty;
    }

    public uint AccountId { get; }
    public string AccountName { get; }
    public long CharacterCoid { get; }
    public string CharacterName { get; }
}

public sealed class PlayerNameMatch
{
    public PlayerNameMatch(uint accountId, string accountName, long characterCoid, string characterName, int score)
    {
        AccountId = accountId;
        AccountName = accountName ?? string.Empty;
        CharacterCoid = characterCoid;
        CharacterName = characterName ?? string.Empty;
        Score = score;
    }

    public uint AccountId { get; }
    public string AccountName { get; }
    public long CharacterCoid { get; }
    public string CharacterName { get; }
    public int Score { get; }
}

public enum PlayerNameMatchKind
{
    None = 0,
    Unique = 1,
    Ambiguous = 2,
}

public sealed class PlayerNameMatchResult
{
    private PlayerNameMatchResult(PlayerNameMatchKind kind, PlayerNameMatch best, IReadOnlyList<PlayerNameMatch> matches)
    {
        Kind = kind;
        Best = best;
        Matches = matches;
    }

    public PlayerNameMatchKind Kind { get; }
    public PlayerNameMatch Best { get; }
    public IReadOnlyList<PlayerNameMatch> Matches { get; }

    public static PlayerNameMatchResult None()
        => new(PlayerNameMatchKind.None, null, Array.Empty<PlayerNameMatch>());

    public static PlayerNameMatchResult Unique(PlayerNameMatch best, IReadOnlyList<PlayerNameMatch> all = null)
        => new(PlayerNameMatchKind.Unique, best, all ?? new[] { best });

    public static PlayerNameMatchResult Ambiguous(IReadOnlyList<PlayerNameMatch> matches)
        => new(PlayerNameMatchKind.Ambiguous, null, matches ?? Array.Empty<PlayerNameMatch>());
}
