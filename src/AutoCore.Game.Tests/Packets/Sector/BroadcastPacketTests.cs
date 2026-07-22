using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Sector;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class BroadcastPacketTests
{
    [TestMethod]
    public void Opcode_IsBroadcast()
    {
        Assert.AreEqual(GameOpcode.Broadcast, new BroadcastPacket().Opcode);
    }

    [TestMethod]
    public void WriteRead_RoundTripsFields()
    {
        var message = "Broadcast msg";
        var original = new BroadcastPacket
        {
            ChatType = ChatType.SectorMessage,
            SenderCoid = 0x1122334455667788UL,
            IsGM = false,
            MessageLength = (short)(message.Length + 1),
            Sender = "Announcer",
            Message = message
        };

        using var ms = new MemoryStream(new byte[256]);
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        ms.Position = 0;
        var roundTrip = new BroadcastPacket();
        roundTrip.Read(new BinaryReader(ms));

        Assert.AreEqual(original.ChatType, roundTrip.ChatType);
        Assert.AreEqual(original.SenderCoid, roundTrip.SenderCoid);
        Assert.AreEqual(original.IsGM, roundTrip.IsGM);
        Assert.AreEqual(original.MessageLength, roundTrip.MessageLength);
        Assert.AreEqual(original.Sender, roundTrip.Sender);
        Assert.AreEqual(original.Message, roundTrip.Message);
    }

    [TestMethod]
    public void Read_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[4]);
        Assert.ThrowsException<EndOfStreamException>(() => new BroadcastPacket().Read(new BinaryReader(ms)));
    }
}
