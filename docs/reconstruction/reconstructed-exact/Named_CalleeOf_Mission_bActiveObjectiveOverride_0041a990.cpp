// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a990
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a990
// Callee of Mission_bActiveObjectiveOverride (+2 other named callers)
// Address:   0x0041a990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0041a990, FUN_0041bf70, FUN_00422de0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+2 other named callers)
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

void Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a990(void)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x10) != 0) {

    FUN_00422de0();

    FUN_0041bf70();

  }

  return;

}
