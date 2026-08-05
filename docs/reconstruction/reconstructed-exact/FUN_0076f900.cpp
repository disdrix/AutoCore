// =============================================================================
// FUN_0076f900
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f900
// Address:   0x0076f900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076f900 @ 0x0076f900
// Stable ID: aa_0076f900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076f5f0, FUN_0076f900, fcos, fsin.
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

void FUN_0076f900(float *param_1,uint32_t /* width from decompiler */ param_2,float param_3)



{

  float10 fVar1;

  float10 fVar2;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_0076f5f0(&local_c,param_2);

  fVar2 = (float10)DAT_00a0f298;

  fVar1 = (float10)fsin((float10)param_3 * fVar2);

  *param_1 = (float)((float10)local_c * fVar1);

  param_1[1] = (float)((float10)local_8 * fVar1);

  param_1[2] = (float)((float10)local_4 * fVar1);

  fVar2 = (float10)fcos((float10)param_3 * fVar2);

  param_1[3] = (float)fVar2;

  return;

}
