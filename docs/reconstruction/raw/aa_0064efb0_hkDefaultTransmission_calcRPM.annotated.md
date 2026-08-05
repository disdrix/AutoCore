# Annotated low-level: hkDefaultTransmission_calcRPM

| Field | Value |
|---|---|
| Stable ID | `aa_0064efb0` |
| VA | `0x0064efb0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064efb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __fastcall hkDefaultTransmission_calcRPM(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  float local_8;
  
  iVar9 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  iVar12 = *(int *)(iVar9 + 0xc);
  iVar14 = 0;
  fVar15 = 0.0;
  local_8 = 0.0;
  if (3 < iVar12) {
    pfVar10 = (float *)(*(int *)(param_1 + 0x4c) + 8);
    pfVar11 = (float *)(*(int *)(iVar9 + 0x80) + 0x14c);
    iVar13 = (iVar12 - 4U >> 2) + 1;
    iVar14 = iVar13 * 4;
    do {
      pfVar4 = pfVar11 + -0x30;
      pfVar1 = pfVar10 + -2;
      fVar7 = *pfVar11;
      pfVar2 = pfVar10 + -1;
      pfVar5 = pfVar11 + 0x30;
      fVar8 = *pfVar10;
      pfVar6 = pfVar11 + 0x60;
      pfVar3 = pfVar10 + 1;
      pfVar10 = pfVar10 + 4;
      pfVar11 = pfVar11 + 0xc0;
      iVar13 = iVar13 + -1;
      fVar15 = *pfVar4 * DAT_009e4da8 * *pfVar1 + fVar15 + fVar7 * DAT_009e4da8 * *pfVar2 +
               *pfVar5 * DAT_009e4da8 * fVar8 + *pfVar6 * DAT_009e4da8 * *pfVar3;
      local_8 = fVar15;
    } while (iVar13 != 0);
  }
  if (iVar14 < iVar12) {
    pfVar10 = (float *)(*(int *)(param_1 + 0x4c) + iVar14 * 4);
    pfVar11 = (float *)(iVar14 * 0xc0 + 0x8c + *(int *)(iVar9 + 0x80));
    iVar12 = iVar12 - iVar14;
    do {
      fVar15 = *pfVar11;
      fVar7 = *pfVar10;
      pfVar11 = pfVar11 + 0x30;
      pfVar10 = pfVar10 + 1;
      iVar12 = iVar12 + -1;
      local_8 = fVar15 * DAT_009e4da8 * fVar7 + local_8;
    } while (iVar12 != 0);
  }
  if (*(char *)(param_1 + 0x14) == '\0') {
    return (float10)*(float *)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x10) * 4) *
           (float10)*(float *)(param_1 + 0x34) * (float10)local_8;
  }
  return (float10)(0.0 - *(float *)(param_1 + 0x3c)) * (float10)*(float *)(param_1 + 0x34) *
         (float10)local_8;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
