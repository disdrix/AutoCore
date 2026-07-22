using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Extensions;

using AutoCore.Utils.Extensions;

[TestClass]
public class RandomExtensionsTests
{
    [TestMethod]
    public void NextUInt_ReturnsNonNegativeUintInIntRange()
    {
        var rand = new Random(12345);
        for (var i = 0; i < 50; i++)
        {
            var value = rand.NextUInt();
            // Random.Next() returns [0, int.MaxValue); cast to uint preserves that range
            Assert.IsTrue(value <= (uint)int.MaxValue);
        }
    }

    [TestMethod]
    public void NextUInt_IsDeterministicWithSameSeed()
    {
        var a = new Random(99).NextUInt();
        var b = new Random(99).NextUInt();
        Assert.AreEqual(a, b);
    }

    [TestMethod]
    public void NextUInt_DiffersAcrossSequence()
    {
        var rand = new Random(7);
        var first = rand.NextUInt();
        var second = rand.NextUInt();
        // Extremely unlikely to be equal for successive Next() calls
        Assert.AreNotEqual(first, second);
    }
}
