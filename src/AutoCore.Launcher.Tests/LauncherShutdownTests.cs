using System.Diagnostics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Launcher.Tests;

using AutoCore.Launcher.Bootstrap;
using AutoCore.Launcher.Tests.Fakes;

[TestClass]
public class LauncherShutdownTests
{
    [TestMethod]
    public void Shutdown_UsesReverseStartOrder_SectorGlobalAuth()
    {
        var events = new List<string>();
        var sector = new FakeLauncherServerHost("Sector", eventLog: events);
        var global = new FakeLauncherServerHost("Global", eventLog: events);
        var auth = new FakeLauncherServerHost("Auth", eventLog: events);

        // Pretend they were started.
        Assert.IsTrue(auth.Start());
        Assert.IsTrue(global.Start());
        Assert.IsTrue(sector.Start());
        events.Clear();

        var result = LauncherShutdownCoordinator.Shutdown(sector, global, auth);

        Assert.IsTrue(result.Completed);
        Assert.IsFalse(result.Cancelled);
        CollectionAssert.AreEqual(
            LauncherShutdownCoordinator.ExpectedShutdownOrder.ToList(),
            result.ShutDownHosts.ToList());
        CollectionAssert.AreEqual(
            new[] { "Sector.Shutdown", "Global.Shutdown", "Auth.Shutdown" },
            events);

        Assert.IsTrue(sector.IsShutdown);
        Assert.IsTrue(global.IsShutdown);
        Assert.IsTrue(auth.IsShutdown);
        Assert.IsFalse(sector.IsStarted);
        Assert.IsFalse(global.IsStarted);
        Assert.IsFalse(auth.IsStarted);
    }

    [TestMethod]
    public void ExpectedShutdownOrder_IsReverseOfStartOrder()
    {
        CollectionAssert.AreEqual(
            new[] { "Sector", "Global", "Auth" },
            LauncherShutdownCoordinator.ExpectedShutdownOrder.ToList());

        var start = LauncherInitOrchestrator.ExpectedServerStartOrder.ToArray();
        var expectedReverse = start.Reverse().ToArray();
        CollectionAssert.AreEqual(
            expectedReverse,
            LauncherShutdownCoordinator.ExpectedShutdownOrder.ToArray());
    }

    [TestMethod]
    public void Shutdown_WhenCancelledMidway_DoesNotHangAndStopsRemainingHosts()
    {
        using var cts = new CancellationTokenSource();
        var events = new List<string>();

        var sector = new FakeLauncherServerHost(
            "Sector",
            eventLog: events,
            onShutdown: () => cts.Cancel());
        var global = new FakeLauncherServerHost("Global", eventLog: events);
        var auth = new FakeLauncherServerHost("Auth", eventLog: events);

        var sw = Stopwatch.StartNew();
        var result = LauncherShutdownCoordinator.Shutdown(sector, global, auth, cts.Token);
        sw.Stop();

        Assert.IsTrue(result.Cancelled, "Cancellation after Sector should abort remaining hosts.");
        Assert.IsFalse(result.Completed);
        CollectionAssert.AreEqual(new[] { "Sector" }, result.ShutDownHosts.ToList());
        CollectionAssert.AreEqual(new[] { "Sector.Shutdown" }, events);
        Assert.AreEqual(0, global.ShutdownCount);
        Assert.AreEqual(0, auth.ShutdownCount);

        // Fail-fast: must not block waiting on ports or host I/O.
        Assert.IsTrue(sw.Elapsed < TimeSpan.FromSeconds(1),
            $"Shutdown after cancel took too long: {sw.Elapsed}");
    }

    [TestMethod]
    public void Shutdown_WhenAlreadyCancelled_ReturnsImmediatelyWithoutCallingHosts()
    {
        using var cts = new CancellationTokenSource();
        cts.Cancel();

        var events = new List<string>();
        var sector = new FakeLauncherServerHost("Sector", eventLog: events);
        var global = new FakeLauncherServerHost("Global", eventLog: events);
        var auth = new FakeLauncherServerHost("Auth", eventLog: events);

        var sw = Stopwatch.StartNew();
        var result = LauncherShutdownCoordinator.Shutdown(sector, global, auth, cts.Token);
        sw.Stop();

        Assert.IsTrue(result.Cancelled);
        Assert.AreEqual(0, result.ShutDownHosts.Count);
        Assert.AreEqual(0, events.Count);
        Assert.IsTrue(sw.Elapsed < TimeSpan.FromMilliseconds(500));
    }

    [TestMethod]
    public void Shutdown_DoesNotBindPorts()
    {
        // Pure fakes: coordinator only invokes Shutdown(); no sockets are opened.
        var listenersBefore = System.Net.NetworkInformation.IPGlobalProperties
            .GetIPGlobalProperties()
            .GetActiveTcpListeners()
            .Length;

        var result = LauncherShutdownCoordinator.Shutdown(
            new FakeLauncherServerHost("Sector"),
            new FakeLauncherServerHost("Global"),
            new FakeLauncherServerHost("Auth"));

        var listenersAfter = System.Net.NetworkInformation.IPGlobalProperties
            .GetIPGlobalProperties()
            .GetActiveTcpListeners()
            .Length;

        Assert.IsTrue(result.Completed);
        Assert.AreEqual(listenersBefore, listenersAfter,
            "Launcher shutdown coordinator must not open or bind any TCP ports.");
    }

    [TestMethod]
    public void InitThenShutdown_FullLifecycleWithFakes_IsOrderedAndPortFree()
    {
        var events = new List<string>();
        var game = new FakeLauncherGameBootstrap(events);
        var auth = new FakeLauncherServerHost("Auth", eventLog: events);
        var global = new FakeLauncherServerHost("Global", eventLog: events);
        var sector = new FakeLauncherServerHost("Sector", eventLog: events);

        var init = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            game,
            auth,
            global,
            sector,
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsTrue(init.Success, init.ErrorMessage);

        events.Clear();
        var shutdown = LauncherShutdownCoordinator.Shutdown(sector, global, auth);

        Assert.IsTrue(shutdown.Completed);
        CollectionAssert.AreEqual(
            new[] { "Sector.Shutdown", "Global.Shutdown", "Auth.Shutdown" },
            events);
    }
}
