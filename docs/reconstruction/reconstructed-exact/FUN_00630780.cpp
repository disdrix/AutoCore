// =============================================================================
// FUN_00630780
// -----------------------------------------------------------------------------
// Stable ID: aa_00630780
// Address:   0x00630780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00630780 @ 0x00630780
// Stable ID: aa_00630780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~447 non-empty decompiler lines.
//  - Control keywords: if×61, goto×13, while×11, do×6, for×2, return×1.
//  - Notable callees: ROUND×8, ABS×2, FUN_0062d9d0, FUN_00630780.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00630780(int param_1,float *param_2,int *param_3)



{

  float *pfVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  uint *puVar10;

  byte *pbVar11;

  byte *pbVar12;

  uint uVar13;

  byte bVar14;

  float *pfVar15;

  float10 fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  uint *local_100;

  float local_f8;

  float local_f0 [3];

  int local_e4;

  float local_e0 [5];

  int local_cc;

  int *apiStack_c8 [6];

  float afStack_b0 [4];

  float local_a0 [4];

  uint local_90 [4];

  float afStack_80 [4];

  float afStack_70 [5];

  int aiStack_5c [3];

  float local_50 [5];

  byte abStack_3c [12];

  byte abStack_30 [12];

  int *local_24;

  uint uStack_1c;

  int iStack_18;

  int iStack_14;

  

  local_e0[1] = param_2[9] + param_2[1];

  local_a0[2] = param_2[2] - param_2[10];

  local_a0[3] = param_2[3] - param_2[0xb];

  local_a0[0] = *param_2 - param_2[8];

  local_a0[1] = param_2[1] - param_2[9];

  local_e0[0] = param_2[8] + *param_2;

  local_e0[2] = param_2[10] + param_2[2];

  local_e0[3] = param_2[0xb] + param_2[3];

  fVar18 = *(float *)(param_1 + 0x30) * (local_a0[0] + *(float *)(param_1 + 0x10));

  fVar19 = *(float *)(param_1 + 0x38) * (*(float *)(param_1 + 0x18) + local_a0[2]);

  fVar20 = *(float *)(param_1 + 0x34) * (*(float *)(param_1 + 0x14) + local_a0[1]);

  fVar17 = *(float *)(param_1 + 0x3c) * (*(float *)(param_1 + 0x1c) + local_a0[3]);

  if (DAT_009e33e4 <= fVar18) {

    fVar18 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar20) {

    fVar20 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar19) {

    fVar19 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar17) {

    fVar17 = DAT_009e33e4;

  }

  if (fVar18 <= 0.0) {

    fVar18 = 0.0;

  }

  if (fVar20 <= 0.0) {

    fVar20 = 0.0;

  }

  if (fVar19 <= 0.0) {

    fVar19 = 0.0;

  }

  if (fVar17 <= 0.0) {

    fVar17 = 0.0;

  }

  local_90[0] = (uint)ROUND(fVar18);

  local_90[1] = (uint)ROUND(fVar20);

  local_90[2] = (uint)ROUND(fVar19);

  local_90[3] = (uint)ROUND(fVar17);

  fVar19 = *(float *)(param_1 + 0x30) * (*(float *)(param_1 + 0x10) + local_e0[0]);

  fVar20 = *(float *)(param_1 + 0x34) * (*(float *)(param_1 + 0x14) + local_e0[1]);

  fVar18 = *(float *)(param_1 + 0x38) * (*(float *)(param_1 + 0x18) + local_e0[2]);

  fVar17 = *(float *)(param_1 + 0x3c) * (*(float *)(param_1 + 0x1c) + local_e0[3]);

  if (DAT_009e33e4 <= fVar19) {

    fVar19 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar20) {

    fVar20 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar18) {

    fVar18 = DAT_009e33e4;

  }

  if (DAT_009e33e4 <= fVar17) {

    fVar17 = DAT_009e33e4;

  }

  if (fVar19 <= 0.0) {

    fVar19 = 0.0;

  }

  if (fVar20 <= 0.0) {

    fVar20 = 0.0;

  }

  if (fVar18 <= 0.0) {

    fVar18 = 0.0;

  }

  if (fVar17 <= 0.0) {

    fVar17 = 0.0;

  }

  local_f0[0] = (float)(int)ROUND(fVar19);

  local_f0[1] = (float)(int)ROUND(fVar20);

  local_f0[2] = (float)(int)ROUND(fVar18);

  local_e4 = (int)ROUND(fVar17);

  local_cc = param_1;

  FUN_0062d9d0(*(int *)(param_1 + 0x44) + 0x10);

  iVar8 = *(int *)(param_1 + 0x44) >> 4;

  if (-1 < iVar8) {

    iVar8 = iVar8 + 1;

    piVar9 = local_24;

    do {

      iVar8 = iVar8 + -1;

      *piVar9 = 0;

      piVar9[1] = 0;

      piVar9[2] = 0;

      piVar9[3] = 0;

      piVar9 = piVar9 + 4;

    } while (iVar8 != 0);

  }

  piVar9 = (int *)param_2[0xc];

  if (piVar9 == (int *)0x0) {

    piVar9 = (int *)(param_1 + 0x4c);

  }

  bVar14 = 1;

  local_f8 = 0.0;

  do {

    iVar8 = piVar9[1];

    uVar13 = *(uint *)((int)local_90 + (int)local_f8);

    iVar3 = *piVar9;

    if (uVar13 < *(uint *)(iVar3 + (iVar8 >> 1) * 8)) {

      for (puVar10 = (uint *)(iVar3 + 8);

          (puVar10 < (uint *)(iVar3 + -0x20 + iVar8 * 8) && (puVar10[6] <= uVar13));

          puVar10 = puVar10 + 8) {

        *(byte *)(puVar10[1] + (int)local_24) = *(byte *)(puVar10[1] + (int)local_24) ^ bVar14;

        *(byte *)(puVar10[3] + (int)local_24) = *(byte *)(puVar10[3] + (int)local_24) ^ bVar14;

        *(byte *)(puVar10[5] + (int)local_24) = *(byte *)(puVar10[5] + (int)local_24) ^ bVar14;

        *(byte *)(puVar10[7] + (int)local_24) = *(byte *)(puVar10[7] + (int)local_24) ^ bVar14;

      }

      uVar4 = *puVar10;

      while (uVar4 <= uVar13) {

        *(byte *)(puVar10[1] + (int)local_24) = *(byte *)(puVar10[1] + (int)local_24) ^ bVar14;

        puVar10 = puVar10 + 2;

        uVar4 = *puVar10;

      }

      uVar13 = *(uint *)((int)local_f0 + (int)local_f8);

      uVar4 = *puVar10;

      *(uint **)((int)apiStack_c8 + (int)local_f8) = puVar10;

      while (uVar4 <= uVar13) {

        *(byte *)(puVar10[1] + (int)local_24) =

             *(byte *)(puVar10[1] + (int)local_24) ^ ((byte)*puVar10 & 1) - 1 & bVar14;

        puVar10 = puVar10 + 2;

        uVar4 = *puVar10;

      }

      *(uint **)((int)apiStack_c8 + (int)local_f8 + 0xc) = puVar10;

    }

    else {

      for (puVar10 = (uint *)(iVar3 + -0x10 + iVar8 * 8);

          ((uint *)(iVar3 + 0x20U) <= puVar10 &&

          (*(uint *)((int)local_f0 + (int)local_f8) < puVar10[-6])); puVar10 = puVar10 + -8) {

        *(byte *)(puVar10[1] + (int)local_24) = *(byte *)(puVar10[1] + (int)local_24) ^ bVar14;

        *(byte *)(puVar10[-1] + (int)local_24) = *(byte *)(puVar10[-1] + (int)local_24) ^ bVar14;

        *(byte *)(puVar10[-3] + (int)local_24) = *(byte *)(puVar10[-3] + (int)local_24) ^ bVar14;

        *(byte *)(puVar10[-5] + (int)local_24) = *(byte *)(puVar10[-5] + (int)local_24) ^ bVar14;

      }

      uVar4 = *(uint *)((int)local_f0 + (int)local_f8);

      uVar5 = *puVar10;

      while (uVar4 < uVar5) {

        *(byte *)(puVar10[1] + (int)local_24) = *(byte *)(puVar10[1] + (int)local_24) ^ bVar14;

        puVar10 = puVar10 + -2;

        uVar5 = *puVar10;

      }

      *(uint **)((int)apiStack_c8 + (int)local_f8 + 0xc) = puVar10 + 2;

      uVar4 = *puVar10;

      while (uVar13 < uVar4) {

        *(byte *)(puVar10[1] + (int)local_24) =

             *(byte *)(puVar10[1] + (int)local_24) ^ -((byte)*puVar10 & 1) & bVar14;

        puVar10 = puVar10 + -2;

        uVar4 = *puVar10;

      }

      *(uint **)((int)apiStack_c8 + (int)local_f8) = puVar10 + 2;

    }

    local_f8 = (float)((int)local_f8 + 4);

    piVar9 = piVar9 + 3;

    bVar14 = bVar14 * '\x02';

  } while ((int)local_f8 < 0xc);

  iVar8 = *(int *)(local_cc + 0x44);

  local_f8 = g_flOne;

  if (local_24 < local_24 + (iVar8 >> 2) + 1) {

    local_100 = (uint *)(*(int *)(local_cc + 0x40) + 0x34);

    piVar9 = local_24;

    do {

      if ((*piVar9 + 0x1010101U & 0x8080808) != 0) {

        if (((char)*piVar9 == '\a') && ((local_100[-7] & 1) == 0)) {

          fVar16 = (float10)(**(code **)(*param_3 + 4))(local_100[-7],0);

          if ((float)fVar16 <= local_f8) {

            local_f8 = (float)fVar16;

          }

        }

        if ((*(char *)((int)piVar9 + 1) == '\a') && ((*local_100 & 1) == 0)) {

          fVar16 = (float10)(**(code **)(*param_3 + 4))(*local_100,0);

          if ((float)fVar16 <= local_f8) {

            local_f8 = (float)fVar16;

          }

        }

        if ((*(char *)((int)piVar9 + 2) == '\a') && ((local_100[7] & 1) == 0)) {

          fVar16 = (float10)(**(code **)(*param_3 + 4))(local_100[7],0);

          if ((float)fVar16 <= local_f8) {

            local_f8 = (float)fVar16;

          }

        }

        if ((*(char *)((int)piVar9 + 3) == '\a') && ((local_100[0xe] & 1) == 0)) {

          fVar16 = (float10)(**(code **)(*param_3 + 4))(local_100[0xe],0);

          if ((float)fVar16 <= local_f8) {

            local_f8 = (float)fVar16;

          }

        }

      }

      local_100 = local_100 + 0x1c;

      piVar9 = piVar9 + 1;

    } while (piVar9 < local_24 + (iVar8 >> 2) + 1);

  }

  local_50[0] = param_2[4] - *param_2;

  local_50[1] = param_2[5] - param_2[1];

  local_50[2] = param_2[6] - param_2[2];

  local_50[3] = param_2[7] - param_2[3];

  pfVar15 = (float *)(local_cc + 0x30);

  iVar8 = 0;

  do {

    fVar17 = *(float *)((int)local_50 + iVar8) * *pfVar15;

    if (fVar17 <= 0.0) {

      uVar6 = *(uint32_t /* width from decompiler */ *)((int)apiStack_c8 + iVar8 + 0xc);

      uVar2 = *(uint32_t /* width from decompiler */ *)((int)local_a0 + iVar8);

      *(uint32_t /* width from decompiler */ *)((int)apiStack_c8 + iVar8 + 0xc) = *(uint32_t /* width from decompiler */ *)((int)apiStack_c8 + iVar8);

      *(uint32_t /* width from decompiler */ *)((int)local_a0 + iVar8) = *(uint32_t /* width from decompiler */ *)((int)local_e0 + iVar8);

      *(uint32_t /* width from decompiler */ *)((int)apiStack_c8 + iVar8) = uVar6;

      uVar6 = *(uint32_t /* width from decompiler */ *)((int)local_f0 + iVar8);

      *(uint32_t /* width from decompiler */ *)((int)local_f0 + iVar8) = *(uint32_t /* width from decompiler */ *)((int)local_90 + iVar8);

      *(int *)((int)apiStack_c8 + iVar8) = *(int *)((int)apiStack_c8 + iVar8) + -8;

      piVar9 = (int *)((int)apiStack_c8 + iVar8 + 0xc);

      *piVar9 = *piVar9 + -8;

      *(uint32_t /* width from decompiler */ *)((int)local_90 + iVar8) = uVar6;

      *(uint32_t /* width from decompiler */ *)((int)aiStack_5c + iVar8) = 0xfffffff8;

      *(uint32_t /* width from decompiler */ *)((int)local_e0 + iVar8) = uVar2;

      pbVar11 = abStack_3c + iVar8;

      pbVar11[0] = 1;

      pbVar11[1] = 0;

      pbVar11[2] = 0;

      pbVar11[3] = 0;

      pbVar11 = abStack_30 + iVar8;

      pbVar11[0] = 0;

      pbVar11[1] = 0;

      pbVar11[2] = 0;

      pbVar11[3] = 0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)aiStack_5c + iVar8) = 8;

      pbVar11 = abStack_3c + iVar8;

      pbVar11[0] = 0;

      pbVar11[1] = 0;

      pbVar11[2] = 0;

      pbVar11[3] = 0;

      pbVar11 = abStack_30 + iVar8;

      pbVar11[0] = 1;

      pbVar11[1] = 0;

      pbVar11[2] = 0;

      pbVar11[3] = 0;

    }

    if ((ABS(fVar17) < (pfVar15[-8] + *(float *)((int)local_a0 + iVar8)) * *pfVar15 * DAT_009e33dc)

       || (ABS(fVar17) <

           (*(float *)((int)pfVar15 + (int)param_2 + (-0x20 - local_cc)) + pfVar15[-8]) * *pfVar15 *

           DAT_009e33dc)) {

      *(uint32_t /* width from decompiler */ *)((int)afStack_b0 + iVar8) = 0;

      *(uint32_t /* width from decompiler */ *)((int)afStack_70 + iVar8) = DAT_00a12f70;

      *(uint32_t /* width from decompiler */ *)((int)afStack_80 + iVar8) = DAT_00a12f70;

    }

    else {

      fVar17 = g_flOne / fVar17;

      *(float *)((int)afStack_70 + iVar8) =

           ((pfVar15[-8] + *(float *)((int)local_a0 + iVar8)) * *pfVar15 -

           *(float *)(local_cc + 0x7c)) * fVar17;

      fVar18 = pfVar15[-8];

      fVar19 = *pfVar15;

      fVar20 = *(float *)(local_cc + 0x7c);

      *(float *)((int)afStack_b0 + iVar8) = fVar17;

      *(float *)((int)afStack_80 + iVar8) =

           ((*(float *)((int)local_e0 + iVar8) + fVar18) * fVar19 - fVar20) * fVar17;

    }

    iVar8 = iVar8 + 4;

    pfVar15 = pfVar15 + 1;

  } while (iVar8 < 0xc);

  fVar17 = (float)*apiStack_c8[0];

  if (*apiStack_c8[0] < 0) {

    fVar17 = fVar17 + _DAT_00aaa5dc;

  }

  local_f0[0] = fVar17 * afStack_b0[0] - afStack_70[0];

  fVar17 = (float)*apiStack_c8[1];

  if (*apiStack_c8[1] < 0) {

    fVar17 = fVar17 + _DAT_00aaa5dc;

  }

  local_f0[1] = fVar17 * afStack_b0[1] - afStack_70[1];

  fVar17 = (float)*apiStack_c8[2];

  if (*apiStack_c8[2] < 0) {

    fVar17 = fVar17 + _DAT_00aaa5dc;

  }

  local_f0[2] = fVar17 * afStack_b0[2] - afStack_70[2];

  fVar17 = (float)*apiStack_c8[3];

  if (*apiStack_c8[3] < 0) {

    fVar17 = fVar17 + _DAT_00aaa5dc;

  }

  local_e0[0] = fVar17 * afStack_b0[0] - afStack_80[0];

  fVar17 = (float)*apiStack_c8[4];

  if (*apiStack_c8[4] < 0) {

    fVar17 = fVar17 + _DAT_00aaa5dc;

  }

  local_e0[1] = fVar17 * afStack_b0[1] - afStack_80[1];

  fVar17 = (float)*apiStack_c8[5];

  if (*apiStack_c8[5] < 0) {

    fVar17 = fVar17 + _DAT_00aaa5dc;

  }

  *(char *)local_24 = '\b';

  local_e0[2] = fVar17 * afStack_b0[2] - afStack_80[2];

  if (local_f0[1] <= local_f0[0]) {

    local_100 = (uint *)0x1;

    if (local_f0[1] < local_f0[2]) goto LAB_00630fd0;

  }

  else if (local_f0[0] < local_f0[2]) {

    local_100 = (uint *)0x0;

    goto LAB_00630fd0;

  }

  local_100 = (uint *)0x2;

