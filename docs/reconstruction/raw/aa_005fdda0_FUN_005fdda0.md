# Raw capture: FUN_005fdda0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdda0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdda0` |
| **Canonical name** | `FUN_005fdda0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fdda0(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a7d93;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  if (-1 < (int)param_1[8]) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[6],param_1[8] * 4,0x12);
  }
  local_4 = local_4 & 0xffffff00;
  if (-1 < (int)param_1[5]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],param_1[5] << 4,0x12);
  }
  local_4 = 0xffffffff;
  if (-1 < (int)param_1[2]) {
    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,param_1[2] << 4,0x12);
  }
  ExceptionList = pvStack_c;
  return;
}
```
