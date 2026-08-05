// =============================================================================
// FUN_006507c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006507c0
// Address:   0x006507c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006507c0 @ 0x006507c0
// Stable ID: aa_006507c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, FUN_0060c3c0, FUN_006507c0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006507c0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8ea8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009e52c4;

  param_1[9] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2);

  param_1[0xe] = DAT_009e52b0;

  param_1[0xf] = DAT_009e52b4;

  param_1[0x10] = DAT_009e52b8;

  local_4 = 0;

  param_1[0x11] = DAT_009e52bc;

  param_1[0x1b] = param_3;

  FUN_0060c3c0();

  param_1[0xb] = *(uint32_t /* width from decompiler */ *)(param_1[0x1b] + 0x44);

  *(uint8_t *)(param_1 + 0xc) = *(uint8_t *)(param_1[0x1b] + 0x48);

  param_1[10] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_3 + 4) + 0x10);

  param_1[0x12] = *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c);

  param_1[0x14] = *(uint32_t /* width from decompiler */ *)(param_3 + 0x28);

  param_1[0x15] = *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c);

  param_1[0x16] = *(uint32_t /* width from decompiler */ *)(param_3 + 0x38);

  param_1[0x18] = *(uint32_t /* width from decompiler */ *)(param_3 + 0x30);

  param_1[0x19] = *(uint32_t /* width from decompiler */ *)(param_3 + 0x34);

  param_1[0x1a] = *(uint32_t /* width from decompiler */ *)(param_3 + 0x3c);

  param_1[7] = 0xb;

  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);

  CVOGHBBase_AttachOwnerObject(param_1,(void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));

  param_1[2] = 1000;

  param_1[0x1c] = g_dwClientTickMs;

  ExceptionList = local_c;

  return param_1;

}
