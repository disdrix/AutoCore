// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00438c40
// Callee of Named_CalleeOf_Named_gfxBody
// Address:   0x00438c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00438c40, FUN_00457ac0, _atexit.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxBody
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

undefined * Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438c40(void)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bcc4d;

  local_c = ExceptionList;

  if ((DAT_00d1fd40 & 1) == 0) {

    DAT_00d1fd40 = DAT_00d1fd40 | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_00457ac0(&DAT_00d1fd18);

    _atexit((_func_4879 *)&LAB_009c3310);

  }

  ExceptionList = local_c;

  return &DAT_00d1fd18;

}
