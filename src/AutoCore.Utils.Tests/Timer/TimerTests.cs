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
}
