// =============================================================================
// FUN_005fc240
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc240
// Address:   0x005fc240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fc240 @ 0x005fc240
// Stable ID: aa_005fc240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004f7ec0, FUN_005081f0, FUN_005fc240.
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

void __fastcall FUN_005fc240(int param_1)



{

  int iVar1;

  

  if (*(int **)(param_1 + 0x18) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1d4))();

    if ((iVar1 != 0) && (*(int *)(param_1 + 0x10) < 1)) {

      FUN_004f7ec0(1);

    }

  }

  FUN_005081f0();

  return;

}
