// =============================================================================
// FUN_00717110
// -----------------------------------------------------------------------------
// Stable ID: aa_00717110
// Address:   0x00717110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717110 @ 0x00717110
// Stable ID: aa_00717110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00717110.
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

void FUN_00717110(float *param_1,float *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float *pfVar8;

  float *pfVar9;

  float *pfVar10;

  

  pfVar10 = (float *)&DAT_00a13314;

  fVar1 = *param_1;

  pfVar8 = param_1 + param_3;

  fVar2 = *param_2;

  fVar3 = *pfVar8;

  fVar4 = param_2[param_3];

  pfVar9 = param_2 + param_3;

  *param_1 = (fVar3 + fVar1) - (fVar4 + fVar2);

  *param_2 = (fVar1 - fVar3) + (fVar2 - fVar4);

  if (param_3 != 0x100) {

    pfVar10 = (float *)&DAT_00a1370c;

  }

  param_3 = param_3 >> 1;

  param_1[param_3] = param_1[param_3] + param_1[param_3];

  param_2[param_3] = param_2[param_3] + param_2[param_3];

  if (1 < param_3) {

    param_3 = param_3 + -1;

    do {

      pfVar9 = pfVar9 + -1;

      pfVar8 = pfVar8 + -1;

      param_2 = param_2 + 1;

      param_1 = param_1 + 1;

      fVar3 = *pfVar8 + *param_1;

      fVar4 = *param_1 - *pfVar8;

      fVar6 = *pfVar9 + *param_2;

      fVar7 = *param_2 - *pfVar9;

      fVar1 = *pfVar10;

      fVar2 = pfVar10[1];

      param_3 = param_3 + -1;

      fVar5 = fVar1 * fVar6 - fVar2 * fVar4;

      *param_1 = fVar3 - fVar5;

      fVar1 = fVar1 * fVar4 + fVar2 * fVar6;

      *param_2 = fVar1 + fVar7;

      *pfVar8 = fVar5 + fVar3;

      *pfVar9 = -(fVar7 - fVar1);

      pfVar10 = pfVar10 + 2;

    } while (param_3 != 0);

  }

  return;

}
