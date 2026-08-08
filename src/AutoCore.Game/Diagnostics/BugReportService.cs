namespace AutoCore.Game.Diagnostics;

using System.Collections.Concurrent;
using AutoCore.Game.Entities;
using AutoCore.Utils;
using AutoCore.Utils.Logging;
using AutoCore.Utils.Reliability;

/// <summary>
/// Player-facing bug report submission: build zip, rate-limit, upload via
/// <see cref="BugReportUploadBridge"/> (Discord when wired by Launcher).
/// </summary>
public static class BugReportService
{
    /// <summary>Minimum seconds between reports from the same character.</summary>
    public static int CooldownSeconds { get; set; } = 60;

    private static readonly ConcurrentDictionary<long, DateTime> LastSubmitUtc = new();

    /// <summary>
    /// Build and queue upload. Returns immediately with a player-facing message; upload runs detached.
    /// </summary>
    public static BugReportSubmitResult Submit(Character character, string description)
    {
        if (character == null)
            return BugReportSubmitResult.Fail("No character loaded.");

        long coid = 0;
        try { coid = character.ObjectId.Coid; } catch { /* test */ }

        if (coid != 0 && LastSubmitUtc.TryGetValue(coid, out var last))
        {
            var elapsed = DateTime.UtcNow - last;
            if (elapsed.TotalSeconds < CooldownSeconds)
            {
                var wait = CooldownSeconds - (int)elapsed.TotalSeconds;
                return BugReportSubmitResult.Fail($"Please wait {wait}s before another bug report.");
            }
        }

        if (!BugReportUploadBridge.IsAvailable)
        {
            return BugReportSubmitResult.Fail(
                "Bug reports are not available (Discord not connected). Tell an admin.");
        }

        BugReportPackage package;
        try
        {
            package = BugReportBuilder.Build(character, description);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, "BugReportService.Build", ex);
            return BugReportSubmitResult.Fail("Failed to build bug report. Please try again later.");
        }

        if (coid != 0)
            LastSubmitUtc[coid] = DateTime.UtcNow;

        GameLog.Audit("BugReportSubmitted",
            ("ReportId", package.ReportId),
            ("CharacterId", package.CharacterId),
            ("CharacterName", package.CharacterName),
            ("SessionId", package.SessionId),
            ("ZipBytes", package.ZipBytes.Length),
            ("DescriptionLength", description?.Length ?? 0));

        SafeTask.FireAndForget(
            UploadAndLogAsync(package),
            $"BugReport upload {package.ReportId}");

        return BugReportSubmitResult.Ok(
            $"Bug report {package.ReportId} submitted ({package.ZipBytes.Length} bytes). Thank you!");
    }

    private static async Task UploadAndLogAsync(BugReportPackage package)
    {
        try
        {
            var result = await BugReportUploadBridge.UploadAsync(package).ConfigureAwait(false);
            if (result.Success)
            {
                GameLog.Info("BugReportUploaded",
                    ("ReportId", package.ReportId),
                    ("CharacterId", package.CharacterId));
                Logger.WriteLog(LogType.Network,
                    "Bug report {0} uploaded for character {1}", package.ReportId, package.CharacterId);
            }
            else
            {
                GameLog.Warn("BugReportUploadFailed", "SRV-002",
                    ("ReportId", package.ReportId),
                    ("Detail", result.Detail ?? result.PlayerMessage));
                Logger.WriteLog(LogType.Warning,
                    "Bug report {0} upload failed: {1}", package.ReportId, result.Detail ?? result.PlayerMessage);
            }
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            Logger.WriteException(LogType.Error, $"BugReport upload {package.ReportId}", ex);
            GameLog.Error("BugReportUploadFailed", "SRV-002",
                ("ReportId", package.ReportId),
                ("ExceptionType", ex.GetType().Name));
        }
    }

    /// <summary>Test seam: clear cooldown table.</summary>
    public static void ResetForTests()
    {
        LastSubmitUtc.Clear();
        CooldownSeconds = 60;
    }
}
