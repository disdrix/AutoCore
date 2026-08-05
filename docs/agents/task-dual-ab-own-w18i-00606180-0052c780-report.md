# Dual A/B report — W18-I OWN (`aa_00606180`, `aa_0052c780`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00606180`, `0x0052c780`. Dual A/B + three-rep refine.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ xrefs / callees / ctor context). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).  
**Image base:** `0x400000`.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_00606180` / `0x00606180` | `CVOGHBWakeupSkill_Fire_Inferred` | **accept-with-gaps** |
| `aa_0052c780` / `0x0052c780` | `FUN_0052c780` | **leave-FUN** (behavior accept-with-gaps) |

---

## Sealed facts — `0x00606180` CVOGHBWakeupSkill_Fire_Inferred

1. **ABI:** HB in **ECX** (`__thiscall`); no stack args; tails via empty **`FUN_005081f0`**.
2. **Body:** `0x00606180`–`0x006061de`.
3. **Class:** RTTI **Confirmed** `CVOGHBWakeupSkill`; vtbl `PTR_FUN_009de7b4` slot **`+0x14`** (DATA `0x009de7c8` sole xref).
4. **Dispatch role:** EndOrDestroy / list Remove onEnd path — **not** TryFire OnHeartBeat (`+0x0C`=RescheduleAfterFire), **not** Stop OnEnd (`+0x10`).
5. **CF:** if owner `*(hb+0x18)`: optional `FUN_00514e00(owner)` when `+0x658==0`; `Skill_LocalCastValidate(owner, skipBusy=+0x658, skill=NULL, 0)`; on allow → `Skill_ApplyEffectsOnTarget_Inferred(skill=hb+0x24, caster, world+0x654, tfid+0x660, pos+0x66c, seed+0x670)`.
6. **ECX at FUN_00514e00:** **owner** (closes residual gap for this call site).
7. **Three-rep:** raw 2026-07-23 CF ≡ live decompile ≡ body/call-site bytes; ApplyEffects skill-`this` sealed (`lea ecx,[esi+0x24]`).

### Gaps

- Product method English (keep `_Inferred`).
- Runtime / bit-exact image diff.
- Full period setup from ApplyStatusEffectLocal (sibling).

---

## Sealed facts — `0x0052c780` FUN_0052c780

1. **ABI:** entity in **ECX**; no stack formals; tails **`FUN_004c81f0`**.
2. **Body:** `0x0052c780`–`0x0052c854`.
3. **CF:** clear `+0x6bb` → secondary **`vtbl+0x40(1)`** → `FUN_005169c0(sec)` → **`FUN_005b2ba0(block)`** (result used) → lock skill hash `sec+0x74` → walk → **`Skill_SetIsCastingFlag(skill, 0)`** → unlock → clear `+0x1fc` → tail.
4. **Decomp noise falsified:** SetIsCastingFlag third-arg/`uVar3=1` is the **vcall** arg only.
5. **Strings:** HashError TraversalLock / TraverseToNext + `VOG_DEBUG_STOP` (**assert only**).
6. **Naming:** leave `FUN_*`; reject `Named_VOG_DEBUG_STOP_*`.
7. **Caller:** sole CODE xref `0x004fb9d0` (containing function undefined in Ghidra).
8. **Three-rep:** raw ≡ live decompile ≡ body bytes.

### Gaps

- Product / class name.
- Field English for `+0x6bb` / `+0x1fc` / vcall+0x40.
- Caller function recovery.
- Runtime / bit-exact image diff.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00606180` | `reviews/A_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md` | `reviews/B_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md` | **accept-with-gaps** |
| `0x0052c780` | `reviews/A_aa_0052c780_FUN_0052c780.md` | `reviews/B_aa_0052c780_FUN_0052c780.md` | **leave-FUN** |

---

## Files

### `aa_00606180` / `CVOGHBWakeupSkill_Fire_Inferred`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00606180_CVOGHBWakeupSkill_Fire_Inferred.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00606180_FUN_00606180.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\CVOGHBWakeupSkill_Fire_Inferred.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00606180.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00606180_FUN_00606180.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00606180_FUN_00606180.annotated.md` |

### `aa_0052c780` / `FUN_0052c780`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_0052c780_FUN_0052c780.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_0052c780_FUN_0052c780.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0052c780_FUN_0052c780.md` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_0052c780.cpp` |
| Rejected scaffold note | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Named_VOG_DEBUG_STOP_0052c780.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0052c780_FUN_0052c780.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0052c780_FUN_0052c780.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w18i-00606180-0052c780-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x006061e0` | `CVOGHBWakeupSkill_ctor` (RTTI; field seed) |
| `0x005538a0` | `Skill_ApplyEffectsOnTarget_Inferred` (callee) |
| `0x0051a790` | `Skill_LocalCastValidate` (callee) |
| `0x00514e00` | leave-FUN active-cast dec (callee; ECX=owner at this site) |
| `0x005083f0` | `CVOGHBBase_EndOrDestroy` (vtbl+0x18 → calls +0x14) |
| `0x00507950` | `CVOGHBList_Tick` (Remove → EndOrDestroy) |
| `0x005502d0` | `Skill_SetIsCastingFlag` (clear-walk callee of 0052c780) |
| `0x005169c0` | leave-FUN lazy 0x14 block (callee; result → 005b2ba0) |
| `0x004c81f0` | tail cleanup after clear-walk |

---
