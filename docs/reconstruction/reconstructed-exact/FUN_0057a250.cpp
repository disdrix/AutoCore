// =============================================================================
// FUN_0057a250
// -----------------------------------------------------------------------------
// Stable ID: aa_0057a250
// Address:   0x0057a250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057a250 @ 0x0057a250
// Stable ID: aa_0057a250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0057a250.
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

uint64_t __thiscall FUN_0057a250(int param_1,int param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x1c) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 2;

  }

  if (iVar1 <= param_2) {

    return 0xffffffffffffffff;

  }

  return **(uint64_t **)(*(int *)(param_1 + 0x1c) + param_2 * 4);

}
