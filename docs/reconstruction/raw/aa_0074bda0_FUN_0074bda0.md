# Raw capture: FUN_0074bda0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074bda0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074bda0` |
| **Canonical name** | `FUN_0074bda0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0074bda0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ad91f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkWriter_BeginChunk(0x42424f58,2);
  local_4 = 0;
  FUN_004399a0();
  FUN_00436030();
  FUN_00436030();
  FUN_00436030();
  uVar1 = FUN_0043b500(param_2 + 0xc);
  local_4 = 0xffffffff;
  stoChunkWriter_EndChunk();
  ExceptionList = local_c;
  return uVar1;
}
```
