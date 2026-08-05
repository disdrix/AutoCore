# Raw capture: FUN_005d6ae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6ae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d6ae0` |
| **Canonical name** | `FUN_005d6ae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005d6ae0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_3;
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  *param_1 = param_2[8] * fVar3 + param_2[4] * fVar2 + *param_2 * fVar1;
  param_1[1] = param_2[9] * fVar3 + param_2[5] * fVar2 + param_2[1] * fVar1;
  param_1[2] = param_2[10] * fVar3 + param_2[6] * fVar2 + param_2[2] * fVar1;
  param_1[3] = 0.0;
  return;
}
```
