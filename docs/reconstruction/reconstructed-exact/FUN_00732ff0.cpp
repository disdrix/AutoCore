// =============================================================================
// FUN_00732ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00732ff0
// Address:   0x00732ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00732ff0 @ 0x00732ff0
// Stable ID: aa_00732ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×18, return×10, for×2.
//  - Notable callees: CONCAT31, FUN_00732f50, FUN_00732ff0.
//  - Return sites: 10.

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

void __fastcall FUN_00732ff0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac983;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00aa5f18;

  local_4 = 6;

  FUN_00732f50();

  piVar1 = (int *)param_1[0xc];

  for (piVar2 = (int *)param_1[0xb]; piVar2 != piVar1; piVar2 = piVar2 + 1) {

    if ((uint32_t /* width from decompiler */ *)*piVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)(1);

    }

  }

  if ((void *)param_1[0xb] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xb]);

  }

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  if ((void *)param_1[3] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  if (param_1[0x16] != 0) {

    piVar1 = (int *)param_1[0x10];

    for (piVar2 = (int *)param_1[0xf]; piVar2 != piVar1; piVar2 = piVar2 + 1) {

      if ((uint32_t /* width from decompiler */ *)*piVar2 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar2)(1);

      }

    }

    if ((void *)param_1[0xf] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0xf]);

    }

    param_1[0xf] = 0;

    param_1[0x10] = 0;

    param_1[0x11] = 0;

    if ((void *)param_1[7] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[7]);

    }

    param_1[7] = 0;

    param_1[8] = 0;

    param_1[9] = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x16] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x16])(1);

    }

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0x17] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x17])(1);

  }

  piVar2 = (int *)param_1[0x18];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    param_1[0x18] = 0;

  }

  local_4 = CONCAT31(local_4._1_3_,5);

  piVar2 = (int *)param_1[0x18];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  if ((void *)param_1[0x13] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x13]);

  }

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  if ((void *)param_1[0xf] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xf]);

  }

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  if ((void *)param_1[0xb] == (void *)0x0) {

    param_1[0xb] = 0;

    param_1[0xc] = 0;

    param_1[0xd] = 0;

    if ((void *)param_1[7] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[7]);

    }

    param_1[7] = 0;

    param_1[8] = 0;

    param_1[9] = 0;

    if ((void *)param_1[3] == (void *)0x0) {

      param_1[3] = 0;

      param_1[4] = 0;

      param_1[5] = 0;

      *param_1 = &PTR_LAB_009d3aa0;

      ExceptionList = pvStack_c;

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0xb]);

}
