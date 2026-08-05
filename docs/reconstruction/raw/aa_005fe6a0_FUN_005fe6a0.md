# Raw capture: FUN_005fe6a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe6a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fe6a0` |
| **Canonical name** | `FUN_005fe6a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005fe6a0(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  void *pOwnerObject;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7dd8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CVOGHBBase_ctor(param_1);
  local_4 = 0;
  *param_1 = &PTR_FUN_009dd43c;
  param_1[4] = 1;
  param_1[3] = 1;
  uVar1 = FUN_0056a680(0);
  param_1[2] = uVar1;
  if (param_2 == (int *)0x0) {
    pOwnerObject = (void *)0x0;
  }
  else {
    pOwnerObject = (void *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2);
  }
  CVOGHBBase_AttachOwnerObject(param_1,pOwnerObject);
  param_1[7] = 9;
  if (*(int *)(*(int *)(param_2[1] + 4) + 0xb0 + (int)param_2) != 0) {
    FUN_00514ff0(0);
  }
  FUN_0056b400(1);
  (**(code **)(*param_2 + 0x2c))(1);
  ExceptionList = param_1;
  return param_1;
}
```
