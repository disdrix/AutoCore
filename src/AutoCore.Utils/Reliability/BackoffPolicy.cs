namespace AutoCore.Utils.Reliability;

/// <summary>
/// Bounded exponential backoff with jitter, for loops that must survive transient failures
/// without spinning hot on a persistent one.
/// <para>
/// SS-10: an accept/receive loop that simply <c>continue</c>s on error turns a permanent
/// condition (for example "too many open files") into a 100%-CPU spin, while a loop that
/// exits on the first error silently stops serving. This policy does neither: it slows down
/// as failures accumulate, and after <see cref="MaxConsecutiveFailures"/> it reports that the
/// loop should give up so the caller can escalate rather than retry forever.
/// </para>
/// <para>Not thread-safe; each loop owns its own instance.</para>
/// </summary>
public sealed class BackoffPolicy
{
    private readonly TimeSpan _initialDelay;
    private readonly TimeSpan _maxDelay;
    private readonly Func<double> _jitter;

    /// <param name="maxConsecutiveFailures">How many back-to-back failures to tolerate before
    /// giving up. Must be at least 1.</param>
    /// <param name="initialDelay">Delay after the first failure.</param>
    /// <param name="maxDelay">Ceiling for the doubling delay.</param>
    /// <param name="jitter">Returns a value in [0,1) used to spread retries. Defaults to
    /// <see cref="Random.Shared"/>; inject a fixed value in tests for determinism.</param>
    public BackoffPolicy(
        int maxConsecutiveFailures = 10,
        TimeSpan? initialDelay = null,
        TimeSpan? maxDelay = null,
        Func<double> jitter = null)
    {
        if (maxConsecutiveFailures < 1)
            throw new ArgumentOutOfRangeException(nameof(maxConsecutiveFailures), maxConsecutiveFailures,
                "At least one failure must be tolerated.");

        MaxConsecutiveFailures = maxConsecutiveFailures;
        _initialDelay = initialDelay ?? TimeSpan.FromMilliseconds(50);
        _maxDelay = maxDelay ?? TimeSpan.FromSeconds(5);
        _jitter = jitter ?? (() => Random.Shared.NextDouble());

        if (_maxDelay < _initialDelay)
            throw new ArgumentOutOfRangeException(nameof(maxDelay), maxDelay,
                "Maximum delay must not be shorter than the initial delay.");
    }

    public int MaxConsecutiveFailures { get; }

    /// <summary>Back-to-back failures since the last <see cref="Reset"/>.</summary>
    public int ConsecutiveFailures { get; private set; }

    /// <summary>Call after a successful iteration.</summary>
    public void Reset() => ConsecutiveFailures = 0;

    /// <summary>
    /// Records a failure and yields how long to wait before retrying.
    /// </summary>
    /// <param name="delay">How long the caller should wait before the next attempt.</param>
    /// <returns><c>false</c> once <see cref="MaxConsecutiveFailures"/> is reached, meaning the
    /// caller must stop retrying and escalate.</returns>
    public bool TryRecordFailure(out TimeSpan delay)
    {
        ConsecutiveFailures++;

        if (ConsecutiveFailures >= MaxConsecutiveFailures)
        {
            delay = TimeSpan.Zero;
            return false;
        }

        // Double from the initial delay, capped, then apply up to +50% jitter so several
        // failing loops do not retry in lockstep.
        var exponent = Math.Min(ConsecutiveFailures - 1, 30);
        var scaled = _initialDelay.TotalMilliseconds * Math.Pow(2, exponent);
        var capped = Math.Min(scaled, _maxDelay.TotalMilliseconds);

        delay = TimeSpan.FromMilliseconds(capped * (1.0 + (Clamp01(_jitter()) * 0.5)));
        return true;
    }

    private static double Clamp01(double value) =>
        double.IsNaN(value) ? 0.0 : Math.Clamp(value, 0.0, 1.0);
}
