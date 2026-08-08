namespace AutoCore.Utils.Logging;

using System.Reflection;

/// <summary>
/// Process-level identity attached to lifecycle events so log streams from different
/// builds and restarts are distinguishable during the playtest.
/// </summary>
public static class ServerIdentity
{
    /// <summary>Unique per process start; distinguishes restarts sharing one log file.</summary>
    public static string ServerInstanceId { get; } = Guid.NewGuid().ToString("N")[..12];

    /// <summary>Informational version of the entry assembly (or Utils as fallback).</summary>
    public static string BuildVersion { get; } = ResolveBuildVersion();

    /// <summary>
    /// Commit hash embedded by the SDK's SourceLink support (the "+hash" suffix of the
    /// informational version); "unknown" when built without git metadata.
    /// </summary>
    public static string CommitHash { get; } = ResolveCommitHash(BuildVersion);

    private static string ResolveBuildVersion()
    {
        try
        {
            var assembly = Assembly.GetEntryAssembly() ?? typeof(ServerIdentity).Assembly;

            var informational = assembly
                .GetCustomAttribute<AssemblyInformationalVersionAttribute>()?
                .InformationalVersion;

            if (!string.IsNullOrWhiteSpace(informational))
                return informational;

            return assembly.GetName().Version?.ToString() ?? "unknown";
        }
        catch
        {
            return "unknown";
        }
    }

    private static string ResolveCommitHash(string buildVersion)
    {
        var plus = buildVersion.IndexOf('+');

        if (plus < 0 || plus == buildVersion.Length - 1)
            return "unknown";

        var hash = buildVersion[(plus + 1)..];

        return hash.Length > 12 ? hash[..12] : hash;
    }
}
