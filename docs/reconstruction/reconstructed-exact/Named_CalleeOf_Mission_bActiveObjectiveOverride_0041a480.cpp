// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a480
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a480
// Callee of Mission_bActiveObjectiveOverride (+1 other named callers)
// Address:   0x0041a480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0041a480, FUN_00421110.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+1 other named callers)
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

void Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a480(void)



{

  int in_EAX;

  uint8_t local_4 [4];

  

  FUN_00421110(local_4,**(uint32_t /* width from decompiler */ **)(in_EAX + 4),*(uint32_t /* width from decompiler */ **)(in_EAX + 4));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(in_EAX + 4));

}
