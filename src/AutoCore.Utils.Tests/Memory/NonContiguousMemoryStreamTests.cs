using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Test.Memory;

using AutoCore.Utils.Memory;

[TestClass]
public class NonContiguousMemoryStreamTests
{
    [TestMethod]
    public void TestLength()
    {
        var buffer1 = new byte[10];
        var buffer2 = new byte[20];
        var buffer3 = new byte[30];

        using var stream = new NonContiguousMemoryStream();

        stream.Write(buffer1);
        stream.Write(buffer2);
        stream.Write(buffer3, 0, buffer3.Length - 10);

        Assert.AreEqual(stream.WritePosition, buffer1.Length + buffer2.Length + buffer3.Length - 10);
    }

    [TestMethod]
    public void TestRead()
    {
        var buffer1 = new byte[20];
        for (var i = 0; i < buffer1.Length; ++i)
            buffer1[i] = (byte)i;

        var buffer2 = new byte[40];
        for (var i = 0; i < buffer2.Length; ++i)
            buffer2[i] = (byte)(buffer1.Length + i);

        var buffer3 = new byte[60];
        for (var i = 0; i < buffer3.Length; ++i)
            buffer3[i] = (byte)(buffer1.Length + buffer2.Length + i);

        using var stream = new NonContiguousMemoryStream();

        stream.Write(buffer1);
        stream.Write(buffer2);
        stream.Write(buffer3);

        var read1 = new byte[30];
        var readCount1 = stream.Read(read1, 0, read1.Length);

        var read2 = new byte[20];
        var readCount2 = stream.Read(read2, 0, read2.Length);

        var read3 = new byte[70];
        var readCount3 = stream.Read(read3, 0, read3.Length);

        Assert.AreEqual(readCount1, 30);
        Assert.AreEqual(readCount2, 20);
        Assert.AreEqual(readCount3, 70);
        Assert.AreEqual(stream.Position, stream.WritePosition);

        // Validate read1
        for (var i = 0; i < 20; ++i)
            Assert.AreEqual(read1[i], buffer1[i]);

        for (var i = 0; i < 10; ++i)
            Assert.AreEqual(read1[20 + i], buffer2[i]);

        // Validate read2
        for (var i = 0; i < 20; ++i)
            Assert.AreEqual(read2[i], buffer2[10 + i]);

        // Validate read3
        for (var i = 0; i < 10; ++i)
            Assert.AreEqual(read3[i], buffer2[30 + i]);

        for (var i = 0; i < 60; ++i)
            Assert.AreEqual(read3[10 + i], buffer3[i]);
    }

    [TestMethod]
    public void TestRemoveBytes()
    {
        var buffer1 = new byte[5];
        var buffer2 = new byte[5];

        for (var i = 0; i < 5; ++i)
        {
            buffer1[i] = (byte)i;
            buffer2[i] = (byte)(i * 2);
        }

        using var stream = new NonContiguousMemoryStream();

        stream.Write(buffer1);
        stream.Write(buffer2);

        var throwAwayData = new byte[2];
        stream.Read(throwAwayData, 0, 2);

        stream.RemoveBytes(3);

        var data = new byte[7];
        stream.Read(data, 0, data.Length);

        Assert.AreEqual(data[0], 3);
        Assert.AreEqual(data[1], 4);
        Assert.AreEqual(data[2], 0);
        Assert.AreEqual(data[3], 2);
        Assert.AreEqual(data[4], 4);
        Assert.AreEqual(data[5], 6);
        Assert.AreEqual(data[6], 8);
        Assert.AreEqual(stream.Position, stream.WritePosition);
    }

    [TestMethod]
    public void TestRemoveMoreBytes()
    {
        var buffer = new byte[5];

        using var stream = new NonContiguousMemoryStream();

        stream.Write(buffer);
        stream.Write(buffer);

        var throwAwayData = new byte[6];
        stream.Read(throwAwayData, 0, 6);

        stream.RemoveBytes(9);

        Assert.AreEqual(stream.Position, 0);
        Assert.AreEqual(stream.WritePosition, 1);
    }

    [TestMethod]
    public void TestRemoveAllBytes()
    {
        var buffer = new byte[5];

        using var stream = new NonContiguousMemoryStream();

        stream.Write(buffer);
        stream.Write(buffer);

        var throwAwayData = new byte[6];
        stream.Read(throwAwayData, 0, 6);

        stream.RemoveBytes(10);

        Assert.AreEqual(stream.Position, 0);
        Assert.AreEqual(stream.WritePosition, 0);
    }

    [TestMethod]
    public void TestRemoveTooManyBytes()
    {
        var buffer = new byte[5];

        using var stream = new NonContiguousMemoryStream();

        stream.Write(buffer);
        stream.Write(buffer);

        Assert.ThrowsException<ArgumentOutOfRangeException>(() => stream.RemoveBytes((int)stream.Length + 1));
    }

