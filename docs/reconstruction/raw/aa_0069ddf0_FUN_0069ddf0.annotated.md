# Annotated low-level: FUN_0069ddf0

| Field | Value |
|---|---|
| Stable ID | `aa_0069ddf0` |
| VA | `0x0069ddf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0069ddf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0069ddf0(int param_1,float *param_2,float *param_3,float *param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  int iVar10;
  float *pfVar11;
  float *pfVar12;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  int local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  local_5c = param_1;
  iVar10 = 0;
  pfVar11 = (float *)&DAT_00af55e4;
  fVar4 = g_flZero;
  fVar6 = g_flZero;
  fVar7 = g_flZero;
  do {
    if ((&DAT_00d08f10)[iVar10] != '\0') {
      local_74 = *param_3;
      local_70 = param_3[1];
      local_6c = param_3[2];
      local_68 = *param_2;
      local_64 = param_2[1];
      local_60 = param_2[2];
      local_84 = pfVar11[-1];
      local_80 = *pfVar11;
      local_7c = pfVar11[1];
      if (param_5 == 1) {
        pfVar12 = (float *)(param_1 + 0x3c);
      }
      else if (param_5 == 2) {
        pfVar12 = (float *)(param_1 + 0x7c);
      }
      else {
        pfVar12 = (float *)(param_1 + 4);
      }
      local_48 = pfVar12[9];
      local_44 = pfVar12[10];
      local_58 = pfVar11[5] * pfVar12[3];
      local_40 = pfVar12[0xb];
      local_54 = pfVar11[6] * pfVar12[4];
      local_50 = pfVar11[7] * pfVar12[5];
      fVar5 = g_flOne;
      if (pfVar11[0xb] != g_flZero) {
        local_4c = (local_7c - local_6c) * (local_7c - local_6c) +
                   (local_80 - local_70) * (local_80 - local_70) +
                   (local_84 - local_74) * (local_84 - local_74);
        local_78 = (float)(((int)local_4c >> 1) + 0x1fc00000);
        fVar5 = g_flOne / ((local_78 * pfVar11[0xe] + pfVar11[0xd]) * local_78 + pfVar11[0xc]);
      }
      if (pfVar11[0xb] == g_flZero) {
        pfVar9 = &local_84;
      }
      else {
        pfVar9 = &local_3c;
        local_3c = local_84 - local_74;
        local_38 = local_80 - local_70;
        local_34 = local_7c - local_6c;
      }
      fVar1 = *pfVar9;
      fVar2 = pfVar9[1];
      fVar3 = pfVar9[2];
      fVar8 = g_flOne / SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
      fVar1 = fVar1 * fVar8 * *param_2 + fVar2 * fVar8 * param_2[1] + fVar8 * fVar3 * param_2[2];
      if (fVar1 < g_flZero) {
        fVar1 = g_flZero;
      }
      fVar7 = (pfVar11[2] * *pfVar12 * fVar1 + pfVar11[5] * pfVar12[3]) * fVar5 + pfVar12[9] + fVar7
      ;
      fVar6 = (pfVar11[3] * pfVar12[1] * fVar1 + pfVar11[6] * pfVar12[4]) * fVar5 + pfVar12[10] +
              fVar6;
      fVar4 = fVar5 * (pfVar11[4] * pfVar12[2] * fVar1 + pfVar11[7] * pfVar12[5]) + pfVar12[0xb] +
              fVar4;
    }
    pfVar11 = pfVar11 + 0x10;
    iVar10 = iVar10 + 1;
  } while ((int)pfVar11 < 0xaf57e4);
  *param_4 = fVar7;
  param_4[1] = fVar6;
  param_4[2] = fVar4;
  param_4[3] = 1.0;
  if (g_flZero <= fVar7) {
    if (fVar7 <= g_flOne) {
      *param_4 = fVar7;
    }
    else {
      *param_4 = 1.0;
    }
  }
  else {
    *param_4 = 0.0;
  }
  if (g_flZero <= fVar6) {
    if (fVar6 <= g_flOne) {
      param_4[1] = fVar6;
    }
    else {
      param_4[1] = 1.0;
    }
  }
  else {
    param_4[1] = 0.0;
  }
  if (fVar4 < g_flZero) {
    param_4[2] = 0.0;
    return;
  }
  if (g_flOne < fVar4) {
    param_4[2] = 1.0;
    return;
  }
  param_4[2] = fVar4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
