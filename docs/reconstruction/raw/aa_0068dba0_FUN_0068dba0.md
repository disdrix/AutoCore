# Raw capture: FUN_0068dba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068dba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068dba0` |
| **Canonical name** | `FUN_0068dba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0068dba0(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009aa508;
  local_c = ExceptionList;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0068d2c0(param_2,local_1c);
  ExceptionList = local_c;
  return param_1;
}
```
