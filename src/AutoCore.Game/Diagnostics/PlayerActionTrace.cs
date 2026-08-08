namespace AutoCore.Game.Diagnostics;

using AutoCore.Game.Entities;
using AutoCore.Utils.Logging;

/// <summary>
/// High-fidelity breadcrumbs for <c>/reportbug</c>. Always retained in
/// <see cref="PlayerActionTraceBuffer"/> via <see cref="GameLog.Action"/>, independent of
/// NDJSON minimum level. Prefer these over Debug-only Logger lines for anything a player does
/// or that happens to a player.
/// </summary>
public static class PlayerActionTrace
{
    public static void ObjectUsed(
        Character character,
        long targetCoid,
        string handler,
        int objectiveId = 0,
        int? targetCbid = null)
    {
        GameLog.Action("ObjectUsed",
            Identity(character)
                .Append(("TargetCoid", targetCoid))
                .Append(("Handler", handler ?? "None"))
                .Append(("ObjectiveId", objectiveId))
                .Append(("TargetCbid", targetCbid))
                .ToArray());
    }

    public static void NpcInteract(
        Character character,
        long npcCoid,
        int npcCbid,
        string outcome,
        int objectiveId = 0,
        int missionCount = 0,
        float? distance = null)
    {
        GameLog.Action("NpcInteract",
            Identity(character)
                .Append(("NpcCoid", npcCoid))
                .Append(("NpcCbid", npcCbid))
                .Append(("Outcome", outcome ?? "unknown"))
                .Append(("ObjectiveId", objectiveId))
                .Append(("MissionCount", missionCount))
                .Append(("Distance", distance))
                .ToArray());
    }

    public static void MissionDialogResponse(
        Character character,
        int missionId,
        bool accepted,
        long npcCoid,
        string outcome)
    {
        GameLog.Action("MissionDialogResponse",
            Identity(character)
                .Append(("MissionId", missionId))
                .Append(("Accepted", accepted))
                .Append(("NpcCoid", npcCoid))
                .Append(("Outcome", outcome ?? "unknown"))
                .ToArray());
    }

    public static void DamageDealt(
        Character attackerCharacter,
        ClonedObjectBase target,
        int damage,
        bool isCrit,
        long? weaponCbid = null)
    {
        if (attackerCharacter == null || damage <= 0)
            return;

        GameLog.Action("DamageDealt",
            Identity(attackerCharacter)
                .Append(("ActorCharacterId", SafeCoid(attackerCharacter)))
                .Append(("TargetCoid", target?.ObjectId.Coid ?? 0))
                .Append(("TargetCbid", target?.CBID ?? 0))
                .Append(("TargetType", target?.GetType().Name))
                .Append(("Damage", damage))
                .Append(("IsCrit", isCrit))
                .Append(("WeaponCbid", weaponCbid))
                .Append(("TargetHpAfter", target?.GetCurrentHP()))
                .ToArray());
    }

    public static void DamageTaken(
        Character victimCharacter,
        ClonedObjectBase attacker,
        int damage,
        int hpAfter,
        int hpMax,
        int shieldAbsorb = 0)
    {
        if (victimCharacter == null || damage <= 0)
            return;

        GameLog.Action("DamageTaken",
            Identity(victimCharacter)
                .Append(("VictimCharacterId", SafeCoid(victimCharacter)))
                .Append(("AttackerCoid", attacker?.ObjectId.Coid ?? 0))
                .Append(("AttackerCbid", attacker?.CBID ?? 0))
                .Append(("AttackerType", attacker?.GetType().Name))
                .Append(("Damage", damage))
                .Append(("ShieldAbsorb", shieldAbsorb))
                .Append(("HpAfter", hpAfter))
                .Append(("HpMax", hpMax))
                .ToArray());
    }

    public static void Healed(
        Character character,
        int amount,
        int hpAfter,
        int hpMax,
        string source = null)
    {
        if (character == null || amount <= 0)
            return;

        GameLog.Action("Healed",
            Identity(character)
                .Append(("Amount", amount))
                .Append(("HpAfter", hpAfter))
                .Append(("HpMax", hpMax))
                .Append(("Source", source ?? "unknown"))
                .ToArray());
    }

    public static void SkillCast(
        Character character,
        int skillId,
        byte rank,
        bool success,
        string response = null,
        long targetCoid = 0)
    {
        if (character == null)
            return;

        GameLog.Action("SkillCast",
            Identity(character)
                .Append(("CasterCharacterId", SafeCoid(character)))
                .Append(("SkillId", skillId))
                .Append(("Rank", rank))
                .Append(("Success", success))
                .Append(("Response", response))
                .Append(("TargetCoid", targetCoid))
                .ToArray());
    }

    public static void CombatHit(
        Character character,
        string role,
        long otherCoid,
        int damage,
        bool killed = false)
    {
        if (character == null || damage <= 0)
            return;

        GameLog.Action("CombatHit",
            Identity(character)
                .Append(("Role", role ?? "unknown"))
                .Append(("OtherCoid", otherCoid))
                .Append(("Damage", damage))
                .Append(("Killed", killed))
                .ToArray());
    }

    private static List<(string Key, object Value)> Identity(Character character)
    {
        var list = new List<(string, object)>(12);
        if (character == null)
            return list;

        try
        {
            list.Add(("CharacterId", character.ObjectId.Coid));
        }
        catch { /* unbound */ }

        try
        {
            var name = character.Name;
            if (!string.IsNullOrEmpty(name))
                list.Add(("CharacterName", name));
        }
        catch { /* DBData null */ }

        var conn = character.OwningConnection;
        if (conn != null)
        {
            list.Add(("SessionId", conn.SessionId));
            try
            {
                if (conn.Account != null)
                    list.Add(("AccountId", conn.Account.Id));
            }
            catch { /* */ }
        }

        try
        {
            if (character.Map != null)
                list.Add(("MapId", character.Map.ContinentId));
        }
        catch { /* */ }

        return list;
    }

    private static long SafeCoid(Character c)
    {
        try { return c.ObjectId.Coid; }
        catch { return 0; }
    }

    private static List<(string Key, object Value)> Append(
        this List<(string Key, object Value)> list,
        (string Key, object Value) pair)
    {
        if (pair.Value != null)
            list.Add(pair);
        return list;
    }
}
