// =============================================================================
// FUN_00522290
// -----------------------------------------------------------------------------
// Stable ID: aa_00522290
// Address:   0x00522290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522290 @ 0x00522290
// Stable ID: aa_00522290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×6, return×5.
//  - Notable callees: FUN_00404c90, FUN_004c3940, FUN_00522290.
//  - Return sites: 5.

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

int __fastcall FUN_00522290(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + -0xd9c) + 4) + param_1;

  if (*(int *)(iVar1 + -0xcf8) != 0) {

    if (*(char *)(*(int *)(iVar1 + -0xcf8) + 0xf5) != '\0') {

      if (*(int *)(param_1 + -0xd98) != 0) {

        return *(int *)(*(int *)(param_1 + -0xd98) + 0x3c) + 0xb0;

      }

      return *(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd1c + param_1;

    }

    if (*(char *)(param_1 + -0x8af) == '\0') {

      if ((*(char *)(param_1 + -0x6e7) != '\0') && (*(int **)(iVar1 + -0xcfc) != (int *)0x0)) {

        iVar1 = (**(code **)(**(int **)(iVar1 + -0xcfc) + 0x1c8))();

        if (iVar1 != 0) {

          (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcfc + param_1) +

                      0x1c8))();

          iVar1 = FUN_00404c90();

          return iVar1;

        }

      }

      iVar1 = FUN_004c3940();

      return iVar1;

    }

  }

  return iVar1 + -0xd1c;

}
