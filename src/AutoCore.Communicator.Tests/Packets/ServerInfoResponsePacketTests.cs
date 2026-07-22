using Microsoft.VisualStudio.TestTools.UnitTesting;
using AutoCore.Communicator.Packets;

namespace AutoCore.Communicator.Tests.Packets;

[TestClass]
public class ServerInfoResponsePacketTests
{
    [TestMethod]
    public void RoundTrip_PreservesFieldsAndOpcode()
    {
        var info = PacketTestHelper.SampleServerInfo();
        var source = new ServerInfoResponsePacket(info);
        var bytes = PacketTestHelper.WritePacket(source);

        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);

        var opcode = (CommunicatorOpcode)br.ReadByte();
        var target = new ServerInfoResponsePacket();
        target.Read(br);

        Assert.AreEqual(CommunicatorOpcode.ServerInfoResponse, opcode);
        Assert.AreEqual(CommunicatorOpcode.ServerInfoResponse, source.Opcode);
        Assert.AreEqual(info.Port, target.Info.Port);
        Assert.AreEqual(info.AgeLimit, target.Info.AgeLimit);
        Assert.AreEqual(info.PKFlag, target.Info.PKFlag);
        Assert.AreEqual(info.CurrentPlayers, target.Info.CurrentPlayers);
        Assert.AreEqual(info.MaxPlayers, target.Info.MaxPlayers);
        Assert.AreEqual(bytes.Length, ms.Position);
    }

    [TestMethod]
    public void TruncatedBuffer_Throws()
    {
        var source = new ServerInfoResponsePacket(PacketTestHelper.SampleServerInfo());
        var bytes = PacketTestHelper.WritePacket(source);
        var truncated = bytes.Take(2).ToArray();

        PacketTestHelper.AssertTruncatedThrows(() =>
        {
            using var ms = new MemoryStream(truncated);
            using var br = new BinaryReader(ms);
            _ = br.ReadByte();
            new ServerInfoResponsePacket().Read(br);
        });
    }

    [TestMethod]
    public void DefaultCtor_EmptyInfo()
    {
        var packet = new ServerInfoResponsePacket();
        Assert.IsNotNull(packet.Info);
        Assert.AreEqual(0, packet.Info.Port);
    }

    [TestMethod]
    public void ToString_ContainsPort()
    {
        var text = new ServerInfoResponsePacket(PacketTestHelper.SampleServerInfo()).ToString();
        StringAssert.Contains(text, "ServerInfoResponsePacket");
        StringAssert.Contains(text, "27001");
    }
}
