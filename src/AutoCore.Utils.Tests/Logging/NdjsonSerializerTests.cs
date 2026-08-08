using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using System.Text.Json;
using AutoCore.Utils.Logging;

[TestClass]
public class NdjsonSerializerTests
{
    [TestCleanup]
    public void Cleanup()
    {
        LogContext.ClearForTests();
    }

    [TestMethod]
    public void Serialize_ProducesSingleLineParseableJson_WithEnvelopeFields()
    {
        var record = StructuredLogRecord.Create(
            StructuredLogLevel.Info,
            "UnitTestEvent",
            audit: false,
            ("PlayerName", "Tester"));

        var line = NdjsonSerializer.Serialize(record);

        Assert.IsFalse(line.Contains('\n'), "NDJSON records must be exactly one line.");

        using var doc = JsonDocument.Parse(line);
        var root = doc.RootElement;

        Assert.AreEqual("UnitTestEvent", root.GetProperty("EventName").GetString());
        Assert.AreEqual("INFO", root.GetProperty("Level").GetString());
        Assert.AreEqual("Tester", root.GetProperty("PlayerName").GetString());

        var timestamp = root.GetProperty("Timestamp").GetString();
        Assert.IsTrue(timestamp.EndsWith("Z"),
            $"Timestamp must be UTC ISO-8601 ('Z' suffix); got '{timestamp}'.");
    }

    [TestMethod]
    public void Create_MergesAmbientLogContext_IntoRecordProperties()
    {
        StructuredLogRecord record;

        using (LogContext.Push(("SessionId", "s-9"), ("AccountId", 5)))
        {
            record = StructuredLogRecord.Create(
                StructuredLogLevel.Info, "ContextEvent", audit: false, ("Extra", 1));
        }

        var line = NdjsonSerializer.Serialize(record);
        using var doc = JsonDocument.Parse(line);
        var root = doc.RootElement;

        Assert.AreEqual("s-9", root.GetProperty("SessionId").GetString(),
            "Ambient context must be captured into the record at creation time.");
        Assert.AreEqual(5, root.GetProperty("AccountId").GetInt32());
        Assert.AreEqual(1, root.GetProperty("Extra").GetInt32());
    }

    [TestMethod]
    public void Serialize_ExplicitProperty_OverridesAmbientContextKey()
    {
        StructuredLogRecord record;

        using (LogContext.Push(("Result", "ambient")))
        {
            record = StructuredLogRecord.Create(
                StructuredLogLevel.Info, "OverrideEvent", audit: false, ("Result", "explicit"));
        }

        using var doc = JsonDocument.Parse(NdjsonSerializer.Serialize(record));

        Assert.AreEqual("explicit", doc.RootElement.GetProperty("Result").GetString(),
            "A property passed explicitly at the call site must win over the ambient value.");
    }

    [TestMethod]
    public void Serialize_AuditFlag_IsEmittedOnlyWhenTrue()
    {
        var audit = StructuredLogRecord.Create(StructuredLogLevel.Info, "AuditEvent", audit: true);
        var normal = StructuredLogRecord.Create(StructuredLogLevel.Info, "NormalEvent", audit: false);

        using var auditDoc = JsonDocument.Parse(NdjsonSerializer.Serialize(audit));
        Assert.IsTrue(auditDoc.RootElement.GetProperty("Audit").GetBoolean(),
            "Audit records must carry Audit=true so they are filterable.");

        using var normalDoc = JsonDocument.Parse(NdjsonSerializer.Serialize(normal));
        Assert.IsFalse(normalDoc.RootElement.TryGetProperty("Audit", out _),
            "Non-audit records should not waste bytes on Audit=false.");
    }

    /// <summary>
    /// SS-06 semantics extended to the structured pipeline: the serializer is called from
    /// catch blocks and must never throw, even for hostile property values.
    /// </summary>
    [TestMethod]
    public void Serialize_HostileToStringPropertyValue_DegradesInsteadOfThrowing()
    {
        var record = StructuredLogRecord.Create(
            StructuredLogLevel.Error,
            "HostileEvent",
            audit: false,
            ("Bad", new ThrowingToString()));

        string line = null;
        try
        {
            line = NdjsonSerializer.Serialize(record);
        }
        catch (Exception ex)
        {
            Assert.Fail($"Serializer must never throw; got {ex.GetType().Name}.");
        }

        using var doc = JsonDocument.Parse(line);
        StringAssert.Contains(doc.RootElement.GetProperty("Bad").GetString(), "unserializable",
            "A hostile value must degrade to a marker string, keeping the rest of the record intact.");
    }

    [TestMethod]
    public void Serialize_NullEventNameAndNullValues_DegradeInsteadOfThrowing()
    {
        var record = StructuredLogRecord.Create(
            StructuredLogLevel.Warning,
            eventName: null,
            audit: false,
            ("NullValue", null));

        using var doc = JsonDocument.Parse(NdjsonSerializer.Serialize(record));
        var root = doc.RootElement;

        Assert.IsFalse(string.IsNullOrEmpty(root.GetProperty("EventName").GetString()),
            "A null event name must degrade to a non-empty placeholder, not crash or vanish.");
        Assert.AreEqual(JsonValueKind.Null, root.GetProperty("NullValue").ValueKind,
            "Null property values are legal and serialize as JSON null.");
    }

    [TestMethod]
    public void Serialize_CommonValueKinds_KeepTheirJsonTypes()
    {
        var record = StructuredLogRecord.Create(
            StructuredLogLevel.Info,
            "TypedEvent",
            audit: false,
            ("Long", 123456789012345L),
            ("Double", 1.5d),
            ("Bool", true),
            ("Guid", Guid.Parse("11111111-2222-3333-4444-555555555555")));

        using var doc = JsonDocument.Parse(NdjsonSerializer.Serialize(record));
        var root = doc.RootElement;

        Assert.AreEqual(123456789012345L, root.GetProperty("Long").GetInt64());
        Assert.AreEqual(1.5d, root.GetProperty("Double").GetDouble());
        Assert.IsTrue(root.GetProperty("Bool").GetBoolean());
        Assert.AreEqual("11111111-2222-3333-4444-555555555555", root.GetProperty("Guid").GetString());
    }

    private sealed class ThrowingToString
    {
        public override string ToString() => throw new InvalidOperationException("hostile");
    }
}
