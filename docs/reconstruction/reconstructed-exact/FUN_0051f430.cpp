// =============================================================================
// FUN_0051f430
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f430
// Address:   0x0051f430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051f430 @ 0x0051f430
// Stable ID: aa_0051f430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0051f430.
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

longlong __fastcall FUN_0051f430(int param_1)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = 0;

  if (*(int *)(param_1 + -0xe4) != 0) {

    lVar1 = (**(code **)(**(int **)(param_1 + -0xe4) + 0x10))();

  }

  if (*(int *)(param_1 + -0xc0) != 0) {

    lVar2 = (**(code **)(**(int **)(param_1 + -0xc0) + 0x10))();

    lVar1 = lVar2 + lVar1;

  }

  if (*(int *)(param_1 + -0xd0) != 0) {

    lVar2 = (**(code **)(**(int **)(param_1 + -0xd0) + 0x16c))();

    lVar1 = lVar2 + lVar1;

  }

  if (*(int *)(param_1 + -0xb50) != 0) {

    lVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xb50) + 4) + 4) + 4 +

                                 *(int *)(param_1 + -0xb50)) + 0x16c))();

    lVar1 = lVar2 + lVar1;

  }

  return lVar1;

}
