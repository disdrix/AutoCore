# Raw capture: InventoryGrid_PlaceItemFootprint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571620` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00571620` |
| **Canonical name** | `InventoryGrid_PlaceItemFootprint` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_00571620(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte unaff_SI;
  undefined4 unaff_retaddr;
  uint uVar9;
  uint local_c;
  byte bStack_8;
  uint uStack_4;
  
  iVar4 = *(int *)(param_2[0x2a] + 0x38);
  if ((((iVar4 == 0x12) || (iVar4 == 0x14)) || (iVar4 == 0x16)) ||
     (((iVar4 == 0x36 || (iVar4 == 0x38)) || (iVar4 == 0x3a)))) {
    return 0;
  }
  if (iVar4 == 4) {
    FUN_00566f00(param_2);
    (**(code **)(*param_2 + 0x158))(*(undefined4 *)(param_1 + 0x24));
    return 1;
  }
  iVar4 = *(int *)(param_2[0x2a] + 0x3c);
  cVar1 = *(char *)(iVar4 + 0x406);
  local_c = (uint)*(byte *)(iVar4 + 0x407);
  if (*(int *)(param_1 + 4) == 4) {
    if (cVar1 == '\0') {
      cVar1 = '\x02';
    }
    if (local_c == 0) {
      local_c = 2;
    }
  }
  cVar3 = FUN_00570840(cVar1,local_c,param_3,param_4,0);
  if (cVar3 == '\0') {
    return 0;
  }
  uVar9 = *(uint *)(param_1 + 0x24);
  (**(code **)(*param_2 + 0x158))();
  (**(code **)(*param_2 + 0x24c))(cVar1,param_3);
  (**(code **)(*param_2 + 0x40))(1);
  if (((uint)param_2[0x5f] >> 6 & 1) != 0) {
    iVar4 = (**(code **)(*param_2 + 0x1cc))();
    if (*(int *)(iVar4 + 8) != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0xb8))(0x3f800000);
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0xfc))();
  }
  (**(code **)(*param_2 + 0x260))(unaff_retaddr);
  if (unaff_SI != 0) {
    uStack_4 = (uint)unaff_SI;
    iVar4 = 0;
    uVar8 = local_c;
    do {
      if ((char)uVar8 != '\0') {
        iVar5 = 0;
        uVar6 = uVar8 & 0xff;
        do {
          iVar2 = *(int *)(param_1 + 0x28);
          iVar7 = *(int *)(param_1 + 0xc) * (local_c + iVar4) + iVar5 + (uint)bStack_8;
          iVar5 = iVar5 + 1;
          uVar6 = uVar6 - 1;
          *(int *)(iVar2 + iVar7 * 8) = param_2[0x58];
          *(int *)(iVar2 + 4 + iVar7 * 8) = param_2[0x59];
          uVar8 = uVar9;
        } while (uVar6 != 0);
      }
      iVar4 = iVar4 + 1;
      uStack_4 = uStack_4 - 1;
    } while (uStack_4 != 0);
  }
  FUN_00566f00(param_2);
  param_2[0x5f] = param_2[0x5f] | 0x10;
  FUN_00512670();
  FUN_005706d0();
  return 1;
}
```
