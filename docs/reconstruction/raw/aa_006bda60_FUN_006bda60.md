# Raw capture: FUN_006bda60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bda60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bda60` |
| **Canonical name** | `FUN_006bda60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * __thiscall FUN_006bda60(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  uVar1 = param_1[2] & 0x7fffffff;
  if ((int)uVar1 < param_2[1]) {
    if (-1 < param_1[2]) {
      (**(code **)(*DAT_00b05060 + 0x14))(*param_1,uVar1 << 3,0x12);
    }
    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[1] << 3,0x12);
    *param_1 = iVar2;
    param_1[2] = param_2[1];
  }
  puVar3 = (undefined4 *)*param_1;
  param_1[1] = param_2[1];
  iVar2 = param_2[1];
  if (0 < iVar2) {
    iVar5 = *param_2 - (int)puVar3;
    do {
      *puVar3 = *(undefined4 *)(iVar5 + (int)puVar3);
      puVar3[1] = *(undefined4 *)(iVar5 + 4 + (int)puVar3);
      puVar3 = puVar3 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  piVar4 = param_1 + 3;
  iVar2 = 0x80;
  do {
    *piVar4 = *(int *)(((int)param_2 - (int)param_1) + (int)piVar4);
    piVar4[1] = *(int *)(((int)param_2 - (int)param_1) + 4 + (int)piVar4);
    piVar4 = piVar4 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return param_1;
}
```
