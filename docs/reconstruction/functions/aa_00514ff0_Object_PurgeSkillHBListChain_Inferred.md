# Function record: Object_PurgeSkillHBListChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514ff0` |
| **Canonical name** | `Object_PurgeSkillHBListChain_Inferred` |
| **FUN_* alias** | `FUN_00514ff0` |
| **Address** | `0x00514ff0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / object HB bookkeeping |
| **Completion status** | **Dual sealed 2026-07-29 W19-N** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Historical scaffold: `Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00514ff0` — **do not use for semantics**.

## Purpose

Purge active **CVOGHBSkillBase** heartbeats from the object''s HB list (`*(this+0xB0)`) when gate flag `this+0x25` is set, via `CNDDoubleList_InvokePredicateAndRemove_Inferred` + predicate `LAB_00512eb0` (Stop `vtbl+0x18`, optional `hb+0x6a4` when ctx≠0). Then recurse once onto linked object `*(this+0xAC)` with stack ctx **0**.

## Signature (byte-sealed)

```c
// __thiscall: ECX = object*; stack arg = ctx host dword; RET 4
void __thiscall Object_PurgeSkillHBListChain_Inferred(void *pThis, int ctxHost);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00514ff0_FUN_00514ff0.md`
- Annotated: `docs/reconstruction/raw/aa_00514ff0_FUN_00514ff0.annotated.md`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_00514ff0.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/Object_PurgeSkillHBListChain_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md`

## Callers / callees

| Direction | VA / name | Role |
|---|---|---|
| Callee | `0x004e2600` `CNDDoubleList_InvokePredicateAndRemove_Inferred` | CS list walk/remove |
| Callee | self | chain recurse via `+0xAC` |
| Callee (data) | `LAB_00512eb0` | SkillBase stop/remove predicate |
| Caller | `Skill_ApplyStatusEffectLocal` | pre-apply clear |
| Caller | `FUN_0056d520` Weapon_StartFire… | optional purge |
| Caller | `FUN_005c8fe0` / `FUN_004f62e0` | damage paths (often arg **1**) |
| Caller | `FUN_005d9290`, `FUN_00812a60`, `FUN_005c89f0`, `FUN_005fe6a0` | other object paths |

Sibling: `FUN_00515030` — loop form, flag `+0x26`, different predicate.

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + RET 4 | **High** (bytes) |
| Flag `+0x25`, list* `+0xB0`, link `+0xAC` | **High** |
| Predicate SkillBase stop/remove | **High** (RTTI + CF) |
| Product method English | **Open** (`_Inferred`) |
| Runtime / bit-exact | Open |
