// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_007a42d0, _atexit.
//  - Return sites: 1.

// =============================================================================
// CVOGReaction_RandomUnitScalar
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4330
// Address:   0x007a4330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

undefined * CVOGReaction_RandomUnitScalar(void)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b009f;

  local_c = ExceptionList;

  if ((DAT_00d20c34 & 1) == 0) {

    DAT_00d20c34 = DAT_00d20c34 | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_007a42d0();

    _atexit((_func_4879 *)&LAB_009c30c0);

  }

  ExceptionList = local_c;

  return &DAT_00d20c1c;

}
