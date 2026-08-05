# Review B (skeptical / adversarial): `aa_004cf080` Combat_RollCritMultiplier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf080` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004cf080_Combat_RollCritMultiplier_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is a debug-stop helper (`Named_CalleeOf_…VOG_DEBUG_STOP`) | Scaffold chain name; body is crit mult | **Falsified** debug claim |
| 2 | Returns bool hit/miss | ST0 float; callers compare `> g_flOne` and scale dmg | **Falsified** bool claim |
| 3 | Mult is flat 2.0 or from skill table | Bytes: `level*0.01 + ~1.2` doubles | **Falsified** flat mult |
| 4 | Uses float chance 0..1 vs roll/65535 | Compare is `(roll%100) vs chance*100` | **Sealed percent gate** |
| 5 | `__thiscall` on attacker | Stack formals + plain RET; not ECX this | **Falsified** thiscall |
| 6 | `vtbl+0x27c` is crit power / damage bonus | Cross-duals treat slot as **level** int; FILD int | **Survives as level (Probable)** — not crit-power |
| 7 | Null attacker still rolls | Null → FLD 1.0, no chance call | **Falsified** null-roll |
| 8 | Name `Combat_RollCritMultiplier_Inferred` wrong | Two combat damage callers + mult>1 scale path | **Survives** structural name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Crit gate `%100` vs `chance*100` | **High** | Wrong crit rate |
| Mult `level*0.01+~1.2` | **High** | Wrong crit damage curve |
| Null → 1.0 | **High** | Spurious crits |
| cdecl ABI | **High** | Stack corruption in ports |
| Level semantic of +0x27c | **Medium** | Mult tied to wrong int |
| Chance helper English | **Open** | Chance inputs wrong if ported alone |

---

## 3. Cross-check against raw / bytes

```
raw: if p1: level=vcall+0x27c; chance=004cef70; if (p3%100)<=chance*100 → level*0.01+1.2; else 1.0
bytes: TEST ESI; CALL [vtbl+0x27c]; FILD; IDIV 100; CALL 004cef70; FMUL 100; FCOMIP/JB miss;
       FLD level; FMUL qword 0.01; FADD qword ~1.2 / FLD 1.0
```

Clean ≡ raw ≡ bytes. No modernization of CF.

---

## 4. Surviving contract for AutoCore

```csharp
// Crit mult only — chance from FUN_004cef70 sibling when ported.
static float RollCritMultiplier(object attacker, object target, ushort roll)
{
    if (attacker == null) return 1.0f;
    int level = GetLevel(attacker); // vtbl+0x27c
    float chance = CritChance(attacker, target); // FUN_004cef70
    if ((roll % 100) <= chance * 100.0f)
        return level * 0.01f + 1.20000005f; // image double ~1.2000000476837158
    return 1.0f;
}
// Callers: if (mult > 1f) dmg = Round(dmg * mult);
```

**Port traps to reject:**

- Treating return as bool.
- Using `roll/65535` instead of `% 100`.
- Flat 2× crit without level term.
- Assuming thiscall ECX=attacker on entry.

---

## 5. Residual gaps (do not block seal)

1. Dual of `FUN_004cef70` chance body (out of ownership / residual).
2. Product English for function / level vfunc.
3. Live combat differential of mult histogram.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break the percent gate or `level*0.01+~1.2` mult kernel. Main falsifications are debug-stop scaffold name, bool return, and flat mult myths. Gaps are product English + chance helper dual.
