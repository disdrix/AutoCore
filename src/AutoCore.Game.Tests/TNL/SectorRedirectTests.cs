using System.Net;
using AutoCore.Game.Packets.Global;
using AutoCore.Game.TNL;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.TNL;

/// <summary>
/// Pins the Global→Sector hand-off address used in TransferToSectorPacket.
/// Hardcoding 127.0.0.1 breaks LAN/remote clients (they connect to themselves).
/// </summary>
[TestClass]
public class SectorRedirectTests
{
    private IPAddress? _savedRedirect;

    [TestInitialize]
    public void SaveRedirect()
    {
        _savedRedirect = TNLConnection.SectorRedirectAddress;
    }

    [TestCleanup]
    public void RestoreRedirect()
    {
        TNLConnection.SectorRedirectAddress = _savedRedirect ?? IPAddress.Loopback;
    }

    [TestMethod]
    public void SectorRedirectAddress_DefaultsToLoopback()
    {
        // Reset to type default semantics for this assertion.
        TNLConnection.SectorRedirectAddress = IPAddress.Loopback;

        Assert.AreEqual(IPAddress.Loopback, TNLConnection.SectorRedirectAddress);
    }

    [TestMethod]
    public void BuildSectorTransfer_UsesConfiguredRedirectAddress()
    {
        var configured = IPAddress.Parse("192.168.50.62");
        TNLConnection.SectorRedirectAddress = configured;

        TransferToSectorPacket packet = TNLConnection.BuildSectorTransfer();

        Assert.AreSame(configured, packet.IPAddress);
        Assert.AreEqual(27001u, packet.Port);
        Assert.AreEqual(0u, packet.Flags);
    }
}
