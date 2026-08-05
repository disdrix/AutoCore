# Raw capture: FUN_005dfe20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dfe20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dfe20` |
| **Canonical name** | `FUN_005dfe20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_005dfe20(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a73d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00518940();
  *param_1 = &PTR_FUN_009dbbfc;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  *(undefined1 *)(param_1 + 0x68) = 0;
  ExceptionList = local_c;
  return param_1;
}
```
