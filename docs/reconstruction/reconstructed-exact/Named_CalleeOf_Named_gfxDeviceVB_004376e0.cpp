// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_004376e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004376e0
// Callee of Named_gfxDeviceVB
// Address:   0x004376e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00437680, FUN_004376e0, FUN_00748430, _eh_vector_constructor_iterator_.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_gfxDeviceVB_004376e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009bd6c7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[1] = &PTR_LAB_00a9db0c;

  *param_1 = &PTR_FUN_00a9db64;

  param_1[1] = &PTR_LAB_00a9db58;

  param_1[3] = 0;

  param_1[2] = &PTR_FUN_00a9da80;

  local_4 = 2;

  uStack_3 = 0;

  _eh_vector_constructor_iterator_(param_1 + 4,8,2,FUN_00437440,FUN_00437450);

  param_1[8] = 0;

  *(uint8_t *)(param_1 + 9) = 0;

  *(uint8_t *)((int)param_1 + 0x25) = 0;

  *(uint8_t *)((int)param_1 + 0x26) = 0;

  local_4 = 4;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  uVar1 = DAT_00aaa630;

  param_1[0xf] = DAT_00aaa630;

  param_1[0x10] = uVar1;

  param_1[0x11] = uVar1;

  uVar1 = DAT_00aaa63c;

  param_1[0x12] = DAT_00aaa63c;

  param_1[0x13] = uVar1;

  param_1[0x14] = uVar1;

  *(uint8_t *)(param_1 + 0x15) = 1;

  param_1[0x16] = 0;

  param_1[0x1a] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  FUN_00437680(param_1 + 0x1e);

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  param_1[0x2e] = 0;

  _local_4 = CONCAT31(uStack_3,7);

  param_1[0x2f] = 0;

  param_1[0x30] = 0;

  FUN_00748430(param_2);

  ExceptionList = local_c;

  return param_1;

}
