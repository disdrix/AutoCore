using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Login;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Login;

[TestClass]
public class LoginDeleteCharacterPacketTests
{
    [TestMethod]
    public void Opcode_IsLoginDeleteCharacter()
    {
        Assert.AreEqual(GameOpcode.LoginDeleteCharacter, new LoginDeleteCharacterPacket().Opcode);
    }

    [TestMethod]
    public void Read_SkipsPadThenReadsCharacterCoid()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0); // pad
            writer.Write(0x1122334455667788L);
        }

        ms.Position = 0;
        var packet = new LoginDeleteCharacterPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(0x1122334455667788L, packet.CharacterCoid);
    }

    [TestMethod]
    public void Read_TruncatedBuffer_Throws()
    {
        using var ms = new MemoryStream(new byte[4]); // pad only
        var packet = new LoginDeleteCharacterPacket();
        Assert.ThrowsException<EndOfStreamException>(() => packet.Read(new BinaryReader(ms)));
    }
}
