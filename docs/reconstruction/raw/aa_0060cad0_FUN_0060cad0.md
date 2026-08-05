# Raw capture: FUN_0060cad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060cad0` |
| **Canonical name** | `FUN_0060cad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0060cad0(int param_1,undefined4 param_2)

{
  int local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  local_4 = *(undefined1 *)(param_1 + 0x21);
  local_8 = param_2;
  local_c = param_1;
  FUN_004e2600(FUN_0060c9b0,&local_c,0);
  return;
}
```
