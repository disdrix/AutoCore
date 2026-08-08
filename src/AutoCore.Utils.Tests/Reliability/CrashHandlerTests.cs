using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Reliability;

using AutoCore.Utils.Reliability;

[TestClass]
public class CrashHandlerTests
{
    [TestCleanup]
    public void Cleanup()
    {
        // Never leave process-global hooks registered by a test.
        CrashHandler.Uninstall();
    }

    /// <summary>
    /// SS-07: the Launcher hosts Auth, Global and Sector in one process, so registration
    /// must be safe to attempt more than once.
    /// </summary>
    [TestMethod]
    public void Install_IsIdempotent()
    {
        Assert.IsTrue(CrashHandler.Install("Sector"), "First install should register the hooks.");
        Assert.IsFalse(CrashHandler.Install("Sector"), "A second install must be ignored.");
        Assert.AreEqual("Sector", CrashHandler.Subsystem);
    }

    [TestMethod]
    public void Install_WithBlankSubsystem_FallsBackToUnknown()
    {
        CrashHandler.Install("   ");
        Assert.AreEqual("Unknown", CrashHandler.Subsystem);
    }

    /// <summary>
    /// The report is the entire value of this layer — if it lacks context it is useless.
    /// </summary>
    [TestMethod]
    public void DescribeCrash_IncludesSubsystemThreadTimestampAndFullExceptionChain()
    {
        Exception captured;

        try
        {
            try
            {
                throw new InvalidOperationException("inner-cause-marker");
            }
            catch (Exception inner)
            {
                throw new ApplicationException("outer-wrapper-marker", inner);
            }
        }
        catch (Exception ex)
        {
            captured = ex;
        }

        var report = CrashHandler.DescribeCrash("Sector", captured, isTerminating: true);

        Assert.IsTrue(report.Contains("UNHANDLED EXCEPTION", StringComparison.Ordinal));
        Assert.IsTrue(report.Contains("process is terminating", StringComparison.Ordinal),
            "The report must say whether the process is going down.");
        Assert.IsTrue(report.Contains("Sector", StringComparison.Ordinal),
            "The failing subsystem must be identified.");
        Assert.IsTrue(report.Contains("thread", StringComparison.Ordinal),
            "Thread information must be captured.");
        Assert.IsTrue(report.Contains("outer-wrapper-marker", StringComparison.Ordinal),
            "Outer exception message must be preserved.");
        Assert.IsTrue(report.Contains("inner-cause-marker", StringComparison.Ordinal),
            "Inner exception chain must be preserved.");
        Assert.IsTrue(report.Contains(nameof(DescribeCrash_IncludesSubsystemThreadTimestampAndFullExceptionChain), StringComparison.Ordinal),
            "Stack trace must be preserved.");
    }

    [TestMethod]
    public void DescribeCrash_WhenNotTerminating_SaysProcessContinues()
    {
        var report = CrashHandler.DescribeCrash("Auth", new InvalidOperationException("x"), isTerminating: false);

        Assert.IsTrue(report.Contains("process is continuing", StringComparison.Ordinal));
    }

    /// <summary>
    /// The CLR allows non-Exception objects to be thrown by other languages; the reporter
    /// must not itself fail on one.
    /// </summary>
    [TestMethod]
    public void DescribeCrash_WithNonExceptionObject_StillProducesAReport()
    {
        var report = CrashHandler.DescribeCrash("Global", "a bare string was thrown", isTerminating: true);

        Assert.IsTrue(report.Contains("non-Exception object", StringComparison.Ordinal));
        Assert.IsTrue(report.Contains("a bare string was thrown", StringComparison.Ordinal));
    }

    [TestMethod]
    public void DescribeCrash_WithNullExceptionObject_StillProducesAReport()
    {
        var report = CrashHandler.DescribeCrash("Global", null, isTerminating: true);

        Assert.IsTrue(report.Contains("no exception object supplied", StringComparison.Ordinal));
    }

    [TestMethod]
    public void DescribeUnobservedTask_ListsEveryInnerFailure()
    {
        var aggregate = new AggregateException(
            new InvalidOperationException("failure-one"),
            new ApplicationException("failure-two"));

        var report = CrashHandler.DescribeUnobservedTask("Sector", aggregate);

        Assert.IsTrue(report.Contains("UNOBSERVED TASK EXCEPTION", StringComparison.Ordinal));
        Assert.IsTrue(report.Contains("failure-one", StringComparison.Ordinal));
        Assert.IsTrue(report.Contains("failure-two", StringComparison.Ordinal),
            "Every inner failure must be listed, not just the first.");
        Assert.IsTrue(report.Contains("SafeTask.FireAndForget", StringComparison.Ordinal),
            "The report should point at the fix so the next engineer knows what to do.");
    }

    [TestMethod]
    public void DescribeUnobservedTask_WithNull_StillProducesAReport()
    {
        var report = CrashHandler.DescribeUnobservedTask("Sector", null);

        Assert.IsTrue(report.Contains("no exception supplied", StringComparison.Ordinal));
    }

    /// <summary>
    /// A crash report is worthless if generating it throws. Exercise a type whose
    /// ToString() itself fails.
    /// </summary>
    [TestMethod]
    public void DescribeCrash_WhenExceptionToStringThrows_DoesNotPropagate()
    {
        var report = CrashHandler.DescribeCrash("Sector", new HostileException(), isTerminating: true);

        Assert.IsTrue(
            report.Contains("ToString() threw", StringComparison.Ordinal),
            $"Expected a degraded description, got: {report}");
    }

    private sealed class HostileException : Exception
    {
        public override string ToString() => throw new NotSupportedException("hostile ToString");
    }
}
