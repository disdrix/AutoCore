// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assManager_00989b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00989b00
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assManager
// Address:   0x00989b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_009899a0, FUN_00989b00, _aligned_malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assManager
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

bool __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assManager_00989b00(uint32_t /* width from decompiler */ *param_1,void *param_2)



{

  size_t in_EAX;

  size_t unaff_EBX;

  void *pvVar1;

  

  FUN_009899a0();

  *(uint8_t *)(param_1 + 3) = param_2._0_1_;

  param_1[4] = in_EAX;

  param_1[2] = in_EAX - 1;

  param_1[5] = unaff_EBX;

  if (unaff_EBX == 0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = _aligned_malloc(unaff_EBX,in_EAX);

  }

  if (pvVar1 != (void *)0x0) {

    *param_1 = pvVar1;

    param_1[1] = param_1[5];

    param_2 = pvVar1;

    CVOGReaction_FailMissionNotify(&param_2);

  }

  return pvVar1 != (void *)0x0;

}
