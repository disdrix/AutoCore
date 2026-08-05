// =============================================================================
// FUN_00569de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00569de0
// Address:   0x00569de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00569de0 @ 0x00569de0
// Stable ID: aa_00569de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00569de0.
//  - Return sites: 3.

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

void __thiscall FUN_00569de0(int param_1,float param_2)



{

  float fVar1;

  

  fVar1 = g_flOne - (g_flOne - *(float *)(param_1 + 0xdc)) * param_2;

  if ((DAT_00aaa668 < fVar1) && (g_flOne <= fVar1)) {

    *(float *)(param_1 + 0xdc) = g_flOne;

    return;

  }

  if (DAT_00aaa668 < fVar1) {

    *(float *)(param_1 + 0xdc) = fVar1;

    return;

  }

  *(float *)(param_1 + 0xdc) = DAT_00aaa668;

  return;

}
