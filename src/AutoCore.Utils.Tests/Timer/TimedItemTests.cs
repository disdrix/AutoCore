using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Timer;

using AutoCore.Utils.Timer;

[TestClass]
public class TimedItemTests
{
    [TestMethod]
    public void Constructor_InitializesProperties()
    {
        var called = false;
        Action action = () => called = true;
        var item = new TimedItem("tick", 100, repeating: true, action);

        Assert.AreEqual("tick", item.Name);
        Assert.AreEqual(100, item.Timer);
        Assert.AreEqual(100, item.CurrentTimer);
        Assert.IsTrue(item.Repeating);
        Assert.AreSame(action, item.Action);
        Assert.IsFalse(called);
    }

    [TestMethod]
    public void Update_WhenDeltaLessThanCurrent_DecrementsAndReturnsFalse()
    {
        var item = new TimedItem("a", 100, false, null);

        Assert.IsFalse(item.Update(40));
        Assert.AreEqual(60, item.CurrentTimer);
    }

    [TestMethod]
    public void Update_WhenDeltaEqualsCurrent_FiresAndResetsWithZeroRemainder()
    {
        var item = new TimedItem("a", 100, true, null);

        Assert.IsTrue(item.Update(100));
        // CurrentTimer = Timer - (delta - CurrentTimer) = 100 - (100 - 100) = 100
        Assert.AreEqual(100, item.CurrentTimer);
    }

    [TestMethod]
    public void Update_WhenDeltaExceedsCurrent_FiresAndCarriesRemainder()
    {
        var item = new TimedItem("a", 100, true, null);

        Assert.IsTrue(item.Update(130));
        // CurrentTimer = 100 - (130 - 100) = 70
        Assert.AreEqual(70, item.CurrentTimer);
    }

    [TestMethod]
    public void Update_MultipleSteps_EventuallyFires()
    {
        var item = new TimedItem("a", 50, false, null);

        Assert.IsFalse(item.Update(20));
        Assert.AreEqual(30, item.CurrentTimer);
        Assert.IsFalse(item.Update(20));
        Assert.AreEqual(10, item.CurrentTimer);
        Assert.IsTrue(item.Update(10));
    }

    [TestMethod]
    public void Schedule_SetsCurrentTimer()
    {
        var item = new TimedItem("a", 100, false, null);
        item.Update(50);
        Assert.AreEqual(50, item.CurrentTimer);

        item.Schedule(25);
        Assert.AreEqual(25, item.CurrentTimer);
        Assert.AreEqual(100, item.Timer);
    }

    [TestMethod]
    public void ResetTimer_RestoresInitialTimer()
    {
        var item = new TimedItem("a", 100, false, null);
        item.Update(70);
        Assert.AreEqual(30, item.CurrentTimer);

        item.ResetTimer();
        Assert.AreEqual(100, item.CurrentTimer);
    }
}
