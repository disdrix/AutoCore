// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00604d40
// Callee of Named_CalleeOf_Client_Input_DriveControlTick (+1 other named callers)
// Address:   0x00604d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_DriveControlTick: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_Input_DriveControlTick (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_Start, CVOGHBBase_ctor, FUN_00604d40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_DriveControlTick (+1 other named callers)
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

CVOGHBBase * __thiscall Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604d40(CVOGHBBase *param_1,void *param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8018;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CVOGHBBase_ctor(param_1);

  local_4 = 0;

  param_1->pVTable = &PTR_FUN_009cdfb0;

  CVOGHBBase_AttachOwnerObject(param_1,param_2);

  param_1->nUnusedOrFlags = 2;

  param_1->nPeriodSentinel = -1000;

  param_1->nPeriodMs = 1000;

  CVOGHBBase_Start(param_1);

  ExceptionList = local_c;

  return param_1;

}
