# Raw capture: FUN_007b7ea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b7ea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b7ea0` |
| **Canonical name** | `FUN_007b7ea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007b7ea0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009aba9f;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  iVar3 = param_1;
  if (DAT_00d1793c != '\0') {
    if (DAT_00d1e56c == (int *)0x0) {
      ExceptionList = &pvStack_c;
      _com_issue_error(-0x7fffbffd);
    }
    else {
      ExceptionList = &pvStack_c;
      (**(code **)(*DAT_00d1e56c + 8))(DAT_00d1e56c);
      DAT_00d1e56c = (int *)0x0;
    }
  }
  piVar1 = (int *)(param_1 + 0x28);
  local_4._0_1_ = 2;
  piVar2 = (int *)*piVar1;
  piVar4 = piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  piVar1 = (int *)*piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  local_4 = 0xffffffff;
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,iVar3,piVar4);
  }
  ExceptionList = pvStack_c;
  return;
}
```
