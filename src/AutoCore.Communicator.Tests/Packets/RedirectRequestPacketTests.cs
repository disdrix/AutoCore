using Microsoft.VisualStudio.TestTools.UnitTesting;
using AutoCore.Communicator.Packets;

namespace AutoCore.Communicator.Tests.Packets;

[TestClass]
public class RedirectRequestPacketTests
{
    [TestMethod]
    public void RoundTrip_PreservesFieldsAndOpcode()
    {
        var source = new RedirectRequestPacket(PacketTestHelper.SampleRedirectRequest());
        var bytes = PacketTestHelper.WritePacket(source);

        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);

        var opcode = (CommunicatorOpcode)br.ReadByte();
        var target = new RedirectRequestPacket();
        target.Read(br);

        Assert.AreEqual(CommunicatorOpcode.RedirectRequest, opcode);
        Assert.AreEqual(CommunicatorOpcode.RedirectRequest, source.Opcode);
        Assert.AreEqual(source.Request.AccountId, target.Request.AccountId);
        Assert.AreEqual(source.Request.Username, target.Request.Username);
        Assert.AreEqual(source.Request.Email, target.Request.Email);
        Assert.AreEqual(source.Request.OneTimeKey, target.Request.OneTimeKey);
        Assert.AreEqual(bytes.Length, ms.Position);
    }

    [TestMethod]
    public void TruncatedBuffer_Throws()
    {
        var source = new RedirectRequestPacket(PacketTestHelper.SampleRedirectRequest());
        var bytes = PacketTestHelper.WritePacket(source);
        var truncated = bytes.Take(3).ToArray();

        PacketTestHelper.AssertTruncatedThrows(() =>
        {
            using var ms = new MemoryStream(truncated);
            using var br = new BinaryReader(ms);
            _ = br.ReadByte();
            new RedirectRequestPacket().Read(br);
        });
    }

    [TestMethod]
    public void EmptyStrings_RoundTrip()
    {
        var request = new RedirectRequest
        {
            AccountId = 1,
            Username = string.Empty,
            Email = string.Empty,
            OneTimeKey = 0
        };
        var source = new RedirectRequestPacket(request);
        var bytes = PacketTestHelper.WritePacket(source);

        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);
        _ = br.ReadByte();
        var target = new RedirectRequestPacket();
        target.Read(br);

        Assert.AreEqual(string.Empty, target.Request.Username);
        Assert.AreEqual(string.Empty, target.Request.Email);
    }

    [TestMethod]
    public void ToString_ContainsAccountId()
    {
        var text = new RedirectRequestPacket(PacketTestHelper.SampleRedirectRequest()).ToString();
        StringAssert.Contains(text, "RedirectRequestPacket");
        StringAssert.Contains(text, "42");
    }
}
