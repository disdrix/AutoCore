# Raw capture: FUN_0073acb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073acb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0073acb0` |
| **Canonical name** | `FUN_0073acb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __fastcall FUN_0073acb0(int param_1)

{
  FUN_00464900();
  return (float10)*(float *)(param_1 + 0x21c);
}
```
