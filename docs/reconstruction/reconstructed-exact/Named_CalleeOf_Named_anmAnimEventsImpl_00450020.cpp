// =============================================================================
// Named_CalleeOf_Named_anmAnimEventsImpl_00450020
// -----------------------------------------------------------------------------
// Stable ID: aa_00450020
// Callee of Named_anmAnimEventsImpl
// Address:   0x00450020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmAnimEventsImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00450020, FUN_00450050.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_anmAnimEventsImpl
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

void Named_CalleeOf_Named_anmAnimEventsImpl_00450020(void)



{

  undefined **local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint8_t *local_4;

  

  local_4 = (uint8_t *)&local_20;

  local_20 = &PTR_FUN_009d4828;

  local_1c = 0;

  local_18 = 0;

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  FUN_00450050();

  return;

}
