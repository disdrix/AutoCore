# Raw capture: FUN_005fdb80

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdb80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdb80` |
| **Canonical name** | `FUN_005fdb80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005fdb80(int param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a7d16;
  pvStack_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  if (-1 < (int)*(uint *)(param_1 + 0x28)) {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x20),*(uint *)(param_1 + 0x28) & 0x7fffffff,0x12);
  }
  local_4 = local_4 & 0xffffff00;
  if (-1 < *(int *)(param_1 + 0x18)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0x18) * 4,0x12);
  }
  local_4 = 0xffffffff;
  if (-1 < *(int *)(param_1 + 0xc)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 0xc) * 4,0x12);
  }
  ExceptionList = pvStack_c;
  return;
}
```
