// =============================================================================
// FUN_006238a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006238a0
// Address:   0x006238a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006238a0 @ 0x006238a0
// Stable ID: aa_006238a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, FUN_00618180, FUN_006238a0.
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

FUN_006238a0(uint32_t /* width from decompiler */ *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8a38;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00618180(param_2,param_3,param_4,param_5,param_6,param_7,0,0x3f800000);

  *param_1 = &PTR_FUN_009d18bc;

  local_4 = 0;

  iVar1 = (**(code **)(*param_2 + 0x210))(0);

  if (iVar1 == 0) {

    CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);

  }

  ExceptionList = param_1;

  return param_1;

}
