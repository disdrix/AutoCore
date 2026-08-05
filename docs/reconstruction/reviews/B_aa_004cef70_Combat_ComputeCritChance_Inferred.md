# Review B (skeptical / adversarial): `aa_004cef70` Combat_ComputeCritChance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cef70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004cef70_Combat_ComputeCritChance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Debug-stop / VOG_DEBUG scaffold name | Body is pure float chance math; consumer is crit mult | **Falsified** debug claim |
| 2 | Returns bool or percent 0–100 | ST0 float; consumer multiplies by 100 | **Falsified** bool/percent return |
| 3 | Always `level*0.00025+0.05` | Bind path calls `FUN_004c4dd0` instead | **Falsified** as always-fallback |
| 4 | `__thiscall` on attacker | Stack formals; `RET` not `RET n`; ESI/EDI from stack | **Falsified** thiscall |
| 5 | Target required | Null target skips resist; no crash path in decomp | **Falsified** required-target |
| 6 | `g_flKillSpreeBonusPerStack` is kill-spree mechanic here | Same 0.05f global reused as base/floor (XP name) | **Name misleading**; **value sealed** |
| 7 | Name `Combat_ComputeCritChance_Inferred` wrong | Sealed consumer `004cf080` percent gate uses this as chance | **Survives** structural name |
| 8 | Floor maps negative to 0.0 | Bytes load `0.05` global on `chance < 0` | **Falsified** zero-floor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fallback `level*0.001*0.25+0.05` | **High** | Wrong base crit rate |
| Bind vs fallback branch | **High** | Miss skill crit tables |
| Bonus/resist field slots | **High** (callee decomp) | Wrong equip modifiers |
| cdecl ST0 | **High** | ABI corruption |
| Product name “crit chance” | **Medium** | Could be generic hit-chance if other consumers differ |
| `004c4dd0` curve | **Open** | Wrong skill-scaled base |

---

## 3. Cross-check against raw / bytes

```
raw: level=vcall+0x27c; if !bind: level*0.001*0.25+0.05; else 004c4dd0;
     +004c3140(1); -004c3120(flagT); floor 0.05
bytes: CALL [+0x27c]; FILD; TEST bind; MULSS 0.001; MULSS 0.25; ADDSS 0.05 /
       CALL 004c4dd0; CALL 004c3140; FSUB 004c3120; COMISS <0 → load 0.05; FLD; RET
```

Clean ≡ raw ≡ bytes for owned unit. No CF modernization.

---

## 4. Surviving contract for AutoCore

```csharp
// Crit chance only — pair with Combat_RollCritMultiplier_Inferred.
static float ComputeCritChance(object attacker, object target)
{
    int level = GetLevel(attacker); // vtbl+0x27c
    float chance;
    var bind = GetSkillBind(attacker); // vtbl+0x214
    if (bind == null)
        chance = level * 0.001f * 0.25f + 0.05f;
    else
        chance = SkillTableCritChance(bind); // FUN_004c4dd0
    if (GetSkillBind(attacker) != null)
        chance += ReadAtkCritBonus(bind, hi: true); // +0x1dc
    if (target != null && GetSkillBind(target) != null) {
        bool alt = ProbeEntity(target); // vtbl+0x1d4
        chance -= ReadTgtCritResist(GetSkillBind(target), alt); // +0x1e4/+0x1e0
    }
    if (chance < 0f) chance = 0.05f;
    return chance;
}
// Consumer: if ((roll % 100) <= chance * 100f) crit mult else 1f
```

**Port traps to reject:**

- Treating return as percent 0–100 without `*100` at gate.
- Ignoring skill-bind path / always using level formula.
- Flooring negatives to 0 instead of 0.05.
- Assuming thiscall ECX=attacker.

---

## 5. Residual gaps (do not block seal)

1. Dual of `FUN_004c4dd0` skill-table base (out of ownership).
2. Product English for vfuncs / bind object.
3. Live histogram of chance values vs UI display path.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break the fallback product formula, bind branch, bonus/resist shape, floor, or cdecl ST0 ABI. Main falsifications are debug scaffold name, always-fallback myth, and kill-spree semantic of the 0.05 constant. Gaps are skill-table dual + product English.
