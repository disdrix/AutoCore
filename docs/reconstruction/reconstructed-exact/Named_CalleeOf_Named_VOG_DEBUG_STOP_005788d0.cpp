// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005788d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005788d0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x005788d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: CONCAT31, CVOGHBBase_AttachOwnerObject, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, FUN_00513b00, FUN_0054f3c0, FUN_005788d0, FUN_0058ab60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_VOG_DEBUG_STOP_005788d0(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,void *param_5,

            uint32_t /* width from decompiler */ *param_6,uint32_t /* width from decompiler */ param_7)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5218;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CVOGHBBase_ctor(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_009d3fdc;

  FUN_0054f3c0();

  param_1[0x1ac] = 0;

  param_1[0x1ad] = 0;

  param_1[0x1ae] = 0;

  *(uint8_t *)(param_1 + 0x1a9) = 0;

  param_1[7] = 1;

  puVar1 = param_1 + 9;

  for (iVar3 = 0x18c; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar1 = *param_3;

    param_3 = param_3 + 1;

    puVar1 = puVar1 + 1;

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  puVar1 = (uint32_t /* width from decompiler */ *)(param_2 + 0x160);

  if (param_2 == 0) {

    puVar1 = &DAT_009d3f88;

  }

  param_1[0x196] = *puVar1;

  param_1[0x197] = puVar1[1];

  param_1[0x198] = puVar1[2];

  param_1[0x199] = puVar1[3];

  if (param_2 == 0) {

    puVar1 = &DAT_009d3f88;

  }

  else {

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00513b00(local_1c);

  }

  param_1[0x19a] = *puVar1;

  param_1[0x19b] = puVar1[1];

  param_1[0x19c] = puVar1[2];

  param_1[0x19d] = puVar1[3];

  param_1[0x1a2] = param_4;

  param_1[0x1a4] = *param_6;

  param_1[0x1a5] = param_6[1];

  param_1[0x1a6] = param_6[2];

  param_1[0x1a7] = param_6[3];

  param_1[0x1aa] = param_7;

  uVar2 = FUN_0058ab60(param_7);

  param_1[0x1a8] = uVar2;

  iVar3 = Skill_ValidateTargetForSkill(param_1 + 9,param_5,(void *)0x1);

  if ((char)iVar3 != '\0') {

    CVOGHBBase_AttachOwnerObject(param_1,param_5);

    iVar3 = param_1[6];

    param_1[0x19e] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x160);

    param_1[0x19f] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164);

    param_1[0x1a0] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168);

    param_1[0x1a1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x16c);

    param_1[2] = param_1[0x10];

    iVar3 = param_1[0xf];

    if (iVar3 == 0) {

      iVar3 = 1;

    }

    CVOGHBBase_SetPeriodAndCounter(param_1,iVar3,true);

  }

  ExceptionList = local_c;

  return param_1;

}
