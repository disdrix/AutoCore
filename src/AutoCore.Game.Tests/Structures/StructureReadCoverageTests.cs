using AutoCore.Game.Structures;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Structures;

/// <summary>Pure binary Read/ToString coverage for cold structure types.</summary>
[TestClass]
public class StructureReadCoverageTests
{
    [TestMethod]
    public void Vector3_ReadDistToString()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            w.Write(1f); w.Write(2f); w.Write(3f);
        }

        ms.Position = 0;
        var v = Vector3.ReadNew(new BinaryReader(ms));
        Assert.AreEqual(1f, v.X);
        Assert.AreEqual(2f, v.Y);
        Assert.AreEqual(3f, v.Z);
        Assert.AreEqual(0f, v.Dist(v));
        Assert.AreEqual(0f, v.DistSq(v));
        var other = new Vector3(4, 6, 3);
        Assert.AreEqual(25f, v.DistSq(other));
        Assert.AreEqual(5f, v.Dist(other));
        StringAssert.Contains(v.ToString(), "1");
    }

    [TestMethod]
    public void Vector4_ReadToVector3ToString()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            w.Write(1f); w.Write(2f); w.Write(3f); w.Write(4f);
        }

        ms.Position = 0;
        var v4 = Vector4.ReadNew(new BinaryReader(ms));
        var v3 = v4.ToVector3();
        Assert.AreEqual(1f, v3.X);
        Assert.AreEqual(3f, v3.Z);
        StringAssert.Contains(v4.ToString(), "4");
    }

    [TestMethod]
    public void Quaternion_ReadDefaultToString()
    {
        Assert.AreEqual(1f, Quaternion.Default.W);
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            w.Write(0.1f); w.Write(0.2f); w.Write(0.3f); w.Write(0.9f);
        }

        ms.Position = 0;
        var q = Quaternion.Read(new BinaryReader(ms));
        Assert.AreEqual(0.1f, q.X);
        Assert.AreEqual(0.9f, q.W);
        StringAssert.Contains(q.ToString(), "0.1");
    }

    [TestMethod]
    public void DamageSpecific_ReadWriteCreateEmpty()
    {
        var empty = DamageSpecific.CreateEmpty();
        Assert.AreEqual(6, empty.Damage.Length);

        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            for (short i = 0; i < 6; i++)
                w.Write(i);
        }

        ms.Position = 0;
        var d = DamageSpecific.ReadNew(new BinaryReader(ms));
        Assert.AreEqual((short)5, d.Damage[5]);

        using var outMs = new MemoryStream();
        using (var w = new BinaryWriter(outMs, System.Text.Encoding.UTF8, leaveOpen: true))
            d.Write(w);

        outMs.Position = 0;
        var roundTrip = new DamageSpecific();
        roundTrip.Read(new BinaryReader(outMs));
        CollectionAssert.AreEqual(d.Damage, roundTrip.Damage);
    }

    [TestMethod]
    public void Variable_Read_MapVersion46()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            w.Write(7); // Id
            w.Write((byte)2); // Type
            w.Write(1.5f); // Value
            w.Write(0.5f); // Initial
            w.Write(true); // UniqueForImport
            w.WriteUtf8StringOn("myvar", 64);
        }

        ms.Position = 0;
        var v = Variable.Read(new BinaryReader(ms), mapVersion: 46);
        Assert.AreEqual(7, v.Id);
        Assert.AreEqual((byte)2, v.Type);
        Assert.AreEqual(1.5f, v.Value);
        Assert.AreEqual(0.5f, v.InitialValue);
        Assert.IsTrue(v.UniqueForImport);
        Assert.AreEqual("myvar", v.Name);

        var test = Variable.CreateForTests(1, 0, 3f, 1f, "t");
        Assert.AreEqual("t", test.Name);
    }

    [TestMethod]
    public void FrontRear_Rgb_SkillElement_HeadBody_HeadDetail()
    {
        using (var ms = new MemoryStream())
        {
            using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            {
                w.Write(1.0f); w.Write(2.0f);
            }

            ms.Position = 0;
            var fr = FrontRear.ReadNew(new BinaryReader(ms));
            Assert.AreEqual(1.0f, fr.Front);
            Assert.AreEqual(2.0f, fr.Rear);
        }

        using (var ms = new MemoryStream())
        {
            using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            {
                w.Write(0.1f); w.Write(0.2f); w.Write(0.3f);
            }

            ms.Position = 0;
            var rgb = RGB.ReadNew(new BinaryReader(ms));
            Assert.AreEqual(0.1f, rgb.R);
            Assert.AreEqual(0.3f, rgb.B);
            StringAssert.Contains(rgb.ToString(), "R:");
        }

        using (var ms = new MemoryStream())
        {
            using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            {
                w.Write(10); // SkillId
                w.Write(2); // ElementType
                w.Write((byte)1); // EquationType
                w.Write(new byte[3]);
                w.Write(1.0f);
                w.Write(0.5f);
            }

            ms.Position = 0;
            var se = SkillElement.ReadNew(new BinaryReader(ms));
            Assert.AreEqual(10, se.SkillId);
            Assert.AreEqual(2, se.ElementType);
            Assert.AreEqual((byte)1, se.EquationType);
            Assert.AreEqual(1.0f, se.ValueBase);
            Assert.AreEqual(0.5f, se.ValuePerLevel);
        }

        using (var ms = new MemoryStream())
        {
            using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            {
                w.Write(1); // Id
                w.Write(2); // CloneBase
                w.Write(1); // IsHead
                w.Write(0); // IsBody
                // UTF16 string on 65 chars
                var name = "head.dat";
                var bytes = System.Text.Encoding.Unicode.GetBytes(name.PadRight(65, '\0'));
                w.Write(bytes);
                w.Write(new byte[2]); // pad
                w.Write(4); // MaxTextures
            }

            ms.Position = 0;
            var hb = HeadBody.ReadNew(new BinaryReader(ms));
            Assert.AreEqual(1, hb.Id);
            Assert.AreEqual(2, hb.CloneBase);
            Assert.AreEqual("head.dat", hb.FileName.TrimEnd('\0'));
            StringAssert.Contains(hb.ToString(), "Id:");
        }

        using (var ms = new MemoryStream())
        {
            using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            {
                w.Write(5); // Id
                w.Write(6); // HeadBody
                w.Write(7); // CloneBase
                var name = "detail.dat";
                var bytes = System.Text.Encoding.Unicode.GetBytes(name.PadRight(65, '\0'));
                w.Write(bytes);
                w.Write((byte)2); // Type
                w.Write((byte)0); // pad
                w.Write(3); // MaxTextures
                w.Write(1); // DisableHair
            }

            ms.Position = 0;
            var hd = HeadDetail.ReadNew(new BinaryReader(ms));
            Assert.AreEqual(5, hd.Id);
            Assert.AreEqual(7, hd.CloneBase);
            Assert.AreEqual((byte)2, hd.Type);
            Assert.AreEqual(1, hd.DisableHair);
            StringAssert.Contains(hd.ToString(), "Id:");
        }
    }

    [TestMethod]
    public void Skill_Read_WithElement()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            w.Write(100); // Id
            w.Write(1); // Class
            w.Write(2); // Race
            w.Write(0); // TargetType
            w.Write(0); // TargetSubType
            w.Write(0); // TargetObjectType
            w.Write(0); // AffectedTarget
            w.Write(0); // AffectedSubType
            w.Write(0); // AffectedObjectType
            w.Write(0); // StatusEffect
            w.Write(0); // prereq1
            w.Write(0); // prereq2
            w.Write(0); // prereq3
            w.Write((byte)1); // LocationTree
            w.Write((byte)2); // LocationLine
            w.Write((byte)5); // MinimumLevel
            w.Write((byte)0); // SkillType
            // Name UTF16 33, Description 1025, XMLName 65
            WriteUtf16On(w, "SkillA", 33);
            WriteUtf16On(w, "A skill", 1025);
            WriteUtf16On(w, "skill_a", 65);
            w.Write(new byte[2]);
            w.Write(0); // IsChain
            w.Write(0); // IsSpray
            w.Write((byte)0); // OptionalAction
            w.Write((byte)5); // MaxSkillLevel
            w.Write(new byte[2]);
            w.Write(0); // UseBodyForArc
            w.Write(10); // GroupId
            w.Write(11); // CategoryId
            w.Write(0); // SummonedCreatureId
            w.Write(0); w.Write(0); w.Write(0); w.Write(0); // optionals
            w.Write((short)1); // NumOfElements
            w.Write(new byte[2]);
            // one SkillElement
            w.Write(100); // SkillId
            w.Write(1); // ElementType
            w.Write((byte)0);
            w.Write(new byte[3]);
            w.Write(2.0f);
            w.Write(0.1f);
        }

        ms.Position = 0;
        var skill = Skill.Read(new BinaryReader(ms));
        Assert.AreEqual(100, skill.Id);
        Assert.AreEqual(1, skill.Class);
        Assert.AreEqual((byte)5, skill.MinimumLevel);
        Assert.AreEqual((byte)5, skill.MaxSkillLevel);
        Assert.AreEqual(10, skill.GroupId);
        Assert.AreEqual(1, skill.Elements.Count);
        Assert.AreEqual(2.0f, skill.Elements[0].ValueBase);
        Assert.AreEqual("SkillA", skill.Name.TrimEnd('\0'));
    }

    [TestMethod]
    public void SeaPlane_Reward_TimeCurve_PropertiesAssignable()
    {
        var plane = new SeaPlane
        {
            Coords = new Vector4(1, 2, 3, 4),
            CoordsList = new List<Vector4> { new(0, 0, 0, 0) },
        };
        Assert.AreEqual(1f, plane.Coords.X);
        Assert.AreEqual(1, plane.CoordsList.Count);

        var reward = new Reward { Level = 2, BaseAmount = 50, NumStops = 3 };
        Assert.AreEqual(50, reward.BaseAmount);

        var curve = new TimeCurve { NumStops = 2, Percentage = 0.5f };
        Assert.AreEqual(0.5f, curve.Percentage);
    }

    private static void WriteUtf16On(BinaryWriter w, string text, int charCount)
    {
        var padded = (text ?? "").PadRight(charCount, '\0');
        if (padded.Length > charCount)
            padded = padded[..charCount];
        w.Write(System.Text.Encoding.Unicode.GetBytes(padded));
    }
}
