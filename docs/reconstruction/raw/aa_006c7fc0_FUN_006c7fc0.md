# Raw capture: FUN_006c7fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7fc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c7fc0` |
| **Canonical name** | `FUN_006c7fc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006c7fc0(int param_1,undefined1 *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_28;
  float local_14;
  
  fVar4 = *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc);
  fVar6 = param_3[4] - *param_3;
  fVar2 = param_3[5] - param_3[1];
  fVar1 = param_3[6] - param_3[2];
  fVar5 = fVar2 * param_3[1] + fVar6 * *param_3 + fVar1 * param_3[2];
  if (fVar5 < g_flZero) {
    fVar6 = fVar6 * fVar6 + fVar2 * fVar2 + fVar1 * fVar1;
    if (fVar5 * fVar5 <= fVar6 * fVar4 * DAT_00aaa7ac) {
      fVar1 = *param_3;
      local_14 = 0.0;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      local_28 = fVar5;
    }
    else {
      if (fVar6 < fVar4) goto LAB_006c8013;
      local_28 = 0.0;
      local_14 = -fVar5;
      fVar5 = local_14 / fVar6;
      fVar3 = g_flOne - fVar5;
      fVar1 = fVar5 * param_3[4] + fVar3 * *param_3;
      fVar2 = fVar3 * param_3[1] + fVar5 * param_3[5];
      fVar3 = fVar3 * param_3[2] + fVar5 * param_3[6];
    }
    fVar4 = local_28 * local_28 - ((fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3) - fVar4) * fVar6;
    if (((fVar4 < g_flZero == (fVar4 == g_flZero)) &&
        (local_14 = (-local_28 - SQRT(fVar4)) + local_14, local_14 < fVar6)) &&
       (g_flZero <= local_14)) {
      local_14 = local_14 / fVar6;
      param_4[5] = local_14;
      fVar4 = g_flOne - local_14;
      *param_4 = local_14 * param_3[4] + fVar4 * *param_3;
      param_4[1] = fVar4 * param_3[1] + local_14 * param_3[5];
      param_4[2] = fVar4 * param_3[2] + local_14 * param_3[6];
      param_4[3] = local_14 * param_3[7] + fVar4 * param_3[3];
      fVar4 = g_flOne / *(float *)(param_1 + 0xc);
      param_4[4] = -NAN;
      *param_4 = fVar4 * *param_4;
      param_4[1] = fVar4 * param_4[1];
      param_4[2] = fVar4 * param_4[2];
      param_4[3] = fVar4 * param_4[3];
      *param_2 = 1;
      return;
    }
  }
LAB_006c8013:
  *param_2 = 0;
  return;
}
```
