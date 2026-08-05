// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006061e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006061e0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x006061e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, while×1, return×1.
//  - Notable callees: FUN_004cbfc0×2, FUN_00608720×2, CVOGHBBase_AttachOwnerObject, CVOGHBBase_ctor, FUN_006061e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006061e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,void *param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ param_5,int *param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ param_9

            )



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8106;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CVOGHBBase_ctor(param_1);

  *param_1 = &PTR_FUN_009de7b4;

  puVar2 = param_1 + 9;

  for (iVar1 = 0x18c; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *param_4;

    param_4 = param_4 + 1;

    puVar2 = puVar2 + 1;

  }

  param_1[0x195] = param_5;

  *(uint8_t *)(param_1 + 0x196) = (uint8_t)param_9;

  param_1[0x198] = 0;

  param_1[0x199] = 0;

  param_1[0x19a] = 0;

  param_1[0x19b] = param_7;

  param_1[3] = 1;

  param_1[4] = 1;

  param_1[0x19c] = param_8;

  local_4 = 1;

  param_1[2] = param_2;

  CVOGHBBase_AttachOwnerObject(param_1,param_3);

  while (((*param_6 != -1 || (param_6[1] != -1)) || ((char)param_6[2] != '\0'))) {

    iVar1 = param_1[0x198];

    if ((iVar1 == 0) || ((uint)(param_1[0x19a] - iVar1 >> 4) <= (uint)(param_1[0x199] - iVar1 >> 4))

       ) {

      FUN_004cbfc0(param_1[0x199],1,param_6);

      param_6 = param_6 + 4;

    }

    else {

      iVar1 = param_1[0x199];

      FUN_00608720(iVar1,1,param_6,param_1 + 0x197,param_9);

      param_1[0x199] = iVar1 + 0x10;

      param_6 = param_6 + 4;

    }

  }

  iVar1 = param_1[0x198];

  if ((iVar1 == 0) || ((uint)(param_1[0x19a] - iVar1 >> 4) <= (uint)(param_1[0x199] - iVar1 >> 4)))

  {

    FUN_004cbfc0(param_1[0x199],1,&DAT_009de7a0);

  }

  else {

    iVar1 = param_1[0x199];

    FUN_00608720(iVar1,1,&DAT_009de7a0,param_1 + 0x197,param_9);

    param_1[0x199] = iVar1 + 0x10;

  }

  ExceptionList = local_c;

  return param_1;

}
