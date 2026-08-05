// =============================================================================
// Named_CalleeOf_Mission_Couldn_t_find_source_child_geo_for_delay_00787260
// -----------------------------------------------------------------------------
// Stable ID: aa_00787260
// Callee of Mission_Couldn_t_find_source_child_geo_for_delayed_volum
// Address:   0x00787260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Couldn_t_find_source_child_geo_for_delay: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00787260.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Couldn_t_find_source_child_geo_for_delayed_volum
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Mission_Couldn_t_find_source_child_geo_for_delay_00787260(int *param_1)



{

  if (*param_1 != 0) {

    return *(uint32_t /* width from decompiler */ *)(*param_1 + 0x18);

  }

  return 0;

}
