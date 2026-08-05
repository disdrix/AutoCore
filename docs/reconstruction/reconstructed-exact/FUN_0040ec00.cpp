// =============================================================================
// FUN_0040ec00
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ec00
// Address:   0x0040ec00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ec00 @ 0x0040ec00
// Stable ID: aa_0040ec00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040ec00.
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

uint32_t /* width from decompiler */ FUN_0040ec00(void)



{

  int in_EAX;

  

  if ((((in_EAX != 0x31545844) && (in_EAX != 0x32545844)) && (in_EAX != 0x33545844)) &&

     ((in_EAX != 0x34545844 && (in_EAX != 0x35545844)))) {

    return 0;

  }

  return 1;

}
