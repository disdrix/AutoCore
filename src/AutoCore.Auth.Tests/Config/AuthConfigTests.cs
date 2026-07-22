using AutoCore.Auth.Config;
using AutoCore.Auth.Network;
using AutoCore.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Auth.Tests.Config;

[TestClass]
public class AuthConfigTests
{
    [TestMethod]
    public void Defaults_AreEmptyConnectionAndZeroPorts()
    {
        var config = new AuthConfig();
        Assert.AreEqual(string.Empty, config.AuthDatabaseConnectionString);
        Assert.AreEqual(0, config.AuthSocketPort);
        Assert.AreEqual(0, config.CommunicatorPort);
        Assert.IsNotNull(config.LoggerConfig);
    }

    [TestMethod]
    public void Properties_RoundTripAssignedValues()
    {
        var config = new AuthConfig
        {
            AuthDatabaseConnectionString = "Server=localhost;Database=auth;",
            AuthSocketPort = 2106,
            CommunicatorPort = 2107,
            LoggerConfig = new Logger.LoggerConfig { IsDebugMode = false, LogToFile = false }
        };

        Assert.AreEqual("Server=localhost;Database=auth;", config.AuthDatabaseConnectionString);
        Assert.AreEqual(2106, config.AuthSocketPort);
        Assert.AreEqual(2107, config.CommunicatorPort);
        Assert.IsFalse(config.LoggerConfig.IsDebugMode);
        Assert.IsFalse(config.LoggerConfig.LogToFile);
    }

    [TestMethod]
    public void ValidateConfig_RejectsZeroPorts()
    {
        Assert.IsFalse(AuthServer.ValidateConfig(new AuthConfig()));
        Assert.IsFalse(AuthServer.ValidateConfig(new AuthConfig { AuthSocketPort = 2106 }));
        Assert.IsFalse(AuthServer.ValidateConfig(new AuthConfig { CommunicatorPort = 2107 }));
    }

    [TestMethod]
    public void ValidateConfig_AcceptsNonZeroPorts()
    {
        Assert.IsTrue(AuthServer.ValidateConfig(new AuthConfig
        {
            AuthSocketPort = 2106,
            CommunicatorPort = 2107
        }));
    }
}
