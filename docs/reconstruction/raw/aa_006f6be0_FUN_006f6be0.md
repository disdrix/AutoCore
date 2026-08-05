# Raw capture: FUN_006f6be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f6be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f6be0` |
| **Canonical name** | `FUN_006f6be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006f6be0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar13 = g_flZero;
  fVar7 = *param_2 - *param_3;
  fVar8 = param_2[1] - param_3[1];
  fVar9 = param_2[2] - param_3[2];
  fVar1 = *param_4 - *param_3;
  fVar2 = param_4[1] - param_3[1];
  fVar3 = param_4[2] - param_3[2];
  fVar10 = fVar8 * fVar8 + fVar7 * fVar7 + fVar9 * fVar9;
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  fVar5 = fVar1 * fVar7 + fVar2 * fVar8 + fVar3 * fVar9;
  fVar6 = fVar4 * fVar10 - fVar5 * fVar5;
  if (g_flZero < fVar6) {
    fVar13 = g_flOne / fVar6;
    fVar9 = (*param_3 - *param_1) * fVar7 +
            (param_3[1] - param_1[1]) * fVar8 + fVar9 * (param_3[2] - param_1[2]);
    fVar8 = (*param_3 - *param_1) * fVar1 +
            (param_3[1] - param_1[1]) * fVar2 + (param_3[2] - param_1[2]) * fVar3;
    fVar7 = fVar5 * fVar8 - fVar9 * fVar4;
    fVar8 = fVar9 * fVar5 - fVar8 * fVar10;
    *param_5 = fVar7 * fVar13;
    param_5[1] = ((fVar6 - fVar7) - fVar8) * fVar13;
    param_5[2] = fVar8 * fVar13;
    return;
  }
  fVar5 = *param_2 - *param_4;
  fVar6 = param_2[1] - param_4[1];
  fVar11 = param_2[2] - param_4[2];
  fVar12 = fVar5 * fVar5 + fVar6 * fVar6 + fVar11 * fVar11;
  if (fVar10 < fVar4) {
    fVar7 = *param_1;
    if (fVar4 <= fVar12) {
      fVar8 = *param_4;
      fVar9 = param_1[1];
      fVar1 = param_4[1];
      fVar2 = param_1[2];
      fVar3 = param_4[2];
      param_5[1] = 0.0;
      fVar12 = ((fVar7 - fVar8) * fVar5 + (fVar9 - fVar1) * fVar6 + (fVar2 - fVar3) * fVar11) /
               fVar12;
      *param_5 = fVar12;
      param_5[2] = g_flOne - fVar12;
      return;
    }
    fVar8 = *param_3;
    fVar9 = param_1[1];
    fVar10 = param_3[1];
    fVar5 = param_1[2];
    fVar6 = param_3[2];
    *param_5 = 0.0;
    fVar4 = ((fVar7 - fVar8) * fVar1 + (fVar9 - fVar10) * fVar2 + (fVar5 - fVar6) * fVar3) / fVar4;
    param_5[2] = fVar4;
    param_5[1] = g_flOne - fVar4;
    return;
  }
  if (fVar12 < fVar10) {
    fVar1 = *param_1;
    fVar2 = *param_3;
    fVar3 = param_1[1];
    fVar4 = param_3[1];
    fVar5 = param_1[2];
    fVar6 = param_3[2];
    param_5[2] = 0.0;
    fVar10 = ((fVar1 - fVar2) * fVar7 + (fVar3 - fVar4) * fVar8 + (fVar5 - fVar6) * fVar9) / fVar10;
    *param_5 = fVar10;
    param_5[1] = g_flOne - fVar10;
    return;
  }
  param_5[1] = 0.0;
  if (fVar13 < fVar12) {
    fVar12 = ((*param_1 - *param_4) * fVar5 +
             (param_1[1] - param_4[1]) * fVar6 + (param_1[2] - param_4[2]) * fVar11) / fVar12;
    *param_5 = fVar12;
    param_5[2] = g_flOne - fVar12;
    return;
  }
  *param_5 = 0.0;
  param_5[2] = 0.0;
  return;
}
```
