namespace AutoCore.Sim.Ai;

/// <summary>
/// Learns the height offset between a grounded vehicle's wire Y and the server heightfield by
/// watching the OWNER's vehicle (live 2026-08-08: fixed conventions floated the clone, so the
/// convention is measured, not assumed). EMA with an outlier gate so jumps/airborne moments
/// don't drag the offset.
/// </summary>
public sealed class GroundOffsetCalibrator
{
    /// <summary>EMA time constant (s): converges in ~1 s of grounded driving.</summary>
    private const float SmoothingTau = 0.3f;

    /// <summary>Deltas farther than this from the current estimate are treated as airborne.</summary>
    private const float OutlierBand = 2.0f;

    /// <summary>
    /// Rejected deltas within this of each other count as a stable plateau (live 2026-08-09:
    /// the heightfield bias grows with elevation — a scale error — so the offset must re-learn
    /// after climbs instead of latching).
    /// </summary>
    private const float PlateauStabilityBand = 0.75f;

    /// <summary>Seconds of stable out-of-band samples before re-seeding to the new plateau.</summary>
    private const float PlateauReseedSeconds = 1.5f;

    private bool _hasEstimate;
    private float _rejectStreakSeconds;
    private float _lastRejectedDelta;
    private bool _hasRejectedDelta;

    public float Offset { get; private set; }

    public void Observe(float ownerY, float terrainYAtOwner, float dt)
    {
        var delta = ownerY - terrainYAtOwner;
        if (!float.IsFinite(delta))
            return;

        if (!_hasEstimate)
        {
            // First sample seeds the estimate but only if plausible for a grounded vehicle.
            if (delta is > -3f and < 5f)
            {
                Offset = delta;
                _hasEstimate = true;
            }
            return;
        }

        if (MathF.Abs(delta - Offset) > OutlierBand)
        {
            // Out of band: airborne spike OR a genuine new ground plateau after elevation
            // change. Spikes vary sample-to-sample; a plateau holds steady — after
            // PlateauReseedSeconds of steady out-of-band deltas, re-seed there.
            if (_hasRejectedDelta && MathF.Abs(delta - _lastRejectedDelta) <= PlateauStabilityBand)
            {
                _rejectStreakSeconds += dt;
                if (_rejectStreakSeconds >= PlateauReseedSeconds)
                {
                    Offset = delta;
                    _rejectStreakSeconds = 0f;
                    _hasRejectedDelta = false;
                }
            }
            else
            {
                _rejectStreakSeconds = 0f;
            }

            _lastRejectedDelta = delta;
            _hasRejectedDelta = true;
            return;
        }

        _rejectStreakSeconds = 0f;
        _hasRejectedDelta = false;
        var alpha = MathF.Min(1f, dt / SmoothingTau);
        Offset += (delta - Offset) * alpha;
    }
}
