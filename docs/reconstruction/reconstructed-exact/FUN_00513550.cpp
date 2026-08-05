// =============================================================================
// FUN_00513550
// -----------------------------------------------------------------------------
// Stable ID: aa_00513550
// Address:   0x00513550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513550 @ 0x00513550
// Stable ID: aa_00513550
// Embedded strings (evidence for future rename):
//   - "%S_i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00513550, _snprintf.
//  - Strings: "%S_i".
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

undefined * __fastcall FUN_00513550(int param_1)



{

  _snprintf(&DAT_00b04380,0x104,"%S_i",*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x10);

  return &DAT_00b04380;

}
