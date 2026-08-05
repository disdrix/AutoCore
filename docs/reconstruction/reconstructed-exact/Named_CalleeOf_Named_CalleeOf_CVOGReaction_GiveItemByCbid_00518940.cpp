// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00518940
// -----------------------------------------------------------------------------
// Stable ID: aa_00518940
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x00518940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00512670, FUN_00518940, InitializeCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00518940(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a35e8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint8_t *)(param_1 + 0x20) = 0;

  *(uint8_t *)(param_1 + 0x21) = 0;

  *(uint8_t *)(param_1 + 0x22) = 0;

  *(uint8_t *)(param_1 + 0x23) = 0;

  *(uint8_t *)(param_1 + 0x24) = 0;

  *(uint8_t *)(param_1 + 0x25) = 0;

  *(uint8_t *)(param_1 + 0x26) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = DAT_00b04370;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = DAT_00b04374;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = DAT_00b04378;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = DAT_00b0437c;

  fVar2 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

  *(float *)(param_1 + 0xb8) = fVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 200) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

  *(uint16_t *)(param_1 + 0xe8) = 0;

  *(uint16_t *)(param_1 + 0xea) = 0xffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 0xffffffff;

  *(uint8_t *)(param_1 + 0x100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 300) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x130) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x138) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x140) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x158) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = g_abTfidInvalid_9CDF88._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = g_abTfidInvalid_9CDF88._4_4_;

  local_4 = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x168) = g_abTfidInvalid_9CDF88._8_4_;

  uVar1 = g_abTfidInvalid_9CDF88._12_4_;

  *(uint *)(param_1 + 0x184) = *(uint *)(param_1 + 0x184) & 0xfffffff0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = 0xffffffff;

  *(uint8_t *)(param_1 + 0x178) = 0;

  *(uint16_t *)(param_1 + 0x180) = 0;

  *(uint8_t *)(param_1 + 0x101) = 0;

  *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) & 0xffe22210 | 0x22210;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0;

  FUN_00512670();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0xffffffff;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009ce07c;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(uint8_t *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009ce154;

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0xb0) = puVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = g_abTfidInvalid_9CDF88._0_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = g_abTfidInvalid_9CDF88._4_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = g_abTfidInvalid_9CDF88._8_4_;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = g_abTfidInvalid_9CDF88._12_4_;

  DAT_00b04200 = DAT_00b04200 + 1;

  if (DAT_00b04200 == 1) {

    _DAT_00b041f0 = 0;

    _DAT_00b041f4 = 0;

    _DAT_00b041f8 = 0;

  }

  ExceptionList = local_c;

  return param_1;

}
