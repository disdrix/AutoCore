// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006049b0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_006049b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006049b0
// Address:   0x006049b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall Named_VOG_DEBUG_STOP_006049b0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a7fdb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  local_4 = 0;

  if (param_2 == 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  ExceptionList = local_c;

  return param_1;

}
