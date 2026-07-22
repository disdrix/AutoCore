using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Launcher.Tests;

using AutoCore.Launcher.Bootstrap;

[TestClass]
public class LauncherConfigValidationTests
{
    [TestMethod]
    public void Validate_WithValidConfigs_Succeeds()
    {
        var result = LauncherConfigValidator.Validate(
            TestConfigFactory.CreateValidAuth(),
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsTrue(result.IsValid, result.FormatErrors());
        Assert.AreEqual(0, result.Errors.Count);
    }

    [TestMethod]
    public void Validate_MissingAuthConnectionString_FailsFast()
    {
        var auth = TestConfigFactory.CreateValidAuth();
        auth.AuthDatabaseConnectionString = "   ";

        var result = LauncherConfigValidator.Validate(
            auth,
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "Auth.AuthDatabaseConnectionString");
    }

    [TestMethod]
    public void Validate_MalformedConnectionString_FailsFast()
    {
        var global = TestConfigFactory.CreateValidGlobal();
        global.CharDatabaseConnectionString = "not-a-connection-string";

        var result = LauncherConfigValidator.Validate(
            TestConfigFactory.CreateValidAuth(),
            global,
            TestConfigFactory.CreateValidSector(),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "Global.CharDatabaseConnectionString");
        StringAssert.Contains(result.FormatErrors(), "not a valid connection string");
    }

    [TestMethod]
    public void Validate_MissingWorldConnectionString_FailsFast()
    {
        var global = TestConfigFactory.CreateValidGlobal();
        global.WorldDatabaseConnectionString = string.Empty;

        var result = LauncherConfigValidator.Validate(
            TestConfigFactory.CreateValidAuth(),
            global,
            TestConfigFactory.CreateValidSector(),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "Global.WorldDatabaseConnectionString");
    }

    [TestMethod]
    public void Validate_MissingGamePath_FailsFast()
    {
        var global = TestConfigFactory.CreateValidGlobal(gamePath: "   ");

        var result = LauncherConfigValidator.Validate(
            TestConfigFactory.CreateValidAuth(),
            global,
            TestConfigFactory.CreateValidSector(),
            _ => true);

        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "Global.GamePath is required");
    }

