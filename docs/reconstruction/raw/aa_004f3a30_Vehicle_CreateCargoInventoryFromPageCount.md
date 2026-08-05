# Raw capture: Vehicle_CreateCargoInventoryFromPageCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3a30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f3a30` |
| **Canonical name** | `Vehicle_CreateCargoInventoryFromPageCount` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Vehicle_CreateCargoInventoryFromPageCount — cargo grid from chassis page count.
   
   Parameters:
     this: vehicle; nPages: chassis InventorySlots (pages, NOT total cells)
   Returns: void.
   
   Algorithm:
     Destroy prior grid @vehicle+0x2b0
     If not special flag@+0x2ac: new InventoryGrid(width=6, height=nPages*13, pages=nPages)
     Bind owner TFID / character to grid vfuncs +0x18/+0x14
   
   Callisto X InventorySlots=1 → 78 cells. Wire page-count not total slots.
   AutoCore: VehicleCargoCapacity, InventoryPacketFactory page wire. */

void __thiscall Vehicle_CreateCargoInventoryFromPageCount(void *this,short nPages)

{
  void *pNewGridMem;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2c75;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)((int)this + 0x2b0) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)((int)this + 0x2b0))(1);
  }
  *(undefined4 *)((int)this + 0x2b0) = 0;
  if (*(char *)((int)this + 0x2ac) == '\0') {
    pNewGridMem = operator_new(0x68);
                    /* Store grid pointer at vehicle+0x2b0; bind owner */
    uStack_4 = 0;
    if (pNewGridMem == (void *)0x0) {
      pNewGridMem = (void *)0x0;
    }
    else {
      pNewGridMem = InventoryGrid_ctor_Inferred(pNewGridMem,6,nPages * 0xd,(int)nPages);
    }
    uStack_4 = 0xffffffff;
    *(void **)((int)this + 0x2b0) = pNewGridMem;
    InventoryGrid_SetOwnerFlag_Inferred(pNewGridMem,1);
    (**(code **)(**(int **)((int)this + 0x2b0) + 0x18))
              (*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this);
    (**(code **)(**(int **)((int)this + 0x2b0) + 0x14))
              (*(undefined4 *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this));
  }
  ExceptionList = pvStack_c;
  return;
}
```
