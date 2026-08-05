// =============================================================================
// FUN_00522460
// -----------------------------------------------------------------------------
// Stable ID: aa_00522460
// Address:   0x00522460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522460 @ 0x00522460
// Stable ID: aa_00522460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004c38f0, FUN_00522460.
//  - Return sites: 3.

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

void __fastcall FUN_00522460(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(param_1 + -0xd9c) + 4);

  if (*(char *)(*(int *)(iVar2 + -0xcf8 + param_1) + 0xf5) != '\0') {

                    /* WARNING: Could not recover jumptable at 0x00522497. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c + param_1) + 0x1c8))();

    return;

  }

  if ((*(char *)(param_1 + -0x6e7) != '\0') &&

     (piVar1 = *(int **)(iVar2 + param_1 + -0xcfc), piVar1 != (int *)0x0)) {

    iVar2 = (**(code **)(*piVar1 + 0x1c8))();

    if (iVar2 != 0) {

      iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcfc + param_1) +

                          0x1c8))();

                    /* WARNING: Could not recover jumptable at 0x005224e1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1c8))();

      return;

    }

  }

  FUN_004c38f0();

  return;

}