    [TestMethod]
    public void Validate_BadGamePath_FailsFast()
    {
        const string missingPath = @"C:\AutoCore\DoesNotExist\Game";
        var global = TestConfigFactory.CreateValidGlobal(gamePath: missingPath);

        var result = LauncherConfigValidator.Validate(
            TestConfigFactory.CreateValidAuth(),
            global,
            TestConfigFactory.CreateValidSector(gamePath: missingPath),
            _ => false);

        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "Global.GamePath does not exist");
        StringAssert.Contains(result.FormatErrors(), missingPath);
    }

    [TestMethod]
    public void Validate_InvalidAuthPort_FailsFast()
    {
        var auth = TestConfigFactory.CreateValidAuth();
        auth.AuthSocketPort = 0;

        var result = LauncherConfigValidator.Validate(
            auth,
            TestConfigFactory.CreateValidGlobal(),
            TestConfigFactory.CreateValidSector(),
            TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath));

        Assert.IsFalse(result.IsValid);
        StringAssert.Contains(result.FormatErrors(), "Auth.AuthSocketPort");
    }

    [TestMethod]
    public void ValidateOrThrow_WithInvalidConfig_ThrowsInvalidOperationException()
    {
        var auth = TestConfigFactory.CreateValidAuth();
        auth.AuthDatabaseConnectionString = string.Empty;

        var ex = Assert.ThrowsException<InvalidOperationException>(() =>
            LauncherConfigValidator.ValidateOrThrow(
                auth,
                TestConfigFactory.CreateValidGlobal(),
                TestConfigFactory.CreateValidSector(),
                TestConfigFactory.PathExistsFor(TestConfigFactory.ExistingGamePath)));

        StringAssert.Contains(ex.Message, "Auth.AuthDatabaseConnectionString");
    }

    [TestMethod]
    public void LoadConfig_MissingPrimaryFile_ThrowsFileNotFound()
    {
        var tempDir = CreateTempDirectory();
        try
        {
            var ex = Assert.ThrowsException<FileNotFoundException>(() =>
                LauncherConfigLoader.LoadAuthConfig(tempDir));

            StringAssert.Contains(ex.Message, LauncherConfigLoader.AuthConfigFileName);
        }
        finally
        {
            Directory.Delete(tempDir, recursive: true);
        }
    }

    [TestMethod]
    public void LoadConfig_ValidAuthJson_BindsConnectionStringAndPorts()
    {
        var tempDir = CreateTempDirectory();
        try
        {
            File.WriteAllText(
                Path.Combine(tempDir, LauncherConfigLoader.AuthConfigFileName),
                """
                {
                  "AuthDatabaseConnectionString": "Server=localhost;Database=auth;Uid=u;Password=p",
                  "AuthSocketPort": 3106,
                  "CommunicatorPort": 3107
                }
                """);

            var config = LauncherConfigLoader.LoadAuthConfig(tempDir);

            Assert.AreEqual("Server=localhost;Database=auth;Uid=u;Password=p", config.AuthDatabaseConnectionString);
            Assert.AreEqual(3106, config.AuthSocketPort);
            Assert.AreEqual(3107, config.CommunicatorPort);
        }
        finally
        {
            Directory.Delete(tempDir, recursive: true);
        }
    }

    [TestMethod]
    public void LoadConfig_ValidGlobalJson_BindsGamePathAndDatabases()
    {
        var tempDir = CreateTempDirectory();
        try
        {
            File.WriteAllText(
                Path.Combine(tempDir, LauncherConfigLoader.GlobalConfigFileName),
                """
                {
                  "CharDatabaseConnectionString": "Server=localhost;Database=char;Uid=u;Password=p",
                  "WorldDatabaseConnectionString": "Server=localhost;Database=world;Uid=u;Password=p",
                  "CommunicatorPort": 2107,
                  "GamePath": "C:/Games/AutoAssault",
                  "GameConfig": { "Port": 26880, "PublicAddress": "127.0.0.1" }
                }
                """);

            var config = LauncherConfigLoader.LoadGlobalConfig(tempDir);

            Assert.AreEqual("C:/Games/AutoAssault", config.GamePath);
            Assert.AreEqual("Server=localhost;Database=char;Uid=u;Password=p", config.CharDatabaseConnectionString);
            Assert.AreEqual(26880, config.GameConfig.Port);
        }
        finally
        {
            Directory.Delete(tempDir, recursive: true);
        }
    }

    [TestMethod]
    public void LoadConfig_EnvOverlay_OverridesPrimaryValues()
    {
        var tempDir = CreateTempDirectory();
        try
        {
            File.WriteAllText(
                Path.Combine(tempDir, LauncherConfigLoader.AuthConfigFileName),
                """
                {
                  "AuthDatabaseConnectionString": "Server=primary;Database=auth;Uid=u;Password=p",
                  "AuthSocketPort": 2106,
                  "CommunicatorPort": 2107
                }
                """);
            File.WriteAllText(
                Path.Combine(tempDir, LauncherConfigLoader.AuthEnvConfigFileName),
                """
                {
                  "AuthSocketPort": 9999
                }
                """);

            var config = LauncherConfigLoader.LoadAuthConfig(tempDir);

            Assert.AreEqual(9999, config.AuthSocketPort);
            Assert.AreEqual("Server=primary;Database=auth;Uid=u;Password=p", config.AuthDatabaseConnectionString);
        }
        finally
        {
            Directory.Delete(tempDir, recursive: true);
        }
    }

    private static string CreateTempDirectory()
    {
        var path = Path.Combine(Path.GetTempPath(), "AutoCore.Launcher.Tests", Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(path);
        return path;
    }
}
