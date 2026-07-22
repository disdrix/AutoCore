using AutoCore.Game.Diagnostics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Diagnostics;

/// <summary>
/// File/env resolution paths for <see cref="LootTuning.ApplyFromConfigFiles"/>.
/// </summary>
[TestClass]
public class LootTuningConfigFileTests
{
    private string? _savedEnv;

    [TestInitialize]
    public void SetUp()
    {
        _savedEnv = Environment.GetEnvironmentVariable(LootTuning.ConfigFileEnvVar);
        Environment.SetEnvironmentVariable(LootTuning.ConfigFileEnvVar, null);
        LootTuning.ResetToDefaults();
    }

    [TestCleanup]
    public void TearDown()
    {
        Environment.SetEnvironmentVariable(LootTuning.ConfigFileEnvVar, _savedEnv);
        LootTuning.ResetToDefaults();
    }

    [TestMethod]
    public void ApplyFromConfigFiles_MissingFile_KeepsDefaults()
    {
        var root = Path.Combine(Path.GetTempPath(), "loot-cfg-missing-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try
        {
            LootTuning.ApplyFromConfigFiles(root);
            Assert.AreEqual(LootTuning.DefaultLootRate, LootTuning.LootRate, 1e-9);
            Assert.IsFalse(LootTuning.IgnoreDropCommoditiesGate);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_ContentRootFile_LoadsRate()
    {
        var root = Path.Combine(Path.GetTempPath(), "loot-cfg-root-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        var path = Path.Combine(root, LootTuning.DefaultConfigFileName);
        File.WriteAllText(path, """{"LootRate": 12.5, "IgnoreDropCommoditiesGate": true}""");
        try
        {
            LootTuning.ApplyFromConfigFiles(root);
            Assert.AreEqual(12.5, LootTuning.LootRate, 1e-9);
            Assert.IsTrue(LootTuning.IgnoreDropCommoditiesGate);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_EnvPath_TakesPrecedence()
    {
        var root = Path.Combine(Path.GetTempPath(), "loot-cfg-env-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        var envFile = Path.Combine(root, "custom-loot.json");
        File.WriteAllText(envFile, """{"LootRate": 77}""");
        Environment.SetEnvironmentVariable(LootTuning.ConfigFileEnvVar, envFile);
        try
        {
            // Even with a different content root, env wins.
            LootTuning.ApplyFromConfigFiles(Path.GetTempPath());
            Assert.AreEqual(77, LootTuning.LootRate, 1e-9);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_InvalidJson_KeepsDefaults()
    {
        var root = Path.Combine(Path.GetTempPath(), "loot-cfg-bad-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        File.WriteAllText(Path.Combine(root, LootTuning.DefaultConfigFileName), "{not-json");
        try
        {
            LootTuning.ApplyFromConfigFiles(root);
            Assert.AreEqual(LootTuning.DefaultLootRate, LootTuning.LootRate, 1e-9);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromJson_StringBooleansAndRates_Parse()
    {
        Assert.IsTrue(LootTuning.ApplyFromJson(
            """{"lootRate":"2.5","ignoreDropCommoditiesGate":"true"}""",
            out var error), error);
        Assert.AreEqual(2.5, LootTuning.LootRate, 1e-9);
        Assert.IsTrue(LootTuning.IgnoreDropCommoditiesGate);
    }

    [TestMethod]
    public void ApplyFromJson_BadGateType_Fails()
    {
        Assert.IsFalse(LootTuning.ApplyFromJson(
            """{"IgnoreDropCommoditiesGate": 1}""",
            out _));
    }

    [TestMethod]
    public void ApplyFromJson_Empty_Fails()
    {
        Assert.IsFalse(LootTuning.ApplyFromJson("   ", out var error));
        StringAssert.Contains(error, "empty");
    }

    [TestMethod]
    public void ApplyFromJson_NonObject_Fails()
    {
        Assert.IsFalse(LootTuning.ApplyFromJson("[1,2]", out _));
    }

    [TestMethod]
    public void Passes_ZeroScaled_IsFalse()
    {
        LootTuning.LootRate = 0;
        Assert.IsFalse(LootTuning.Passes(0.5, new Random(1)));
    }
}
