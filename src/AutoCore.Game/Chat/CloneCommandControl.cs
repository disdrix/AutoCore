namespace AutoCore.Game.Chat;

using AutoCore.Game.Entities;

/// <summary>
/// Hook seam for the /clone command. AutoCore.Game cannot reference AutoCore.Sim
/// (dependency direction is Sector -> Sim -> Game), so the Sector host installs the
/// toggle delegate at startup. Same pattern as SectorLoopControl.
/// </summary>
public static class CloneCommandControl
{
    /// <summary>
    /// Toggles a clone vehicle for the given character and returns the user-facing
    /// result message. Null when no Sim host is wired (command reports unavailable).
    /// </summary>
    public static Func<Character, string> TryToggleClone { get; set; }

    /// <summary>
    /// /clonetrim: live height-trim tuning (arg = metres or null to query). Same wiring rules
    /// as <see cref="TryToggleClone"/>.
    /// </summary>
    public static Func<Character, string, string> TryTrimClone { get; set; }

    /// <summary>/clonefollowdist: live follow-distance tuning (metres, or "default" to reset).</summary>
    public static Func<Character, string, string> TrySetFollowDistance { get; set; }

    /// <summary>/clonestop (true) / /clonefollow (false): park or resume the caller's clone.</summary>
    public static Func<Character, bool, string> TrySetHold { get; set; }
}
