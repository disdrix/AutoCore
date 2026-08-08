# Function record: CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060df70` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` |
| **Ghidra name** | `FUN_0060df70` |
| **Prior names** | `FUN_0060df70` (scaffold only; no Named_CalleeOf_* for this VA) |
| **Address** | `0x0060df70` |
| **Body** | `0x0060df70`–`0x0060e06a` inclusive (**251 B** / `0xFB`); pad `CC` @ `0x0060e06b` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` — `this` = UseItem requirement; **`ret 0x1C`** (7 stack dwords) |
| **Completion status** | **Dual A/B sealed** (MEGA-038 2026-08-05); runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Verdict** | **accept-with-gaps** |

## Purpose

`CVOGObjectiveRequirement_UseItem` virtual method at **vtbl +0x04**: dispatch **object-use events 9 and 10**.

1. If event ∉ {9,10} → return 0.
2. If Eval (`vtbl+8`) already complete → return 0.
3. If `req+0x54 != -1`, require character MI field `+0xFC` equal.
4. If `MatchTargetCore(charCtx, worldObj)` fails → return 0.
5. **Apply arm:** event **10** OR `req+0x34 == 0` → `ApplyObjectUseProgress` → return its AL.
6. **Packet arm:** event **9** AND `req+0x34 != 0` → find `this` in parent objective vector `parent+0x158`, call `FUN_005319d0` with mission key + index + world COID quad @ `+0x160` → **return 0**.

Primary residual context: **sole caller** of dualed `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` (`0x0060d630`).

## Signature (sealed)

```c
// this = CVOGObjectiveRequirement_UseItem*
// ret 0x1C
uint8_t __thiscall CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred(
    void* this,
    void* charCtx,        // stack +0x04
    void* progress,       // stack +0x08  (Eval-compatible)
    int eventId,          // stack +0x0C  must be 9 or 10
    uint32_t unused_10,   // stack +0x10 unread
    uint32_t unused_14,   // stack +0x14 unread
    uint32_t unused_18,   // stack +0x18 unread
    void* worldObj);      // stack +0x1C  COID @ +0x160..+0x16C
// returns AL: Apply AL on apply arm; 0 on all other exits
```

## Requirement / host layout (body-backed)

| Off | Width | Role | Confidence |
|----:|-------|------|------------|
| `+0x00` | ptr | vtbl | **High** |
| `+0x04` | ptr | parent mission / objective host | **High** |
| `+0x34` | i32 | 0 → Apply; ≠0 + event9 → packet | **High** |
| `+0x54` | i32 | optional char field gate; `-1` skip | **High** |
| parent `+0x10` | u32 | mission key into `FUN_005319d0` | **High** |
| parent `+0x158/+0x15c` | ptr pair | objective* vector begin/end | **High** |
| world `+0x160..+0x16C` | 4×u32 | instance COID for packet | **High** |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ MEGA-038 append) | `docs/reconstruction/raw/aa_0060df70_FUN_0060df70.md` |
| Annotated | `docs/reconstruction/raw/aa_0060df70_FUN_0060df70.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060df70.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0060df70_CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0060df70_CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred.md` |
| Function FUN | `docs/reconstruction/functions/aa_0060df70_FUN_0060df70.md` |
| Report | `docs/agents/task-dual-ab-0060df70-mega-038-report.md` |

## Callers / callees

| Direction | Symbol | VA | Notes |
|---|---|---|---|
| DATA | UseItem vtbl +0x04 | `0x009dfc20` | sole xref |
| Code callers | — | — | virtual dispatch only |
| Callee | UseItem_Eval | vtbl+8 (`0x0060cfe0`) | incomplete gate |
| Callee | UseItem_MatchTargetCore | `0x0060d460` | dual sealed |
| Callee | UseItem_ApplyObjectUseProgress | `0x0060d630` | dual sealed; sole caller |
| Callee | FUN_005319d0 | `0x005319d0` | LogicUi packet path |

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompiler + disassembly | **High** |
| ABI `ret 0x1C` / event 9\|10 / Apply branch | **High** |
| Class UseItem via vtbl + sibling duals | **High** |
| Event 9/10 product English | **Tentative** → `_Inferred` |
| `FUN_005319d0` product name | **Tentative** |
| Runtime / bit-exact | **Open** |
