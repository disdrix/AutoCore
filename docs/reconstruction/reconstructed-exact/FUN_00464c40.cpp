// =============================================================================
// FUN_00464c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00464c40
// Address:   0x00464c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00464c40 @ 0x00464c40
// Stable ID: aa_00464c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: CONCAT31, FUN_00414b60, FUN_00464c40, FUN_00748600.
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

void __fastcall FUN_00464c40(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bdd1e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00aa465c;

  param_1[1] = &PTR_LAB_00aa4650;

  piVar2 = DAT_00d1eebc;

  local_4 = 5;

  if (DAT_00d1eebc != (int *)0x0) {

    piVar1 = DAT_00d1eebc + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    DAT_00d1eebc = (int *)0x0;

  }

  local_4 = CONCAT31(local_4._1_3_,4);

  param_1[0x43] = &PTR_FUN_00a9db18;

  piVar2 = (int *)param_1[0x44];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  if ((void *)param_1[0x40] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x40]);

  }

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  if ((void *)param_1[0x3c] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3c]);

  }

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  if ((void *)param_1[0x38] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x38]);

  }

  param_1[0x38] = 0;

  param_1[0x39] = 0;

  param_1[0x3a] = 0;

  FUN_00414b60();

  local_4 = 0xffffffff;

  FUN_00748600();

  ExceptionList = pvStack_c;

  return;

}
