namespace AutoCore.Sector.Config;

public class GameConfig
{
    public string PublicAddress { get; set; }
    public int Port { get; set; }
    /// <summary>
    /// Enables the local dev-control HTTP API.
    /// <para>
    /// SS-21: defaults to <b>false</b>. The API exposes unauthenticated endpoints including
    /// <c>/chat-command</c>, which executes commands as a selected character. It binds
    /// <see cref="System.Net.IPAddress.Loopback"/> only, so it is not remotely reachable — but it
    /// is still an unauthenticated administrative channel and must be opted into per deployment
    /// rather than being on by default. Do not enable it on a server hosting real players.
    /// </para>
    /// </summary>
    public bool EnableDevControl { get; set; } = false;
    public int DevControlPort { get; set; } = 27999;
    /// <summary>
    /// If true, allows clients with different TNL versions to connect (for testing)
    /// </summary>
    public bool AllowVersionMismatch { get; set; } = false;
    /// <summary>
    /// Expected TNL version. Default is 175. Set to 0 to use default, or set to client version (e.g., 161) to allow that version
    /// </summary>
    public int ExpectedVersion { get; set; } = 0;
}
