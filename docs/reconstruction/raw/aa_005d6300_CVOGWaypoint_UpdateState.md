# Raw capture: CVOGWaypoint_UpdateState

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6300` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d6300` |
| **Canonical name** | `CVOGWaypoint_UpdateState` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall CVOGWaypoint_UpdateState(int param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7122;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0076cf00("CVOGWaypoint::UpdateState");
  local_4 = 0;
  switch(*(undefined1 *)(param_1 + 0x50)) {
  case 0:
    FUN_005d5750();
    break;
  case 1:
    FUN_005d5960();
    break;
  case 2:
    FUN_005d5cc0();
    break;
  case 3:
    FUN_005d5680();
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_c;
  return;
}
```
