using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Login;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Login;

[TestClass]
public class LoginNewCharacterResponsePacketTests
{
    [TestMethod]
    public void Opcode_IsLoginNewCharacterResponse()
    {
        Assert.AreEqual(GameOpcode.LoginNewCharacterResponse, new LoginNewCharacterResponsePacket(0, 0).Opcode);
    }

    [TestMethod]
    public void Write_EmitsResultAndNewCharCoid()
    {
        var packet = new LoginNewCharacterResponsePacket(7u, 0x0102030405060708L);
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual(12, bytes.Length);
        Assert.AreEqual(7u, BitConverter.ToUInt32(bytes, 0));
        Assert.AreEqual(0x0102030405060708L, BitConverter.ToInt64(bytes, 4));
    }
}
