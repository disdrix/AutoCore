using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Extensions;

using AutoCore.Utils.Extensions;

[TestClass]
public class BinaryWriterExtensionsTests
{
    private static byte[] Capture(Action<BinaryWriter> write)
    {
        using var ms = new MemoryStream();
        using (var bw = new BinaryWriter(ms, Encoding.UTF8, leaveOpen: true))
            write(bw);
        return ms.ToArray();
    }

    [TestMethod]
    public void WriteUtf8NullString_WritesBytesAndTrailingNull()
    {
        var bytes = Capture(w => w.WriteUtf8NullString("ab"));
        CollectionAssert.AreEqual(new byte[] { (byte)'a', (byte)'b', 0 }, bytes);
    }

    [TestMethod]
    public void WriteUtf8NullString_RespectsMaxLen()
    {
        // maxLen=3 → len = min(bytes.Length, maxLen-1) = 2, then null
        var bytes = Capture(w => w.WriteUtf8NullString("abcdef", maxLen: 3));
        CollectionAssert.AreEqual(new byte[] { (byte)'a', (byte)'b', 0 }, bytes);
    }

    [TestMethod]
    public void WriteUtf8StringOn_PadsWithZeros()
    {
        var bytes = Capture(w => w.WriteUtf8StringOn("hi", 5));
        CollectionAssert.AreEqual(new byte[] { (byte)'h', (byte)'i', 0, 0, 0 }, bytes);
    }

    [TestMethod]
    public void WriteUtf8StringOn_TruncatesWhenLongerThanLen()
    {
        var bytes = Capture(w => w.WriteUtf8StringOn("hello", 3));
        CollectionAssert.AreEqual(new byte[] { (byte)'h', (byte)'e', (byte)'l' }, bytes);
    }

    [TestMethod]
    public void WriteUtf8StringOn_NullOrEmpty_WritesZeros()
    {
        var bytes = Capture(w => w.WriteUtf8StringOn(null, 3));
        CollectionAssert.AreEqual(new byte[] { 0, 0, 0 }, bytes);

        bytes = Capture(w => w.WriteUtf8StringOn("", 2));
        CollectionAssert.AreEqual(new byte[] { 0, 0 }, bytes);
    }

    [TestMethod]
    public void WriteLengthedString_NullOrEmpty_WritesZeroLength()
    {
        var bytes = Capture(w => w.WriteLengthedString(null));
        CollectionAssert.AreEqual(BitConverter.GetBytes(0), bytes);

        bytes = Capture(w => w.WriteLengthedString(""));
        CollectionAssert.AreEqual(BitConverter.GetBytes(0), bytes);
    }

    [TestMethod]
    public void WriteLengthedString_WritesLengthThenPayload()
    {
        var bytes = Capture(w => w.WriteLengthedString("hi"));
        // length int32 = 2, then "hi" padded/written on length 2
        var expected = new List<byte>();
        expected.AddRange(BitConverter.GetBytes(2));
        expected.Add((byte)'h');
        expected.Add((byte)'i');
        CollectionAssert.AreEqual(expected.ToArray(), bytes);
    }

    [TestMethod]
    public void WriteUtf8String_WritesExactCharsWithoutNull()
    {
        var bytes = Capture(w => w.WriteUtf8String("xy"));
        CollectionAssert.AreEqual(new byte[] { (byte)'x', (byte)'y' }, bytes);
    }

    [TestMethod]
    public void WriteConstArray_InvokesWriterForEach()
    {
        var seen = new List<int>();
        Capture(w => w.WriteConstArray(new[] { 1, 2, 3 }, 3, v => seen.Add(v)));
        CollectionAssert.AreEqual(new[] { 1, 2, 3 }, seen);
    }

    [TestMethod]
    public void WriteAt_Byte_WritesAtPositionAndRestoresCursor()
    {
        using var ms = new MemoryStream(new byte[8]);
        using var w = new BinaryWriter(ms);
        w.BaseStream.Position = 5;
        w.WriteAt((byte)0xAB, 1);
        Assert.AreEqual(5, w.BaseStream.Position);
        Assert.AreEqual(0xAB, ms.ToArray()[1]);
    }

    [TestMethod]
    public void WriteAt_AllPrimitiveOverloads_WriteAndRestorePosition()
    {
        using var ms = new MemoryStream(new byte[64]);
        using var w = new BinaryWriter(ms);
        w.BaseStream.Position = 40;

        w.WriteAt((sbyte)-5, 0);
        w.WriteAt((short)-1000, 1);
        w.WriteAt((ushort)50000, 3);
        w.WriteAt(-123456, 5);
        w.WriteAt(0xDEADBEEFu, 9);
        w.WriteAt(-9999999999L, 13);
        w.WriteAt(0x1122334455667788UL, 21);
        w.WriteAt(1.5f, 29);
        w.WriteAt(2.5d, 33);

        Assert.AreEqual(40, w.BaseStream.Position);

        var data = ms.ToArray();
        using var r = new BinaryReader(new MemoryStream(data));
        Assert.AreEqual((sbyte)-5, r.ReadSByte());
        Assert.AreEqual((short)-1000, r.ReadInt16());
        Assert.AreEqual((ushort)50000, r.ReadUInt16());
        Assert.AreEqual(-123456, r.ReadInt32());
        Assert.AreEqual(0xDEADBEEFu, r.ReadUInt32());
        Assert.AreEqual(-9999999999L, r.ReadInt64());
        Assert.AreEqual(0x1122334455667788UL, r.ReadUInt64());
        Assert.AreEqual(1.5f, r.ReadSingle());
        Assert.AreEqual(2.5d, r.ReadDouble());
    }

    [TestMethod]
    public void RoundTrip_LengthedString_ViaReaderExtensions()
    {
        var bytes = Capture(w => w.WriteLengthedString("roundtrip"));
        using var reader = new BinaryReader(new MemoryStream(bytes));
        Assert.AreEqual("roundtrip", reader.ReadLengthedString());
    }

    [TestMethod]
    public void RoundTrip_Utf8NullString()
    {
        var bytes = Capture(w => w.WriteUtf8NullString("nullterm"));
        using var reader = new BinaryReader(new MemoryStream(bytes));
        Assert.AreEqual("nullterm", reader.ReadUTF8NullString());
    }
}
