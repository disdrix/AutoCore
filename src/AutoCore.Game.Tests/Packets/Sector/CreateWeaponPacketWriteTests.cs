using System.IO;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

[TestClass]
public class CreateWeaponPacketWriteTests
{
    [TestMethod]
    public void Write_EmitsWeaponSpecificFieldsWithoutThrowing()
    {
        var packet = new CreateWeaponPacket
        {
            CBID = 501,
            ObjectId = new TFID(9001, true),
            VarianceRange = 1.1f,
            VarianceRefireRate = 0.2f,
            VarianceDamageMinimum = 0.3f,
            VarianceDamageMaximum = 0.4f,
            VarianceOffensiveBonus = 5,
            PrefixAccuracyBonus = 0.5f,
            PrefixPenetrationBonus = 2,
            RechargeTime = 1500,
            Mass = 12.5f,
            RangeMinimum = 5f,
            RangeMaximum = 80f,
            ValidArc = 90f,
            MinimumDamage = DamageSpecific.CreateEmpty(),
            MaximumDamage = DamageSpecific.CreateEmpty(),
            Name = "Test Gun",
        };

        // Pre-sized buffer: base simple-object write uses Position skips for padding.
        var buf = new byte[1024];
        using var ms = new MemoryStream(buf);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);
        writer.Flush();

        Assert.IsTrue(ms.Position > 176, $"Expected full weapon body, position={ms.Position}");
    }

    [TestMethod]
    public void WriteEmptyPacket_AdvancesPastWeaponPad()
    {
        var buf = new byte[1024];
        using var ms = new MemoryStream(buf);
        using var writer = new BinaryWriter(ms);
        CreateWeaponPacket.WriteEmptyPacket(writer);
        writer.Flush();

        // Empty weapon is base simple empty + 176 pad.
        Assert.IsTrue(ms.Position >= 176, $"Expected empty weapon pad advance, position={ms.Position}");
    }
}
