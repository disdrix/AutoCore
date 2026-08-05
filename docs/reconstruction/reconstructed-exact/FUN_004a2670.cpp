// =============================================================================
// FUN_004a2670
// -----------------------------------------------------------------------------
// Stable ID: aa_004a2670
// Address:   0x004a2670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a2670 @ 0x004a2670
// Stable ID: aa_004a2670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×3, do×1.
//  - Notable callees: FUN_004a2670, FUN_004a80c0, FUN_004b85d0, FUN_004b99c0.
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

void __fastcall FUN_004a2670(int *param_1)



{

  char cVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  

  piVar5 = (int *)**(int **)(*param_1 + 4);

  if (piVar5 != *(int **)(*param_1 + 4)) {

    do {

      FUN_004b85d0();

      pvVar2 = (void *)piVar5[4];

      if (pvVar2 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      if (*(char *)((int)piVar5 + 0x15) == '\0') {

        piVar3 = (int *)piVar5[2];

        if (*(char *)((int)piVar3 + 0x15) == '\0') {

          cVar1 = *(char *)(*piVar3 + 0x15);

          piVar5 = piVar3;

          piVar3 = (int *)*piVar3;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar3 + 0x15);

            piVar5 = piVar3;

            piVar3 = (int *)*piVar3;

          }

        }

        else {

          cVar1 = *(char *)(piVar5[1] + 0x15);

          piVar4 = (int *)piVar5[1];

          piVar3 = piVar5;

          while ((piVar5 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar5[2]))) {

            cVar1 = *(char *)(piVar5[1] + 0x15);

            piVar4 = (int *)piVar5[1];

            piVar3 = piVar5;

          }

        }

      }

    } while (piVar5 != *(int **)(*param_1 + 4));

  }

  pvVar2 = (void *)*param_1;

  if (pvVar2 != (void *)0x0) {

    FUN_004a80c0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *param_1 = 0;

  return;

}
