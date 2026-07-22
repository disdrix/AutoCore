using Microsoft.VisualStudio.TestTools.UnitTesting;
using AutoCore.Communicator.Packets;

namespace AutoCore.Communicator.Tests.Packets;

[TestClass]
public class ServerInfoRequestPacketTests
{
    [TestMethod]
    public void RoundTrip_PreservesOpcode_EmptyPayload()
    {
        var source = new ServerInfoRequestPacket();
        var bytes = PacketTestHelper.WritePacket(source);

        Assert.AreEqual(1, bytes.Length);
        Assert.AreEqual((byte)CommunicatorOpcode.ServerInfoRequest, bytes[0]);
        Assert.AreEqual(CommunicatorOpcode.ServerInfoRequest, source.Opcode);

        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);
        var opcode = (CommunicatorOpcode)br.ReadByte();
        var target = new ServerInfoRequestPacket();
        target.Read(br); // no-op body

        Assert.AreEqual(CommunicatorOpcode.ServerInfoRequest, opcode);
        Assert.AreEqual(bytes.Length, ms.Position);
    }

    [TestMethod]
    public void ToString_IsStable()
    {
        StringAssert.Contains(new ServerInfoRequestPacket().ToString(), "ServerInfoRequestPacket");
    }
}
