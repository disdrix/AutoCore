# Function record: Skill_ValidateTargetForSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553650` |
| **Canonical name** | `Skill_ValidateTargetForSkill` |
| **Address** | `0x00553650` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` + `RET 8` |
| **Return type** | `int` (low `AL` bool: **1=valid**, **0=rejected**) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual accept** — residual tighten 2026-07-29 (all callers + outFlags orthogonality sealed) |

---

## 1. Summary

Validates whether `pTargetObj` is legal for `this` skill runtime:

1. Call `*(skill+0x5F0)->vtbl+0x44(target, skill, 0)`.
2. If result **== 1** → return **0** (reject).
3. Else walk HB list at `target+0xB0` via `CNDDoubleList_InvokePredicateAndRemove_Inferred` (`0x004e2600`) + `Skill_ValidateTarget_HBSkillListener` (`0x005532E0`); return context result byte (default **1**).

**Does not** write ResolveTargetList `outFlags`. Not used on the player quick-bar `RequestCast` path observed so far; callers: NPC cast, outpost skill banks, reaction skill cast (type 0xC), skill-HB construction.

---

## 2. Signature

```c
int __thiscall Skill_ValidateTargetForSkill(
    void* thisSkill,       // skill runtime
    void* pTargetObj,      // target entity
    void* bNotifyHBFlag);  // low byte 0/1
```

Decompiler formal names `(pSkill, pTarget)` are **swapped/misnamed** relative to assembly and callers. Live Ghidra decompile still incomplete vs asm — use annotated/raw asm appendix.

---

## 3. Behavior (exact)

```
rc = handler(skill+0x5F0)->vtbl+0x44(target, skill, 0);
if (rc == 1) return 0;
ctx = { target, skill, result=1, notify=(uint8)flag };
CNDDoubleList_InvokePredicateAndRemove_Inferred(
    this=target+0xB0, Skill_ValidateTarget_HBSkillListener, &ctx, 0);
return ctx.result;
```

Handler codes (unit + listener): **1** reject, **2** accept (+ optional HB notify via `hb->vtbl+0x18(1,0)` when notify flag set).

---

## 4. Callers (Ghidra xrefs — all parents sealed)

| Call site | Parent | Role | notify | Polarity |
|---|---|---|---:|---|
| `0x005789F3` | `CVOGHBSkillBase_ctor` `0x005788D0` | Skill HB ctor; attach on accept | 1 | `(char)!=0` proceed |
| `0x0057C976` | `CVOGReaction_Dispatch` `0x0057C500` case **0xC** | Reaction single-target skill cast | 0 | `TEST AL` / `JZ` skip |
| `0x0057CA3C` | same case **0xC** | Multi-target TFID collect loop | 0 | same |
| `0x005D1882` | `NPC_TryCastSkillFromSet` `0x005D1280` | AI cast after resolve+range | 0 | `(char)!=0` proceed |
| `0x00606EB6` | `Outpost_CastSkillsForFaction` `0x00606D70` | Outpost faction skill bank | 0 | `(char)!=0` proceed |
| `0x00607285` | `Outpost_CastSkillsForBeaconShare` `0x006070E0` | Outpost beacon-share bank | 0 | `TEST AL` / `JZ` |
| `0x006074F2` | same BeaconShare (second site; next FUN `0x00607550`) | same | 0 | `TEST AL` / `JZ` |

### outFlags

This unit has **no** outFlags parameter and writes none. NPC path: `Skill_ResolveTargetList` fills resolve flags **before** this bool gate; failures here skip cast without OR-ing extra bits.

---

## 5. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_00553650_Skill_ValidateTargetForSkill.*` |
| Clean | `reconstructed-exact/Skill_ValidateTargetForSkill.cpp` |
| Dual reviews | `reviews/A_aa_00553650_Skill_ValidateTargetForSkill.md`, `reviews/B_aa_00553650_*` |
| Listener | `Skill_ValidateTarget_HBSkillListener` @ `0x005532E0` |
| List util | `CNDDoubleList_InvokePredicateAndRemove_Inferred` @ `0x004e2600` |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Control flow (asm) | **Confirmed** |
| Wrapper return polarity 1=ok | **Confirmed** (7/7 callers) |
| stack0 = target, stack1 = flag | **Confirmed** |
| Handler slot `+0x5F0` / vtbl `+0x44` | **Confirmed** |
| Handler code 1 = reject | **Confirmed** |
| Listener RTTI / string | **Confirmed** |
| All call-site parents | **Confirmed** (residual seal) |
| outFlags non-writer | **Confirmed** |
| Handler class type name | Open |
| Full vtbl+0x44 catalog | Open |
| Overall | **Human-refined dual accept; runtime open** |

---

## 7. Open questions

1. Concrete type of object at `skill+0x5F0`.
2. Full catalog of vtbl+0x44 implementations per skill family.
3. Exact product method name for the CNDDoubleList walker (beyond `_Inferred`).
4. Whether any player cast UI path invokes this unit (still none found).
