// =============================================================================
// FUN_00492be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00492be0
// Address:   0x00492be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00492be0 @ 0x00492be0
// Stable ID: aa_00492be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CONCAT31, FUN_0048ea00, FUN_0048eb10, FUN_00492be0, FUN_00494060, FUN_00498260.
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

void __fastcall FUN_00492be0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  uint8_t auStack_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a0a76;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009c7928;

  local_4 = 0xc;

  param_1[0x34] = 0;

  FUN_0048eb10();

  FUN_0048ea00();

  param_1[0x30] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x32] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x32])(1);

  }

  param_1[0x32] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x31] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x31])(1);

  }

  param_1[0x31] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x33] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x33])(1);

  }

  pvVar1 = (void *)param_1[0x40];

  param_1[0x33] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_00498260();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x40] = 0;

  local_4 = CONCAT31(local_4._1_3_,0xb);

  FUN_00494060(auStack_10,*(uint32_t /* width from decompiler */ *)param_1[100],(uint32_t /* width from decompiler */ *)param_1[100]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[100]);

}
