// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_00796d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00796d40
// Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction (+1 other named callers)
// Address:   0x00796d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_OnKeyDown_MatchAction: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_Input_OnKeyDown_MatchAction (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00796cd0, FUN_00796d40, _atexit.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_OnKeyDown_MatchAction (+1 other named callers)
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



undefined * Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_00796d40(void)



{

  if ((_DAT_00d20050 & 1) == 0) {

    _DAT_00d20050 = _DAT_00d20050 | 1;

    FUN_00796cd0();

    _atexit((_func_4879 *)&DAT_009c3110);

  }

  return &DAT_00d1fe78;

}
