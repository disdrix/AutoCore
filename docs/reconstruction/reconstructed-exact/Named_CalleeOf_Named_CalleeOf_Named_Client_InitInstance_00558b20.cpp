// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00558b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00558b20
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x00558b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, FUN_00553c50, FUN_00558670, FUN_00558b20, FUN_00558e70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_00558b20(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a47b7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CVOGHBBase_ctor(param_1);

  uVar2 = DAT_00aaa668;

  *param_1 = &PTR_FUN_009d267c;

  param_1[9] = uVar2;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  *(uint8_t *)(param_1 + 0xe) = 0;

  param_1[0xf] = 30000;

  param_1[0x10] = param_2;

  param_1[0x52] = 0;

  *(uint8_t *)(param_1 + 0x11) = 0;

  *(uint8_t *)(param_1 + 0x53) = 0;

  local_4._0_1_ = 1;

  local_4._1_3_ = 0;

  param_1[0x54] = 0xffffffff;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  param_1[0x58] = 0;

  param_1[0x59] = 0;

  *(uint16_t *)(param_1 + 0x5a) = 0xffff;

  *(uint16_t *)((int)param_1 + 0x16a) = 0xffff;

  *(uint16_t *)(param_1 + 0x5b) = 0xffff;

  *(uint16_t *)((int)param_1 + 0x16e) = 0xffff;

  iVar1 = FUN_00558e70();

  param_1[0x5d] = iVar1;

  *(uint8_t *)(iVar1 + 0x571) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x5d] + 4) = param_1[0x5d];

  *(uint32_t /* width from decompiler */ *)param_1[0x5d] = param_1[0x5d];

  *(uint32_t /* width from decompiler */ *)(param_1[0x5d] + 8) = param_1[0x5d];

  param_1[0x5e] = 0;

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  param_1[0x68] = 0;

  param_1[0x6a] = 0;

  param_1[0x6b] = 0;

  param_1[0x6c] = 0;

  param_1[0x6d] = 0;

  param_1[0x72] = 0;

  param_1[0x73] = 0;

  param_1[0x74] = 0x80000000;

  local_4 = CONCAT31(local_4._1_3_,5);

  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);

  param_1[99] = 0;

  param_1[0x5f] = 0;

  param_1[0x60] = 0;

  FUN_00558670();

  param_1[0x62] = 0;

  param_1[2] = 10;

  param_1[0x71] = 0;

  param_1[0x6e] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x6f) = 0;

  *(uint8_t *)((int)param_1 + 0x1bd) = 0;

  param_1[0x70] = 0;

  uVar2 = FUN_00553c50();

  param_1[0x55] = uVar2;

  ExceptionList = local_c;

  return param_1;

}
