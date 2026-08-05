// =============================================================================
// FUN_00713230
// -----------------------------------------------------------------------------
// Stable ID: aa_00713230
// Address:   0x00713230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713230 @ 0x00713230
// Stable ID: aa_00713230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00713230.
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

void FUN_00713230(float *param_1,int param_2,int param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  

  fVar1 = *(float *)(param_2 + 4 + param_3 * 8);

  fVar2 = *(float *)(param_2 + param_3 * 8);

  fVar1 = g_flOne / (fVar1 * fVar1 + fVar2 * fVar2);

  *param_4 = (*(float *)(param_2 + param_3 * 8) * *param_1 -

             param_1[1] * *(float *)(param_2 + 4 + param_3 * 8)) * fVar1;

  param_4[1] = (param_1[1] * *(float *)(param_2 + param_3 * 8) +

               *(float *)(param_2 + 4 + param_3 * 8) * *param_1) * fVar1;

  return;

}
