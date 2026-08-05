// =============================================================================
// FUN_0073ac80
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ac80
// Address:   0x0073ac80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073ac80 @ 0x0073ac80
// Stable ID: aa_0073ac80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00464900, FUN_0073ac80.
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

float10 __fastcall FUN_0073ac80(int param_1)



{

  if (*(char *)(param_1 + 0xd0) == '\0') {

    return (float10)g_flZero;

  }

  FUN_00464900();

  return (float10)*(float *)(param_1 + 0x21c) * (float10)*(float *)(param_1 + 0xd4);

}
