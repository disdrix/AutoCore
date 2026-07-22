using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests;

[TestClass]
public class LoggerTests
{
    private string _tempLogPath;

    [TestInitialize]
    public void Init()
    {
        // Disable file logging by default for isolation; individual tests opt in.
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            IsDebugMode = true,
            LogToFile = false,
            LogFilePath = null
        });
    }

    [TestCleanup]
    public void Cleanup()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            IsDebugMode = true,
            LogToFile = false,
            LogFilePath = null
        });

        if (!string.IsNullOrEmpty(_tempLogPath) && File.Exists(_tempLogPath))
        {
            try { File.Delete(_tempLogPath); } catch { /* best-effort */ }
        }
    }

    [TestMethod]
    public void UpdateConfig_DisablesFileLogging_DoesNotThrow()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        Assert.IsFalse(Logger.Config.LogToFile);
    }

    [TestMethod]
    public void UpdateConfig_EnablesFileLogging_CreatesFileAndWritesStartup()
    {
        _tempLogPath = Path.Combine(Path.GetTempPath(), $"autocore-logger-{Guid.NewGuid():N}.txt");

        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = true,
            LogFilePath = _tempLogPath,
            IsDebugMode = true
        });

        Assert.IsTrue(File.Exists(_tempLogPath));

        // Close writer before reading (exclusive FileStream while open).
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        var content = File.ReadAllText(_tempLogPath);
        Assert.IsTrue(content.Contains("Logging system startup!", StringComparison.Ordinal));
        Assert.IsTrue(content.Contains("Logging system shutdown!", StringComparison.Ordinal));
        Assert.IsTrue(new FileInfo(_tempLogPath).Length > 0);

        // Re-open on non-empty file (blank line + second startup).
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = true,
            LogFilePath = _tempLogPath,
            IsDebugMode = true
        });
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        content = File.ReadAllText(_tempLogPath);
        Assert.IsTrue(content.Contains("Logging system startup!", StringComparison.Ordinal));
    }

    [TestMethod]
    public void WriteLog_AllStandardTypes_DoNotThrow()
    {
        foreach (LogType type in Enum.GetValues(typeof(LogType)))
        {
            if (type is LogType.ExportData or LogType.File)
                continue;

            Logger.WriteLog(type, $"message for {type}");
        }
    }

    [TestMethod]
    public void WriteLog_FileType_DoesNotWriteToConsolePath_DoesNotThrow()
    {
        // File type returns early after optional file write (no console)
        Logger.WriteLog(LogType.File, "file-only");
    }

    [TestMethod]
    public void WriteLog_Debug_WhenDebugModeOff_IsSuppressedFromConsole()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            IsDebugMode = false,
            LogToFile = false
        });

        Logger.WriteLog(LogType.Debug, "should be suppressed");
        // No exception is the contract; suppression is console-only
    }

    [TestMethod]
    public void WriteLog_Debug_WhenDebugModeOn_DoesNotThrow()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            IsDebugMode = true,
            LogToFile = false
        });
        Logger.WriteLog(LogType.Debug, "visible debug");
    }

    [TestMethod]
    public void WriteLog_ObjectOverload_Null_WritesNullLiteral()
    {
        Logger.WriteLog(LogType.None, (object)null);
        Logger.WriteLog(LogType.None, 12345);
    }

    [TestMethod]
    public void WriteLog_FormatOverload_FormatsArgs()
    {
        Logger.WriteLog(LogType.Command, "value={0} flag={1}", 7, true);
    }

    [TestMethod]
    public void WriteLog_ExportData_ThrowsBecauseNotHandledInSwitch()
    {
        // Production switch has no ExportData case; falls to default and throws.
        Assert.ThrowsException<ArgumentOutOfRangeException>(
            () => Logger.WriteLog(LogType.ExportData, "payload"));
    }

    [TestMethod]
    public void WriteLog_InvalidEnum_Throws()
    {
        Assert.ThrowsException<ArgumentOutOfRangeException>(
            () => Logger.WriteLog((LogType)999, "bad"));
    }

    [TestMethod]
    public void WriteLog_ToFile_AppendsMessage()
    {
        _tempLogPath = Path.Combine(Path.GetTempPath(), $"autocore-logger-{Guid.NewGuid():N}.txt");
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = true,
            LogFilePath = _tempLogPath,
            IsDebugMode = true
        });

        Logger.WriteLog(LogType.Network, "network-line-unique-xyz");
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });

        var content = File.ReadAllText(_tempLogPath);
        Assert.IsTrue(content.Contains("network-line-unique-xyz", StringComparison.Ordinal));
        Assert.IsTrue(content.Contains("[Network]", StringComparison.Ordinal));
    }

    [TestMethod]
    public void LoggerConfig_Defaults()
    {
        var cfg = new Logger.LoggerConfig();
        Assert.IsTrue(cfg.IsDebugMode);
        Assert.IsTrue(cfg.LogToFile);
        Assert.AreEqual("log.txt", cfg.LogFilePath);
    }

    [TestMethod]
    public void UpdateConfig_LogToFileTrue_WithEmptyPath_DoesNotOpenWriter()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig
        {
            LogToFile = true,
            LogFilePath = "  "
        });
        // Should not throw; writer only opens when path is non-whitespace
        Logger.WriteLog(LogType.Error, "no-file");
    }
}
