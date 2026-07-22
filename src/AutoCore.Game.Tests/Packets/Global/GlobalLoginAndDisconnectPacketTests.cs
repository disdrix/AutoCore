using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Global;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Global;

[TestClass]
public class GlobalLoginAndDisconnectPacketTests
{
    [TestMethod]
    public void LoginPacket_Read_CharacterCoidAndSectorOverride()
    {
        Assert.AreEqual(GameOpcode.Login, new LoginPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0); // pad
            writer.Write(0xABCDEF01L);
            writer.Write(42);
        }

        ms.Position = 0;
        var packet = new LoginPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(0xABCDEF01L, packet.CharacterCoid);
        Assert.AreEqual(42, packet.StartSectorOverride);
    }

    [TestMethod]
    public void LoginAckPacket_Write_SuccessAndPad()
    {
        Assert.AreEqual(GameOpcode.LoginAck, new LoginAckPacket().Opcode);

        var packet = new LoginAckPacket { Success = true };
        using var ms = new MemoryStream(new byte[8]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        Assert.IsTrue(reader.ReadBoolean());
    }

    [TestMethod]
    public void DisconnectPacket_Read_IntentionalFlag()
    {
        Assert.AreEqual(GameOpcode.Disconnect, new DisconnectPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(true);
            writer.Write(new byte[3]);
        }

        ms.Position = 0;
        var packet = new DisconnectPacket();
        packet.Read(new BinaryReader(ms));
        Assert.IsTrue(packet.Intentional);
    }

    [TestMethod]
    public void DisconnectAckPacket_Write_EmptyBody()
    {
        Assert.AreEqual(GameOpcode.DisconnectAck, new DisconnectAckPacket().Opcode);

        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        new DisconnectAckPacket().Write(writer);
        Assert.AreEqual(0, ms.Length);
    }

    [TestMethod]
    public void LoginPacket_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[4]);
        Assert.ThrowsException<EndOfStreamException>(() => new LoginPacket().Read(new BinaryReader(ms)));
    }
}
