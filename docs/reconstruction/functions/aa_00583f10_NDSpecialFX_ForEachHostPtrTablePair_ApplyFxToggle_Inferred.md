# Function record: NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00583f10` |
| **Canonical name** | `NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred` |
| **Ghidra name** | `FUN_00583f10` |
| **Address** | `0x00583f10`–`0x00583f9e` |
| **Body size** | **143** B |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / NDSpecialFX multi-host fan-out |
| **Convention** | MSVC thiscall; `RET 0x10` (4 stack dwords); ECX = table owner |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W25-D OWN) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|------|--------|
| `FUN_00583f10` | Ghidra auto |
| `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup_00583f10` | **Rejected** as sole role (caller-chain scaffold) |
| `NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred` | **Canonical** (this dual) |

## Purpose

After vbase-adjusting `this`, walk **two host-pointer vectors** (`base+0x128..+0x12c` and `base+0x13c..+0x140`). For each host pointer, call sealed `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` with the four stack args unchanged (start/stop/slot-filter/slot).

## Signature

```c
// thiscall; RET 0x10
void __thiscall NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred(
    void *table_owner,
    int want_start,
    int want_stop,
    char use_slot_filter,
    int slot_filter);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00583f10_FUN_00583f10.md`
- Annotated: `docs/reconstruction/raw/aa_00583f10_FUN_00583f10.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00583f10.cpp`
- Named: `docs/reconstruction/reconstructed-exact/NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00583f10_FUN_00583f10.md`
- Review A: `docs/reconstruction/reviews/A_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md`

## Callers / callees

| Dir | VA | Name / role |
|---|---|---|
| Callee | `0x004b7030` | `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` (W24-D) |
| Caller | `0x004c8110` | dual effect-slot apply (this dual) |
| Caller | `0x00584330` | related chain apply |
| Caller | `0x00584290` | related |
| Caller | `0x004ff6f0` | graphics path |
| Caller | `0x005857a0` / `0x00586060` | related |
| Xref | `0x0052bdfb` | additional |

## Confidence

| Claim | Level |
|---|---|
| Body span + `ret 0x10` thiscall | **Confirmed** (bytes) |
| Two host* vectors at +0x128/+0x12c and +0x13c/+0x140 | **Confirmed** |
| Per-entry ECX = *it | **Confirmed** (bytes; decomp miss) |
| Args passthrough to `004b7030` | **Confirmed** |
| Fan-out role (not list walk at +0x204) | **Confirmed** |
| Product method name | **Inferred** |
| Table A/B English | Open |
| Runtime / bit-exact | Open |
