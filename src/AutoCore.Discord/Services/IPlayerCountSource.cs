namespace AutoCore.Discord.Services;

/// <summary>
/// Supplies the current online player count for Discord rich presence.
/// Implemented by the Launcher against Auth's game-server list.
/// </summary>
public interface IPlayerCountSource
{
    int GetOnlinePlayerCount();
}
