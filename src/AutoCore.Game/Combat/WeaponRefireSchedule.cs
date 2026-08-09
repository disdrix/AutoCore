namespace AutoCore.Game.Combat;

/// <summary>
/// Schedule-based weapon refire gate. The sector combat tick is coarse (50 ms), so stamping
/// "last fired = now" quantizes every cooldown up to the next tick boundary — a 100 ms weapon
/// drifts to 150 ms. Anchoring the next-shot time to the schedule keeps the tick a latency
/// floor while preserving the exact average rate the client simulates on its ~16 ms heartbeat
/// (CVOGHBBase_TryFire / StampLastFireTime).
/// </summary>
public static class WeaponRefireSchedule
{
    /// <summary>
    /// Returns true when the slot may fire now and advances the schedule.
    /// Continuous fire advances by exactly <paramref name="cooldownMs"/> per shot (late ticks
    /// catch up within one period); after an idle gap of a full period or more the schedule
    /// re-anchors at now + cooldown so no banked shots burst out.
    /// </summary>
    public static bool TryFire(ref long nextFireAtMs, long nowMs, long cooldownMs)
    {
        if (cooldownMs <= 0)
            return true;

        if (nowMs < nextFireAtMs)
            return false;

        nextFireAtMs = nowMs - nextFireAtMs >= cooldownMs
            ? nowMs + cooldownMs
            : nextFireAtMs + cooldownMs;
        return true;
    }
}
