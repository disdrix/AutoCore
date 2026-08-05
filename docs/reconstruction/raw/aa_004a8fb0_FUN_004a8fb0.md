# Raw capture: FUN_004a8fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a8fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004a8fb0` |
| **Canonical name** | `FUN_004a8fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __fastcall FUN_004a8fb0(int param_1)

{
  float10 fVar1;
  
  if (*(int *)(param_1 + 0x3d8) != 0) {
    fVar1 = (float10)FUN_005a58c0();
    return fVar1;
  }
  return (float10)g_flZero;
}
```
