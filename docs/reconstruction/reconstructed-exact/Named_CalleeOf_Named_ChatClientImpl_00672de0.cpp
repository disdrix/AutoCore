// =============================================================================
// Named_CalleeOf_Named_ChatClientImpl_00672de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00672de0
// Callee of Named_ChatClientImpl
// Address:   0x00672de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ChatClientImpl: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00680300×11, CONCAT31, FUN_00672de0, FUN_00680320, InitializeCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ChatClientImpl
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_ChatClientImpl_00672de0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9299;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_10 = param_1;

  FUN_00680320();

  *param_1 = &PTR_FUN_009e8274;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = DAT_00aa9110;

  param_1[0x29] = DAT_00aa9114;

  param_1[0x2a] = DAT_00aa9118;

  param_1[0x2b] = DAT_00aa911c;

  param_1[0x57] = 0;

  param_1[0x58] = 0;

  param_1[0x59] = 0;

  param_1[0x25a] = 0;

  *(uint8_t *)(param_1 + 0x25b) = 0;

  *(uint8_t *)((int)param_1 + 0x96e) = 0;

  local_4 = 0;

  param_1[0x25d] = 0;

  param_1[0x25e] = 0;

  param_1[0x25f] = 0;

  param_1[0x260] = 0;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x261));

  *(uint8_t *)(param_1 + 0x267) = 1;

  local_4 = CONCAT31(local_4._1_3_,1);

  *(uint8_t *)(param_1 + 0x268) = 0;

  param_1[0x269] = 0;

  *(uint16_t *)(param_1 + 0x26a) = 0xbe;

  *(uint16_t *)((int)param_1 + 0x9aa) = 300;

  param_1[0x26b] = 0;

  local_14 = 0;

  FUN_00680300(&local_14,&LAB_00673c20);

  local_14 = 1;

  FUN_00680300(&local_14,&LAB_00673c70);

  local_14 = 2;

  FUN_00680300(&local_14,&LAB_00673c80);

  local_14 = 3;

  FUN_00680300(&local_14,&LAB_00673140);

  local_14 = 4;

  FUN_00680300(&local_14,&LAB_00673150);

  local_14 = 5;

  FUN_00680300(&local_14,&LAB_00673160);

  local_14 = 6;

  FUN_00680300(&local_14,&LAB_00673170);

  local_14 = 7;

  FUN_00680300(&local_14,&LAB_00673180);

  local_14 = 8;

  FUN_00680300(&local_14,&LAB_00673190);

  local_14 = 9;

  FUN_00680300(&local_14,&LAB_006731a0);

  local_14 = 10;

  FUN_00680300(&local_14,&LAB_006731b0);

  ExceptionList = local_c;

  return param_1;

}
