using AutoCore.Game.Structures;

namespace AutoCore.Sim.Ai;

/// <summary>
/// Flags a vehicle that is commanding meaningful throttle but not displacing (nose against an
/// obstacle, high-sided, wedged). Displacement is measured over a sliding window.
/// </summary>
public sealed class StuckDetector
{
    private const float WindowSeconds = 2f;
    private const float MinDisplacement = 0.5f;
    private const float MinThrottle = 0.5f;

    private Vector3 _anchor;
    private float _elapsed;
    private bool _anchored;

    /// <summary>Returns true when stuck; caller decides recovery. Resets itself on trigger.</summary>
    public bool Update(Vector3 position, float throttle, float dt)
    {
        if (MathF.Abs(throttle) < MinThrottle)
        {
            Reset();
            return false;
        }

        if (!_anchored)
        {
            _anchor = position;
            _anchored = true;
            _elapsed = 0f;
            return false;
        }

        if (position.Dist(_anchor) >= MinDisplacement)
        {
            _anchor = position;
            _elapsed = 0f;
            return false;
        }

        _elapsed += dt;
        if (_elapsed < WindowSeconds)
            return false;

        Reset();
        return true;
    }

    public void Reset()
    {
        _anchored = false;
        _elapsed = 0f;
    }
}
