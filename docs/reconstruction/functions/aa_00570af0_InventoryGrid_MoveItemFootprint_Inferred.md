# Function record: InventoryGrid_MoveItemFootprint_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570af0` |
| **Canonical name** | `InventoryGrid_MoveItemFootprint_Inferred` |
| **Address** | `0x00570af0` |
| **Body** | `0x00570af0`–`0x00570cfb` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual A/B + residual 2026-08-04; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** (`A_` / `B_` + residual `a_00570af0.md`) |

## Purpose

Relocate an already-bound item on an inventory grid: CanPlace at new origin (local conflictOut), clear old InvSize footprint, set origin via vtbl `+0x24c`, stamp COID into every new cell, dirty grid.

## Signature (byte-sealed 2026-08-04)

```c
uint32_t __thiscall InventoryGrid_MoveItemFootprint_Inferred(
    InventoryGrid* this,   // ECX
    ItemObject* item,      // stack0
    uint32_t originX,      // stack1
    uint32_t originY);     // stack2
// RET 0x0C
```

Decompiler label: `FUN_00570af0`. Stamp `unaff_*` in decompile is **wrong** — use clean / bytes.

## Behavioral summary

| Stage | Behavior |
|-------|----------|
| Gate | null item → 0; CanPlace fail → 0 |
| Clear | empty pairs at current GetX/GetY footprint |
| Move | `vtbl+0x24c(originX, originY)` |
| Stamp | COID `item+0x160/+0x164` full rect |
| Post | optional `FUN_00512670(*(grid+0x24))`; `grid+0x21=1` |

### Index (byte-sealed)

```text
clear:  index = height * curX + curY
stamp:  index = height * (originX + dx) + (originY + dy)
// height = *(grid+0x0c); cells = *(grid+0x28); stride 8
```

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature | **Confirmed** (`RET 0x0C`) |
| Control flow | High |
| Stamp/clear formula | **Confirmed** |
| Naming | Inferred (no xrefs) |
| Callers | **Open** (Ghidra empty) |
| Overall | **Probable / accept-with-gaps** |

## Open questions

- Discover callers (indirect / table / dead).
- Runtime overlapping move cell dump.
- Product English / PDB.
- Differential / bit-exact.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00570af0_FUN_00570af0.md`
- Annotated: `docs/reconstruction/raw/aa_00570af0_FUN_00570af0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_MoveItemFootprint_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00570af0.cpp`
- Dual A/B: `reviews/A|B_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md`
- Residual: `reviews/a_00570af0.md`
