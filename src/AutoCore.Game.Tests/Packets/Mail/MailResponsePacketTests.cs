using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Mail;
using AutoCore.Game.Structures.Mail;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Mail;

[TestClass]
public class MailResponsePacketTests
{
    [TestMethod]
    public void MailCreateResponse_Write_ErrorCode()
    {
        Assert.AreEqual(MailOpcode.MailCreateResponse, new MailCreateResponsePacket().Opcode);

        var packet = new MailCreateResponsePacket
        {
            Error = MailCreateResponsePacket.CreateError.TargetNotExist
        };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        Assert.AreEqual((uint)MailCreateResponsePacket.CreateError.TargetNotExist, BitConverter.ToUInt32(ms.ToArray(), 0));
    }

    [TestMethod]
    public void MailDeleteResponse_Write_ErrorAndMailId()
    {
        Assert.AreEqual(MailOpcode.MailDeleteResponse, new MailDeleteResponsePacket().Opcode);

        var packet = new MailDeleteResponsePacket
        {
            Error = MailDeleteResponsePacket.DeleteError.Attachments,
            MailId = 55L
        };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual((uint)MailDeleteResponsePacket.DeleteError.Attachments, BitConverter.ToUInt32(bytes, 0));
        Assert.AreEqual(55L, BitConverter.ToInt64(bytes, 4));
    }

    [TestMethod]
    public void MailContentCollectResponse_Write_ErrorAndMailId()
    {
        Assert.AreEqual(MailOpcode.MailContentCollectResponse, new MailContentCollectResponsePacket().Opcode);

        var packet = new MailContentCollectResponsePacket
        {
            Error = MailContentCollectResponsePacket.CollectError.NoAttachments,
            MailId = 77L
        };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual((uint)MailContentCollectResponsePacket.CollectError.NoAttachments, BitConverter.ToUInt32(bytes, 0));
        Assert.AreEqual(77L, BitConverter.ToInt64(bytes, 4));
    }

    [TestMethod]
    public void MailNotification_Write_AllFields()
    {
        Assert.AreEqual(MailOpcode.MailNotification, new MailNotificationPacket().Opcode);

        var packet = new MailNotificationPacket
        {
            Notification = MailNotificationPacket.NotifyState.AuctionWon,
            MailId = 1L,
            ReceiverId = 2L,
            AttachmentId = 3L,
            AttachmentType = 4
        };

        using var ms = new MemoryStream(new byte[64]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        Assert.AreEqual((uint)MailNotificationPacket.NotifyState.AuctionWon, reader.ReadUInt32());
        Assert.AreEqual(1L, reader.ReadInt64());
        Assert.AreEqual(2L, reader.ReadInt64());
        Assert.AreEqual(3L, reader.ReadInt64());
        Assert.AreEqual(4, reader.ReadInt32());
    }

    [TestMethod]
    public void MailListResponse_Write_EmptyAndSingleMail()
    {
        Assert.AreEqual(MailOpcode.MailListResponse, new MailListResponsePacket().Opcode);

        var empty = new MailListResponsePacket();
        using (var ms = new MemoryStream(new byte[16]))
        using (var writer = new BinaryWriter(ms))
        {
            empty.Write(writer);
            ms.Position = 0;
            using var reader = new BinaryReader(ms);
            Assert.AreEqual((ushort)0, reader.ReadUInt16());
        }

        var packet = new MailListResponsePacket
        {
            Mails =
            [
                new MailListItem
                {
                    MailId = 10L,
                    Subject = "Subj",
                    Message = "Msg",
                    SenderName = "Alice",
                    Money = 100L,
                    AttachmentId = 200L,
                    ExtraInfo = 3,
                    TimeRemaining = 999L
                }
            ]
        };

        using var outMs = new MemoryStream(new byte[1024]);
        using var outWriter = new BinaryWriter(outMs);
        packet.Write(outWriter);

        outMs.Position = 0;
        using var outReader = new BinaryReader(outMs);
        Assert.AreEqual((ushort)1, outReader.ReadUInt16());
        outReader.ReadUInt16(); // pad
        Assert.AreEqual(10L, outReader.ReadInt64());
        Assert.AreEqual("Subj", outReader.ReadUTF8StringOn(50));
        Assert.AreEqual("Msg", outReader.ReadUTF8StringOn(400));
        Assert.AreEqual("Alice", outReader.ReadUTF8StringOn(17));
        outReader.ReadBytes(5); // pad
        Assert.AreEqual(100L, outReader.ReadInt64());
        Assert.AreEqual(200L, outReader.ReadInt64());
        Assert.AreEqual((sbyte)3, outReader.ReadSByte());
        outReader.ReadBytes(7); // pad
        Assert.AreEqual(999L, outReader.ReadInt64());
    }

    [TestMethod]
    public void BaseMailPacket_DefaultReadWrite_ThrowNotSupported()
    {
        var packet = new MailListRequestPacket();
        // Base defaults throw only when not overridden — ListRequest overrides Read to empty.
        // MailCreateResponse overrides Write only; Read should throw.
        var response = new MailCreateResponsePacket();
        Assert.ThrowsException<NotSupportedException>(() => response.Read(new BinaryReader(new MemoryStream())));
    }
}
