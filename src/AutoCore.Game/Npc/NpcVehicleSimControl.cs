namespace AutoCore.Game.Npc;

using AutoCore.Game.Entities;

/// <summary>
/// Hook seam handing NPC VEHICLE movement to AutoCore.Sim (dependency direction is
/// Sector -> Sim -> Game, so the Sector host installs the delegate at startup — same
/// pattern as CloneCommandControl). Creatures/bipeds/animals never go through this seam.
/// </summary>
public static class NpcVehicleSimControl
{
    /// <summary>
    /// Consulted by <see cref="NpcTicker"/> for every pathed NPC vehicle each tick. Returns
    /// true when the Sim owns (and adopts, on first call) this vehicle's movement — the
    /// legacy movers then leave it alone. Null / false → legacy behaviour.
    /// </summary>
    public static Func<Vehicle, bool> TrySimDrive { get; set; }
}
