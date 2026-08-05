# Annotated low-level: FUN_006bba50

| Field | Value |
|---|---|
| Stable ID | `aa_006bba50` |
| VA | `0x006bba50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bba50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bba50(float *param_1,float *param_2,float *param_3)

{
  undefined1 auVar1 [16];
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  
  if ((*param_1 == *param_2) && (param_1[1] == param_2[1])) {
    *param_3 = 0.0;
    param_3[1] = -1.0;
    param_3[2] = 0.0;
    param_3[3] = 0.0;
    return;
  }
  fVar2 = *param_1 - *param_2;
  fVar4 = param_1[1] - param_2[1];
  fVar7 = param_1[2] - param_2[2];
  fVar3 = fVar4 * fVar4;
  fVar6 = fVar7 * fVar7;
  auVar9._4_4_ = fVar3;
  auVar9._0_4_ = fVar3;
  auVar9._8_4_ = fVar3;
  auVar9._12_4_ = fVar3;
  auVar10._4_12_ = auVar9._4_12_;
  auVar10._0_4_ = fVar3 + fVar2 * fVar2;
  auVar11._4_4_ = fVar6;
  auVar11._0_4_ = fVar6 + auVar10._0_4_;
  auVar11._8_4_ = fVar6;
  auVar11._12_4_ = fVar6;
  auVar11 = rsqrtss(auVar10,auVar11);
  fVar3 = auVar11._0_4_;
  fVar3 = fVar3 * 0.5 * (3.0 - (fVar6 + auVar10._0_4_) * fVar3 * fVar3);
  fVar2 = fVar3 * fVar2;
  fVar4 = fVar3 * fVar4;
  fVar7 = fVar3 * fVar7;
  fVar3 = fVar3 * (param_1[3] - param_2[3]);
  fVar6 = fVar4 * 0.0 - fVar7 * 1.0;
  fVar5 = fVar7 * 0.0 - fVar2 * 0.0;
  fVar8 = fVar2 * 1.0 - fVar4 * 0.0;
  *param_3 = fVar6;
  param_3[1] = fVar5;
  param_3[2] = fVar8;
  param_3[3] = fVar3 * 0.0 - fVar3 * 0.0;
  if (fVar8 * fVar8 + fVar5 * fVar5 + fVar6 * fVar6 < _DAT_00a0d150) {
    *param_3 = fVar4 * 1.0 - fVar7 * 0.0;
    param_3[1] = fVar7 * 0.0 - fVar2 * 1.0;
    param_3[2] = fVar2 * 0.0 - fVar4 * 0.0;
    param_3[3] = fVar3 * 0.0 - fVar3 * 0.0;
  }
  fVar2 = *param_3;
  fVar4 = param_3[1];
  fVar7 = param_3[2];
  fVar3 = fVar4 * fVar4;
  fVar6 = fVar7 * fVar7;
  auVar12._4_4_ = fVar3;
  auVar12._0_4_ = fVar3;
  auVar12._8_4_ = fVar3;
  auVar12._12_4_ = fVar3;
  auVar13._4_12_ = auVar12._4_12_;
  auVar13._0_4_ = fVar3 + fVar2 * fVar2;
  auVar1._4_4_ = fVar6;
  auVar1._0_4_ = fVar6 + auVar13._0_4_;
  auVar1._8_4_ = fVar6;
  auVar1._12_4_ = fVar6;
  auVar11 = rsqrtss(auVar13,auVar1);
  fVar3 = auVar11._0_4_;
  fVar3 = fVar3 * 0.5 * (3.0 - (fVar6 + auVar13._0_4_) * fVar3 * fVar3);
  *param_3 = fVar3 * fVar2;
  param_3[1] = fVar3 * fVar4;
  param_3[2] = fVar3 * fVar7;
  param_3[3] = fVar3 * param_3[3];
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
