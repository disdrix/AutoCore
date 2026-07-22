using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Extensions;

using AutoCore.Utils.Extensions;

[TestClass]
public class StringExtensionsTests
{
    [TestMethod]
    public void GetByteArrayFromString_ParsesSpaceSeparatedBytes()
    {
        var result = "1 2 255 0".GetByteArrayFromString();
        CollectionAssert.AreEqual(new byte[] { 1, 2, 255, 0 }, result);
    }

    [TestMethod]
    public void GetByteArrayFromString_CollapsesExtraSpaces()
    {
        var result = "  10   20  ".GetByteArrayFromString();
        CollectionAssert.AreEqual(new byte[] { 10, 20 }, result);
    }

    [TestMethod]
    public void GetByteArrayFromString_Empty_ReturnsEmptyArray()
    {
        var result = "".GetByteArrayFromString();
        Assert.AreEqual(0, result.Length);
    }

    [TestMethod]
    public void GetByteArrayFromString_WhitespaceOnly_ReturnsEmptyArray()
    {
        var result = "   ".GetByteArrayFromString();
        Assert.AreEqual(0, result.Length);
    }

    [TestMethod]
    public void GetByteArrayFromString_InvalidToken_Throws()
    {
        Assert.ThrowsException<FormatException>(() => "1 xx 3".GetByteArrayFromString());
    }

    [TestMethod]
    public void GetByteArrayFromString_OutOfRange_Throws()
    {
        Assert.ThrowsException<OverflowException>(() => "256".GetByteArrayFromString());
    }
}
