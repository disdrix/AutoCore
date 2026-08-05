# Annotated low-level: Client_SendInventoryAddItem

| Field | Value |
|---|---|
| Stable ID | `aa_00530df0` |
| VA | `0x00530df0` |
| System | inventory-transfer |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00530df0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_SendInventoryAddItem - builds & sends the InventoryAddItem request (opcode 0x2047,
   0x20-byte struct) CLIENT->SERVER, e.g. when the player drags an item into a cargo slot. param_2 =
   the item object (grid X at +0x160, grid Y at +0x164). Calls Inventory_SerializeAddItemPacket to
   fill the packet. Confirms server-side InventoryAddItemPacket layout: +8=X, +0xc=Y,
   +0x12=addToExisting, +0x18=wasAdded. Logs "INVENTORY FAILURE for %I64d item:%I64d" on failure. */

void __thiscall Client_SendInventoryAddItem(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 local_150;
  int local_14c;
  undefined1 local_148 [28];
  undefined4 local_12c;
  int local_128;
  int local_124;
  
  param_2[0x5f] = param_2[0x5f] & 0xfffffffb;
  puVar3 = operator_new(0x20);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  *puVar3 = 0x2047;
  cVar2 = Inventory_SerializeAddItemPacket(puVar3,param_2,&local_14c);
  if (cVar2 == '\0') {
                    /* WARNING: Subroutine does not return */
    operator_delete(puVar3);
  }
  if (*(int *)(param_2[0x2a] + 0x38) == 4) {
    local_128 = param_2[0x58];
    local_124 = param_2[0x59];
    local_12c = 0xc;
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) != 0) {
      Client_SendLogicUiPacket(local_148);
    }
  }
  if (*(char *)((int)puVar3 + 0x12) == '\0') {
    *(undefined1 *)((int)puVar3 + 0x12) = 0;
    local_150 = *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x2b0);
    uVar4 = (**(code **)(*param_2 + 0x25c))();
    cVar2 = FUN_00571620(param_2,*(undefined1 *)(puVar3 + 4),*(undefined1 *)((int)puVar3 + 0x11),
                         uVar4);
    if (cVar2 == '\0') {
      uStack_160 = DAT_00b045a0;
      uStack_15c = DAT_00b045a4;
      uStack_158 = DAT_00b045a8;
      uStack_154 = DAT_00b045ac;
      if ((*(char *)(param_1 + 0x6b9) != '\0') &&
         ((piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa4 + param_1),
          piVar1 == (int *)0x0 || (iVar5 = (**(code **)(*piVar1 + 0x1c8))(), iVar5 == 0)))) {
        return;
      }
      puVar6 = (undefined4 *)FUN_00404c90();
      uStack_160 = *puVar6;
      uStack_15c = puVar6[1];
      uStack_158 = puVar6[2];
      uStack_154 = puVar6[3];
      FUN_004d2820(param_2,&uStack_160,0,1);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x250);
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;
      }
      (**(code **)(*param_2 + 0x158))(iVar5);
    }
    (**(code **)(*param_2 + 0xb4))();
                    /* WARNING: Subroutine does not return */
    operator_delete(puVar3);
  }
  FUN_00571830(param_3,*(undefined4 *)(local_14c + 0x160),*(undefined4 *)(local_14c + 0x164));
  FUN_004d4790(param_2);
  cVar2 = FUN_00570710();
  if (cVar2 == '\0') {
    iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
    FUN_007a4480(1,"INVENTORY FAILURE for %I64d item:%I64d",*(undefined4 *)(iVar5 + 0x164 + param_1)
                 ,*(undefined4 *)(iVar5 + 0x168 + param_1),param_2[0x58],param_2[0x59]);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(puVar3);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
