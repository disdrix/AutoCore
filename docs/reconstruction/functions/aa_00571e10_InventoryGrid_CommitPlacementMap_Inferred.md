# Function record: InventoryGrid_CommitPlacementMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571e10` |
| **Canonical name** | `InventoryGrid_CommitPlacementMap_Inferred` |
| **Ghidra name** | `FUN_00571e10` |
| **Address** | `0x00571e10`–`0x00571fae` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual A/B complete** (2026-07-29 W22-C) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Apply the client inventory **placement map** (`grid+0x60`) to live item/cell state, optionally migrating items off a related grid via `InventoryGrid_RemoveItem`, then wipe the map.

Used as:

1. **Fail restore** after RePlaceItems cannot place (with related+flag).
2. **Success commit** when RePlaceItems flag requests related remove+clear.
3. **Fail restore** for SortAndRepack with `(0,0)` (restamp+clear only).

## Signature (image-sealed)

```c
void InventoryGrid_CommitPlacementMap_Inferred(
    void *thisGrid,     // ECX
    void *relatedGrid,  // stack0
    char  doRemove);    // stack1; ret 8
```

## Artifacts

| Role | Path |
|---|---|
| Raw + W22-C | `docs/reconstruction/raw/aa_00571e10_FUN_00571e10.md` |
| Annotated | `docs/reconstruction/raw/aa_00571e10_FUN_00571e10.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_CommitPlacementMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00571e10.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00571e10_InventoryGrid_CommitPlacementMap_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00571e10_InventoryGrid_CommitPlacementMap_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00571e10_FUN_00571e10.md` |

## Offsets (body-backed)

| Rel | Role |
|---:|---|
| `grid+0x0c` | pitch for cell index |
| `grid+0x24` | owner bind arg |
| `grid+0x28` | cell array base (8-byte entries) |
| `grid+0x5c` | map shell for `FUN_005731c0` |
| `grid+0x60` | map head pointer |
| `grid+0x64` | map element count (cleared to 0) |
| `node+0x10` | item* |
| `node+0x14/+0x15` | origin X/Y |
| `node+0x19` | isnil |
| `item+0x160/+0x164` | COID lo/hi as dword indices `0x58/0x59` |
| clone `+0x406/+0x407` | footprint h/w |

## Open questions

- PDB/product symbol.
- relatedGrid exact class identity.
- Compose with success-path double-clear in RePlaceItems (map already empty).
