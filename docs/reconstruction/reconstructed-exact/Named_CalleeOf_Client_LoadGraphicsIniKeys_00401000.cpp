// =============================================================================
// Named_CalleeOf_Client_LoadGraphicsIniKeys_00401000
// -----------------------------------------------------------------------------
// Stable ID: aa_00401000
// Callee of Client_LoadGraphicsIniKeys
// Address:   0x00401000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_LoadGraphicsIniKeys: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00401000.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_LoadGraphicsIniKeys
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_LoadGraphicsIniKeys_00401000(float param_1)



{

  if ((param_1 < DAT_00a0f298) || (DAT_00aaa68c < param_1)) {

    param_1 = g_flOne;

  }

  DAT_00aefa88 = param_1;

  return;

}
