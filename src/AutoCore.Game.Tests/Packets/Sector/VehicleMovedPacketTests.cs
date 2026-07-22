using AutoCore.Game.Constants;
using AutoCore.Game.Extensions;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class VehicleMovedPacketTests
{
    [TestMethod]
    public void Opcode_IsVehicleMoved()
    {
        Assert.AreEqual(GameOpcode.VehicleMoved, new VehicleMovedPacket().Opcode);
    }

    [TestMethod]
    public void Read_BaseObjectMovedPlusVehicleFields()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            // ObjectMovedPacket body
            writer.Write(0); // pad
            writer.WriteTFID(new TFID(100L, false));
            WriteVector3(writer, 1f, 2f, 3f); // Location
            WriteVector3(writer, 0.1f, 0.2f, 0.3f); // Velocity
            writer.Write(0f); writer.Write(0f); writer.Write(0f); writer.Write(1f); // Quaternion
            WriteVector3(writer, 0f, 0f, 0f); // AngularVelocity
            writer.Write(true); // Absolute
            writer.Write(new byte[3]);
            WriteVector3(writer, 5f, 6f, 7f); // TargetPosition
            writer.Write(0); // pad

            // VehicleMoved extension
            writer.Write(0.5f); // Acceleration
            writer.Write(-0.25f); // Steering
            writer.Write(1.5f); // TurretDirection
            writer.Write((byte)VehicleMovedFlags.Handbreak);
            writer.Write((byte)3); // Firing
            writer.Write((ushort)0); // unknown after firing
            writer.WriteTFID(new TFID(200L, true));
        }

        ms.Position = 0;
        var packet = new VehicleMovedPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(100L, packet.ObjectId.Coid);
        Assert.IsFalse(packet.ObjectId.Global);
        Assert.AreEqual(1f, packet.Location.X);
        Assert.AreEqual(2f, packet.Location.Y);
        Assert.AreEqual(3f, packet.Location.Z);
        Assert.IsTrue(packet.Absolute);
        Assert.AreEqual(0.5f, packet.Acceleration);
        Assert.AreEqual(-0.25f, packet.Steering);
        Assert.AreEqual(1.5f, packet.TurretDirection);
        Assert.AreEqual(VehicleMovedFlags.Handbreak, packet.VehicleFlags);
        Assert.AreEqual((byte)3, packet.Firing);
        Assert.AreEqual(200L, packet.Target.Coid);
        Assert.IsTrue(packet.Target.Global);
    }

    [TestMethod]
    public void Read_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[8]);
        Assert.ThrowsException<EndOfStreamException>(() => new VehicleMovedPacket().Read(new BinaryReader(ms)));
    }

    private static void WriteVector3(BinaryWriter writer, float x, float y, float z)
    {
        writer.Write(x);
        writer.Write(y);
        writer.Write(z);
    }
}
