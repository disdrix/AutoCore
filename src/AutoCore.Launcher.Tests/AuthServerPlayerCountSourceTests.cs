using AutoCore.Auth.Network;
using AutoCore.Communicator;
using AutoCore.Launcher.Bootstrap;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Launcher.Tests;

[TestClass]
public class AuthServerPlayerCountSourceTests
{
    [TestMethod]
    public void GetOnlinePlayerCount_SumsCurrentPlayersAcrossServers()
    {
        var auth = new AuthServer();
        try
        {
            auth.Servers[1] = new ServerInfo { ServerId = 1, CurrentPlayers = 3, MaxPlayers = 100 };
            auth.Servers[2] = new ServerInfo { ServerId = 2, CurrentPlayers = 5, MaxPlayers = 100 };

            var source = new AuthServerPlayerCountSource(auth);
            Assert.AreEqual(8, source.GetOnlinePlayerCount());
        }
        finally
        {
            auth.Shutdown();
        }
    }

    [TestMethod]
    public void GetOnlinePlayerCount_WhenEmpty_ReturnsZero()
    {
        var auth = new AuthServer();
        try
        {
            var source = new AuthServerPlayerCountSource(auth);
            Assert.AreEqual(0, source.GetOnlinePlayerCount());
        }
        finally
        {
            auth.Shutdown();
        }
    }
}
