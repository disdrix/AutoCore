// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_004bff90
// -----------------------------------------------------------------------------
// Stable ID: aa_004bff90
// Callee of Named_CalleeOf_CVOGReaction_SpawnObject
// Address:   0x004bff90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004bfb60, FUN_004bff90, FUN_004c0530, FUN_004c0570, FUN_005c6b40.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_SpawnObject
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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_004bff90(void *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = (int)param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1962;

  local_c = ExceptionList;

  uVar2 = 0;

  if ((param_1 == (void *)0x0) || (*(char *)((int)param_1 + 0xf) != '\0')) {

    return 0;

  }

  ExceptionList = &local_c;

  param_1 = operator_new(0x80);

  local_4 = 0;

  if (param_1 != (void *)0x0) {

    uVar2 = FUN_005c6b40(iVar1,param_2,param_3,param_4,param_5,param_6);

  }

  local_4 = 0xffffffff;

  param_1 = (void *)uVar2;

  iVar1 = FUN_004bfb60(iVar1);

  if (DAT_00af0ae0 < *(uint *)(iVar1 + 8)) {

    FUN_004c0530(&param_1);

    ExceptionList = local_c;

    return uVar2;

  }

  FUN_004c0570(&param_1);

  ExceptionList = local_c;

  return uVar2;

}
