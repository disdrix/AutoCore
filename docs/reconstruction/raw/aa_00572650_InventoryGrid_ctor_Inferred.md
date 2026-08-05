# Raw capture: InventoryGrid_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572650` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00572650` |
| **Canonical name** | `InventoryGrid_ctor_Inferred` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* InventoryGrid_ctor_Inferred — construct inventory grid (0x68 bytes).
   
   Parameters:
     this; nWidth (cargo=6); nHeight (cargo=pages*13); nPages (clamped >=1)
   Returns: this.
   
   Algorithm:
     Init vtable/CS/RB-tree; store width@dword[2], height@[3], pages@[5]
     Clamp dims >=1; InventoryGrid_AllocateCellArray_Inferred
   Name INFERRED — retail symbol not recovered. */

void * __thiscall InventoryGrid_ctor_Inferred(void *this,int nWidth,int nHeight,int nPages)

{
  int pTreeSentinel;
  void *pExceptionList;
  undefined1 *puStack_8;
  undefined4 nSehState;
  
  nSehState = 0xffffffff;
  puStack_8 = &LAB_009a4f62;
  pExceptionList = ExceptionList;
  ExceptionList = &pExceptionList;
  *(undefined ***)this = &PTR_FUN_009d3390;
  *(undefined ***)((int)this + 0x2c) = &PTR_FUN_009cb334;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined1 *)((int)this + 0x54) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  *(undefined ***)((int)this + 0x2c) = &PTR_FUN_009d3384;
  nSehState = 0;
  pTreeSentinel = FUN_005ae2b0();
  *(int *)((int)this + 0x60) = pTreeSentinel;
  *(undefined1 *)(pTreeSentinel + 0x19) = 1;
  *(int *)(*(int *)((int)this + 0x60) + 4) = *(int *)((int)this + 0x60);
  *(undefined4 *)*(undefined4 *)((int)this + 0x60) = *(undefined4 *)((int)this + 0x60);
  *(int *)(*(int *)((int)this + 0x60) + 8) = *(int *)((int)this + 0x60);
  *(undefined4 *)((int)this + 100) = 0;
  *(int *)((int)this + 0xc) = nHeight;
  nSehState = CONCAT31(nSehState._1_3_,1);
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined1 *)((int)this + 0x20) = 0;
  *(undefined1 *)((int)this + 0x21) = 0;
  *(undefined1 *)((int)this + 0x22) = 0;
  *(int *)((int)this + 8) = nWidth;
  *(int *)((int)this + 0x14) = nPages;
  if (nPages < 1) {
    *(undefined4 *)((int)this + 0x14) = 1;
  }
  if (*(int *)((int)this + 8) < 1) {
    *(undefined4 *)((int)this + 8) = 1;
  }
  if (*(int *)((int)this + 0xc) < 1) {
    *(undefined4 *)((int)this + 0xc) = 1;
  }
  InventoryGrid_AllocateCellArray_Inferred(this);
  ExceptionList = pExceptionList;
  return this;
}
```
