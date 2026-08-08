using AutoCore.Game.Experience;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Experience;

/// <summary>
/// SS-22: every experience/credit lookup used to swallow asset failures with a bare
/// <c>catch</c> commented "Asset manager not initialized in unit tests", then quietly return a
/// built-in retail approximation. In production that converts an asset problem into silently
/// wrong XP, credits and quest rewards — invisible until someone audits the numbers, by which
/// point the character database is already wrong.
/// <para>
/// The fallback itself is correct behaviour (the server stays playable). Being silent was not.
/// </para>
/// </summary>
[TestClass]
public class ExperienceFallbackVisibilityTests
{
    private ExperienceService _svc = null!;

    [TestInitialize]
    public void Init()
    {
        _svc = ExperienceService.Instance;
        _svc.ResetForTests();
        ExperienceService.ResetFallbackTrackingForTests();
    }

    [TestCleanup]
    public void Cleanup()
    {
        _svc.ResetForTests();
        ExperienceService.ResetFallbackTrackingForTests();
    }

    /// <summary>
    /// With no injected resolver and no loaded assets, the threshold lookup degrades to the
    /// built-in table — and that degradation must be counted, not silent.
    /// </summary>
    [TestMethod]
    public void GetThreshold_WhenAssetsUnavailable_ReturnsFallback_AndRecordsTheDegradation()
    {
        var value = _svc.GetThreshold(5);

        Assert.AreEqual(
            ExperienceService.DefaultRetailThreshold(5),
            value,
            "The fallback must still return a usable threshold so the server stays playable.");

        Assert.IsTrue(
            ExperienceService.FallbackCount > 0,
            "SS-22: falling back to the built-in retail table must be recorded so an operator " +
            "can tell that awarded XP is being computed from approximations.");
    }

    [TestMethod]
    public void GetCreatureXp_WhenAssetsUnavailable_RecordsTheDegradation()
    {
        _svc.GetCreatureXp(10);

        Assert.IsTrue(ExperienceService.FallbackCount > 0);
    }

    [TestMethod]
    public void GetQuestBaseCredits_WhenAssetsUnavailable_RecordsTheDegradation()
    {
        _svc.GetQuestBaseCredits(10);

        Assert.IsTrue(ExperienceService.FallbackCount > 0);
    }

    /// <summary>
    /// An injected resolver is the healthy path: it must short-circuit before the asset lookup
    /// and therefore must NOT be reported as a fallback, or the signal becomes noise.
    /// </summary>
    [TestMethod]
    public void GetThreshold_WithInjectedResolver_IsNotCountedAsFallback()
    {
        _svc.ResolveThreshold = level => 12345u;

        var value = _svc.GetThreshold(5);

        Assert.AreEqual(12345u, value);
        Assert.AreEqual(
            0,
            ExperienceService.FallbackCount,
            "A configured resolver is the healthy path and must not be reported as degradation.");
    }

    /// <summary>
    /// The counter must keep accumulating across calls so an operator can see how much of the
    /// session's progression was computed from fallback data.
    /// </summary>
    [TestMethod]
    public void FallbackCount_AccumulatesAcrossLookups()
    {
        _svc.GetThreshold(5);
        var afterFirst = ExperienceService.FallbackCount;

        _svc.GetCreatureXp(10);
        _svc.GetQuestFrac(0);

        Assert.IsTrue(
            ExperienceService.FallbackCount > afterFirst,
            "Each degraded lookup must increment the counter.");
    }

    [TestMethod]
    public void ResetFallbackTrackingForTests_ClearsTheCounter()
    {
        _svc.GetThreshold(5);
        Assert.IsTrue(ExperienceService.FallbackCount > 0);

        ExperienceService.ResetFallbackTrackingForTests();

        Assert.AreEqual(0, ExperienceService.FallbackCount);
    }
}
