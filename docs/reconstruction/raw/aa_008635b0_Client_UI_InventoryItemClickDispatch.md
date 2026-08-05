# Raw capture: Client_UI_InventoryItemClickDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_008635b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008635b0` |
| **Canonical name** | `Client_UI_InventoryItemClickDispatch` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall Client_UI_InventoryItemClickDispatch(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined1 uStack_410;
  undefined1 uStack_40f;
  undefined1 uStack_40e;
  undefined1 uStack_40d;
  undefined1 auStack_40c [3];
  char cStack_409;
  char acStack_408 [2];
  undefined4 auStack_406 [256];
  
  if (DAT_00d1b6d8 != 0) {
    iVar2 = (**(code **)(*param_1 + 0x3ac))();
    if ((((iVar2 == 0) || (DAT_00d1bdfa == '\0')) || (DAT_00d1b978 == (int *)0x0)) ||
       ((cVar1 = (**(code **)(*DAT_00d1b978 + 0x3d8))(), cVar1 == '\0' ||
        (cVar1 = (**(code **)(*DAT_00d1b978 + 0xd0))(), cVar1 == '\0')))) {
      if (*(int *)(DAT_00d1b6d8 + 0xcd0) == 0) {
        Client_SendInventoryGrab_Hardpoint();
        return 1;
      }
      iVar2 = (**(code **)(*DAT_00d1b1f8 + 0x3ac))();
      if ((iVar2 != 0) && (cVar1 = FUN_00862860(), cVar1 != '\0')) {
        if (DAT_00d1b6d8 != 0) {
          if ((*(int *)(DAT_00d1b6d8 + 0x250) != 0) && (iVar7 = FUN_004fabc0(iVar2,0), iVar7 != 0))
          {
            FUN_00931db0();
            return 1;
          }
          if (((DAT_00d1b6d8 != 0) && ((*(uint *)(iVar2 + 0x17c) >> 0x14 & 1) == 0)) &&
             (cVar1 = FUN_00513fc0(*(undefined4 *)(iVar2 + 0x160),*(undefined4 *)(iVar2 + 0x164)),
             cVar1 != '\0')) {
            DAT_00d1e440 = param_1[0x37];
            DAT_00d1e438 = iVar2;
            FUN_007fdfb0(&DAT_00d1a840,
                         "Warning: This will permanently customize this item to you!  If you do this, you will no longer be able to trade it.  Are you sure?"
                         ,0x4e5b,1,0);
            return 1;
          }
        }
        Client_SendInventoryDrop_Hardpoint(param_1);
      }
    }
    else if (DAT_00d1b978[0x68ae] != 0) {
      acStack_408[0] = '[';
      acStack_408[1] = '\0';
      puVar10 = auStack_406;
      for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined2 *)puVar10 = 0;
      FUN_007a69d0();
      iVar2 = (**(code **)(*param_1 + 0x3ac))();
      if ((*(uint *)(iVar2 + 0x17c) >> 0x13 & 1) != 0) {
        pcVar3 = (char *)FUN_007a6de0("Broken: ",0xffffffff);
        pcVar4 = pcVar3;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        pcVar11 = &cStack_409;
        do {
          pcVar9 = pcVar11 + 1;
          pcVar11 = pcVar11 + 1;
        } while (*pcVar9 != '\0');
        pcVar9 = pcVar3;
        for (uVar8 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar8 = (int)pcVar4 - (int)pcVar3 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *pcVar11 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      piVar5 = (int *)(**(code **)(*param_1 + 0x3ac))();
      uVar12 = 0xffffffff;
      uVar6 = (**(code **)(*piVar5 + 0x15c))(0xffffffff);
      pcVar3 = (char *)FUN_007a6de0(uVar6,uVar12);
      pcVar4 = pcVar3;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar11 = &cStack_409;
      do {
        pcVar9 = pcVar11 + 1;
        pcVar11 = pcVar11 + 1;
      } while (*pcVar9 != '\0');
      pcVar9 = pcVar3;
      for (uVar8 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar8 = (int)pcVar4 - (int)pcVar3 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar11 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar11 = pcVar11 + 1;
      }
      pcVar4 = &cStack_409;
      do {
        pcVar3 = pcVar4 + 1;
        pcVar4 = pcVar4 + 1;
      } while (*pcVar3 != '\0');
      iVar2 = *param_1;
      *(undefined2 *)pcVar4 = DAT_00a62c94;
      piVar5 = (int *)(**(code **)(iVar2 + 0x3ac))();
      iVar2 = (**(code **)(*piVar5 + 0x210))(0);
      if (iVar2 == 0) {
        uVar6 = 0xffffffff;
        uVar12 = 0xffffffff;
      }
      else {
        piVar5 = (int *)(**(code **)(*param_1 + 0x3ac))();
        iVar7 = (**(code **)(*piVar5 + 0x210))(0);
        iVar2 = *(int *)(*(int *)(iVar7 + 4) + 4);
        uVar6 = *(undefined4 *)(iVar2 + 0x164 + iVar7);
        uVar12 = *(undefined4 *)(iVar2 + 0x168 + iVar7);
      }
      uStack_40e = 0xff;
      uStack_40f = 0;
      uStack_410 = 0xff;
      uStack_40d = 0xff;
      iVar2 = (**(code **)(*param_1 + 0x3ac))();
      FUN_00795b10(auStack_40c,1,*(undefined4 *)(iVar2 + 0x160),*(undefined4 *)(iVar2 + 0x164),uVar6
                   ,uVar12,&uStack_410,0);
      if (DAT_00d1b978[0xac] != 0) {
        iVar2 = *(int *)DAT_00d1b978[0xac];
        uVar6 = (**(code **)(*DAT_00d1b978 + 0x88))();
        (**(code **)(iVar2 + 0x3c0))(uVar6);
      }
      iVar2 = *DAT_00d1b978;
      uVar6 = (**(code **)(*(int *)DAT_00d1b978[0x68ae] + 0x88))();
      (**(code **)(iVar2 + 0x3c0))(uVar6);
      return 1;
    }
  }
  return 1;
}
```
