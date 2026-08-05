# Raw capture: FUN_005b3ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b3ad0` |
| **Canonical name** | `FUN_005b3ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __thiscall FUN_005b3ad0(int param_1,int param_2)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x24) - *(float *)(param_2 + 4);
  if (fVar1 <= 0.0) {
    return (float10)g_flZero;
  }
  if (DAT_00aaa7a4 < fVar1) {
    return (float10)g_flOne;
  }
  return (float10)fVar1 * (float10)DAT_00aaac18;
}
```
