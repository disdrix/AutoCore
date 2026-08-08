namespace AutoCore.Auth.Config;

using AutoCore.Utils;

public class AuthConfig
{
    public Logger.LoggerConfig LoggerConfig { get; set; } = new();
    public string AuthDatabaseConnectionString { get; set; } = string.Empty;
    public int AuthSocketPort { get; set; }
    public int CommunicatorPort { get; set; }

    /// <summary>
    /// Password for the bootstrap <c>admin</c> account, used only when the auth database has no
    /// accounts at all. Empty by default: SS-20 removed the hard-coded <c>"admin"</c> credential,
    /// so leaving this unset means no account is created and the operator is told to run
    /// <c>auth.create</c> instead.
    /// </summary>
    public string DefaultAdminPassword { get; set; } = string.Empty;
}
