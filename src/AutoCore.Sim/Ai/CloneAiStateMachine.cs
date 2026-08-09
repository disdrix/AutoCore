namespace AutoCore.Sim.Ai;

public enum CloneAiMode
{
    Follow,
    Orbit,
    Recover,
    CatchUp,
}

/// <summary>All clone-AI tuning constants in one place, live-tunable later if needed.</summary>
public sealed class CloneAiTuning
{
    /// <summary>Player speed (m/s) that, held for <see cref="FollowEnterHold"/>, enters Follow.</summary>
    public float FollowEnterSpeed { get; init; } = 4f;

    public float FollowEnterHold { get; init; } = 0.5f;

    /// <summary>Player speed (m/s) below which, held for <see cref="OrbitEnterHold"/>, enters Orbit.</summary>
    public float OrbitEnterSpeed { get; init; } = 1.5f;

    public float OrbitEnterHold { get; init; } = 1.5f;

    public float OrbitRadius { get; init; } = 8f;

    public float OrbitSpeed { get; init; } = 8f;

    /// <summary>Follow offset behind the player (m).</summary>
    public float FollowDistance { get; init; } = 6f;

    /// <summary>Aim lead on the player's velocity (s).</summary>
    public float LookaheadSeconds { get; init; } = 0.6f;

    public float StuckSpeed { get; init; } = 0.5f;

    public float StuckHold { get; init; } = 2f;

    public float RecoverDuration { get; init; } = 1.5f;

    /// <summary>
    /// Separation beyond which the clone teleports behind the player. Live feedback 2026-08-08:
    /// 120 m tripped constantly at cruise speed — keep this generous.
    /// </summary>
    public float CatchUpDistance { get; init; } = 250f;
}

/// <summary>
/// Follow/Orbit mode selection with hysteresis: each transition requires the player's speed to
/// hold past a threshold for a dwell time, so dithering around either threshold never flaps.
/// Recover/CatchUp are driven externally by CloneDriveBrain (stuck detection, separation).
/// </summary>
public sealed class CloneAiStateMachine
{
    private readonly CloneAiTuning _tuning;
    private float _followHold;
    private float _orbitHold;

    public CloneAiStateMachine(CloneAiTuning tuning)
    {
        _tuning = tuning ?? throw new ArgumentNullException(nameof(tuning));
        Mode = CloneAiMode.Follow;
    }

    public CloneAiMode Mode { get; private set; }

    public void Update(float playerSpeed, float dt)
    {
        if (playerSpeed >= _tuning.FollowEnterSpeed)
        {
            _followHold += dt;
            _orbitHold = 0f;
            if (Mode == CloneAiMode.Orbit && _followHold >= _tuning.FollowEnterHold)
                Mode = CloneAiMode.Follow;
        }
        else if (playerSpeed <= _tuning.OrbitEnterSpeed)
        {
            _orbitHold += dt;
            _followHold = 0f;
            if (Mode == CloneAiMode.Follow && _orbitHold >= _tuning.OrbitEnterHold)
                Mode = CloneAiMode.Orbit;
        }
        else
        {
            // Between thresholds: decay both holds; current mode is sticky.
            _followHold = 0f;
            _orbitHold = 0f;
        }
    }

    /// <summary>Force a mode (Recover/CatchUp handoffs from the brain).</summary>
    public void ForceMode(CloneAiMode mode)
    {
        Mode = mode;
        _followHold = 0f;
        _orbitHold = 0f;
    }
}
