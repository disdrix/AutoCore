# Function record: Object_ApplyDualFxSlots_SlotFilterWild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8110` |
| **Canonical name** | `Object_ApplyDualFxSlots_SlotFilterWild_Inferred` |
| **Ghidra name** | `FUN_004c8110` |
| **Address** | `0x004c8110`–`0x004c81e5` |
| **Body size** | **214** B |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / dual effect-slot apply |
| **Convention** | MSVC thiscall; **no stack formals**; **tail jmp** `FUN_00584330` |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W25-D OWN) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|------|--------|
| `FUN_004c8110` | Ghidra auto |
| `Object_ApplyDualFxSlots_SlotFilterWild_Inferred` | **Canonical** (this dual) |

## Purpose

For each non-null effect pointer in dual slots (`this-0x27c`, `this-0x280`):

1. Fan-out via `NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred` (`0x00583f10`) on `this-0x4c0` with args `(0, effect, 1, -1)`.
2. Apply sealed `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` to each host in a local host* vector (vb from `this-0x4fc`, range `-0x3c4..-0x3c0`) with the same args.

Then **tail-chain** `FUN_00584330` with `ECX = this - 0x430`.

## Signature

```c
// thiscall; no stack args; does not return (tail jmp)
void __thiscall Object_ApplyDualFxSlots_SlotFilterWild_Inferred(void *self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c8110_FUN_004c8110.md`
- Annotated: `docs/reconstruction/raw/aa_004c8110_FUN_004c8110.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004c8110.cpp`
- Named: `docs/reconstruction/reconstructed-exact/Object_ApplyDualFxSlots_SlotFilterWild_Inferred.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004c8110_FUN_004c8110.md`
- Review A: `docs/reconstruction/reviews/A_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md`

## Callers / callees

| Dir | VA | Name / role |
|---|---|---|
| Callee | `0x00583f10` | `NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred` (this dual) |
| Callee | `0x004b7030` | `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` (W24-D) |
| Callee | `0x00584330` | chain apply (tail jmp; not owned) |
| Caller | `0x004cce83` | MI this-adjust thunk |
| Caller | `0x0053bc49` | MI this-adjust + sub `0x8a0` thunk |

## Confidence

| Claim | Level |
|---|---|
| Dual slots + null gates | **Confirmed** |
| Arg pack `(0, effect, 1, -1)` | **Confirmed** |
| `00583f10` + local vector + `004b7030` | **Confirmed** |
| Tail jmp `00584330` @ this-0x430 | **Confirmed** |
| thiscall nested subobject | **Confirmed** |
| Product class/slot names | **Inferred** |
| Runtime / bit-exact | Open |
