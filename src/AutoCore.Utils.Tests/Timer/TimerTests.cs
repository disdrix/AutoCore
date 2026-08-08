using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Timer;

using AutoCore.Utils.Timer;

[TestClass]
public class TimerTests
{
    [TestMethod]
    public void Add_AndUpdate_InvokesActionWhenElapsed()
    {
        var timer = new Timer();
        var count = 0;
        timer.Add("once", 50, repeating: false, () => count++);

        timer.Update(30);
        Assert.AreEqual(0, count);

        timer.Update(20);
        Assert.AreEqual(1, count);

        // Non-repeating item is removed after fire
        timer.Update(1000);
        Assert.AreEqual(1, count);
    }

    [TestMethod]
    public void Add_Repeating_FiresMultipleTimes()
    {
        var timer = new Timer();
        var count = 0;
        timer.Add("rep", 10, repeating: true, () => count++);

        timer.Update(10);
        timer.Update(10);
        timer.Update(10);

        Assert.AreEqual(3, count);
    }

    [TestMethod]
    public void Remove_PreventsFurtherFires()
    {
        var timer = new Timer();
        var count = 0;
        timer.Add("x", 5, repeating: true, () => count++);
        timer.Remove("x");
        timer.Update(100);
        Assert.AreEqual(0, count);
    }

    [TestMethod]
    public void Remove_UnknownName_DoesNotThrow()
    {
        var timer = new Timer();
        timer.Remove("missing");
    }

    [TestMethod]
    public void Schedule_AdjustsNextFire()
    {
        var timer = new Timer();
        var count = 0;
        timer.Add("s", 100, repeating: false, () => count++);
        timer.Schedule("s", 5);

        timer.Update(5);
        Assert.AreEqual(1, count);
    }

    [TestMethod]
    public void Schedule_UnknownName_DoesNotThrow()
    {
        var timer = new Timer();
        timer.Schedule("nope", 10);
    }

    [TestMethod]
    public void ResetTimer_RestoresFullInterval()
    {
        var timer = new Timer();
        var count = 0;
        timer.Add("r", 50, repeating: false, () => count++);
        timer.Update(40);
        timer.ResetTimer("r");
        timer.Update(40);
        Assert.AreEqual(0, count);
        timer.Update(10);
        Assert.AreEqual(1, count);
    }

    [TestMethod]
    public void ResetTimer_UnknownName_DoesNotThrow()
    {
        var timer = new Timer();
        timer.ResetTimer("missing");
    }

    [TestMethod]
    public void Add_SameName_ReplacesExisting()
    {
        var timer = new Timer();
        var first = 0;
        var second = 0;
        timer.Add("dup", 10, false, () => first++);
        timer.Add("dup", 10, false, () => second++);
        timer.Update(10);
        Assert.AreEqual(0, first);
        Assert.AreEqual(1, second);
    }

    [TestMethod]
    public void Update_NullAction_DoesNotThrow()
    {
        var timer = new Timer();
        timer.Add("n", 1, false, null);
        timer.Update(1);
    }

    [TestMethod]
    public void Update_WithNoItems_DoesNotThrow()
    {
        var timer = new Timer();
        timer.Update(16);
    }

    [TestMethod]
    public void Update_MultipleItems_RemovesOnlyNonRepeatingThatFired()
    {
        var timer = new Timer();
        var a = 0;
        var b = 0;
        timer.Add("once", 10, false, () => a++);
        timer.Add("rep", 10, true, () => b++);

        timer.Update(10);
        Assert.AreEqual(1, a);
        Assert.AreEqual(1, b);

        timer.Update(10);
        Assert.AreEqual(1, a);
        Assert.AreEqual(2, b);
    }

    /// <summary>
    /// SS-09 tripwire: the timer wheel is pumped from the sector/auth/global tick. One
    /// throwing timed action must not skip the other due timers.
    /// </summary>
    [TestMethod]
    public void Update_WhenOneActionThrows_OtherDueActionsStillFire()
    {
        var timer = new Timer();
        var first = 0;
        var third = 0;

        timer.Add("a-first", 10, repeating: true, () => first++);
        timer.Add("b-throws", 10, repeating: true, () => throw new InvalidOperationException("SS-09 injected timer failure"));
        timer.Add("c-third", 10, repeating: true, () => third++);

        timer.Update(10);

        Assert.AreEqual(1, first, "The timer registered before the failing one must fire.");
        Assert.AreEqual(
            1,
            third,
            "SS-09: the timer registered after the failing one must still fire. A throwing " +
            "callback must not abort the remaining due timers.");
    }

    /// <summary>
    /// SS-09 tripwire: the one-shot cleanup list was built after the invoke, so a throw
    /// skipped removal and the one-shot re-fired forever.
    /// </summary>
    [TestMethod]
    public void Update_WhenOneShotActionThrows_ItIsStillRemovedAndDoesNotRefireForever()
    {
        var timer = new Timer();
        var attempts = 0;

        timer.Add("one-shot-that-throws", 10, repeating: false, () =>
        {
            attempts++;
            throw new InvalidOperationException("SS-09 injected one-shot failure");
        });

        timer.Update(10);
        timer.Update(10);
        timer.Update(10);

        Assert.AreEqual(
            1,
            attempts,
            "SS-09: a non-repeating timer must be removed even when its action throws. " +
            $"It fired {attempts} times, meaning a failing one-shot re-fires forever.");
    }

    /// <summary>
    /// SS-09 tripwire: callbacks previously ran inside the lock while enumerating the
    /// dictionary, so a callback that scheduled follow-up work threw
    /// InvalidOperationException (collection modified during enumeration).
    /// </summary>
    [TestMethod]
    public void Update_WhenActionRegistersAnotherTimer_DoesNotThrowAndSchedulesIt()
    {
        var timer = new Timer();
        var followUpRan = 0;

        timer.Add("scheduler", 10, repeating: false,
            () => timer.Add("follow-up", 10, repeating: false, () => followUpRan++));

        timer.Update(10);

        Assert.AreEqual(0, followUpRan, "The follow-up should not have fired on the same pass.");

        timer.Update(10);

        Assert.AreEqual(
            1,
            followUpRan,
            "SS-09: a timed action must be able to schedule further work. This is exactly what " +
            "the exit and communicator-reconnect timers do.");
    }

    /// <summary>
    /// SS-09: a callback that removes a timer must not corrupt the pass either.
    /// </summary>
    [TestMethod]
    public void Update_WhenActionRemovesAnotherTimer_DoesNotThrow()
    {
        var timer = new Timer();
        var victimRan = 0;

        timer.Add("a-remover", 10, repeating: false, () => timer.Remove("b-victim"));
        timer.Add("b-victim", 10, repeating: true, () => victimRan++);

        timer.Update(10);
        timer.Update(10);

        Assert.AreEqual(
            0,
            victimRan,
            "A timer removed during the pass must not fire afterwards.");
    }

    /// <summary>
    /// SS-09: cancellation from a timed action is control flow, not a fault, and must
    /// surface to the caller rather than being logged as a timer failure.
    /// </summary>
    [TestMethod]
    public void Update_WhenActionCancels_PropagatesToCaller()
    {
        var timer = new Timer();
        timer.Add("cancelling", 10, repeating: false, () => throw new OperationCanceledException());

        Assert.ThrowsException<OperationCanceledException>(() => timer.Update(10));
    }
}
