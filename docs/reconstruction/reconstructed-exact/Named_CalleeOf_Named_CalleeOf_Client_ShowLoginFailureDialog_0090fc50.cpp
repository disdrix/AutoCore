// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog_0090fc50
// -----------------------------------------------------------------------------
// Stable ID: aa_0090fc50
// Callee of Named_CalleeOf_Client_ShowLoginFailureDialog
// Address:   0x0090fc50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_ShowLoginFailureDialog: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00933080×24, FUN_0090fc50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_ShowLoginFailureDialog
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



void Named_CalleeOf_Named_CalleeOf_Client_ShowLoginFailureDialog_0090fc50(void)



{

  if (((DAT_00d09970 == 0) || (DAT_00d09980 == 0)) || (DAT_00d09990 == 0)) {

    DAT_00d09970 = FUN_00933080(&DAT_00d1a840);

    DAT_00d09980 = FUN_00933080(&DAT_00d1a840);

    DAT_00d09990 = FUN_00933080(&DAT_00d1a840);

    DAT_00d09940 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09950 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09960 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09974 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09984 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09994 = FUN_00933080(&DAT_00d1a840);

    DAT_00d09944 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09954 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09964 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09978 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09988 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09998 = FUN_00933080(&DAT_00d1a840);

    DAT_00d09948 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09958 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d09968 = FUN_00933080(&DAT_00d1a840);

    _DAT_00d0997c = FUN_00933080(&DAT_00d1a840);

    _DAT_00d0998c = FUN_00933080(&DAT_00d1a840);

    _DAT_00d0999c = FUN_00933080(&DAT_00d1a840);

    _DAT_00d0994c = FUN_00933080(&DAT_00d1a840);

    _DAT_00d0995c = FUN_00933080(&DAT_00d1a840);

    _DAT_00d0996c = FUN_00933080(&DAT_00d1a840);

  }

  return;

}
