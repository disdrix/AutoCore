# Raw capture: FUN_005fdf20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdf20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdf20` |
| **Canonical name** | `FUN_005fdf20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
float10 __fastcall FUN_005fdf20(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = ABS(*(float *)(param_1 + 0x1c));
  if (fVar1 < *(float *)(param_1 + 0x38)) {
    return (float10)g_flZero;
  }
  fVar2 = g_flOne;
  if (*(float *)(param_1 + 0x1c) <= g_flZero) {
    fVar2 = DAT_00aaa668;
  }
  if (fVar1 < *(float *)(param_1 + 0x28)) {
    return ((float10)fVar1 - (float10)*(float *)(param_1 + 0x38)) *
           (float10)*(float *)(param_1 + 0x2c) * (float10)fVar2;
  }
  return (((float10)fVar1 - (float10)*(float *)(param_1 + 0x28)) *
          (float10)*(float *)(param_1 + 0x30) + (float10)*(float *)(param_1 + 0x34)) *
         (float10)fVar2;
}
```
