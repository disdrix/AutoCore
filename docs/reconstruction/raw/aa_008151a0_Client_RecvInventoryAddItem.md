# Raw capture: Client_RecvInventoryAddItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_008151a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008151a0` |
| **Canonical name** | `Client_RecvInventoryAddItem` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvInventoryAddItem(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_EBX;
  undefined4 uVar6;
  char acStack_100 [256];
  
  FUN_007a69d0();
  piVar2 = (int *)CVOGReaction_ResolveObjectTarget
                            (1,*(undefined4 *)(unaff_EBX + 8),*(undefined4 *)(unaff_EBX + 0xc));
  iVar5 = DAT_00d1b8dc;
  if (piVar2 == (int *)0x0) {
    return;
  }
  if (*(char *)(unaff_EBX + 0x18) != '\0') {
    if (DAT_00d1b8dc != 0) {
      cVar1 = FUN_00513e70();
      if ((cVar1 == '\0') || (*(int *)(unaff_EBX + 0x14) < 2)) {
        if (((uint)piVar2[0x5f] >> 0x13 & 1) == 0) {
          puVar3 = &DAT_00a1419b;
        }
        else {
          puVar3 = (undefined1 *)FUN_007a6de0("Broken: ",0xffffffff);
        }
        uVar6 = 0xffffffff;
        uVar4 = (**(code **)(*piVar2 + 0x15c))(0xffffffff);
        uVar4 = FUN_007a6de0(uVar4,uVar6);
        uVar6 = FUN_007a6de0("Received Loot",0xffffffff);
        sprintf(acStack_100,"%s: %s%s",uVar6,puVar3,uVar4);
      }
      else {
        if (((uint)piVar2[0x5f] >> 0x13 & 1) == 0) {
          puVar3 = &DAT_00a1419b;
        }
        else {
          puVar3 = (undefined1 *)FUN_007a6de0("Broken: ",0xffffffff);
        }
        uVar6 = 0xffffffff;
        uVar4 = (**(code **)(*piVar2 + 0x15c))(0xffffffff,*(undefined4 *)(unaff_EBX + 0x14));
        uVar4 = FUN_007a6de0(uVar4,uVar6);
        uVar6 = FUN_007a6de0("Received Loot",0xffffffff);
        sprintf(acStack_100,"%s: %s%s x%d",uVar6,puVar3,uVar4);
      }
      FUN_008f8200(iVar5,0x17,&DAT_00a1419b,acStack_100,0);
    }
    if (((*(int *)(param_1 + 0xf38) != 0) &&
        (cVar1 = (**(code **)(**(int **)(param_1 + 0xf38) + 0x3d8))(), cVar1 != '\0')) &&
       (*(int *)(*(int *)(param_1 + 0xf38) + 0xcb8) != 0)) {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xf38) + 0xcb8) + 0x3ac))(piVar2);
    }
    if (((*(char *)(unaff_EBX + 0x12) == '\0') || (*(int *)(param_1 + 0xe98) == 0)) ||
       ((*(int *)(*(int *)(param_1 + 0xe98) + 0x250) == 0 ||
        (iVar5 = FUN_00571010(*(undefined4 *)(unaff_EBX + 8),*(undefined4 *)(unaff_EBX + 0xc)),
        iVar5 == 0)))) {
      FUN_00945540(param_1);
    }
    else {
      FUN_00571830(*(undefined4 *)(unaff_EBX + 0x14),*(undefined4 *)(unaff_EBX + 8),
                   *(undefined4 *)(unaff_EBX + 0xc));
    }
    if ((DAT_00d1b894 != (int *)0x0) &&
       (cVar1 = (**(code **)(*DAT_00d1b894 + 0x3d8))(), cVar1 != '\0')) {
      FUN_0089c6c0(1);
    }
    FUN_0092ce90();
    return;
  }
  return;
}
```
