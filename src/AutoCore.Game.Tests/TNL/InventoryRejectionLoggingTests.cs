using AutoCore.Game.Diagnostics;
using AutoCore.Game.Inventory;
using AutoCore.Game.Packets;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Game.TNL;
using AutoCore.Utils.Logging;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.TNL;

/// <summary>
/// Phase 3: rejected inventory operations must always be visible as
/// <c>InventoryRequestRejected</c> (INV-001), even when the
/// <see cref="ServerConfig.InventoryDebugPackets"/> debug gate is off (the default).
/// Successful-operation debug logging stays gated as before.
/// </summary>
[TestClass]
public class InventoryRejectionLoggingTests
{
    private InMemoryLogSink _sink = null!;
    private bool _savedDebugPackets;

    [TestInitialize]
    public void Init()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        _savedDebugPackets = ServerConfig.InventoryDebugPackets;
        ServerConfig.InventoryDebugPackets = false;
    }

    [TestCleanup]
    public void Cleanup()
    {
        ServerConfig.InventoryDebugPackets = _savedDebugPackets;
        GameLog.ResetForTests();
        LogContext.ClearForTests();
    }

    [TestMethod]
    public void FailedGrab_EmitsInventoryRequestRejected_EvenWithDebugGateOff()
    {
        var result = InventoryOperationResult.SinglePacket(
            new InventoryGrabResponsePacket { WasSuccessful = false },
            "grab rejected: item not found");

        TNLConnection.LogInventoryOperationOutcome(result);

        var record = _sink.Single("InventoryRequestRejected");
        Assert.AreEqual(StructuredLogLevel.Warning, record.Level);
        Assert.AreEqual("INV-001", record.GetProperty("ErrorCode"));
        Assert.AreEqual("grab rejected: item not found", record.GetProperty("Reason"));
    }

    [TestMethod]
    public void FailedDrop_EmitsInventoryRequestRejected()
    {
        var result = InventoryOperationResult.SinglePacket(
            new InventoryDropResponsePacket { WasSuccessful = false },
            "drop rejected: slot occupied");

        TNLConnection.LogInventoryOperationOutcome(result);

        Assert.AreEqual("drop rejected: slot occupied",
            _sink.Single("InventoryRequestRejected").GetProperty("Reason"));
    }

    [TestMethod]
    public void SuccessfulOperation_WithDebugGateOff_EmitsNothing()
    {
        var result = InventoryOperationResult.SinglePacket(
            new InventoryGrabResponsePacket { WasSuccessful = true },
            "grab ok");

        TNLConnection.LogInventoryOperationOutcome(result);

        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "InventoryRequestRejected"),
            "successful operations must not raise the rejection event");
    }

    [TestMethod]
    public void NullResult_DoesNotThrow()
    {
        TNLConnection.LogInventoryOperationOutcome(null);
        Assert.AreEqual(0, _sink.Records.Count);
    }
}
