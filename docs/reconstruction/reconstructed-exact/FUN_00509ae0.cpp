// =============================================================================
// FUN_00509ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00509ae0
// Address:   0x00509ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00509ae0 @ 0x00509ae0
// Stable ID: aa_00509ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00509ae0, Map_LowerBoundFindByIntKey.
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

uint32_t /* width from decompiler */ __fastcall FUN_00509ae0(int *param_1)



{

  int *extraout_EAX;

  

  Map_LowerBoundFindByIntKey(&DAT_00b041dc,&stack0xfffffffc,&stack0x00000004,param_1);

  return CONCAT31((int3)((uint)*extraout_EAX >> 8),*extraout_EAX != DAT_00b041e0);

}
