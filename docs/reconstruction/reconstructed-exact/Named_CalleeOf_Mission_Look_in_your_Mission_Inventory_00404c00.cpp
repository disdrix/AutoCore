// =============================================================================
// Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_00404c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00404c00
// Callee of Mission_Look_in_your_Mission_Inventory
// Address:   0x00404c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Look_in_your_Mission_Inventory: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00404c00, SQRT.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Look_in_your_Mission_Inventory
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

float10 __fastcall Named_CalleeOf_Mission_Look_in_your_Mission_Inventory_00404c00(float *param_1)



{

  return SQRT((float10)param_1[2] * (float10)param_1[2] +

              (float10)param_1[1] * (float10)param_1[1] + (float10)*param_1 * (float10)*param_1);

}
