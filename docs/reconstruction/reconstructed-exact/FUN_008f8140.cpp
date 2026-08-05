// =============================================================================
// FUN_008f8140
// -----------------------------------------------------------------------------
// Stable ID: aa_008f8140
// Address:   0x008f8140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f8140 @ 0x008f8140
// Stable ID: aa_008f8140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00792d20, FUN_008f8140.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ * FUN_008f8140(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7987;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a3668c;

  _eh_vector_constructor_iterator_

            (param_1 + 0x148,0x10,0x96,(_func_void_void_ptr *)&LAB_0095aae0,FUN_0095aaa0);

  param_1[0x13f] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x140) = 0;

  param_1[0x142] = 0;

  param_1[0x143] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0xffffffff;

  param_1[0x43c] = 0;

  param_1[0x43d] = 0;

  param_1[0x3a0] = 0;

  puVar2 = param_1 + 0x3a2;

  for (iVar1 = 0x96; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  ExceptionList = local_c;

  return param_1;

}
