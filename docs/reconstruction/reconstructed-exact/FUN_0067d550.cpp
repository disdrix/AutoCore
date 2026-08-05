// =============================================================================
// FUN_0067d550
// -----------------------------------------------------------------------------
// Stable ID: aa_0067d550
// Address:   0x0067d550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067d550 @ 0x0067d550
// Stable ID: aa_0067d550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~172 non-empty decompiler lines.
//  - Control keywords: if×31, return×12, while×3.
//  - Notable callees: FUN_0067ca70, FUN_0067d550, FUN_0067fef0.
//  - Return sites: 12.

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

void __fastcall FUN_0067d550(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a97aa;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009e9174;

  local_4 = 9;

  if ((void *)param_1[0xa8f] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xa8f]);

  }

  if ((int *)param_1[0xa61] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xa61] + 0x10))();

    if ((uint32_t /* width from decompiler */ *)param_1[0xa61] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xa61])(1);

    }

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0xa85] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xa85])(1);

  }

  if ((param_1[0xa4a] != 0) &&

     (iStack_10 = (int)(param_1[0xa4b] - param_1[0xa4a]) >> 2, iStack_10 != 0)) {

    piVar2 = *(int **)(param_1[0xa4b] + -4);

    if (param_1[0xa4a] != 0) {

      iStack_10 = (int)(param_1[0xa4b] - param_1[0xa4a]) >> 2;

      if (iStack_10 != 0) {

        param_1[0xa4b] = param_1[0xa4b] + -4;

      }

    }

    puVar3 = (uint32_t /* width from decompiler */ *)*piVar2;

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar2);

  }

  while ((param_1[0xa4e] != 0 &&

         (iStack_10 = (int)(param_1[0xa4f] - param_1[0xa4e]) >> 2, iStack_10 != 0))) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1[0xa4f] + -4);

    if (param_1[0xa4e] != 0) {

      iStack_10 = (int)(param_1[0xa4f] - param_1[0xa4e]) >> 2;

      if (iStack_10 != 0) {

        param_1[0xa4f] = param_1[0xa4f] + -4;

      }

    }

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      operator_delete__((void *)*puVar3);

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar3);

    }

  }

  if ((param_1[0xa5a] != 0) &&

     (iStack_10 = (int)(param_1[0xa5b] - param_1[0xa5a]) >> 2, iStack_10 != 0)) {

    piVar2 = *(int **)(param_1[0xa5b] + -4);

    if (param_1[0xa5a] != 0) {

      iStack_10 = (int)(param_1[0xa5b] - param_1[0xa5a]) >> 2;

      if (iStack_10 != 0) {

        param_1[0xa5b] = param_1[0xa5b] + -4;

      }

    }

    puVar3 = (uint32_t /* width from decompiler */ *)*piVar2;

    piVar1 = puVar3 + 5;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)*puVar3)(1);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar2);

  }

  if ((param_1[0xa56] != 0) &&

     (iStack_10 = (int)(param_1[0xa57] - param_1[0xa56]) >> 2, iStack_10 != 0)) {

    piVar2 = *(int **)(param_1[0xa57] + -4);

    if (param_1[0xa56] != 0) {

      iStack_10 = (int)(param_1[0xa57] - param_1[0xa56]) >> 2;

      if (iStack_10 != 0) {

        param_1[0xa57] = param_1[0xa57] + -4;

      }

    }

    puVar3 = (uint32_t /* width from decompiler */ *)*piVar2;

    piVar1 = puVar3 + 5;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)*puVar3)(1);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar2);

  }

  while ((param_1[0xa52] != 0 &&

         (iStack_10 = (int)(param_1[0xa53] - param_1[0xa52]) >> 2, iStack_10 != 0))) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1[0xa53] + -4);

    if (param_1[0xa52] != 0) {

      iStack_10 = (int)(param_1[0xa53] - param_1[0xa52]) >> 2;

      if (iStack_10 != 0) {

        param_1[0xa53] = param_1[0xa53] + -4;

      }

    }

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

  }

  while ((param_1[0xa5e] != 0 &&

         (iStack_10 = (int)(param_1[0xa5f] - param_1[0xa5e]) >> 2, iStack_10 != 0))) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1[0xa5f] + -4);

    if (param_1[0xa5e] != 0) {

      iStack_10 = (int)(param_1[0xa5f] - param_1[0xa5e]) >> 2;

      if (iStack_10 != 0) {

        param_1[0xa5f] = param_1[0xa5f] + -4;

      }

    }

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

  }

  if ((void *)param_1[0xa5e] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xa5e]);

  }

  param_1[0xa5e] = 0;

  param_1[0xa5f] = 0;

  param_1[0xa60] = 0;

  if ((void *)param_1[0xa5a] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xa5a]);

  }

  param_1[0xa5a] = 0;

  param_1[0xa5b] = 0;

  param_1[0xa5c] = 0;

  if ((void *)param_1[0xa56] == (void *)0x0) {

    param_1[0xa56] = 0;

    param_1[0xa57] = 0;

    param_1[0xa58] = 0;

    if ((void *)param_1[0xa52] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0xa52]);

    }

    param_1[0xa52] = 0;

    param_1[0xa53] = 0;

    param_1[0xa54] = 0;

    if ((void *)param_1[0xa4e] == (void *)0x0) {

      param_1[0xa4e] = 0;

      param_1[0xa4f] = 0;

      param_1[0xa50] = 0;

      if ((void *)param_1[0xa4a] == (void *)0x0) {

        param_1[0xa4a] = 0;

        param_1[0xa4b] = 0;

        param_1[0xa4c] = 0;

        local_4._0_1_ = 2;

        FUN_0067ca70();

        local_4._0_1_ = 1;

        _eh_vector_destructor_iterator_

                  (param_1 + 0x45,0x28,0x100,(_func_void_void_ptr *)&LAB_0067c690);

        local_4 = (uint)local_4._1_3_ << 8;

        FUN_0067fef0(&iStack_10,*(uint32_t /* width from decompiler */ *)param_1[0x43],(uint32_t /* width from decompiler */ *)param_1[0x43]);

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)param_1[0x43]);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0xa4a]);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xa4e]);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0xa56]);

}