    [TestMethod]
    public void TestCopyToWithCount()
    {
        var buffer = new byte[5];

        using var stream1 = new NonContiguousMemoryStream();
        using var stream2 = new NonContiguousMemoryStream();

        stream1.Write(buffer);
        stream1.CopyToWithCount(stream2, 10);

        Assert.AreEqual(5, stream1.Position);
        Assert.AreEqual(5, stream1.WritePosition);
        Assert.AreEqual(0, stream2.Position);
        Assert.AreEqual(5, stream2.WritePosition);
    }

    [TestMethod]
    public void Capabilities_AreReadableWritableSeekable()
    {
        using var stream = new NonContiguousMemoryStream();
        Assert.IsTrue(stream.CanRead);
        Assert.IsTrue(stream.CanWrite);
        Assert.IsTrue(stream.CanSeek);
    }

    [TestMethod]
    public void Flush_DoesNotThrow()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[] { 1, 2, 3 });
        stream.Flush();
    }

    [TestMethod]
    public void AvailableBytesToRead_TracksWriteAndReadPositions()
    {
        using var stream = new NonContiguousMemoryStream();
        Assert.AreEqual(0, stream.AvailableBytesToRead);

        stream.Write(new byte[10]);
        Assert.AreEqual(10, stream.AvailableBytesToRead);

        stream.Read(new byte[4], 0, 4);
        Assert.AreEqual(6, stream.AvailableBytesToRead);
    }

    [TestMethod]
    public void Seek_BeginCurrentEnd()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[20]);
        // Write expands capacity (WriteArrayCapacity), so Length >= WritePosition.
        var length = stream.Length;

        Assert.AreEqual(5, stream.Seek(5, SeekOrigin.Begin));
        Assert.AreEqual(5, stream.Position);

        Assert.AreEqual(8, stream.Seek(3, SeekOrigin.Current));
        Assert.AreEqual(8, stream.Position);

        var expectedEnd = length - 5;
        Assert.AreEqual(expectedEnd, stream.Seek(-5, SeekOrigin.End));
        Assert.AreEqual(expectedEnd, stream.Position);
    }

    [TestMethod]
    public void SeekWrite_BeginCurrentEnd()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[20]);

        Assert.AreEqual(2, stream.SeekWrite(2, SeekOrigin.Begin));
        Assert.AreEqual(2, stream.WritePosition);

        Assert.AreEqual(5, stream.SeekWrite(3, SeekOrigin.Current));
        Assert.AreEqual(5, stream.WritePosition);

        // Length is buffer capacity after SetLength expansion (>= 20)
        var endPos = stream.SeekWrite(0, SeekOrigin.End);
        Assert.AreEqual(stream.Length, endPos);
        Assert.AreEqual(stream.Length, stream.WritePosition);
    }

    [TestMethod]
    public void SetLength_ExpandsCapacity()
    {
        using var stream = new NonContiguousMemoryStream();
        Assert.AreEqual(0, stream.Length);
        stream.SetLength(100);
        Assert.IsTrue(stream.Length >= 100);
    }

    [TestMethod]
    public void SetLength_WhenNotGrowing_DoesNotThrow()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[10]);
        var length = stream.Length;
        stream.SetLength(1); // value <= Length → no-op branch
        Assert.AreEqual(length, stream.Length);
    }

    [TestMethod]
    public void Read_NullBuffer_Throws()
    {
        using var stream = new NonContiguousMemoryStream();
        Assert.ThrowsException<ArgumentNullException>(() => stream.Read(null!, 0, 1));
    }

    [TestMethod]
    public void Read_NegativeOffset_Throws()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[4]);
        Assert.ThrowsException<ArgumentOutOfRangeException>(() => stream.Read(new byte[4], -1, 1));
    }

    [TestMethod]
    public void Read_CountExceedsBuffer_Throws()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[4]);
        Assert.ThrowsException<ArgumentOutOfRangeException>(() => stream.Read(new byte[2], 0, 3));
    }

    [TestMethod]
    public void Write_NullBuffer_Throws()
    {
        using var stream = new NonContiguousMemoryStream();
        Assert.ThrowsException<ArgumentNullException>(() => stream.Write(null!, 0, 1));
    }

    [TestMethod]
    public void Write_NegativeOffset_Throws()
    {
        using var stream = new NonContiguousMemoryStream();
        Assert.ThrowsException<ArgumentOutOfRangeException>(() => stream.Write(new byte[4], -1, 1));
    }

    [TestMethod]
    public void Write_CountExceedsBuffer_Throws()
    {
        using var stream = new NonContiguousMemoryStream();
        Assert.ThrowsException<ArgumentOutOfRangeException>(() => stream.Write(new byte[2], 0, 3));
    }

    [TestMethod]
    public void Read_WhenPastWritePosition_ReturnsZero()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[] { 1, 2 });
        stream.Position = stream.WritePosition;
        var read = stream.Read(new byte[4], 0, 4);
        Assert.AreEqual(0, read);
    }

    [TestMethod]
    public void CopyToWithCount_Zero_DoesNothing()
    {
        using var src = new NonContiguousMemoryStream();
        using var dst = new NonContiguousMemoryStream();
        src.Write(new byte[] { 1, 2, 3 });
        src.CopyToWithCount(dst, 0);
        Assert.AreEqual(0, src.Position);
        Assert.AreEqual(0, dst.WritePosition);
    }

    [TestMethod]
    public void CopyToWithCount_ExactCount()
    {
        using var src = new NonContiguousMemoryStream();
        using var dst = new MemoryStream();
        src.Write(new byte[] { 10, 20, 30, 40 });
        src.CopyToWithCount(dst, 3);
        CollectionAssert.AreEqual(new byte[] { 10, 20, 30 }, dst.ToArray());
        Assert.AreEqual(3, src.Position);
    }

    [TestMethod]
    public void Close_ReturnsBuffersAndResets()
    {
        var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[50]);
        stream.Close();
        // After close, Length should be 0 (buffers cleared)
        Assert.AreEqual(0, stream.Length);
    }

    [TestMethod]
    public void Write_SpansMultipleInternalBuffers()
    {
        using var stream = new NonContiguousMemoryStream();
        // WriteArrayCapacity = 256; write more than one chunk expansion
        var big = new byte[600];
        for (var i = 0; i < big.Length; i++)
            big[i] = (byte)(i % 251);

        stream.Write(big, 0, big.Length);
        Assert.AreEqual(big.Length, stream.WritePosition);

        var read = new byte[big.Length];
        var n = stream.Read(read, 0, read.Length);
        Assert.AreEqual(big.Length, n);
        CollectionAssert.AreEqual(big, read);
    }

    [TestMethod]
    public void RemoveBytes_Zero_IsNoOpOnEmptyOrigin()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[] { 1, 2, 3 });
        stream.RemoveBytes(0);
        Assert.AreEqual(3, stream.WritePosition);
        Assert.AreEqual(3, stream.AvailableBytesToRead);
    }

    [TestMethod]
    public void Write_AtOffsetIntoExistingStream_Overwrites()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[] { 1, 2, 3, 4, 5 });
        stream.SeekWrite(2, SeekOrigin.Begin);
        stream.Write(new byte[] { 9, 9 }, 0, 2);
        // Restore write cursor past existing payload so reads can see full 5 bytes.
        stream.SeekWrite(5, SeekOrigin.Begin);

        stream.Position = 0;
        var buf = new byte[5];
        stream.Read(buf, 0, 5);
        CollectionAssert.AreEqual(new byte[] { 1, 2, 9, 9, 5 }, buf);
    }

    [TestMethod]
    public void RemoveBytes_AcrossMultipleBuffers_ReturnsPooledArrays()
    {
        using var stream = new NonContiguousMemoryStream();
        // First write expands by WriteArrayCapacity (256).
        var first = new byte[200];
        for (var i = 0; i < first.Length; i++)
            first[i] = (byte)(i & 0xFF);
        stream.Write(first, 0, first.Length);

        // Second write forces another buffer when past current Length.
        var second = new byte[200];
        for (var i = 0; i < second.Length; i++)
            second[i] = (byte)((i + 50) & 0xFF);
        stream.Write(second, 0, second.Length);

        Assert.IsTrue(stream.WritePosition >= 400);

        // Remove past first buffer so RemoveBytes hits index > 0 path.
        stream.RemoveBytes(250);

        Assert.AreEqual(stream.WritePosition, stream.AvailableBytesToRead + stream.Position);
        var remaining = new byte[stream.AvailableBytesToRead];
        var n = stream.Read(remaining, 0, remaining.Length);
        Assert.AreEqual(remaining.Length, n);
        Assert.IsTrue(n > 0);
        // 200 bytes first + 200 second; after removing 250, first remaining byte is second[50]
        Assert.AreEqual(second[50], remaining[0]);
    }

    [TestMethod]
    public void Read_AndWrite_AcrossBufferBoundary()
    {
        using var stream = new NonContiguousMemoryStream();
        var payload = new byte[400];
        for (var i = 0; i < payload.Length; i++)
            payload[i] = (byte)(i % 251);

        // Write in two chunks to encourage multi-buffer layout
        stream.Write(payload, 0, 200);
        stream.Write(payload, 200, 200);

        // Read in small chunks spanning boundaries
        var readBack = new byte[400];
        var offset = 0;
        while (offset < 400)
        {
            var chunk = Math.Min(37, 400 - offset);
            var n = stream.Read(readBack, offset, chunk);
            Assert.IsTrue(n > 0);
            offset += n;
        }

        CollectionAssert.AreEqual(payload, readBack);
    }

    [TestMethod]
    public void GetIndices_PastEnd_IsSafeViaSeek()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[10]);
        // Seek past logical end — GetIndices used internally for reads beyond buffers
        stream.Position = stream.Length + 100;
        var n = stream.Read(new byte[5], 0, 5);
        Assert.AreEqual(0, n);
    }

    [TestMethod]
    public void Optimize_IsCallableViaReflection()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[8]);
        var method = typeof(NonContiguousMemoryStream)
            .GetMethod("Optimize", System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic);
        Assert.IsNotNull(method);
        method!.Invoke(stream, null);
    }
}