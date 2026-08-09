using System.Text;
using AutoCore.Game.Constants;
using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Game.Inventory;
using AutoCore.Game.Managers;
using AutoCore.Game.Packets;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Skills;

namespace AutoCore.Game.Chat;

public sealed class ChatCommandService
{
    public static ChatCommandService Instance { get; } = new();

    public ChatCommandExecutionResult Execute(Character character, string command)
    {
        var parts = command.Split(' ', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries);
        if (parts.Length == 0)
            return new ChatCommandExecutionResult(false, string.Empty);

        // SS-28: gate mutating commands before any state change.
        if (!ChatAdminGate.Authorize(character, parts[0]))
            return new ChatCommandExecutionResult(true, "Permission denied (GM required).");

        switch (parts[0])
        {
            case "/listItems":
            case "/listitems":
                return new ChatCommandExecutionResult(
                    true,
                    InventoryCommandService.Instance.ListItems(parts));

            case "/addItem":
            case "/additem":
                var addItemResult = InventoryCommandService.Instance.AddItem(
                    character == null ? null : new InventoryRuntime(character),
                    parts);

                return new ChatCommandExecutionResult(
                    true,
                    addItemResult.Message,
                    addItemResult.Packets,
                    addItemResult.AddedItem);

            case "/setcargo":
            case "/setCargo":
                return SetCargo(character, parts);

            case "/clearcargo":
            case "/clearCargo":
                return ClearCargo(character);

            case "/removeMissionCargo":
            case "/removemissioncargo":
                return RemoveMissionCargo(character, parts);

            case "/cargoinfo":
            case "/cargoInfo":
                return CargoInfo(character);

            case "/sectorTick":
            case "/sectortick":
            case "/sector.tick":
                return SectorTick(parts);

            case "/clone":
            case "/unclone":
                return ToggleClone(character);

            case "/clonetrim":
            case "/cloneTrim":
                return TrimClone(character, parts.Length > 1 ? parts[1] : null);

            case "/clonefollowdist":
            case "/cloneFollowDist":
                return CloneFollowDist(character, parts.Length > 1 ? parts[1] : null);

            case "/clonestop":
            case "/cloneStop":
                return CloneHold(character, hold: true);

            case "/clonefollow":
            case "/cloneFollow":
                return CloneHold(character, hold: false);

            case "/showMissions":
            case "/showmissions":
                return ShowMissions(character);

            case "/reportbug":
            case "/bug":
            case "/bugreport":
                return ReportBug(character, command, parts);

            case "/clearAllMissions":
            case "/clearallmissions":
                return ClearAllMissions(character);

            case "/removeCurrentMission":
            case "/removecurrentmission":
                return RemoveCurrentMission(character);

            case "/removeMission":
            case "/removemission":
                return RemoveMission(character, parts);

            case "/giveMission":
            case "/givemission":
                return GiveMission(character, parts);

            case "/completeMission":
            case "/completemission":
                return CompleteMission(character, parts);

            case "/setHP":
            case "/sethp":
            case "/hp":
                return SetHP(character, parts);

            case "/setMaxHP":
            case "/setmaxhp":
            case "/mhp":
                return SetMaxHP(character, parts);

            case "/shield":
            case "/setShield":
            case "/setshield":
                return SetShield(character, parts);

            case "/mshield":
            case "/setMaxShield":
            case "/setmaxshield":
                return SetMaxShield(character, parts);

            case "/power":
            case "/setPower":
            case "/setpower":
                return SetPower(character, parts);

            case "/mpower":
            case "/setMaxPower":
            case "/setmaxpower":
                return SetMaxPower(character, parts);

            case "/skills":
                return Skills(character, parts);

            case "/resetSkills":
            case "/resetskills":
                return ResetSkills(character);

            case "/kick":
                return Kick(character, parts);

            case "/ban":
                return Ban(character, parts);

            case "/unban":
                return Unban(character, parts);

            case "/listplayers":
            case "/listPlayers":
                return ListPlayers();

            default:
            {
                // Case-insensitive aliases.
                var cmd = parts[0].ToLowerInvariant();
                if (cmd is "/skillpoints")
                    return SkillPoints(character, parts);

                // Client steals bare /player for //playerrename — prefer /addplayer.
                if (cmd is "/addplayer" or "/newaccount" or "/player")
                    return CreatePlayer(parts);

                if (cmd is "/listplayers")
                    return ListPlayers();

                if (cmd is "/kick")
                    return Kick(character, parts);

                if (cmd is "/ban")
                    return Ban(character, parts);

                if (cmd is "/unban")
                    return Unban(character, parts);

                return new ChatCommandExecutionResult(false, string.Empty);
            }
        }
    }

