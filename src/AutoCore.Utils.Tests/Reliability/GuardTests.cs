using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Reliability;

using AutoCore.Utils.Reliability;

[TestClass]
public class GuardTests
{
    [TestMethod]
    public void Run_WhenWorkSucceeds_ReturnsTrue()
    {
        var ran = false;

        var ok = Guard.Run("unit-test-operation", () => ran = true, onError: _ => { });

        Assert.IsTrue(ok, "Guard.Run must report success when the work completes.");
        Assert.IsTrue(ran, "The work delegate must actually have been invoked.");
    }

    /// <summary>
    /// The core contract: an unexpected exception is contained, not propagated, so the
    /// caller's loop or boundary survives.
    /// </summary>
    [TestMethod]
    public void Run_WhenWorkThrows_ReturnsFalse_AndDoesNotPropagate()
    {
        var ok = Guard.Run(
            "unit-test-operation",
            () => throw new InvalidOperationException("injected failure"),
            onError: _ => { });

        Assert.IsFalse(ok, "Guard.Run must report failure when the work throws.");
    }

    [TestMethod]
    public void Run_WhenWorkThrows_PassesOriginalExceptionToOnError()
    {
        Exception captured = null;
        var injected = new InvalidOperationException("injected failure");

        Guard.Run("unit-test-operation", () => throw injected, onError: ex => captured = ex);

        Assert.AreSame(
            injected,
            captured,
            "The original exception instance must reach the error sink so its stack trace survives.");
    }

    /// <summary>
    /// A throwing error sink must not defeat the guard — otherwise the recovery path
    /// becomes a second crash source.
    /// </summary>
    [TestMethod]
    public void Run_WhenOnErrorItselfThrows_StillDoesNotPropagate()
    {
        var ok = Guard.Run(
            "unit-test-operation",
            () => throw new InvalidOperationException("injected failure"),
            onError: _ => throw new ApplicationException("sink also failed"));

        Assert.IsFalse(ok, "A failing error sink must still yield a contained failure, not a throw.");
    }

    [TestMethod]
    public void Run_WithNullWork_ReturnsTrue_AndDoesNotThrow()
    {
        Assert.IsTrue(
            Guard.Run("unit-test-operation", null, onError: _ => { }),
            "A null work delegate is a no-op, not a failure.");
    }

    /// <summary>
    /// Cancellation is a control-flow signal, not a fault. It must propagate so the
    /// surrounding loop can stop instead of spinning through cancelled work.
    /// </summary>
    [TestMethod]
    public void Run_WhenCancelled_PropagatesInsteadOfSwallowing()
    {
        Assert.ThrowsException<OperationCanceledException>(
            () => Guard.Run(
                "unit-test-operation",
                () => throw new OperationCanceledException(),
                onError: _ => { }));
    }

    /// <summary>
    /// Continuing after memory exhaustion is not safe; the guard must not pretend to recover.
    /// </summary>
    [TestMethod]
    public void Run_WhenOutOfMemory_PropagatesInsteadOfSwallowing()
    {
        Assert.ThrowsException<OutOfMemoryException>(
            () => Guard.Run(
                "unit-test-operation",
                () => throw new OutOfMemoryException(),
                onError: _ => { }));
    }

    /// <summary>
    /// The canonical long-running-component tripwire: A succeeds, B throws and is reported,
    /// C still succeeds, and the loop is still alive at the end.
    /// </summary>
    [TestMethod]
    public void ForEach_WhenOneItemThrows_LaterItemsStillRun_AndFailureIsReported()
    {
        var processed = new List<string>();
        var failures = new List<(string Item, Exception Error)>();

        var failureCount = Guard.ForEach(
            new[] { "A", "B", "C" },
            "unit-test-item",
            item =>
            {
                if (item == "B")
                    throw new InvalidOperationException("injected failure for B");

                processed.Add(item);
            },
            describe: item => item,
            onError: (item, ex) => failures.Add((item, ex)));

        CollectionAssert.AreEqual(
            new[] { "A", "C" },
            processed,
            "Item C must still be processed after item B threw. One bad unit of work must " +
            "never skip the remaining work.");

        Assert.AreEqual(1, failureCount, "Exactly one item should be reported as failed.");
        Assert.AreEqual(1, failures.Count, "The error sink must be told about item B.");
        Assert.AreEqual("B", failures[0].Item, "The failing item must be identified.");
        Assert.IsInstanceOfType(
            failures[0].Error,
            typeof(InvalidOperationException),
            "The original exception type must be preserved for diagnosis.");
    }

    [TestMethod]
    public void ForEach_WhenAllSucceed_ReturnsZeroFailures()
    {
        var seen = 0;

        var failureCount = Guard.ForEach(
            new[] { 1, 2, 3 },
            "unit-test-item",
            _ => seen++,
            onError: (_, _) => { });

        Assert.AreEqual(0, failureCount);
        Assert.AreEqual(3, seen);
    }

    [TestMethod]
    public void ForEach_WhenEveryItemThrows_CountsEveryFailure_AndStillCompletes()
    {
        var attempted = 0;

        var failureCount = Guard.ForEach(
            new[] { 1, 2, 3 },
            "unit-test-item",
            _ =>
            {
                attempted++;
                throw new InvalidOperationException("always fails");
            },
            onError: (_, _) => { });

        Assert.AreEqual(3, attempted, "Every item must be attempted even when all of them fail.");
        Assert.AreEqual(3, failureCount);
    }

    [TestMethod]
    public void ForEach_WithNullCollection_IsNoOp()
    {
        Assert.AreEqual(
            0,
            Guard.ForEach<string>(null, "unit-test-item", _ => { }, onError: (_, _) => { }),
            "A null collection is a no-op, not a failure.");
    }

    /// <summary>
    /// Cancellation must stop the whole loop rather than being counted once per remaining item.
    /// </summary>
    [TestMethod]
    public void ForEach_WhenItemCancels_StopsLoopAndPropagates()
    {
        var processed = new List<int>();

        Assert.ThrowsException<OperationCanceledException>(() => Guard.ForEach(
            new[] { 1, 2, 3 },
            "unit-test-item",
            item =>
            {
                if (item == 2)
                    throw new OperationCanceledException();

                processed.Add(item);
            },
            onError: (_, _) => { }));

        CollectionAssert.AreEqual(
            new[] { 1 },
            processed,
            "Cancellation must abort the loop; item 3 must not be processed.");
    }
}
