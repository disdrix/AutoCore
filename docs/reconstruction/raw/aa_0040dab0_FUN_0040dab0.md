# Raw capture: FUN_0040dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040dab0` |
| **Canonical name** | `FUN_0040dab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_0040dab0(float param_1)

{
  if (param_1 < 0.0) {
    return (int)(param_1 - g_flMissionXpRoundBias);
  }
  return (int)(param_1 + g_flMissionXpRoundBias);
}
```
