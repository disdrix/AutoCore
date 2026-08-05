// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_005fe6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fe6a0
// Callee of Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons (+1 other named callers)
// Address:   0x005fe6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_ctor, FUN_00514ff0, FUN_0056a680, FUN_0056b400, FUN_005fe6a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_005fe6a0(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pOwnerObject;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a7dd8;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  CVOGHBBase_ctor(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_009dd43c;

  param_1[4] = 1;

  param_1[3] = 1;

  uVar1 = FUN_0056a680(0);

  param_1[2] = uVar1;

  if (param_2 == (int *)0x0) {

    pOwnerObject = (void *)0x0;

  }

  else {

    pOwnerObject = (void *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2);

  }

  CVOGHBBase_AttachOwnerObject(param_1,pOwnerObject);

  param_1[7] = 9;

  if (*(int *)(*(int *)(param_2[1] + 4) + 0xb0 + (int)param_2) != 0) {

    FUN_00514ff0(0);

  }

  FUN_0056b400(1);

  (**(code **)(*param_2 + 0x2c))(1);

  ExceptionList = param_1;

  return param_1;

}
