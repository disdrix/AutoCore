using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Sector;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class MapTransferRequestPacketTests
{
    [TestMethod]
    public void Opcode_IsMapTransferRequest()
    {
        Assert.AreEqual(GameOpcode.MapTransferRequest, new MapTransferRequestPacket().Opcode);
    }

    [TestMethod]
    public void Read_AllFields()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write((int)AutoCore.Game.Packets.Sector.MapTransferType.Highway);
            writer.Write(1234);
            writer.Write(0); // pad
            writer.Write(0x99L);
            writer.Write(true);
            writer.WriteUtf8StringOn("gm-arg", 50);
            writer.Write(new byte[5]);
        }

        ms.Position = 0;
        var packet = new MapTransferRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(AutoCore.Game.Packets.Sector.MapTransferType.Highway, packet.Type);
        Assert.AreEqual(1234, packet.Data);
        Assert.AreEqual(0x99L, packet.OptionalMapCoid);
        Assert.IsTrue(packet.PreferPVP);
        Assert.AreEqual("gm-arg", packet.GMParameter);
    }

    [TestMethod]
    public void Read_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[4]);
        Assert.ThrowsException<EndOfStreamException>(() => new MapTransferRequestPacket().Read(new BinaryReader(ms)));
    }
}
