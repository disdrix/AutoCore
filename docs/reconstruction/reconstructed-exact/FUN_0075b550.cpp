// =============================================================================
// FUN_0075b550
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b550
// Address:   0x0075b550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075b550 @ 0x0075b550
// Stable ID: aa_0075b550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×11, return×2.
//  - Notable callees: FUN_0096efd0×2, FUN_0073f4a0, FUN_0073f500, FUN_0075b550, _aligned_free.
//  - Return sites: 2.

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

void __fastcall FUN_0075b550(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009acc91;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a9edc8;

  local_4 = 7;

  iVar3 = param_1[0x11];

  if (iVar3 != 0) {

    piVar1 = (int *)(iVar3 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar3 + 4) + 8))();

    }

    param_1[0x11] = 0;

  }

  FUN_0073f4a0();

  piVar1 = (int *)param_1[0x14];

  if (piVar1 != (int *)0x0) {

    *piVar1 = (int)DAT_00d21944;

    DAT_00d21944 = piVar1;

  }

  piVar1 = (int *)param_1[0x15];

  if (piVar1 != (int *)0x0) {

    *piVar1 = (int)DAT_00d21944;

    DAT_00d21944 = piVar1;

  }

  local_4._0_1_ = 6;

  FUN_0096efd0();

  local_4._0_1_ = 5;

  piVar1 = (int *)param_1[0x4d];

  if (piVar1 != (int *)0x0) {

    piVar2 = piVar1 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar1 + 8))();

    }

  }

  local_4._0_1_ = 4;

  param_1[0x4b] = &PTR_FUN_00a9db18;

  piVar1 = (int *)param_1[0x4c];

  if (piVar1 != (int *)0x0) {

    piVar2 = piVar1 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar1 + 8))();

    }

  }

  local_4._0_1_ = 3;

  param_1[0x35] = &PTR_FUN_00a9db18;

  piVar1 = (int *)param_1[0x36];

  if (piVar1 != (int *)0x0) {

    piVar2 = piVar1 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar1 + 8))();

    }

  }

  if ((void *)param_1[0x30] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x30]);

  }

  param_1[0x30] = 0;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  local_4._0_1_ = 1;

  FUN_0096efd0();

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0073f500(param_1 + 4);

  _aligned_free((void *)param_1[2]);

  ExceptionList = pvStack_c;

  return;

}
