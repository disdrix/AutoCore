// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveItemByCbid_00575440
// -----------------------------------------------------------------------------
// Stable ID: aa_00575440
// Callee of CVOGReaction_GiveItemByCbid
// Address:   0x00575440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00457c60, FUN_00518940, FUN_00575440.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_GiveItemByCbid
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_CVOGReaction_GiveItemByCbid_00575440(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5096;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00518940();

  local_4 = 0;

  *param_1 = &PTR_FUN_009d33c4;

  uVar1 = FUN_00457c60();

  param_1[0x78] = uVar1;

  param_1[0x79] = 0;

  param_1[0x7e] = 0;

  param_1[0x7f] = 0;

  param_1[0x80] = 0;

  *(uint8_t *)(param_1 + 0x7c) = 0;

  *(uint8_t *)((int)param_1 + 0x1f1) = 0;

  *(uint8_t *)(param_1 + 0x76) = 0;

  param_1[0x65] = 0;

  param_1[0x7b] = 0;

  *(uint8_t *)((int)param_1 + 0x1f2) = 0;

  param_1[100] = 1;

  param_1[0x7a] = 0xffffffff;

  param_1[0x66] = 0xffffffff;

  param_1[0x67] = 0xffffffff;

  param_1[0x6a] = 0xffffffff;

  param_1[0x6b] = 0xffffffff;

  param_1[0x6e] = 0xffffffff;

  param_1[0x6f] = 0xffffffff;

  param_1[0x72] = 0xffffffff;

  param_1[0x73] = 0xffffffff;

  param_1[0x68] = 0;

  param_1[0x6c] = 0;

  param_1[0x70] = 0;

  param_1[0x74] = 0;

  ExceptionList = local_c;

  return param_1;

}
