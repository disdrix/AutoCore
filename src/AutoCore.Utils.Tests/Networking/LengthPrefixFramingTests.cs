using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Networking;

using AutoCore.Utils.Memory;
using AutoCore.Utils.Networking;

/// <summary>
/// Contract tests for AsyncLengthedSocket length-prefix framing without OS socket I/O.
/// Mirrors Send / PeekIncomingPacketDataSize behavior using NonContiguousMemoryStream.
/// </summary>
[TestClass]
public class LengthPrefixFramingTests
{
    // Mirror of AsyncLengthedSocket private framing helpers (kept in sync with production).

    private static int HeaderSizeInBytes(AsyncLengthedSocket.HeaderSizeType headerSize) =>
        (int)headerSize;

    private static void WriteFrame(
        NonContiguousMemoryStream stream,
        byte[] payload,
        int offset,
        int count,
        AsyncLengthedSocket.HeaderSizeType headerSize,
        bool countHeaderSize)
    {
        var headerBytes = HeaderSizeInBytes(headerSize);
        var sizeToWrite = count;
        if (countHeaderSize)
            sizeToWrite += headerBytes;

        var sizeHolder = new byte[4];
        BitConverter.TryWriteBytes(sizeHolder, sizeToWrite);
        stream.Write(sizeHolder, 0, headerBytes);
        stream.Write(payload, offset, count);
    }

    private static int PeekPayloadSize(
        NonContiguousMemoryStream stream,
        AsyncLengthedSocket.HeaderSizeType headerSize,
        bool countHeaderSize)
    {
        var headerBytes = HeaderSizeInBytes(headerSize);
        if (stream.AvailableBytesToRead < headerBytes)
            return -1;

        var readPosition = stream.Position;
        var sizeHolder = new byte[4];
        try
        {
            stream.Read(sizeHolder, 0, headerBytes);

            var packetSize = headerSize switch
            {
                AsyncLengthedSocket.HeaderSizeType.Byte => sizeHolder[0],
                AsyncLengthedSocket.HeaderSizeType.Word => BitConverter.ToInt16(sizeHolder, 0),
                AsyncLengthedSocket.HeaderSizeType.Dword => BitConverter.ToInt32(sizeHolder, 0),
                _ => throw new Exception($"Unknown HeaderSizeType: {headerSize}!")
            };

            if (countHeaderSize)
                packetSize -= headerBytes;

            return packetSize;
        }
        finally
        {
            stream.Position = readPosition;
        }
    }

    private static byte[] ReadCompleteFrame(
        NonContiguousMemoryStream stream,
        AsyncLengthedSocket.HeaderSizeType headerSize,
        bool countHeaderSize)
    {
        var payloadSize = PeekPayloadSize(stream, headerSize, countHeaderSize);
        Assert.IsTrue(payloadSize >= 0, "Expected complete header");

        var headerBytes = HeaderSizeInBytes(headerSize);
        Assert.IsTrue(
            stream.AvailableBytesToRead >= payloadSize + headerBytes,
            "Expected full frame available");

        stream.RemoveBytes(headerBytes);
        var payload = new byte[payloadSize];
        var read = stream.Read(payload, 0, payloadSize);
        Assert.AreEqual(payloadSize, read);
        stream.RemoveBytes(payloadSize);
        return payload;
    }

    [TestMethod]
    public void Frame_Dword_CountHeader_RoundTripsPayload()
    {
        using var stream = new NonContiguousMemoryStream();
        var payload = new byte[] { 1, 2, 3, 4, 5 };

        WriteFrame(stream, payload, 0, payload.Length,
            AsyncLengthedSocket.HeaderSizeType.Dword, countHeaderSize: true);

        var peeked = PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true);
        Assert.AreEqual(payload.Length, peeked);
        // Frame on wire: 4-byte header + payload
        Assert.AreEqual(payload.Length + 4, stream.AvailableBytesToRead);

