using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Mail;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Mail;

[TestClass]
public class MailRequestPacketTests
{
    [TestMethod]
    public void MailListRequest_OpcodeAndEmptyRead()
    {
        Assert.AreEqual(MailOpcode.MailListRequest, new MailListRequestPacket().Opcode);
        var packet = new MailListRequestPacket();
        packet.Read(new BinaryReader(new MemoryStream()));
    }

    [TestMethod]
    public void MailCreateRequest_Read_AllFields()
    {
        Assert.AreEqual(MailOpcode.MailCreateRequest, new MailCreateRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.WriteUtf8StringOn("Hello", 50);
            writer.WriteUtf8StringOn("Body text", 400);
            writer.WriteUtf8StringOn("Bob", 17);
            writer.Write((byte)0); // pad
            writer.Write(500L);
            writer.Write(9001L);
        }

        ms.Position = 0;
        var packet = new MailCreateRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual("Hello", packet.Subject);
        Assert.AreEqual("Body text", packet.Message);
        Assert.AreEqual("Bob", packet.ReceiverName);
        Assert.AreEqual(500L, packet.Money);
        Assert.AreEqual(9001L, packet.AttachmentId);
    }

    [TestMethod]
    public void MailDeleteRequest_Read_MailAndReceiverIds()
    {
        Assert.AreEqual(MailOpcode.MailDeleteRequest, new MailDeleteRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0); // pad
            writer.Write(111L);
            writer.Write(222L);
        }

        ms.Position = 0;
        var packet = new MailDeleteRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(111L, packet.MailId);
        Assert.AreEqual(222L, packet.ReceiverId);
    }

    [TestMethod]
    public void MailContentCollectRequest_Read_MailAndReceiverIds()
    {
        Assert.AreEqual(MailOpcode.MailContentCollectRequest, new MailContentCollectRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0);
            writer.Write(333L);
            writer.Write(444L);
        }

        ms.Position = 0;
        var packet = new MailContentCollectRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(333L, packet.MailId);
        Assert.AreEqual(444L, packet.ReceiverId);
    }

    [TestMethod]
    public void MailCreateRequest_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[10]);
        Assert.ThrowsException<EndOfStreamException>(() =>
            new MailCreateRequestPacket().Read(new BinaryReader(ms)));
    }
}
