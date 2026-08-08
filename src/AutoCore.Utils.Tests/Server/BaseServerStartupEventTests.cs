using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Server;

using AutoCore.Utils.Logging;
using AutoCore.Utils.Server;
using AutoCore.Utils.Tests.Logging;

[TestClass]
public class BaseServerStartupEventTests
{
    private InMemoryLogSink _sink;

    [TestInitialize]
    public void Init()
    {
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        GameLog.MinimumLevel = StructuredLogLevel.Trace;
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
    }

    /// <summary>
    /// With multiple builds being tested during the playtest, every server start must be
    /// attributable: which server, which build, which process instance.
    /// </summary>
    [TestMethod]
    public void InitConsole_EmitsServerStartingEvent_WithBuildIdentity()
    {
        new StartupProbeServer().InitConsole();

        var record = _sink.Single("ServerStarting");

        Assert.AreEqual("StartupProbe", record.GetProperty("ServerName"));
        Assert.AreEqual(ServerIdentity.BuildVersion, record.GetProperty("BuildVersion"));
        Assert.AreEqual(ServerIdentity.CommitHash, record.GetProperty("CommitHash"));
        Assert.AreEqual(ServerIdentity.ServerInstanceId, record.GetProperty("ServerInstanceId"));
    }

    private sealed class StartupProbeServer : BaseServer
    {
        public StartupProbeServer() : base("StartupProbe") { }

        public override bool IsRunning => false;
    }
}
