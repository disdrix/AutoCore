# Raw named plate: InventoryGrid_RePlaceItems_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572360` |
| **VA** | `0x00572360` |
| **Ghidra** | `FUN_00572360` |
| **Canonical name** | `InventoryGrid_RePlaceItems_Inferred` |
| **System** | inventory-transfer |
| **Capture** | 2026-07-29 W21-B (named plate over 2026-07-23 scaffold) |

Authoritative decompile body lives in `raw/aa_00572360_FUN_00572360.md` (append-only).  
This plate records the inferred product name only.

## Signature

```c
// __thiscall ECX=InventoryGrid*, stack relatedPtr + flag, ret 8
// returns 1 success / 0 fail; relatedPtr==null → 0
uint32_t InventoryGrid_RePlaceItems_Inferred(void *thisGrid, void *relatedPtr, char flag);
```

## Semantics (one-liner)

Walk grid item enumeration; CanPlace at saved origin or FindFree(page=-1); PlaceItemFootprint; on full success clear RB (+ optional AllocCell); on fail restore helper + return 0.
