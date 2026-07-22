using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Sector;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class ChangeCombatModePacketTests
{
    [TestMethod]
    public void Request_OpcodeAndRead()
    {
        Assert.AreEqual(GameOpcode.ChangeCombatModeRequest, new ChangeCombatModeRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0); // pad
            writer.Write(0xABCDEFL);
            writer.Write((byte)2);
            writer.Write(new byte[7]);
        }

        ms.Position = 0;
        var packet = new ChangeCombatModeRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(0xABCDEFL, packet.CharacterCoid);
        Assert.AreEqual((byte)2, packet.Mode);
    }

    [TestMethod]
    public void Response_OpcodeAndWrite()
    {
        Assert.AreEqual(GameOpcode.ChangeCombatModeResponse, new ChangeCombatModeResponsePacket().Opcode);

        var packet = new ChangeCombatModeResponsePacket
        {
            CharacterCoid = 0x1122L,
            Mode = 1,
            Success = true
        };

        using var ms = new MemoryStream(new byte[32]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        reader.ReadInt32(); // pad
        Assert.AreEqual(0x1122L, reader.ReadInt64());
        Assert.AreEqual((byte)1, reader.ReadByte());
        Assert.IsTrue(reader.ReadBoolean());
    }

    [TestMethod]
    public void Request_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[4]);
        Assert.ThrowsException<EndOfStreamException>(() =>
            new ChangeCombatModeRequestPacket().Read(new BinaryReader(ms)));
    }
}
