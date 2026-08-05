// =============================================================================
// FUN_0075f560
// -----------------------------------------------------------------------------
// Stable ID: aa_0075f560
// Address:   0x0075f560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075f560 @ 0x0075f560
// Stable ID: aa_0075f560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~152 non-empty decompiler lines.
//  - Control keywords: return×20, if×19.
//  - Notable callees: CONCAT31, FUN_0073bbd0, FUN_0073c040, FUN_0073de30, FUN_00746380, FUN_0075eee0, FUN_0075f560, FUN_0096a340.
//  - Return sites: 20.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_0075f560(int param_1)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b2667;

  local_c = ExceptionList;

  local_4 = 1;

  ExceptionList = &local_c;

  FUN_0075eee0();

  pvVar1 = *(void **)(param_1 + 0x770);

  if (pvVar1 != (void *)0x0) {

    FUN_009872f0(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x770) = 0;

  pvVar1 = *(void **)(param_1 + 0x76c);

  if (pvVar1 != (void *)0x0) {

    FUN_00746380(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x76c) = 0;

  pvVar1 = *(void **)(param_1 + 0x768);

  if (pvVar1 != (void *)0x0) {

    if (*(void **)((int)pvVar1 + 0x4c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar1 + 0x4c));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x4c) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x54) = 0;

    if (*(void **)((int)pvVar1 + 0x38) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar1 + 0x38));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x40) = 0;

    _DAT_00d1f64c = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x768) = 0;

  pvVar1 = *(void **)(param_1 + 0x73c);

  if (pvVar1 != (void *)0x0) {

    FUN_00986270(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x73c) = 0;

  pvVar1 = *(void **)(param_1 + 0x740);

  if (pvVar1 != (void *)0x0) {

    FUN_0073c040(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x740) = 0;

  pvVar1 = *(void **)(param_1 + 0x744);

  if (pvVar1 != (void *)0x0) {

    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar1 + 4));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

    DAT_00d1f630 = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x744) = 0;

  if (*(void **)(param_1 + 0x748) != (void *)0x0) {

    _DAT_00d1f654 = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x748));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x748) = 0;

  pvVar1 = *(void **)(param_1 + 0x74c);

  if (pvVar1 != (void *)0x0) {

    FUN_00986de0(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74c) = 0;

  pvVar1 = *(void **)(param_1 + 0x750);

  if (pvVar1 != (void *)0x0) {

    FUN_00985e90(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x750) = 0;

  pvVar1 = *(void **)(param_1 + 0x758);

  if (pvVar1 != (void *)0x0) {

    FUN_0073bbd0(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x758) = 0;

  pvVar1 = *(void **)(param_1 + 0x75c);

  if (pvVar1 != (void *)0x0) {

    if (*(void **)((int)pvVar1 + 0x14) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar1 + 0x14));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x1c) = 0;

    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)((int)pvVar1 + 4));

    }

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

    DAT_00d1f640 = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x75c) = 0;

  pvVar1 = *(void **)(param_1 + 0x760);

  if (pvVar1 != (void *)0x0) {

    local_4._0_1_ = 2;

    FUN_0096a340();

    local_4 = CONCAT31(local_4._1_3_,1);

    DAT_00d1f05c = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x760) = 0;

  pvVar1 = *(void **)(param_1 + 0x764);

  if (pvVar1 != (void *)0x0) {

    FUN_0073de30(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x764) = 0;

  pvVar1 = *(void **)(param_1 + 0x754);

  if (pvVar1 != (void *)0x0) {

    FUN_0096e830(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x754) = 0;

  DAT_00d1f048 = 0;

  DAT_00d1f044 = 0;

  ExceptionList = local_c;

  return;

}
