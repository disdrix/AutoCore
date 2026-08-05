// =============================================================================
// FUN_007066f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007066f0
// Address:   0x007066f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007066f0 @ 0x007066f0
// Stable ID: aa_007066f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×17, do×2, while×2, return×1.
//  - Notable callees: FUN_007066f0.
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



void __fastcall FUN_007066f0(uint32_t /* width from decompiler */ param_1,float *param_2,int param_3,int param_4)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  

  iVar5 = 0;

  if (3 < param_4) {

    do {

      if (iVar5 == 0) {

        fVar2 = *param_2;

      }

      else {

        fVar2 = param_2[iVar5] - param_2[iVar5 + -1];

      }

      iVar1 = param_4 + -1;

      if (iVar5 == iVar1) {

        fVar3 = (float)_DAT_00a0f190 - param_2[iVar5];

      }

      else {

        fVar3 = param_2[iVar5 + 1] - param_2[iVar5];

      }

      if (fVar3 < fVar2) {

        fVar2 = fVar3;

      }

      *(float *)(param_3 + iVar5 * 4) = (float)_DAT_00a0f6c8 / (fVar2 + (float)_DAT_00a0f1d8);

      fVar2 = param_2[iVar5 + 1];

      if (iVar5 != -1) {

        fVar2 = fVar2 - param_2[iVar5];

      }

      if (iVar5 + 1 == iVar1) {

        fVar3 = (float)_DAT_00a0f190 - param_2[iVar5 + 1];

      }

      else {

        fVar3 = param_2[iVar5 + 2] - param_2[iVar5 + 1];

      }

      if (fVar3 < fVar2) {

        fVar2 = fVar3;

      }

      iVar8 = iVar5 + 2;

      *(float *)(param_3 + 4 + iVar5 * 4) = (float)_DAT_00a0f6c8 / (fVar2 + (float)_DAT_00a0f1d8);

      if (iVar8 == 0) {

        fVar2 = *param_2;

        iVar7 = 0;

        pfVar6 = param_2;

      }

      else {

        iVar7 = iVar8 * 4;

        pfVar6 = param_2 + iVar8;

        fVar2 = param_2[iVar8] - param_2[iVar5 + 1];

      }

      if (iVar8 == iVar1) {

        fVar3 = (float)_DAT_00a0f190 - *pfVar6;

      }

      else {

        fVar3 = param_2[iVar5 + 3] - *pfVar6;

      }

      if (fVar3 < fVar2) {

        fVar2 = fVar3;

      }

      iVar1 = iVar5 + 3;

      *(float *)(iVar7 + param_3) = (float)_DAT_00a0f6c8 / (fVar2 + (float)_DAT_00a0f1d8);

      if (iVar1 == 0) {

        fVar2 = *param_2;

        iVar8 = 0;

        pfVar4 = param_2;

      }

      else {

        iVar8 = iVar1 * 4;

        pfVar4 = param_2 + iVar1;

        fVar2 = param_2[iVar1] - *pfVar6;

      }

      if (iVar1 == param_4 + -1) {

        fVar3 = (float)_DAT_00a0f190 - *pfVar4;

      }

      else {

        fVar3 = param_2[iVar5 + 4] - *pfVar4;

      }

      if (fVar3 < fVar2) {

        fVar2 = fVar3;

      }

      iVar5 = iVar5 + 4;

      *(float *)(iVar8 + param_3) = (float)_DAT_00a0f6c8 / (fVar2 + (float)_DAT_00a0f1d8);

    } while (iVar5 < param_4 + -3);

  }

  if (iVar5 < param_4) {

    do {

      if (iVar5 == 0) {

        fVar2 = *param_2;

      }

      else {

        fVar2 = param_2[iVar5] - param_2[iVar5 + -1];

      }

      if (iVar5 == param_4 + -1) {

        fVar3 = (float)_DAT_00a0f190 - param_2[iVar5];

      }

      else {

        fVar3 = param_2[iVar5 + 1] - param_2[iVar5];

      }

      if (fVar3 < fVar2) {

        fVar2 = fVar3;

      }

      iVar5 = iVar5 + 1;

      *(float *)(param_3 + -4 + iVar5 * 4) = (float)_DAT_00a0f6c8 / (fVar2 + (float)_DAT_00a0f1d8);

    } while (iVar5 < param_4);

  }

  return;

}
