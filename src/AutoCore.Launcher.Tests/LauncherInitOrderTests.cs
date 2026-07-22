using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Launcher.Tests;

using AutoCore.Launcher.Bootstrap;
using AutoCore.Launcher.Tests.Fakes;

[TestClass]
public class LauncherInitOrderTests
{
    [TestMethod]
    public void Run_WithFakes_CompletesExpectedOrderWithoutPortBind()
    {
        var events = new List<string>();
        var game = new FakeLauncherGameBootstrap(events);
        var auth = new FakeLauncherServerHost("Auth", eventLog: events);
        var global = new FakeLauncherServerHost("Global", eventLog: events);
        var sector = new FakeLauncherServerHost("Sector", eventLog: events);

        var result = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            game,
            auth,
            global,
            sector,
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsTrue(result.Success, result.ErrorMessage);
        CollectionAssert.AreEqual(
            LauncherInitOrchestrator.ExpectedSuccessfulOrder.ToList(),
            result.CompletedSteps.ToList());

        CollectionAssert.AreEqual(
            new[]
            {
                "InitializeConnectionStrings",
                "EnsureDatabasesCreated",
                "InitializeAssetManager",
                "LoadAllAssetData",
                "ApplyEarlyRuntimeConfig",
                "InitializeLootManager",
                "InitializeMapManager",
                "ApplyLateRuntimeConfig",
                "Auth.Setup",
                "Auth.Start",
                "Global.Setup",
                "Global.Start",
                "Sector.Setup",
                "Sector.Start",
            },
            events);

        Assert.IsTrue(auth.IsStarted);
        Assert.IsTrue(global.IsStarted);
        Assert.IsTrue(sector.IsStarted);
        Assert.AreEqual(TestConfigFactory.ExistingGamePath, game.LastGamePath);
        Assert.IsTrue(game.LastAllowMissingCbid);
    }

    [TestMethod]
    public void ExpectedServerStartOrder_IsAuthThenGlobalThenSector()
    {
        CollectionAssert.AreEqual(
            new[] { "Auth", "Global", "Sector" },
            LauncherInitOrchestrator.ExpectedServerStartOrder.ToList());
    }

    [TestMethod]
    public void Run_WhenAssetInitFails_StopsBeforeServerStart()
    {
        var events = new List<string>();
        var game = new FakeLauncherGameBootstrap(events, assetsInitialize: false);
        var auth = new FakeLauncherServerHost("Auth", eventLog: events);
        var global = new FakeLauncherServerHost("Global", eventLog: events);
        var sector = new FakeLauncherServerHost("Sector", eventLog: events);

        var result = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            game,
            auth,
            global,
            sector,
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.Success);
        Assert.AreEqual(LauncherInitStep.InitializeAssets, result.FailedStep);
        Assert.AreEqual(0, auth.SetupCount);
        Assert.AreEqual(0, global.StartCount);
        Assert.AreEqual(0, sector.StartCount);
        CollectionAssert.DoesNotContain(events, "Auth.Setup");
        StringAssert.Contains(result.ErrorMessage, "Asset Manager");
    }

    [TestMethod]
    public void Run_WhenAssetLoadFails_StopsBeforeRuntimeConfig()
    {
        var events = new List<string>();
        var game = new FakeLauncherGameBootstrap(events, assetsLoad: false);
        var auth = new FakeLauncherServerHost("Auth", eventLog: events);

        var result = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            game,
            auth,
            new FakeLauncherServerHost("Global", eventLog: events),
            new FakeLauncherServerHost("Sector", eventLog: events),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.Success);
        Assert.AreEqual(LauncherInitStep.LoadAssets, result.FailedStep);
        CollectionAssert.DoesNotContain(events, "ApplyEarlyRuntimeConfig");
        CollectionAssert.DoesNotContain(events, "Auth.Start");
    }

    [TestMethod]
    public void Run_WhenAuthStartFails_DoesNotStartGlobalOrSector()
    {
        var events = new List<string>();
        var game = new FakeLauncherGameBootstrap(events);
        var auth = new FakeLauncherServerHost("Auth", startSucceeds: false, eventLog: events);
        var global = new FakeLauncherServerHost("Global", eventLog: events);
        var sector = new FakeLauncherServerHost("Sector", eventLog: events);

        var result = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            game,
            auth,
            global,
            sector,
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.Success);
        Assert.AreEqual(LauncherInitStep.StartAuth, result.FailedStep);
        Assert.AreEqual(1, auth.SetupCount);
        Assert.AreEqual(1, auth.StartCount);
        Assert.AreEqual(0, global.SetupCount);
        Assert.AreEqual(0, sector.SetupCount);
        StringAssert.Contains(result.ErrorMessage, "Auth");
    }

    [TestMethod]
    public void Run_WhenGlobalStartFails_DoesNotStartSector()
    {
        var events = new List<string>();
        var result = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            new FakeLauncherGameBootstrap(events),
            new FakeLauncherServerHost("Auth", eventLog: events),
            new FakeLauncherServerHost("Global", startSucceeds: false, eventLog: events),
            new FakeLauncherServerHost("Sector", eventLog: events),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.Success);
        Assert.AreEqual(LauncherInitStep.StartGlobal, result.FailedStep);
        CollectionAssert.Contains(events, "Auth.Start");
        CollectionAssert.Contains(events, "Global.Start");
        CollectionAssert.DoesNotContain(events, "Sector.Setup");
    }

    [TestMethod]
    public void Run_WhenMapManagerFails_ContinuesToServerStart()
    {
        var events = new List<string>();
        var result = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            new FakeLauncherGameBootstrap(events, mapInitialize: false),
            new FakeLauncherServerHost("Auth", eventLog: events),
            new FakeLauncherServerHost("Global", eventLog: events),
            new FakeLauncherServerHost("Sector", eventLog: events),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsTrue(result.Success, result.ErrorMessage);
        CollectionAssert.Contains(events, "InitializeMapManager");
        CollectionAssert.Contains(events, "Sector.Start");
    }

    [TestMethod]
    public void Run_WhenConfigInvalid_FailsAtValidateAndSkipsDb()
    {
        var events = new List<string>();
        var auth = TestConfigFactory.CreateValidAuth();
        auth.AuthDatabaseConnectionString = string.Empty;

        var result = LauncherInitOrchestrator.Run(
            auth,
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            new FakeLauncherGameBootstrap(events),
            new FakeLauncherServerHost("Auth", eventLog: events),
            new FakeLauncherServerHost("Global", eventLog: events),
            new FakeLauncherServerHost("Sector", eventLog: events),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.Success);
        Assert.AreEqual(LauncherInitStep.ValidateConfig, result.FailedStep);
        CollectionAssert.DoesNotContain(events, "InitializeConnectionStrings");
        Assert.AreEqual(1, result.CompletedSteps.Count);
        Assert.AreEqual(LauncherInitStep.ValidateConfig, result.CompletedSteps[0]);
    }

    [TestMethod]
    public void Run_WhenCancelledBeforeStart_ReturnsCancelledWithoutStartingServers()
    {
        using var cts = new CancellationTokenSource();
        cts.Cancel();

        var events = new List<string>();
        var result = LauncherInitOrchestrator.Run(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            new FakeLauncherGameBootstrap(events),
            new FakeLauncherServerHost("Auth", eventLog: events),
            new FakeLauncherServerHost("Global", eventLog: events),
            new FakeLauncherServerHost("Sector", eventLog: events),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath),
            cts.Token);

        Assert.IsFalse(result.Success);
        Assert.IsTrue(result.Cancelled);
        Assert.AreEqual(0, events.Count);
    }
}
