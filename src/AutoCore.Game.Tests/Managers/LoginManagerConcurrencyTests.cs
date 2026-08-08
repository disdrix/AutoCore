using AutoCore.Game.Managers;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

/// <summary>
/// SS-23: the session-expiry sweep enumerated the pending-login dictionary <b>outside</b> the
/// lock and only took it to remove. A concurrent login therefore threw
/// "Collection was modified" out of the timer callback.
/// <para>
/// This is invisible with two players and routine with fifty — the failure mode scales with
/// exactly the thing a closed alpha introduces. Post-SS-09 the throw no longer kills the tick,
/// but the sweep aborts for that pass, so expired sessions accumulate and players start being
/// told they are already logged in.
/// </para>
/// </summary>
[TestClass]
public class LoginManagerConcurrencyTests
{
    private LoginManager _manager = null!;

    [TestInitialize]
    public void Init()
    {
        _manager = LoginManager.Instance;
        _manager.ResetForTests();
    }

    [TestCleanup]
    public void Cleanup() => _manager.ResetForTests();

    /// <summary>
    /// A single expiry sweep must complete its work while logins are arriving on another thread.
    /// <para>
    /// Note the sweep no longer <i>throws</i> out of Update — SS-09 isolates timer callbacks, so
    /// the exception is caught and logged. That is why this asserts on the sweep's <b>effect</b>
    /// rather than on an exception: the surviving damage is that the aborted pass leaves expired
    /// sessions in place, and a player whose session never expires is told they are already
    /// logged in.
    /// </para>
    /// <para>
    /// The 20k seeded live sessions widen the enumeration window — the same thing a rising
    /// player count does in production.
    /// </para>
    /// </summary>
    [TestMethod]
    public void Update_WhileLoginsAreBeingRegistered_StillExpiresStaleSessions()
    {
        const uint expiredCount = 50;

        // Expired entries the sweep must remove.
        for (uint id = 1; id <= expiredCount; id++)
            _manager.ExpectLoginToGlobal(id, $"expired{id}", id);

        _manager.ExpireAllPendingLoginsForTests();

        // Live population: makes each sweep enumerate a large map, as it would with many players.
        for (uint id = 1_000; id < 21_000; id++)
            _manager.ExpectLoginToGlobal(id, $"live{id}", id);

        var stop = new CancellationTokenSource();

        // Writer keeps mutating the dictionary for the whole duration of the sweep.
        var writer = Task.Run(() =>
        {
            uint accountId = 100_000;
            while (!stop.IsCancellationRequested)
            {
                _manager.ExpectLoginToGlobal(accountId, $"joining{accountId}", accountId);
                accountId++;
            }
        });

        try
        {
            // Give the writer time to get going, then run exactly one sweep.
            Thread.Sleep(50);
            _manager.Update(10_000);
        }
        finally
        {
            stop.Cancel();
            writer.Wait(TimeSpan.FromSeconds(5));
        }

        var stillPending = 0;
        for (uint id = 1; id <= expiredCount; id++)
        {
            if (_manager.HasPendingLoginForTests(id))
                stillPending++;
        }

        Assert.AreEqual(
            0,
            stillPending,
            $"SS-23: {stillPending} of {expiredCount} expired sessions survived the sweep. " +
            "Enumerating the login map outside the lock aborts the pass when a login arrives " +
            "mid-enumeration, so stale sessions accumulate as player count rises.");
    }

    /// <summary>
    /// The sweep must still do its job: expired entries go, unexpired entries stay.
    /// </summary>
    [TestMethod]
    public void Update_RemovesExpiredLogins_AndKeepsLiveOnes()
    {
        _manager.ExpectLoginToGlobal(1001, "expired-player", 1001);
        _manager.ExpireAllPendingLoginsForTests();

        _manager.ExpectLoginToGlobal(1002, "live-player", 1002);

        _manager.Update(10_000);

        Assert.IsFalse(
            _manager.HasPendingLoginForTests(1001),
            "An expired pending login must be swept away.");
        Assert.IsTrue(
            _manager.HasPendingLoginForTests(1002),
            "A login that has not expired must survive the sweep.");
    }
}
