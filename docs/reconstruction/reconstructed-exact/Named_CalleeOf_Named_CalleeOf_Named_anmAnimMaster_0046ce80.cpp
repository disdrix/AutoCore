// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster_0046ce80
// -----------------------------------------------------------------------------
// Stable ID: aa_0046ce80
// Callee of Named_CalleeOf_Named_anmAnimMaster
// Address:   0x0046ce80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0046ce80, _atexit.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmAnimMaster
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined * Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster_0046ce80(void)



{

  if ((_DAT_00d1f7c0 & 1) == 0) {

    _DAT_00d1f7c0 = _DAT_00d1f7c0 | 1;

    _DAT_00d1f7bc = &PTR_FUN_00aa6dac;

    _atexit((_func_4879 *)&LAB_009c36b0);

  }

  return &DAT_00d1f7bc;

}
