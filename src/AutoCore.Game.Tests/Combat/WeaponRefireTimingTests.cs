using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Combat;

using AutoCore.Game.Combat;

/// <summary>
/// Schedule-based refire: the sector combat tick runs every 50 ms, so a stamp-at-now cooldown
/// quantizes every weapon to tick boundaries (a 100 ms weapon drifts to 150 ms ≈ 6.7 shots/s
/// instead of 10). Advancing the schedule by the cooldown keeps the tick a latency floor, not a
/// rate error. Client anchor: CVOGHBBase_TryFire stamps at its per-frame heartbeat (~16 ms), so
/// its quantization is negligible — average rate is the compatibility target.
/// </summary>
[TestClass]
public class WeaponRefireTimingTests
{
    [TestMethod]
    public void Refire100msWeapon_On50msTick_Fires10PerSecond()
    {
        long next = 0;
        var fires = 0;
        for (long now = 100_000; now < 110_000; now += 50)
        {
            if (WeaponRefireSchedule.TryFire(ref next, now, 100))
                fires++;
        }

        Assert.AreEqual(100, fires, "a 100 ms weapon driven by a 50 ms tick must average 10 shots/s");
    }

    [TestMethod]
    public void Refire75msWeapon_On50msTick_MatchesAverageRate()
    {
        long next = 0;
        var fires = 0;
        for (long now = 100_000; now < 103_000; now += 50)
        {
            if (WeaponRefireSchedule.TryFire(ref next, now, 75))
                fires++;
        }

        Assert.AreEqual(40, fires, "3000 ms / 75 ms = 40 shots despite the coarser tick");
    }

    [TestMethod]
    public void Refire_BeforeCooldownElapsed_DoesNotFire()
    {
        long next = 0;
        Assert.IsTrue(WeaponRefireSchedule.TryFire(ref next, 100_000, 100));
        Assert.IsFalse(WeaponRefireSchedule.TryFire(ref next, 100_050, 100));
    }

    [TestMethod]
    public void Refire_AfterLongIdle_DoesNotBankShots()
    {
        long next = 0;
        Assert.IsTrue(WeaponRefireSchedule.TryFire(ref next, 100_000, 100));

        // Idle 900 ms, resume firing: one shot now, and the NEXT full cooldown applies —
        // no burst of banked shots.
        Assert.IsTrue(WeaponRefireSchedule.TryFire(ref next, 101_000, 100));
        Assert.IsFalse(WeaponRefireSchedule.TryFire(ref next, 101_050, 100),
            "an idle period must not bank extra shots");
        Assert.IsTrue(WeaponRefireSchedule.TryFire(ref next, 101_100, 100));
    }

    [TestMethod]
    public void Refire_LateTick_CatchesUpWithinOnePeriod()
    {
        long next = 0;
        Assert.IsTrue(WeaponRefireSchedule.TryFire(ref next, 100_000, 100));

        // Tick jitter: the 100_100 tick lands at 100_110. The schedule stays anchored, so the
        // following shot is due at 100_200 — average rate is preserved.
        Assert.IsTrue(WeaponRefireSchedule.TryFire(ref next, 100_110, 100));
        Assert.IsTrue(WeaponRefireSchedule.TryFire(ref next, 100_200, 100));
    }
}
