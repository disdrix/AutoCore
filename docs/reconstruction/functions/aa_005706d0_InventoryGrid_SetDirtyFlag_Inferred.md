# Function record: InventoryGrid_SetDirtyFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005706d0` |
| **Canonical name** | `InventoryGrid_SetDirtyFlag_Inferred` |
| **Ghidra symbol** | `FUN_005706d0` |
| **Address** | `0x005706d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (2026-07-29; WQ8R-J reconfirm 2026-08-04) |
| **Name confidence** | **Inferred** — dirty byte + place-family callers; no PDB string |

## Purpose

Leaf post-stamp dirty mark for InventoryGrid.

## Contract

```
// __thiscall InventoryGrid* this; plain ret
void InventoryGrid_SetDirtyFlag_Inferred(grid);
// if (obj = grid[+0x24]) Object_PropagateDirtyBit0x20000(obj);  // | 0x20000 @ +0x17c chain
// grid[+0x21] = 1;
```

## Related

| Unit | Role |
|---|---|
| `InventoryGrid_PlaceItemFootprint` `0x00571620` | primary post-stamp caller |
| `Object_PropagateDirtyBit0x20000` `0x00512670` | owner dirty bit |
| MergeStackQty `0x00571830` | also sets `+0x21` |

## Gaps

- Product English for `+0x21` / `+0x24`
- Clearer of dirty flag
- Runtime / bit-exact
