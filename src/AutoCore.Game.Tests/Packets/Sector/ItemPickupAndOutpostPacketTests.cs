using AutoCore.Game.Constants;
using AutoCore.Game.Extensions;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class ItemPickupAndOutpostPacketTests
{
    [TestMethod]
    public void ItemPickup_OpcodeAndRead()
    {
        Assert.AreEqual(GameOpcode.ItemPickup, new ItemPickupPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(42);
            writer.WriteTFID(new TFID(9001L, true));
        }

        ms.Position = 0;
        var packet = new ItemPickupPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(42, packet.UnknownField);
        Assert.AreEqual(9001L, packet.ItemId.Coid);
        Assert.IsTrue(packet.ItemId.Global);
    }

    [TestMethod]
    public void ItemPickup_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[4]);
        Assert.ThrowsException<EndOfStreamException>(() => new ItemPickupPacket().Read(new BinaryReader(ms)));
    }

    [TestMethod]
    public void OutpostTokenChance_Write_ChanceFloat()
    {
        Assert.AreEqual(GameOpcode.OutpostTokenChance, new OutpostTokenChancePacket().Opcode);

        var packet = new OutpostTokenChancePacket { Chance = 0.75f };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        Assert.AreEqual(0.75f, BitConverter.ToSingle(ms.ToArray(), 0));
    }

    [TestMethod]
    public void SectorMailPacket_Write_WrapsSubPacket()
    {
        Assert.AreEqual(GameOpcode.SectorMail, new MailPacket().Opcode);

        var packet = new MailPacket
        {
            CoidCharacter = 55L,
            SubPacket = new AutoCore.Game.Packets.Mail.MailCreateResponsePacket
            {
                Error = AutoCore.Game.Packets.Mail.MailCreateResponsePacket.CreateError.NoItem
            }
        };

        using var ms = new MemoryStream(new byte[64]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        reader.ReadInt32();
        Assert.AreEqual(55L, reader.ReadInt64());
        reader.ReadInt64();
        Assert.AreEqual((uint)MailOpcode.MailCreateResponse, reader.ReadUInt32());
        Assert.AreEqual((uint)AutoCore.Game.Packets.Mail.MailCreateResponsePacket.CreateError.NoItem, reader.ReadUInt32());
    }
}