    private static ChatCommandExecutionResult ListPlayers()
        => new(true, PlayerModerationService.Instance.ListPlayers());

    private static ChatCommandExecutionResult Kick(Character character, string[] parts)
    {
        var query = parts.Length >= 2 ? string.Join(' ', parts.Skip(1)) : null;
        return new ChatCommandExecutionResult(true, PlayerModerationService.Instance.Kick(query, character));
    }

    private static ChatCommandExecutionResult Ban(Character character, string[] parts)
    {
        var query = parts.Length >= 2 ? string.Join(' ', parts.Skip(1)) : null;
        return new ChatCommandExecutionResult(true, PlayerModerationService.Instance.Ban(query, character));
    }

    private static ChatCommandExecutionResult Unban(Character character, string[] parts)
    {
        var query = parts.Length >= 2 ? string.Join(' ', parts.Skip(1)) : null;
        return new ChatCommandExecutionResult(true, PlayerModerationService.Instance.Unban(query, character));
    }

    /// <summary>
    /// Create an auth login account. Prefer <c>/addplayer</c> — the client intercepts <c>/player</c>
    /// as the GM <c>//playerrename</c> command ("not allowed to choose a new name for yourself").
    /// Email is auto-generated as <c>{user}@autocore.local</c>. Char account is created on first login.
    /// </summary>
    private static ChatCommandExecutionResult CreatePlayer(string[] parts)
    {
        if (parts.Length < 3)
            return new ChatCommandExecutionResult(true, "Usage: /addplayer <user> <pass>  (aliases: /newaccount, /player)");

        var result = PlayerAccountService.Instance.Create(parts[1], parts[2]);
        return new ChatCommandExecutionResult(true, result.Message);
    }

    /// <summary>
    /// Live-tune sector main loop period (ms). Usage: <c>/sectorTick 100</c> or <c>/sectorTick</c> to query.
    /// </summary>
    private static ChatCommandExecutionResult SectorTick(string[] parts)
    {
        if (parts.Length < 2)
        {
            var current = SectorLoopControl.CurrentMilliseconds;
            return new ChatCommandExecutionResult(
                true,
                current.HasValue
                    ? $"Sector tick is {current.Value}ms. Usage: /sectorTick <ms>  (e.g. /sectorTick 50, /sectorTick 10)"
                    : "Sector loop control is not available (sector server not running).");
        }

        if (!int.TryParse(parts[1], out var ms))
            return new ChatCommandExecutionResult(true, "Usage: /sectorTick <ms>  (integer 1-5000)");

        if (!SectorLoopControl.TrySet(ms, out var message))
            return new ChatCommandExecutionResult(true, message);

        return new ChatCommandExecutionResult(true, message);
    }

    /// <summary>
    /// Toggle a simulated clone of the character's vehicle. The actual behavior lives in
    /// AutoCore.Sim; the Sector host wires <see cref="CloneCommandControl.TryToggleClone"/>.
    /// </summary>
    private static ChatCommandExecutionResult ToggleClone(Character character)
    {
        var toggle = CloneCommandControl.TryToggleClone;
        if (toggle == null)
            return new ChatCommandExecutionResult(true, "Clone simulation is unavailable on this server.");

        return new ChatCommandExecutionResult(true, toggle(character));
    }

    /// <summary>/clonetrim &lt;metres&gt; — live clone height trim; see CloneCommandControl.</summary>
    private static ChatCommandExecutionResult TrimClone(Character character, string arg)
    {
        var trim = CloneCommandControl.TryTrimClone;
        if (trim == null)
            return new ChatCommandExecutionResult(true, "Clone simulation is unavailable on this server.");

        return new ChatCommandExecutionResult(true, trim(character, arg));
    }

    /// <summary>/clonestop and /clonefollow — park / resume the caller's clone.</summary>
    private static ChatCommandExecutionResult CloneHold(Character character, bool hold)
    {
        var setter = CloneCommandControl.TrySetHold;
        if (setter == null)
            return new ChatCommandExecutionResult(true, "Clone simulation is unavailable on this server.");

        return new ChatCommandExecutionResult(true, setter(character, hold));
    }

