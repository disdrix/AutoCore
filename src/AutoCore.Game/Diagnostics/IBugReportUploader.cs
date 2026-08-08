namespace AutoCore.Game.Diagnostics;

/// <summary>
/// Delivers a packed bug report (typically Discord channel file upload).
/// Injected by Launcher when Discord is enabled; null/unset means reports stay local-only.
/// </summary>
public interface IBugReportUploader
{
    /// <summary>True when a destination is configured and the transport is ready.</summary>
    bool IsAvailable { get; }

    /// <summary>
    /// Upload <paramref name="package"/> asynchronously. Must not throw out of the caller's
    /// fire-and-forget boundary (implementations should catch and return failure).
    /// </summary>
    Task<BugReportSubmitResult> UploadAsync(BugReportPackage package, CancellationToken cancellationToken = default);
}
