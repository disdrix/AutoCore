// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00594030
// -----------------------------------------------------------------------------
// Stable ID: aa_00594030
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00594030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×21, return×9, do×1, while×1.
//  - Notable callees: FUN_005b8340×3, FUN_0074ecf0×2, FUN_004b6960, FUN_0055a4f0, FUN_00590f00, FUN_00594030, FUN_00596770, FUN_0074e260.
//  - Return sites: 9.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00594030(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  void *pvVar3;

  int iVar4;

  int local_4;

  

  iVar4 = 0;

  if (*(void **)(param_1 + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  if (*(void **)(param_1 + 0xe0) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xe0));

  }

  pvVar2 = *(void **)(param_1 + 0xdc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_0055a4f0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = 0;

  if (*(int *)(param_1 + 0x1c4) == 0) {

    local_4 = 0;

  }

  else {

    local_4 = *(int *)(param_1 + 0x1c8) - *(int *)(param_1 + 0x1c4) >> 2;

  }

  if (0 < local_4) {

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c4) + iVar4 * 4);

      if ((DAT_00b04e88 == 0) ||

         ((uint)(DAT_00b04e90 - DAT_00b04e88 >> 2) <= (uint)((int)DAT_00b04e8c - DAT_00b04e88 >> 2))

         ) {

        FUN_00596770(DAT_00b04e8c,1,puVar1);

      }

      else {

        *DAT_00b04e8c = *puVar1;

        DAT_00b04e8c = DAT_00b04e8c + 1;

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < local_4);

  }

  if (*(void **)(param_1 + 0x1c4) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1cc) = 0;

    if (*(int *)(param_1 + 0x14) == 0) {

      FUN_00590f00(0,0);

    }

    else {

      FUN_004b6960(param_1,1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

    if (*(int *)(param_1 + 0x91c) != 0) {

      if (*(int *)(param_1 + 0x918) != 0) {

        FUN_0074e260(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x91c) + 0x8c));

      }

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x91c) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x91c))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x91c) = 0;

    }

    if (*(int **)(param_1 + 0x18) != (int *)0x0) {

      if (*(int *)(param_1 + 0x20) != 0) {

        (**(code **)(**(int **)(param_1 + 0x18) + 0x10))(*(int *)(param_1 + 0x20));

      }

      if (*(int *)(param_1 + 0x24) != 0) {

        (**(code **)(**(int **)(param_1 + 0x18) + 0x10))(*(int *)(param_1 + 0x24));

      }

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x18) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x18))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    }

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x1c) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x1c))(1);

    }

    pvVar2 = *(void **)(param_1 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    if (pvVar2 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

    pvVar2 = *(void **)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    if (pvVar2 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    if (*(int *)(param_1 + 0x914) == 0) {

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x914) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x914))(1);

      }

      pvVar3 = *(void **)(param_1 + 0x6b0);

      pvVar2 = (void *)(param_1 + 0x3bc);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x914) = 0;

      if (pvVar3 == pvVar2) {

        FUN_005b8340();

        *(void **)(param_1 + 0x6b0) = pvVar2;

        *(void **)(param_1 + 0x6ac) = pvVar2;

        FUN_005b8340();

        return;

      }

      FUN_005b8340();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(*(int *)(param_1 + 0x914) + 0x78));

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x1c4));

}
