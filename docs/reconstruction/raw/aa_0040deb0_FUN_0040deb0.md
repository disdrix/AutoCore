# Raw capture: FUN_0040deb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040deb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040deb0` |
| **Canonical name** | `FUN_0040deb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0040deb0(undefined4 param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009bd009;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00411630(param_1);
  ExceptionList = local_c;
  return param_1;
}
```
