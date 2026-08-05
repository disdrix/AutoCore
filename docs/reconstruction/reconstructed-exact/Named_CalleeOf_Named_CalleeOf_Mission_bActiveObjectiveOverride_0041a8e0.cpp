// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a8e0
// Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
// Address:   0x0041a8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0041bf70×2, CONCAT31, FUN_0041a8e0, FUN_00422de0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
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

void Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a8e0(int param_1)



{

  int *piVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009bd810;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if (*(int *)(param_1 + 0x10) != 0) {

    ExceptionList = &pvStack_c;

    FUN_00422de0();

    FUN_0041bf70();

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0041bf70();

  piVar1 = *(int **)(param_1 + 0x14);

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  local_4 = local_4 & 0xffffff00;

  piVar1 = *(int **)(param_1 + 0x10);

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  if (*(int *)(param_1 + 0xc) != 0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(*(int *)(param_1 + 0xc) + 0xc));

  }

  ExceptionList = pvStack_c;

  return;

}
