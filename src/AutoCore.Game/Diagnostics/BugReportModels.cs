namespace AutoCore.Game.Diagnostics;

/// <summary>Result of attempting to deliver a player bug report.</summary>
public sealed class BugReportSubmitResult
{
    public bool Success { get; init; }
    public string PlayerMessage { get; init; } = string.Empty;
    public string? Detail { get; init; }

    public static BugReportSubmitResult Ok(string message = "Bug report submitted. Thank you!")
        => new() { Success = true, PlayerMessage = message };

    public static BugReportSubmitResult Fail(string playerMessage, string? detail = null)
        => new() { Success = false, PlayerMessage = playerMessage, Detail = detail };
}

/// <summary>Built package ready for upload (zip bytes + Discord message text).</summary>
public sealed class BugReportPackage
{
    public required string ReportId { get; init; }
    public required string FileName { get; init; }
    public required byte[] ZipBytes { get; init; }
    public required string DiscordMessage { get; init; }
    public required string CharacterName { get; init; }
    public long CharacterId { get; init; }
    public string? SessionId { get; init; }
}
