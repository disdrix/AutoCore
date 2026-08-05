// =============================================================================
// FUN_00515060
// -----------------------------------------------------------------------------
// Stable ID: aa_00515060
// Address:   0x00515060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00515060 @ 0x00515060
// Stable ID: aa_00515060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004e2600, FUN_00515060.
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

void __thiscall FUN_00515060(int param_1,uint32_t /* width from decompiler */ param_2)



{

  if (*(int *)(param_1 + 0xac) != 0) {

    (**(code **)(**(int **)(param_1 + 0xac) + 0x220))(param_2,0);

  }

  FUN_004e2600(&LAB_00512f50,&param_2,0);

  return;

}
