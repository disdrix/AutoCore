# Raw capture: FUN_004e7fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e7fb0` |
| **Canonical name** | `FUN_004e7fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004e7fb0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a256b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009cc6ec;
  local_4 = 0;
  if (*(char *)((int)param_1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:Destructor, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  FUN_004e8020();
  FUN_0059c8a0();
  ExceptionList = local_c;
  return;
}
```
