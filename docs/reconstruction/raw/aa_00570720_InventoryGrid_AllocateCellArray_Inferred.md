# Raw capture: InventoryGrid_AllocateCellArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570720` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00570720` |
| **Canonical name** | `InventoryGrid_AllocateCellArray_Inferred` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* InventoryGrid_AllocateCellArray_Inferred — allocate empty cell array.
   
   Parameters:
     pGrid (ECX): inventory grid
   Returns: void.
   
   Algorithm:
     free old cells@+0x28; nTotal=width*height → +0x10
     derive page dims @+0x18/+0x1c; allocate nTotal * 8 bytes filled with -1
   Name INFERRED. */

void __fastcall InventoryGrid_AllocateCellArray_Inferred(void *pGrid)

{
  undefined4 *pCell;
  int nTotalCells;
  uint nDwordCount;
  
  if (*(void **)((int)pGrid + 0x28) != (void *)0x0) {
    operator_delete__(*(void **)((int)pGrid + 0x28));
  }
  nTotalCells = *(int *)((int)pGrid + 8) * *(int *)((int)pGrid + 0xc);
  *(undefined4 *)((int)pGrid + 0x28) = 0;
  *(int *)((int)pGrid + 0x10) = nTotalCells;
  *(int *)((int)pGrid + 0x1c) =
       (nTotalCells / *(int *)((int)pGrid + 0x14)) / *(int *)((int)pGrid + 8);
  *(int *)((int)pGrid + 0x18) = nTotalCells / *(int *)((int)pGrid + 0xc);
  pCell = operator_new__(nTotalCells * 8);
  *(undefined4 **)((int)pGrid + 0x28) = pCell;
  for (nDwordCount = (uint)(*(int *)((int)pGrid + 0x10) * 8) >> 2; nDwordCount != 0;
      nDwordCount = nDwordCount - 1) {
    *pCell = 0xffffffff;
    pCell = pCell + 1;
  }
  for (nTotalCells = 0; nTotalCells != 0; nTotalCells = nTotalCells + -1) {
    *(undefined1 *)pCell = 0xff;
    pCell = (undefined4 *)((int)pCell + 1);
  }
  return;
}
```
