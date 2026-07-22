using System.IO;
using System.Runtime.CompilerServices;
using AutoCore.Game.CloneBases;
using AutoCore.Game.CloneBases.Specifics;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Entities;

[TestClass]
public class WheelSetWriteToPacketTests
{
    [TestMethod]
    public void WriteToPacket_WithCloneBase_FillsFrictionFields()
    {
        var wheelSet = new WheelSet();
        wheelSet.SetCoid(5001, true);

        var clone = (CloneBaseWheelSet)RuntimeHelpers.GetUninitializedObject(typeof(CloneBaseWheelSet));
        clone.CloneBaseSpecific = new CloneBaseSpecific
        {
            Type = (int)CloneBaseObjectType.WheelSet,
            CloneBaseId = 42,
        };
        clone.SimpleObjectSpecific = new SimpleObjectSpecific { MaxHitPoint = 1 };
        clone.WheelSetSpecific = new WheelSetSpecific
        {
            Friction = new short[] { 10, 20, 30, 40, 50, 60 },
            NumWheelsAxle = new byte[] { 2, 2 },
            Wheel0Name = "w0",
            Wheel1Name = "w1",
            WheelSetType = 1,
        };
        wheelSet.AssignCloneBaseForTests(clone);

        var packet = new CreateWheelSetPacket
        {
            ObjectId = new TFID(5001, true),
            CBID = 42,
        };
        wheelSet.WriteToPacket(packet);

        Assert.AreEqual(10, packet.FrictionGravel);
        Assert.AreEqual(20, packet.FrictionIce);
        Assert.AreEqual(30, packet.FrictionMud);
        Assert.AreEqual(40, packet.FrictionPaved);
        Assert.AreEqual(50, packet.FrictionPlains);
        Assert.AreEqual(60, packet.FrictionSand);
        Assert.IsFalse(packet.IsDefault);
        Assert.AreEqual("", packet.Name);
    }

    [TestMethod]
    public void WriteToPacket_WithoutCloneBase_Throws()
    {
        var wheelSet = new WheelSet();
        wheelSet.SetCoid(5002, true);
        var packet = new CreateWheelSetPacket
        {
            ObjectId = new TFID(5002, true),
            CBID = -1,
        };

        Assert.ThrowsException<InvalidOperationException>(() => wheelSet.WriteToPacket(packet));
    }

    [TestMethod]
    public void WriteToPacket_NonWheelSetPacket_OnlyBaseWrite()
    {
        var wheelSet = new WheelSet();
        wheelSet.SetCoid(5003, true);
        var clone = (CloneBaseWheelSet)RuntimeHelpers.GetUninitializedObject(typeof(CloneBaseWheelSet));
        clone.CloneBaseSpecific = new CloneBaseSpecific
        {
            Type = (int)CloneBaseObjectType.WheelSet,
            CloneBaseId = 7,
        };
        clone.SimpleObjectSpecific = new SimpleObjectSpecific { MaxHitPoint = 1 };
        clone.WheelSetSpecific = new WheelSetSpecific { Friction = new short[6] };
        wheelSet.AssignCloneBaseForTests(clone);

        // Non-CreateWheelSetPacket path should not throw even if friction unused.
        var simple = new CreateSimpleObjectPacket
        {
            ObjectId = new TFID(5003, true),
            CBID = 7,
        };
        wheelSet.WriteToPacket(simple);
        Assert.AreEqual(7, simple.CBID);
    }
}
