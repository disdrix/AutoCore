// =============================================================================
// FUN_006f88a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f88a0
// Address:   0x006f88a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f88a0 @ 0x006f88a0
// Stable ID: aa_006f88a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×11, return×5, do×1, while×1.
//  - Notable callees: FUN_006fb090×2, FUN_005b3370, FUN_006f8590, FUN_006f8720, FUN_006f87d0, FUN_006f88a0, FUN_006fb110.
//  - Return sites: 5.

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



void __thiscall FUN_006f88a0(uint32_t /* width from decompiler */ *param_1,int param_2,float *param_3,ushort *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  ushort uVar8;

  float *pfVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  ushort *puVar13;

  int iVar14;

  

  if (*param_4 < 6) {

    if (*param_4 < 3) {

      fVar1 = param_3[4];

      pfVar9 = (float *)param_1[6];

      fVar2 = param_3[5];

      fVar3 = param_3[6];

    }

    else {

      fVar1 = *param_3;

      pfVar9 = (float *)param_1[5];

      fVar2 = param_3[1];

      fVar3 = param_3[2];

    }

    iVar12 = 0;

    if (0 < *(int *)(param_2 + 0x54)) {

      iVar14 = 0;

      puVar13 = (ushort *)(param_2 + 0x20);

      do {

        if ((*puVar13 < 6) &&

           (fVar6 = (fVar1 * *pfVar9 + fVar2 * pfVar9[4] + fVar3 * pfVar9[8] + pfVar9[0xc]) -

                    *(float *)(**(int **)param_1[4] + iVar14),

           iVar10 = **(int **)param_1[4] + iVar14,

           fVar7 = (fVar1 * pfVar9[1] + fVar2 * pfVar9[5] + fVar3 * pfVar9[9] + pfVar9[0xd]) -

                   *(float *)(iVar10 + 4),

           fVar5 = (fVar1 * pfVar9[2] + fVar2 * pfVar9[6] + fVar3 * pfVar9[10] + pfVar9[0xe]) -

                   *(float *)(iVar10 + 8),

           fVar6 * fVar6 + fVar7 * fVar7 + fVar5 * fVar5 <=

           (float)param_1[0x18] * (float)param_1[0x18] + _DAT_00a0f000)) {

          return;

        }

        iVar12 = iVar12 + 1;

        puVar13 = puVar13 + 3;

        iVar14 = iVar14 + 0x30;

      } while (iVar12 < *(int *)(param_2 + 0x54));

    }

  }

  if ((*(int *)(param_2 + 0x54) < 8) &&

     (iVar12 = FUN_006fb110(*param_1,param_1[1],param_4), -1 < iVar12)) {

    piVar4 = *(int **)param_1[4];

    if (piVar4[1] == (piVar4[2] & 0x7fffffffU)) {

      FUN_005b3370(piVar4,0x30);

    }

    iVar14 = piVar4[1] * 0x30 + *piVar4;

    piVar4[1] = piVar4[1] + 1;

    if (*(ushort *)(param_3 + 0xe) < 3) {

      FUN_006f8590(iVar14,param_4,param_3);

    }

    else if (*(ushort *)(param_3 + 0xe) < 6) {

      FUN_006f8720(iVar14,param_4,param_3);

    }

    else {

      FUN_006f87d0(iVar14,param_4,param_3);

    }

    if ((1 < *(int *)(param_2 + 0x54)) &&

       (iVar10 = **(int **)param_1[4], iVar11 = (*(int **)param_1[4])[1] * 0x30,

       pfVar9 = (float *)(iVar11 + -0x50 + iVar10),

       fVar1 = *(float *)(iVar14 + 0x10) * *pfVar9 +

               pfVar9[1] * *(float *)(iVar14 + 0x14) +

               *(float *)(iVar11 + -0x48 + iVar10) * *(float *)(iVar14 + 0x18),

       fVar1 < g_flZero != (fVar1 == g_flZero))) {

      *(int *)(*(int *)param_1[4] + 4) = *(int *)(*(int *)param_1[4] + 4) + -1;

      FUN_006fb090(iVar12,*param_1,param_1[1]);

      return;

    }

    iVar12 = iVar14;

    uVar8 = (**(code **)(*(int *)param_1[3] + 4))(*param_1,param_1[1],param_1[2]);

    puVar13 = (ushort *)(param_2 + (iVar12 * 3 + 0x12) * 2);

    *puVar13 = uVar8;

    if (uVar8 == 0xffff) {

      *(int *)(*(int *)param_1[4] + 4) = *(int *)(*(int *)param_1[4] + 4) + -1;

      FUN_006fb090(iVar12,*param_1,param_1[1]);

      return;

    }

    param_4[2] = uVar8;

    *(ushort *)(iVar14 + 0x20) = *puVar13;

    if (*param_4 < 6) {

      *(int *)(param_2 + 0x50) = *(int *)(param_2 + 0x50) + 1;

      return;

    }

  }

  return;

}
