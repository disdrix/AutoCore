// =============================================================================
// FUN_00717920
// -----------------------------------------------------------------------------
// Stable ID: aa_00717920
// Address:   0x00717920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717920 @ 0x00717920
// Stable ID: aa_00717920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, if×3, return×1.
//  - Notable callees: FUN_00714590×2, FUN_007159e0×2, FUN_00717920.
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



void FUN_00717920(float *param_1,float param_2,float *param_3)



{

  int iVar1;

  float10 fVar2;

  float fVar3;

  float fVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  float10 fVar9;

  float10 fVar10;

  float local_24;

  float local_20;

  uint8_t local_1c [4];

  uint8_t local_18 [4];

  float local_14 [5];

  

  pfVar5 = param_1;

  FUN_00714590(param_1,0x40,local_1c,&local_24);

  iVar6 = 0xb;

  pfVar8 = param_3;

  fVar3 = g_flOne;

  do {

    pfVar8 = pfVar8 + 1;

    iVar6 = iVar6 + -1;

    fVar3 = (g_flOne - *pfVar8 * *pfVar8) * fVar3;

  } while (iVar6 != 0);

  fVar9 = (float10)FUN_007159e0(fVar3);

  fVar2 = (float10)DAT_00a0f298;

  iVar6 = 5;

  fVar3 = *param_3 * *param_3 + g_flOne;

  fVar4 = *param_3 * DAT_00a12f70;

  iVar7 = 0;

  pfVar8 = local_14;

  do {

    iVar1 = iVar7 * 4;

    iVar7 = iVar7 + DAT_00a13ffc;

    fVar10 = (float10)FUN_007159e0(fVar4 * *(float *)(PTR_DAT_00af8b14 + iVar1) + fVar3);

    iVar6 = iVar6 + -1;

    *pfVar8 = (float)((float10)(float)((float10)param_2 - fVar9 * fVar2) -

                     fVar10 * (float10)DAT_00a0f298);

    pfVar8 = pfVar8 + 1;

  } while (iVar6 != 0);

  param_1 = (float *)0x1;

  pfVar8 = pfVar5;

  do {

    pfVar8 = pfVar8 + 1;

    fVar3 = (*pfVar8 -

            ((float)((uint)param_1 & 0xf) * DAT_00a14000 *

             (local_14[((int)param_1 >> 4) + 1] - local_14[(int)param_1 >> 4]) +

            local_14[(int)param_1 >> 4])) * DAT_00a0f298;

    if (_DAT_00a13fec < fVar3) {

      fVar3 = _DAT_00a13fec;

    }

    if (fVar3 <= _DAT_00a13ff0) {

      fVar3 = _DAT_00a13ff0;

    }

    if ((int)param_1 < DAT_00a13ff4) {

      fVar3 = (float)(int)param_1 * _DAT_00a13ff8 * fVar3;

    }

    param_1 = (float *)((int)param_1 + 1);

    *pfVar8 = fVar3 + *pfVar8;

  } while ((int)param_1 < 0x40);

  FUN_00714590(pfVar5,0x40,local_18,&local_20);

  iVar6 = 0x40;

  do {

    iVar6 = iVar6 + -1;

    *pfVar5 = (local_24 - local_20) + *pfVar5;

    pfVar5 = pfVar5 + 1;

  } while (iVar6 != 0);

  return;

}
