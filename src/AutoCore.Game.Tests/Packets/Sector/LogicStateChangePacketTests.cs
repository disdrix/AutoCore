using System.IO;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class LogicStateChangePacketTests
{
    [TestMethod]
    public void Write_VariableType_WritesTypeAndPayload()
    {
        var packet = new LogicStateChangePacket(variableId: 12, value: 3.5f);
        // Pre-sized buffer so Position-pad advances stay in range (retail layout uses Position skips).
        var buf = new byte[64];
        using var ms = new MemoryStream(buf);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);
        writer.Flush();

        using var reader = new BinaryReader(new MemoryStream(buf));
        Assert.AreEqual((byte)LogicStateChangeType.Variable, reader.ReadByte());
        reader.BaseStream.Position += 3;
        Assert.AreEqual(12, reader.ReadInt32());
        Assert.AreEqual(3.5f, reader.ReadSingle(), 1e-5f);
    }

    [TestMethod]
    public void Write_ReactionType_WritesCoidAndActivator()
    {
        var packet = new LogicStateChangePacket(
            reactionCoid: 55_001,
            activator: new TFID(99, true),
            singleClientOnly: true);
        // Default Type is Reaction (0) when using the reaction ctor.
        Assert.AreEqual(LogicStateChangeType.Reaction, packet.Type);

        var buf = new byte[64];
        using var ms = new MemoryStream(buf);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);
        writer.Flush();

        using var reader = new BinaryReader(new MemoryStream(buf));
        Assert.AreEqual((byte)LogicStateChangeType.Reaction, reader.ReadByte());
        reader.BaseStream.Position += 3;
        Assert.AreEqual(55_001L, reader.ReadInt64());
        Assert.AreEqual(99L, reader.ReadInt64());
        Assert.IsTrue(reader.ReadBoolean());
    }

    [TestMethod]
    public void Write_UnknownType_Throws()
    {
        var packet = new LogicStateChangePacket(1, 1f)
        {
            Type = (LogicStateChangeType)99
        };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        Assert.ThrowsException<InvalidDataException>(() => packet.Write(writer));
    }
}
