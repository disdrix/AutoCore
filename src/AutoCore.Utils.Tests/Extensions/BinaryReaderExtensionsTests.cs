using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Extensions;

using AutoCore.Utils.Extensions;

[TestClass]
public class BinaryReaderExtensionsTests
{
    private static BinaryReader ReaderFrom(Action<BinaryWriter> write)
    {
        var ms = new MemoryStream();
        using (var bw = new BinaryWriter(ms, Encoding.UTF8, leaveOpen: true))
            write(bw);
        ms.Position = 0;
        return new BinaryReader(ms, Encoding.UTF8, leaveOpen: true);
    }

    [TestMethod]
    public void ReadLengthedString_EmptyLength_ReturnsEmpty()
    {
        using var reader = ReaderFrom(w => w.Write(0));
        Assert.AreEqual("", reader.ReadLengthedString());
    }

    [TestMethod]
    public void ReadLengthedString_ReadsUtf8Payload()
    {
        var payload = Encoding.UTF8.GetBytes("hello");
        using var reader = ReaderFrom(w =>
        {
            w.Write(payload.Length);
            w.Write(payload);
        });
        Assert.AreEqual("hello", reader.ReadLengthedString());
    }

    [TestMethod]
    public void ReadUTF8NullString_StopsAtNull()
    {
        using var reader = ReaderFrom(w =>
        {
            w.Write(Encoding.UTF8.GetBytes("abc"));
            w.Write((byte)0);
            w.Write((byte)0xFF);
        });
        Assert.AreEqual("abc", reader.ReadUTF8NullString());
    }

    [TestMethod]
    public void ReadUTF8NullString_RespectsMaxLength()
    {
        using var reader = ReaderFrom(w =>
        {
            w.Write(Encoding.UTF8.GetBytes("abcdef"));
            w.Write((byte)0);
        });
        // Loop: while (b != 0 && (maxLength == -1 || i++ < maxLength))
        // With maxLength=3: reads a (i=0->1), b (1->2), c (2->3), then i++ is 3 which is not < 3 so stops
        // Actually: condition checked after ReadByte. First b='a', i++ < 3 → i becomes 0 then compared...
        // while ((b = reader.ReadByte()) != 0 && (maxLength == -1 || i++ < maxLength))
        // i starts 0. Read 'a', i++ < 3 → 0 < 3 true, i=1, append a
        // Read 'b', 1 < 3, i=2, append b
        // Read 'c', 2 < 3, i=3, append c
        // Read 'd', 3 < 3 false → stop without appending d (but d was already consumed)
        Assert.AreEqual("abc", reader.ReadUTF8NullString(3));
    }

    [TestMethod]
    public void ReadUTF8StringOn_WithEmbeddedNull_StopsAtNull()
    {
        using var reader = ReaderFrom(w =>
        {
            w.Write(new byte[] { (byte)'h', (byte)'i', 0, (byte)'x' });
        });
        Assert.AreEqual("hi", reader.ReadUTF8StringOn(4));
    }

    [TestMethod]
    public void ReadUTF8StringOn_AllNull_ReturnsEmpty()
    {
        using var reader = ReaderFrom(w => w.Write(new byte[] { 0, 0, 0 }));
        Assert.AreEqual("", reader.ReadUTF8StringOn(3));
    }

    [TestMethod]
    public void ReadUTF8StringOn_NoNull_UsesFullLength()
    {
        using var reader = ReaderFrom(w => w.Write(Encoding.UTF8.GetBytes("abcd")));
        Assert.AreEqual("abcd", reader.ReadUTF8StringOn(4));
    }

    [TestMethod]
    public void ReadUTF16StringOn_ZeroSize_ReturnsEmpty()
    {
        using var reader = ReaderFrom(_ => { });
        Assert.AreEqual(string.Empty, reader.ReadUTF16StringOn(0));
    }

    [TestMethod]
    public void ReadUTF16StringOn_WithEmbeddedNull_StopsEarly()
    {
        using var reader = ReaderFrom(w =>
        {
            // "ab" then UTF-16 null then "c"
            w.Write(Encoding.Unicode.GetBytes("ab"));
            w.Write((byte)0);
            w.Write((byte)0);
            w.Write(Encoding.Unicode.GetBytes("c"));
        });
        Assert.AreEqual("ab", reader.ReadUTF16StringOn(4));
    }

    [TestMethod]
    public void ReadUTF16StringOn_NoNull_ReturnsFullString()
    {
        using var reader = ReaderFrom(w => w.Write(Encoding.Unicode.GetBytes("xy")));
        Assert.AreEqual("xy", reader.ReadUTF16StringOn(2));
    }

    [TestMethod]
    public void ReadConstArray_WithFuncT_FillsArray()
    {
        var i = 0;
        using var reader = ReaderFrom(_ => { });
        var result = reader.ReadConstArray(3, () => ++i);
        CollectionAssert.AreEqual(new[] { 1, 2, 3 }, result);
    }

    [TestMethod]
    public void ReadConstArray_WithFuncReaderT_PassesReader()
    {
        using var reader = ReaderFrom(w =>
        {
            w.Write(10);
            w.Write(20);
        });
        var result = reader.ReadConstArray(2, r => r.ReadInt32());
        CollectionAssert.AreEqual(new[] { 10, 20 }, result);
    }

    [TestMethod]
    public void ReadConstArray_ZeroCount_ReturnsEmpty()
    {
        using var reader = ReaderFrom(_ => { });
        var result = reader.ReadConstArray(0, () => 1);
        Assert.AreEqual(0, result.Length);
    }
}
