# Annotated low-level: hkDefaultAerodynamics_update

| Field | Value |
|---|---|
| Stable ID | `aa_0064dae0` |
| VA | `0x0064dae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064dae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall hkDefaultAerodynamics_update(int param_1)

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
  int iVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  
  iVar15 = *(int *)(*(int *)(param_1 + 8) + 0x10);
  fVar1 = *(float *)(iVar15 + 0x14);
  fVar2 = *(float *)(iVar15 + 0x18);
  fVar3 = *(float *)(iVar15 + 0x10);
  iVar16 = *(int *)(*(int *)(param_1 + 8) + 0x30);
  iVar17 = *(int *)(iVar16 + 0x3c);
  fVar20 = *(float *)(iVar17 + 0xa0);
  fVar18 = *(float *)(iVar17 + 0xa0) * fVar2 + *(float *)(iVar17 + 0x90) * fVar1 +
           *(float *)(iVar17 + 0x80) * fVar3;
  fVar4 = *(float *)(iVar15 + 0x24);
  fVar5 = *(float *)(iVar15 + 0x28);
  fVar6 = *(float *)(iVar17 + 0x80);
  fVar22 = *(float *)(iVar17 + 0x84) * fVar3 + *(float *)(iVar17 + 0xa4) * fVar2 +
           *(float *)(iVar17 + 0x94) * fVar1;
  fVar7 = *(float *)(iVar15 + 0x20);
  fVar23 = *(float *)(iVar17 + 0x88) * fVar3 + *(float *)(iVar17 + 0xa8) * fVar2 +
           *(float *)(iVar17 + 0x98) * fVar1;
  fVar1 = *(float *)(iVar17 + 0x90);
  fVar2 = *(float *)(iVar17 + 0x94);
  fVar3 = *(float *)(iVar15 + 0x28);
  fVar8 = *(float *)(iVar17 + 0x84);
  fVar9 = *(float *)(iVar17 + 0xa4);
  fVar10 = *(float *)(iVar17 + 0x88);
  fVar11 = *(float *)(iVar15 + 0x24);
  fVar12 = *(float *)(iVar17 + 0x98);
  fVar13 = *(float *)(iVar15 + 0x28);
  fVar14 = *(float *)(iVar17 + 0xa8);
  fVar21 = *(float *)(iVar17 + 0x48) * fVar23 + *(float *)(iVar17 + 0x44) * fVar22 +
           *(float *)(iVar17 + 0x40) * fVar18;
  fVar19 = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x30) *
           fVar21 * fVar21 * DAT_00a0f298;
  fVar21 = ABS(fVar21) * *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x34) *
           *(float *)(param_1 + 0x30) * fVar21 * DAT_00aaa6cc;
  *(float *)(param_1 + 0x10) = fVar18 * fVar21;
  *(float *)(param_1 + 0x14) = fVar22 * fVar21;
  *(float *)(param_1 + 0x18) = fVar23 * fVar21;
  *(float *)(param_1 + 0x1c) = fVar21 * g_flZero;
  *(float *)(param_1 + 0x10) =
       (fVar1 * fVar4 + fVar20 * fVar5 + fVar6 * fVar7) * fVar19 + *(float *)(param_1 + 0x10);
  fVar20 = 0.0;
  *(float *)(param_1 + 0x14) =
       (fVar8 * fVar7 + fVar2 * fVar4 + fVar9 * fVar3) * fVar19 + *(float *)(param_1 + 0x14);
  *(float *)(param_1 + 0x18) =
       (fVar10 * fVar7 + fVar12 * fVar11 + fVar14 * fVar13) * fVar19 + *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x1c) = fVar19 * 0.0 + *(float *)(param_1 + 0x1c);
  fVar1 = *(float *)(*(int *)(iVar16 + 0x3c) + 0x2c);
  if (fVar1 != 0.0) {
    fVar20 = g_flOne / fVar1;
  }
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x40) * fVar20 + *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x44) * fVar20 + *(float *)(param_1 + 0x14);
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x48) * fVar20 + *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x4c) * fVar20 + *(float *)(param_1 + 0x1c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
