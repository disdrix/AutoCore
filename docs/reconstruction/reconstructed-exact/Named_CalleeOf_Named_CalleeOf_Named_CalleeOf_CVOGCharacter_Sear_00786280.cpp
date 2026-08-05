// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Sear_00786280
// -----------------------------------------------------------------------------
// Stable ID: aa_00786280
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions
// Address:   0x00786280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_0044e100, FUN_00780730, FUN_00786280.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Sear_00786280(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac29c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_2 = param_3;

  param_2[1] = 0;

  param_2[2] = param_1;

  param_2[4] = 0;

  param_2[5] = 0;

  param_2[6] = 0;

  local_4 = 0;

  iVar1 = FUN_0044e100();

  param_2[8] = iVar1;

  *(uint8_t *)(iVar1 + 0x2d) = 1;

  *(uint32_t /* width from decompiler */ *)(param_2[8] + 4) = param_2[8];

  *(uint32_t /* width from decompiler */ *)param_2[8] = param_2[8];

  *(uint32_t /* width from decompiler */ *)(param_2[8] + 8) = param_2[8];

  param_2[9] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  param_2[10] = 0;

  param_2[0xb] = 0;

  param_2[0xc] = 0;

  param_2[0xd] = 0;

  param_2[0xe] = 0;

  param_2[0xf] = 0;

  param_2[0x10] = 0;

  param_2[0x11] = 0;

  param_2[0x12] = 0;

  param_2[0x13] = 0;

  param_2[0x14] = 0;

  param_2[0x15] = 0;

  *(uint8_t *)(param_2 + 0x16) = 1;

  pvVar2 = operator_new(0x30);

  if (pvVar2 == (void *)0x0) {

    param_2[1] = 0;

  }

  else {

    uVar3 = FUN_00780730();

    param_2[1] = uVar3;

  }

  ExceptionList = local_c;

  return param_2;

}
