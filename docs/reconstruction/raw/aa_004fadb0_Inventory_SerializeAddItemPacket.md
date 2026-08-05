# Raw capture: Inventory_SerializeAddItemPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fadb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fadb0` |
| **Canonical name** | `Inventory_SerializeAddItemPacket` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Inventory_SerializeAddItemPacket - fills an InventoryAddItem packet (param_2) from an item object
   (param_3/piVar2). Writes packet+8 = item[0x58] (grid X, byte off +0x160), packet+0xc = item[0x59]
   (grid Y, +0x164), packet+0x12 = addToExisting, packet+0x18 = wasAdded. item[0x2a] (+0xa8) ->
   type/clonebase ptr; +0x38==4 is a slot-type check. item[0x5f] (+0x17c) = flags bitfield.
   World-object branch reads coid from obj+0x160/+0x164. */

char __thiscall Inventory_SerializeAddItemPacket(int param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  
  piVar2 = param_3;
  *(undefined1 *)(param_2 + 0x18) = 0;
  if (*(int *)(param_1 + 0x2b0) == 0) {
    return '\0';
  }
  cVar1 = '\0';
  cVar4 = FUN_00513e70();
  if (cVar4 == '\0') {
    if ((*(int *)(piVar2[0x2a] + 0x38) == 4) ||
       (cVar4 = FUN_005714e0(piVar2,param_2 + 0x10,param_2 + 0x11,1,0xffffffff), cVar4 != '\0')) {
      *(undefined1 *)(param_2 + 0x18) = 1;
      *(undefined1 *)(param_2 + 0x12) = 0;
      *(int *)(param_2 + 8) = piVar2[0x58];
      *(int *)(param_2 + 0xc) = piVar2[0x59];
      cVar1 = '\x01';
    }
  }
  else {
    param_3 = (int *)0x0;
    FUN_004294f0();
    piVar3 = param_4;
    iVar5 = FUN_004022a0(&param_3,param_4);
    while (iVar5 == 0) {
      iVar5 = *piVar3;
      if ((((iVar5 != 0) &&
           (*(int *)(*(int *)(iVar5 + 0xa8) + 0x34) == *(int *)(piVar2[0x2a] + 0x34))) &&
          ((*(uint *)(iVar5 + 0x17c) >> 0x13 & 1) == 0)) && (((uint)piVar2[0x5f] >> 0x13 & 1) == 0))
      {
        uVar6 = (**(code **)(*piVar2 + 0x25c))();
        cVar4 = FUN_0040abf0(uVar6);
        if (cVar4 != '\0') {
          *(undefined1 *)(param_2 + 0x18) = 1;
          *(undefined1 *)(param_2 + 0x12) = 1;
          *(undefined1 *)(param_2 + 0x10) = 0;
          *(undefined1 *)(param_2 + 0x11) = 0;
          iVar5 = *piVar3;
          *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar5 + 0x160);
          cVar1 = '\x01';
          *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar5 + 0x164);
          break;
        }
      }
      iVar5 = FUN_004022a0(&param_3,piVar3);
    }
    iVar5 = *(int *)(param_1 + 0x2b0);
    if (*(char *)(iVar5 + 0x54) != '\0') {
      *(undefined1 *)(iVar5 + 0x54) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x30));
    }
    if ((cVar1 == '\0') &&
       ((*(int *)(piVar2[0x2a] + 0x38) == 4 ||
        (cVar4 = FUN_005714e0(piVar2,param_2 + 0x10,param_2 + 0x11,1,0xffffffff), cVar4 != '\0'))))
    {
      *(undefined1 *)(param_2 + 0x18) = 1;
      *(undefined1 *)(param_2 + 0x12) = 0;
      *(int *)(param_2 + 8) = piVar2[0x58];
      *(int *)(param_2 + 0xc) = piVar2[0x59];
      return '\x01';
    }
  }
  return cVar1;
}
```
