# Raw capture: FUN_006fb6d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006fb6d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006fb6d0` |
| **Canonical name** | `FUN_006fb6d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006fb6d0(int *param_1,undefined4 param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  param_4[8] = param_3[3];
  *param_4 = -*param_3;
  param_4[1] = -param_3[1];
  param_4[2] = -param_3[2];
  param_4[3] = -param_3[3];
  if (*param_1 == 1) {
    param_4[4] = (float)param_1[8];
    param_4[5] = (float)param_1[9];
    param_4[6] = (float)param_1[10];
    param_4[7] = (float)param_1[0xb];
    param_4[9] = 1.0;
    return;
  }
  if (param_1[1] == 1) {
    fVar1 = param_3[3];
    param_4[4] = (float)param_1[0x28];
    param_4[5] = (float)param_1[0x29];
    param_4[6] = (float)param_1[0x2a];
    param_4[7] = (float)param_1[0x2b];
    param_4[4] = fVar1 * *param_4 + param_4[4];
    param_4[5] = fVar1 * param_4[1] + param_4[5];
    param_4[6] = fVar1 * param_4[2] + param_4[6];
    param_4[7] = fVar1 * param_4[3] + param_4[7];
    param_4[9] = 0.0;
    return;
  }
  param_4[4] = (float)param_1[0x4c];
  param_4[5] = (float)param_1[0x4d];
  param_4[6] = (float)param_1[0x4e];
  param_4[7] = (float)param_1[0x4f];
  param_4[9] = 0.5;
  return;
}
```
