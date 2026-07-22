using System.Reflection;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Global.Tests.Network;

using AutoCore.Global.Network;
using AutoCore.Utils.Commands;
using static GlobalServerTestHelpers;

[TestClass]
public class GlobalServerCommandTests
{
    private GlobalServer? _server;

    [TestCleanup]
    public void Cleanup()
    {
        if (_server != null)
            SafeShutdown(_server);
        _server = null;
    }

    [TestMethod]
    public void RegisterCommands_ExitIsDispatchableViaCommandProcessor()
    {
        _server = CreateServer();
        var commands = GetRegisteredCommands();

        Assert.IsTrue(commands.ContainsKey("exit"));
        Assert.IsNotNull(commands["exit"]);
    }

    [TestMethod]
    public void ProcessExitCommand_WithoutMinutes_SchedulesImmediateShutdownTimer()
    {
        _server = CreateServer();
        _server.Setup(CreateSetupConfig());

        InvokePrivate(_server, "ProcessExitCommand", new object[] { new[] { "exit" } });

        // 0 minutes => 0 ms timer; one MainLoop tick should fire Shutdown.
        _server.MainLoop(1);

        Assert.IsNull(_server.Interface, "exit timer with 0 minutes should invoke Shutdown.");
        Assert.IsFalse(_server.IsRunning);
        GC.SuppressFinalize(_server);
        _server = null;
    }

    [TestMethod]
    public void ProcessExitCommand_WithMinutes_SchedulesDelayedTimerWithoutImmediateShutdown()
    {
        _server = CreateServer();
        _server.Setup(CreateSetupConfig());

        InvokePrivate(_server, "ProcessExitCommand", new object[] { new[] { "exit", "5" } });

        // 5 minutes = 300000 ms; a single 1 ms tick must not fire.
        _server.MainLoop(1);

        Assert.IsNotNull(_server.Interface, "Delayed exit must not shut down after 1 ms.");
    }

    [TestMethod]
    public void ProcessExitCommand_InvalidMinutes_ThrowsFormatException()
    {
        _server = CreateServer();

        try
        {
            InvokePrivate(_server, "ProcessExitCommand", new object[] { new[] { "exit", "not-a-number" } });
            Assert.Fail("Expected FormatException via TargetInvocationException.");
        }
        catch (TargetInvocationException ex)
        {
            Assert.IsInstanceOfType(ex.InnerException, typeof(FormatException));
        }
    }

    [TestMethod]
    public void UnknownCommand_ProcessCommand_DoesNotThrowWhenNoConsoleInput()
    {
        // When console input is redirected / unavailable, ReadCommand returns null and ProcessCommand no-ops.
        CommandProcessor.ProcessCommand();
    }

    [TestMethod]
    public void RegisterCommand_Overwrite_IsLoggedAndReplacesHandler()
    {
        _server = CreateServer();
        var invoked = false;

        CommandProcessor.RegisterCommand("global.exit", _ => invoked = true);

        var commands = GetRegisteredCommands();
        commands["exit"](new[] { "exit" });

        Assert.IsTrue(invoked);

        // Restore server handler for other tests in this class.
        InvokePrivate(_server, "RegisterCommands");
    }
}
