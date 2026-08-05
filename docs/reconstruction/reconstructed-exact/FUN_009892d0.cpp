// =============================================================================
// FUN_009892d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009892d0
// Address:   0x009892d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009892d0 @ 0x009892d0
// Stable ID: aa_009892d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_009892d0.
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

void FUN_009892d0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  

  param_1[1] = 0;

  fVar1 = g_flOne;

  *param_1 = &PTR_FUN_00aa092c;

  param_1[2] = 0xffffffff;

  param_1[3] = 0xffffffff;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = fVar1;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  return;

}
