# Function record: Skill_SiblingCastClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514e20` |
| **Canonical name** | `Skill_SiblingCastClear` |
| **Address** | `0x00514e20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual A/B complete** — accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Prior scaffold: `FUN_00514e20`
- Prior human: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00514e20`
- Predicate: `Skill_SiblingCastClearPredicate_INFERRED` @ `0x00512bb0` (was `LAB_00512bb0`)
- Product demangled symbol: **Open** (working title is role-sealed)

## Purpose

Clear sibling cast heartbeats from the host object’s HB list at `+0xB0`: match `CVOGHBSkillBase` (type 1) by skillId + partial source TFID; optionally (flag≠0) also match `CVOGHBOKToCastAgain` (type 8) by skillId. On match, invoke `hb.vtbl+0x18(1,0)` then unlink/destroy the list node via `CNDDoubleList_InvokePredicateAndRemove_Inferred`.

## Signature (asm-sealed)

```c
// __thiscall  RET 0x18
void Skill_SiblingCastClear(
    void *pHost,           // ECX; list at *(pHost+0xB0)
    int nSkillId,          // stack+4
    uint32_t tfid0,        // +8
    uint32_t tfid1,        // +0xc
    uint32_t tfid2,        // +0x10
    uint32_t tfid3,        // +0x14
    uint8_t bAlsoOkToCastAgain); // +0x18
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00514e20_FUN_00514e20.md`
- Annotated: `docs/reconstruction/raw/aa_00514e20_FUN_00514e20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_SiblingCastClear.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00514e20_Skill_SiblingCastClear.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00514e20_Skill_SiblingCastClear.md`
- Residual: `docs/reconstruction/reviews/a_00514e20.md`

## Callers / callees

**Callers (3):**

| Caller | VA site | flag |
|---|---|---|
| `Skill_ApplyStatusEffectLocal` | `0x0051ab93` | 0 |
| `FUN_00514e70` | `0x00514ee3` | 0 |
| `FUN_0052db50` | `0x0052dbae` | 1 |

**Callees:**

| Callee | Role |
|---|---|
| `CNDDoubleList_InvokePredicateAndRemove_Inferred` (`0x004e2600`) | CS list walk/remove |
| predicate `0x00512bb0` | SkillBase / OKToCastAgain match + Stop |

## Confidence

| Claim | Level |
|---|---|
| Control flow from asm + decompiler | **Confirmed** |
| thiscall + list `+0xB0` | **Confirmed** |
| Predicate RTTI arms | **Confirmed** |
| Parameter semantic names | **High** (callers) |
| Product C++ symbol | Tentative / Open |
