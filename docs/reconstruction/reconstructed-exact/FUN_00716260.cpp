// =============================================================================
// FUN_00716260
// -----------------------------------------------------------------------------
// Stable ID: aa_00716260
// Address:   0x00716260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716260 @ 0x00716260
// Stable ID: aa_00716260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×14, do×8, while×8, return×1.
//  - Notable callees: ftol×3, FUN_00712480, FUN_00715a00, FUN_00716260, FUN_00716580, FUN_00716600, FUN_00716650, FUN_00717ac0.
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



void FUN_00716260(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 float *param_5,float param_6,float *param_7,float param_8,float *param_9,

                 float *param_10,float *param_11,uint32_t /* width from decompiler */ param_12)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  int iVar10;

  float *pfVar11;

  float10 fVar12;

  float local_c;

  float local_8;

  

  pfVar3 = param_9;

  local_8 = _DAT_00a0f51c / (float)param_5;

  iVar4 = ftol();

  if (0xff < (int)ROUND((float)iVar4 * local_8)) {

    iVar4 = iVar4 + -1;

  }

  if (100 < iVar4) {

    iVar4 = 100;

  }

  if (_DAT_00a111ac <= param_6 * _DAT_00a111ac) {

    iVar5 = 1;

  }

  else {

    iVar5 = (int)(100 / (longlong)iVar4);

  }

  iVar6 = iVar5 * iVar4;

  fVar1 = local_8 / (float)iVar5;

  iVar7 = ftol();

  iVar8 = iVar7 * iVar5;

  fVar12 = (float10)FUN_00716600(param_5,fVar1);

  FUN_00717ac0((float)fVar12,local_8,fVar1,iVar4,iVar7,param_3,param_10,param_7,param_9,param_8,

               param_11);

  FUN_00716650(param_1,local_8,&local_c,0x50);

  fVar2 = local_c;

  local_8 = (float)ftol();

  param_11 = (float *)local_c;

  param_8 = 0.31830987;

  param_5 = (float *)0x0;

  if (0 < iVar4) {

    param_7 = param_9;

    do {

      *param_7 = (float)param_11 + *param_7;

      param_11 = (float *)((float)param_11 + fVar2);

      if ((int)local_8 <= (int)param_5) {

        param_8 = param_8 + _DAT_00a12850;

      }

      if (((uint)param_5 & 1) == 0) {

        *param_7 = param_8 + *param_7;

      }

      fVar12 = (float10)FUN_00715a00(*(uint32_t /* width from decompiler */ *)(((int)param_10 - (int)param_9) + (int)param_7))

      ;

      *(float *)(((int)param_10 - (int)param_9) + (int)param_7) = (float)fVar12;

      param_5 = (float *)((int)param_5 + 1);

      param_7 = param_7 + 1;

    } while ((int)param_5 < iVar4);

  }

  iVar4 = iVar4 + -1;

  iVar10 = iVar6 + -1;

  if (iVar7 <= iVar4) {

    pfVar9 = param_9 + iVar4;

    param_11 = param_9 + iVar10;

    iVar7 = (iVar4 - iVar7) + 1;

    iVar4 = iVar4 - iVar7;

    do {

      pfVar11 = param_11;

      if (0 < iVar5) {

        iVar10 = iVar10 - iVar5;

        pfVar11 = param_11 + -iVar5;

        param_8 = (float)iVar5;

        do {

          *(uint32_t /* width from decompiler */ *)((int)param_11 + ((int)param_10 - (int)param_9)) =

               *(uint32_t /* width from decompiler */ *)((int)pfVar9 + ((int)param_10 - (int)param_9));

          *param_11 = *pfVar9;

          param_11 = param_11 + -1;

          param_8 = (float)((int)param_8 + -1);

        } while (param_8 != 0.0);

      }

      param_11 = pfVar11;

      pfVar9 = pfVar9 + -1;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  if (-1 < iVar4) {

    param_5 = param_9 + iVar4;

    iVar7 = (int)param_10 - (int)param_9;

    param_9 = (float *)(iVar4 + 1);

    do {

      iVar4 = iVar10 + -1;

      param_10[iVar10] = *(float *)((int)param_5 + iVar7);

      pfVar3[iVar10] = *param_5;

      if (1 < iVar5) {

        iVar10 = iVar5 + -1;

        pfVar9 = pfVar3 + iVar4;

        iVar4 = iVar4 - iVar10;

        do {

          *(uint32_t /* width from decompiler */ *)((int)pfVar9 + iVar7) = 0;

          *pfVar9 = 0.0;

          pfVar9 = pfVar9 + -1;

          iVar10 = iVar10 + -1;

        } while (iVar10 != 0);

      }

      param_5 = param_5 + -1;

      param_9 = (float *)((int)param_9 + -1);

      iVar10 = iVar4;

    } while (param_9 != (float *)0x0);

  }

  if (iVar8 < iVar6) {

    iVar4 = iVar6 - iVar8;

    pfVar9 = pfVar3 + iVar8;

    do {

      iVar5 = FUN_00716580(param_12);

      iVar4 = iVar4 + -1;

      *pfVar9 = (float)iVar5 * _DAT_00a12820;

      pfVar9 = pfVar9 + 1;

    } while (iVar4 != 0);

  }

  param_5 = (float *)0x3f800000;

  iVar4 = iVar6;

  pfVar9 = param_10;

  fVar2 = g_flZero;

  if (0 < iVar6) {

    do {

      fVar2 = fVar2 + *pfVar9;

      pfVar9 = pfVar9 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    if (_DAT_00a0f164 < fVar2) {

      param_5 = (float *)(_DAT_00a0f164 / fVar2);

    }

  }

  iVar4 = iVar6;

  pfVar9 = param_10;

  if (0 < iVar6) {

    do {

      iVar4 = iVar4 + -1;

      *pfVar9 = (float)param_5 * *pfVar9;

      pfVar9 = pfVar9 + 1;

    } while (iVar4 != 0);

  }

  FUN_00712480(fVar1,iVar6,0xa0,param_2,param_3,param_4,pfVar3,param_10);

  return;

}
