using AutoCore.Auth.Config;
using AutoCore.Auth.Network;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Auth.Tests.Config;

/// <summary>
/// Program.Main is an integration entrypoint (config bind + DB + Start).
/// Port validation is extracted to <see cref="AuthServer.ValidateConfig"/> for unit coverage.
/// </summary>
[TestClass]
public class AuthConfigValidationTests
{
    [TestMethod]
    [DataRow(0, 0, false)]
    [DataRow(2106, 0, false)]
    [DataRow(0, 2107, false)]
    [DataRow(2106, 2107, true)]
    [DataRow(1, 1, true)]
    public void ValidateConfig_PortMatrix(int authPort, int commPort, bool expected)
    {
        var config = new AuthConfig
        {
            AuthSocketPort = authPort,
            CommunicatorPort = commPort
        };
        Assert.AreEqual(expected, AuthServer.ValidateConfig(config));
    }
}
