# Function record: InventoryGrid_RemoveItemAtXY

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571db0` |
| **Canonical name** | `InventoryGrid_RemoveItemAtXY` |
| **Ghidra name** | `FUN_00571db0` |
| **Address** | `0x00571db0` |
| **Body** | `0x00571db0`–`0x00571e0e` (94 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-08-04 (WQ8R-G) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** (`A_` / `B_`) |

## Alias

- `FUN_00571db0`
- Descriptive: `InventoryGrid_RemoveAtCell`, `InventoryGrid_ClearCellRemoveOne`
- Sibling thin path: `FUN_00571d80` FindByCoid + Remove (forceFull from arg)

## Purpose

Bounds-check grid cell `(x,y)`, read the 8-byte COID stamp from the cell array, resolve the item via `InventoryGrid_FindItemByCoid`, then `InventoryGrid_RemoveItem(item, 1, forceFull=0)` (stack peel or full unstamp depending on qty/flags).

## Signature (byte-sealed 2026-08-04)

```c
// MSVC __thiscall; RET 0x08  (epilogue C2 08 00)
ItemObject* InventoryGrid_RemoveItemAtXY(
    InventoryGrid* this,  // ECX
    uint8_t        x,     // stack0
    uint8_t        y);    // stack1
```

## Behavioral summary

| Path | Result |
|------|--------|
| `x >= width(+0x08)` or `y >= height(+0x0c)` | `nullptr` (no callees) |
| In bounds | `RemoveItem(FindItemByCoid(cellCoid), 1, 0)` |

### Index formula (byte-sealed)

```text
index = *(grid+0x0c) * x + y     // height * x + y
// cells = *(grid+0x28); entry = cells[index] as {coidLo, coidHi} @ *8
```

Same packing family as Place / CanPlace / FindFree / RemoveItem unstamp.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **Confirmed** |
| Signature / `RET 0x08` | **Confirmed** |
| Index formula | **Confirmed** (`read_memory`) |
| Callees Find + Remove | **Confirmed** (rel32) |
| forceFull always 0 / qty 1 | **Confirmed** (`push 0; push 1`) |
| Naming | Probable (Inferred) |
| Static callers | **None in Ghidra** (gap) |
| Runtime / bit-exact | Open |

## Open questions

- Who calls this VA (0 static CALL xrefs)?
- PDB English name
- Runtime peel vs full-remove from empty/invalid cell COIDs (`-1,-1`)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00571db0_FUN_00571db0.md`
- Annotated: `docs/reconstruction/raw/aa_00571db0_FUN_00571db0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveItemAtXY.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00571db0.cpp`
- Function (Ghidra): `docs/reconstruction/functions/aa_00571db0_FUN_00571db0.md`
- Reviews: `A_aa_00571db0_InventoryGrid_RemoveItemAtXY.md`, `B_aa_00571db0_InventoryGrid_RemoveItemAtXY.md`
