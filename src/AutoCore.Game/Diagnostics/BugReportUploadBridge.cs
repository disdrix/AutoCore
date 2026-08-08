namespace AutoCore.Game.Diagnostics;

/// <summary>
/// Static seam so Sector/Game chat commands can reach the Launcher-hosted Discord uploader
/// without a project reference from Game → Discord.
/// </summary>
public static class BugReportUploadBridge
{
    private static IBugReportUploader _uploader;

    public static IBugReportUploader Uploader
    {
        get => _uploader;
        set => _uploader = value;
    }

    public static bool IsAvailable => _uploader?.IsAvailable == true;

    public static Task<BugReportSubmitResult> UploadAsync(
        BugReportPackage package,
        CancellationToken cancellationToken = default)
    {
        var uploader = _uploader;
        if (uploader == null || !uploader.IsAvailable)
        {
            return Task.FromResult(BugReportSubmitResult.Fail(
                "Bug reports are not available right now (Discord not configured).",
                "No IBugReportUploader registered."));
        }

        return uploader.UploadAsync(package, cancellationToken);
    }

    /// <summary>Test / shutdown cleanup.</summary>
    public static void Clear() => _uploader = null;
}
