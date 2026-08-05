// =============================================================================
// FUN_006270b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006270b0
// Address:   0x006270b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006270b0 @ 0x006270b0
// Stable ID: aa_006270b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, CVOGHBBase_AttachOwnerObject, FUN_00439770, FUN_005788d0, FUN_006270b0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_006270b0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            int *param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8b76;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_005788d0(param_2,param_3,param_4,param_5,param_6,param_7);

  local_4 = 0;

  *param_1 = &PTR_FUN_009d1c54;

  iVar1 = FUN_00439770();

  param_1[0x1b1] = iVar1;

  *(uint8_t *)(iVar1 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x1b1] + 4) = param_1[0x1b1];

  *(uint32_t /* width from decompiler */ *)param_1[0x1b1] = param_1[0x1b1];

  *(uint32_t /* width from decompiler */ *)(param_1[0x1b1] + 8) = param_1[0x1b1];

  param_1[0x1b2] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  iVar1 = (**(code **)(*param_5 + 0x210))(0);

  if (iVar1 == 0) {

    CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);

  }

  ExceptionList = param_1;

  return param_1;

}
