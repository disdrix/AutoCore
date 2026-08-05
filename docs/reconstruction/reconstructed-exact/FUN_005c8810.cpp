// =============================================================================
// FUN_005c8810
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8810
// Address:   0x005c8810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c8810 @ 0x005c8810
// Stable ID: aa_005c8810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_005c8810.
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

void __thiscall FUN_005c8810(int param_1,float param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0xac);

  while (iVar1 != 0) {

    param_1 = *(int *)(param_1 + 0xac);

    iVar1 = *(int *)(param_1 + 0xac);

  }

  *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) + param_2;

  return;

}
