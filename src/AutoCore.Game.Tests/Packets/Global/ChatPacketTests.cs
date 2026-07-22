using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Global;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Global;

[TestClass]
public class ChatPacketTests
{
    [TestMethod]
    public void Opcode_IsChat()
    {
        Assert.AreEqual(GameOpcode.Chat, new ChatPacket().Opcode);
    }

    [TestMethod]
    public void WriteRead_RoundTripsFields()
    {
        var message = "Hello sector";
        var original = new ChatPacket
        {
            ChatType = ChatType.PrivateMessage,
            IsGM = true,
            PrivateRecipientName = "Target",
            Sender = "Sender",
            MessageLength = (short)(message.Length + 1),
            Message = message
        };

        using var ms = new MemoryStream(new byte[256]);
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        ms.Position = 0;
        var roundTrip = new ChatPacket();
        roundTrip.Read(new BinaryReader(ms));

        Assert.AreEqual(original.ChatType, roundTrip.ChatType);
        Assert.AreEqual(original.IsGM, roundTrip.IsGM);
        Assert.AreEqual(original.PrivateRecipientName, roundTrip.PrivateRecipientName);
        Assert.AreEqual(original.Sender, roundTrip.Sender);
        Assert.AreEqual(original.MessageLength, roundTrip.MessageLength);
        Assert.AreEqual(original.Message, roundTrip.Message);
    }

    [TestMethod]
    public void Read_TruncatedBuffer_Throws()
    {
        using var ms = new MemoryStream(new byte[8]);
        Assert.ThrowsException<EndOfStreamException>(() => new ChatPacket().Read(new BinaryReader(ms)));
    }
}
