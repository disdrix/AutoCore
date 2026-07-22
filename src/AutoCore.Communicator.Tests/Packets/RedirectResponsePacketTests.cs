using Microsoft.VisualStudio.TestTools.UnitTesting;
using AutoCore.Communicator.Packets;

namespace AutoCore.Communicator.Tests.Packets;

[TestClass]
public class RedirectResponsePacketTests
{
    [TestMethod]
    [DataRow(true, 100u)]
    [DataRow(false, 0u)]
    public void RoundTrip_PreservesFieldsAndOpcode(bool success, uint accountId)
    {
        var source = new RedirectResponsePacket
        {
            Success = success,
            AccountId = accountId
        };
        var bytes = PacketTestHelper.WritePacket(source);

        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);

        var opcode = (CommunicatorOpcode)br.ReadByte();
        var target = new RedirectResponsePacket();
        target.Read(br);

        Assert.AreEqual(CommunicatorOpcode.RedirectResponse, opcode);
        Assert.AreEqual(CommunicatorOpcode.RedirectResponse, source.Opcode);
        Assert.AreEqual(success, target.Success);
        Assert.AreEqual(accountId, target.AccountId);
        Assert.AreEqual(bytes.Length, ms.Position);
    }

    [TestMethod]
    public void TruncatedBuffer_Throws()
    {
        var truncated = new byte[] { (byte)CommunicatorOpcode.RedirectResponse, 1, 2 };

        PacketTestHelper.AssertTruncatedThrows(() =>
        {
            using var ms = new MemoryStream(truncated);
            using var br = new BinaryReader(ms);
            _ = br.ReadByte();
            new RedirectResponsePacket().Read(br);
        });
    }

    [TestMethod]
    public void ToString_IncludesAccountId()
    {
        var text = new RedirectResponsePacket { AccountId = 99, Success = true }.ToString();
        StringAssert.Contains(text, "RedirectResponsePacket");
        StringAssert.Contains(text, "99");
    }
}
