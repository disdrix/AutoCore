namespace AutoCore.Discord.Services;

/// <summary>Test / fallback player-count source with a fixed value.</summary>
public sealed class StaticPlayerCountSource : IPlayerCountSource
{
    private int _count;

    public StaticPlayerCountSource(int count = 0) => _count = count;

    public int GetOnlinePlayerCount() => _count;

    public void SetCount(int count) => _count = count;
}
