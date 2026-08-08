using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Reliability;

using AutoCore.Utils.Reliability;

[TestClass]
public class BackoffPolicyTests
{
    private static BackoffPolicy Deterministic(
        int maxConsecutiveFailures = 5,
        int initialMs = 10,
        int maxMs = 1000) =>
        new(maxConsecutiveFailures,
            TimeSpan.FromMilliseconds(initialMs),
            TimeSpan.FromMilliseconds(maxMs),
            jitter: () => 0.0);

    [TestMethod]
    public void TryRecordFailure_DelayGrowsExponentially()
    {
        var policy = Deterministic();

        Assert.IsTrue(policy.TryRecordFailure(out var first));
        Assert.IsTrue(policy.TryRecordFailure(out var second));
        Assert.IsTrue(policy.TryRecordFailure(out var third));

        Assert.AreEqual(10, first.TotalMilliseconds, 0.001);
        Assert.AreEqual(20, second.TotalMilliseconds, 0.001);
        Assert.AreEqual(40, third.TotalMilliseconds, 0.001);
    }

    [TestMethod]
    public void TryRecordFailure_DelayIsCappedAtMaxDelay()
    {
        var policy = Deterministic(maxConsecutiveFailures: 100, initialMs: 10, maxMs: 50);

        TimeSpan delay = TimeSpan.Zero;
        for (var i = 0; i < 10; i++)
            Assert.IsTrue(policy.TryRecordFailure(out delay));

        Assert.AreEqual(
            50,
            delay.TotalMilliseconds,
            0.001,
            "The delay must not grow past the configured ceiling.");
    }

    /// <summary>
    /// The whole point: retries are bounded, never infinite.
    /// </summary>
    [TestMethod]
    public void TryRecordFailure_ReturnsFalseOnceTheFailureCapIsReached()
    {
        var policy = Deterministic(maxConsecutiveFailures: 3);

        Assert.IsTrue(policy.TryRecordFailure(out _), "First failure should still retry.");
        Assert.IsTrue(policy.TryRecordFailure(out _), "Second failure should still retry.");
        Assert.IsFalse(
            policy.TryRecordFailure(out _),
            "The third consecutive failure hits the cap; the loop must be told to give up " +
            "rather than retry forever.");
    }

    [TestMethod]
    public void Reset_AfterSuccess_RestoresFullRetryBudgetAndDelay()
    {
        var policy = Deterministic(maxConsecutiveFailures: 3);

        policy.TryRecordFailure(out _);
        policy.TryRecordFailure(out _);
        Assert.AreEqual(2, policy.ConsecutiveFailures);

        policy.Reset();

        Assert.AreEqual(0, policy.ConsecutiveFailures);
        Assert.IsTrue(policy.TryRecordFailure(out var delay), "Budget must be restored after a success.");
        Assert.AreEqual(10, delay.TotalMilliseconds, 0.001, "Delay must restart from the initial value.");
    }

    [TestMethod]
    public void TryRecordFailure_AppliesJitterUpToFiftyPercent()
    {
        var noJitter = new BackoffPolicy(5, TimeSpan.FromMilliseconds(100), TimeSpan.FromSeconds(1), () => 0.0);
        var fullJitter = new BackoffPolicy(5, TimeSpan.FromMilliseconds(100), TimeSpan.FromSeconds(1), () => 1.0);

        noJitter.TryRecordFailure(out var low);
        fullJitter.TryRecordFailure(out var high);

        Assert.AreEqual(100, low.TotalMilliseconds, 0.001);
        Assert.AreEqual(150, high.TotalMilliseconds, 0.001,
            "Full jitter should add 50% so concurrent loops do not retry in lockstep.");
    }

    [TestMethod]
    public void Constructor_RejectsNonPositiveFailureCap()
    {
        Assert.ThrowsException<ArgumentOutOfRangeException>(() => new BackoffPolicy(0));
    }

    [TestMethod]
    public void Constructor_RejectsMaxDelayShorterThanInitialDelay()
    {
        Assert.ThrowsException<ArgumentOutOfRangeException>(() =>
            new BackoffPolicy(5, TimeSpan.FromSeconds(10), TimeSpan.FromSeconds(1)));
    }

    /// <summary>
    /// A misbehaving jitter source must not produce a negative or absurd delay.
    /// </summary>
    [TestMethod]
    public void TryRecordFailure_WithOutOfRangeJitter_ClampsInsteadOfMisbehaving()
    {
        var negative = new BackoffPolicy(5, TimeSpan.FromMilliseconds(100), TimeSpan.FromSeconds(1), () => -5.0);
        var huge = new BackoffPolicy(5, TimeSpan.FromMilliseconds(100), TimeSpan.FromSeconds(1), () => 99.0);
        var nan = new BackoffPolicy(5, TimeSpan.FromMilliseconds(100), TimeSpan.FromSeconds(1), () => double.NaN);

        negative.TryRecordFailure(out var negativeDelay);
        huge.TryRecordFailure(out var hugeDelay);
        nan.TryRecordFailure(out var nanDelay);

        Assert.AreEqual(100, negativeDelay.TotalMilliseconds, 0.001);
        Assert.AreEqual(150, hugeDelay.TotalMilliseconds, 0.001);
        Assert.AreEqual(100, nanDelay.TotalMilliseconds, 0.001);
    }
}
