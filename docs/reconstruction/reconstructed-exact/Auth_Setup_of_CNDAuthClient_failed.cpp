// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00417210, FUN_007299e0, FUN_007a4480, FUN_008223e0, OutputDebugStringA.
//  - Strings: "Setup of CNDAuthClient failed!\n"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Auth_Setup_of_CNDAuthClient_failed
// -----------------------------------------------------------------------------
// Stable ID: aa_008223e0
// Address:   0x008223e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Setup of CNDAuthClient failed!
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Auth_Setup_of_CNDAuthClient_failed(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b0f8d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa7420;

  param_1[1] = 0;

  *param_1 = &PTR_FUN_00a76344;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  local_4 = 1;

  *(uint8_t *)(param_1 + 0x1d) = 2;

  *(uint8_t *)(param_1 + 2) = 0;

  *(uint8_t *)((int)param_1 + 0x29) = 0;

  *(uint8_t *)((int)param_1 + 0x4a) = 0;

  *(uint8_t *)((int)param_1 + 0x4b) = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  FUN_00417210(0,0,0,0,0);

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x13] = 6;

  iVar1 = FUN_007299e0();

  if (iVar1 < 0) {

    OutputDebugStringA("Setup of CNDAuthClient failed!\n");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  ExceptionList = local_c;

  return param_1;

}
