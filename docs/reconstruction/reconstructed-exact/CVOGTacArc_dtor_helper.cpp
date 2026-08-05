// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0096efd0×2, CVOGTacArc_dtor_helper, FUN_0096f510.
//  - Return sites: 1.

// =============================================================================
// CVOGTacArc_dtor_helper
// -----------------------------------------------------------------------------
// Stable ID: aa_00632900
// Address:   0x00632900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __fastcall CVOGTacArc_dtor_helper(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a8bc1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_CVOGTacArc_vdtor_009e3538;

  local_4 = 2;

  if ((void *)param_1[0xb] != (void *)0x0) {

    operator_delete__((void *)param_1[0xb]);

  }

  param_1[0xb] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[6] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[6])(1);

  }

  param_1[6] = 0;

  local_4._0_1_ = 1;

  FUN_0096f510();

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0096efd0();

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = pvStack_c;

  return;

}
