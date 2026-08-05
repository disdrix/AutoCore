// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveI_007a44e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a44e0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x007a44e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007a4480, FUN_007a44e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveI_007a44e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_007a4480(param_2,param_1);

  return;

}
