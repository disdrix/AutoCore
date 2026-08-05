# Raw capture: FUN_005fdaf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdaf0` |
| **Canonical name** | `FUN_005fdaf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fdaf0(int param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a7ceb;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (-1 < *(int *)(param_1 + 0x2c)) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x2c) * 4,0x12);
  }
  local_4 = 0xffffffff;
  if (-1 < *(int *)(param_1 + 0x20)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 0x20) * 4,0x12);
  }
  ExceptionList = pvStack_c;
  return;
}
```
