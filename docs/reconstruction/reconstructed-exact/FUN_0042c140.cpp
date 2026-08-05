// =============================================================================
// FUN_0042c140
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c140
// Address:   0x0042c140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042c140 @ 0x0042c140
// Stable ID: aa_0042c140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×12, while×6, return×6, do×1.
//  - Notable callees: free×4, FUN_00784f20×2, FUN_0042c140, FUN_0042c540, FUN_0042fe60.
//  - Return sites: 6.

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

void __fastcall FUN_0042c140(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  void *pvVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int iVar7;

  

  iVar6 = param_1[3];

  *param_1 = &PTR_LAB_00a9b350;

  while (iVar6 != 0) {

    FUN_0042fe60();

    iVar6 = param_1[3];

  }

  iVar6 = param_1[9];

  while (iVar6 != 0) {

    FUN_0042c540();

    iVar6 = param_1[9];

  }

  iVar6 = 0;

  if (0 < (int)param_1[0xc]) {

    iVar7 = 0;

    do {

      pvVar2 = *(void **)(iVar7 + param_1[0xe]);

      if (pvVar2 != (void *)0x0) {

        FUN_00784f20();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      iVar6 = iVar6 + 1;

      iVar7 = iVar7 + 0x1c;

    } while (iVar6 < (int)param_1[0xc]);

  }

  FUN_00784f20();

  pvVar2 = (void *)param_1[0x18];

  if (pvVar2 == (void *)0x0) {

    pvVar2 = (void *)param_1[0x19];

    if (pvVar2 == (void *)0x0) {

      piVar3 = (int *)param_1[0x10];

      if (piVar3 != (int *)0x0) {

        piVar1 = piVar3 + 2;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar3 + 8))();

        }

      }

      piVar3 = (int *)param_1[0xf];

      if (piVar3 != (int *)0x0) {

        piVar1 = piVar3 + 2;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar3 + 8))();

        }

      }

      free((void *)param_1[0xe]);

      free((void *)param_1[0xb]);

      free((void *)param_1[8]);

      free((void *)param_1[5]);

      *param_1 = &PTR_LAB_00a9b1dc;

      puVar5 = (uint32_t /* width from decompiler */ *)param_1[1];

      while (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

        *puVar5 = 0;

        puVar5[1] = 0;

        puVar5[2] = 0;

        puVar5 = puVar4;

      }

      return;

    }

    iVar6 = *(int *)((int)pvVar2 + 8);

    while( true ) {

      if (iVar6 == 0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      piVar3 = *(int **)((int)pvVar2 + 8);

      iVar6 = *piVar3;

      if (piVar3 != (int *)0x0) break;

      *(int *)((int)pvVar2 + 8) = iVar6;

    }

    operator_delete__((void *)piVar3[1]);

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar3);

  }

  iVar6 = *(int *)((int)pvVar2 + 8);

  while( true ) {

    if (iVar6 == 0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

    piVar3 = *(int **)((int)pvVar2 + 8);

    iVar6 = *piVar3;

    if (piVar3 != (int *)0x0) break;

    *(int *)((int)pvVar2 + 8) = iVar6;

  }

  operator_delete__((void *)piVar3[1]);

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar3);

}
