using AutoCore.Game.Chat;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Chat;

[TestClass]
public class PlayerNameMatcherTests
{
    [TestMethod]
    public void Score_Exact_IsHighest()
    {
        Assert.AreEqual(100, PlayerNameMatcher.Score("Bob", "Bob"));
        Assert.AreEqual(100, PlayerNameMatcher.Score("bob", "BOB"));
    }

    [TestMethod]
    public void Score_StartsWith_BeatsContains()
    {
        Assert.AreEqual(80, PlayerNameMatcher.Score("bo", "Bobby"));
        Assert.AreEqual(60, PlayerNameMatcher.Score("ob", "Bobby"));
        Assert.IsTrue(PlayerNameMatcher.Score("bo", "Bobby") > PlayerNameMatcher.Score("ob", "Bobby"));
    }

    [TestMethod]
    public void Score_NoMatch_IsZero()
    {
        Assert.AreEqual(0, PlayerNameMatcher.Score("zzz", "Alice"));
        Assert.AreEqual(0, PlayerNameMatcher.Score("", "Alice"));
        Assert.AreEqual(0, PlayerNameMatcher.Score("Alice", ""));
    }

    [TestMethod]
    public void Resolve_PrefersExactOverPartial()
    {
        var candidates = new[]
        {
            Cand(1, "x", 10, "Bobby"),   // starts-with / contains only
            Cand(2, "x", 20, "Bob"),     // exact character name
        };

        var result = PlayerNameMatcher.Resolve("Bob", candidates);

        Assert.AreEqual(PlayerNameMatchKind.Unique, result.Kind);
        Assert.AreEqual(2u, result.Best.AccountId);
        Assert.AreEqual(100, result.Best.Score);
    }

    [TestMethod]
    public void Resolve_UniqueContains_Succeeds()
    {
        var candidates = new[]
        {
            Cand(1, "alpha", 10, "HeroOne"),
            Cand(2, "beta", 20, "Other"),
        };

        var result = PlayerNameMatcher.Resolve("ero", candidates);

        Assert.AreEqual(PlayerNameMatchKind.Unique, result.Kind);
        Assert.AreEqual(1u, result.Best.AccountId);
    }

    [TestMethod]
    public void Resolve_AmbiguousTie_ReturnsCandidates()
    {
        // Same best score (starts-with 80) on two different accounts.
        var candidates = new[]
        {
            Cand(1, "x", 10, "AliceA"),
            Cand(2, "y", 20, "AliceB"),
        };

        var result = PlayerNameMatcher.Resolve("Alice", candidates);

        Assert.AreEqual(PlayerNameMatchKind.Ambiguous, result.Kind);
        Assert.AreEqual(2, result.Matches.Count);
    }

    [TestMethod]
    public void Resolve_None_WhenNoMatch()
    {
        var candidates = new[] { Cand(1, "alice", 10, "Alice") };
        var result = PlayerNameMatcher.Resolve("zzz", candidates);
        Assert.AreEqual(PlayerNameMatchKind.None, result.Kind);
    }

    [TestMethod]
    public void Resolve_EmptyQuery_IsNone()
    {
        var candidates = new[] { Cand(1, "alice", 10, "Alice") };
        Assert.AreEqual(PlayerNameMatchKind.None, PlayerNameMatcher.Resolve("  ", candidates).Kind);
        Assert.AreEqual(PlayerNameMatchKind.None, PlayerNameMatcher.Resolve(null!, candidates).Kind);
    }

    [TestMethod]
    public void Resolve_DedupesByAccountId_KeepsBestScore()
    {
        // Same account appears twice (two name fields scored separately upstream as one candidate
        // with best-of fields). Matcher still collapses duplicate account ids.
        var candidates = new[]
        {
            Cand(5, "target", 100, "Other"),
            Cand(5, "x", 100, "target"),
        };

        var result = PlayerNameMatcher.Resolve("target", candidates);

        Assert.AreEqual(PlayerNameMatchKind.Unique, result.Kind);
        Assert.AreEqual(1, result.Matches.Count);
        Assert.AreEqual(5u, result.Best.AccountId);
        Assert.AreEqual(100, result.Best.Score);
    }

    static PlayerNameCandidate Cand(uint acctId, string acctName, long charCoid, string charName)
        => new(acctId, acctName, charCoid, charName);
}
