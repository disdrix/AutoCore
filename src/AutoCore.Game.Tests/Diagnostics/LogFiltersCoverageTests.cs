using AutoCore.Game.Diagnostics;
using AutoCore.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Diagnostics;

/// <summary>
/// Residual <see cref="LogFilters"/> coverage: console, config files, WriteIf, presets.
/// </summary>
[TestClass]
public class LogFiltersCoverageTests
{
    private string? _previousEnv;

    [TestInitialize]
    public void SetUp()
    {
        LogFilters.ResetToDefaults();
        WireDiag.Enabled = false;
        GhostObjectDiag.ResetForTests();
        _previousEnv = Environment.GetEnvironmentVariable(LogFilters.ConfigFileEnvVar);
        Environment.SetEnvironmentVariable(LogFilters.ConfigFileEnvVar, null);
    }

    [TestCleanup]
    public void TearDown()
    {
        LogFilters.ResetToDefaults();
        WireDiag.Enabled = false;
        GhostObjectDiag.ResetForTests();
        Environment.SetEnvironmentVariable(LogFilters.ConfigFileEnvVar, _previousEnv);
    }

    [TestMethod]
    public void FormatStatus_ListsKnownFilters()
    {
        var status = LogFilters.FormatStatus();
        StringAssert.Contains(status, "Loot");
        StringAssert.Contains(status, "TakeDamage");
        StringAssert.Contains(status, "OutgoingPackets");
    }

    [TestMethod]
    public void ApplyFromJson_EmptyAndNonObject_Fail()
    {
        Assert.IsFalse(LogFilters.ApplyFromJson("", out var err));
        StringAssert.Contains(err, "empty");
        Assert.IsFalse(LogFilters.ApplyFromJson("[1,2]", out err));
        StringAssert.Contains(err, "object");
    }

    [TestMethod]
    public void ApplyFromJson_NonBooleanLeaf_Fails()
    {
        Assert.IsFalse(LogFilters.ApplyFromJson("""{"Loot":123}""", out var err));
        StringAssert.Contains(err, "boolean");
    }

    [TestMethod]
    public void ApplyFromJson_StringBooleansAndUnknownKeys()
    {
        Assert.IsTrue(LogFilters.ApplyFromJson(
            """{"Loot":"off","NotAFilter":true,"Damage":{"OnDeath":"yes","Nope":false}}""",
            out var err), err);
        Assert.IsFalse(LogFilters.Loot);
        Assert.IsTrue(LogFilters.OnDeath);
    }

    [TestMethod]
    public void ApplyFromJson_InvalidJson_Fails()
    {
        Assert.IsFalse(LogFilters.ApplyFromJson("{not-json", out var err));
        Assert.IsFalse(string.IsNullOrEmpty(err));
    }

    [TestMethod]
    public void ApplyLootWorkPreset_MatchesQuiet()
    {
        LogFilters.OutgoingPackets = true;
        LogFilters.ApplyLootWorkPreset();
        Assert.IsFalse(LogFilters.OutgoingPackets);
        Assert.IsTrue(LogFilters.Loot);
        Assert.IsTrue(LogFilters.MapPropRam);
        Assert.IsTrue(LogFilters.TakeDamage);
    }

    [TestMethod]
    public void WriteIf_OnlyWhenEnabled()
    {
        // Must not throw either way; enabled path hits Logger.
        LogFilters.WriteIf(false, LogType.Debug, "silent");
        LogFilters.WriteIf(true, LogType.Debug, "visible");
        LogFilters.WriteIf(true, LogType.Debug, "fmt {0}", 1);
        LogFilters.WriteIf(false, LogType.Debug, "fmt {0}", 2);
    }

    [TestMethod]
    public void HandleConsoleCommand_ListSetResetQuietLootHelpUnknown()
    {
        LogFilters.HandleConsoleCommand(new[] { "log" }); // default list
        LogFilters.HandleConsoleCommand(new[] { "log", "list" });
        LogFilters.HandleConsoleCommand(new[] { "log", "status" });
        LogFilters.HandleConsoleCommand(new[] { "log", "show" });
        LogFilters.HandleConsoleCommand(new[] { "log", "help" });
        LogFilters.HandleConsoleCommand(new[] { "log", "?" });
        LogFilters.HandleConsoleCommand(new[] { "log", "notacommand" });

        LogFilters.HandleConsoleCommand(new[] { "log", "set", "Loot", "0" });
        Assert.IsFalse(LogFilters.Loot);
        LogFilters.HandleConsoleCommand(new[] { "log", "set", "Loot", "true" });
        Assert.IsTrue(LogFilters.Loot);
        LogFilters.HandleConsoleCommand(new[] { "log", "set", "Loot" }); // usage
        LogFilters.HandleConsoleCommand(new[] { "log", "set", "NotReal", "1" });

        LogFilters.HandleConsoleCommand(new[] { "log", "quiet" });
        LogFilters.HandleConsoleCommand(new[] { "log", "loot" });
        LogFilters.HandleConsoleCommand(new[] { "log", "reset" });
        LogFilters.HandleConsoleCommand(new[] { "log", "defaults" });
        Assert.IsTrue(LogFilters.Loot);
    }

    [TestMethod]
    public void ApplyFromConfigFiles_MissingFile_UsesDefaults()
    {
        var missingRoot = Path.Combine(Path.GetTempPath(), "autocore-logfilters-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(missingRoot);
        try
        {
            LogFilters.OutgoingPackets = true;
            LogFilters.ApplyFromConfigFiles(missingRoot);
            Assert.IsFalse(LogFilters.OutgoingPackets);
            Assert.IsTrue(LogFilters.Loot);
        }
        finally
        {
            Directory.Delete(missingRoot, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_LoadsJsonFromContentRoot()
    {
        var root = Path.Combine(Path.GetTempPath(), "autocore-logfilters-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        var path = Path.Combine(root, LogFilters.DefaultConfigFileName);
        File.WriteAllText(path, """{"OutgoingPackets":true,"Loot":false}""");
        try
        {
            LogFilters.ApplyFromConfigFiles(root);
            Assert.IsTrue(LogFilters.OutgoingPackets);
            Assert.IsFalse(LogFilters.Loot);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_EnvPath_OverridesContentRoot()
    {
        var root = Path.Combine(Path.GetTempPath(), "autocore-logfilters-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        var path = Path.Combine(root, "custom.filters.json");
        File.WriteAllText(path, """{"DeathNet":true}""");
        Environment.SetEnvironmentVariable(LogFilters.ConfigFileEnvVar, path);
        try
        {
            LogFilters.ApplyFromConfigFiles(contentRoot: null);
            Assert.IsTrue(LogFilters.DeathNet);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_InvalidFile_DoesNotThrow()
    {
        var root = Path.Combine(Path.GetTempPath(), "autocore-logfilters-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        File.WriteAllText(Path.Combine(root, LogFilters.DefaultConfigFileName), "{bad");
        try
        {
            LogFilters.ApplyFromConfigFiles(root);
            // Defaults re-applied before load; bad JSON leaves defaults.
            Assert.IsTrue(LogFilters.Loot);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void TrySet_WireDiagAndGhostObjectDiag()
    {
        Assert.IsTrue(LogFilters.TrySet("WireDiag", true, out var err), err);
        Assert.IsTrue(WireDiag.Enabled);
        Assert.IsTrue(LogFilters.TrySet("GhostObjectDiag", true, out err), err);
        Assert.IsTrue(GhostObjectDiag.Enabled);
    }
}
