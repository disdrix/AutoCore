# Raw capture: FUN_0062fad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062fad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0062fad0` |
| **Canonical name** | `FUN_0062fad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0062fad0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint local_40;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int local_14;
  uint uStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar7 = *(int *)(param_1 + 0x44);
  FUN_0062d8e0(iVar7);
  FUN_0062d960(iVar7);
  FUN_005d4370(iVar7);
  iVar1 = 0;
  if (0 < iVar7) {
    iVar6 = 0;
    do {
      puVar8 = (undefined4 *)(*(int *)(param_1 + 0x40) + iVar6);
      puVar9 = (undefined4 *)(iVar6 + local_14);
      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      *(undefined4 *)(local_28 + iVar1 * 8) =
           *(undefined4 *)
            (*(int *)(param_1 + 0x4c) + *(int *)(iVar6 + 0x10 + *(int *)(param_1 + 0x40)) * 8);
      *(int *)(local_28 + 4 + iVar1 * 8) = iVar1;
      iVar1 = iVar1 + 1;
      iVar6 = iVar6 + 0x1c;
    } while (iVar1 < iVar7);
  }
  local_40 = local_40 & 0xffffff00;
  if (1 < iVar7 + -1) {
    FUN_0062c000(local_28 + 8,0,iVar7 + -2,local_40);
  }
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x44)) {
    iVar1 = 0;
    piVar2 = (int *)(local_28 + 4);
    do {
      *(int *)(local_3c + *piVar2 * 4) = iVar7;
      iVar7 = iVar7 + 1;
      puVar8 = (undefined4 *)(local_14 + *piVar2 * 0x1c);
      puVar9 = (undefined4 *)(*(int *)(param_1 + 0x40) + iVar1);
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      piVar2 = piVar2 + 2;
      iVar1 = iVar1 + 0x1c;
    } while (iVar7 < *(int *)(param_1 + 0x44));
  }
  iVar7 = 1;
  if (1 < *(int *)(param_1 + 0x44)) {
    iVar1 = 0x1c;
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0x40) + 0x18 + iVar1);
      if (((uint)piVar2 & 1) == 0) {
        *piVar2 = iVar7;
      }
      else {
        *(int *)(((uint)piVar2 & 0xfffffffe) + *(int *)(param_1 + 0x78)) = iVar7;
      }
      iVar7 = iVar7 + 1;
      iVar1 = iVar1 + 0x1c;
    } while (iVar7 < *(int *)(param_1 + 0x44));
  }
  iVar7 = 0;
  local_40 = 0;
  if (0 < *(int *)(param_1 + 0x70)) {
    do {
      iVar1 = *(int *)(param_1 + 0x78);
      iVar6 = *(int *)(iVar1 + 0xc + iVar7);
      while (iVar6 = iVar6 + -1, -1 < iVar6) {
        iVar5 = *(int *)(iVar1 + iVar7 + 8);
        *(undefined4 *)(iVar5 + iVar6 * 4) =
             *(undefined4 *)(local_3c + *(int *)(iVar5 + iVar6 * 4) * 4);
      }
      local_40 = local_40 + 1;
      iVar7 = iVar7 + 0x14;
    } while ((int)local_40 < *(int *)(param_1 + 0x70));
  }
  piVar2 = (int *)(param_1 + 0x50);
  iVar7 = 3;
  do {
    iVar1 = 0;
    if (0 < *piVar2) {
      piVar3 = (int *)(piVar2[-1] + 4);
      do {
        *piVar3 = *(int *)(local_3c + *piVar3 * 4);
        iVar1 = iVar1 + 1;
        piVar3 = piVar3 + 2;
      } while (iVar1 < *piVar2);
    }
    piVar3 = DAT_00b05060;
    piVar2 = piVar2 + 3;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar4 = local_2c * 4 + 0xfU & 0xfffffff0;
  if ((uVar4 == 0) || ((local_30 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - uVar4;
    piVar3[3] = piVar3[3] + uVar4;
  }
  else {
    (**(code **)(*DAT_00b05060 + 0x28))(local_30,uVar4);
  }
  if (-1 < local_34) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_3c,local_34 * 4,0x12);
  }
  piVar2 = DAT_00b05060;
  uVar4 = iStack_18 * 8 + 0xfU & 0xfffffff0;
  if ((uVar4 == 0) || ((iStack_1c != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - uVar4;
    piVar2[3] = piVar2[3] + uVar4;
  }
  else {
    (**(code **)(*DAT_00b05060 + 0x28))(iStack_1c,uVar4);
  }
  if (-1 < iStack_20) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_28,iStack_20 * 8,0x12);
  }
  piVar2 = DAT_00b05060;
  uVar4 = iStack_4 * 0x1c + 0xfU & 0xfffffff0;
  if ((uVar4 == 0) || ((iStack_8 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - uVar4;
    piVar2[3] = piVar2[3] + uVar4;
  }
  else {
    (**(code **)(*DAT_00b05060 + 0x28))(iStack_8,uVar4);
  }
  if (-1 < (int)uStack_c) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_14,(uStack_c & 0x7fffffff) * 0x1c,0x12);
  }
  return;
}
```
