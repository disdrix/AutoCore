// =============================================================================
// Inv_setloottype_d
// -----------------------------------------------------------------------------
// Stable ID: aa_0094db40
// Address:   0x0094db40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_setloottype_d @ 0x0094db40
// Stable ID: aa_0094db40
// Embedded strings (evidence for future rename):
//   - "//setloottype %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00941fb0, Inv_setloottype_d, sprintf.
//  - Strings: "//setloottype %d".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//setloottype %d"
 * Domain alias of FUN_0094db40 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_setloottype_d(uint32_t /* width from decompiler */ param_1)



{

  char local_80 [128];

  

  sprintf(local_80,"//setloottype %d");

  FUN_00941fb0(param_1,3,0);

  return;

}
