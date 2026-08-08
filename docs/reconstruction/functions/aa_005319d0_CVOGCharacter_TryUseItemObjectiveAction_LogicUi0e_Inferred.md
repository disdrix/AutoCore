# Function record: CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005319d0` |
| **Canonical name** | `CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred` |
| **Ghidra name** | `FUN_005319d0` |
| **Prior names** | `FUN_005319d0` (scaffold only; no Named_CalleeOf_* for this VA) |
| **Address** | `0x005319d0` |
| **Body** | `0x005319d0`–`0x00531afd` inclusive (**302 B** / `0x12E`); pad `CC` @ `0x00531afe` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` — `this` = character; **`ret 0x18`** (6 stack dwords); **AL** bool |
| **Completion status** | **Dual A/B sealed** (R10-012 2026-08-05); runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Verdict** | **accept-with-gaps** |

## Purpose

`CVOGCharacter` helper invoked from UseItem **ObjectEventDispatch** packet arm:

1. If dual-base gate **`+0x7E == 0`**: skip validation → send LogicUI **`0x0E`** → return **1**.
2. If gate set: look up active objective def by key in **`char+0x548`**; index evaluator vector **`+0x158/+0x15c`**; require type code **`0x0C`** (vtbl **`+0x50`**); RTTI cast to **`CVOGObjectiveRequirement_UseItem`**; stage target at UseItem **`+0x34`** via residual **`FUN_00522b30`** with COID×4 + flag **`+0x3c`**; on failure return **0**.
3. Success: pack LogicUI type **`0x0E`** (key + sign-extend + index) and `Client_SendLogicUiPacket` with queue this = dual-base **`+0xE8B8`**.

Parent dispatch **does not forward AL** (clears after call).

## Signature (sealed)

```c
// this = character*
// ret 0x18
uint8_t __thiscall CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred(
    void* this,
    uint32_t objectiveKey,  // stack +0x04
    int reqIndex,           // stack +0x08
    uint32_t coid0,         // stack +0x0C  worldObj+0x160 @ caller
    uint32_t coid1,         // stack +0x10
    uint32_t coid2,         // stack +0x14
    uint32_t coid3);        // stack +0x18
// returns AL: 1 on LogicUI send; 0 on validation fail
```

## Layout (body-backed)

| Off | Width | Role | Confidence |
|----:|-------|------|------------|
| dual-base `+0x7E` | u8 | live/validation gate | **High** |
| dual-base `+0xE8B8` | — | LogicUI queue this | **High** |
| `char+0x548` | ptr | active objective def hash | **High** |
| def `+0x158/+0x15c` | ptr pair | evaluator* vector | **High** |
| req vtbl `+0x50` | method | type code; expect `0x0C` | **High** |
| UseItem `+0x34` | ptr | stage target | **High** |
| UseItem `+0x3c` | u8 | flag into `FUN_00522b30` | **High** |
| LogicUI type | imm | **`0x0E`** | **High** |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ R10-012 append) | `docs/reconstruction/raw/aa_005319d0_FUN_005319d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005319d0_FUN_005319d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005319d0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005319d0_CVOGCharacter_TryUseItemObjectiveAction_LogicUi0e_Inferred.md` |
| Function FUN | `docs/reconstruction/functions/aa_005319d0_FUN_005319d0.md` |
| Report | `docs/agents/task-dual-ab-005319d0-r10-report.md` |

## Callers / callees

| Direction | Symbol | VA | Notes |
|---|---|---|---|
| Caller | `CVOGObjectiveRequirement_UseItem_ObjectEventDispatch_Inferred` | `0x0060df70` @ `0x0060e04a` | sole code xref |
| Callee | `CNDHash_LookupByKey` | — | active hash |
| Callee | `__RTDynamicCast` | — | UseItem RTTI |
| Callee | `FUN_00522b30` | `0x00522b30` | residual stage |
| Callee | `Client_SendLogicUiPacket` | `0x004059f0` | type 0xE |

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompiler + image | **High** |
| ABI `ret 0x18` / gate / hash / RTTI UseItem / LogicUI 0xE | **High** |
| Sole caller packet arm | **High** |
| LogicUI 0xE product English | **Tentative** → `_Inferred` |
| `FUN_00522b30` product name | **Tentative** |
| Runtime / bit-exact | **Open** |
