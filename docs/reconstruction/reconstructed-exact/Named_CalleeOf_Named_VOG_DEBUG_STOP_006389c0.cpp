// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_006389c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006389c0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x006389c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGHBBase_ctor, CVOGReaction_RandomUnitScalar, FUN_006389c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_006389c0(uint32_t /* width from decompiler */ *param_1)



{

  ushort uVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8e28;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CVOGHBBase_ctor(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_009e3c24;

  param_1[9] = 0xfa;

  param_1[10] = 1000;

  param_1[0xb] = 0x5dc;

  param_1[7] = 4;

  iVar2 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar2 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

  param_1[2] = (int)((longlong)(ulonglong)uVar1 % (longlong)(int)param_1[9]) / 2 + param_1[9];

  ExceptionList = local_c;

  return param_1;

}
