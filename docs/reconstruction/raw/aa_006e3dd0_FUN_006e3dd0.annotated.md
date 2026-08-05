# Annotated low-level: FUN_006e3dd0

| Field | Value |
|---|---|
| Stable ID | `aa_006e3dd0` |
| VA | `0x006e3dd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006e3dd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006e3dd0(int param_1,int *param_2,int *param_3,int param_4,int *param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined8 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined2 uVar14;
  float *pfVar15;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtSphereSphere";
    uVar8 = rdtsc();
    DAT_00bc5644[1] = (int)uVar8;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  iVar3 = *param_2;
  iVar4 = param_2[2];
  iVar5 = param_3[2];
  fVar9 = *(float *)(iVar4 + 0x50) - *(float *)(iVar5 + 0x50);
  iVar6 = *param_3;
  fVar10 = *(float *)(iVar4 + 0x54) - *(float *)(iVar5 + 0x54);
  fVar11 = *(float *)(iVar4 + 0x58) - *(float *)(iVar5 + 0x58);
  fVar1 = *(float *)(iVar4 + 0x5c);
  fVar2 = *(float *)(iVar5 + 0x5c);
  fVar12 = fVar9 * fVar9 + fVar10 * fVar10 + fVar11 * fVar11;
  fVar13 = *(float *)(param_4 + 8) + *(float *)(iVar6 + 0xc) + *(float *)(iVar3 + 0xc);
  if (fVar13 * fVar13 <= fVar12) {
    if (*(short *)(param_1 + 0xc) != -1) {
      (**(code **)(**(int **)(param_1 + 8) + 8))(*(short *)(param_1 + 0xc));
      *(undefined2 *)(param_1 + 0xc) = 0xffff;
    }
  }
  else {
    piVar7 = (int *)*param_5;
    if (piVar7[1] == (piVar7[2] & 0x7fffffffU)) {
      FUN_005b3370(piVar7,0x30);
    }
    fVar13 = g_flZero;
    pfVar15 = (float *)(piVar7[1] * 0x30 + *piVar7);
    piVar7[1] = piVar7[1] + 1;
    if (fVar12 <= fVar13) {
      pfVar15[4] = DAT_00af4f90;
      pfVar15[5] = DAT_00af4f94;
      pfVar15[6] = DAT_00af4f98;
      pfVar15[7] = DAT_00af4f9c;
      fVar1 = -(*(float *)(iVar6 + 0xc) + *(float *)(iVar3 + 0xc));
    }
    else {
      fVar13 = g_flOne / SQRT(fVar12);
      pfVar15[4] = fVar9 * fVar13;
      pfVar15[5] = fVar10 * fVar13;
      pfVar15[6] = fVar11 * fVar13;
      pfVar15[7] = (fVar1 - fVar2) * fVar13;
      fVar1 = fVar13 * fVar12 - (*(float *)(iVar6 + 0xc) + *(float *)(iVar3 + 0xc));
    }
    fVar2 = *(float *)(iVar6 + 0xc);
    *pfVar15 = *(float *)(iVar5 + 0x50);
    fVar9 = fVar1 * DAT_00a0f298;
    pfVar15[1] = *(float *)(iVar5 + 0x54);
    pfVar15[2] = *(float *)(iVar5 + 0x58);
    fVar9 = fVar9 + fVar2;
    pfVar15[3] = *(float *)(iVar5 + 0x5c);
    *pfVar15 = fVar9 * pfVar15[4] + *pfVar15;
    pfVar15[1] = fVar9 * pfVar15[5] + pfVar15[1];
    pfVar15[2] = fVar9 * pfVar15[6] + pfVar15[2];
    pfVar15[3] = fVar9 * pfVar15[7] + pfVar15[3];
    pfVar15[3] = fVar1;
    if (*(short *)(param_1 + 0xc) == -1) {
      uVar14 = (**(code **)(**(int **)(param_1 + 8) + 4))(param_2,param_3,param_4,pfVar15);
      *(undefined2 *)(param_1 + 0xc) = uVar14;
    }
    if (*(short *)(param_1 + 0xc) == -1) {
      *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;
    }
    else {
      *(short *)(pfVar15 + 8) = *(short *)(param_1 + 0xc);
    }
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar8 = rdtsc();
    DAT_00bc5644[1] = (int)uVar8;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
