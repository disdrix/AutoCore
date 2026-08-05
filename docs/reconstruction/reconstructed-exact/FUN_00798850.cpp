// =============================================================================
// FUN_00798850
// -----------------------------------------------------------------------------
// Stable ID: aa_00798850
// Address:   0x00798850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00798850 @ 0x00798850
// Stable ID: aa_00798850
// Embedded strings (evidence for future rename):
//   - "%f,%f,%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00798850, swscanf.
//  - Strings: "%f,%f,%f".
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

void FUN_00798850(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  swscanf((wchar_t *)*param_1,L"%f,%f,%f",param_2,param_2 + 4,param_2 + 8);

  return;

}
