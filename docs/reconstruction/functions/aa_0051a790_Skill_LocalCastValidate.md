# Function record: Skill_LocalCastValidate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a790` |
| **Canonical name** | `Skill_LocalCastValidate` |
| **Address** | `0x0051a790` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (this = caster) |
| **Return type** | `int` (`eSkillResponses`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual gate-ladder strengthen 2026-07-29** — CF High; ordered G0–G9 sealed; UX codes via FormatFailureMessage; plate ABI names false; runtime open |

---

## 1. Summary

Local pre-cast validation. Returns `eSkillResponses` (`0` = allow). Callers format failures with `Skill_FormatFailureMessage`. Not server authority. Pure read/call gates — **no stores** in body.

---

## 2. Signature (working; not plate)

```c
int __thiscall Skill_LocalCastValidate(
    void* thisCaster,
    void* bSkipBusyCheck,  // 0 → run busy gate (callers pass 0)
    void* pSkill,          // skill runtime; null = lightweight
    void* pRangeExtra);    // forwarded toward Skill_LocalRangeTargetCheck (callers pass 0)
```

**Ghidra note:** stack slot names/types were wrong (`pSkill` typed as `char` / named `bSkipBusyCheck`). Body uses skill offsets (`+0x5fc`, `+0x614`, …). Call sites:

```text
Skill_LocalCastValidate(casterEntity, 0, pSkillRuntime, 0)
// NPC lightweight: pSkill null/0
```

---

## 3. Ordered gate ladder (G0→G9)

| Gate | Condition | Return |
|------|-----------|-------:|
| **G0** | `this+0xb4 & 0x02` | **5** |
| **G1** | `vtbl+0x198()` and (plant null or `plant+0x6b4 < 1`) | **3** |
| **G2** | `bSkipBusy==0` and (`+0xb4&8` + world type `0x14`) | **5** |
| **G2** | `bSkipBusy==0` and `*(FUN_005169c0()+0x10) != 0` | **6** |
| **G3** | `pSkill == null` | **0** |
| **G4** | active-cast binding **≠** invalid TFID | **0** (skip deep) |
| **G5** | plant≠0 ∧ `+0x6b4 < 1` ∧ `+0x12c < skill+8` | **4** |
| **G6** | `skill+0x628` or category CD remaining ≠ 0 | **7** |
| **G7** | plant==0 ∧ `*(FUN_00518c20()+8)!=0` ∧ `skill+0x615&2` | **10** |
| **G8** | hide/form ladder (`vtbl+0x19c`, flags `0x4000`/`0x40`) | **12** / **11** / `LocalRangeTargetCheck` |
| **G9** | else | **0** |

**Port rule:** early-exit order is load-bearing; do not reorder.  
**Power nuance:** if `plant+0x6b4 >= 1`, G5 never rejects on low power.

### Hide ladder (G8 detail)

```text
related = vtbl+0x19c()
if related == 0:
  (skill+0x615 & 0x40)==0 → LocalRangeTargetCheck else → 11
else:
  formFlag @ related layout +0x29
  plant==0 && formFlag && !(skill+0x614 & 0x4000) → 12
  else if !(skill+0x614 & 0x4000) → LocalRangeTargetCheck
  formFlag → LocalRangeTargetCheck
  else → 11
```

---

## 4. eSkillResponses (this unit + UX)

| Code | FormatFailureMessage string | Body trigger |
|---:|---|---|
| 0 | (ok) | G3 / G4 occupied / G9 |
| 3 | Cannot do that while wrecked! | G1 plant / `+0x6b4` |
| 4 | You don't have enough power! | G5 triple conjunct |
| 5 | You can't do that with your current status. | G0 / G2 alt |
| 6 | You're already actively using a skill! | G2 busy `+0x10` |
| 7 | This skill is not ready to use again yet! | G6 casting / CD |
| 10 | You have an active skill that prevents you from doing that. | G7 map + bit2 |
| 11 | You must be hidden to use this. | G8 fallthrough |
| 12 | You can't do this while hidden. | G8 form + missing `0x4000` |
| 13 / 14 | range / wrong target | **not literals here** — LocalRangeTargetCheck / handler |
| 15 | accuracy / unhandled default path | LocalRangeTargetCheck `0xf` |

---

## 5. Helpers and callees

| Addr / name | Role in this unit | Naming |
|-------------|-------------------|--------|
| `FUN_005169c0` | busy state `+0x10` → code 6 | **leave FUN_*** |
| `FUN_00518c20` | active-cast map; size `+8` → code 10; Lookup uses same map | **leave FUN_*** |
| `Skill_LookupActiveCastBinding` | bind TFID by `skill+0x5fc` | named |
| `TFID_NotEquals` | free bind when equal invalid (compare 2×i32 + char) | named |
| `Skill_GetCategoryCooldownRemaining` | ST0 residual vs `g_flZero` → 7 | named |
| `Skill_LocalRangeTargetCheck` | range/accuracy/handler | named |
| `g_abTfidInvalid_9CDF88` | `{ -1,-1,0,0 }` sentinel | read_memory sealed |

---

## 6. Callers (9)

| Name | VA |
|------|-----|
| `Client_QuickBarActivateSkillSlot` | `0x00921b50` |
| `Client_RequestCastSkill` | `0x00941590` |
| `Client_StanceOrGadgetActivatePath` | `0x0093a3d0` |
| `NPC_TryCastSkillFromSet` | `0x005d1280` |
| `FUN_00521650` | `0x00521650` |
| `FUN_00606180` | `0x00606180` |
| `FUN_00829190` | `0x00829190` |
| `FUN_0091f6b0` | `0x0091f6b0` |
| `FUN_00941d50` | `0x00941d50` |

---

## 7. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_0051a790_Skill_LocalCastValidate.*` |
| Clean | `reconstructed-exact/Skill_LocalCastValidate.cpp` |
| Dual A/B | `reviews/A_aa_0051a790_*`, `reviews/B_aa_0051a790_*` |
| Residual scratch | `reviews/a_0051a790.md` |
| UX table | `raw/aa_0054fa20_Skill_FormatFailureMessage.md` (or live `0x0054fa20`) |
| System map | `systems/skills-abilities.md` |
| Topic | `docs/topic-extractions/skill-cast.md` |

---

## 8. Confidence

| Dimension | Level |
|---|---|
| Function boundary | High (named Ghidra) |
| Ordered gate ladder | **High** (G0–G9) |
| Control flow | High (decompiler + 2026-07-29 re-check) |
| Param naming vs Ghidra plate | High working map; plate false |
| Return code UX table | **High** (FormatFailureMessage) |
| Power `+0x6b4` dual-use | **High CF** |
| FPU CD compare representation | Tentative (extraout_ST0 stand-in) |
| Overall | **Human-refined; gate ladder + residual codes sealed; runtime open** |

---

## 9. Open questions

1. Assembly formal seal (stack widths).
2. Product names: `FUN_005169c0`, `FUN_00518c20`, `plant+0x6b4`, skill flag bits.
3. Runtime matrix of each reject code.
4. Product rationale for occupied binding → allow 0.
