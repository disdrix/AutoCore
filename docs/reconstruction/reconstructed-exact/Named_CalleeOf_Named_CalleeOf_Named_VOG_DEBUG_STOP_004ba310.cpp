// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ba310
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba310
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x004ba310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004933f0×6, CONCAT31, FUN_00439770, FUN_004ba310, FUN_0074ba00, strncpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

uint * __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ba310(uint *param_1,char *param_2)



{

  float fVar1;

  uint uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  fVar1 = g_flOne;

  puStack_8 = &LAB_009a1671;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = *param_1 & 0xfffffffc;

  *(uint8_t *)(param_1 + 1) = 0;

  *(uint8_t *)((int)param_1 + 5) = 0;

  *(uint8_t *)((int)param_1 + 6) = 0;

  *(uint8_t *)((int)param_1 + 7) = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  *(uint8_t *)((int)param_1 + 9) = 0;

  *(uint8_t *)((int)param_1 + 10) = 0;

  *(uint8_t *)((int)param_1 + 0xb) = 1;

  *(uint8_t *)(param_1 + 3) = 0;

  param_1[4] = 0;

  param_1[6] = DAT_009cb2a0;

  param_1[7] = DAT_009cb2a4;

  param_1[8] = DAT_009cb2a8;

  param_1[9] = DAT_009cb2ac;

  param_1[0xc] = (uint)fVar1;

  param_1[0xd] = (uint)fVar1;

  param_1[0xe] = (uint)fVar1;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x12] = DAT_009cb2a0;

  param_1[0x13] = DAT_009cb2a4;

  param_1[0x14] = DAT_009cb2a8;

  param_1[0x15] = DAT_009cb2ac;

  param_1[0x16] = 0xffffffff;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x1a] = DAT_009cb2a0;

  param_1[0x1b] = DAT_009cb2a4;

  param_1[0x1c] = DAT_009cb2a8;

  param_1[0x1d] = DAT_009cb2ac;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  local_4 = 0;

  FUN_0074ba00();

  local_4._0_1_ = 1;

  *(uint8_t *)(param_1 + 0x35) = 0;

  uVar2 = FUN_004933f0();

  param_1[0x78] = uVar2;

  param_1[0x79] = 0;

  local_4._0_1_ = 2;

  uVar2 = FUN_004933f0();

  param_1[0x7b] = uVar2;

  param_1[0x7c] = 0;

  local_4._0_1_ = 3;

  uVar2 = FUN_004933f0();

  param_1[0x7e] = uVar2;

  param_1[0x7f] = 0;

  local_4._0_1_ = 4;

  uVar2 = FUN_004933f0();

  param_1[0x81] = uVar2;

  param_1[0x82] = 0;

  local_4._0_1_ = 5;

  uVar2 = FUN_004933f0();

  param_1[0x84] = uVar2;

  param_1[0x85] = 0;

  local_4._0_1_ = 6;

  uVar2 = FUN_004933f0();

  param_1[0x87] = uVar2;

  param_1[0x88] = 0;

  local_4 = CONCAT31(local_4._1_3_,7);

  uVar2 = FUN_00439770();

  param_1[0x8a] = uVar2;

  *(uint8_t *)(uVar2 + 0x15) = 1;

  *(uint *)(param_1[0x8a] + 4) = param_1[0x8a];

  *(uint *)param_1[0x8a] = param_1[0x8a];

  *(uint *)(param_1[0x8a] + 8) = param_1[0x8a];

  param_1[0x8b] = 0;

  param_1[0x8c] = 2;

  param_1[0x23] = 0;

  param_1[0x22] = 0;

  param_1[0x21] = 0;

  param_1[0x20] = 0;

  param_1[0x34] = g_dwClientTickMs;

  strncpy((char *)((int)param_1 + 0xd5),param_2,0x104);

  ExceptionList = local_c;

  return param_1;

}
