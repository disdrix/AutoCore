// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a3e0
// Callee of Mission_bActiveObjectiveOverride (+9 other named callers)
// Address:   0x0041a3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+9 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0041a3e0, FUN_0041a8e0, FUN_00423170.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+9 other named callers)
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

void Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a3e0(int param_1)



{

  int *piVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bd84a;

  pvStack_c = ExceptionList;

  local_4 = 0;

  if (param_1 == 0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = (int *)(param_1 + 0x24);

  }

  ExceptionList = &pvStack_c;

  FUN_00423170();

  piVar1 = (int *)*piVar1;

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(piVar1);

  }

  local_4 = 0xffffffff;

  FUN_0041a8e0(param_1);

  ExceptionList = pvStack_c;

  return;

}
