// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0054a260
// -----------------------------------------------------------------------------
// Stable ID: aa_0054a260
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0054a260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418890, FUN_0054a260.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint8_t * Named_CalleeOf_Named_VOG_DEBUG_STOP_0054a260(void)



{

  int local_4;

  

  FUN_00418890(&local_4,&stack0x00000004);

  if (local_4 != DAT_00b04738) {

    return (uint8_t *)(local_4 + 0x194);

  }

  return &DAT_00a1419b;

}
