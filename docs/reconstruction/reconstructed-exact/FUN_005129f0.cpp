// =============================================================================
// FUN_005129f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005129f0
// Address:   0x005129f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005129f0 @ 0x005129f0
// Stable ID: aa_005129f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_005129f0.
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

void __thiscall FUN_005129f0(int param_1,int *param_2)



{

  int iVar1;

  

  param_1 = param_1 + 0x28;

  iVar1 = 3;

  do {

    (**(code **)(*param_2 + 0x14))(param_1,8);

    param_1 = param_1 + 8;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
