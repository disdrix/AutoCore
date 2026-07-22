using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Global;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Global;

[TestClass]
public class NewsAndEventPacketTests
{
    [TestMethod]
    public void NewsPacket_Write_LanguageLengthAndText()
    {
        Assert.AreEqual(GameOpcode.News, new NewsPacket().Opcode);

        var packet = new NewsPacket("Hello news", 3u);
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        Assert.AreEqual(3u, reader.ReadUInt32());
        Assert.AreEqual("Hello news".Length + 1, reader.ReadInt32());
        var textBytes = new List<byte>();
        byte b;
        while ((b = reader.ReadByte()) != 0)
            textBytes.Add(b);
        Assert.AreEqual("Hello news", System.Text.Encoding.UTF8.GetString(textBytes.ToArray()));
    }

    [TestMethod]
    public void NewsPacket_Read_LanguageOnly()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(9u);
            writer.Write(5u); // length field (ignored by Read)
        }

        ms.Position = 0;
        var packet = new NewsPacket();
        packet.Read(new BinaryReader(ms));
        Assert.AreEqual(9u, packet.Language);
    }

    [TestMethod]
    public void EventStatusPacket_Write_IdAndStatus()
    {
        Assert.AreEqual(GameOpcode.EventStatus, new EventStatusPacket().Opcode);

        var packet = new EventStatusPacket { Id = 12, Status = 34 };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual(12, BitConverter.ToInt32(bytes, 0));
        Assert.AreEqual(34, BitConverter.ToInt32(bytes, 4));
    }
}
