using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Net;
using AutoCore.Communicator.Packets;

namespace AutoCore.Communicator.Tests.Packets;

[TestClass]
public class LoginRequestPacketTests
{
    [TestMethod]
    public void RoundTrip_PreservesFieldsAndOpcode()
    {
        var source = new LoginRequestPacket(PacketTestHelper.SampleServerData(), PacketTestHelper.SampleServerInfo());
        var bytes = PacketTestHelper.WritePacket(source);

        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);

        var opcode = (CommunicatorOpcode)br.ReadByte();
        var target = new LoginRequestPacket();
        target.Read(br);

        Assert.AreEqual(CommunicatorOpcode.LoginRequest, opcode);
        Assert.AreEqual(CommunicatorOpcode.LoginRequest, source.Opcode);
        Assert.AreEqual(source.Data.Id, target.Data.Id);
        Assert.AreEqual(source.Data.Password, target.Data.Password);
        Assert.AreEqual(source.Data.Address, target.Data.Address);
        Assert.AreEqual(source.Data.Port, target.Data.Port);
        Assert.AreEqual(source.InfoPacket.Info.Port, target.InfoPacket.Info.Port);
        Assert.AreEqual(source.InfoPacket.Info.AgeLimit, target.InfoPacket.Info.AgeLimit);
        Assert.AreEqual(source.InfoPacket.Info.PKFlag, target.InfoPacket.Info.PKFlag);
        Assert.AreEqual(source.InfoPacket.Info.CurrentPlayers, target.InfoPacket.Info.CurrentPlayers);
        Assert.AreEqual(source.InfoPacket.Info.MaxPlayers, target.InfoPacket.Info.MaxPlayers);
        Assert.AreEqual(bytes.Length, ms.Position);
    }

    [TestMethod]
    public void RoundTrip_IPv6Address_PreservesAddress()
    {
        var data = PacketTestHelper.SampleServerData();
        data.Address = IPAddress.Parse("2001:db8::1");
        var source = new LoginRequestPacket(data, PacketTestHelper.SampleServerInfo());

        var bytes = PacketTestHelper.WritePacket(source);
        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);
        _ = br.ReadByte();
        var target = new LoginRequestPacket();
        target.Read(br);

        Assert.AreEqual(data.Address, target.Data.Address);
    }

    [TestMethod]
    public void TruncatedBuffer_Throws()
    {
        var source = new LoginRequestPacket(PacketTestHelper.SampleServerData(), PacketTestHelper.SampleServerInfo());
        var bytes = PacketTestHelper.WritePacket(source);
        var truncated = bytes.Take(bytes.Length / 2).ToArray();

        PacketTestHelper.AssertTruncatedThrows(() =>
        {
            using var ms = new MemoryStream(truncated);
            using var br = new BinaryReader(ms);
            _ = br.ReadByte();
            new LoginRequestPacket().Read(br);
        });
    }

    [TestMethod]
    public void EmptyPassword_RoundTrips()
    {
        var data = PacketTestHelper.SampleServerData();
        data.Password = string.Empty;
        var source = new LoginRequestPacket(data, PacketTestHelper.SampleServerInfo());

        var bytes = PacketTestHelper.WritePacket(source);
        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);
        _ = br.ReadByte();
        var target = new LoginRequestPacket();
        target.Read(br);

        Assert.AreEqual(string.Empty, target.Data.Password);
    }

    [TestMethod]
    public void ToString_ContainsIdAndAddress()
    {
        var packet = new LoginRequestPacket(PacketTestHelper.SampleServerData(3), PacketTestHelper.SampleServerInfo());
        var text = packet.ToString();
        StringAssert.Contains(text, "LoginRequestPacket");
        StringAssert.Contains(text, "3");
    }
}
