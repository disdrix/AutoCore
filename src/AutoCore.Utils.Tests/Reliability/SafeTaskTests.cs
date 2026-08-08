using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Reliability;

using AutoCore.Utils.Reliability;

[TestClass]
public class SafeTaskTests
{
    /// <summary>
    /// SS-17: a detached task that faults must have its exception observed and logged.
    /// An unobserved fault is invisible until the GC finalizes the Task.
    /// </summary>
    [TestMethod]
    public void FireAndForget_WhenTaskFaults_ObservesAndReportsTheException()
    {
        var reported = new ManualResetEventSlim(false);
        Exception captured = null;

        SafeTask.FireAndForget(
            Task.Run(() => throw new InvalidOperationException("injected detached failure")),
            "unit-test-detached-work",
            onError: ex =>
            {
                captured = ex;
                reported.Set();
            });

        Assert.IsTrue(
            reported.Wait(TimeSpan.FromSeconds(5)),
            "A faulted detached task must report its failure.");

        Assert.IsInstanceOfType(
            captured,
            typeof(InvalidOperationException),
            "The original exception must be unwrapped from the task's AggregateException so " +
            $"its type survives. Got: {captured?.GetType().Name}");
        Assert.AreEqual("injected detached failure", captured.Message);
    }

    [TestMethod]
    public void FireAndForget_WhenTaskFaults_MarksTheTaskObserved()
    {
        var reported = new ManualResetEventSlim(false);
        var task = Task.Run(() => throw new InvalidOperationException("injected detached failure"));

        SafeTask.FireAndForget(task, "unit-test-detached-work", onError: _ => reported.Set());

        Assert.IsTrue(reported.Wait(TimeSpan.FromSeconds(5)));

        // Accessing Exception is what marks a faulted task observed; assert the continuation
        // already did so rather than relying on this read.
        Assert.IsNotNull(task.Exception, "A faulted task must expose its AggregateException.");
    }

    /// <summary>
    /// Cancellation is not a failure and must not be reported as one, or shutdown will
    /// produce a burst of spurious errors.
    /// </summary>
    [TestMethod]
    public void FireAndForget_WhenTaskCancelled_IsNotReportedAsFailure()
    {
        using var cts = new CancellationTokenSource();
        cts.Cancel();

        var errorReported = false;
        var finished = new ManualResetEventSlim(false);

        SafeTask.FireAndForget(
            Task.FromCanceled(cts.Token),
            "unit-test-detached-work",
            onError: _ => errorReported = true,
            onCompleted: () => finished.Set());

        Assert.IsTrue(finished.Wait(TimeSpan.FromSeconds(5)), "The continuation must run.");
        Assert.IsFalse(errorReported, "Cancellation must not be reported through the error sink.");
    }

    [TestMethod]
    public void FireAndForget_WhenTaskSucceeds_ReportsNoError()
    {
        var errorReported = false;
        var finished = new ManualResetEventSlim(false);

        SafeTask.FireAndForget(
            Task.CompletedTask,
            "unit-test-detached-work",
            onError: _ => errorReported = true,
            onCompleted: () => finished.Set());

        Assert.IsTrue(finished.Wait(TimeSpan.FromSeconds(5)));
        Assert.IsFalse(errorReported);
    }

    [TestMethod]
    public void FireAndForget_WithNullTask_DoesNotThrow()
    {
        SafeTask.FireAndForget(null, "unit-test-detached-work", onError: _ => { });
    }

    /// <summary>
    /// The reporting path must not become a second crash source.
    /// </summary>
    [TestMethod]
    public void FireAndForget_WhenErrorSinkThrows_DoesNotFaultTheContinuation()
    {
        var attempted = new ManualResetEventSlim(false);

        SafeTask.FireAndForget(
            Task.Run(() => throw new InvalidOperationException("injected detached failure")),
            "unit-test-detached-work",
            onError: _ =>
            {
                attempted.Set();
                throw new ApplicationException("sink also failed");
            });

        Assert.IsTrue(attempted.Wait(TimeSpan.FromSeconds(5)));

        // Give the continuation a moment to complete; a throwing sink must not leave an
        // unobserved faulted continuation behind.
        Thread.Sleep(100);
    }

    /// <summary>
    /// An AggregateException wrapping several failures must report all of them, not just the first.
    /// </summary>
    [TestMethod]
    public void FireAndForget_WhenTaskHasMultipleFailures_ReportsAll()
    {
        var reported = new List<Exception>();
        var finished = new ManualResetEventSlim(false);

        var failing = Task.WhenAll(
            Task.Run(() => throw new InvalidOperationException("failure-one")),
            Task.Run(() => throw new ApplicationException("failure-two")));

        SafeTask.FireAndForget(
            failing,
            "unit-test-detached-work",
            onError: ex =>
            {
                lock (reported)
                    reported.Add(ex);
            },
            onCompleted: () => finished.Set());

        Assert.IsTrue(finished.Wait(TimeSpan.FromSeconds(5)));

        lock (reported)
        {
            Assert.AreEqual(
                2,
                reported.Count,
                "Task.WhenAll surfaces only the first exception via await; every inner failure " +
                $"must still be reported. Got: {string.Join(", ", reported.Select(e => e.Message))}");
        }
    }
}
