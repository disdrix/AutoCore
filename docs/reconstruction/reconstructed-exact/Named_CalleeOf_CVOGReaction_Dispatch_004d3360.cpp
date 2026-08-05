// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_004d3360
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3360
// Callee of CVOGReaction_Dispatch
// Address:   0x004d3360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, FUN_004d3360, FUN_004e3050, FUN_004e47b0, FUN_005a5050.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGReaction_Dispatch_004d3360(int param_1,void *param_2)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t local_14 [8];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2035;

  local_c = ExceptionList;

  uVar1 = param_2._0_1_;

  ExceptionList = &local_c;

  FUN_004e3050(&local_1c,&param_2);

  if (local_1c != *(int *)(param_1 + 0xe514)) {

    ExceptionList = local_c;

    return *(uint32_t /* width from decompiler */ *)(local_1c + 0x10);

  }

  param_2 = operator_new(0x120);

  uVar2 = 0;

  local_4 = 0;

  if (param_2 != (void *)0x0) {

    uVar2 = FUN_005a5050();

  }

  local_4 = 0xffffffff;

  local_1c = CONCAT31(local_1c._1_3_,uVar1);

  local_18 = uVar2;

  FUN_004e47b0(local_14,&local_1c);

  ExceptionList = local_c;

  return uVar2;

}
