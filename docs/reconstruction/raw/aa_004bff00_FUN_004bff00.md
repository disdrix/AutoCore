# Raw capture: FUN_004bff00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bff00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bff00` |
| **Canonical name** | `FUN_004bff00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bff00(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a194d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_009cb624;
  local_4 = 0;
  FUN_004bfcb0();
  local_4 = 0xffffffff;
  _eh_vector_destructor_iterator_(param_1 + 1,0xc,9,FUN_004c0520);
  ExceptionList = local_c;
  return;
}
```
