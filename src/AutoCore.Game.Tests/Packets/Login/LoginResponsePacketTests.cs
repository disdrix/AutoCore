using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Login;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Login;

[TestClass]
public class LoginResponsePacketTests
{
    [TestMethod]
    public void Opcode_IsLoginResponse()
    {
        Assert.AreEqual(GameOpcode.LoginResponse, new LoginResponsePacket(0).Opcode);
    }

    [TestMethod]
    public void Write_EmitsResultUint()
    {
        var packet = new LoginResponsePacket(0x42u);
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual(4, bytes.Length);
        Assert.AreEqual(0x42u, BitConverter.ToUInt32(bytes, 0));
        Assert.AreEqual(0x42u, packet.Result);
    }
}
