using AutoCore.Game.Diagnostics;
using AutoCore.Game.Npc;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Diagnostics;

/// <summary>
/// File/env resolution for <see cref="ServerConfig.ApplyFromConfigFiles"/>.
/// </summary>
[TestClass]
public class ServerConfigConfigFileTests
{
    private string? _savedEnv;

    [TestInitialize]
    public void SetUp()
    {
        _savedEnv = Environment.GetEnvironmentVariable(ServerConfig.ConfigFileEnvVar);
        Environment.SetEnvironmentVariable(ServerConfig.ConfigFileEnvVar, null);
        ServerConfig.ResetToDefaults();
        NpcVehicleDriveController.Enabled = false;
        SoftNpcPathMotion.Enabled = false;
    }

    [TestCleanup]
    public void TearDown()
    {
        Environment.SetEnvironmentVariable(ServerConfig.ConfigFileEnvVar, _savedEnv);
        ServerConfig.ResetToDefaults();
        NpcVehicleDriveController.Enabled = false;
        SoftNpcPathMotion.Enabled = false;
    }

    [TestMethod]
    public void ApplyFromConfigFiles_MissingFile_KeepsDefaults()
    {
        var root = Path.Combine(Path.GetTempPath(), "scfg-missing-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        try
        {
            ServerConfig.ApplyFromConfigFiles(root);
            Assert.IsFalse(ServerConfig.NpcVehiclePhysicsEnabled);
            Assert.AreEqual(NpcVehicleControllerTier.Hard, ServerConfig.ControllerTier);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_ContentRootYaml_Loads()
    {
        var root = Path.Combine(Path.GetTempPath(), "scfg-root-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        File.WriteAllText(Path.Combine(root, ServerConfig.DefaultConfigFileName), """
            enableRamming: true
            npcVehiclePhysics:
              enabled: true
              controllerTier: kinematic
              substepHz: 90
            """);
        try
        {
            ServerConfig.ApplyFromConfigFiles(root);
            Assert.IsTrue(ServerConfig.EnableRamming);
            Assert.IsTrue(ServerConfig.NpcVehiclePhysicsEnabled);
            Assert.AreEqual(NpcVehicleControllerTier.Kinematic, ServerConfig.ControllerTier);
            Assert.AreEqual(90, ServerConfig.SubstepHz);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_EnvPath_TakesPrecedence()
    {
        var root = Path.Combine(Path.GetTempPath(), "scfg-env-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        var envFile = Path.Combine(root, "custom-server.yaml");
        File.WriteAllText(envFile, "enableRamming: true");
        Environment.SetEnvironmentVariable(ServerConfig.ConfigFileEnvVar, envFile);
        try
        {
            ServerConfig.ApplyFromConfigFiles(Path.GetTempPath());
            Assert.IsTrue(ServerConfig.EnableRamming);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }

    [TestMethod]
    public void ApplyFromConfigFiles_MalformedYaml_KeepsDefaults()
    {
        var root = Path.Combine(Path.GetTempPath(), "scfg-bad-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(root);
        File.WriteAllText(Path.Combine(root, ServerConfig.DefaultConfigFileName), ":\n  - not: valid: yaml: [");
        try
        {
            ServerConfig.ApplyFromConfigFiles(root);
            Assert.IsFalse(ServerConfig.EnableRamming);
            Assert.IsFalse(ServerConfig.NpcVehiclePhysicsEnabled);
        }
        finally
        {
            Directory.Delete(root, recursive: true);
        }
    }
}
