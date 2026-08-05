// =============================================================================
// FUN_004ac290
// -----------------------------------------------------------------------------
// Stable ID: aa_004ac290
// Address:   0x004ac290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ac290 @ 0x004ac290
// Stable ID: aa_004ac290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×13, return×8.
//  - Notable callees: FUN_0096efd0×6, FUN_004ac290, FUN_004afa10, FUN_0096f510.
//  - Return sites: 8.

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

void __fastcall FUN_004ac290(int param_1)



{

  void *pvVar1;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a130d;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  local_10 = param_1;

  if (*(void **)(param_1 + 0x3dc) != (void *)0x0) {

    ExceptionList = &pvStack_c;

    operator_delete__(*(void **)(param_1 + 0x3dc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dc) = 0;

  if (*(void **)(param_1 + 0x3e0) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x3e0));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3e0) = 0;

  if (*(void **)(param_1 + 0x334) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x334));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x334) = 0;

  if (*(void **)(param_1 + 0x38c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x38c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38c) = 0;

  if (*(void **)(param_1 + 0x3a4) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x3a4));

  }

  pvVar1 = *(void **)(param_1 + 0x394);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3a4) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x394) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x390) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x390))(1);

  }

  pvVar1 = *(void **)(param_1 + 0x3e4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x390) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 1000);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3e4) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x3ec);

  *(uint32_t /* width from decompiler */ *)(param_1 + 1000) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x3f0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3ec) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x3f4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f0) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  pvVar1 = *(void **)(param_1 + 0x3f8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f4) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f8) = 0;

  local_4 = 0xffffffff;

  FUN_004afa10(&local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0x3d0),*(uint32_t /* width from decompiler */ **)(param_1 + 0x3d0));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x3d0));

}
