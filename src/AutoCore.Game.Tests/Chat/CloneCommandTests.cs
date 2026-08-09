using AutoCore.Game.Chat;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Chat;

[TestClass]
public class CloneCommandTests
{
    [TestCleanup]
    public void Cleanup()
    {
        CloneCommandControl.TryToggleClone = null;
    }

    [TestMethod]
    public void Clone_NoHookInstalled_ReportsUnavailable()
    {
        CloneCommandControl.TryToggleClone = null;

        var result = ChatCommandService.Instance.Execute(null, "/clone");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "unavailable");
    }

    [TestMethod]
    public void Clone_HookInstalled_ReturnsHookMessage()
    {
        CloneCommandControl.TryToggleClone = _ => "Clone spawned.";

        var result = ChatCommandService.Instance.Execute(null, "/clone");

        Assert.IsTrue(result.Handled);
        Assert.AreEqual("Clone spawned.", result.Message);
    }

    [TestMethod]
    public void Unclone_RoutesToSameToggleHook()
    {
        var calls = 0;
        CloneCommandControl.TryToggleClone = _ => { calls++; return "toggled"; };

        var clone = ChatCommandService.Instance.Execute(null, "/clone");
        var unclone = ChatCommandService.Instance.Execute(null, "/unclone");

        Assert.IsTrue(clone.Handled);
        Assert.IsTrue(unclone.Handled);
        Assert.AreEqual(2, calls);
    }

    [TestMethod]
    public void CloneCommands_AreGmGated()
    {
        Assert.IsTrue(ChatAdminGate.IsMutatingCommand("/clone"));
        Assert.IsTrue(ChatAdminGate.IsMutatingCommand("/unclone"));
        Assert.IsTrue(ChatAdminGate.IsMutatingCommand("/clonetrim"));
    }

    [TestMethod]
    public void CloneTrim_RoutesArgumentToHook()
    {
        string seen = null;
        CloneCommandControl.TryTrimClone = (_, arg) => { seen = arg; return "trim set"; };

        var result = ChatCommandService.Instance.Execute(null, "/clonetrim -0.35");

        Assert.IsTrue(result.Handled);
        Assert.AreEqual("trim set", result.Message);
        Assert.AreEqual("-0.35", seen);

        CloneCommandControl.TryTrimClone = null;
        var unavailable = ChatCommandService.Instance.Execute(null, "/clonetrim 0.1");
        StringAssert.Contains(unavailable.Message.ToLowerInvariant(), "unavailable");
    }
}
