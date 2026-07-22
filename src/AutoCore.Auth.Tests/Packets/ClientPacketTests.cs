using System.Text;
using AutoCore.Auth.Data;
using AutoCore.Auth.Packets.Client;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Parameters;

namespace AutoCore.Auth.Tests.Packets;

[TestClass]
public class ClientPacketTests
{
    [TestMethod]
    public void AboutToPlay_RoundTrip()
    {
        var original = new AboutToPlayPacket
        {
            SessionId1 = 0x11223344,
            SessionId2 = 0x55667788,
            ServerId = 3
        };

        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        Assert.AreEqual((byte)ClientOpcode.AboutToPlay, reader.ReadByte());

        var read = new AboutToPlayPacket();
        read.Read(reader);

        Assert.AreEqual(original.SessionId1, read.SessionId1);
        Assert.AreEqual(original.SessionId2, read.SessionId2);
        Assert.AreEqual(original.ServerId, read.ServerId);
        Assert.IsTrue(original.ToString().Contains("AboutToPlayPacket"));
    }

    [TestMethod]
    public void Logout_RoundTrip()
    {
        var original = new LogoutPacket { SessionId1 = 1, SessionId2 = 2 };
        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        Assert.AreEqual((byte)ClientOpcode.Logout, reader.ReadByte());

        var read = new LogoutPacket();
        read.Read(reader);
        Assert.AreEqual(1u, read.SessionId1);
        Assert.AreEqual(2u, read.SessionId2);
        Assert.IsTrue(original.ToString().Contains("LogoutPacket"));
    }

    [TestMethod]
    public void ServerListExt_RoundTrip()
    {
        var original = new ServerListExtPacket
        {
            SessionId1 = 9,
            SessionId2 = 8,
            ListKind = 1
        };

        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        Assert.AreEqual((byte)ClientOpcode.ServerListExt, reader.ReadByte());

        var read = new ServerListExtPacket();
        read.Read(reader);
        Assert.AreEqual(9u, read.SessionId1);
        Assert.AreEqual(8u, read.SessionId2);
        Assert.AreEqual((byte)1, read.ListKind);
        Assert.IsTrue(original.ToString().Contains("ServerListExtPacket"));
    }

    [TestMethod]
    public void SCCheck_RoundTrip()
    {
        var original = new SCCheckPacket { UserId = 42, CardValue = 99 };
        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        Assert.AreEqual((byte)ClientOpcode.SCCheck, reader.ReadByte());

        var read = new SCCheckPacket();
        read.Read(reader);
        Assert.AreEqual(42u, read.UserId);
        Assert.AreEqual(99u, read.CardValue);
        Assert.IsTrue(original.ToString().Contains("SCCheckPacket"));
    }

    [TestMethod]
    public void Login_Read_DecryptsDesCredentials()
    {
        // Layout: 30 encrypted bytes (14 user + 16 pass), then GameId u32, CDKey u16.
        var plain = new byte[30];
        Encoding.UTF8.GetBytes("testuser").CopyTo(plain, 0);
        Encoding.UTF8.GetBytes("secret").CopyTo(plain, 14);

        var key = new byte[] { 0x54, 0x45, 0x53, 0x54, 0x00, 0x00, 0x00, 0x00 };
        var engine = new DesEngine();
        engine.Init(true, new DesParameters(key));
        for (var i = 0; i < 24; i += 8)
            engine.ProcessBlock(plain, i, plain, i);

        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(plain);
            writer.Write(0x01020304u); // GameId
            writer.Write((ushort)0xABCD); // CDKey
        }

        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        var packet = new LoginPacket();
        packet.Read(reader);

        Assert.AreEqual("testuser", packet.UserName);
        Assert.AreEqual("secret", packet.Password);
        Assert.AreEqual(0x01020304u, packet.GameId);
        Assert.AreEqual((ushort)0xABCD, packet.CDKey);
        Assert.AreEqual(ClientOpcode.Login, packet.Opcode);
        Assert.IsTrue(packet.ToString().Contains("testuser"));
    }

    [TestMethod]
    public void Login_Read_UsesFullFieldWhenNoNullTerminator()
    {
        var plain = new byte[30];
        for (var i = 0; i < 14; i++)
            plain[i] = (byte)('A' + (i % 26));
        for (var i = 0; i < 16; i++)
            plain[14 + i] = (byte)('a' + (i % 26));

        var key = new byte[] { 0x54, 0x45, 0x53, 0x54, 0x00, 0x00, 0x00, 0x00 };
        var engine = new DesEngine();
        engine.Init(true, new DesParameters(key));
        for (var i = 0; i < 24; i += 8)
            engine.ProcessBlock(plain, i, plain, i);

        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(plain);
            writer.Write(7u);
            writer.Write((ushort)1);
        }

        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        var packet = new LoginPacket();
        packet.Read(reader);

        Assert.AreEqual(14, packet.UserName!.Length);
        Assert.AreEqual(16, packet.Password!.Length);
    }

    [TestMethod]
    public void Login_Write_ThrowsNotImplemented()
    {
        Assert.ThrowsException<NotImplementedException>(() =>
            new LoginPacket().Write(new BinaryWriter(new MemoryStream())));
    }
}
