namespace AutoCore.Launcher.Bootstrap;

using AutoCore.Auth.Network;
using AutoCore.Discord.Services;

/// <summary>
/// Sums <c>CurrentPlayers</c> across Auth's authenticated game-server list for Discord presence.
/// </summary>
public sealed class AuthServerPlayerCountSource : IPlayerCountSource
{
    private readonly AuthServer _authServer;

    public AuthServerPlayerCountSource(AuthServer authServer)
    {
        _authServer = authServer ?? throw new ArgumentNullException(nameof(authServer));
    }

    public int GetOnlinePlayerCount()
    {
        lock (_authServer.Servers)
        {
            var total = 0;
            foreach (var server in _authServer.Servers.Values)
                total += server.CurrentPlayers;
            return total;
        }
    }
}
