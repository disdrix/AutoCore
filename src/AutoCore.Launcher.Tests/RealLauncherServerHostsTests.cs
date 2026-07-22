using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Launcher.Tests;

using AutoCore.Auth.Network;
using AutoCore.Database.Auth;
using AutoCore.Global.Network;
using AutoCore.Launcher.Bootstrap;
using AutoCore.Sector.Network;
using AutoCore.Utils.Commands;

/// <summary>
/// Real host adapters without calling <c>Start</c> (no shared ports).
/// </summary>
[TestClass]
public class RealLauncherServerHostsTests
{
    private Func<AuthContext>? _previousAuthFactory;

    [TestInitialize]
    public void Init()
    {
        _previousAuthFactory = AuthServer.CreateAuthContext;
        var dbName = "launcher-hosts-" + Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => new AuthContext(
            new DbContextOptionsBuilder<AuthContext>().UseInMemoryDatabase(dbName).Options);
    }

    [TestCleanup]
    public void Cleanup()
    {
        AuthServer.CreateAuthContext = _previousAuthFactory ?? (static () => new AuthContext());
        // Hosts register scoped exit commands; clear leftovers so other tests stay isolated.
        CommandProcessor.RemoveCommand("auth.exit");
        CommandProcessor.RemoveCommand("global.exit");
        CommandProcessor.RemoveCommand("sector.exit");
        CommandProcessor.RemoveCommand("exit");
    }

    [TestMethod]
    public void AuthHost_Ctor_NullArgs_Throw()
    {
        var server = new AuthServer();
        var config = TestConfigFactory.CreateValidAuth();

        Assert.ThrowsException<ArgumentNullException>(() => new AuthLauncherServerHost(null!, config));
        Assert.ThrowsException<ArgumentNullException>(() => new AuthLauncherServerHost(server, null!));

        SafeShutdownAuth(server);
    }

    [TestMethod]
    public void GlobalHost_Ctor_NullArgs_Throw()
    {
        var server = new GlobalServer();
        var config = TestConfigFactory.CreateValidGlobal();

        Assert.ThrowsException<ArgumentNullException>(() => new GlobalLauncherServerHost(null!, config));
        Assert.ThrowsException<ArgumentNullException>(() => new GlobalLauncherServerHost(server, null!));

        SafeShutdownGlobal(server);
    }

    [TestMethod]
    public void SectorHost_Ctor_NullArgs_Throw()
    {
        var server = new SectorServer();
        var config = TestConfigFactory.CreateValidSector();

        Assert.ThrowsException<ArgumentNullException>(() => new SectorLauncherServerHost(null!, config));
        Assert.ThrowsException<ArgumentNullException>(() => new SectorLauncherServerHost(server, null!));

        SafeShutdownSector(server);
    }

    [TestMethod]
    public void Hosts_NameProperties_MatchRoles()
    {
        var auth = new AuthLauncherServerHost(new AuthServer(), TestConfigFactory.CreateValidAuth());
        var global = new GlobalLauncherServerHost(new GlobalServer(), TestConfigFactory.CreateValidGlobal());
        var sector = new SectorLauncherServerHost(new SectorServer(), TestConfigFactory.CreateValidSector());

        Assert.AreEqual("Auth", auth.Name);
        Assert.AreEqual("Global", global.Name);
        Assert.AreEqual("Sector", sector.Name);

        // Never Start — only dispose via Shutdown after optional Setup.
        auth.Shutdown();
        global.Shutdown();
        sector.Shutdown();
        Assert.IsTrue(auth.IsShutdown);
        Assert.IsTrue(global.IsShutdown);
        Assert.IsTrue(sector.IsShutdown);
        Assert.IsFalse(auth.IsStarted);
        Assert.IsFalse(global.IsStarted);
        Assert.IsFalse(sector.IsStarted);
    }

    [TestMethod]
    public void Hosts_SetupThenShutdown_WithoutStart_IsSafe()
    {
        var authServer = new AuthServer();
        var globalServer = new GlobalServer();
        var sectorServer = new SectorServer();

        // Port 0 so Setup does not claim production Auth/Global/Sector ports if Start were ever called by mistake.
        var authConfig = TestConfigFactory.CreateValidAuth();
        authConfig.AuthSocketPort = 0;
        authConfig.CommunicatorPort = 0;

        var globalConfig = TestConfigFactory.CreateValidGlobal();
        globalConfig.GameConfig.Port = 0;

        var sectorConfig = TestConfigFactory.CreateValidSector();
        sectorConfig.GameConfig.Port = 0;

        var authHost = new AuthLauncherServerHost(authServer, authConfig);
        var globalHost = new GlobalLauncherServerHost(globalServer, globalConfig);
        var sectorHost = new SectorLauncherServerHost(sectorServer, sectorConfig);

        authHost.Setup();
        globalHost.Setup();
        sectorHost.Setup();

        Assert.IsFalse(authHost.IsStarted);
        Assert.IsFalse(globalHost.IsStarted);
        Assert.IsFalse(sectorHost.IsStarted);

        // Shutdown without Start must be safe (no listeners bound).
        sectorHost.Shutdown();
        globalHost.Shutdown();
        authHost.Shutdown();

        Assert.IsTrue(sectorHost.IsShutdown);
        Assert.IsTrue(globalHost.IsShutdown);
        Assert.IsTrue(authHost.IsShutdown);
        Assert.IsFalse(authHost.IsStarted);
    }

    private static void SafeShutdownAuth(AuthServer server)
    {
        try { server.Shutdown(); } catch { /* best effort */ }
        GC.SuppressFinalize(server);
    }

    private static void SafeShutdownGlobal(GlobalServer server)
    {
        try { server.Shutdown(); } catch { /* best effort */ }
        GC.SuppressFinalize(server);
        CommandProcessor.RemoveCommand("global.exit");
        CommandProcessor.RemoveCommand("exit");
    }

    private static void SafeShutdownSector(SectorServer server)
    {
        try { server.Shutdown(); } catch { /* best effort */ }
        GC.SuppressFinalize(server);
        CommandProcessor.RemoveCommand("sector.exit");
        CommandProcessor.RemoveCommand("exit");
    }
}
