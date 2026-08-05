// =============================================================================
// FUN_0055d750
// -----------------------------------------------------------------------------
// Stable ID: aa_0055d750
// Address:   0x0055d750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055d750 @ 0x0055d750
// Stable ID: aa_0055d750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×9, return×5.
//  - Notable callees: FUN_007567b0×5, FUN_00988860×5, FUN_00988710×4, FUN_0055d750.
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

void __fastcall FUN_0055d750(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  

  if (*(char *)(param_1 + 8) != '\0') {

    (**(code **)(**(int **)(DAT_00d1f058 + 0x2c) + 0xc))(*(uint32_t /* width from decompiler */ *)(param_1[4] + 0xa0));

    (**(code **)(*(int *)param_1[4] + 0x10))();

    FUN_007567b0(0,0);

    *(uint32_t /* width from decompiler */ *)(param_1[4] + 0xc0) = 3;

    *(uint8_t *)(param_1 + 8) = 0;

  }

  FUN_00988860(param_1[4]);

  FUN_00988860(param_1[5]);

  FUN_00988860(param_1[6]);

  FUN_00988860(param_1[7]);

  FUN_00988860(param_1[4]);

  FUN_007567b0(0,0);

  FUN_007567b0(0,0);

  FUN_007567b0(0,0);

  FUN_007567b0(0,0);

  pvVar1 = (void *)*param_1;

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *param_1 = 0;

  pvVar1 = (void *)param_1[1];

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[1] = 0;

  pvVar1 = (void *)param_1[2];

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[2] = 0;

  pvVar1 = (void *)param_1[3];

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[3] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[4] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[4])(1);

  }

  param_1[4] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[5] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[5])(1);

  }

  param_1[5] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[6] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[6])(1);

  }

  param_1[6] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[7] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[7])(1);

  }

  param_1[7] = 0;

  return;

}
