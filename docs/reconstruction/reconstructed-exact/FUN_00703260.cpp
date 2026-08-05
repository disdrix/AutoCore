// =============================================================================
// FUN_00703260
// -----------------------------------------------------------------------------
// Stable ID: aa_00703260
// Address:   0x00703260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00703260 @ 0x00703260
// Stable ID: aa_00703260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00703260, _CIpow.
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



void FUN_00703260(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  float10 fVar2;

  float10 fVar3;

  

  param_1[1] = 0;

  param_1[2] = 0x3f800000;

  param_1[8] = 0;

  *param_1 = 0x3dcccccd;

  param_1[10] = 0;

  param_1[9] = 0;

  param_1[0xb] = 0;

  fVar3 = (float10)_CIpow();

  fVar2 = (float10)_DAT_00aaa5f0;

  param_1[0xf] = 0;

  param_1[0xd] = (float)(fVar3 * fVar2);

  param_1[0xe] = 0x3d4ccccd;

  param_1[0xc] = (float)(fVar3 * fVar2 * (float10)(float)g_nInferredThreatDefault);

  fVar1 = (float)((float10)0.6931471805599453 * (float10)_DAT_00a0f108);

  param_1[3] = fVar1;

  param_1[4] = fVar1;

  param_1[5] = fVar1;

  param_1[6] = fVar1;

  param_1[7] = fVar1;

  return;

}
