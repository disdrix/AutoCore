using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.EntityTemplates;

/// <summary>
/// Binary <see cref="ReactionTemplate.Read"/> coverage for transfer/text/waypoint/dialog paths.
/// </summary>
[TestClass]
public class ReactionTemplateReadTests
{
    [TestMethod]
    public void Read_TransferMap_ParsesMapTransferFieldsAndReactions()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteCommonHeader(w, ReactionType.TransferMap, "xfer");
            w.Write((byte)MapTransferType.ContinentObject);
            w.Write(693); // MapTransferData
            w.Write(2); // reaction count
            w.Write(1001);
            w.Write(1002);
            // mapVersion >= 8 conditions
            w.Write(true); // AllConditionsNeeded
            w.Write(1); // condition count
            w.Write(1); // LeftId
            w.Write(2); // RightId
            w.Write((byte)ConditionalType.EqualTo);
            w.Write(new byte[3]); // pad
            w.Write(false); // DoForAllPlayers
        }

        ms.Position = 0;
        var tpl = new ReactionTemplate();
        tpl.Read(new BinaryReader(ms), mapVersion: 20);

        Assert.AreEqual("xfer", tpl.Name.TrimEnd('\0'));
        Assert.AreEqual(ReactionType.TransferMap, tpl.ReactionType);
        Assert.AreEqual(MapTransferType.ContinentObject, tpl.MapTransfer);
        Assert.AreEqual(693, tpl.MapTransferData);
        Assert.AreEqual(0, tpl.Objects.Count);
        CollectionAssert.AreEqual(new long[] { 1001, 1002 }, tpl.Reactions.ToArray());
        Assert.IsTrue(tpl.AllConditionsNeeded);
        Assert.AreEqual(1, tpl.Conditions.Count);
        Assert.AreEqual(1, tpl.Conditions[0].LeftId);
        Assert.AreEqual(ConditionalType.EqualTo, tpl.Conditions[0].Type);
        Assert.IsFalse(tpl.DoForAllPlayers);
    }

    [TestMethod]
    public void Read_TextWithReactionText_ParsesMainParamsAndChoices()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteCommonHeader(w, ReactionType.Text, "dialog");
            w.Write(1); // object count
            w.Write(55);
            w.Write(0); // reactions
            w.Write(true); // has text
            w.Write((byte)ReactionTextType.OKDialog);
            w.Write((byte)ReactionTextTargetType.Client);
            w.WriteLengthedString("Main text");
            w.Write(1); // param count
            w.Write((byte)ReactionTextParamType.Variable);
            w.Write(new byte[3]);
            w.Write(9); // Id
            w.Write(1.25f); // CachedValue (mapVersion >= 14)
            w.Write(1); // choice count
            w.Write(777L); // TriggerCoid
            w.WriteLengthedString("Choice A");
            w.Write(0); // choice params

            w.Write(false); // AllConditionsNeeded
            w.Write(0); // conditions
            w.Write(true); // DoForAllPlayers
        }

        ms.Position = 0;
        var tpl = new ReactionTemplate();
        tpl.Read(new BinaryReader(ms), mapVersion: 20);

        Assert.AreEqual(ReactionType.Text, tpl.ReactionType);
        CollectionAssert.AreEqual(new long[] { 55 }, tpl.Objects.ToArray());
        Assert.IsNotNull(tpl.Text);
        Assert.AreEqual(ReactionTextType.OKDialog, tpl.Text.Type);
        Assert.AreEqual("Main text", tpl.Text.Main);
        Assert.AreEqual(1, tpl.Text.Params.Count);
        Assert.AreEqual(9, tpl.Text.Params[0].Id);
        Assert.AreEqual(1.25f, tpl.Text.Params[0].CachedValue);
        Assert.AreEqual(1, tpl.Text.Choices.Count);
        Assert.AreEqual(777L, tpl.Text.Choices[0].TriggerCoid);
        Assert.AreEqual("Choice A", tpl.Text.Choices[0].Text);
        Assert.IsTrue(tpl.DoForAllPlayers);
    }

    [TestMethod]
    public void Read_TimerStart_ParsesMiscText()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteCommonHeader(w, ReactionType.TimerStart, "timer");
            w.Write(0); // objects
            w.Write(0); // reactions
            // no text block for non-Text type
            w.Write(false);
            w.Write(0);
            w.Write(false);
            w.WriteLengthedString("timer-name"); // MiscText (>=9)
        }

        ms.Position = 0;
        var tpl = new ReactionTemplate();
        tpl.Read(new BinaryReader(ms), mapVersion: 20);
        Assert.AreEqual("timer-name", tpl.MiscText);
    }

    [TestMethod]
    public void Read_AddWaypoint_ParsesWaypointTypeAndText()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteCommonHeader(w, ReactionType.AddWaypoint, "wp");
            w.Write(0);
            w.Write(0);
            w.Write(false);
            w.Write(0);
            w.Write(false);
            w.Write((int)ReactionWaypointType.Interact);
            w.WriteLengthedString("Go here");
        }

        ms.Position = 0;
        var tpl = new ReactionTemplate();
        tpl.Read(new BinaryReader(ms), mapVersion: 20);
        Assert.AreEqual(ReactionWaypointType.Interact, tpl.WaypointType);
        Assert.AreEqual("Go here", tpl.WaypointText);
    }

    [TestMethod]
    public void Read_GiveMissionDialog_ParsesMissionLists()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteCommonHeader(w, ReactionType.GiveMissionDialog, "missions");
            w.Write(0);
            w.Write(0);
            w.Write(false);
            w.Write(0);
            w.Write(false);
            // mapVersion > 16 && GiveMissionDialog
            w.Write(2); // mission type count
            w.Write(10);
            w.Write(20);
            w.Write(1); // mission count
            w.Write(470);
            // mapVersion >= 20 → no legacy skip block
        }

        ms.Position = 0;
        var tpl = new ReactionTemplate();
        tpl.Read(new BinaryReader(ms), mapVersion: 20);

        CollectionAssert.AreEqual(new[] { 10, 20 }, tpl.MissionTypes.ToArray());
        CollectionAssert.AreEqual(new[] { 470 }, tpl.Missions.ToArray());
    }

    [TestMethod]
    public void Read_GiveMissionDialog_MapVersion16_SkipsLegacyTail()
    {
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            WriteCommonHeader(w, ReactionType.Activate, "legacy"); // type ignored for mapVersion==16 mission block
            w.Write(0);
            w.Write(0);
            w.Write(false);
            w.Write(0);
            w.Write(false);
            // mapVersion == 16 always reads mission lists
            w.Write(0); // mission types
            w.Write(0); // missions
            // legacy skip: count * 4 + 4, then size
            w.Write(2); // count
            w.Write(1); w.Write(2); // 2 * 4
            w.Write(99); // +4
            w.Write(3); // size
            w.Write(new byte[3]);
        }

        ms.Position = 0;
        var tpl = new ReactionTemplate();
        tpl.Read(new BinaryReader(ms), mapVersion: 16);
        Assert.AreEqual(0, tpl.Missions.Count);
        Assert.AreEqual(ms.Length, ms.Position);
    }

    [TestMethod]
    public void Create_ReturnsReactionBoundToTemplate()
    {
        var tpl = new ReactionTemplate { COID = 42, ReactionType = ReactionType.Activate };
        var created = tpl.Create();
        Assert.IsInstanceOfType(created, typeof(Reaction));
        Assert.AreSame(tpl, ((Reaction)created).Template);
    }

    private static void WriteCommonHeader(BinaryWriter w, ReactionType type, string name)
    {
        w.WriteUtf8StringOn(name, 65);
        w.Write((byte)type);
        w.Write(true); // ActOnActivator
        w.Write(0); // ObjectiveIDCheck
        w.Write(false); // DoForConvoy
        w.Write(1); // GenericVar1
        w.Write(2.5f); // GenericVar2
        w.Write(3); // GenericVar3
    }
}
