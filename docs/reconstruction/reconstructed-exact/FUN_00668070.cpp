// =============================================================================
// FUN_00668070
// -----------------------------------------------------------------------------
// Stable ID: aa_00668070
// Address:   0x00668070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00668070 @ 0x00668070
// Stable ID: aa_00668070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00665e40, FUN_00667420, FUN_00668070.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00668070(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_00665e40(param_2);

  *param_1 = &PTR_FUN_009e7864;

  param_1[2] = &PTR_LAB_009e7854;

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x3a] = 0;

  FUN_00667420(param_2);

  return param_1;

}
