// =============================================================================
// FUN_00498a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00498a50
// Address:   0x00498a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00498a50 @ 0x00498a50
// Stable ID: aa_00498a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00498a50.
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

uint8_t __thiscall FUN_00498a50(int param_1,float param_2)



{

  if (*(char *)(param_1 + 0x17c) != '\0') {

    return 1;

  }

  param_2 = *(float *)(param_1 + 0x174) - param_2;

  *(float *)(param_1 + 0x174) = param_2;

  if (param_2 <= 0.0) {

    *(uint8_t *)(param_1 + 0x17c) = 1;

    return 1;

  }

  return 0;

}
