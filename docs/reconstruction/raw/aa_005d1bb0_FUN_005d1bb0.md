# Raw capture: FUN_005d1bb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1bb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d1bb0` |
| **Canonical name** | `FUN_005d1bb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __fastcall FUN_005d1bb0(int param_1)

{
  float10 fVar1;
  float fVar2;
  
  if (g_flOne <= ABS(ABS(*(float *)(param_1 + 0xc)))) {
    fVar2 = 0.0;
    if (ABS(*(float *)(param_1 + 0xc)) <= 0.0) {
      fVar2 = DAT_009da860;
    }
    return (float10)fVar2 + (float10)fVar2;
  }
  fVar1 = (float10)_CIacos();
  return fVar1 + fVar1;
}
```
