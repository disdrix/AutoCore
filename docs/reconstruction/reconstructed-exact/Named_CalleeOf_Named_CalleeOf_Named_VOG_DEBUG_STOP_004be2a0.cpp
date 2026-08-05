// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004be2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004be2a0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004be2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×8, return×5.
//  - Notable callees: FUN_0074b580×3, FUN_00763f60×3, FUN_004be2a0×2, CONCAT31, FUN_004bf740.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004be2a0(int *param_1)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a1833;

  local_c = ExceptionList;

  local_4 = 9;

  ExceptionList = &local_c;

  if ((char)param_1[0x174] != '\0') {

    ExceptionList = &local_c;

    param_1[6] = param_1[5];

    if (param_1[6] != 0) {

      pvVar1 = *(void **)(param_1[6] + 0xc);

      if ((*(int *)((int)pvVar1 + 4) != 0) &&

         (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((int)pvVar1 + 4) + 4) + 4) + 0xac +

                           *(int *)((int)pvVar1 + 4)) + 0x38) == 1)) {

        (**(code **)(**(int **)((int)pvVar1 + 4) + 8))();

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    FUN_004bf740();

  }

  DAT_00b03734 = DAT_00b03734 + -1;

  *(int *)(*param_1 + 4) = param_1[1];

  *(int *)param_1[1] = *param_1;

  pvVar1 = DAT_00b03730;

  DAT_00b0373c = DAT_00b0373c + -1;

  if (DAT_00b0373c == 0) {

    if (DAT_00b03730 != (void *)0x0) {

      Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004be2a0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    DAT_00b03730 = (void *)0x0;

  }

  else if (DAT_00b0373c < 0) {

    DAT_00b0373c = 0;

  }

  if ((void *)param_1[0x163] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x163]);

  }

  param_1[0x163] = 0;

  param_1[0x164] = 0;

  param_1[0x165] = 0;

  if ((void *)param_1[0x15f] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x15f]);

  }

  param_1[0x15f] = 0;

  param_1[0x160] = 0;

  param_1[0x161] = 0;

  local_4._0_1_ = 6;

  FUN_0074b580();

  local_4._0_1_ = 5;

  FUN_0074b580();

  local_4._0_1_ = 4;

  FUN_0074b580();

  local_4._0_1_ = 3;

  FUN_00763f60();

  local_4._0_1_ = 2;

  FUN_00763f60();

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_00763f60();

  param_1[8] = (int)&PTR_LAB_009cb5cc;

  param_1[4] = (int)&PTR_LAB_009cb5cc;

  ExceptionList = local_c;

  return;

}
