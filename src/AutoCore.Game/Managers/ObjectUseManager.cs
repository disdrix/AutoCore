namespace AutoCore.Game.Managers;

using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.TNL;
using AutoCore.Utils;
using AutoCore.Utils.Logging;

/// <summary>
/// Single entry point for C2S UseObject (0x2072). Dispatches to use-item, mission dialog,
/// vendor store open, and other Open* facility reactions without hardcoding content ids.
/// </summary>
public static class ObjectUseManager
{
    /// <summary>
    /// Handle UseObject: use-item → mission dialog (if any) → store → facility → unhandled log.
    /// </summary>
    public static void Handle(TNLConnection conn, UseObjectPacket packet)
    {
        var character = conn?.CurrentCharacter;
        if (character == null || packet == null)
            return;

        var targetCoid = packet.Target?.Coid ?? -1;
        Logger.WriteLog(LogType.Debug,
            "UseObject: charCoid={0} target={1} objectiveId={2}",
            character.ObjectId.Coid,
            targetCoid,
            packet.ObjectiveId);

        // Always breadcrumb UseObject for /reportbug — including rejects — so multi-click
        // NPC spam shows up even when map/dialog resolution fails.
        if (character.Map == null)
        {
            PlayerActionTrace.ObjectUsed(character, targetCoid, "NoMap", packet.ObjectiveId);
            return;
        }

        if (targetCoid <= 0)
        {
            PlayerActionTrace.ObjectUsed(character, targetCoid, "InvalidTarget", packet.ObjectiveId);
            return;
        }

        character.MapPresence.EnsureContinent(character.Map.ContinentId, character.Map.InstanceSerial);
        if (character.MapPresence.IsSuppressed(targetCoid))
        {
            Logger.WriteLog(LogType.Debug,
                "UseObject: rejected suppressed coid={0} for char={1}",
                targetCoid,
                character.ObjectId.Coid);
            PlayerActionTrace.ObjectUsed(character, targetCoid, "Suppressed", packet.ObjectiveId);
            return;
        }

        string handler = "None";

        // 1) Mission use-item / use-object world targets.
        if (MissionUseItemProgress.TryHandleUseObject(conn, character, targetCoid, packet.ObjectiveId))
            handler = "MissionUseItem";
        // 2) Mission dialog when the NPC has something to offer/turn in.
        else if (NpcInteractHandler.TryHandleMissionDialog(conn, character, packet))
            handler = "MissionDialog";
        // 3) Map-authored TriggerEvents (kiosk spawn → trigger → OpenStore reaction chain).
        else if (InteractTriggerService.TryFire(conn, character, targetCoid))
            handler = "Trigger";
        // 4) Vendor store spatial fallback (OpenStore near player/target).
        else if (VendorStoreService.TryOpen(conn, character, targetCoid))
            handler = "Vendor";
        // 5) Other Open* facilities (BodyShop, Garage, Refinery, SkillTrainer, …).
        else if (FacilityOpenService.TryOpen(conn, character, targetCoid))
            handler = "Facility";
        else
        {
            Logger.WriteLog(LogType.Debug,
                "UseObject: no handler for target={0} charCoid={1} objectiveId={2}",
                targetCoid,
                character.ObjectId.Coid,
                packet.ObjectiveId);
        }

        // High-fidelity /reportbug breadcrumb (always retained in PlayerActionTraceBuffer).
        PlayerActionTrace.ObjectUsed(character, targetCoid, handler, packet.ObjectiveId);
    }
}
