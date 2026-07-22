using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Login;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Login;

[TestClass]
public class LoginRequestPacketTests
{
    [TestMethod]
    public void Opcode_IsLoginRequest()
    {
        Assert.AreEqual(GameOpcode.LoginRequest, new LoginRequestPacket().Opcode);
    }

    [TestMethod]
    public void Read_RoundTripsFieldsFromCraftedBuffer()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.WriteUtf8StringOn("player1", 33);
            writer.WriteUtf8StringOn("secret", 33);
            writer.Write(new byte[2]); // pad
            writer.Write(0x11223344u);
            writer.Write(0xAABBCCDDu);
        }

        ms.Position = 0;
        var packet = new LoginRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual("player1", packet.Username);
        Assert.AreEqual("secret", packet.Password);
        Assert.AreEqual(0x11223344u, packet.UserId);
        Assert.AreEqual(0xAABBCCDDu, packet.AuthKey);
    }

    [TestMethod]
    public void Read_TruncatedBuffer_Throws()
    {
        using var ms = new MemoryStream(new byte[10]);
        var packet = new LoginRequestPacket();
        Assert.ThrowsException<EndOfStreamException>(() => packet.Read(new BinaryReader(ms)));
    }
}
