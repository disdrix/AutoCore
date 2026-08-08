namespace AutoCore.Game.Diagnostics;

using System.IO.Compression;
using System.Text;
using System.Text.Json;
using AutoCore.Game.Entities;
using AutoCore.Game.TNL;
using AutoCore.Utils.Logging;

/// <summary>
/// Assembles a player bug-report zip: free-text description, mission journal, session snapshot,
/// and the last N structured action events for that player.
/// </summary>
public static class BugReportBuilder
{
    public const int DefaultEventLimit = 500;
    public const int MaxDescriptionLength = 1500;

    public static BugReportPackage Build(
        Character character,
        string description,
        int eventLimit = DefaultEventLimit)
    {
        ArgumentNullException.ThrowIfNull(character);

        description = SanitizeDescription(description);
        var reportId = DateTime.UtcNow.ToString("yyyyMMdd-HHmmss") + "-" + Guid.NewGuid().ToString("N")[..8];
        var sessionId = character.OwningConnection?.SessionId;
        long characterId = 0;
        try { characterId = character.ObjectId.Coid; } catch { /* unbound test character */ }

        var characterName = SafeName(character);
        var events = PlayerActionTraceBuffer.SnapshotForPlayer(
            sessionId ?? string.Empty,
            characterId,
            eventLimit);

        var readme = BuildReadme(reportId, description, character, sessionId, characterId, events.Count);
        var journal = BuildMissionJournal(character);
        var snapshot = BuildSnapshotJson(character, sessionId, characterId, description, reportId);
        var eventsNdjson = BuildEventsNdjson(events);

        byte[] zipBytes;
        using (var ms = new MemoryStream())
        {
            using (var zip = new ZipArchive(ms, ZipArchiveMode.Create, leaveOpen: true))
            {
                WriteEntry(zip, "README.txt", readme);
                WriteEntry(zip, "description.txt", description);
                WriteEntry(zip, "mission-journal.txt", journal);
                WriteEntry(zip, "snapshot.json", snapshot);
                WriteEntry(zip, "player-events.ndjson", eventsNdjson);
            }
            zipBytes = ms.ToArray();
        }

        var safeName = SanitizeFileToken(characterName);
        var fileName = $"bugreport-{safeName}-{reportId}.zip";
        var discordMessage =
            $"**Bug report** `{reportId}`\n" +
            $"**Player:** {characterName} (coid `{characterId}`)\n" +
            $"**Session:** `{sessionId ?? "n/a"}`\n" +
            $"**Events:** {events.Count}\n" +
            $"**Description:** {Truncate(description, 400)}";

        return new BugReportPackage
        {
            ReportId = reportId,
            FileName = fileName,
            ZipBytes = zipBytes,
            DiscordMessage = discordMessage,
            CharacterName = characterName,
            CharacterId = characterId,
            SessionId = sessionId,
        };
    }

    public static string SanitizeDescription(string description)
    {
        if (string.IsNullOrWhiteSpace(description))
            return "(no description provided)";

        var trimmed = description.Trim();
        if (trimmed.Length > MaxDescriptionLength)
            trimmed = trimmed[..MaxDescriptionLength];
        return trimmed;
    }

    private static void WriteEntry(ZipArchive zip, string name, string content)
    {
        var entry = zip.CreateEntry(name, CompressionLevel.Optimal);
        using var stream = entry.Open();
        using var writer = new StreamWriter(stream, new UTF8Encoding(encoderShouldEmitUTF8Identifier: false));
        writer.Write(content);
    }

    private static string BuildReadme(
        string reportId,
        string description,
        Character character,
        string sessionId,
        long characterId,
        int eventCount)
    {
        var sb = new StringBuilder();
        sb.AppendLine("AutoCore player bug report");
        sb.AppendLine("=========================");
        sb.AppendLine($"ReportId: {reportId}");
        sb.AppendLine($"Utc: {DateTime.UtcNow:O}");
        sb.AppendLine($"Character: {SafeName(character)} ({characterId})");
        sb.AppendLine($"AccountId: {SafeAccountId(character)}");
        sb.AppendLine($"SessionId: {sessionId ?? "n/a"}");
        sb.AppendLine($"GMLevel: {character.GMLevel}");
        sb.AppendLine($"Level: {SafeLevel(character)}");
        sb.AppendLine($"Map: {DescribeMap(character)}");
        sb.AppendLine($"Position: {DescribePosition(character)}");
        sb.AppendLine($"Vehicle HP/Shield/Power: {DescribeVehiclePools(character)}");
        sb.AppendLine($"Credits: {SafeCredits(character)}");
        sb.AppendLine($"Active missions: {character.CurrentQuests?.Count ?? 0}");
        sb.AppendLine($"Completed missions: {character.CompletedMissionIds?.Count ?? 0}");
        sb.AppendLine($"Structured events included: {eventCount}");
        sb.AppendLine();
        sb.AppendLine("Description:");
        sb.AppendLine(description);
        sb.AppendLine();
        sb.AppendLine("Files:");
        sb.AppendLine("  description.txt       — player free text");
        sb.AppendLine("  mission-journal.txt   — active + completed missions");
        sb.AppendLine("  snapshot.json         — structured session snapshot");
        sb.AppendLine("  player-events.ndjson  — last N audit/session events for this player");
        return sb.ToString();
    }

