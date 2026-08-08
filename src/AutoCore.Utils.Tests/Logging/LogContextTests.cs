using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class LogContextTests
{
    [TestCleanup]
    public void Cleanup()
    {
        // LogContext is ambient (AsyncLocal); make sure no scope leaks between tests.
        LogContext.ClearForTests();
    }

    [TestMethod]
    public void CurrentProperties_WithNoScope_IsEmpty()
    {
        Assert.AreEqual(0, LogContext.CurrentProperties.Count,
            "With no scope pushed there must be no ambient properties.");
    }

    [TestMethod]
    public void Push_MakesPropertiesVisible_UntilDisposed()
    {
        using (LogContext.Push(("SessionId", "s-1"), ("AccountId", 42)))
        {
            var props = ToDictionary(LogContext.CurrentProperties);

            Assert.AreEqual("s-1", props["SessionId"], "Pushed property must be visible inside the scope.");
            Assert.AreEqual(42, props["AccountId"], "All pushed properties must be visible inside the scope.");
        }

        Assert.AreEqual(0, LogContext.CurrentProperties.Count,
            "Disposing the scope must remove its properties.");
    }

    [TestMethod]
    public void Push_Nested_ChildOverridesParentKey_AndParentRestoredOnDispose()
    {
        using (LogContext.Push(("SessionId", "outer"), ("AccountId", 1)))
        {
            using (LogContext.Push(("SessionId", "inner")))
            {
                var props = ToDictionary(LogContext.CurrentProperties);

                Assert.AreEqual("inner", props["SessionId"], "The innermost value for a key must win.");
                Assert.AreEqual(1, props["AccountId"], "Parent-scope properties must still be visible.");
            }

            Assert.AreEqual("outer", ToDictionary(LogContext.CurrentProperties)["SessionId"],
                "Disposing the child scope must restore the parent value.");
        }
    }

    [TestMethod]
    public void Capture_Restore_CarriesContextToAnotherThread()
    {
        // Simulates the queue pattern: capture at enqueue on the game thread,
        // restore inside the worker (a plain Thread — AsyncLocal does not flow there by itself).
        LogContext snapshot;

        using (LogContext.Push(("SessionId", "s-queue"), ("CharacterId", 7L)))
        {
            snapshot = LogContext.Capture();
        }

        Dictionary<string, object> seenOnWorker = null;

        var worker = new Thread(() =>
        {
            using (LogContext.Restore(snapshot))
            {
                seenOnWorker = ToDictionary(LogContext.CurrentProperties);
            }
        });

        worker.Start();
        worker.Join(TimeSpan.FromSeconds(5));

        Assert.IsNotNull(seenOnWorker, "Worker thread must have run to completion.");
        Assert.AreEqual("s-queue", seenOnWorker["SessionId"],
            "Restore must reproduce the captured properties on the worker thread.");
        Assert.AreEqual(7L, seenOnWorker["CharacterId"],
            "Restore must reproduce all captured properties on the worker thread.");
    }

    [TestMethod]
    public async Task Push_FlowsAcrossTaskRun()
    {
        Dictionary<string, object> seenInTask;

        using (LogContext.Push(("SessionId", "s-task")))
        {
            seenInTask = await Task.Run(() => ToDictionary(LogContext.CurrentProperties));
        }

        Assert.AreEqual("s-task", seenInTask["SessionId"],
            "AsyncLocal context must flow into Task.Run so async handlers keep their session identity.");
    }

    [TestMethod]
    public void Restore_NullSnapshot_DoesNotThrow_AndScopeIsEmpty()
    {
        using (LogContext.Restore(null))
        {
            Assert.AreEqual(0, LogContext.CurrentProperties.Count,
                "Restoring a null snapshot must yield an empty ambient context, not a crash.");
        }
    }

    private static Dictionary<string, object> ToDictionary(
        IReadOnlyList<KeyValuePair<string, object>> properties)
    {
        var result = new Dictionary<string, object>();

        foreach (var pair in properties)
            result[pair.Key] = pair.Value;

        return result;
    }
}
