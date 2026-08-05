# Function record: CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d630` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress` |
| **Ghidra name** | `FUN_0060d630` |
| **Address** | `0x0060d630` |
| **Body** | `0x0060d630`–`0x0060d7e1` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B sealed** (WQ7R-H 2026-08-04); runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Purpose

UseItem requirement apply path for matched **object-use events** (caller events 9/10): advance progress slot by 1.0, optional inventory give/remove and world-object destroy, and on eval complete optionally **`CVOGReaction_GiveMission`** + give item. Primary residual **GiveMission** caller on WQ-007 UseItem chain.

## Signature

```c
uint8_t /* AL */ __thiscall
CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress(
    UseItemReq* this,   // ECX
    void* charCtx,      // stack+4
    void* progress,     // stack+8  (slot floats; Eval-compatible)
    void* worldObj);    // stack+0xC
// ret 0x0C
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060d630_FUN_0060d630.md` |
| Annotated | `docs/reconstruction/raw/aa_0060d630_FUN_0060d630.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060d630.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0060d630_CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0060d630_CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.md` |
| Scratch | `docs/reconstruction/tmp/a_0060d630.md` |
| Function FUN | `docs/reconstruction/functions/aa_0060d630_FUN_0060d630.md` |

## Callers / callees

| Direction | Symbol | VA | Notes |
|---|---|---|---|
| Caller | `FUN_0060df70` | `0x0060df70` | sole; call @`0x0060e061` |
| Callee | `CVOGReaction_GiveMission` | `0x005327c0` | on eval complete; id @req+0x4c |
| Callee | `CVOGReaction_RemoveInventoryItem` | `0x005721c0` | primary/secondary remove |
| Callee | `FUN_005310a0` | `0x005310a0` | give-by-cbid (InitActive sibling) |
| Callee | `FUN_007a4480` | `0x007a4480` | fail log |
| Callee | `FUN_004d0e90` | `0x004d0e90` | mark object destroy |

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompiler + ABI image | **High** |
| Class UseItem via RTTI/vtable | **High** |
| GiveMission residual role | **High** |
| Parameter product English (progress/worldObj) | **Probable** |
| Runtime / bit-exact | **Open** |
