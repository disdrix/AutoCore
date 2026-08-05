# Raw capture: Client_SendInventoryGrab_FromGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860e20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00860e20` |
| **Canonical name** | `Client_SendInventoryGrab_FromGrid` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* C2S InventoryGrab (0x2034, size 0x20) from inventory grid. inventoryType from window+0x56c+4;
   quantity from stack arg. Sends via connection vtable+0x18. */

undefined4 Client_SendInventoryGrab_FromGrid(int param_1,undefined4 param_2)

{
  int iVar1;
  int *unaff_EDI;
  undefined4 auStack_20 [2];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 uStack_10;
  undefined1 uStack_8;
  undefined4 uStack_4;
  
  if (unaff_EDI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_EDI + 0x3ac))();
    if (((iVar1 == 0) || (DAT_00d1d8dc == (int *)0x0)) || (iVar1 == DAT_00d1d8dc[0x146])) {
      DAT_00d1d8f4 = 1;
      DAT_00d1d8f5 = 0;
      if (DAT_00d1d8dc != (int *)0x0) {
        (**(code **)(*DAT_00d1d8dc + 4))(0);
      }
    }
  }
  FUN_007fbbb0();
  if (DAT_00d1a8f6 == '\0') {
    auStack_20[0] = 0x2034;
    iVar1 = (**(code **)(*unaff_EDI + 0x3ac))();
    uStack_10 = *(undefined1 *)(iVar1 + 0x168);
    iVar1 = (**(code **)(*unaff_EDI + 0x3ac))();
    uStack_18 = *(undefined4 *)(iVar1 + 0x160);
    uStack_14 = *(undefined4 *)(iVar1 + 0x164);
    uStack_8 = *(undefined1 *)(*(int *)(param_1 + 0x56c) + 4);
    uStack_4 = param_2;
    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {
      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,auStack_20,0x20,0);
    }
    DAT_00d1b4b0 = 1;
    DAT_00d1a8f6 = '\x01';
  }
  return 1;
}
```
