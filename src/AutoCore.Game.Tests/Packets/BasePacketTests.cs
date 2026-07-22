using AutoCore.Game.Packets;
using AutoCore.Game.Packets.Login;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets;

[TestClass]
public class BasePacketTests
{
    [TestMethod]
    public void BasePacket_DefaultWrite_ThrowsWhenNotOverridden()
    {
        // LoginRequestPacket only overrides Read; Write falls through to BasePacket.
        var packet = new LoginRequestPacket();
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        Assert.ThrowsException<NotSupportedException>(() => packet.Write(writer));
    }

    [TestMethod]
    public void BasePacket_DefaultRead_ThrowsWhenNotOverridden()
    {
        var packet = new LoginResponsePacket(0);
        using var ms = new MemoryStream();
        using var reader = new BinaryReader(ms);
        Assert.ThrowsException<NotSupportedException>(() => packet.Read(reader));
    }
}
