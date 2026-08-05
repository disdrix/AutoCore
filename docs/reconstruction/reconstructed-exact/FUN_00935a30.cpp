// =============================================================================
// FUN_00935a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00935a30
// Address:   0x00935a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00935a30 @ 0x00935a30
// Stable ID: aa_00935a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×12, return×9, do×3, while×3.
//  - Notable callees: FUN_00797d70×2, FUN_00796520, FUN_00796d40, FUN_007ae100, FUN_00935430, FUN_00935a30, FUN_00976f40.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ FUN_00935a30(void)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int unaff_EDI;

  

  FUN_00935430();

  piVar4 = &DAT_00d09a38;

  do {

    if ((uint32_t /* width from decompiler */ *)*piVar4 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar4)(1);

    }

    *piVar4 = 0;

    piVar4 = piVar4 + 1;

  } while ((int)piVar4 < 0xd09a4c);

  FUN_007ae100();

  FUN_00976f40();

  iVar3 = FUN_00796d40();

  FUN_00796520(0);

  piVar4 = *(int **)(iVar3 + 8);

  if (piVar4 != (int *)0x0) {

    (**(code **)(*piVar4 + 8))(piVar4);

  }

  *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = 0;

  piVar4 = (int *)**(int **)(unaff_EDI + 0xac4);

  if (piVar4 != *(int **)(unaff_EDI + 0xac4)) {

    do {

      pvVar1 = *(void **)(piVar4[2] + 0x5c);

      if (pvVar1 != (void *)0x0) {

        FUN_00797d70(pvVar1);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(piVar4[2] + 0x5c) = 0;

      if (*(void **)piVar4[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)piVar4[2]);

      }

      *(uint32_t /* width from decompiler */ *)piVar4[2] = 0;

      if ((void *)piVar4[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar4[2]);

      }

      piVar4[2] = 0;

      piVar2 = (int *)*piVar4;

      if (piVar4 != *(int **)(unaff_EDI + 0xac4)) {

        *(int **)piVar4[1] = piVar2;

        *(int *)(*piVar4 + 4) = piVar4[1];

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar4);

      }

      piVar4 = piVar2;

    } while (piVar2 != (int *)*(int *)(unaff_EDI + 0xac4));

  }

  piVar4 = (int *)**(int **)(unaff_EDI + 0xab8);

  if (piVar4 != *(int **)(unaff_EDI + 0xab8)) {

    do {

      pvVar1 = *(void **)(piVar4[2] + 0x5c);

      if (pvVar1 != (void *)0x0) {

        FUN_00797d70(pvVar1);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(piVar4[2] + 0x5c) = 0;

      if (*(void **)piVar4[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)piVar4[2]);

      }

      *(uint32_t /* width from decompiler */ *)piVar4[2] = 0;

      if ((void *)piVar4[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar4[2]);

      }

      piVar4[2] = 0;

      piVar2 = (int *)*piVar4;

      if (piVar4 != *(int **)(unaff_EDI + 0xab8)) {

        *(int **)piVar4[1] = piVar2;

        *(int *)(*piVar4 + 4) = piVar4[1];

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar4);

      }

      piVar4 = piVar2;

    } while (piVar2 != (int *)*(int *)(unaff_EDI + 0xab8));

  }

  return 0;

}
