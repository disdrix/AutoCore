# Dual A/B report — `aa_006070e0` Outpost_CastSkillsForBeaconShare

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x006070e0`. Dual A/B + artifacts. Seal beacon-share outpost skill bank cast.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/callees). No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006070e0` Outpost_CastSkillsForBeaconShare | **accept-with-gaps** — ratio/flag/list/mode/batch sealed; nested vfunc + invalid-log CF residual |

---

## Sealed facts

### Role / ABI

1. **Name:** `Outpost_CastSkillsForBeaconShare` (registry + invalid outpost skill string). Former `FUN_006070e0`.
2. **ABI:** MSVC **`__thiscall`** — ECX = outpost object; stack **`int factionIndex`** must be in **`[0, 3]`** else no-op.
3. **Sole caller:** `FUN_006078e0` @ `0x006078e0` — sets `*(float*)(this+0x24c) = factionBeacons/totalBeacons`; when ratio **changes**, calls this with **`factionIndex = *(this+0x234)`**.

### Skill bank (per faction)

4. **Faction base:** `this + factionIndex * 0x48`.
5. **Bank vector:** begin `*(base+0xd4)`, end `*(base+0xd8)`, entry stride **0x10**, count `(end-begin)>>4`.
6. **Entry layout:**
   | Off | Field |
   |---:|---|
   | +0x00 | `u32` skillId |
   | +0x04 | `u8` rank/level → `ResolveSkillTargets` 2nd arg (low byte) |
   | +0x08 | `f32` min beacon-share threshold |
   | +0x0C | `char` skip when **≠ 0** |
7. **Process when:** `flag==0` **AND** `ratio(+0x24c) >= threshold(+0x8)`.  
   Skip formula: `flag!=0 OR (ratio < threshold)`.
8. **Flag polarity ≠** `Outpost_CastSkillsForFaction` (faction processes when flag **≠ 0**).

### Targets / cast

9. **TFID list:** per-faction `base+0xb4/+0xb8`, stride **8** (not global `+0x228` used by Faction cast).
10. **`CVOGReaction_ResolveObjectTarget(0, lo, hi)`** — mode **0** (Faction uses **1**).
11. Nested expand: object vtbl **`+0x1ec`** → container; CS walk via `FUN_004294f0` / `FUN_004022a0`; filter vtbl **`+0x1d8`** and `*(side+0x250)==0` (or null side); then `Skill_ValidateTargetForSkill(skill, entity, NULL)`.
12. Batch TFIDs from **`entity+0x160`** (dwords `[0x58..0x5b]`); flush when **`count > 0x62`** (99th entry); append terminator then `CVOGReaction_CastSkillOnTarget`.
13. **Terminator** `DAT_009de7d8` (`read_memory`): `FF FF FF FF FF FF FF FF 00 00 00 00 00 00 00 00`.
14. **Aim** `&DAT_00d029d0`: static image zeros (`read_memory` 32B).
15. **Source:** outpost adj `*( *(this+4)+4 ) + this + 4`; cast extras `0, -1, 0, 0`.
16. **No direct network** in this unit (cast dual: local pack / no wire in `CastSkillOnTarget`).

### Callees (this unit)

`ResolveSkillTargets` `0x0054c570`, `ResolveObjectTarget` `0x004bae70`, `Skill_ValidateTargetForSkill` `0x00553650`, `CastSkillOnTarget` `0x004d09a0`, `FUN_004294f0`, `FUN_004022a0`, `FUN_007a4480`, `operator_delete`, `LeaveCriticalSection`.

---

## Gaps

1. Product English names: vtbl `+0x1ec`, `+0x1d8`, field `+0x250`.
2. ResolveObjectTarget mode **0** vs **1** product filter semantics.
3. Entry `+0xC` flag English (and why inverted vs Faction bank).
4. Absolute CF: invalid log after successful free (Ghidra marks `operator_delete` noreturn; same pattern on Faction sibling).
5. `CONCAT22` high half of Resolve 2nd arg is decompiler noise from bank pointer — full rank width residual.
6. Runtime live capture; binary diff; bit-exact; PDB name.
7. Full `CastSkillOnTarget` arg-slot English mapping owned by `aa_004d09a0` dual (not re-opened).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` | accept-with-gaps |

---

## Files

| Kind | Absolute path |
|------|----------------|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006070e0_Outpost_CastSkillsForBeaconShare.md` |
| Legacy stub | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006070e0_FUN_006070e0.md` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006070e0_FUN_006070e0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006070e0_FUN_006070e0.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Outpost_CastSkillsForBeaconShare.cpp` |
| Matrix row | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\VERIFICATION_MATRIX.md` |
| System map | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\systems\skills-abilities.md` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-006070e0-outpost-castskills-beaconshare-report.md` |
| Scratch | `C:\Users\josh\Documents\GitHub\AutoCore\tmp\a_006070e0.md` |

Legacy scaffold names retained: `FUN_006070e0.cpp`, `Skill_Invalid_outpost_skill_cast_for_skill_d_map_s_006070e0.cpp`.

---

## AutoCore port sketch

```csharp
// Call only when beacon share ratio changes (caller responsibility).
void CastSkillsForBeaconShare(Outpost op, int factionIndex)
{
    if (factionIndex < 0 || factionIndex > 3) return;
    float ratio = op.BeaconShareRatio; // +0x24c
    var bank = op.FactionSkillBank(factionIndex); // +0xd4 stride 0x10
    foreach (var e in bank)
    {
        if (e.SkipFlag != 0) continue;          // polarity ≠ Faction cast
        if (ratio < e.MinShareRatio) continue;
        var skill = ResolveSkillTargets(e.SkillId, e.RankByte);
        if (skill == null) { LogInvalid(e.SkillId, op.MapName); continue; }

        var batch = new List<Tfid16>(100);
        foreach (var tfid in op.FactionTargetTfids(factionIndex)) // +0xb4
        {
            var obj = ResolveObjectTarget(mode: 0, tfid);
            if (obj == null) continue;
            foreach (var entity in ExpandContainer(obj)) // residual vtbl+0x1ec/CS
            {
                if (!PassSideFilter(entity)) continue;   // residual +0x1d8/+0x250
                if (!ValidateTargetForSkill(skill, entity, null)) continue;
                batch.Add(entity.Tfid); // +0x160
                if (batch.Count > 0x62)
                {
                    CastSkillOnTarget(skill, op.AsSource, batch, aimZero: true);
                    batch.Clear();
                }
            }
        }
        if (batch.Count > 0)
            CastSkillOnTarget(skill, op.AsSource, batch, aimZero: true);
        // free skill materialization
    }
}
```

**Do not** copy `Outpost_CastSkillsForFaction` without applying mode/list/flag/ratio deltas.