LAB_00630fd0:

  if (local_e0[1] <= local_e0[0]) {

    iVar8 = 1;

    if (local_e0[1] < local_e0[2]) goto LAB_00631010;

    goto LAB_00631000;

  }

LAB_00630fe1:

  if (local_e0[2] <= local_e0[0]) goto LAB_00631000;

  iVar8 = 0;

LAB_00631010:

  while( true ) {

    piVar9 = DAT_00b05060;

    pfVar15 = local_f0 + (int)local_100;

    pfVar1 = local_e0 + iVar8;

    if (local_f0[(int)local_100] < local_e0[iVar8] || local_f0[(int)local_100] == local_e0[iVar8])

    break;

    if (local_f8 < *pfVar1) goto LAB_00631205;

    do {

      pbVar11 = (byte *)apiStack_c8[iVar8 + 3];

      iVar3 = *(int *)(pbVar11 + 4);

      *(byte *)(iVar3 + (int)local_24) =

           *(byte *)(iVar3 + (int)local_24) ^ (*pbVar11 & 1 ^ abStack_30[iVar8 * 4]) << (sbyte)iVar8

      ;

      if (6 < *(byte *)(iVar3 + (int)local_24)) {

        if (iVar3 == 0) {

          *pfVar1 = g_flLevelUpUiBase_Inferred;

          if (local_e0[0] < local_e0[1]) goto LAB_00630fe1;

          goto LAB_0063111c;

        }

        uVar13 = *(uint *)(*(int *)(local_cc + 0x40) + iVar3 * 0x1c + 0x18);

        if ((uVar13 & 1) == 0) {

          fVar16 = (float10)(**(code **)(*param_3 + 4))(uVar13,0);

          if ((float)fVar16 <= local_f8) {

            local_f8 = (float)fVar16;

          }

        }

      }

      iVar7 = *(int *)pbVar11;

      pbVar11 = pbVar11 + aiStack_5c[iVar8];

      iVar3 = *(int *)pbVar11;

      apiStack_c8[iVar8 + 3] = (int *)pbVar11;

    } while (iVar7 == iVar3);

    fVar17 = (float)*(int *)pbVar11;

    if (*(int *)pbVar11 < 0) {

      fVar17 = fVar17 + _DAT_00aaa5dc;

    }

    *pfVar1 = fVar17 * afStack_b0[iVar8] - afStack_80[iVar8];

    if (local_e0[0] < local_e0[1]) goto LAB_00630fe1;

LAB_0063111c:

    if (local_e0[2] <= local_e0[1]) {

LAB_00631000:

      iVar8 = 2;

    }

    else {

      iVar8 = 1;

    }

  }

  if (local_f8 < *pfVar15) {

LAB_00631205:

    uVar13 = iStack_14 + 0xfU & 0xfffffff0;

    if ((uVar13 == 0) || ((iStack_18 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

      DAT_00b05060[2] = DAT_00b05060[2] - uVar13;

      piVar9[3] = piVar9[3] + uVar13;

    }

    else {

      (**(code **)(*DAT_00b05060 + 0x28))(iStack_18,uVar13);

    }

    if (-1 < (int)uStack_1c) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_24,uStack_1c & 0x7fffffff,0x12);

    }

    return;

  }

  bVar14 = abStack_3c[(int)local_100 * 4];

  do {

    pbVar12 = (byte *)apiStack_c8[(int)local_100];

    iVar3 = *(int *)(pbVar12 + 4);

    pbVar11 = (byte *)(iVar3 + (int)local_24);

    *pbVar11 = *pbVar11 ^ (*pbVar12 & 1 ^ bVar14) << (sbyte)local_100;

    if (8 < *(byte *)(iVar3 + (int)local_24)) {

      *pfVar15 = g_flLevelUpUiBase_Inferred;

      goto LAB_006311b7;

    }

    iVar7 = *(int *)pbVar12;

    pbVar12 = pbVar12 + aiStack_5c[(int)local_100];

    iVar3 = *(int *)pbVar12;

    apiStack_c8[(int)local_100] = (int *)pbVar12;

  } while (iVar7 == iVar3);

  fVar17 = (float)*(int *)pbVar12;

  if (*(int *)pbVar12 < 0) {

    fVar17 = fVar17 + _DAT_00aaa5dc;

  }

  *pfVar15 = fVar17 * afStack_b0[(int)local_100] - afStack_70[(int)local_100];

LAB_006311b7:

  if (local_f0[1] <= local_f0[0]) {

    if (local_f0[1] < local_f0[2]) {

      local_100 = (uint *)0x1;

      goto LAB_00631010;

    }

  }

  else if (local_f0[0] < local_f0[2]) {

    local_100 = (uint *)0x0;

    goto LAB_00631010;

  }

  local_100 = (uint *)0x2;

  goto LAB_00631010;

}
