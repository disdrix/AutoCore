# Raw capture: FUN_005fe7a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe7a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fe7a0` |
| **Canonical name** | `FUN_005fe7a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005fe7a0(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7e0f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_2 != 0) {
    ExceptionList = &local_c;
    param_1[1] = &DAT_009dd760;
    FUN_00518940();
    local_4 = 0;
  }
  FUN_005c7f30(0);
  *param_1 = &PTR_FUN_009dd724;
  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009dd45c;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xdc;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  *(undefined2 *)(param_1 + 0x33) = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  puVar1 = (uint *)(*(int *)(param_1[1] + 4) + 0x180 + (int)param_1);
  *puVar1 = *puVar1 | 0x10;
  ExceptionList = local_c;
  return param_1;
}
```
