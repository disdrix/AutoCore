# Raw capture: FUN_005fde60

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fde60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fde60` |
| **Canonical name** | `FUN_005fde60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fde60(int param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009a7dbe;
  pvStack_c = ExceptionList;
  local_4 = 2;
  ExceptionList = &pvStack_c;
  if (-1 < *(int *)(param_1 + 0x44)) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x3c),*(int *)(param_1 + 0x44) * 4,0x12);
  }
  local_4._0_1_ = 1;
  if (-1 < *(int *)(param_1 + 0x38)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x30),*(int *)(param_1 + 0x38) * 4,0x12);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  if (-1 < *(int *)(param_1 + 0x2c)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x2c) * 4,0x12);
  }
  local_4 = 0xffffffff;
  FUN_005fdda0();
  ExceptionList = pvStack_c;
  return;
}
```
