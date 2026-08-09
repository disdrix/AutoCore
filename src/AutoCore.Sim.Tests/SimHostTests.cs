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
}