    /// <summary>/clonefollowdist &lt;metres|default&gt; — live clone follow distance.</summary>
    private static ChatCommandExecutionResult CloneFollowDist(Character character, string arg)
    {
        var setter = CloneCommandControl.TrySetFollowDistance;
        if (setter == null)
            return new ChatCommandExecutionResult(true, "Clone simulation is unavailable on this server.");

        return new ChatCommandExecutionResult(true, setter(character, arg));
    }

    private static ChatCommandExecutionResult Skills(Character character, string[] parts)
    {
        if (character == null) return new ChatCommandExecutionResult(true, "No character loaded.");
        if (parts.Length == 1) return new ChatCommandExecutionResult(true, $"Skill points available: {character.SkillPoints}.");
        if (parts.Length != 3 || !string.Equals(parts[1], "set", StringComparison.OrdinalIgnoreCase) ||
            !short.TryParse(parts[2], out var points) || points < 0)
            return new ChatCommandExecutionResult(true, "Usage: /skills or /skills set <0-32767>");
        CharacterSkillService.Instance.SetPoints(character, points);
        return new ChatCommandExecutionResult(true, $"Skill points set to {points}.", new BasePacket[] { CharacterLevelManager.Instance.BuildPacket(character) });
    }

    /// <summary>
    /// Debug: grant or set unspent skill points. Usage:
    /// <c>/skillPoints</c> (query), <c>/skillPoints 50</c> (set), <c>/skillPoints add 10</c> (add).
    /// </summary>
    private static ChatCommandExecutionResult SkillPoints(Character character, string[] parts)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        if (parts.Length == 1)
            return new ChatCommandExecutionResult(true, $"Skill points available: {character.SkillPoints}. Usage: /skillPoints <n> | /skillPoints add <n>");

        short points;
        if (parts.Length >= 3 && string.Equals(parts[1], "add", StringComparison.OrdinalIgnoreCase))
        {
            if (!short.TryParse(parts[2], out var delta))
                return new ChatCommandExecutionResult(true, "Usage: /skillPoints add <amount>");
            var sum = character.SkillPoints + delta;
            if (sum < 0)
                sum = 0;
            if (sum > short.MaxValue)
                sum = short.MaxValue;
            points = (short)sum;
        }
        else if (parts.Length >= 2 && short.TryParse(parts[1], out points) && points >= 0)
        {
            // absolute set
        }
        else
        {
            return new ChatCommandExecutionResult(true, "Usage: /skillPoints <0-32767> | /skillPoints add <amount>");
        }

