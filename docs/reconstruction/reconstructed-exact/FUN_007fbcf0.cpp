// =============================================================================
// FUN_007fbcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbcf0
// Address:   0x007fbcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fbcf0 @ 0x007fbcf0
// Stable ID: aa_007fbcf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT22, FUN_007fbcf0.
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

uint32_t /* width from decompiler */ FUN_007fbcf0(void)



{

  int iVar1;

  

  if (DAT_00d1b252 == 1) {

    return 0x4b;

  }

  iVar1 = DAT_00d1b252 - 2;

  if (iVar1 != 0) {

    return CONCAT22((short)((uint)iVar1 >> 0x10),100);

  }

  return 0x32;

}
