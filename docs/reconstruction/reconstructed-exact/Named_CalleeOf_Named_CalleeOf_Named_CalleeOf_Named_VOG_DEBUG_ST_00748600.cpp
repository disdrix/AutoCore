// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00748600
// -----------------------------------------------------------------------------
// Stable ID: aa_00748600
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00748600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: CONCAT31, FUN_0073e800, FUN_00748260, FUN_00748600, _eh_vector_destructor_iterator_.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00748600(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009acb83;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a9db64;

  param_1[1] = &PTR_LAB_00a9db58;

  local_4 = 7;

  FUN_00748260();

  piVar2 = (int *)param_1[8];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    param_1[8] = 0;

  }

  param_1[0x23] = 0;

  local_4._0_1_ = 6;

  piVar2 = (int *)param_1[0x2e];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  if ((void *)param_1[0x27] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x27]);

  }

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  local_4._0_1_ = 4;

  FUN_0073e800(param_1 + 0x1e);

  local_4._0_1_ = 3;

  piVar2 = (int *)param_1[8];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  local_4._0_1_ = 2;

  _eh_vector_destructor_iterator_(param_1 + 4,8,2,FUN_00437450);

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[2] = &PTR_FUN_00a9da80;

  piVar2 = (int *)param_1[3];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  param_1[1] = &PTR_LAB_00a9db0c;

  *param_1 = &PTR_LAB_00a9db34;

  ExceptionList = pvStack_c;

  return;

}
