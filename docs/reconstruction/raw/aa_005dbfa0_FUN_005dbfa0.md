# Raw capture: FUN_005dbfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dbfa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dbfa0` |
| **Canonical name** | `FUN_005dbfa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_005dbfa0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a72e5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_2 != 0) {
    ExceptionList = &local_c;
    param_1[1] = &DAT_009db9ac;
    param_1[0x11] = &DAT_009db9a4;
    FUN_00518940();
    local_4 = 0;
  }
  FUN_005d4830(0);
  *param_1 = &PTR_LAB_009db924;
  param_1[0x10] = &PTR_FUN_009db8e8;
  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009db624;
  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x1bc;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  *(undefined1 *)(param_1 + 0x37) = 0;
  *(undefined1 *)((int)param_1 + 0xdd) = 1;
  *(undefined1 *)((int)param_1 + 0xde) = 0;
  *(undefined1 *)((int)param_1 + 0xdf) = 0;
  *(undefined1 *)(param_1 + 0x38) = 0;
  *(undefined1 *)((int)param_1 + 0xe1) = 1;
  *(undefined1 *)((int)param_1 + 0xe2) = 1;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x58) = 1;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5e] = 0xffffffff;
  param_1[0x5f] = 0xffffffff;
  param_1[0x60] = 0xffffffff;
  param_1[0x61] = 0xffffffff;
  param_1[99] = 0xffffffff;
  *(undefined1 *)((int)param_1 + 0x18a) = 0;
  *(undefined1 *)((int)param_1 + 0x18b) = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  *(undefined1 *)(param_1 + 0x62) = 1;
  *(undefined1 *)((int)param_1 + 0x189) = 1;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  *(undefined1 *)((int)param_1 + 0xe3) = 0;
  puVar1 = (undefined4 *)(*(int *)(param_1[1] + 4) + 0x84 + (int)param_1);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  ExceptionList = local_c;
  return param_1;
}
```
