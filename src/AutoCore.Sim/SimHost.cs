using AutoCore.Game.Chat;
using AutoCore.Game.Entities;
using AutoCore.Sim.Clone;

namespace AutoCore.Sim;

/// <summary>
/// Facade the Sector server hosts: owns the clone manager (and later the per-map sim worlds).
/// Wiring: SectorServer calls <see cref="InstallCommandHook"/> at startup and
/// <see cref="Tick"/> once per main-loop tick (after TickNpcs, before Interface.Pulse).
/// </summary>
public sealed class SimHost
{
    public static SimHost Instance { get; } = new();

    private readonly CloneManager _cloneManager = new();

    internal CloneManager CloneManager => _cloneManager;

    public string ToggleClone(Character character) => _cloneManager.Toggle(character);

    public void Tick(long nowMs, float dt) => _cloneManager.Tick(nowMs, dt);

    /// <summary>Routes /clone through AutoCore.Game's hook seam to this host.</summary>
    public static void InstallCommandHook()
    {
        CloneCommandControl.TryToggleClone = Instance.ToggleClone;
    }
}
