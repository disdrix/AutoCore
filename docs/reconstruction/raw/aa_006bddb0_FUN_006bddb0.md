# Raw capture: FUN_006bddb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bddb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bddb0` |
| **Canonical name** | `FUN_006bddb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006bddb0(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar10 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      *(undefined4 *)((uint)*(ushort *)(*(int *)(param_1 + 4) + iVar10 * 8) * 0x10 + 0xc + *param_2)
           = 0x40000000;
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(param_1 + 8));
  }
  piVar2 = DAT_00b05060;
  uVar5 = param_2[1];
  piVar1 = DAT_00b05060 + 3;
  uVar12 = uVar5 * 4 + 0xf & 0xfffffff0;
  if (*piVar1 < (int)uVar12) {
    iVar10 = (**(code **)(*DAT_00b05060 + 0x24))(uVar12);
  }
  else {
    iVar10 = DAT_00b05060[2];
    DAT_00b05060[2] = iVar10 + uVar12;
    piVar2[3] = *piVar1 - uVar12;
  }
  iVar15 = 0;
  iVar11 = 0;
  if (0 < param_2[1]) {
    iVar14 = 0;
    iVar13 = 0;
    do {
      iVar6 = *param_2;
      if (*(int *)(iVar13 + 0xc + iVar6) == 0x40000000) {
        puVar3 = (undefined4 *)(iVar13 + iVar6);
        uVar7 = puVar3[1];
        uVar8 = puVar3[2];
        uVar9 = puVar3[3];
        puVar4 = (undefined4 *)(iVar14 + iVar6);
        *puVar4 = *puVar3;
        puVar4[1] = uVar7;
        puVar4[2] = uVar8;
        puVar4[3] = uVar9;
        *(int *)(iVar10 + iVar11 * 4) = iVar15;
        iVar15 = iVar15 + 1;
        iVar14 = iVar14 + 0x10;
      }
      else {
        *(undefined4 *)(iVar10 + iVar11 * 4) = 0xffffffff;
      }
      iVar11 = iVar11 + 1;
      iVar13 = iVar13 + 0x10;
    } while (iVar11 < param_2[1]);
  }
  if ((int)(param_2[2] & 0x7fffffffU) < iVar15) {
    iVar11 = (param_2[2] & 0x7fffffffU) * 2;
    if (iVar11 <= iVar15) {
      iVar11 = iVar15;
    }
    FUN_005b3300(param_2,iVar11,0x10);
  }
  param_2[1] = iVar15;
  iVar11 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      *(undefined2 *)(*(int *)(param_1 + 4) + iVar11 * 8) =
           *(undefined2 *)(iVar10 + (uint)*(ushort *)(*(int *)(param_1 + 4) + iVar11 * 8) * 4);
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(param_1 + 8));
  }
  piVar1 = DAT_00b05060;
  if ((uVar12 == 0) || ((iVar10 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    piVar2 = DAT_00b05060 + 3;
    DAT_00b05060[2] = DAT_00b05060[2] - uVar12;
    piVar1[3] = *piVar2 + uVar12;
  }
  else {
    (**(code **)(*DAT_00b05060 + 0x28))(iVar10,uVar12);
  }
  if (-1 < (int)(uVar5 | 0x80000000)) {
    (**(code **)(*DAT_00b05060 + 0x14))(iVar10,uVar5 << 2,0x12);
  }
  iVar10 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      *(undefined4 *)((uint)*(ushort *)(*(int *)(param_1 + 4) + iVar10 * 8) * 0x10 + 0xc + *param_2)
           = 0;
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(param_1 + 8));
  }
  return;
}
```
