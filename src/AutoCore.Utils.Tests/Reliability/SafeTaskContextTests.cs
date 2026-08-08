using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Reliability;

using AutoCore.Utils;
using AutoCore.Utils.Logging;
using AutoCore.Utils.Reliability;
using AutoCore.Utils.Tests.Logging;

/// <summary>
/// Phase 2 context capture across detached work: SafeTask.FireAndForget must report task
/// faults with the ambient LogContext of the enqueue site, not the (empty) context of the
/// ThreadPool continuation that observes the fault.
/// </summary>
[TestClass]
public class SafeTaskContextTests
{
    private InMemoryLogSink _sink;

    [TestInitialize]
    public void Init()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
    }

    [TestMethod]
    public void FireAndForget_FaultReport_CarriesEnqueueSiteContext()
    {
        using var completed = new ManualResetEventSlim(false);

        using (LogContext.Push(("SessionId", "safetask-session-1")))
        {
            SafeTask.FireAndForget(
                Task.FromException(new InvalidOperationException("boom")),
                "SafeTaskContextTests.failing-op",
                onCompleted: completed.Set);
        }

        Assert.IsTrue(completed.Wait(TimeSpan.FromSeconds(5)),
            "The continuation must run and signal completion.");

        var report = _sink.Records.Single(r =>
            r.EventName == "Legacy" &&
            (r.Message?.Contains("SafeTaskContextTests.failing-op") ?? false));

        Assert.AreEqual("safetask-session-1", report.GetProperty("SessionId"),
            "The fault report must be attributable to the session that enqueued the work, " +
            "even though the continuation runs on a ThreadPool thread with no ambient scope.");
    }

    [TestMethod]
    public void FireAndForget_FaultReport_DoesNotLeakContextIntoCaller()
    {
        using var completed = new ManualResetEventSlim(false);

        using (LogContext.Push(("SessionId", "safetask-session-2")))
        {
            // Already-faulted task → the continuation runs synchronously here, exercising
            // the Restore path on the caller's own thread.
            SafeTask.FireAndForget(
                Task.FromException(new InvalidOperationException("boom")),
                "SafeTaskContextTests.leak-check",
                onCompleted: completed.Set);
        }

        Assert.IsTrue(completed.Wait(TimeSpan.FromSeconds(5)),
            "The continuation must run and signal completion.");
        Assert.AreEqual(0, LogContext.CurrentProperties.Count,
            "After the enqueue scope closes, the caller's ambient context must be empty — " +
            "the Restore used for fault reporting must not leave the captured chain behind.");
    }
}
