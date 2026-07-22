using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Sector;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class TransferFromGlobalPacketTests
{
    [TestMethod]
    public void Opcode_IsTransferFromGlobalStage2()
    {
        Assert.AreEqual(GameOpcode.TransferFromGlobalStage2, new TransferFromGlobalPacket().Opcode);
    }

    [TestMethod]
    public void WriteRead_RoundTripsSecurityKeyAndCoid()
    {
        var original = new TransferFromGlobalPacket
        {
            SecurityKey = 0xDEADBEEFu,
            CharacterCoid = 0x1122334455667788L
        };

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        ms.Position = 0;
        var roundTrip = new TransferFromGlobalPacket();
        roundTrip.Read(new BinaryReader(ms));

        Assert.AreEqual(original.SecurityKey, roundTrip.SecurityKey);
        Assert.AreEqual(original.CharacterCoid, roundTrip.CharacterCoid);
    }

    [TestMethod]
    public void Stage3_OpcodeAndPositionRoundTrip()
    {
        Assert.AreEqual(GameOpcode.TransferFromGlobalStage3, new TransferFromGlobalStage3Packet().Opcode);

        var original = new TransferFromGlobalStage3Packet
        {
            SecurityKey = 1u,
            CharacterCoid = 2L,
            PositionX = 10.5f,
            PositionY = 20.5f,
            PositionZ = 30.5f
        };

        using var ms = new MemoryStream(new byte[64]);
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        ms.Position = 0;
        var roundTrip = new TransferFromGlobalStage3Packet();
        roundTrip.Read(new BinaryReader(ms));

        Assert.AreEqual(original.SecurityKey, roundTrip.SecurityKey);
        Assert.AreEqual(original.CharacterCoid, roundTrip.CharacterCoid);
        Assert.AreEqual(original.PositionX, roundTrip.PositionX);
        Assert.AreEqual(original.PositionY, roundTrip.PositionY);
        Assert.AreEqual(original.PositionZ, roundTrip.PositionZ);
    }

    [TestMethod]
    public void Read_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[2]);
        Assert.ThrowsException<EndOfStreamException>(() => new TransferFromGlobalPacket().Read(new BinaryReader(ms)));
    }
}
