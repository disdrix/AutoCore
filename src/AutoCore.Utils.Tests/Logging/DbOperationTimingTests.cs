using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class DbOperationTimingTests
{
    private InMemoryLogSink _sink;
    private int _savedThreshold;

    [TestInitialize]
    public void Init()
    {
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        GameLog.MinimumLevel = StructuredLogLevel.Trace;
        _savedThreshold = DbOperationTiming.SlowThresholdMs;
    }

    [TestCleanup]
    public void Cleanup()
    {
        DbOperationTiming.SlowThresholdMs = _savedThreshold;
        GameLog.ResetForTests();
        LogContext.ClearForTests();
    }

    [TestMethod]
    public void Run_FastOp_NoSlowEvent()
    {
        DbOperationTiming.SlowThresholdMs = 250;
        var result = DbOperationTiming.Run("FastOp", () => 42);

        Assert.AreEqual(42, result);
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "DbOperationSlow"));
    }

    [TestMethod]
    public void Run_SlowOp_EmitsDbOperationSlow()
    {
        DbOperationTiming.SlowThresholdMs = 1;
        DbOperationTiming.Run("SlowOp", () =>
        {
            Thread.Sleep(5);
            return true;
        });

        var slow = _sink.Single("DbOperationSlow");
        Assert.AreEqual("DB-002", slow.GetProperty("ErrorCode"));
        Assert.AreEqual("SlowOp", slow.GetProperty("Operation"));
        Assert.IsTrue((long)slow.GetProperty("DurationMs") >= 1);
    }

    [TestMethod]
    public void Run_ThrowingOp_EmitsDbOperationFailed_AndRethrows()
    {
        DbOperationTiming.SlowThresholdMs = 250;
        try
        {
            DbOperationTiming.Run("BoomOp", () => throw new InvalidOperationException("db down"));
            Assert.Fail("expected exception");
        }
        catch (InvalidOperationException)
        {
            // expected
        }

        var failed = _sink.Single("DbOperationFailed");
        Assert.AreEqual("DB-003", failed.GetProperty("ErrorCode"));
        Assert.AreEqual("BoomOp", failed.GetProperty("Operation"));
        Assert.AreEqual("InvalidOperationException", failed.GetProperty("ExceptionType"));
    }
}
