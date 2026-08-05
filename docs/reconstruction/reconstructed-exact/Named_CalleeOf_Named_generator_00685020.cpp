// =============================================================================
// Named_CalleeOf_Named_generator_00685020
// -----------------------------------------------------------------------------
// Stable ID: aa_00685020
// Callee of Named_generator
// Address:   0x00685020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00685020.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_generator
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

void Named_CalleeOf_Named_generator_00685020(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  *param_2 = *param_1;

  *(uint8_t *)(param_2 + 1) = *(uint8_t *)(param_1 + 1);

  *(uint8_t *)((int)param_2 + 5) = *(uint8_t *)((int)param_1 + 5);

  *(uint16_t *)((int)param_2 + 6) = *(uint16_t *)((int)param_1 + 6);

  return;

}