        CharacterSkillService.Instance.SetPoints(character, points);
        return new ChatCommandExecutionResult(
            true,
            $"Skill points set to {points}.",
            new BasePacket[] { CharacterLevelManager.Instance.BuildPacket(character) });
    }

    private static ChatCommandExecutionResult ResetSkills(Character character)
    {
        if (character == null) return new ChatCommandExecutionResult(true, "No character loaded.");
        var count = character.LearnedSkills.Count;
        CharacterSkillService.Instance.Reset(character);
        return new ChatCommandExecutionResult(true, $"Removed {count} learned skill(s) without refunding points. Relog to refresh the skill tree.");
    }

    /// <summary>
    /// Player bug report: packs description + mission journal + last N action events into a zip
    /// and uploads via <see cref="BugReportUploadBridge"/> (Discord when Launcher wired it).
    /// Open to all players (not GM-gated). Usage: <c>/reportbug your text here</c>
    /// </summary>
    private static ChatCommandExecutionResult ReportBug(Character character, string fullCommand, string[] parts)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        // Everything after the command token is free text (may contain spaces).
        var description = string.Empty;
        if (!string.IsNullOrEmpty(fullCommand))
        {
            var firstSpace = fullCommand.IndexOf(' ');
            if (firstSpace >= 0 && firstSpace + 1 < fullCommand.Length)
                description = fullCommand[(firstSpace + 1)..].Trim();
        }

        if (string.IsNullOrWhiteSpace(description) && parts.Length < 2)
        {
            return new ChatCommandExecutionResult(true,
                "Usage: /reportbug <what went wrong>  — attaches mission journal + recent actions and posts to the team.");
        }

        if (string.IsNullOrWhiteSpace(description) && parts.Length >= 2)
            description = string.Join(' ', parts.Skip(1));

        var result = BugReportService.Submit(character, description);
        return new ChatCommandExecutionResult(true, result.PlayerMessage);
    }

    /// <summary>
    /// Report this character's server-side mission state: completed mission ids and active quests
    /// (with active objective sequence + progress). Diagnostic for mission persistence.
    /// </summary>
    private static ChatCommandExecutionResult ShowMissions(Character character)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var completed = character.CompletedMissionIds.OrderBy(x => x).ToList();

        var sb = new StringBuilder();
        sb.Append($"Completed ({completed.Count}): ");
        sb.Append(completed.Count == 0 ? "none" : string.Join(", ", completed));

        sb.Append($" | Active ({character.CurrentQuests.Count}): ");
        if (character.CurrentQuests.Count == 0)
        {
            sb.Append("none");
        }
        else
        {
            sb.Append(string.Join("; ", character.CurrentQuests.Select(q =>
            {
                var progress = q.ObjectiveProgress != null && q.ActiveObjectiveSequence < q.ObjectiveProgress.Length
                    ? q.ObjectiveProgress[q.ActiveObjectiveSequence]
                    : 0;
                var max = q.ObjectiveMax != null && q.ActiveObjectiveSequence < q.ObjectiveMax.Length
                    ? q.ObjectiveMax[q.ActiveObjectiveSequence]
                    : 0;
                return $"mission {q.MissionId} (seq {q.ActiveObjectiveSequence}, {progress}/{max})";
            })));
        }

        return new ChatCommandExecutionResult(true, sb.ToString());
    }

    /// <summary>
    /// Wipe this character's mission state (active + completed) from memory AND the char DB.
    /// The client keeps its current journal until the next relog, when the (now empty) create
    /// packet resets it. Diagnostic / test reset for mission persistence.
    /// </summary>
    private static ChatCommandExecutionResult ClearAllMissions(Character character)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var coid = character.ObjectId.Coid;
        var activeCount = character.CurrentQuests.Count;
        var completedCount = character.CompletedMissionIds.Count;

        character.CurrentQuests.Clear();
        character.CompletedMissionIds.Clear();
        MissionPersistence.Instance.DeleteAllForCharacter(coid);

        return new ChatCommandExecutionResult(
            true,
            $"Cleared {activeCount} active and {completedCount} completed mission(s) for coid {coid} (memory + DB). Relog to reset the client journal.");
    }

    /// <summary>
    /// Remove this character's active missions from memory AND the char DB, preserving completed
    /// missions. Client journal updates on the next relog via the create packet.
    /// </summary>
    private static ChatCommandExecutionResult RemoveCurrentMission(Character character)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var coid = character.ObjectId.Coid;
        var activeCount = character.CurrentQuests.Count;

        character.CurrentQuests.Clear();
        MissionPersistence.Instance.DeleteActiveForCharacter(coid);

        return new ChatCommandExecutionResult(
            true,
            $"Removed {activeCount} active mission(s) for coid {coid} (memory + DB). Completed missions preserved. Relog to reset the client journal.");
    }

    /// <summary>
    /// Abandon an active mission by id (FailMission path) and/or erase it from completed.
    /// Full wipe for that mission id: active + completed memory and DB rows, client journal sync.
    /// Usage: <c>/removeMission &lt;id&gt;</c>
    /// </summary>
    private static ChatCommandExecutionResult RemoveMission(Character character, string[] parts)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        if (parts.Length < 2 || !int.TryParse(parts[1], out var missionId) || missionId <= 0)
            return new ChatCommandExecutionResult(true, "Usage: /removeMission <id>");

        var wasActive = character.CurrentQuests.Any(q => q.MissionId == missionId);
        var wasCompleted = character.CompletedMissionIds.Contains(missionId);

        if (!wasActive && !wasCompleted)
            return new ChatCommandExecutionResult(true, $"Mission {missionId} not found (not active or completed).");

        if (wasActive)
            NpcInteractHandler.FailMission(character.OwningConnection, character, missionId);

        if (wasCompleted)
            character.CompletedMissionIds.Remove(missionId);

        // Ensure active + completed DB rows are dropped even when only completed (FailMission no-ops).
        MissionPersistence.Instance.OnMissionRemoved(character.ObjectId.Coid, missionId);

        // FailMission already pushed journal when active; completed-only still needs a resync.
        if (!wasActive && character.OwningConnection != null)
            NpcInteractHandler.PushJournalMissionList(character.OwningConnection, character);

        var partsDesc = (wasActive, wasCompleted) switch
        {
            (true, true) => "active + completed",
            (true, false) => "active",
            _ => "completed",
        };

        return new ChatCommandExecutionResult(
            true,
            $"Removed mission {missionId} ({partsDesc}; memory + DB). Client journal updated.");
    }

    /// <summary>
    /// Force-grant a mission by id onto this character's active list and push journal/objective
    /// state to the client. Uses the same path as NPC dialog acceptance.
    /// </summary>
    private static ChatCommandExecutionResult GiveMission(Character character, string[] parts)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        if (parts.Length < 2 || !int.TryParse(parts[1], out var missionId) || missionId <= 0)
            return new ChatCommandExecutionResult(true, "Usage: /giveMission <id>");

        if (AssetManager.Instance.GetMission(missionId) == null)
            return new ChatCommandExecutionResult(true, $"Unknown mission id {missionId}.");

        var alreadyActive = character.CurrentQuests.Any(q => q.MissionId == missionId);
        NpcInteractHandler.GrantMission(character.OwningConnection, character, missionId);

        return new ChatCommandExecutionResult(
            true,
            alreadyActive
                ? $"Mission {missionId} already active; resent to client."
                : $"Granted mission {missionId} (active + client sync).");
    }

    /// <summary>
    /// Force-complete an active mission by id: move to completed, persist, and push client
    /// complete + journal packets.
    /// </summary>
    private static ChatCommandExecutionResult CompleteMission(Character character, string[] parts)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        if (parts.Length < 2 || !int.TryParse(parts[1], out var missionId) || missionId <= 0)
            return new ChatCommandExecutionResult(true, "Usage: /completeMission <id>");

        if (character.CurrentQuests.All(q => q.MissionId != missionId))
        {
            if (character.CompletedMissionIds.Contains(missionId))
                return new ChatCommandExecutionResult(true, $"Mission {missionId} is already completed.");

            return new ChatCommandExecutionResult(true, $"Mission {missionId} is not active.");
        }

        NpcInteractHandler.ForceCompleteMission(character.OwningConnection, character, missionId);

        return new ChatCommandExecutionResult(
            true,
            $"Completed mission {missionId} (removed from active + client sync).");
    }

    private static ChatCommandExecutionResult SetHP(Character character, string[] parts)
    {
        if (parts.Length < 2 || !int.TryParse(parts[1], out var hp))
            return new ChatCommandExecutionResult(true, "Usage: /setHP <value> (alias /hp). Example: /hp 250");

        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var vehicle = character.CurrentVehicle;
        if (vehicle == null)
            return new ChatCommandExecutionResult(true, "You are not in a vehicle!");

        // Ghost dirty; CharacterLevel via Packets (ChatManager) — same as /power sendPacket:false.
        vehicle.SetCurrentHP(hp, triggerGhostUpdate: true, notifyOwnerHud: false);
        var packet = CharacterLevelManager.Instance.SyncOwnedCombatHud(character, sendPacket: false);
        return new ChatCommandExecutionResult(
            true,
            $"HP set to {vehicle.GetCurrentHP()}/{vehicle.GetMaximumHP()}.",
            new BasePacket[] { packet });
    }

    private static ChatCommandExecutionResult SetMaxHP(Character character, string[] parts)
    {
        if (parts.Length < 2 || !int.TryParse(parts[1], out var maxHp))
            return new ChatCommandExecutionResult(true, "Usage: /setMaxHP <value> (alias /mhp). Example: /mhp 2000");

        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var vehicle = character.CurrentVehicle;
        if (vehicle == null)
            return new ChatCommandExecutionResult(true, "You are not in a vehicle!");

        vehicle.SetMaximumHP(maxHp, triggerGhostUpdate: true, notifyOwnerHud: false);
        var packet = CharacterLevelManager.Instance.SyncOwnedCombatHud(character, sendPacket: false);
        return new ChatCommandExecutionResult(
            true,
            $"Max HP set to {vehicle.GetCurrentHP()}/{vehicle.GetMaximumHP()}.",
            new BasePacket[] { packet });
    }

    private static ChatCommandExecutionResult SetShield(Character character, string[] parts)
    {
        if (parts.Length < 2 || !int.TryParse(parts[1], out var shield))
            return new ChatCommandExecutionResult(true, "Usage: /shield <value>. Example: /shield 250");

        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var vehicle = character.CurrentVehicle;
        if (vehicle == null)
            return new ChatCommandExecutionResult(true, "You are not in a vehicle!");

        // Ghost ShieldMask + owner MultipleStatUpdate (0x2010 type=1 → Vehicle_SetCurrentShield).
        vehicle.SetCurrentShield(shield);
        return new ChatCommandExecutionResult(
            true,
            $"Shield set to {vehicle.CurrentShield}/{vehicle.MaxShield}.");
    }

    private static ChatCommandExecutionResult SetMaxShield(Character character, string[] parts)
    {
        if (parts.Length < 2 || !int.TryParse(parts[1], out var maxShield))
            return new ChatCommandExecutionResult(true, "Usage: /mshield <value>. Example: /mshield 500");

        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var vehicle = character.CurrentVehicle;
        if (vehicle == null)
            return new ChatCommandExecutionResult(true, "You are not in a vehicle!");

        vehicle.SetMaximumShield(maxShield);
        return new ChatCommandExecutionResult(
            true,
            $"Max shield set to {vehicle.CurrentShield}/{vehicle.MaxShield}.");
    }

    private static ChatCommandExecutionResult SetPower(Character character, string[] parts)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        if (parts.Length < 2)
        {
            var powerState = CharacterLevelManager.Instance.GetPower(character.ObjectId.Coid);
            return new ChatCommandExecutionResult(true, $"Server power: {powerState.Current}/{powerState.Maximum}.");
        }

        if (!short.TryParse(parts[1], out var power))
            return new ChatCommandExecutionResult(true, "Usage: /power <value>. Example: /power 50");

        // sendPacket: false — ChatManager delivers via ChatCommandExecutionResult.Packets.
        var packet = CharacterLevelManager.Instance.SetPower(character, power, sendPacket: false);
        return new ChatCommandExecutionResult(
            true,
            $"Power set to {packet.CurrentMana}/{packet.MaxMana}.",
            new BasePacket[] { packet });
    }

    private static ChatCommandExecutionResult SetMaxPower(Character character, string[] parts)
    {
        if (parts.Length < 2 || !short.TryParse(parts[1], out var maxPower))
            return new ChatCommandExecutionResult(true, "Usage: /mpower <value>. Example: /mpower 200");

        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var packet = CharacterLevelManager.Instance.SetMaxMana(character, maxPower, sendPacket: false);
        return new ChatCommandExecutionResult(
            true,
            $"Max power set to {packet.CurrentMana}/{packet.MaxMana}.",
            new BasePacket[] { packet });
    }

    private static ChatCommandExecutionResult SetCargo(Character character, string[] parts)
    {
        if (parts.Length < 2 || !int.TryParse(parts[1], out var pageCount) || pageCount < 1)
            return new ChatCommandExecutionResult(true, "Usage: /setcargo <pages> [width]. Example: /setcargo 13 24");

        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var width = character.Inventory.Width;
        if (parts.Length >= 3)
        {
            if (!int.TryParse(parts[2], out width) || width < 1)
                return new ChatCommandExecutionResult(true, "Width must be a positive integer.");
        }

        character.Inventory.SetCapacity(width, pageCount);
        character.Inventory.SaveCapacity(character.ObjectId.Coid);
        character.Inventory.ReloadCargo(character.ObjectId.Coid);

        IReadOnlyList<BasePacket> packets = new BasePacket[]
        {
            InventoryPacketFactory.CreateCargoSendAll(character.Inventory)
        };

        return new ChatCommandExecutionResult(
            true,
            $"Cargo capacity set to {character.Inventory.Width}x{character.Inventory.PageCount} ({character.Inventory.SlotCount} slots).",
            packets);
    }

    private static ChatCommandExecutionResult ClearCargo(Character character)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var result = character.Inventory.ClearCargo(character.ObjectId.Coid);
        return new ChatCommandExecutionResult(true, result.Message, result.Packets);
    }

    /// <summary>
    /// Remove mission-inventory cargo stacks (IsMissionItem). Optional CBID filter.
    /// Usage: <c>/removeMissionCargo</c> or <c>/removeMissionCargo &lt;cbid&gt;</c>
    /// </summary>
    private static ChatCommandExecutionResult RemoveMissionCargo(Character character, string[] parts)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        var cbidFilter = 0;
        if (parts.Length >= 2)
        {
            if (!int.TryParse(parts[1], out cbidFilter) || cbidFilter <= 0)
                return new ChatCommandExecutionResult(true, "Usage: /removeMissionCargo [cbid]");
        }

        var result = character.Inventory.RemoveMissionCargo(character.ObjectId.Coid, cbidFilter);
        return new ChatCommandExecutionResult(true, result.Message, result.Packets);
    }

    private static ChatCommandExecutionResult CargoInfo(Character character)
    {
        if (character == null)
            return new ChatCommandExecutionResult(true, "No character loaded.");

        return new ChatCommandExecutionResult(true, character.Inventory.DescribeCargoStatus());
    }
}
