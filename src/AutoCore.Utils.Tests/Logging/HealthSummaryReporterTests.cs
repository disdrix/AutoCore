using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class HealthSummaryReporterTests
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
    public void Tick_EmitsOnlyAfterInterval()
    {
        var reporter = new HealthSummaryReporter(
            () => new (string, object)[] { ("Sessions", 3) },
            intervalMs: 1000);

        reporter.Tick(400);
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "HealthSummary"));

        reporter.Tick(700);
        var summary = _sink.Single("HealthSummary");
        Assert.AreEqual(3, summary.GetProperty("Sessions"));
        Assert.IsNotNull(summary.GetProperty("BuildVersion"));
        Assert.IsNotNull(summary.GetProperty("WorkingSetBytes"));
    }

    [TestMethod]
    public void EmitNow_AlwaysWrites()
    {
        var reporter = new HealthSummaryReporter(() => Array.Empty<(string, object)>(), intervalMs: 60_000);
        reporter.EmitNow();
        Assert.AreEqual(1, _sink.Records.Count(r => r.EventName == "HealthSummary"));
    }
}
