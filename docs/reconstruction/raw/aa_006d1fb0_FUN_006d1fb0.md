# Raw capture: FUN_006d1fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006d1fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006d1fb0` |
| **Canonical name** | `FUN_006d1fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006d1fb0(int param_1,undefined1 *param_2,float *param_3,float *param_4)

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
  float fVar14;
  float fVar15;
  float fVar16;
  
  fVar16 = g_flZero;
  fVar1 = *(float *)(param_1 + 0x20) - *(float *)(param_1 + 0x10);
  fVar5 = *(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x14);
  fVar3 = *(float *)(param_1 + 0x28) - *(float *)(param_1 + 0x18);
  fVar6 = *(float *)(param_1 + 0x30) - *(float *)(param_1 + 0x10);
  fVar7 = *(float *)(param_1 + 0x34) - *(float *)(param_1 + 0x14);
  fVar4 = *(float *)(param_1 + 0x38) - *(float *)(param_1 + 0x18);
  fVar2 = fVar4 * fVar5 - fVar7 * fVar3;
  fVar3 = fVar3 * fVar6 - fVar4 * fVar1;
  fVar1 = fVar7 * fVar1 - fVar5 * fVar6;
  fVar4 = fVar1 * *(float *)(param_1 + 0x18) +
          fVar3 * *(float *)(param_1 + 0x14) + fVar2 * *(float *)(param_1 + 0x10);
  fVar5 = (fVar1 * param_3[2] + fVar3 * param_3[1] + fVar2 * *param_3) - fVar4;
  fVar4 = (fVar2 * param_3[4] + fVar3 * param_3[5] + fVar1 * param_3[6]) - fVar4;
  if (((fVar4 * fVar5 < g_flZero) || ((fVar5 == g_flZero && (fVar4 != g_flZero)))) &&
     (fVar4 = fVar5 / (fVar5 - fVar4), fVar4 < param_4[5])) {
    fVar12 = (fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) * DAT_00aaa6b4;
    fVar6 = g_flOne - fVar4;
    fVar10 = fVar6 * *param_3 + fVar4 * param_3[4];
    fVar11 = fVar6 * param_3[1] + fVar4 * param_3[5];
    fVar13 = fVar6 * param_3[2] + fVar4 * param_3[6];
    fVar6 = *(float *)(param_1 + 0x10) - fVar10;
    fVar7 = *(float *)(param_1 + 0x14) - fVar11;
    fVar14 = *(float *)(param_1 + 0x18) - fVar13;
    fVar8 = *(float *)(param_1 + 0x20) - fVar10;
    fVar9 = *(float *)(param_1 + 0x24) - fVar11;
    fVar15 = *(float *)(param_1 + 0x28) - fVar13;
    if (fVar12 <= (fVar15 * fVar7 - fVar9 * fVar14) * fVar2 +
                  (fVar14 * fVar8 - fVar15 * fVar6) * fVar3 +
                  fVar1 * (fVar9 * fVar6 - fVar7 * fVar8)) {
      fVar10 = *(float *)(param_1 + 0x30) - fVar10;
      fVar11 = *(float *)(param_1 + 0x34) - fVar11;
      fVar13 = *(float *)(param_1 + 0x38) - fVar13;
      if ((fVar12 <= (fVar13 * fVar9 - fVar11 * fVar15) * fVar2 +
                     (fVar15 * fVar10 - fVar13 * fVar8) * fVar3 +
                     fVar1 * (fVar11 * fVar8 - fVar9 * fVar10)) &&
         (fVar12 <= (fVar11 * fVar14 - fVar13 * fVar7) * fVar2 +
                    (fVar13 * fVar6 - fVar14 * fVar10) * fVar3 +
                    fVar1 * (fVar7 * fVar10 - fVar11 * fVar6))) {
        param_4[5] = fVar4;
        param_4[3] = 0.0;
        if (fVar5 <= fVar16) {
          *param_4 = -fVar2;
          param_4[1] = -fVar3;
          param_4[2] = -fVar1;
        }
        else {
          *param_4 = fVar2;
          param_4[1] = fVar3;
          param_4[2] = fVar1;
        }
        fVar1 = param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4;
        fVar2 = g_flZero;
        if (fVar1 != g_flZero) {
          fVar2 = g_flOne / SQRT(fVar1);
        }
        param_4[4] = -NAN;
        *param_4 = fVar2 * *param_4;
        param_4[1] = fVar2 * param_4[1];
        param_4[2] = fVar2 * param_4[2];
        param_4[3] = fVar2 * g_flZero;
        *param_2 = 1;
        return;
      }
    }
  }
  *param_2 = 0;
  return;
}
```
