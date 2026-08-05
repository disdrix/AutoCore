# Raw capture: FUN_0099cae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099cae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0099cae0` |
| **Canonical name** | `FUN_0099cae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0099cae0(int param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009afa58;
  pvStack_c = ExceptionList;
  local_4._0_1_ = 2;
  local_4._1_3_ = 0;
  ExceptionList = &pvStack_c;
  if ((param_2 != (int *)0x0) &&
     (ExceptionList = &pvStack_c, param_2[1] = param_2[1] + 1, param_2[1] == 1)) {
    (**(code **)(*param_2 + 4))();
  }
  if ((param_2 != (int *)0x0) && (*(uint *)(param_1 + 0x10) < (uint)param_2[0x1f])) {
    *(int *)(param_1 + 0x10) = param_2[0x1f];
  }
  param_4 = param_4 & 0xffffff00;
  FUN_004278d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),param_4);
  FUN_0044edb0(param_1,param_4,1);
  local_4 = (uint)local_4._1_3_ << 8;
  if (param_2 != (int *)0x0) {
    piVar1 = param_2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*param_2 + 8))();
    }
  }
  local_4 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    piVar1 = param_2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*param_2 + 8))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}
```
