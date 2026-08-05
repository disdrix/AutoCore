# Raw capture: Client_RecvInventoryDropResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813730` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00813730` |
| **Canonical name** | `Client_RecvInventoryDropResponse` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* S2C InventoryDropResponse (0x2037; early-out on 0x203b). EBX=packet EAX=client. success@+0x22;
   inventoryType@+0x1A (1=cargo,3=locker?,5=trade,6=other); locX@+0x18 locY@+0x19; swapFlag@+0x23;
   concat/split@+0x38; swap coid@+0x28/+0x2C; qty@+0x1C. */

void Client_RecvInventoryDropResponse(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *unaff_EBX;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  int local_94;
  char local_80 [128];
  
  *(undefined1 *)(in_EAX + 0xb6) = 0;
  FUN_007a69d0();
  if (*unaff_EBX == 0x203b) {
    return;
  }
  iVar8 = 0;
  local_94 = 0;
  if (*(char *)((int)unaff_EBX + 0x22) == '\0') {
    pcVar3 = (char *)FUN_007a6de0("Inventory Drop failed... server returned false",0xffffffff);
    sprintf(local_80,pcVar3);
    FUN_007fdfb0(in_EAX,local_80,0xffffffff,1,0);
    FUN_007fc150();
    return;
  }
  if (*(int *)(in_EAX + 0xe04) == 0) {
    return;
  }
  if (*(int *)(*(int *)(in_EAX + 0xe04) + 0xe4e8) == 0) {
    return;
  }
  iVar1 = *(int *)(in_EAX + 0xe98);
  if (iVar1 == 0) {
    return;
  }
  switch(*(undefined1 *)((int)unaff_EBX + 0x1a)) {
  case 1:
    iVar8 = *(int *)(*(int *)(in_EAX + 0x1040) + 0x50c);
    if (iVar8 != 0) {
      local_94 = *(int *)(iVar8 + 0x580);
    }
    if (*(int *)(iVar1 + 0x250) == 0) goto switchD_008137e4_caseD_2;
    iVar8 = *(int *)(*(int *)(iVar1 + 0x250) + 0x2b0);
    break;
  default:
    goto switchD_008137e4_caseD_2;
  case 3:
    iVar8 = *(int *)(*(int *)(in_EAX + 0x1034) + 0x510);
    if (iVar8 != 0) {
      local_94 = *(int *)(iVar8 + 0x580);
    }
    iVar8 = *(int *)(iVar1 + 0xcbc);
    break;
  case 5:
    iVar8 = *(int *)(iVar1 + 0xce0);
    if (*(int *)(in_EAX + 0x1050) != 0) {
      local_94 = *(int *)(*(int *)(in_EAX + 0x1050) + 0x588);
    }
    Client_RefreshOpenMissionUiWindows(in_EAX);
    break;
  case 6:
    pvVar4 = Client_LookupObjectByTfid_Inferred(1,*(uint *)(iVar1 + 0xcd8),*(uint *)(iVar1 + 0xcdc))
    ;
    if (pvVar4 != (void *)0x0) {
      iVar8 = *(int *)((int)pvVar4 + 0xce0);
    }
    if (*(int *)(in_EAX + 0x1050) != 0) {
      local_94 = *(int *)(*(int *)(in_EAX + 0x1050) + 0x58c);
    }
    Client_RefreshOpenMissionUiWindows(in_EAX);
  }
  if (iVar8 == 0) {
switchD_008137e4_caseD_2:
    uVar12 = 0;
    uVar10 = 1;
    uVar9 = 0xffffffff;
    uVar5 = FUN_007a6de0("Called Drop on invalid inventory object, get a programmer",0xffffffff);
    FUN_007fdfb0(in_EAX,uVar5,uVar9,uVar10,uVar12);
    return;
  }
  if (*(char *)((int)unaff_EBX + 0x23) == '\0') {
    if (*(char *)((int)unaff_EBX + 0x1a) == '\x06') {
      piVar6 = Object_ResolveFromTFID((TFID_16 *)(unaff_EBX + 2));
    }
    else {
      if (*(int **)(in_EAX + 0x9b8) == (int *)0x0) {
        return;
      }
      iVar8 = (**(code **)(**(int **)(in_EAX + 0x9b8) + 0x3ac))();
      if (iVar8 == 0) {
        return;
      }
      piVar6 = (int *)(**(code **)(**(int **)(in_EAX + 0x9b8) + 0x3ac))();
      FUN_007fc150();
    }
    if (piVar6 == (int *)0x0) {
      return;
    }
    cVar2 = FUN_00571b60(piVar6);
    if (((cVar2 == '\0') || (cVar2 = (**(code **)(*piVar6 + 0x250))(), cVar2 != (char)unaff_EBX[6]))
       || (cVar2 = (**(code **)(*piVar6 + 0x254))(), cVar2 != *(char *)((int)unaff_EBX + 0x19))) {
      uVar5 = (**(code **)(*piVar6 + 0x25c))();
      cVar2 = FUN_00571620(piVar6,(char)unaff_EBX[6],*(undefined1 *)((int)unaff_EBX + 0x19),uVar5);
      if (cVar2 == '\0') {
        uVar13 = unaff_EBX[2];
        pcVar3 = "Dropping failed trying to add to inventory";
        goto LAB_00813b75;
      }
    }
    Client_RefreshOpenMissionUiWindows(in_EAX);
    FUN_0092ce90();
  }
  else {
    piVar6 = (int *)FUN_00571010(unaff_EBX[10],unaff_EBX[0xb]);
    if ((char)unaff_EBX[0xe] == '\0') {
      if (piVar6 == (int *)0x0) {
        uVar13 = unaff_EBX[2];
        pcVar3 = "Swapped Item didn\'t exist";
      }
      else {
        uVar5 = (**(code **)(*piVar6 + 0x25c))();
        uVar10 = 0;
        uVar9 = (**(code **)(*piVar6 + 0x25c))(0);
        FUN_00571b80(piVar6,uVar9,uVar10);
        if (*(char *)((int)unaff_EBX + 0x1a) == '\x06') {
          FUN_009440e0(piVar6,1,0,0xffffffff,0xffffffff);
        }
        piVar7 = Object_ResolveFromTFID((TFID_16 *)(unaff_EBX + 2));
        uVar9 = (**(code **)(*piVar7 + 0x25c))();
        cVar2 = FUN_00571620(piVar7,(char)unaff_EBX[6],*(undefined1 *)((int)unaff_EBX + 0x19),uVar9)
        ;
        if (cVar2 != '\0') {
          if (*(char *)((int)unaff_EBX + 0x1a) != '\x06') {
            (**(code **)(*piVar6 + 0x260))(uVar5);
            FUN_007fc270(*(undefined1 *)((int)unaff_EBX + 0x1a));
          }
          Client_RefreshOpenMissionUiWindows(in_EAX);
          FUN_0092ce90();
          return;
        }
        uVar13 = ((TFID_16 *)(unaff_EBX + 2))->dwCoidLo;
        pcVar3 = "Dropping failed trying to swap";
      }
LAB_00813b75:
      uVar5 = FUN_007a6de0(pcVar3,0xffffffff);
      sprintf(local_80,"%s: %i",uVar5,uVar13);
    }
    else {
      if (piVar6 != (int *)0x0) {
        if (*(char *)((int)unaff_EBX + 0x1a) == '\x06') {
          (**(code **)(*piVar6 + 0x260))(unaff_EBX[7]);
          *(short *)(piVar6 + 0x60) = (short)unaff_EBX[8];
          Client_RefreshOpenMissionUiWindows(in_EAX);
        }
        else {
          if ((*(int **)(in_EAX + 0x9b8) != (int *)0x0) &&
             (iVar8 = (**(code **)(**(int **)(in_EAX + 0x9b8) + 0x3ac))(), iVar8 != 0)) {
            uVar5 = (**(code **)(**(int **)(in_EAX + 0x9b8) + 0x3ac))();
            FUN_00513eb0(uVar5);
            piVar6 = (int *)(**(code **)(**(int **)(in_EAX + 0x9b8) + 0x3ac))();
            uVar5 = *(undefined4 *)(*(int *)(in_EAX + 0xe04) + 0xe4e8);
            (**(code **)(*piVar6 + 0x2a8))(uVar5);
            uVar11 = 0xffffffff;
            uVar12 = 0xffffffff;
            uVar10 = 0;
            uVar9 = (**(code **)(**(int **)(in_EAX + 0x9b8) + 0x3ac))(1,0,0xffffffff,0xffffffff);
            FUN_009440e0(uVar9,uVar10,uVar12,uVar11,uVar5);
          }
          FUN_007fc150();
          Client_RefreshOpenMissionUiWindows(in_EAX);
        }
        goto LAB_00813bbc;
      }
      iVar8 = unaff_EBX[2];
      uVar5 = FUN_007a6de0("Dropping failed trying to concatinate",0xffffffff);
      sprintf(local_80,"%s: %i",uVar5,iVar8);
    }
    FUN_007fdfb0(in_EAX,local_80,0xffffffff,1,0);
    FUN_007fc150();
  }
LAB_00813bbc:
  if (local_94 != 0) {
    FUN_0085e890();
  }
  return;
}
```
