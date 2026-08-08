# Function record (named): InventoryGrid_RemoveAllAndReEmptyCells_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570f50` |
| **Semantic name** | `InventoryGrid_RemoveAllAndReEmptyCells_Inferred` |
| **Ghidra name** | `FUN_00570f50` |
| **Address** | `0x00570f50`–`0x00570f62` inclusive (**19 B** / `0x13`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Partition** | R10-013 residual dual; parent dual `0x00570720` |
| **Naming basis** | `List_RemoveAll(grid+0x2c)` + dualed `AllocateCellArray` re-empty; thin twin of ClearItems path |
| **Status** | Dual sealed R10-013 (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / superseded

- Scaffold: `FUN_00570f50` (2026-07-23)
- Parent-seed alias: `Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_00570f50` — **not** preferred (single-caller bias; multi-caller inventory helper)
- Twin: `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` @ `0x00570f70` (full item teardown first)

## Purpose

Thin **clear/re-empty** of an `InventoryGrid` without the item-walk detach path:

1. `list = grid + 0x2c`
2. `List_RemoveAll(list)` — CS enter; throw if locked; drain nodes with scalar-deleting dtor; clear head/counts; CS leave
3. Tail to `InventoryGrid_AllocateCellArray_Inferred(grid)` — free `+0x28`, recompute totals, alloc empty cells (`0xFFFFFFFF` fill)

Does **not** destroy the grid object, free cells without realloc, place/stamp items, or perform twin’s TraversalLock + `vtbl+0x158` detach + `FUN_004d4790` branch.

## Signature

```c
// __fastcall / thiscall-shaped; ECX=InventoryGrid*; void; tail-JMP to Allocate
void __fastcall InventoryGrid_RemoveAllAndReEmptyCells_Inferred(InventoryGrid *grid);
```

## Layouts

### InventoryGrid (partial — this unit)

| Off | Field | Conf |
|----:|-------|------|
| `+0x28` | cell array* (rewritten by Allocate) | **High** |
| `+0x2c` | embedded List host | **High** |

### List host (via dualed RemoveAll)

| Off | Field | Conf |
|----:|-------|------|
| `+0x04` | `CRITICAL_SECTION` | **High** |
| `+0x1c` | head | **High** |
| `+0x20`, `+0x24` | counts / aux cleared | **High** |
| `+0x28` | traversal-lock flag | **High** |

## Callers / callees

| Dir | VA | Name |
|-----|-----|------|
| out | `0x004bc580` | `List_RemoveAll` |
| out | `0x00570720` | `InventoryGrid_AllocateCellArray_Inferred` |
| in | `0x00534bd0` | `CVOGCharacter_ApplyCreateFromPacket` |
| in | `0x00505270` | `Vehicle_applyCreatePacket` |
| in | `0x0052f260` | `FUN_0052f260` (×3 sites) |
| in | `0x004ffe60` | `FUN_004ffe60` |
| in | `0x0051f1f0` | `FUN_0051f1f0` (×3) |
| in | `0x00588cc0` | `FUN_00588cc0` |
| in | `0x00884720` | `FUN_00884720` |
| in | `0x004f358a`, `0x0058761a` | additional xrefs |

## Confidence

| Claim | Level |
|---|---|
| CF: RemoveAll then Allocate | **High** |
| list @ `+0x2c` | **High** |
| Thin vs full twin distinction | **High** |
| Retail symbol | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00570f50_FUN_00570f50.md`
- Annotated: `docs/reconstruction/raw/aa_00570f50_FUN_00570f50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveAllAndReEmptyCells_Inferred.cpp`
- Clean FUN: `docs/reconstruction/reconstructed-exact/FUN_00570f50.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00570f50_*` / `B_aa_00570f50_*`
- Report: `docs/agents/task-dual-ab-00570f50-r10-report.md`
