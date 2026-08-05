# Raw capture: FUN_0049baa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0049baa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0049baa0` |
| **Canonical name** | `FUN_0049baa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0049baa0(float *param_1,char param_2)

{
  float fVar1;
  
  fVar1 = g_flOne;
  if (param_2 != '\0') {
    param_1[0xb] = 0.0;
    param_1[10] = 0.0;
    param_1[9] = 0.0;
    *param_1 = fVar1;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    param_1[3] = 0.0;
    param_1[4] = fVar1;
    param_1[5] = 0.0;
    param_1[6] = 0.0;
    param_1[7] = 0.0;
    param_1[8] = fVar1;
  }
  return;
}
```
