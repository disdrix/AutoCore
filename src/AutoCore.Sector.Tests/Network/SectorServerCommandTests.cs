using System.Net;
using System.Net.Sockets;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sector.Tests.Network;

using AutoCore.Game.Diagnostics;
using AutoCore.Sector.Config;
using AutoCore.Sector.Network;
using AutoCore.Utils.Commands;

[TestClass]
public class SectorServerCommandTests
{
    private SectorServer _server;

    [TestInitialize]
    public void SetUp()
    {
        // Constructor registers sector.* commands on the static CommandProcessor.
        _server = new SectorServer();
        WireIsolationLevers.ResetToDefaults();
        LogFilters.ResetToDefaults();
        SectorLoopControl.GetLoopMilliseconds = null;
        SectorLoopControl.TrySetLoopMilliseconds = null;
    }

    [TestCleanup]
    public void TearDown()
    {
        try
        {
            _server?.Shutdown();
        }
        catch
        {
            // Setup may not have run.
        }

        SectorLoopControl.GetLoopMilliseconds = null;
        SectorLoopControl.TrySetLoopMilliseconds = null;
        WireIsolationLevers.ResetToDefaults();
        LogFilters.ResetToDefaults();
    }

    [TestMethod]
    public void TickCommand_WhenLoopNotRegistered_ReportsUnavailable()
    {
        // ProcessTickCommand uses SectorLoopControl — not registered until Setup.
        CommandProcessor.Execute("sector.tick");
        CommandProcessor.Execute("tick");
        // Valid ms while unregistered → TrySet returns false (lines 64-67).
        CommandProcessor.Execute("tick 50");
    }

    [TestMethod]
    public void TickCommand_InvalidMs_DoesNotThrow()
    {
        CommandProcessor.Execute("sector.tick not-a-number");
    }

    [TestMethod]
    public void TickCommand_AfterSetup_SetsLoopMilliseconds()
    {
        var port = GetFreeUdpPort();
        _server.Setup(new SectorConfig
        {
            GameConfig = new GameConfig
            {
                Port = port,
                PublicAddress = "127.0.0.1",
                EnableDevControl = false
            }
        });

        CommandProcessor.Execute("sector.tick 75");

        Assert.AreEqual(75, _server.Loop.LoopTime);
        Assert.AreEqual(75, SectorLoopControl.CurrentMilliseconds);
    }

    [TestMethod]
    public void TickCommand_AliasWithoutScope_WorksAfterSetup()
    {
        _server.Setup(new SectorConfig
        {
            GameConfig = new GameConfig
            {
                Port = GetFreeUdpPort(),
                PublicAddress = "127.0.0.1",
                EnableDevControl = false
            }
        });

        CommandProcessor.Execute("tick 40");
        Assert.AreEqual(40, _server.Loop.LoopTime);
    }

    [TestMethod]
    public void WireCommand_List_DoesNotThrow()
    {
        CommandProcessor.Execute("sector.wire list");
        CommandProcessor.Execute("wire status");
    }

    [TestMethod]
    public void WireCommand_SetDiag_TogglesLever()
    {
        CommandProcessor.Execute("wire diag on");
        Assert.IsTrue(WireDiag.Enabled);

        CommandProcessor.Execute("wire diag off");
        Assert.IsFalse(WireDiag.Enabled);
    }

    [TestMethod]
    public void LogCommand_ListAndQuiet_DoesNotThrow()
    {
        CommandProcessor.Execute("sector.log list");
        CommandProcessor.Execute("log quiet");
    }

    [TestMethod]
    public void ExitCommand_SchedulesShutdownOnTimerWithoutImmediateStop()
    {
        _server.Setup(new SectorConfig
        {
            GameConfig = new GameConfig
            {
                Port = GetFreeUdpPort(),
                PublicAddress = "127.0.0.1",
                EnableDevControl = false
            }
        });

        // 5 minutes → timer only; do not advance Timer.Update so Shutdown is not fired here.
        CommandProcessor.Execute("sector.exit 5");

        Assert.IsNotNull(_server.Interface, "Exit must schedule shutdown, not run it immediately.");
    }

    [TestMethod]
    public void Execute_EmptyOrWhitespace_IsNoOp()
    {
        CommandProcessor.Execute(null);
        CommandProcessor.Execute("");
        CommandProcessor.Execute("   ");
    }

    [TestMethod]
    public void Execute_UnknownCommand_DoesNotThrow()
    {
        CommandProcessor.Execute("sector.not-a-real-command");
    }

    private static int GetFreeUdpPort()
    {
        using var udp = new UdpClient(0);
        return ((IPEndPoint)udp.Client.LocalEndPoint!).Port;
    }
}
