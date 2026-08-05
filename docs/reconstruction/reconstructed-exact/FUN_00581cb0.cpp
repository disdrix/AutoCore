// =============================================================================
// FUN_00581cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00581cb0
// Address:   0x00581cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581cb0 @ 0x00581cb0
// Stable ID: aa_00581cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004e8860, FUN_004e8910, FUN_00581cb0.
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

void __fastcall FUN_00581cb0(int param_1)



{

  int iVar1;

  

  if (*(int **)(param_1 + -0x88) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

    FUN_004e8910(iVar1 + 0x90,*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0xc + param_1);

    iVar1 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

    FUN_004e8860(iVar1 + 0x80,*(int *)(*(int *)(param_1 + -0x8c) + 4) + 4 + param_1);

  }

  return;

}
