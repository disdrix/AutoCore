# Annotated low-level: FUN_004adc60

| Field | Value |
|---|---|
| Stable ID | `aa_004adc60` |
| VA | `0x004adc60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004adc60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x004adf30) */

void FUN_004adc60(int param_1,int param_2,int param_3)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  bool bVar14;
  char cVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  int local_30;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3 == 3))
      && (*(int *)(param_2 + 4) != 0)) && (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 3 == 3))
  {
    FUN_004b0840(0,local_10,local_c);
    bVar14 = true;
    iVar17 = 0;
    do {
      pfVar3 = *(float **)(param_2 + 4);
      pfVar2 = (float *)(iVar17 + *(int *)(param_1 + 4));
      fVar4 = pfVar3[4];
      fVar5 = pfVar3[5];
      fVar6 = pfVar3[2];
      fVar7 = pfVar3[3];
      fVar8 = *pfVar3;
      fVar9 = pfVar3[1];
      fVar10 = pfVar2[1];
      fVar11 = *pfVar2;
      fVar18 = (fVar4 - fVar6) * (fVar10 - fVar7) - (fVar5 - fVar7) * (fVar11 - fVar6);
      if ((((fVar6 - fVar8) * (fVar10 - fVar9) - (fVar11 - fVar8) * (fVar7 - fVar9)) * fVar18 <= 0.0
          ) || (((fVar8 - fVar4) * (fVar10 - fVar5) - (fVar11 - fVar4) * (fVar9 - fVar5)) * fVar18
                <= 0.0)) {
        bVar14 = false;
      }
      else {
        FUN_004b07d0(pfVar2);
      }
      iVar17 = iVar17 + 8;
    } while (iVar17 < 0x18);
    if (bVar14) {
      FUN_004b09d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),fVar4);
      return;
    }
    bVar14 = true;
    iVar17 = 0;
    do {
      pfVar3 = *(float **)(param_1 + 4);
      pfVar2 = (float *)(iVar17 + *(int *)(param_2 + 4));
      fVar4 = pfVar3[4];
      fVar5 = pfVar3[5];
      fVar6 = pfVar3[2];
      fVar7 = pfVar3[3];
      fVar8 = *pfVar3;
      fVar9 = pfVar3[1];
      fVar10 = pfVar2[1];
      fVar11 = *pfVar2;
      fVar18 = (fVar10 - fVar7) * (fVar4 - fVar6) - (fVar5 - fVar7) * (fVar11 - fVar6);
      if ((((fVar6 - fVar8) * (fVar10 - fVar9) - (fVar7 - fVar9) * (fVar11 - fVar8)) * fVar18 <= 0.0
          ) || (((fVar8 - fVar4) * (fVar10 - fVar5) - (fVar11 - fVar4) * (fVar9 - fVar5)) * fVar18
                <= 0.0)) {
        bVar14 = false;
      }
      else {
        FUN_004b07d0(pfVar2);
      }
      iVar17 = iVar17 + 8;
    } while (iVar17 < 0x18);
    if (bVar14) {
      uVar12 = *(undefined4 *)(param_2 + 4);
      uVar13 = *(undefined4 *)(param_2 + 8);
      if (*(int *)(param_3 + 4) != *(int *)(param_3 + 8)) {
        *(int *)(param_3 + 8) = *(int *)(param_3 + 4);
      }
      FUN_004b0010(*(undefined4 *)(param_3 + 4),uVar12,uVar13,fVar4);
      return;
    }
    local_30 = 0;
    do {
      iVar16 = local_30 + 1;
      iVar17 = 0;
      do {
        iVar1 = iVar17 + 1;
        cVar15 = FUN_00788280(&local_10,*(int *)(param_1 + 4) + local_30 * 8,
                              (iVar16 % 3) * 8 + *(int *)(param_1 + 4),
                              *(int *)(param_2 + 4) + iVar17 * 8,
                              *(int *)(param_2 + 4) + (iVar1 % 3) * 8);
        if (cVar15 != '\0') {
          iVar17 = *(int *)(param_3 + 4);
          if ((iVar17 == 0) ||
             ((uint)(*(int *)(param_3 + 0xc) - iVar17 >> 3) <=
              (uint)(*(int *)(param_3 + 8) - iVar17 >> 3))) {
            FUN_004afd00(*(undefined4 *)(param_3 + 8),1,&local_10);
          }
          else {
            iVar17 = *(int *)(param_3 + 8);
            FUN_00567420(iVar17,1,&local_10,param_3,iVar16);
            *(int *)(param_3 + 8) = iVar17 + 8;
          }
        }
        iVar17 = iVar1;
      } while (iVar1 < 3);
      local_30 = iVar16;
    } while (iVar16 < 3);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
