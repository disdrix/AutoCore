// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_RelockContinentObjec_0052b2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b2e0
// Callee of Named_CalleeOf_CVOGReaction_RelockContinentObject
// Address:   0x0052b2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_RelockContinentObject: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CNDHash_LookupByKey, FUN_0052b2e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_RelockContinentObject
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_RelockContinentObjec_0052b2e0(int param_1,uint param_2)



{

  void *pvVar1;

  

  if (*(void **)(param_1 + 0x534) != (void *)0x0) {

    pvVar1 = CNDHash_LookupByKey(*(void **)(param_1 + 0x534),param_2);

    if (pvVar1 != (void *)0x0) {

      return 1;

    }

  }

  return 0;

}
