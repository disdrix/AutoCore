// =============================================================================
// FUN_00670a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00670a70
// Address:   0x00670a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00670a70 @ 0x00670a70
// Stable ID: aa_00670a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CONCAT31, FUN_00670a70, FUN_00671950.
//  - Return sites: 1.

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

void __fastcall FUN_00670a70(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a9093;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009e7fd0;

  local_4 = 4;

  if ((int *)param_1[0xb] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xb] + 8))(1000);

  }

  if ((int *)param_1[0xc] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xc] + 8))(1000);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0xe] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xe])(1);

  }

  param_1[0xe] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0xb] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xb])(1);

  }

  param_1[0xb] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0xc] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xc])(1);

  }

  param_1[0xc] = 0;

  if ((void *)param_1[0x7e] != (void *)0x0) {

    operator_delete__((void *)param_1[0x7e]);

    param_1[0x7e] = 0;

  }

  local_4 = CONCAT31(local_4._1_3_,3);

  FUN_00671950();

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x88]);

}
