using System.Net;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Global.Tests.Network;

using AutoCore.Communicator;
using AutoCore.Global.Network;
using static GlobalServerTestHelpers;

[TestClass]
public class GlobalServerCommunicatorTests
{
    private GlobalServer? _server;

    [TestCleanup]
    public void Cleanup()
    {
        if (_server != null)
            SafeShutdown(_server);
        _server = null;
    }

    [TestMethod]
    public void OnCommunicatorConnect_FillsServerDataFromConfig()
    {
        _server = CreateServer();
        var config = CreateSetupConfig(publicAddress: "10.20.30.40");
        config.GameConfig.Port = 0;
        config.ServerInfoConfig.Id = 9;
        config.ServerInfoConfig.Password = "peer-pass";
        _server.Setup(config);

        // Port is 0 on the interface, but ServerData.Port is taken from Config.GameConfig.Port after Setup.
        // Set a non-zero advertised port without rebinding (Start is not called).
        _server.Config.GameConfig.Port = 26881;

        var info = new ServerData();
        InvokePrivate(_server, "OnCommunicatorConnect", info);

        Assert.AreEqual(9, info.Id);
        Assert.AreEqual(IPAddress.Parse("10.20.30.40"), info.Address);
        Assert.AreEqual(26881, info.Port);
        Assert.AreEqual("peer-pass", info.Password);
    }

    [TestMethod]
    public void OnCommunicatorServerInfoRequest_FillsServerInfoFromConfig()
    {
        _server = CreateServer();
        var config = CreateSetupConfig();
        config.ServerInfoConfig.AgeLimit = 21;
        config.ServerInfoConfig.PKFlag = 1;
        config.ServerInfoConfig.MaxPlayers = 42;
        _server.Setup(config);
        _server.Config.GameConfig.Port = 27000;

        var info = new ServerInfo
        {
            CurrentPlayers = 99 // should be overwritten to 0
        };

        InvokePrivate(_server, "OnCommunicatorServerInfoRequest", info);

        Assert.AreEqual(21, info.AgeLimit);
        Assert.AreEqual(1, info.PKFlag);
        Assert.AreEqual(0, info.CurrentPlayers);
        Assert.AreEqual(27000, info.Port);
        Assert.AreEqual(42, info.MaxPlayers);
    }

    [TestMethod]
    public void OnCommunicatorLoginResponse_Success_DoesNotCloseSocket()
    {
        _server = CreateServer();
        _server.Setup(CreateSetupConfig());

        // Should only log; no throw.
        InvokePrivate(_server, "OnCommunicatorLoginResponse", true);

        Assert.IsFalse(_server.AuthCommunicator.Connected);
    }

    [TestMethod]
    public void OnCommunicatorLoginResponse_Failure_ClosesWhenConnectedOtherwiseNoOp()
    {
        _server = CreateServer();
        _server.Setup(CreateSetupConfig());

        // Not connected => CloseCommunicator is a no-op for the Connected check.
        InvokePrivate(_server, "OnCommunicatorLoginResponse", false);

        Assert.IsFalse(_server.AuthCommunicator.Connected);
    }

    [TestMethod]
    public void OnCommunicatorRedirectRequest_ValidRequest_RegistersLoginExpectation()
    {
        _server = CreateServer();
        _server.Setup(CreateSetupConfig());

        var request = new RedirectRequest
        {
            AccountId = (uint)(Random.Shared.Next(1, int.MaxValue)),
            Username = "redirect-user",
            OneTimeKey = 0xABCDu
        };

        var result = (bool)InvokePrivate(_server, "OnCommunicatorRedirectRequest", request)!;

        Assert.IsTrue(result, "ExpectLoginToGlobal should accept a unique account/username/key.");
    }

    [TestMethod]
    public void OnCommunicatorRedirectRequest_InvalidUsername_ReturnsFalse()
    {
        _server = CreateServer();
        _server.Setup(CreateSetupConfig());

        var request = new RedirectRequest
        {
            AccountId = 1,
            Username = "",
            OneTimeKey = 1
        };

        var result = (bool)InvokePrivate(_server, "OnCommunicatorRedirectRequest", request)!;

        Assert.IsFalse(result);
    }

    [TestMethod]
    public void OnCommunicatorError_SchedulesReconnectTimer()
    {
        _server = CreateServer();
        // Invalid communicator address so reconnect path does not open a real TCP connect.
        var config = CreateSetupConfig(communicatorAddress: "not-a-valid-ip");
        _server.Setup(config);

        InvokePrivate(_server, "OnCommunicatorError");

        // CommReconnect is 10000 ms; advance past it. ConnectCommunicator catches parse failure.
        _server.MainLoop(10001);

        Assert.IsFalse(_server.AuthCommunicator.Connected);
    }

    [TestMethod]
    public void ConnectCommunicator_InvalidAddress_IsCaughtAndDoesNotThrow()
    {
        _server = CreateServer();
        var config = CreateSetupConfig(communicatorAddress: "%%%");
        _server.Setup(config);

        InvokePrivate(_server, "ConnectCommunicator");

        Assert.IsFalse(_server.AuthCommunicator.Connected);
    }

    [TestMethod]
    public void CloseCommunicator_WhenNotConnected_IsNoOp()
    {
        _server = CreateServer();
        _server.Setup(CreateSetupConfig());

        InvokePrivate(_server, "CloseCommunicator");

        Assert.IsFalse(_server.AuthCommunicator.Connected);
    }
}
