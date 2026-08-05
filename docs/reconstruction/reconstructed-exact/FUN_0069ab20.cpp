// =============================================================================
// FUN_0069ab20
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ab20
// Address:   0x0069ab20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069ab20 @ 0x0069ab20
// Stable ID: aa_0069ab20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_0069ab20.
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

void FUN_0069ab20(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  

  while ((param_3 < param_2 &&

         (iVar1 = (param_2 + -1) / 2,

         *(float *)(param_4 + 0x2c) < *(float *)(*(int *)(param_1 + iVar1 * 4) + 0x2c)))) {

    *(uint32_t /* width from decompiler */ *)(param_1 + param_2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4);

    param_2 = iVar1;

  }

  *(int *)(param_1 + param_2 * 4) = param_4;

  return;

}
