using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class GameLogTests
{
    private InMemoryLogSink _sink;

    [TestInitialize]
    public void Init()
    {
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        GameLog.MinimumLevel = StructuredLogLevel.Trace;
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
    }

    [TestMethod]
    public void Info_WritesRecordWithEventNameLevelAndProperties()
    {
        GameLog.Info("UnitTestEvent", ("ItemCbid", 1234), ("Quantity", 2));

        var record = _sink.Single("UnitTestEvent");

        Assert.AreEqual(StructuredLogLevel.Info, record.Level);
        Assert.AreEqual(1234, record.GetProperty("ItemCbid"));
        Assert.AreEqual(2, record.GetProperty("Quantity"));
    }

    [TestMethod]
    public void Warn_WithErrorCode_AttachesErrorCodeProperty()
    {
        GameLog.Warn("RejectedEvent", "INV-001", ("Reason", "GridFull"));

        var record = _sink.Single("RejectedEvent");

        Assert.AreEqual(StructuredLogLevel.Warning, record.Level);
        Assert.AreEqual("INV-001", record.GetProperty("ErrorCode"));
        Assert.AreEqual("GridFull", record.GetProperty("Reason"));
    }

    [TestMethod]
    public void MinimumLevel_FiltersLowerSeverityEvents()
    {
        GameLog.MinimumLevel = StructuredLogLevel.Warning;

        GameLog.Info("SuppressedInfo");
        GameLog.Warn("VisibleWarn", errorCode: null);

        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "SuppressedInfo"),
            "Events below MinimumLevel must not reach the sink.");
        Assert.AreEqual(1, _sink.Records.Count(r => r.EventName == "VisibleWarn"));
    }

    [TestMethod]
    public void Audit_BypassesMinimumLevelFilter_AndMarksRecord()
    {
        GameLog.MinimumLevel = StructuredLogLevel.Error;

        GameLog.Audit("CurrencyChanged", ("Delta", -250));

        var record = _sink.Single("CurrencyChanged");

        Assert.IsTrue(record.Audit, "Audit events must be flagged for downstream filtering.");
        Assert.AreEqual(-250, record.GetProperty("Delta"));
    }

    [TestMethod]
    public void Emit_WithNoSinkConfigured_DoesNotThrow()
    {
        GameLog.ResetForTests();

        GameLog.Info("NoSinkEvent", ("A", 1));
        GameLog.Audit("NoSinkAudit");
    }

    /// <summary>SS-06 semantics: GameLog is called from catch blocks and must be total.</summary>
    [TestMethod]
    public void Emit_WithHostileArguments_DoesNotThrow()
    {
        GameLog.Info(null);
        GameLog.Info("Event", (null, "value"));
        GameLog.Error("Event", errorCode: null, ("Key", new object()));

        Assert.IsTrue(_sink.Records.Count > 0, "Degraded records should still be emitted where possible.");
    }

    [TestMethod]
    public void Operation_EmitsStartedImmediately_AndCompletedWithDurationOnComplete()
    {
        using (var op = GameLog.Operation("CharacterLoad", ("CharacterId", 7L)))
        {
            Assert.AreEqual(1, _sink.Records.Count(r => r.EventName == "CharacterLoadStarted"),
                "Started must be emitted when the operation scope opens.");

            op.Complete(("Rows", 3));
        }

        var completed = _sink.Single("CharacterLoadCompleted");

        Assert.AreEqual(3, completed.GetProperty("Rows"));
        Assert.IsNotNull(completed.GetProperty("DurationMs"),
            "Completion events must carry a duration for slow-operation diagnosis.");
        Assert.IsTrue((long)completed.GetProperty("DurationMs") >= 0);
        Assert.AreEqual(7L, completed.GetProperty("CharacterId"),
            "Properties passed at Operation() must be carried onto the completion event.");
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "CharacterLoadFailed"),
            "A completed operation must not also report failure.");
    }

    [TestMethod]
    public void Operation_Fail_EmitsFailedWithExceptionDetails()
    {
        var boom = new InvalidOperationException("boom");

        using (var op = GameLog.Operation("CharacterSave", ("CharacterId", 7L)))
        {
            op.Fail(boom);
        }

        var failed = _sink.Single("CharacterSaveFailed");

        Assert.AreEqual(StructuredLogLevel.Error, failed.Level);
        Assert.AreEqual(nameof(InvalidOperationException), failed.GetProperty("ExceptionType"));
        Assert.IsNotNull(failed.GetProperty("DurationMs"));
    }

    /// <summary>
    /// An exception escaping the operation's body must still produce a Failed event —
    /// the scope pattern makes failure reporting exception-safe by construction.
    /// </summary>
    [TestMethod]
    public void Operation_DisposedWithoutCompleteOrFail_EmitsFailed()
    {
        using (GameLog.Operation("VendorPurchase"))
        {
            // Simulates a throw inside the operation: neither Complete nor Fail is called.
        }

        Assert.AreEqual(1, _sink.Records.Count(r => r.EventName == "VendorPurchaseFailed"),
            "Abandoning the scope means the operation did not complete; that must be visible.");
    }

    [TestMethod]
    public void Operation_CarriesAmbientContextOntoAllThreeEvents()
    {
        using (LogContext.Push(("SessionId", "s-op")))
        using (var op = GameLog.Operation("MapTransfer"))
        {
            op.Complete();
        }

        Assert.AreEqual("s-op", _sink.Single("MapTransferStarted").GetProperty("SessionId"));
        Assert.AreEqual("s-op", _sink.Single("MapTransferCompleted").GetProperty("SessionId"));
    }
}
