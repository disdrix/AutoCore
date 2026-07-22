using Microsoft.VisualStudio.TestTools.UnitTesting;
using AutoCore.Communicator.Packets;

namespace AutoCore.Communicator.Tests.Packets;

[TestClass]
public class LoginResponsePacketTests
{
    [TestMethod]
    [DataRow(true)]
    [DataRow(false)]
    public void RoundTrip_PreservesSuccessAndOpcode(bool success)
    {
        var source = new LoginResponsePacket { Success = success };
        var bytes = PacketTestHelper.WritePacket(source);

        using var ms = new MemoryStream(bytes);
        using var br = new BinaryReader(ms);

        var opcode = (CommunicatorOpcode)br.ReadByte();
        var target = new LoginResponsePacket();
        target.Read(br);

        Assert.AreEqual(CommunicatorOpcode.LoginResponse, opcode);
        Assert.AreEqual(CommunicatorOpcode.LoginResponse, source.Opcode);
        Assert.AreEqual(success, target.Success);
        Assert.AreEqual(bytes.Length, ms.Position);
    }

    [TestMethod]
    public void TruncatedBuffer_Throws()
    {
        // Opcode only — missing Success byte
        var truncated = new byte[] { (byte)CommunicatorOpcode.LoginResponse };

        PacketTestHelper.AssertTruncatedThrows(() =>
        {
            using var ms = new MemoryStream(truncated);
            using var br = new BinaryReader(ms);
            _ = br.ReadByte();
            new LoginResponsePacket().Read(br);
        });
    }

    [TestMethod]
    public void ToString_IncludesSuccess()
    {
        var text = new LoginResponsePacket { Success = true }.ToString();
        StringAssert.Contains(text, "LoginResponsePacket");
        StringAssert.Contains(text, "True");
    }
}
