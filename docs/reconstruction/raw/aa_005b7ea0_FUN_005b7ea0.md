# Raw capture: FUN_005b7ea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7ea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b7ea0` |
| **Canonical name** | `FUN_005b7ea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005b7ea0(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = (int)param_3;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6aed;
  local_c = ExceptionList;
  for (piVar5 = *(int **)(param_1 + 0x14); piVar5 != *(int **)(param_1 + 0x18); piVar5 = piVar5 + 1)
  {
    if ((int *)*(int *)*piVar5 == param_3) {
      iVar1 = *(int *)(*piVar5 + 8);
      ExceptionList = &local_c;
      iVar4 = FUN_006759b0(iVar1,*(undefined4 *)(iVar1 + 4),param_2);
      FUN_005b7b30(1);
      *(int *)(iVar1 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      ExceptionList = local_c;
      return;
    }
  }
  ExceptionList = &local_c;
  piVar3 = operator_new(0x10);
  local_4 = 0;
  piVar5 = (int *)0x0;
  if (piVar3 != (int *)0x0) {
    param_3 = piVar3;
    iVar4 = FUN_004933f0();
    piVar3[3] = 0;
    piVar3[2] = iVar4;
    piVar5 = piVar3;
  }
  *piVar5 = iVar1;
  iVar1 = piVar5[2];
  local_4 = 0xffffffff;
  param_3 = piVar5;
  iVar4 = FUN_006759b0(iVar1,*(undefined4 *)(iVar1 + 4),param_2);
  FUN_005b7b30(1);
  *(int *)(iVar1 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  iVar1 = *(int *)(param_1 + 0x14);
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 0x18) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0x1c) - iVar1 >> 2))
     ) {
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    *puVar2 = piVar5;
    *(undefined4 **)(param_1 + 0x18) = puVar2 + 1;
    ExceptionList = local_c;
    return;
  }
  FUN_005b7bd0(*(undefined4 *)(param_1 + 0x18),1,&param_3);
  ExceptionList = local_c;
  return;
}
```
