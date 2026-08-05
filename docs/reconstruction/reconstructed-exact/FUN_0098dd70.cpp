// =============================================================================
// FUN_0098dd70
// -----------------------------------------------------------------------------
// Stable ID: aa_0098dd70
// Address:   0x0098dd70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098dd70 @ 0x0098dd70
// Stable ID: aa_0098dd70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, do×1, while×1.
//  - Notable callees: block×2, FUN_00463e30, FUN_0098dd70.
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

/* WARNING: Removing unreachable block (ram,0x0098de1d) */

/* WARNING: Removing unreachable block (ram,0x0098de20) */



void __thiscall FUN_0098dd70(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  void **ppvVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009ac86b;

  pvStack_c = ExceptionList;

  local_4 = 3;

  piVar5 = (int *)**(int **)(param_2 + 8);

  ExceptionList = &pvStack_c;

  ppvVar4 = &pvStack_c;

  uStack_10 = param_1;

  if (piVar5 != *(int **)(param_2 + 8)) {

    do {

      if ((uint32_t /* width from decompiler */ *)piVar5[3] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)piVar5[3])(1);

      }

      piVar5[3] = 0;

      if ((uint32_t /* width from decompiler */ *)piVar5[4] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)piVar5[4])(1);

      }

      piVar5[4] = 0;

      if ((uint32_t /* width from decompiler */ *)piVar5[5] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)piVar5[5])(1);

      }

      piVar5[5] = 0;

      piVar5 = (int *)*piVar5;

      ppvVar4 = ExceptionList;

    } while (piVar5 != (int *)*(int *)(param_2 + 8));

  }

  ExceptionList = ppvVar4;

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

  pvVar3 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_2 + 8) + 4) = *(int *)(param_2 + 8);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = 0;

  if (pvVar3 == *(void **)(param_2 + 8)) {

    uStack_10 = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

    if (*(int *)(param_2 + 0x14) != *(int *)(param_2 + 0x18)) {

      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x14);

    }

    FUN_00463e30(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14),9,&uStack_10);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = 1;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = 1;

    local_4._0_1_ = 2;

    piVar5 = *(int **)(param_2 + 0x38);

    if (piVar5 != (int *)0x0) {

      piVar1 = piVar5 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar5 + 8))();

      }

    }

    local_4._0_1_ = 1;

    piVar5 = *(int **)(param_2 + 0x30);

    if (piVar5 != (int *)0x0) {

      piVar1 = piVar5 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar5 + 8))();

      }

    }

    local_4 = (uint)local_4._1_3_ << 8;

    piVar5 = *(int **)(param_2 + 0x28);

    if (piVar5 != (int *)0x0) {

      piVar1 = piVar5 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar5 + 8))();

      }

    }

    if (*(void **)(param_2 + 0x14) == (void *)0x0) {

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = 0;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = 0;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = 0;

      puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

      pvVar3 = (void *)*puVar2;

      *puVar2 = puVar2;

      *(int *)(*(int *)(param_2 + 8) + 4) = *(int *)(param_2 + 8);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = 0;

      if (pvVar3 == *(void **)(param_2 + 8)) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_2 + 8));

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_2 + 0x14));

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar3);

}
