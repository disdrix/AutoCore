// =============================================================================
// FUN_006999e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006999e0
// Address:   0x006999e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006999e0 @ 0x006999e0
// Stable ID: aa_006999e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006999e0, SQRT.
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

void FUN_006999e0(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  fVar3 = *param_3 - *param_2;

  fVar6 = param_3[1] - param_2[1];

  fVar5 = param_3[2] - param_2[2];

  fVar4 = g_flOne / SQRT(fVar3 * fVar3 + fVar6 * fVar6 + fVar5 * fVar5);

  fVar7 = (*param_4 - *param_2) * fVar3 * fVar4 +

          (param_4[1] - param_2[1]) * fVar6 * fVar4 + (param_4[2] - param_2[2]) * fVar5 * fVar4;

  fVar1 = param_2[2];

  fVar2 = param_2[1];

  *param_1 = fVar3 * fVar4 * fVar7 + *param_2;

  param_1[1] = fVar6 * fVar4 * fVar7 + fVar2;

  param_1[2] = fVar5 * fVar4 * fVar7 + fVar1;

  return;

}
