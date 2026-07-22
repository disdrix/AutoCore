using Microsoft.Extensions.Configuration;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sector.Tests.Config;

using AutoCore.Sector.Config;

[TestClass]
public class ProgramConfigValidationTests
{
    [TestMethod]
    public void Validate_ValidConfig_DoesNotThrow()
    {
        SectorConfigValidation.Validate(CreateValidConfig());
    }

    [TestMethod]
    public void Validate_NullConfig_Throws()
    {
        Assert.ThrowsException<ArgumentNullException>(() => SectorConfigValidation.Validate(null!));
    }

    [TestMethod]
    public void Validate_NullGameConfig_Throws()
    {
        var config = CreateValidConfig();
        config.GameConfig = null!;

        var ex = Assert.ThrowsException<InvalidOperationException>(() => SectorConfigValidation.Validate(config));
        StringAssert.Contains(ex.Message, "GameConfig");
    }

    [TestMethod]
    public void Validate_NonPositivePort_Throws()
    {
        var config = CreateValidConfig();
        config.GameConfig.Port = 0;

        var ex = Assert.ThrowsException<InvalidOperationException>(() => SectorConfigValidation.Validate(config));
        StringAssert.Contains(ex.Message, "Port");
    }

    [TestMethod]
    public void Validate_MissingPublicAddress_Throws()
    {
        var config = CreateValidConfig();
        config.GameConfig.PublicAddress = "  ";

        var ex = Assert.ThrowsException<InvalidOperationException>(() => SectorConfigValidation.Validate(config));
        StringAssert.Contains(ex.Message, "PublicAddress");
    }

    [TestMethod]
    public void Validate_MissingCharConnectionString_Throws()
    {
        var config = CreateValidConfig();
        config.CharDatabaseConnectionString = "";

        var ex = Assert.ThrowsException<InvalidOperationException>(() => SectorConfigValidation.Validate(config));
        StringAssert.Contains(ex.Message, "CharDatabaseConnectionString");
    }

    [TestMethod]
    public void Validate_MissingWorldConnectionString_Throws()
    {
        var config = CreateValidConfig();
        config.WorldDatabaseConnectionString = null!;

        var ex = Assert.ThrowsException<InvalidOperationException>(() => SectorConfigValidation.Validate(config));
        StringAssert.Contains(ex.Message, "WorldDatabaseConnectionString");
    }

    [TestMethod]
    public void Validate_MissingGamePath_Throws()
    {
        var config = CreateValidConfig();
        config.GamePath = "";

        var ex = Assert.ThrowsException<InvalidOperationException>(() => SectorConfigValidation.Validate(config));
        StringAssert.Contains(ex.Message, "GamePath");
    }

    [TestMethod]
    public void Validate_NegativeDevControlPort_Throws()
    {
        var config = CreateValidConfig();
        config.GameConfig.DevControlPort = -1;

        var ex = Assert.ThrowsException<InvalidOperationException>(() => SectorConfigValidation.Validate(config));
        StringAssert.Contains(ex.Message, "DevControlPort");
    }

    [TestMethod]
    public void Validate_EmptyAuthConnectionString_IsAllowed()
    {
        var config = CreateValidConfig();
        config.AuthDatabaseConnectionString = "";

        SectorConfigValidation.Validate(config);
    }

    [TestMethod]
    public void BindThenValidate_FromTempJson_Succeeds()
    {
        var path = Path.Combine(Path.GetTempPath(), $"sector-validate-{Guid.NewGuid():N}.json");
        try
        {
            File.WriteAllText(path, """
                {
                  "GameConfig": {
                    "Port": 27012,
                    "PublicAddress": "127.0.0.1",
                    "DevControlPort": 0
                  },
                  "CharDatabaseConnectionString": "Server=c;",
                  "WorldDatabaseConnectionString": "Server=w;",
                  "GamePath": "D:\\Game"
                }
                """);

            var config = SectorConfigValidation.Bind(new ConfigurationBuilder().AddJsonFile(path).Build());
            SectorConfigValidation.Validate(config);

            Assert.AreEqual(27012, config.GameConfig.Port);
            Assert.AreEqual(0, config.GameConfig.DevControlPort);
        }
        finally
        {
            if (File.Exists(path))
                File.Delete(path);
        }
    }

    private static SectorConfig CreateValidConfig()
    {
        return new SectorConfig
        {
            GameConfig = new GameConfig
            {
                Port = 27001,
                PublicAddress = "127.0.0.1",
                DevControlPort = 27999
            },
            CharDatabaseConnectionString = "Server=localhost;Database=char;",
            WorldDatabaseConnectionString = "Server=localhost;Database=world;",
            GamePath = @"C:\Program Files\AutoAssault"
        };
    }
}
