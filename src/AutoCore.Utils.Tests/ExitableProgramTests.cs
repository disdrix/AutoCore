using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests;

/// <summary>
/// Only pure / init seams — does not exercise process exit.
/// </summary>
[TestClass]
public class ExitableProgramTests
{
    private sealed class TestableExitable : ExitableProgram
    {
        public static void CallInitialize(ExitEventHandler handler) => Initialize(handler);

        public static ExitEventHandler GetHandler() => ExitHandler;
    }

    [TestMethod]
    public void Initialize_RegistersHandler()
    {
        ExitEventHandler handler = sig => true;
        // SetConsoleCtrlHandler is a Windows native call; should succeed on this host.
        TestableExitable.CallInitialize(handler);
        Assert.IsNotNull(TestableExitable.GetHandler());
        // Multicast may accumulate; ensure our handler is part of the invocation list
        Assert.IsTrue(TestableExitable.GetHandler().GetInvocationList().Contains(handler));
    }
}