        var result = ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true);
        CollectionAssert.AreEqual(payload, result);
        Assert.AreEqual(0, stream.AvailableBytesToRead);
    }

    [TestMethod]
    public void Frame_Dword_NotCountHeader_StoresPayloadSizeOnly()
    {
        using var stream = new NonContiguousMemoryStream();
        var payload = new byte[] { 9, 8, 7 };

        WriteFrame(stream, payload, 0, payload.Length,
            AsyncLengthedSocket.HeaderSizeType.Dword, countHeaderSize: false);

        Assert.AreEqual(payload.Length,
            PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Dword, false));

        var result = ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Dword, false);
        CollectionAssert.AreEqual(payload, result);
    }

    [TestMethod]
    public void Frame_Word_CountHeader_RoundTrips()
    {
        using var stream = new NonContiguousMemoryStream();
        var payload = Enumerable.Range(0, 20).Select(i => (byte)i).ToArray();

        WriteFrame(stream, payload, 0, payload.Length,
            AsyncLengthedSocket.HeaderSizeType.Word, countHeaderSize: true);

        Assert.AreEqual(20, PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Word, true));
        CollectionAssert.AreEqual(payload,
            ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Word, true));
    }

    [TestMethod]
    public void Frame_Byte_CountHeader_RoundTrips()
    {
        using var stream = new NonContiguousMemoryStream();
        var payload = new byte[] { 0xAA, 0xBB };

        WriteFrame(stream, payload, 0, payload.Length,
            AsyncLengthedSocket.HeaderSizeType.Byte, countHeaderSize: true);

        // size byte = 2 + 1 = 3; payload size after subtract = 2
        Assert.AreEqual(2, PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Byte, true));
        CollectionAssert.AreEqual(payload,
            ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Byte, true));
    }

    [TestMethod]
    public void Peek_WhenHeaderIncomplete_ReturnsMinusOne()
    {
        using var stream = new NonContiguousMemoryStream();
        stream.Write(new byte[] { 0x01, 0x00 }, 0, 2); // only 2 of 4 dword bytes

        Assert.AreEqual(-1,
            PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true));
        // Position restored
        Assert.AreEqual(0, stream.Position);
        Assert.AreEqual(2, stream.AvailableBytesToRead);
    }

    [TestMethod]
    public void Peek_DoesNotConsumeBytes()
    {
        using var stream = new NonContiguousMemoryStream();
        var payload = new byte[] { 1, 2, 3, 4 };
        WriteFrame(stream, payload, 0, payload.Length,
            AsyncLengthedSocket.HeaderSizeType.Dword, true);

        var before = stream.Position;
        var available = stream.AvailableBytesToRead;
        _ = PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true);
        _ = PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true);

        Assert.AreEqual(before, stream.Position);
        Assert.AreEqual(available, stream.AvailableBytesToRead);
    }

    [TestMethod]
    public void MultipleFrames_AreReadSequentially()
    {
        using var stream = new NonContiguousMemoryStream();
        var a = new byte[] { 1, 1 };
        var b = new byte[] { 2, 2, 2 };

        WriteFrame(stream, a, 0, a.Length, AsyncLengthedSocket.HeaderSizeType.Dword, true);
        WriteFrame(stream, b, 0, b.Length, AsyncLengthedSocket.HeaderSizeType.Dword, true);

        CollectionAssert.AreEqual(a,
            ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true));
        CollectionAssert.AreEqual(b,
            ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true));
        Assert.AreEqual(0, stream.AvailableBytesToRead);
    }

    [TestMethod]
    public void Frame_PartialPayload_WaitsUntilComplete()
    {
        using var stream = new NonContiguousMemoryStream();
        // Manually write dword header for payload size 4 (count header → stored 8)
        var header = BitConverter.GetBytes(8);
        stream.Write(header, 0, 4);
        stream.Write(new byte[] { 1, 2 }, 0, 2); // partial payload

        var size = PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true);
        Assert.AreEqual(4, size);
        Assert.IsFalse(stream.AvailableBytesToRead >= size + 4);

        stream.Write(new byte[] { 3, 4 }, 0, 2);
        Assert.IsTrue(stream.AvailableBytesToRead >= size + 4);
        CollectionAssert.AreEqual(new byte[] { 1, 2, 3, 4 },
            ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true));
    }

    [TestMethod]
    public void HeaderSizeType_EnumValues_MatchByteCounts()
    {
        Assert.AreEqual(1, (int)AsyncLengthedSocket.HeaderSizeType.Byte);
        Assert.AreEqual(2, (int)AsyncLengthedSocket.HeaderSizeType.Word);
        Assert.AreEqual(4, (int)AsyncLengthedSocket.HeaderSizeType.Dword);
    }

    [TestMethod]
    public void MaxDataSize_Is1024()
    {
        Assert.AreEqual(0x400, AsyncLengthedSocket.MaxDataSize);
    }

    [TestMethod]
    public void Frame_EmptyPayload_CountHeader()
    {
        using var stream = new NonContiguousMemoryStream();
        WriteFrame(stream, Array.Empty<byte>(), 0, 0,
            AsyncLengthedSocket.HeaderSizeType.Dword, true);

        Assert.AreEqual(0, PeekPayloadSize(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true));
        var result = ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true);
        Assert.AreEqual(0, result.Length);
    }

    [TestMethod]
    public void WriteFrame_WithOffsetAndCount_UsesSlice()
    {
        using var stream = new NonContiguousMemoryStream();
        var buffer = new byte[] { 0xFF, 0x10, 0x20, 0x30, 0xFF };
        WriteFrame(stream, buffer, 1, 3,
            AsyncLengthedSocket.HeaderSizeType.Dword, true);

        CollectionAssert.AreEqual(new byte[] { 0x10, 0x20, 0x30 },
            ReadCompleteFrame(stream, AsyncLengthedSocket.HeaderSizeType.Dword, true));
    }
}
