# Raw capture: FUN_0068dfd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068dfd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068dfd0` |
| **Canonical name** | `FUN_0068dfd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0068dfd0(int param_1,uint param_2,undefined4 param_3,void *param_4)

{
  uint uVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009aa528;
  local_c = ExceptionList;
  iVar2 = *(int *)(param_1 + 4);
  local_4 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 4;
  }
  if (uVar1 < param_2) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 4;
    }
    ExceptionList = &local_c;
    FUN_0068d6c0(*(undefined4 *)(param_1 + 8),param_2 - iVar2,&param_3);
  }
  else {
    ExceptionList = &local_c;
    if ((iVar2 != 0) &&
       (ExceptionList = &local_c, param_2 < (uint)(*(int *)(param_1 + 8) - iVar2 >> 4))) {
      ExceptionList = &local_c;
      FUN_0068d240(&param_2,param_2 * 0x10 + iVar2,*(int *)(param_1 + 8));
    }
  }
  if (param_4 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_4);
  }
  ExceptionList = local_c;
  return;
}
```
