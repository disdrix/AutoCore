using AutoCore.Game.Chat;
using AutoCore.Game.Entities;
using AutoCore.Sim.Clone;
using AutoCore.Utils;

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

    /// <summary>
    /// Boundary catch (repo exception-safety rules): a spawn failure on live data must degrade
    /// to a chat message, not abort the inbound packet handler (seen live 2026-08-08 with an
    /// unconstructible equipped ornament).
    /// </summary>
    public string ToggleClone(Character character)
    {
        try
        {
            return _cloneManager.Toggle(character);
        }
        catch (Exception ex)
        {
            Logger.WriteException(LogType.Error, "SimHost.ToggleClone", ex);
            return "Clone failed — see server log.";
        }
    }

    public void Tick(long nowMs, float dt) => _cloneManager.Tick(nowMs, dt);

    /// <summary>
    /// /clonetrim: sets or reports the global publish-height trim (metres). Live tuning knob
    /// for the residual per-map body height (2026-08-09 feedback: "ever so slightly floaty").
    /// </summary>
    public string TrimClone(Character character, string arg)
    {
        if (string.IsNullOrWhiteSpace(arg))
            return $"Clone height trim is {CloneManager.HeightTrim:+0.00;-0.00;0.00} m. Usage: /clonetrim <metres> (e.g. /clonetrim -0.35)";

        if (!float.TryParse(arg, System.Globalization.NumberStyles.Float,
                System.Globalization.CultureInfo.InvariantCulture, out var trim)
            || !float.IsFinite(trim) || MathF.Abs(trim) > 5f)
        {
            return "Usage: /clonetrim <metres between -5 and 5>  (e.g. /clonetrim -0.35)";
        }

        CloneManager.HeightTrim = trim;
        return $"Clone height trim set to {trim:+0.00;-0.00;0.00} m.";
    }

    /// <summary>Routes /clone and /clonetrim through AutoCore.Game's hook seam to this host.</summary>
    public static void InstallCommandHook()
    {
        CloneCommandControl.TryToggleClone = Instance.ToggleClone;
        CloneCommandControl.TryTrimClone = Instance.TrimClone;
    }
}
