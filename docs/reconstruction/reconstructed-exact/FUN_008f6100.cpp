// =============================================================================
// FUN_008f6100
// -----------------------------------------------------------------------------
// Stable ID: aa_008f6100
// Address:   0x008f6100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f6100 @ 0x008f6100
// Stable ID: aa_008f6100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_008f6100.
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

void FUN_008f6100(void)



{

  int iVar1;

  char cVar2;

  int unaff_ESI;

  char unaff_retaddr;

  

  if (*(int *)(unaff_ESI + 0xe80) != 0) {

    if ((*(int *)(unaff_ESI + 0x10ec) - *(int *)(unaff_ESI + 0x10e4) < *(int *)(unaff_ESI + 0x10f0))

       && (*(int *)(unaff_ESI + 0x10ec) != *(int *)(unaff_ESI + 0x10e4) &&

           -1 < *(int *)(unaff_ESI + 0x10ec) - *(int *)(unaff_ESI + 0x10e4))) {

      (**(code **)(**(int **)(unaff_ESI + 0xe80) + 0xd4))(1);

    }

    else {

      (**(code **)(**(int **)(unaff_ESI + 0xe80) + 0xd4))(0);

    }

    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0xe80) + 0xd8))();

    if (cVar2 != '\0') {

      if (*(int *)(*(int *)(unaff_ESI + 0xe80) + 0x94c) != 0) {

        if ((*(int *)(unaff_ESI + 0x10e4) - *(int *)(unaff_ESI + 0x10ec)) +

            *(int *)(unaff_ESI + 0x10f0) == *(int *)(unaff_ESI + 0x10f4)) {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xe80) + 0x94c) + 0xd4))(0);

        }

        else {

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0xe80) + 0x94c) + 0xd4))(1);

        }

      }

      iVar1 = *(int *)(unaff_ESI + 0xe80);

      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x950) != 0)) {

        (**(code **)(**(int **)(iVar1 + 0x950) + 0xd4))(0 < *(int *)(unaff_ESI + 0x10f4));

      }

      iVar1 = ((*(int *)(unaff_ESI + 0x10e4) - *(int *)(unaff_ESI + 0x10ec)) + 9 +

              *(int *)(unaff_ESI + 0x10f0)) / 10;

      if ((0 < iVar1) &&

         ((**(code **)(**(int **)(unaff_ESI + 0xe80) + 0x460))(g_flOne / (float)iVar1),

         unaff_retaddr != '\0')) {

        (**(code **)(**(int **)(unaff_ESI + 0xe80) + 0x454))

                  (g_flOne - (float)*(int *)(unaff_ESI + 0x10f4) /

                             (float)((*(int *)(unaff_ESI + 0x10e4) - *(int *)(unaff_ESI + 0x10ec)) +

                                    *(int *)(unaff_ESI + 0x10f0)),0);

      }

    }

    (**(code **)(**(int **)(unaff_ESI + 0xe80) + 0x34c))();

  }

  return;

}
