// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0096ef70×2, CONCAT31, CVOGTacArc_ctor, FUN_0096f530.
//  - Return sites: 1.

// =============================================================================
// CVOGTacArc_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00632af0
// Address:   0x00632af0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ * __fastcall CVOGTacArc_ctor(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8be1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_CVOGTacArc_vdtor_009e3538;

  *(uint8_t *)((int)param_1 + 0x32) = 0xff;

  *(uint8_t *)((int)param_1 + 0x31) = 0xff;

  *(uint8_t *)(param_1 + 0xc) = 0xff;

  *(uint8_t *)((int)param_1 + 0x33) = 0xff;

  *(uint8_t *)((int)param_1 + 0x36) = 0xff;

  *(uint8_t *)((int)param_1 + 0x35) = 0xff;

  *(uint8_t *)(param_1 + 0xd) = 0xff;

  *(uint8_t *)((int)param_1 + 0x37) = 0xff;

  *(uint8_t *)((int)param_1 + 0x3a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x39) = 0xff;

  *(uint8_t *)(param_1 + 0xe) = 0xff;

  *(uint8_t *)((int)param_1 + 0x3b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x3e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x3d) = 0xff;

  *(uint8_t *)(param_1 + 0xf) = 0xff;

  *(uint8_t *)((int)param_1 + 0x3f) = 0xff;

  FUN_0096ef70();

  local_4 = 0;

  FUN_0096ef70();

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0096f530();

  param_1[2] = g_flOverheatCoolFrac;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[0xb] = 0;

  *(uint8_t *)(param_1 + 1) = 0;

  param_1[10] = 0x32;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  *(uint8_t *)(param_1 + 0xc) = 0xff;

  *(uint8_t *)((int)param_1 + 0x32) = 0;

  *(uint8_t *)((int)param_1 + 0x33) = 0x66;

  *(uint8_t *)((int)param_1 + 0x31) = 0x33;

  *(uint8_t *)(param_1 + 0xd) = 0x33;

  *(uint8_t *)((int)param_1 + 0x36) = 0xd;

  *(uint8_t *)((int)param_1 + 0x35) = 0;

  *(uint8_t *)((int)param_1 + 0x37) = 0x5a;

  *(uint8_t *)((int)param_1 + 0x3a) = 0x66;

  *(uint8_t *)((int)param_1 + 0x39) = 0x66;

  *(uint8_t *)(param_1 + 0xe) = 0x66;

  *(uint8_t *)((int)param_1 + 0x3b) = 0x66;

  *(uint8_t *)((int)param_1 + 0x3f) = 0x66;

  *(uint8_t *)((int)param_1 + 0x3e) = 0xcc;

  *(uint8_t *)((int)param_1 + 0x3d) = 0;

  *(uint8_t *)(param_1 + 0xf) = 0;

  param_1[0x14] = 0;

  *(uint8_t *)(param_1 + 0x10) = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  ExceptionList = local_c;

  return param_1;

}
