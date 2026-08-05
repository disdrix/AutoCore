# Function record: InventoryGrid_SortAndRepack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572730` |
| **Canonical name** | `InventoryGrid_SortAndRepack_Inferred` |
| **Ghidra name** | `FUN_00572730` |
| **Address** | `0x00572730` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual A/B complete** (2026-07-29 W20-S) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Sort and repack an inventory grid under a caller-supplied comparator: allocate a same-dimension temp grid, empty this item tree, repeatedly pick the best remaining item, FindFree+Place into the temp (type-4 fixed at 0,0), then commit back to this (or abort via fail helper and return 0).

## Signature (image-sealed)

```c
// __thiscall ECX=InventoryGrid*, stack compareFn + compareCtx, ret 8
// returns 1 success / 0 fail; adjusted-null this==0xFFFFFFD4 → 0
uint32_t InventoryGrid_SortAndRepack_Inferred(
    void *thisGrid,
    char (*compareFn)(uint32_t ctx, int *cand, int *best),
    uint32_t compareCtx);
```

## Artifacts

| Role | Path |
|---|---|
| Raw scaffold + re-verify | `docs/reconstruction/raw/aa_00572730_FUN_00572730.md` |
| Annotated | `docs/reconstruction/raw/aa_00572730_FUN_00572730.annotated.md` |
| Raw named | `docs/reconstruction/raw/aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_SortAndRepack_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00572730.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00572730_InventoryGrid_SortAndRepack_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00572730_FUN_00572730.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x00572ed0` | `FUN_00572ed0` — passes `FUN_00572f30` |
| Caller | `0x00572ef0` | `FUN_00572ef0` — passes `LAB_00572fe0` |
| Callee | `0x005713a0` | `InventoryGrid_FindFreeSlot` (page `-1`) |
| Callee | `0x00571620` | `InventoryGrid_PlaceItemFootprint` |
| Callee | ctor / alloc | `InventoryGrid_ctor_Inferred`, `InventoryGrid_AllocateCellArray_Inferred` |
| Callee | `0x00572360` | re-place / commit pass |
| Callee | `0x005731c0` | RB node free |
| Callee | list helpers | `FUN_004294f0`, `FUN_004022a0`, `FUN_00566f00`, `FUN_004bc580`, `FUN_004bc950` |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Temp grid heap size | `0x68` | High |
| Grid width / height / field | `+0x08` / `+0x0c` / `+0x14` | High |
| Grid CS / held | `+0x30` / `+0x54` | High |
| Item RB / count | `+0x60` / `+0x64` | High |
| Item type field | `item[0x2a]+0x38` (4 = fixed 0,0) | High |
| InvSize bytes | clonebase blob `+0x406` / `+0x407` | High (shared FindFree family) |
| Item vfuncs | `+0x250`, `+0x254`, `+0x25c` | High |

## Confidence

| Claim | Level |
|---|---|
| Control flow / return codes | High |
| ABI ret 8 + adjusted-null | High |
| Temp grid + FindFree/Place sort role | High |
| Product name | Tentative (`_Inferred`) |
| Exact list/grid ECX per call | Tentative (decomp residual) |
| Runtime / bit-exact | Open |
