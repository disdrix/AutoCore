# Raw capture: Client_SendInventoryGrab_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862d90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00862d90` |
| **Canonical name** | `Client_SendInventoryGrab_Hardpoint` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* C2S InventoryGrab (0x2034, size 0x20) for equipped/hardpoint items. Sets inventoryType=2 at
   +0x18. TFID from item obj +0x160/+0x164/+0x168. Called from Client_UI_InventoryItemClickDispatch
   when store cursor is null. */

undefined4 Client_SendInventoryGrab_Hardpoint(void)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_EBX;
  undefined4 auStack_20 [2];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 uStack_10;
  undefined1 uStack_8;
  
  FUN_007fbbb0();
  if (DAT_00d1b6d8 != 0) {
    iVar1 = (**(code **)(*unaff_EBX + 0x3ac))();
    if (iVar1 != 0) {
      uVar2 = (**(code **)(*unaff_EBX + 0x3ac))();
      iVar1 = FUN_004f6a80(uVar2);
      if (iVar1 != 0) {
        FUN_00931db0();
        return 0;
      }
      auStack_20[0] = 0x2034;
      iVar1 = (**(code **)(*unaff_EBX + 0x3ac))();
      uStack_10 = *(undefined1 *)(iVar1 + 0x168);
      iVar1 = (**(code **)(*unaff_EBX + 0x3ac))();
      uStack_18 = *(undefined4 *)(iVar1 + 0x160);
      uStack_14 = *(undefined4 *)(iVar1 + 0x164);
      uStack_8 = 2;
      Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_20);
      (**(code **)(*unaff_EBX + 0x3bc))(1);
      (**(code **)(*unaff_EBX + 0x34c))();
      return 1;
    }
  }
  return 0;
}
```
