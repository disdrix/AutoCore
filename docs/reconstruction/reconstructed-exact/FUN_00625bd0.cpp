// =============================================================================
// FUN_00625bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00625bd0
// Address:   0x00625bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00625bd0 @ 0x00625bd0
// Stable ID: aa_00625bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00625bd0.
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

uint64_t __thiscall FUN_00625bd0(int param_1,uint param_2)



{

  if ((*(int *)(param_1 + 0x54) != 0) &&

     (param_2 < (uint)(*(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x54) >> 3))) {

    return *(uint64_t *)(*(int *)(param_1 + 0x54) + param_2 * 8);

  }

  return 0;

}
