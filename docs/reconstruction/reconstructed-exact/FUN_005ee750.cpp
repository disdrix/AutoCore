// =============================================================================
// FUN_005ee750
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee750
// Address:   0x005ee750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ee750 @ 0x005ee750
// Stable ID: aa_005ee750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005ee750.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_005ee750(float *param_1,float param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  fVar4 = g_flOne;

  if (param_2 <= 0.0) {

    return 1;

  }

  fVar1 = *param_1;

  fVar2 = param_1[2];

  fVar3 = param_1[1];

  fVar5 = param_2 * g_flDisplayRateScaleOneThird;

  param_3[0xb] = 0.0;

  param_3[10] = 0.0;

  param_3[9] = 0.0;

  param_3[8] = 0.0;

  param_3[0xf] = 0.0;

  param_3[0xe] = 0.0;

  param_3[0xd] = 0.0;

  param_3[0xc] = 0.0;

  param_3[0x13] = 0.0;

  param_3[0x12] = 0.0;

  param_3[0x11] = 0.0;

  param_3[0x10] = 0.0;

  param_3[8] = fVar4;

  param_3[0xd] = fVar4;

  param_3[0x12] = fVar4;

  param_3[8] = (fVar3 * fVar3 + fVar2 * fVar2) * fVar5;

  param_3[0xd] = (fVar1 * fVar1 + fVar2 * fVar2) * fVar5;

  param_3[0x12] = (fVar1 * fVar1 + fVar3 * fVar3) * fVar5;

  param_3[7] = 0.0;

  param_3[6] = 0.0;

  param_3[5] = 0.0;

  param_3[4] = 0.0;

  *param_3 = fVar2 * fVar3 * fVar1 * DAT_00a0f6a4;

  param_3[1] = param_2;

  return 0;

}
