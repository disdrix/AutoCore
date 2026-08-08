using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class RateLimiterTests
{
    private InMemoryLogSink _sink;

    [TestInitialize]
    public void Init()
    {
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        GameLog.MinimumLevel = StructuredLogLevel.Trace;
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
    }

    [TestMethod]
    public void Allow_SuppressesWarnAfterLimit_EmitsSummaryOnWindowReopen()
    {
        var now = new DateTime(2026, 1, 1, 12, 0, 0, DateTimeKind.Utc);
        var limiter = new RateLimiter(limit: 3, window: TimeSpan.FromSeconds(10), utcNow: () => now);
        GameLog.SetRateLimiterForTests(limiter);

        for (var i = 0; i < 5; i++)
            GameLog.Warn("SpamEvent", "NET-001", ("i", i));

        Assert.AreEqual(3, _sink.Records.Count(r => r.EventName == "SpamEvent"),
            "Only the first Limit WARN events should pass.");

        now = now.AddSeconds(11);
        GameLog.Warn("SpamEvent", "NET-001", ("i", 99));

        var summary = _sink.Records.FirstOrDefault(r => r.EventName == "SpamEventRateLimited");
        Assert.IsNotNull(summary, "Window reopen must emit a suppression summary.");
        Assert.AreEqual(2, summary.GetProperty("Suppressed"));
        Assert.IsTrue(_sink.Records.Count(r => r.EventName == "SpamEvent") >= 4);
    }

    [TestMethod]
    public void Allow_AuditAndFatal_NeverSuppressed()
    {
        var limiter = new RateLimiter(limit: 1, window: TimeSpan.FromSeconds(10));
        GameLog.SetRateLimiterForTests(limiter);

        for (var i = 0; i < 5; i++)
            GameLog.Audit("CurrencyChanged", ("i", i));
        for (var i = 0; i < 5; i++)
            GameLog.Fatal("Catastrophe", "SRV-999", ("i", i));

        Assert.AreEqual(5, _sink.Records.Count(r => r.EventName == "CurrencyChanged"));
        Assert.AreEqual(5, _sink.Records.Count(r => r.EventName == "Catastrophe"));
    }

    [TestMethod]
    public void Allow_InfoAndDebug_NotRateLimited()
    {
        var limiter = new RateLimiter(limit: 1, window: TimeSpan.FromSeconds(10));
        GameLog.SetRateLimiterForTests(limiter);

        for (var i = 0; i < 10; i++)
            GameLog.Info("ChattyInfo", ("i", i));

        Assert.AreEqual(10, _sink.Records.Count(r => r.EventName == "ChattyInfo"));
    }

    [TestMethod]
    public void Allow_LifecycleExempt_NeverSuppressed()
    {
        var limiter = new RateLimiter(limit: 1, window: TimeSpan.FromSeconds(10));
        GameLog.SetRateLimiterForTests(limiter);

        for (var i = 0; i < 5; i++)
            GameLog.Warn("ConnectionAccepted", "NET-000", ("i", i));

        Assert.AreEqual(5, _sink.Records.Count(r => r.EventName == "ConnectionAccepted"));
    }
}
