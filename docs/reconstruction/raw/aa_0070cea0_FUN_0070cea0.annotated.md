# Annotated low-level: FUN_0070cea0

| Field | Value |
|---|---|
| Stable ID | `aa_0070cea0` |
| VA | `0x0070cea0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0070cea0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_0070cea0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7,undefined4 param_8,int param_9,int param_10,int param_11,
            int *param_12,int param_13)

{
  char cVar1;
  char cVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  char *pcVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  float10 fVar21;
  float10 fVar22;
  float10 fVar23;
  float10 fVar24;
  float10 fVar25;
  undefined4 *local_8c;
  float local_88;
  float local_84 [3];
  float *local_78;
  int local_74;
  int local_70;
  int local_6c [4];
  int local_5c [4];
  int local_4c;
  float local_48 [4];
  float local_38;
  float local_34;
  float local_28;
  
  local_70 = 1 << ((byte)param_1[1] & 0x1f);
  local_88 = 2.8026e-45;
  local_74 = local_70 * param_13 * 3 + *param_1;
  param_9 = param_9 + (-param_9 & 3U) + in_EAX * 0xc;
  local_4c = param_9 + in_EAX * -0xc;
  local_5c[3] = param_9 + (-param_9 & 3U);
  local_6c[0] = local_4c;
  local_6c[1] = local_4c + in_EAX * 4;
  local_6c[2] = local_4c + in_EAX * 8;
  local_5c[0] = local_5c[3];
  local_5c[1] = local_5c[3] + in_EAX * 4;
  local_5c[2] = local_5c[3] + in_EAX * 8;
  do {
    iVar12 = (param_7 - (int)local_88) + 1;
    iVar20 = 0;
    if (3 < in_EAX) {
      local_6c[3] = -iVar12;
      puVar7 = (undefined4 *)(local_6c[(int)local_88 + 4] + 8);
      local_78 = (float *)((local_6c[3] + 2) - param_7);
      local_8c = (undefined4 *)(param_10 + (int)local_78 * 4);
      puVar8 = (undefined4 *)(param_10 + (local_6c[3] + 2) * 4);
      iVar13 = (int)local_78;
      do {
        if (param_7 + -2 + iVar13 < 0) {
          puVar7[-2] = puVar8[-2];
        }
        else if (iVar13 + -2 < 0) {
          puVar7[-2] = local_8c[-2];
        }
        else {
          puVar7[-2] = 0;
        }
        if (param_7 + -1 + iVar13 < 0) {
          puVar7[-1] = puVar8[-1];
        }
        else if (iVar13 + -1 < 0) {
          puVar7[-1] = local_8c[-1];
        }
        else {
          puVar7[-1] = 0;
        }
        if (param_7 + iVar13 < 0) {
          *puVar7 = *puVar8;
        }
        else if (iVar13 < 0) {
          *puVar7 = *local_8c;
        }
        else {
          *puVar7 = 0;
        }
        if (local_6c[3] + 3 + iVar20 < 0) {
          puVar7[1] = puVar8[1];
        }
        else if (iVar13 + 1 < 0) {
          puVar7[1] = local_8c[1];
        }
        else {
          puVar7[1] = 0;
        }
        local_8c = local_8c + 4;
        iVar20 = iVar20 + 4;
        puVar7 = puVar7 + 4;
        puVar8 = puVar8 + 4;
        iVar13 = iVar13 + 4;
      } while (iVar20 < in_EAX + -3);
    }
    if (iVar20 < in_EAX) {
      local_8c = (undefined4 *)(iVar20 - iVar12);
      puVar8 = (undefined4 *)(local_6c[(int)local_88 + 4] + iVar20 * 4);
      local_78 = (float *)((int)local_8c - param_7);
      puVar7 = (undefined4 *)(param_10 + (int)local_8c * 4);
      puVar14 = (undefined4 *)(param_10 + (int)local_78 * 4);
      iVar20 = in_EAX - iVar20;
      do {
        if ((int)local_8c < 0) {
          *puVar8 = *puVar7;
        }
        else if ((int)local_78 < 0) {
          *puVar8 = *puVar14;
        }
        else {
          *puVar8 = 0;
        }
        local_8c = (undefined4 *)((int)local_8c + 1);
        local_78 = (float *)((int)local_78 + 1);
        puVar7 = puVar7 + 1;
        puVar14 = puVar14 + 1;
        puVar8 = puVar8 + 1;
        iVar20 = iVar20 + -1;
      } while (iVar20 != 0);
    }
    if (local_88 == 2.8026e-45) {
      FUN_0070e910(local_5c[2],param_3,param_4,param_5,local_6c[2]);
    }
    else {
      iVar12 = in_EAX + -1;
      iVar20 = 0;
      if (3 < iVar12) {
        iVar13 = local_6c[(int)local_88 + 1];
        iVar19 = local_6c[(int)local_88];
        puVar8 = (undefined4 *)(iVar13 + 4);
        puVar7 = (undefined4 *)(iVar19 + 0xc);
        iVar15 = (in_EAX - 5U >> 2) + 1;
        iVar20 = iVar15 * 4;
        do {
          *(undefined4 *)((iVar19 - iVar13) + (int)puVar8) = puVar8[-1];
          puVar7[-1] = *puVar8;
          *puVar7 = puVar8[1];
          puVar7[1] = puVar8[2];
          puVar8 = puVar8 + 4;
          puVar7 = puVar7 + 4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      if (iVar20 < iVar12) {
        puVar7 = (undefined4 *)(local_6c[(int)local_88 + 1] + iVar20 * 4);
        puVar8 = (undefined4 *)(local_6c[(int)local_88] + 4 + iVar20 * 4);
        iVar12 = iVar12 - iVar20;
        do {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      puVar8 = (undefined4 *)local_6c[(int)local_88];
      *puVar8 = 0;
      local_8c = (undefined4 *)0x0;
      if (3 < in_EAX) {
        pfVar11 = (float *)local_6c[(int)local_88 + 4];
        iVar12 = (in_EAX - 4U >> 2) + 1;
        local_8c = (undefined4 *)(iVar12 * 4);
        pfVar9 = (float *)(puVar8 + 1);
        pfVar18 = (float *)(param_11 + 0xc);
        do {
          iVar12 = iVar12 + -1;
          pfVar9[-1] = pfVar18[-3] * *pfVar11 + pfVar9[-1];
          *pfVar9 = *(float *)((param_11 - (int)puVar8) + -0x10 + (int)(pfVar9 + 4)) * *pfVar11 +
                    *pfVar9;
          pfVar9[1] = pfVar18[-1] * *pfVar11 + pfVar9[1];
          pfVar9[2] = *pfVar11 * *pfVar18 + pfVar9[2];
          pfVar9 = pfVar9 + 4;
          pfVar18 = pfVar18 + 4;
        } while (iVar12 != 0);
      }
      if ((int)local_8c < in_EAX) {
        iVar12 = local_6c[(int)local_88];
        pfVar11 = (float *)local_6c[(int)local_88 + 4];
        iVar20 = in_EAX - (int)local_8c;
        pfVar9 = (float *)(iVar12 + (int)local_8c * 4);
        do {
          iVar20 = iVar20 + -1;
          *pfVar9 = *(float *)((param_11 - iVar12) + (int)pfVar9) * *pfVar11 + *pfVar9;
          pfVar9 = pfVar9 + 1;
        } while (iVar20 != 0);
      }
    }
    local_88 = (float)((int)local_88 + -1);
  } while (-1 < (int)local_88);
  iVar12 = 0;
  do {
    fVar21 = (float10)FUN_0070c8a0();
    *(float *)((int)local_84 + iVar12) = (float)fVar21;
    iVar12 = iVar12 + 4;
  } while (iVar12 < 0xc);
  local_78 = local_48;
  local_88 = 0.0;
  local_8c = (undefined4 *)0x0;
  do {
    iVar12 = 0;
    if (-1 < (int)local_8c) {
      pfVar11 = (float *)((int)local_48 + (int)local_8c);
      pfVar9 = local_78;
      do {
        fVar21 = (float10)FUN_0070c8a0();
        *pfVar11 = (float)fVar21;
        *pfVar9 = (float)fVar21;
        iVar12 = iVar12 + 1;
        pfVar9 = pfVar9 + 1;
        pfVar11 = pfVar11 + 3;
      } while (iVar12 <= (int)local_88);
    }
    local_8c = (undefined4 *)((int)local_8c + 4);
    local_88 = (float)((int)local_88 + 1);
    local_78 = local_78 + 3;
  } while ((int)local_8c < 0xc);
  local_28 = local_28 * (float)_DAT_00aaa5e0;
  iVar12 = 0;
  iVar20 = 0;
  local_88 = 0.0;
  local_38 = local_38 * (float)_DAT_00aaa5e0;
  local_48[0] = local_48[0] * (float)_DAT_00aaa5e0;
  if (3 < local_70) {
    iVar13 = 2;
    pcVar16 = (char *)(local_74 + 5);
    do {
      fVar5 = (float)(pcVar16[-5] + 0x20);
      fVar4 = (float)(pcVar16[-4] + 0x20);
      fVar6 = (float)(pcVar16[-3] + 0x20);
      fVar6 = ((((((fVar6 * DAT_00a11088 * local_84[0] +
                   fVar4 * DAT_00a11088 * local_84[1] + fVar5 * DAT_00a11088 * local_84[2]) -
                  fVar4 * fVar5 * local_34) - fVar6 * fVar4 * local_48[1]) -
                fVar6 * fVar5 * local_48[2]) - fVar5 * fVar5 * local_28) - fVar4 * fVar4 * local_38)
              - fVar6 * fVar6 * local_48[0];
      iVar19 = iVar20;
      if ((fVar6 <= local_88) && (iVar13 != 2)) {
        iVar19 = iVar12;
        fVar6 = local_88;
      }
      local_88 = fVar6;
      fVar5 = (float)(pcVar16[-2] + 0x20);
      fVar4 = (float)(pcVar16[-1] + 0x20);
      fVar6 = (float)(*pcVar16 + 0x20);
      fVar6 = ((((((fVar6 * DAT_00a11088 * local_84[0] +
                   fVar4 * DAT_00a11088 * local_84[1] + fVar5 * DAT_00a11088 * local_84[2]) -
                  fVar4 * fVar5 * local_34) - fVar6 * fVar4 * local_48[1]) -
                fVar6 * fVar5 * local_48[2]) - fVar5 * fVar5 * local_28) - fVar4 * fVar4 * local_38)
              - fVar6 * fVar6 * local_48[0];
      if ((local_88 < fVar6) || (iVar13 == 1)) {
        iVar19 = iVar13 + -1;
        local_88 = fVar6;
      }
      fVar5 = (float)(pcVar16[1] + 0x20);
      fVar4 = (float)(pcVar16[2] + 0x20);
      fVar6 = (float)(pcVar16[3] + 0x20);
      fVar6 = ((((((fVar6 * DAT_00a11088 * local_84[0] +
                   fVar4 * DAT_00a11088 * local_84[1] + fVar5 * DAT_00a11088 * local_84[2]) -
                  fVar4 * fVar5 * local_34) - fVar6 * fVar4 * local_48[1]) -
                fVar6 * fVar5 * local_48[2]) - fVar5 * fVar5 * local_28) - fVar4 * fVar4 * local_38)
              - fVar6 * fVar6 * local_48[0];
      iVar12 = iVar13;
      if ((fVar6 <= local_88) && (iVar13 != 0)) {
        iVar12 = iVar19;
        fVar6 = local_88;
      }
      local_88 = fVar6;
      fVar5 = (float)(pcVar16[4] + 0x20);
      fVar4 = (float)(pcVar16[5] + 0x20);
      fVar6 = (float)(pcVar16[6] + 0x20);
      fVar6 = ((((((fVar6 * DAT_00a11088 * local_84[0] +
                   fVar4 * DAT_00a11088 * local_84[1] + fVar5 * DAT_00a11088 * local_84[2]) -
                  fVar4 * fVar5 * local_34) - fVar6 * fVar4 * local_48[1]) -
                fVar6 * fVar5 * local_48[2]) - fVar5 * fVar5 * local_28) - fVar4 * fVar4 * local_38)
              - fVar6 * fVar6 * local_48[0];
      if ((local_88 < fVar6) || (iVar13 == -1)) {
        iVar12 = iVar13 + 1;
        local_88 = fVar6;
      }
      iVar20 = iVar20 + 4;
      pcVar16 = pcVar16 + 0xc;
      iVar13 = iVar13 + 4;
    } while (iVar20 < local_70 + -3);
  }
  if (iVar20 < local_70) {
    pcVar16 = (char *)(iVar20 * 3 + 2 + local_74);
    iVar13 = iVar12;
    do {
      fVar5 = (float)(pcVar16[-2] + 0x20);
      fVar4 = (float)(pcVar16[-1] + 0x20);
      fVar6 = (float)(*pcVar16 + 0x20);
      fVar6 = ((((((fVar6 * DAT_00a11088 * local_84[0] +
                   fVar4 * DAT_00a11088 * local_84[1] + fVar5 * DAT_00a11088 * local_84[2]) -
                  fVar4 * fVar5 * local_34) - fVar6 * fVar4 * local_48[1]) -
                fVar6 * fVar5 * local_48[2]) - fVar5 * fVar5 * local_28) - fVar4 * fVar4 * local_38)
              - fVar6 * fVar6 * local_48[0];
      iVar12 = iVar20;
      if ((fVar6 <= local_88) && (iVar20 != 0)) {
        iVar12 = iVar13;
        fVar6 = local_88;
      }
      local_88 = fVar6;
      iVar20 = iVar20 + 1;
      pcVar16 = pcVar16 + 3;
      iVar13 = iVar12;
    } while (iVar20 < local_70);
  }
  local_74 = local_74 + iVar12 * 2;
  cVar1 = *(char *)(iVar12 + local_74);
  local_74 = iVar12 + local_74;
  cVar2 = *(char *)(local_74 + 1);
  cVar3 = *(char *)(local_74 + 2);
  iVar20 = 0;
  *param_12 = iVar12;
  fVar6 = (float)(int)cVar1 * (float)_DAT_00a0f268 + (float)_DAT_00aaa5e0;
  fVar4 = (float)(int)cVar2 * (float)_DAT_00a0f268 + (float)_DAT_00aaa5e0;
  fVar5 = (float)(int)cVar3 * (float)_DAT_00a0f268 + (float)_DAT_00aaa5e0;
  if (3 < in_EAX) {
    pfVar11 = (float *)(local_5c[1] + 4);
    pfVar9 = (float *)(local_5c[3] + 8);
    pfVar18 = (float *)(param_6 + 0xc);
    do {
      iVar12 = iVar20 * 4;
      iVar20 = iVar20 + 4;
      pfVar10 = pfVar11 + 4;
      pfVar17 = pfVar9 + 4;
      pfVar18[-3] = fVar5 * pfVar9[-2] +
                    fVar4 * pfVar11[-1] + fVar6 * *(float *)(local_5c[2] + iVar12);
      *(float *)((param_6 - local_5c[1]) + -0x10 + (int)pfVar10) =
           fVar4 * *pfVar11 +
           fVar6 * *(float *)((local_5c[2] - local_5c[1]) + -0x10 + (int)pfVar10) +
           fVar5 * *(float *)((local_5c[3] - local_5c[1]) + -0x10 + (int)pfVar10);
      *(float *)((param_6 - local_5c[3]) + -0x10 + (int)pfVar17) =
           fVar5 * *pfVar9 +
           fVar4 * pfVar11[1] +
           fVar6 * *(float *)((local_5c[2] - local_5c[3]) + -0x10 + (int)pfVar17);
      *pfVar18 = fVar5 * pfVar9[1] +
                 fVar4 * pfVar11[2] + fVar6 * *(float *)((int)pfVar18 + (local_5c[2] - param_6));
      pfVar11 = pfVar10;
      pfVar9 = pfVar17;
      pfVar18 = pfVar18 + 4;
    } while (iVar20 < in_EAX + -3);
  }
  if (iVar20 < in_EAX) {
    iVar12 = in_EAX - iVar20;
    pfVar11 = (float *)(local_5c[1] + iVar20 * 4);
    do {
      iVar12 = iVar12 + -1;
      *(float *)((int)pfVar11 + (param_6 - local_5c[1])) =
           fVar4 * *pfVar11 +
           fVar6 * *(float *)((int)pfVar11 + (local_5c[2] - local_5c[1])) +
           fVar5 * *(float *)((int)pfVar11 + (local_5c[3] - local_5c[1]));
      pfVar11 = pfVar11 + 1;
    } while (iVar12 != 0);
  }
  fVar21 = (float10)g_flZero;
  iVar12 = 0;
  if (3 < in_EAX) {
    pfVar11 = (float *)(local_4c + 4);
    pfVar9 = (float *)(local_6c[1] + 8);
    pfVar18 = (float *)(local_6c[2] + 0xc);
    do {
      iVar20 = iVar12 * 4;
      iVar12 = iVar12 + 4;
      fVar22 = (((float10)*(float *)(param_2 + iVar20) - (float10)fVar5 * (float10)pfVar11[-1]) -
               (float10)fVar4 * (float10)pfVar9[-2]) - (float10)fVar6 * (float10)pfVar18[-3];
      fVar23 = (((float10)*(float *)((int)pfVar11 + (param_2 - local_4c)) -
                (float10)fVar5 * (float10)*pfVar11) -
               (float10)fVar4 * (float10)*(float *)((int)pfVar11 + (local_6c[1] - local_4c))) -
               (float10)fVar6 * (float10)*(float *)((int)pfVar11 + (local_6c[2] - local_4c));
      fVar24 = (((float10)*(float *)((int)pfVar9 + (param_2 - local_6c[1])) -
                (float10)fVar5 * (float10)pfVar11[1]) - (float10)fVar4 * (float10)*pfVar9) -
               (float10)fVar6 * (float10)*(float *)((int)pfVar9 + (local_6c[2] - local_6c[1]));
      fVar25 = (((float10)*(float *)((int)pfVar18 + (param_2 - local_6c[2])) -
                (float10)fVar5 * (float10)pfVar11[2]) - (float10)fVar4 * (float10)pfVar9[1]) -
               (float10)fVar6 * (float10)*pfVar18;
      fVar21 = fVar25 * fVar25 + fVar24 * fVar24 + fVar23 * fVar23 + fVar22 * fVar22 + fVar21;
      pfVar11 = pfVar11 + 4;
      pfVar9 = pfVar9 + 4;
      pfVar18 = pfVar18 + 4;
    } while (iVar12 < in_EAX + -3);
  }
  if (iVar12 < in_EAX) {
    iVar20 = in_EAX - iVar12;
    pfVar11 = (float *)(local_4c + iVar12 * 4);
    do {
      iVar20 = iVar20 + -1;
      fVar22 = (((float10)*(float *)((int)pfVar11 + (param_2 - local_4c)) -
                (float10)fVar5 * (float10)*pfVar11) -
               (float10)fVar4 * (float10)*(float *)((int)pfVar11 + (local_6c[1] - local_4c))) -
               (float10)fVar6 * (float10)*(float *)((int)pfVar11 + (local_6c[2] - local_4c));
      fVar21 = fVar22 * fVar22 + fVar21;
      pfVar11 = pfVar11 + 1;
    } while (iVar20 != 0);
  }
  return fVar21;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