    private static string BuildMissionJournal(Character character)
    {
        var sb = new StringBuilder();
        sb.AppendLine("=== Active quests ===");
        var quests = character.CurrentQuests;
        if (quests == null || quests.Count == 0)
        {
            sb.AppendLine("(none)");
        }
        else
        {
            foreach (var q in quests)
            {
                var progress = q.ObjectiveProgress != null && q.ActiveObjectiveSequence < q.ObjectiveProgress.Length
                    ? q.ObjectiveProgress[q.ActiveObjectiveSequence]
                    : 0;
                var max = q.ObjectiveMax != null && q.ActiveObjectiveSequence < q.ObjectiveMax.Length
                    ? q.ObjectiveMax[q.ActiveObjectiveSequence]
                    : 0;
                sb.AppendLine(
                    $"MissionId={q.MissionId} State={q.State} ActiveSeq={q.ActiveObjectiveSequence} " +
                    $"Progress={progress}/{max}");
                if (q.ObjectiveProgress != null)
                {
                    for (var i = 0; i < q.ObjectiveProgress.Length; i++)
                    {
                        var m = q.ObjectiveMax != null && i < q.ObjectiveMax.Length ? q.ObjectiveMax[i] : 0;
                        sb.AppendLine($"  obj[{i}] = {q.ObjectiveProgress[i]}/{m}");
                    }
                }
            }
        }

        sb.AppendLine();
        sb.AppendLine("=== Completed mission ids ===");
        var completed = character.CompletedMissionIds;
        if (completed == null || completed.Count == 0)
            sb.AppendLine("(none)");
        else
            sb.AppendLine(string.Join(", ", completed.OrderBy(x => x)));

        return sb.ToString();
    }

    private static string BuildSnapshotJson(
        Character character,
        string sessionId,
        long characterId,
        string description,
        string reportId)
    {
        try
        {
            var obj = new Dictionary<string, object>
            {
                ["ReportId"] = reportId,
                ["TimestampUtc"] = DateTime.UtcNow.ToString("O"),
                ["Description"] = description,
                ["SessionId"] = sessionId ?? "",
                ["CharacterId"] = characterId,
                ["CharacterName"] = SafeName(character),
                ["AccountId"] = SafeAccountId(character),
                ["GMLevel"] = character.GMLevel,
                ["Level"] = SafeLevel(character),
                ["Experience"] = SafeExperience(character),
                ["Credits"] = SafeCredits(character),
                ["Map"] = DescribeMap(character),
                ["Position"] = DescribePosition(character),
                ["VehiclePools"] = DescribeVehiclePools(character),
                ["BuildVersion"] = ServerIdentity.BuildVersion,
                ["CommitHash"] = ServerIdentity.CommitHash,
                ["ServerInstanceId"] = ServerIdentity.ServerInstanceId,
                ["ActiveMissionCount"] = character.CurrentQuests?.Count ?? 0,
                ["CompletedMissionCount"] = character.CompletedMissionIds?.Count ?? 0,
            };
            return JsonSerializer.Serialize(obj, new JsonSerializerOptions { WriteIndented = true });
        }
        catch (Exception ex)
        {
            return $"{{\"error\":\"snapshot failed\",\"type\":\"{ex.GetType().Name}\"}}";
        }
    }

    private static string BuildEventsNdjson(IReadOnlyList<StructuredLogRecord> events)
    {
        if (events == null || events.Count == 0)
            return string.Empty;

        var sb = new StringBuilder(events.Count * 128);
        foreach (var e in events)
            sb.AppendLine(NdjsonSerializer.Serialize(e));
        return sb.ToString();
    }

    private static string SafeName(Character c)
    {
        try { return string.IsNullOrWhiteSpace(c.Name) ? "unknown" : c.Name; }
        catch { return "unknown"; }
    }

    private static object SafeAccountId(Character c)
    {
        try { return c.AccountId; }
        catch { return 0; }
    }

    private static int SafeLevel(Character c)
    {
        try { return c.Level; }
        catch { return 0; }
    }

    private static int SafeExperience(Character c)
    {
        try { return c.Experience; }
        catch { return 0; }
    }

    private static long SafeCredits(Character c)
    {
        try { return c.Credits; }
        catch { return 0; }
    }

    private static string DescribeMap(Character c)
    {
        try
        {
            var map = c.Map;
            if (map == null)
                return "none";
            var name = map.ContinentObject?.DisplayName ?? map.ContinentObject?.MapFileName ?? "?";
            return $"id={map.ContinentId} name={name}";
        }
        catch
        {
            return "unknown";
        }
    }

    private static string DescribePosition(Character c)
    {
        try
        {
            var v = c.CurrentVehicle;
            if (v == null)
                return "n/a";
            var p = v.Position;
            return $"({p.X:F1},{p.Y:F1},{p.Z:F1})";
        }
        catch
        {
            return "n/a";
        }
    }

    private static string DescribeVehiclePools(Character c)
    {
        try
        {
            var v = c.CurrentVehicle;
            if (v == null)
                return "n/a";
            return $"hp={v.GetCurrentHP()}/{v.GetMaximumHP()} shield={v.CurrentShield}/{v.MaxShield}";
        }
        catch
        {
            return "n/a";
        }
    }

    private static string SanitizeFileToken(string name)
    {
        if (string.IsNullOrWhiteSpace(name))
            return "player";
        var sb = new StringBuilder(name.Length);
        foreach (var ch in name)
        {
            if (char.IsLetterOrDigit(ch) || ch is '-' or '_')
                sb.Append(ch);
            else
                sb.Append('_');
        }
        var s = sb.ToString();
        return s.Length == 0 ? "player" : s.Length > 32 ? s[..32] : s;
    }

    private static string Truncate(string s, int max)
        => s.Length <= max ? s : s[..max] + "…";
}
