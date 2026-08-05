// =============================================================================
// FUN_0085d900
// -----------------------------------------------------------------------------
// Stable ID: aa_0085d900
// Address:   0x0085d900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085d900 @ 0x0085d900
// Stable ID: aa_0085d900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0085ce20, FUN_0085d900.
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

uint32_t /* width from decompiler */ __fastcall FUN_0085d900(int *param_1)



{

  if (DAT_00d1b6d8 == 0) {

    return 0;

  }

  if ((param_1[0x123] != 0) && (*(int *)(DAT_00d1b6d8 + 0xcd0) == 0)) {

    *(uint8_t *)((int)param_1 + 0x492) = 1;

    FUN_0085ce20(0);

    (**(code **)(*param_1 + 0x34c))();

  }

  return 1;

}
