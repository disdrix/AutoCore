// =============================================================================
// FUN_006f5630
// -----------------------------------------------------------------------------
// Stable ID: aa_006f5630
// Address:   0x006f5630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f5630 @ 0x006f5630
// Stable ID: aa_006f5630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_006f5630.
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

void FUN_006f5630(int param_1,int *param_2,int *param_3)



{

  int iVar1;

  

  iVar1 = *param_2;

  while (iVar1 != 0) {

    iVar1 = *param_2;

    *param_2 = iVar1 + -1;

    (**(code **)(*param_3 + 8))(*(uint16_t *)((iVar1 + -1) * 0x30 + 0x1c + param_1));

    iVar1 = *param_2;

  }

  return;

}
