# Annotated low-level: FUN_006efe60

| Field | Value |
|---|---|
| Stable ID | `aa_006efe60` |
| VA | `0x006efe60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006efe60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_006efe60(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
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
  int iVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  
  *param_1 = &PTR_FUN_009e5fdc;
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = *param_2;
  piVar1 = param_1 + 4;
  *param_1 = &PTR_FUN_00a0ed58;
  iVar15 = 0;
  *piVar1 = (int)(param_1 + 8);
  param_1[5] = 0;
  param_1[6] = 0x80000004;
  if (0 < (int)param_2[2]) {
    iVar14 = (param_2[2] - 1 >> 1) + 1;
    do {
      fVar2 = *(float *)(param_2[1] + iVar15);
      iVar12 = param_2[1] + iVar15;
      fVar3 = *(float *)(iVar12 + 4);
      fVar4 = *(float *)(iVar12 + 8);
      fVar5 = *(float *)(iVar12 + 0x10);
      fVar9 = fVar5 - fVar2;
      fVar6 = *(float *)(iVar12 + 0x14);
      fVar11 = fVar6 - fVar3;
      fVar7 = *(float *)(iVar12 + 0x18);
      fVar10 = fVar7 - fVar4;
      fVar8 = *(float *)(iVar12 + 0x1c);
      if (param_1[5] == (param_1[6] & 0x7fffffff)) {
        FUN_005b3370(piVar1,0x20);
      }
      pfVar13 = (float *)(param_1[5] * 0x20 + *piVar1);
      param_1[5] = param_1[5] + 1;
      *pfVar13 = fVar2;
      pfVar13[1] = fVar3;
      pfVar13[2] = fVar4;
      pfVar13[3] = SQRT(fVar9 * fVar9 + fVar11 * fVar11 + fVar10 * fVar10);
      pfVar13[4] = fVar5;
      pfVar13[5] = fVar6;
      pfVar13[6] = fVar7;
      iVar15 = iVar15 + 0x20;
      iVar14 = iVar14 + -1;
      pfVar13[7] = fVar8;
    } while (iVar14 != 0);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
