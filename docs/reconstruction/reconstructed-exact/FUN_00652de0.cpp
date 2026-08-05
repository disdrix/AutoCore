// =============================================================================
// FUN_00652de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00652de0
// Address:   0x00652de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652de0 @ 0x00652de0
// Stable ID: aa_00652de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00652de0.
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

void __fastcall FUN_00652de0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x20);

  while (iVar1 = iVar1 + -1, -1 < iVar1) {

    (**(code **)(**(int **)(param_1 + 0x10) + 0x10))

              (*(int *)(*(int *)(param_1 + 0x1c) + iVar1 * 4) + 0xc,0,DAT_00d034f8);

  }

  return;

}
