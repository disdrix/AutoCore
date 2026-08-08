using System.Reflection;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Launcher.Tests;

using AutoCore.Database.Auth;
using AutoCore.Database.Char;
using AutoCore.Database.World;
using AutoCore.Game.Managers;
using AutoCore.Launcher.Bootstrap;

/// <summary>
/// Exercises bootstrap methods that do not require live MySQL or game asset packs.
/// </summary>
[TestClass]
public class DefaultLauncherGameBootstrapTests
{
    [TestInitialize]
    public void Init()
    {
        ResetConnectionString(typeof(AuthContext), string.Empty);
        ResetConnectionString(typeof(CharContext), null);
        ResetConnectionString(typeof(WorldContext), null);
        LootManager.Instance.ResetForTests();
    }

    [TestCleanup]
    public void Cleanup()
    {
        ResetConnectionString(typeof(AuthContext), string.Empty);
        ResetConnectionString(typeof(CharContext), null);
        ResetConnectionString(typeof(WorldContext), null);
        LootManager.Instance.ResetForTests();
    }

    [TestMethod]
    public void InitializeConnectionStrings_SetsAuthCharAndWorld()
    {
        var bootstrap = new DefaultLauncherGameBootstrap();
        var auth = TestConfigFactory.CreateValidAuth();
        var global = TestConfigFactory.CreateValidGlobal();

        auth.AuthDatabaseConnectionString = "Server=localhost;Database=auth_boot_test;";
        global.CharDatabaseConnectionString = "Server=localhost;Database=char_boot_test;";
        global.WorldDatabaseConnectionString = "Server=localhost;Database=world_boot_test;";

        bootstrap.InitializeConnectionStrings(auth, global);

        Assert.AreEqual(auth.AuthDatabaseConnectionString, AuthContext.ConnectionString);
        Assert.AreEqual(global.CharDatabaseConnectionString, CharContext.ConnectionString);
        Assert.AreEqual(global.WorldDatabaseConnectionString, WorldContext.ConnectionString);
    }

    [TestMethod]
    public void ApplyEarlyRuntimeConfig_ToleratesMissingConfigFiles()
    {
        var bootstrap = new DefaultLauncherGameBootstrap();
        var cwd = Environment.CurrentDirectory;
        var temp = Path.Combine(Path.GetTempPath(), "launcher-boot-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);

        try
        {
            Environment.CurrentDirectory = temp;
            // No loot.tuning.json / serverConfig.yaml in temp cwd — must not throw.
            bootstrap.ApplyEarlyRuntimeConfig();
        }
        finally
        {
            Environment.CurrentDirectory = cwd;
            try { Directory.Delete(temp, recursive: true); } catch { /* best effort */ }
        }
    }

    [TestMethod]
    public void ApplyLateRuntimeConfig_ToleratesMissingConfigFiles()
    {
        var bootstrap = new DefaultLauncherGameBootstrap();
        var cwd = Environment.CurrentDirectory;
        var temp = Path.Combine(Path.GetTempPath(), "launcher-boot-late-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(temp);

        try
        {
            Environment.CurrentDirectory = temp;
            bootstrap.ApplyLateRuntimeConfig();
        }
        finally
        {
            Environment.CurrentDirectory = cwd;
            try { Directory.Delete(temp, recursive: true); } catch { /* best effort */ }
        }
    }

    [TestMethod]
    public void InitializeLootManager_WithoutAssets_IsSafe()
    {
        var bootstrap = new DefaultLauncherGameBootstrap();
        // Empty AssetManager clone index — builds empty loot indexes and marks initialized.
        bootstrap.InitializeLootManager();
        // Second call is a no-op once initialized.
        bootstrap.InitializeLootManager();
    }

    [TestMethod]
    public void InitializeMapManager_WithoutContinents_ReturnsTrue()
    {
        var bootstrap = new DefaultLauncherGameBootstrap();
        // No continent objects loaded → MapManager continues with no maps.
        Assert.IsTrue(bootstrap.InitializeMapManager());
    }

    /// <summary>
    /// The Launcher hosts Auth/Global/Sector in one process and never runs
    /// <c>AutoCore.Sector/Program.cs</c>, so it must enable starting-area instancing itself.
    /// Without this, 698/707/708 silently fall back to one shared map and every player in
    /// Ark Bay sees every other player.
    /// </summary>
    [TestMethod]
    public void InitializeMapManager_EnablesStartingAreaInstancing()
    {
        AutoCore.Game.Map.InstancedContinents.SetForTests(null);
        Assert.IsFalse(AutoCore.Game.Map.InstancedContinents.IsInstanced(707),
            "Precondition: instancing is off before bootstrap runs.");

        new DefaultLauncherGameBootstrap().InitializeMapManager();

        Assert.IsTrue(AutoCore.Game.Map.InstancedContinents.IsInstanced(698));
        Assert.IsTrue(AutoCore.Game.Map.InstancedContinents.IsInstanced(707));
        Assert.IsTrue(AutoCore.Game.Map.InstancedContinents.IsInstanced(708));
        Assert.IsFalse(AutoCore.Game.Map.InstancedContinents.IsInstanced(1),
            "Non-starting-area continents must stay shared.");
    }

    private static void ResetConnectionString(Type contextType, string? unset)
    {
        var property = contextType.GetProperty(
            "ConnectionString",
            BindingFlags.Public | BindingFlags.Static);
        Assert.IsNotNull(property, $"{contextType.Name}.ConnectionString property missing.");
        property!.SetValue(null, unset);
    }
}
