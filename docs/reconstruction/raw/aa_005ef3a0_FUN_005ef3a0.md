# Raw capture: FUN_005ef3a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ef3a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ef3a0` |
| **Canonical name** | `FUN_005ef3a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 FUN_005ef3a0(float param_1,float param_2)

{
  if (param_1 <= param_2) {
    param_1 = param_2;
  }
  return (float10)param_1;
}
```
