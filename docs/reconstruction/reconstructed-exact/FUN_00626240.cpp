// =============================================================================
// FUN_00626240
// -----------------------------------------------------------------------------
// Stable ID: aa_00626240
// Address:   0x00626240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00626240 @ 0x00626240
// Stable ID: aa_00626240
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005788d0, FUN_00626240, FUN_007a4480, __RTDynamicCast.
//  - Strings: "VOG_DEBUG_STOP".
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

FUN_00626240(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8ae8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_005788d0(param_2,param_3,param_4,param_5,param_6,param_7);

  local_4 = 0;

  *param_1 = &PTR_FUN_009d1ba4;

  *(uint8_t *)(param_1 + 0x1b2) = 0;

  param_1[0x1b1] = 0;

  *(uint8_t *)((int)param_1 + 0x6c9) = 0;

  iVar1 = __RTDynamicCast(param_5,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGCreature::RTTI_Type_Descriptor,0);

  param_1[0x1b0] = iVar1;

  if (iVar1 == 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  ExceptionList = local_c;

  return param_1;

}
