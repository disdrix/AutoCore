// =============================================================================
// FUN_00522340
// -----------------------------------------------------------------------------
// Stable ID: aa_00522340
// Address:   0x00522340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522340 @ 0x00522340
// Stable ID: aa_00522340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00404a20, FUN_004c39a0, FUN_00522340.
//  - Return sites: 4.

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

int __fastcall FUN_00522340(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(param_1 + -0xd9c) + 4);

  if (*(char *)(*(int *)(iVar2 + -0xcf8 + param_1) + 0xf5) == '\0') {

    if ((*(char *)(param_1 + -0x6e7) != '\0') &&

       (piVar1 = *(int **)(iVar2 + param_1 + -0xcfc), piVar1 != (int *)0x0)) {

      iVar2 = (**(code **)(*piVar1 + 0x1c8))();

      if (iVar2 != 0) {

        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcfc + param_1) + 0x1c8

                    ))();

        iVar2 = FUN_00404a20();

        return iVar2;

      }

    }

    iVar2 = FUN_004c39a0();

    return iVar2;

  }

  if (*(int *)(param_1 + -0xd98) != 0) {

    return *(int *)(*(int *)(param_1 + -0xd98) + 0x3c) + 0x30;

  }

  return *(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd0c + param_1;

}
