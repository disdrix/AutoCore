// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00438d00
// Callee of Named_CalleeOf_Named_gfxBody
// Address:   0x00438d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_00438d00, FUN_00465160.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxBody
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438d00(int param_1,int *param_2,int param_3,int param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_3 == param_4) {

    *param_2 = param_3;

    return;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00465160(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3);

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  for (puVar3 = puVar2; puVar3 != puVar1; puVar3 = puVar3 + 2) {

    (**(code **)*puVar3)(0);

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar2;

  *param_2 = param_3;

  return;

}
