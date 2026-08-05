# Raw capture: FUN_004eacc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eacc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eacc0` |
| **Canonical name** | `FUN_004eacc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004eacc0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a25b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009ccbb4;
  local_4 = 0;
  if (-1 < (int)param_1[4]) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1[2],param_1[4] << 4,0x12);
  }
  *param_1 = &PTR_LAB_009ccb9c;
  ExceptionList = local_c;
  return;
}
```
