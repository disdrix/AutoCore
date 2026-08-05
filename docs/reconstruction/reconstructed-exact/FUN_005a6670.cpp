// =============================================================================
// FUN_005a6670
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6670
// Address:   0x005a6670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6670 @ 0x005a6670
// Stable ID: aa_005a6670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005a6670.
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

void __thiscall FUN_005a6670(uint32_t /* width from decompiler */ *param_1,char param_2)



{

  *param_1 = &PTR_FUN_009d8244;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  if (param_2 != '\0') {

    param_1[1] = param_1;

    param_1[2] = param_1;

  }

  return;

}
