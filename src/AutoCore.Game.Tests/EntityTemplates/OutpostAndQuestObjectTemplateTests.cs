using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.EntityTemplates;

[TestClass]
public class OutpostAndQuestObjectTemplateTests
{
    [TestMethod]
    public void QuestObjectTemplate_Constructor_SetsGraphicsPhysicsType()
    {
        var template = new QuestObjectTemplate();
        Assert.AreEqual(GraphicsObjectType.GraphicsPhysics, template.ObjectType);
        Assert.IsInstanceOfType(template.Create(), typeof(GraphicsObject));
    }

    [TestMethod]
    public void OutpostTemplate_Read_MapVersion59_AllFields()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            // Location Vector4
            writer.Write(1f); writer.Write(2f); writer.Write(3f); writer.Write(4f);
            writer.Write(0.5f); // Unk1
            writer.WriteUtf8StringOn("OutpostA", 65);
            writer.Write(1.25f); // XPScalar
            writer.Write(50f); // CaptureRadius (v>=56)
            writer.Write(3); // VarTotalBeacons
            writer.Write(true); // IsOutpost (v>=59)

            // 4 OutpostInformation slots (v>=57)
            for (var i = 0; i < 4; i++)
            {
                writer.Write((uint)(10 + i)); // BeaconVar
                writer.Write(1); // spawn count
                writer.Write(1000L + i);
                writer.Write(1); // object count
                writer.Write(2000L + i);
                writer.Write(1); // skill count
                writer.Write(30 + i); // SkillId
                writer.Write(2); // SkillLevel
                writer.Write(0.5f); // RequiredBeaconPercantage
                writer.Write(true); // Player
                writer.Write(new byte[3]); // pad
                writer.Write(1); // reaction count (v>=58)
                writer.Write(3000L + i);
            }
        }

        ms.Position = 0;
        var template = new OutpostTemplate();
        template.Read(new BinaryReader(ms), mapVersion: 59);

        Assert.AreEqual(1f, template.Location.X);
        Assert.AreEqual(4f, template.Location.W);
        Assert.AreEqual(0.5f, template.Unk1);
        Assert.AreEqual("OutpostA", template.Name);
        Assert.AreEqual(1.25f, template.XPScalar);
        Assert.AreEqual(50f, template.CaptureRadius);
        Assert.AreEqual(3, template.VarTotalBeacons);
        Assert.IsTrue(template.IsOutpost);
        Assert.AreEqual(4, template.OutpostInformations.Count);

        var first = template.OutpostInformations[0];
        Assert.AreEqual(10u, first.BeaconVar);
        Assert.AreEqual(1, first.Spawns.Count);
        Assert.AreEqual(1000L, first.Spawns[0]);
        Assert.AreEqual(1, first.Objects.Count);
        Assert.AreEqual(2000L, first.Objects[0]);
        Assert.AreEqual(1, first.OutpostSkills.Count);
        Assert.AreEqual(30, first.OutpostSkills[0].SkillId);
        Assert.AreEqual(2, first.OutpostSkills[0].SkillLevel);
        Assert.AreEqual(0.5f, first.OutpostSkills[0].RequiredBeaconPercantage);
        Assert.IsTrue(first.OutpostSkills[0].Player);
        Assert.AreEqual(1, first.Reactions.Count);
        Assert.AreEqual(3000L, first.Reactions[0]);
    }

    [TestMethod]
    public void OutpostTemplate_Read_MapVersionBelow56_SkipsCaptureAndBeacon()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0f); writer.Write(0f); writer.Write(0f); writer.Write(0f);
            writer.Write(0f);
            writer.WriteUtf8StringOn("Old", 65);
            writer.Write(1f);

            // 2 info slots for mapVersion < 57
            for (var i = 0; i < 2; i++)
            {
                writer.Write(0u);
                writer.Write(0); // spawns
                writer.Write(0); // objects
                writer.Write(0); // skills
                // no reactions when mapVersion < 58
            }
        }

        ms.Position = 0;
        var template = new OutpostTemplate();
        template.Read(new BinaryReader(ms), mapVersion: 55);

        Assert.AreEqual("Old", template.Name);
        Assert.AreEqual(0f, template.CaptureRadius);
        Assert.AreEqual(0, template.VarTotalBeacons);
        Assert.IsFalse(template.IsOutpost);
        Assert.AreEqual(2, template.OutpostInformations.Count);
        Assert.AreEqual(0, template.OutpostInformations[0].Reactions.Count);
    }

    [TestMethod]
    public void OutpostTemplate_Create_ReturnsNull()
    {
        Assert.IsNull(new OutpostTemplate().Create());
    }
}
