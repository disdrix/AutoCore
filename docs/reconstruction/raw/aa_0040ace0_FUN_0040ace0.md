# Raw capture: FUN_0040ace0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ace0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040ace0` |
| **Canonical name** | `FUN_0040ace0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool FUN_0040ace0(int param_1)

{
  HWND pHVar1;
  
  pHVar1 = GetForegroundWindow();
  return pHVar1 == *(HWND *)(param_1 + 0x3188);
}
```
