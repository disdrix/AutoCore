using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

[TestClass]
public class PlayerDiagnosticsTests
{
    private InMemoryLogSink _sink;

    [TestInitialize]
    public void Init()
    {
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        GameLog.MinimumLevel = StructuredLogLevel.Info;
        PlayerDiagnostics.Clear();
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        PlayerDiagnostics.Clear();
    }

    [TestMethod]
    public void EnrolledSession_PassesDebugThroughMinimumLevelFilter()
    {
        PlayerDiagnostics.EnrollSession("abc123session", minutes: 15);

        using (LogContext.Push(("SessionId", "abc123session")))
        {
            GameLog.Debug("ElevatedDebug", ("x", 1));
        }

        GameLog.Debug("NotElevated", ("x", 2));

        Assert.AreEqual(1, _sink.Records.Count(r => r.EventName == "ElevatedDebug"));
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "NotElevated"));
    }

    [TestMethod]
    public void EnrolledCharacter_PassesDebugThroughFilter()
    {
        PlayerDiagnostics.EnrollCharacter(42, minutes: 10);

        using (LogContext.Push(("CharacterId", 42L)))
        {
            GameLog.Debug("CharDebug");
        }

        Assert.AreEqual(1, _sink.Records.Count(r => r.EventName == "CharDebug"));
    }

    [TestMethod]
    public void Enrollment_ExpiresAfterMinutes()
    {
        var now = new DateTime(2026, 1, 1, 12, 0, 0, DateTimeKind.Utc);
        PlayerDiagnostics.SetClockForTests(() => now);
        PlayerDiagnostics.EnrollSession("s1", minutes: 5);

        now = now.AddMinutes(6);

        using (LogContext.Push(("SessionId", "s1")))
        {
            GameLog.Debug("ExpiredDebug");
        }

        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "ExpiredDebug"),
            "Expired enrollment must not elevate.");
    }
}
