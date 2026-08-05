// =============================================================================
// FUN_0079ca30
// -----------------------------------------------------------------------------
// Stable ID: aa_0079ca30
// Address:   0x0079ca30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079ca30 @ 0x0079ca30
// Stable ID: aa_0079ca30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0079ca30, fopen.
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

uint32_t /* width from decompiler */ __thiscall FUN_0079ca30(int *param_1,char *param_2)



{

  FILE *pFVar1;

  

  (**(code **)(*param_1 + 0x10))();

  pFVar1 = fopen(param_2,"wb");

  param_1[0x1a5] = (int)pFVar1;

  if (pFVar1 == (FILE *)0x0) {

    return 0;

  }

  *(uint8_t *)((int)param_1 + 6) = 1;

  *(uint8_t *)(param_1 + 1) = 1;

  return 1;

}
