// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeath_00508e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00508e20
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers)
// Address:   0x00508e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: Map_LowerBoundFindByIntKey×2, FUN_00508e20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers)
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeath_00508e20(int param_1)



{

  int *extraout_EAX;

  int *unaff_EDI;

  int local_4;

  

  local_4 = param_1;

  Map_LowerBoundFindByIntKey((void *)(param_1 + 0x74),&local_4,&stack0x00000004,unaff_EDI);

  if (local_4 != *(int *)(param_1 + 0x78)) {

    Map_LowerBoundFindByIntKey((void *)(param_1 + 0x74),&local_4,&stack0x00000004,unaff_EDI);

    return *(uint32_t /* width from decompiler */ *)(*extraout_EAX + 0x10);

  }

  return 0;

}
