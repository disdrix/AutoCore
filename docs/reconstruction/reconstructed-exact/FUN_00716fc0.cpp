// =============================================================================
// FUN_00716fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00716fc0
// Address:   0x00716fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716fc0 @ 0x00716fc0
// Stable ID: aa_00716fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00716fc0.
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

void FUN_00716fc0(float *param_1,float *param_2,int param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float *pfVar8;

  float *pfVar9;

  float *pfVar10;

  float *pfVar11;

  int local_8;

  int local_4;

  

  fVar2 = *param_1;

  fVar3 = *param_2;

  pfVar8 = param_1 + param_3;

  pfVar9 = param_2 + param_3;

  *param_1 = fVar3 + fVar2;

  pfVar10 = (float *)&DAT_00a13314;

  *pfVar8 = fVar2 - fVar3;

  *param_2 = 0.0;

  *pfVar9 = 0.0;

  if (param_3 != 0x100) {

    pfVar10 = (float *)&DAT_00a1370c;

  }

  param_3 = param_3 >> 1;

  local_4 = 1;

  if (1 < param_3) {

    local_8 = param_3 + -1;

    pfVar11 = param_2;

    do {

      pfVar9 = pfVar9 + -1;

      pfVar8 = pfVar8 + -1;

      pfVar11 = pfVar11 + 1;

      param_1 = param_1 + 1;

      fVar2 = *pfVar10;

      pfVar1 = pfVar10 + 1;

      fVar6 = (*pfVar8 + *param_1) * DAT_00a0f298;

      pfVar10 = pfVar10 + 2;

      local_8 = local_8 + -1;

      fVar5 = (*param_1 - *pfVar8) * DAT_00a0f298;

      fVar4 = (*pfVar9 + *pfVar11) * DAT_00a0f298;

      fVar7 = (*pfVar11 - *pfVar9) * DAT_00a0f298;

      fVar3 = fVar5 * *pfVar1 + fVar4 * fVar2;

      fVar2 = fVar5 * fVar2 - fVar4 * *pfVar1;

      *param_1 = fVar3 + fVar6;

      *pfVar8 = fVar6 - fVar3;

      *pfVar11 = fVar7 - fVar2;

      *pfVar9 = -(fVar2 + fVar7);

      local_4 = param_3;

    } while (local_8 != 0);

  }

  param_2[local_4] = -param_2[local_4];

  return;

}
