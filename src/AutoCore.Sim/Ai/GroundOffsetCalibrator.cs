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

    private bool _hasEstimate;

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
            return; // airborne / cliff spike

        var alpha = MathF.Min(1f, dt / SmoothingTau);
        Offset += (delta - Offset) * alpha;
    }
}
