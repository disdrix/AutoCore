# Function record: InventoryGrid_CanPlaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005715d0` |
| **Canonical name** | `InventoryGrid_CanPlaceItem` |
| **Address** | `0x005715d0` |
| **Body** | `0x005715d0`–`0x0057161d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual A/B + residual 2026-08-04 |
| **Bit-for-bit / runtime / diff** | Open (deferred; leaf not blocking) |
| **Dual verdict** | **accept** (`A_` / `B_` + residual `a_005715d0.md`) |

## Purpose

Thin item-aware wrapper: load InvSizeX/Y from item clonebase and call `InventoryGrid_CanPlace`. No cell mutation.

## Signature (byte-sealed 2026-08-04)

```c
uint32_t __thiscall InventoryGrid_CanPlaceItem(
    InventoryGrid* this,     // ECX
    ItemObject* item,        // stack0
    uint32_t originX,        // stack1
    uint32_t originY,        // stack2
    uint32_t* conflictOut);  // stack3 nullable
// RET 0x10
```

Decompiler label: `FUN_005715d0`. Decompiler may hide thiscall — **bytes seal ECX = grid**.

## Behavioral summary

```text
if item == null: return 0
return CanPlace(this, InvSizeX, InvSizeY, originX, originY, conflictOut)
// InvSize from *(*(item+0xa8)+0x3c) +0x406/+0x407
```

## Callers / callees

| Kind | Targets |
|------|---------|
| Callee | `InventoryGrid_CanPlace` `0x00570840` |
| Callers | `FUN_008012f0`, `Client_ConfirmEquipOrCustomizeItem` `0x00941b20`, `FUN_00952bc0`, `FUN_00955010` (18 xrefs) |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **Confirmed** |
| Signature | **Confirmed** (`RET 0x10`) |
| Control flow | **Confirmed** |
| InvSize path | **Confirmed** |
| Naming | Probable |
| Overall | **accept** |

## Open questions

- Product/PDB English.
- Runtime non-null conflictOut via this wrapper (callers often pass 0).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005715d0_FUN_005715d0.md`
- Annotated: `docs/reconstruction/raw/aa_005715d0_FUN_005715d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_CanPlaceItem.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005715d0.cpp`
- Dual A/B: `reviews/A|B_aa_005715d0_InventoryGrid_CanPlaceItem.md`
- Residual: `reviews/a_005715d0.md`
