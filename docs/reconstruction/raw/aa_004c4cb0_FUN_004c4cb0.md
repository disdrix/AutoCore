# Raw capture: FUN_004c4cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c4cb0` |
| **Canonical name** | `FUN_004c4cb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __thiscall FUN_004c4cb0(int param_1,char param_2)

{
  if (param_2 != '\0') {
    return (float10)*(float *)(param_1 + -0x31c);
  }
  return (float10)*(float *)(param_1 + -800);
}
```
