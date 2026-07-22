using AutoCore.Game.Structures;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Structures;

[TestClass]
public class MusicAndVisualWaypointTests
{
    [TestMethod]
    public void Music_Read_MapVersionBelow42_ReturnsDefaults()
    {
        using var ms = new MemoryStream();
        var music = Music.Read(new BinaryReader(ms), mapVersion: 41);
        Assert.IsNull(music.Name);
        Assert.AreEqual(0f, music.MaxRadius);
    }

    [TestMethod]
    public void Music_Read_MapVersion42_AllFields()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.WriteLengthedString("theme");
            writer.Write(true); // Looping
            writer.Write(false); // SilenceAtMaxRadius
            writer.Write(1.0f); // DurationForRepeat
            writer.Write(0.5f); // FadeIn
            writer.Write(0.25f); // FadeOut
            writer.Write(50f); // MaxRadius
            writer.Write(10f); writer.Write(20f); writer.Write(30f);
            writer.Write((int)Music.MusicType.Foreground);
        }

        ms.Position = 0;
        var music = Music.Read(new BinaryReader(ms), mapVersion: 42);

        Assert.AreEqual("theme", music.Name);
        Assert.IsTrue(music.Looping);
        Assert.IsFalse(music.SilenceAtMaxRadius);
        Assert.AreEqual(1.0f, music.DurationForRepeat);
        Assert.AreEqual(0.5f, music.FadeInTime);
        Assert.AreEqual(0.25f, music.FadeOutTime);
        Assert.AreEqual(50f, music.MaxRadius);
        Assert.AreEqual(10f, music.X);
        Assert.AreEqual(20f, music.Y);
        Assert.AreEqual(30f, music.Z);
        Assert.AreEqual(Music.MusicType.Foreground, music.Type);
    }

    [TestMethod]
    public void Music_Read_ZeroMaxRadius_DefaultsTo10()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.WriteLengthedString("x");
            writer.Write(false);
            writer.Write(false);
            writer.Write(0f);
            writer.Write(0f);
            writer.Write(0f);
            writer.Write(0f); // MaxRadius <= 0
            writer.Write(0f); writer.Write(0f); writer.Write(0f);
            writer.Write(0);
        }

        ms.Position = 0;
        var music = Music.Read(new BinaryReader(ms), mapVersion: 42);
        Assert.AreEqual(10.0f, music.MaxRadius);
    }

    [TestMethod]
    public void VisualWaypoint_Read_FieldsAndObjectives()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0); // discarded int
            writer.Write(15); // Id
            writer.Write((byte)2); // Type
            writer.Write(1f); writer.Write(2f); writer.Write(3f); // Position
            writer.Write(100L); // ObjectCoid
            writer.Write(200L); // ReactionCoid
            writer.Write(3); // ObjectiveCount
            writer.Write(11);
            writer.Write(22);
            writer.Write(33);
        }

        ms.Position = 0;
        var wp = VisualWaypoint.Read(new BinaryReader(ms));

        Assert.AreEqual(15, wp.Id);
        Assert.AreEqual((byte)2, wp.Type);
        Assert.AreEqual(1f, wp.Position.X);
        Assert.AreEqual(2f, wp.Position.Y);
        Assert.AreEqual(3f, wp.Position.Z);
        Assert.AreEqual(100L, wp.ObjectCoid);
        Assert.AreEqual(200L, wp.ReactionCoid);
        Assert.AreEqual(3, wp.ObjectiveCount);
        CollectionAssert.AreEqual(new[] { 11, 22, 33 }, wp.Objectives);
    }
}
