// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: switch×1, return×1.
//  - Notable callees: CVOGWaypoint_UpdateState, FUN_005d5680, FUN_005d5750, FUN_005d5960, FUN_005d5cc0, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CVOGWaypoint::UpdateState".
//  - Return sites: 1.

// =============================================================================
// CVOGWaypoint_UpdateState
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6300
// Address:   0x005d6300  (autoassault.exe, image base 0x400000)
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

void __fastcall CVOGWaypoint_UpdateState(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a7122;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CVOGWaypoint::UpdateState");

  local_4 = 0;

  switch(*(uint8_t *)(param_1 + 0x50)) {

  case 0:

    FUN_005d5750();

    break;

  case 1:

    FUN_005d5960();

    break;

  case 2:

    FUN_005d5cc0();

    break;

  case 3:

    FUN_005d5680();

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
