// =============================================================================
// FUN_0066d300
// -----------------------------------------------------------------------------
// Stable ID: aa_0066d300
// Address:   0x0066d300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066d300 @ 0x0066d300
// Stable ID: aa_0066d300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0066d130, FUN_0066d300.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0066d300(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009d27b0;

  param_1[3] = &PTR_LAB_009d2784;

  param_1[4] = &PTR_LAB_009d278c;

  param_1[5] = &PTR_LAB_009d27b0;

  param_1[6] = &PTR_LAB_009e3a68;

  *param_1 = &PTR_FUN_009e7b00;

  param_1[2] = &PTR_LAB_009e7afc;

  param_1[3] = &PTR_LAB_009e7af4;

  param_1[4] = &PTR_LAB_009e7aec;

  param_1[5] = &PTR_LAB_009e7ae8;

  param_1[6] = &PTR_LAB_009e7ad8;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0x80000000;

  FUN_0066d130(param_2);

  return param_1;

}
