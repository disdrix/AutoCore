# Function record: InventoryGrid_RemoveItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571b80` |
| **Canonical name** | `InventoryGrid_RemoveItem` |
| **Ghidra name** | `FUN_00571b80` |
| **Address** | `0x00571b80` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-07-29; clear formula + ABI byte-sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** (`A_` / `B_` + residual `a_00571b80.md`) |

## Alias

- `FUN_00571b80`
- Partition-map: “inventory occupancy sibling” of PlaceItemFootprint (unstamp / pull)
- Prior scaffold: `Named_CalleeOf_Client_RecvInventoryEquip_00571b80`
- Acceptable descriptive alias: `InventoryGrid_RemoveItemFootprint` (full path only; body also peels stacks)

## Purpose

Remove an item from a client inventory grid:

1. Gate: non-null + list membership at `grid+0x2c` (`FUN_00415c00`).
2. If stack-mode (`FUN_00513e70`): optional **qty peel** `SetQty(cur - removeQty)`; when remaining &gt; 0 and `forceFull==0`, skip unstamp/detach and return **null** (grid dirty still set).
3. Full path: **clear** InvSize footprint cells to empty `(-1,-1)` (type 4 skips clear); **detach** list via `FUN_005085b0(grid+0x2c, item)`; SetQty(saved); unbind `vtbl+0x158(0)`; dirty owner + `grid+0x21`; return **item\***.

## Signature (byte-sealed 2026-07-29)

```c
// MSVC __thiscall; RET 0x0C  (epilogue C2 0C 00)
ItemObject* InventoryGrid_RemoveItem(
    InventoryGrid* this,      // ECX
    ItemObject*    item,      // stack0
    int            removeQty, // stack1
    char           forceFull  // stack2
);
```

## Behavioral summary

| Path | Cells | List | Return |
|------|-------|------|--------|
| Null / not in list | unchanged | — | `nullptr` |
| Stack peel, remain&gt;0, force=0 | **unchanged** (still stamped) | stays | `nullptr` |
| Full remove, type ≠ 4 | footprint → empty | detach | `item*` |
| Full remove, type 4 | no clear | detach | `item*` |

### Unstamp index (byte-sealed)

```text
index = *(grid+0x0c) * (originX + dx) + (originY + dy)
// cells[index].lo/hi = 0xFFFFFFFF
```

Same family as Place / CanPlace / FindFree (`height * x + y`).

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature / `RET 0x0C` | **Confirmed** |
| Membership gate `+0x2c` | **Confirmed** |
| Unstamp formula | **Confirmed** (`read_memory`) |
| List detach `FUN_005085b0@+0x2c` | **Confirmed** |
| Stack peel CF | **High** (decompile ≡ raw + partial bytes) |
| Naming | Probable–High |
| Runtime / bit-exact | Open |

## Open questions

- Runtime: peel leaves multi-cell COID stamps until full remove
- Bit15 of `item+0x17c` product meaning
- `FUN_005085b0` vs Place attach `FUN_00566f00` shared layout depth
- PDB English name

## Offsets (body-backed)

### InventoryGrid (`this`)

| Offset | Role |
|--------|------|
| `+0x0c` | Height / index multiplier |
| `+0x10` | Total cell count (bounds) |
| `+0x21` | Dirty byte ← 1 |
| `+0x24` | Owner; optional `FUN_00512670` |
| `+0x28` | Cell array (8 B COID pairs) |
| `+0x2c` | List subobject (contains + detach) |

### Item / clonebase

| Location | Role |
|----------|------|
| `+0xa8` → `+0x38` | Object type; **4** skips clear |
| `+0xa8` → `+0x3c` → `+0x406/+0x407` | InvSizeX / InvSizeY |
| vtbl `+0x250/+0x254` | Origin X / Y |
| vtbl `+0x25C/+0x260` | GetQty / SetQty |
| vtbl `+0x158` | Unbind(0) |
| `+0x17c` bit15 | Skip-full unless `forceFull` |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00571b80_FUN_00571b80.md` |
| Annotated | `raw/aa_00571b80_FUN_00571b80.annotated.md` |
| Clean | `reconstructed-exact/InventoryGrid_RemoveItem.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_00571b80.cpp` (superseded) |
| Dual A | `reviews/A_aa_00571b80_InventoryGrid_RemoveItem.md` |
| Dual B | `reviews/B_aa_00571b80_InventoryGrid_RemoveItem.md` |
| Residual | `reviews/a_00571b80.md` |
| Place sibling | `aa_00571620` / `InventoryGrid_PlaceItemFootprint` |
| Contains sibling | `aa_00571b60` / `InventoryGrid_ContainsItem` |

## Callers / callees

**Callees:** `FUN_00415c00`, `FUN_00513e70`, `FUN_005085b0`, `FUN_00512670`, item vtbls.

**Callers (Ghidra):**  
`CVOGReaction_RemoveInventoryItem` (`0x005721c0`), `Client_RecvInventoryDropResponse` (`0x00813730`), `Client_RecvInventoryEquip` (`0x00813f40`), `FUN_00571d80`, `FUN_00571db0`, `FUN_00571e10`, `FUN_00572ab0`, `FUN_005879e0`, `FUN_00587c00`, `FUN_005252f0`, `FUN_008019d0`, `FUN_0080d570`, `FUN_0080d930`, `FUN_008134d0`, `FUN_0093c3b0`, `FUN_0093d6e0`, `FUN_00944d50`, `FUN_00952bc0`, `FUN_00955010`.

Typical args: `(item, 1, 0)` equip/drop pull; `(item, qty, 0)` partial; `(item, 1000000, 1)` force destroy path.
