// =============================================================================
// FUN_006f1e40
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1e40
// Address:   0x006f1e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1e40 @ 0x006f1e40
// Stable ID: aa_006f1e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_006f3c40×2, FUN_006f1e40, FUN_006f3a00, FUN_006f3a60.
//  - Return sites: 4.

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

void FUN_006f1e40(uint32_t /* width from decompiler */ param_1,int param_2)



{

  if (param_2 < 0) {

    FUN_006f3c40();

    return;

  }

  if (param_2 < 0x100) {

    FUN_006f3a00();

    return;

  }

  if (param_2 < 0x10000) {

    FUN_006f3a60();

    return;

  }

  FUN_006f3c40();

  return;

}
