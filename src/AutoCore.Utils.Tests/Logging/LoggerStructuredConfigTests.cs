using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class LoggerStructuredConfigTests
{
    private string _path;

    [TestInitialize]
    public void Init()
    {
        _path = Path.Combine(Path.GetTempPath(), $"autocore-structured-{Guid.NewGuid():N}.ndjson");
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });

        try { File.Delete(_path); } catch (IOException) { /* best effort */ }
    }

    [TestMethod]
    public void UpdateConfig_WithStructuredLogPath_RoutesGameLogEventsToNdjsonFile()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = false,
            StructuredLogPath = _path
        });

        GameLog.Info("ConfiguredSinkEvent", ("Marker", "here"));
        GameLog.FlushForTests(TimeSpan.FromSeconds(5));

        Assert.IsTrue(File.Exists(_path), "Configuring StructuredLogPath must create the NDJSON sink.");

        var content = ReadAllTextShared(_path);
        StringAssert.Contains(content, "ConfiguredSinkEvent");
        StringAssert.Contains(content, "here");
    }

    [TestMethod]
    public void UpdateConfig_MinimumLevel_IsParsedAndApplied()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = false,
            StructuredLogPath = _path,
            StructuredMinimumLevel = "Warning"
        });

        Assert.AreEqual(StructuredLogLevel.Warning, GameLog.MinimumLevel,
            "The configured minimum level must be applied to the structured pipeline.");
    }

    [TestMethod]
    public void UpdateConfig_UnknownMinimumLevel_FallsBackToInfo_WithoutThrowing()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = false,
            StructuredLogPath = _path,
            StructuredMinimumLevel = "Chartreuse"
        });

        Assert.AreEqual(StructuredLogLevel.Info, GameLog.MinimumLevel,
            "A typo in configuration must degrade to the default, not crash startup.");
    }

    [TestMethod]
    public void UpdateConfig_PlaytestDiagnostics_LowersMinimumLevelToDebug()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = false,
            StructuredLogPath = _path,
            StructuredMinimumLevel = "Info",
            PlaytestDiagnostics = true
        });

        Assert.AreEqual(StructuredLogLevel.Debug, GameLog.MinimumLevel,
            "PlaytestDiagnostics is the one-switch verbose mode for playtest nights.");
    }

    [TestMethod]
    public void UpdateConfig_WithoutStructuredLogPath_LeavesStructuredPipelineDisabled()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });

        // Must be a no-op, not a crash.
        GameLog.Info("NoPipelineEvent");

        Assert.IsFalse(File.Exists(_path));
    }

    private static string ReadAllTextShared(string path)
    {
        using var stream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
        using var reader = new StreamReader(stream);
        return reader.ReadToEnd();
    }
}
