using AutoCore.Game.Structures;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Structures;

[TestClass]
public class RoadNodeTests
{
    [TestMethod]
    public void RoadNode_Unserialize_BaseFields()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(42); // UniqueId
            writer.Write(1.0f); writer.Write(2.0f); writer.Write(3.0f); // Position
            writer.WriteUtf8StringOn("road.dat", 260);
            writer.Write(2); // node count
            writer.Write(10);
            writer.Write(20);
        }

        ms.Position = 0;
        var node = new RoadNode();
        node.Unserialize(new BinaryReader(ms), mapVersion: 1);

        Assert.AreEqual(42, node.UniqueId);
        Assert.AreEqual(1.0f, node.Position.X);
        Assert.AreEqual(2.0f, node.Position.Y);
        Assert.AreEqual(3.0f, node.Position.Z);
        Assert.AreEqual("road.dat", node.FileName);
        CollectionAssert.AreEqual(new[] { 10, 20 }, node.NodeIds);
    }

    [TestMethod]
    public void RoadNodeJunction_Unserialize_RotationAndVectors_WhenMapVersion28()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteBase(writer, uniqueId: 7);
            writer.Write(1.57f); // Rotation
            for (var i = 0; i < 6; i++)
            {
                writer.Write(i + 0.1f); writer.Write(i + 0.2f); writer.Write(i + 0.3f); // Positions
                writer.Write(i + 1.1f); writer.Write(i + 1.2f); writer.Write(i + 1.3f); // Directions
            }
        }

        ms.Position = 0;
        var node = new RoadNodeJunction();
        node.Unserialize(new BinaryReader(ms), mapVersion: 28);

        Assert.AreEqual(7, node.UniqueId);
        Assert.AreEqual(1.57f, node.Rotation);
        Assert.AreEqual(6, node.Positions.Count);
        Assert.AreEqual(6, node.Directions.Count);
        Assert.AreEqual(0.1f, node.Positions[0].X);
        Assert.AreEqual(1.1f, node.Directions[0].X);
    }

    [TestMethod]
    public void RoadNodeJunction_Unserialize_NoVectors_WhenMapVersionBelow28()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteBase(writer, uniqueId: 1);
            writer.Write(0.5f);
        }

        ms.Position = 0;
        var node = new RoadNodeJunction();
        node.Unserialize(new BinaryReader(ms), mapVersion: 27);

        Assert.AreEqual(0.5f, node.Rotation);
        Assert.AreEqual(0, node.Positions.Count);
    }

    [TestMethod]
    public void RiverNode_Unserialize_DepthAndColors()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteBase(writer, uniqueId: 3);
            writer.Write(4.5f); // WaterDepth
            writer.Write(0x11223344u); // Reflect
            writer.Write(0x55667788u); // Refract
        }

        ms.Position = 0;
        var node = new RiverNode();
        node.Unserialize(new BinaryReader(ms), mapVersion: 12);

        Assert.AreEqual(4.5f, node.WaterDepth);
        Assert.AreEqual(0x11223344u, node.ReflectColor);
        Assert.AreEqual(0x55667788u, node.RefractColor);
    }

    [TestMethod]
    public void RiverNode_Unserialize_NoColors_WhenMapVersionBelow12()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteBase(writer, uniqueId: 3);
            writer.Write(2.0f);
        }

        ms.Position = 0;
        var node = new RiverNode();
        node.Unserialize(new BinaryReader(ms), mapVersion: 11);

        Assert.AreEqual(2.0f, node.WaterDepth);
        Assert.AreEqual(0u, node.ReflectColor);
    }

    private static void WriteBase(BinaryWriter writer, int uniqueId)
    {
        writer.Write(uniqueId);
        writer.Write(0f); writer.Write(0f); writer.Write(0f);
        writer.WriteUtf8StringOn("n", 260);
        writer.Write(0); // node count
    }
}
