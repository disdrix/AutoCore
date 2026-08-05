// =============================================================================
// FUN_005d1c00
// -----------------------------------------------------------------------------
// Stable ID: aa_005d1c00
// Address:   0x005d1c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d1c00 @ 0x005d1c00
// Stable ID: aa_005d1c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005d1c00, SQRT.
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

void __thiscall FUN_005d1c00(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  *param_2 = *param_1;

  param_2[1] = param_1[1];

  param_2[2] = param_1[2];

  fVar5 = *param_2 * *param_2 + param_2[1] * param_2[1] + param_2[2] * param_2[2];

  param_2[3] = param_1[3];

  if (fVar5 == 0.0) {

    fVar5 = 0.0;

  }

  else {

    fVar5 = g_flOne / SQRT(fVar5);

  }

  fVar1 = *param_2;

  fVar2 = param_2[2];

  fVar3 = param_2[3];

  fVar4 = param_2[1];

  *param_2 = fVar1 * fVar5;

  param_2[1] = fVar5 * fVar4;

  param_2[2] = fVar2 * fVar5;

  param_2[3] = fVar3 * fVar5;

  if (param_1[3] <= 0.0 && param_1[3] != 0.0) {

    param_2[1] = 0.0 - fVar5 * fVar4;

    *param_2 = 0.0 - fVar1 * fVar5;

    param_2[2] = 0.0 - fVar2 * fVar5;

    param_2[3] = 0.0 - fVar3 * fVar5;

  }

  return;

}
