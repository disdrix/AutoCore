# Raw capture: FUN_007b5be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b5be0` |
| **Canonical name** | `FUN_007b5be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_007b5be0(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b325c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_00a960ac;
  local_4 = 1;
  if (param_1[0xac] != 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    if (param_1[0xa1] == 0) {
      FUN_007a4480(1,"Deleting an unknown window with an owner!");
    }
    else {
      FUN_007a4480(1,"Deleting a window with an owner! (filename: %s)",param_1[0xa1]);
    }
  }
  _DAT_00d17954 = _DAT_00d17954 + -1;
  if (((int *)param_1[0xad] != (int *)0x0) && (*(char *)((int)param_1 + 0xbd) != '\0')) {
    (**(code **)(*(int *)param_1[0xad] + 0xc))(1);
    param_1[0xad] = 0;
    *(undefined1 *)((int)param_1 + 0xbd) = 0;
  }
  FUN_007a8580();
  FUN_007aec70();
  FUN_007aff00();
  pvVar1 = (void *)param_1[0xa3];
  if (pvVar1 != (void *)0x0) {
    FUN_00797d70(pvVar1);
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[0xa3] = 0;
  if ((void *)param_1[0xae] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0xae]);
  }
  param_1[0xae] = 0;
  if ((void *)param_1[0x9d] != (void *)0x0) {
    operator_delete__((void *)param_1[0x9d]);
  }
  param_1[0x9d] = 0;
  if ((void *)param_1[0xa0] != (void *)0x0) {
    operator_delete__((void *)param_1[0xa0]);
  }
  param_1[0xa0] = 0;
  if ((void *)param_1[0x9f] != (void *)0x0) {
    operator_delete__((void *)param_1[0x9f]);
  }
  param_1[0x9f] = 0;
  if ((void *)param_1[0x9e] != (void *)0x0) {
    operator_delete__((void *)param_1[0x9e]);
  }
  param_1[0x9e] = 0;
  if ((void *)param_1[0xa1] != (void *)0x0) {
    operator_delete__((void *)param_1[0xa1]);
  }
  param_1[0xa1] = 0;
  if ((void *)param_1[0xa2] != (void *)0x0) {
    operator_delete__((void *)param_1[0xa2]);
  }
  param_1[0xa2] = 0;
  puVar3 = param_1 + 0x117;
  iVar2 = 0xb;
  do {
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete__((void *)*puVar3);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x7a] = &PTR_FUN_00a964b8;
  FUN_00424060();
  param_1[0x7a] = &PTR_FUN_00a964ac;
  FUN_00424060();
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7b));
  local_4 = 0xffffffff;
  FUN_00759de0();
  ExceptionList = pvStack_c;
  return;
}
```
