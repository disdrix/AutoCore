// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveItemByCbid_0057b0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0057b0e0
// Callee of CVOGReaction_GiveItemByCbid
// Address:   0x0057b0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00518940, FUN_005743e0, FUN_0057b0e0.
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_CVOGReaction_GiveItemByCbid_0057b0e0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a52b3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00518940();

  *param_1 = &PTR_FUN_009d414c;

  *(uint8_t *)((int)param_1 + 0x1d1) = 0;

  param_1[0x76] = 0;

  param_1[0x77] = 0;

  param_1[0x78] = 0;

  param_1[0x7a] = 0;

  param_1[0x7b] = 0;

  param_1[0x7c] = 0;

  *(uint8_t *)(param_1 + 0x7d) = 0;

  *(uint8_t *)((int)param_1 + 0x1f5) = 0;

  *(uint8_t *)((int)param_1 + 0x1f6) = 0;

  param_1[0x7f] = 0xffffffff;

  param_1[0x80] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x81) = 0;

  *(uint8_t *)((int)param_1 + 0x205) = 0;

  *(uint8_t *)((int)param_1 + 0x206) = 1;

  param_1[0x83] = 0;

  param_1[0x84] = 0;

  param_1[0x85] = 0;

  param_1[0x86] = 0xffffffff;

  param_1[0x87] = 0xffffffff;

  param_1[0x88] = 0xffffffff;

  param_1[0x89] = 0xffffffff;

  *(uint8_t *)(param_1 + 0x8a) = 1;

  *(uint8_t *)((int)param_1 + 0x229) = 1;

  param_1[0x8b] = 0;

  param_1[0x8d] = 0;

  param_1[0x8e] = 0;

  param_1[0x8f] = 0;

  param_1[0x91] = 0;

  param_1[0x92] = 0;

  param_1[0x93] = 0;

  local_4 = 5;

  param_1[0x94] = 0;

  param_1[0x96] = 0;

  param_1[0x97] = 0;

  param_1[0x98] = 0;

  param_1[0x99] = 0;

  FUN_005743e0(0,0,0);

  param_1[100] = s_FNew_Reaction_009d4132._2_4_;

  param_1[0x65] = s_FNew_Reaction_009d4132._6_4_;

  param_1[0x66] = s_FNew_Reaction_009d4132._10_4_;

  *(char *)(param_1 + 0x67) = s_FNew_Reaction_009d4132[0xe];

  ExceptionList = local_c;

  return param_1;

}
