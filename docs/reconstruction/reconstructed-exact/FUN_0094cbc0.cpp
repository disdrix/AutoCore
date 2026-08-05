// =============================================================================
// FUN_0094cbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094cbc0
// Address:   0x0094cbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094cbc0 @ 0x0094cbc0
// Stable ID: aa_0094cbc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_008073b0×2, FUN_0094cbc0.
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

void FUN_0094cbc0(char param_1)



{

  if (param_1 != '\0') {

    _param_1 = 0x8012;

    FUN_008073b0(4,&param_1);

    return;

  }

  _param_1 = 0x8014;

  FUN_008073b0(4,&param_1);

  return;

}
