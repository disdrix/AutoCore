// =============================================================================
// Named_CalleeOf_CVOGObjectiveRequirement_Patrol_InitActive_00650d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00650d30
// Callee of CVOGObjectiveRequirement_Patrol_InitActive
// Address:   0x00650d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGObjectiveRequirement_Patrol_InitActive: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, FUN_00650d30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGObjectiveRequirement_Patrol_InitActive
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_CVOGObjectiveRequirement_Patrol_InitActive_00650d30(uint32_t /* width from decompiler */ *param_1,void *param_2,int *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8ec8;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009e52e4;

  local_4 = 0;

  uVar1 = (**(code **)(*param_3 + 0x58))();

  param_1[9] = uVar1;

  param_1[10] = *(uint32_t /* width from decompiler */ *)(param_3[1] + 0x10);

  param_1[0xc] = param_3[0xc];

  param_1[0xd] = param_3[0xd];

  param_1[0xe] = param_3[7];

  param_1[7] = 0xc;

  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);

  if (param_2 != (void *)0x0) {

    param_2 = (void *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2);

  }

  CVOGHBBase_AttachOwnerObject(param_1,param_2);

  param_1[2] = 1000;

  ExceptionList = pvStack_c;

  return param_1;

}
