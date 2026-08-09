using AutoCore.Game.Chat;
using AutoCore.Sim;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests;

[TestClass]
public class SimHostTests
{
    [TestCleanup]
    public void Cleanup()
    {
        CloneCommandControl.TryToggleClone = null;
    }

    [TestMethod]
    public void InstallCommandHook_WiresCloneCommandToSimHost()
    {
        SimHost.InstallCommandHook();

        Assert.IsNotNull(CloneCommandControl.TryToggleClone);

        var result = ChatCommandService.Instance.Execute(null, "/clone");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message, "No character");
    }

    [TestMethod]
    public void Tick_WithNoClones_DoesNotThrow()
    {
        SimHost.Instance.Tick(nowMs: 123, dt: 0.05f);
    }

    [TestMethod]
    public void SetFollowDistance_ParsesSetsAndReports()
    {
        try
        {
            var set = SimHost.Instance.SetFollowDistance(null, "40");
            StringAssert.Contains(set, "40");
            Assert.AreEqual(40f, AutoCore.Sim.Ai.CloneAiTuning.FollowDistanceOverride);

            var reset = SimHost.Instance.SetFollowDistance(null, "default");
            Assert.IsNull(AutoCore.Sim.Ai.CloneAiTuning.FollowDistanceOverride);
            StringAssert.Contains(reset.ToLowerInvariant(), "default");

            var bad = SimHost.Instance.SetFollowDistance(null, "abc");
            StringAssert.Contains(bad.ToLowerInvariant(), "usage");
        }
        finally
        {
            AutoCore.Sim.Ai.CloneAiTuning.FollowDistanceOverride = null;
        }
    }

    [TestMethod]
    public void SetHold_WithoutClone_SaysNoCloneActive()
    {
        var message = SimHost.Instance.SetCloneHold(null, hold: true);
        StringAssert.Contains(message, "No character");

        var character = new AutoCore.Game.Entities.Character();
        character.SetCoid(9901, true);
        var noClone = SimHost.Instance.SetCloneHold(character, hold: true);
        StringAssert.Contains(noClone.ToLowerInvariant(), "no clone");
    }

    [TestMethod]
    public void SetPathSpeed_ParsesSetsAndResets()
    {
        try
        {
            var set = SimHost.Instance.SetPathSpeed(null, "22");
            StringAssert.Contains(set, "22");
            Assert.AreEqual(22f, AutoCore.Sim.Ai.CloneAiTuning.PathSpeedOverride);

            var reset = SimHost.Instance.SetPathSpeed(null, "default");
            Assert.IsNull(AutoCore.Sim.Ai.CloneAiTuning.PathSpeedOverride);
            StringAssert.Contains(reset.ToLowerInvariant(), "default");

            var bad = SimHost.Instance.SetPathSpeed(null, "999");
            StringAssert.Contains(bad.ToLowerInvariant(), "usage");
        }
        finally
        {
            AutoCore.Sim.Ai.CloneAiTuning.PathSpeedOverride = null;
        }
    }

    [TestMethod]
    public void TrimClone_ParsesSetsAndReports()
    {
        try
        {
            var set = SimHost.Instance.TrimClone(null, "-0.35");
            StringAssert.Contains(set, "-0.35");
            Assert.AreEqual(-0.35f, AutoCore.Sim.Clone.CloneManager.HeightTrim, 0.001f);

            var query = SimHost.Instance.TrimClone(null, null);
            StringAssert.Contains(query, "-0.35");

            var bad = SimHost.Instance.TrimClone(null, "abc");
            StringAssert.Contains(bad.ToLowerInvariant(), "usage");
        }
        finally
        {
            AutoCore.Sim.Clone.CloneManager.HeightTrim = 0f;
        }
    }
}
