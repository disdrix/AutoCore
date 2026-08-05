// =============================================================================
// FUN_005a4d70
// -----------------------------------------------------------------------------
// Stable ID: aa_005a4d70
// Address:   0x005a4d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a4d70 @ 0x005a4d70
// Stable ID: aa_005a4d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005a2e40, FUN_005a36f0, FUN_005a4c30, FUN_005a4d70.
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

uint32_t /* width from decompiler */ FUN_005a4d70(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_005a36f0(&local_8,param_1);

  param_1 = 0;

  FUN_005a2e40(local_8,local_4,&param_1,0);

  FUN_005a4c30(&local_8,local_8,local_4);

  return param_1;

}
