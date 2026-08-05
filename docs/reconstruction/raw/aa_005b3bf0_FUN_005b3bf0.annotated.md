# Annotated low-level: FUN_005b3bf0

| Field | Value |
|---|---|
| Stable ID | `aa_005b3bf0` |
| VA | `0x005b3bf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005b3bf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_005b3bf0(int param_1,code *param_2)

{
  float *pfVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  float *pfVar6;
  int *piVar7;
  int *piVar8;
  float10 fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  int local_38;
  float fStack_24;
  
  piVar7 = (int *)**(int **)(param_1 + 0x14);
  local_38 = 0;
  if (piVar7 == *(int **)(param_1 + 0x14)) {
    return 0;
  }
LAB_005b3c10:
  iVar5 = FUN_004baf50(piVar7 + 8);
  if (iVar5 != 0) {
    if (*(int **)(iVar5 + 8) == (int *)0x0) {
LAB_005b3ead:
      cVar4 = (*param_2)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);
      if (cVar4 != '\0') {
        local_38 = local_38 + 1;
        goto LAB_005b3ec9;
      }
    }
    else {
      pfVar6 = (float *)(**(code **)(**(int **)(iVar5 + 8) + 0x48))();
      iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);
      pfVar1 = (float *)(iVar2 + 0x84 + iVar5);
      fVar9 = (float10)FUN_004cd220(*pfVar1 + *pfVar6,pfVar6[2] + *(float *)(iVar2 + 0x8c + iVar5));
      if ((float10)*(float *)(param_1 + 0x24) <= fVar9) {
        fVar10 = (float)DAT_00af247c;
        if (DAT_00af247c < 0) {
          fVar10 = fVar10 + _DAT_00aaa5dc;
        }
        fVar15 = pfVar6[5] + *pfVar1;
        fVar16 = pfVar6[7] + pfVar1[2];
        bVar3 = true;
        fVar13 = ((pfVar6[8] + *pfVar1) - fVar15) * (g_flOne / fVar10);
        fVar14 = ((pfVar6[10] + pfVar1[2]) - fVar16) * (g_flOne / fVar10);
        fVar10 = pfVar6[8] + *pfVar1 + g_flHardKillInterpolate;
        fVar11 = pfVar6[10] + pfVar1[2] + g_flHardKillInterpolate;
        fStack_24 = fVar16;
        do {
          fVar12 = fVar15;
          if (fVar11 < fStack_24) {
            if (bVar3) {
              fVar12 = fVar13 * DAT_00a0f298;
              fStack_24 = fVar14 * DAT_00a0f298 + fVar16;
              bVar3 = true;
              goto LAB_005b3e20;
            }
            break;
          }
          for (; fVar12 <= fVar10; fVar12 = fVar13 + fVar12) {
            fVar9 = (float10)FUN_004cd220(fVar12,fStack_24);
            if (fVar9 < (float10)*(float *)(param_1 + 0x24)) {
              bVar3 = false;
              break;
            }
          }
          fStack_24 = fStack_24 + fVar14;
        } while (bVar3);
      }
    }
    goto LAB_005b3dad;
  }
LAB_005b3ec9:
  piVar8 = (int *)*piVar7;
  if (piVar7 != *(int **)(param_1 + 0x14)) {
    *(int **)piVar7[1] = piVar8;
    *(int *)(*piVar7 + 4) = piVar7[1];
                    /* WARNING: Subroutine does not return */
    operator_delete(piVar7);
  }
  goto LAB_005b3daf;
LAB_005b3e20:
  do {
    if (fVar11 < fStack_24) {
      if (bVar3) goto LAB_005b3ead;
      break;
    }
    for (fVar16 = fVar12 + fVar15; fVar16 <= fVar10; fVar16 = fVar13 + fVar16) {
      fVar9 = (float10)FUN_004cd220(fVar16,fStack_24);
      if (fVar9 < (float10)*(float *)(param_1 + 0x24)) {
        bVar3 = false;
        break;
      }
    }
    fStack_24 = fStack_24 + fVar14;
  } while (bVar3);
LAB_005b3dad:
  piVar8 = (int *)*piVar7;
LAB_005b3daf:
  piVar7 = piVar8;
  if (piVar8 == *(int **)(param_1 + 0x14)) {
    return local_38;
  }
  goto LAB_005b3c10;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
