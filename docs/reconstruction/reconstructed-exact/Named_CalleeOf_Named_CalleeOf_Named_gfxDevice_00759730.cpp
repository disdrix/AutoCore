// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00759730
// -----------------------------------------------------------------------------
// Stable ID: aa_00759730
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x00759730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0040aef0, FUN_00424770, FUN_00757b40, FUN_00759730, FUN_0099cae0, _snwprintf.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00759730(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int *param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_824 [4];

  uint32_t /* width from decompiler */ local_820;

  uint32_t /* width from decompiler */ local_81c;

  uint32_t /* width from decompiler */ local_818;

  uint32_t /* width from decompiler */ local_814;

  uint8_t *local_810;

  wchar_t local_80c [1023];

  uint16_t local_e;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b24b6;

  local_c = ExceptionList;

  local_820 = 0;

  local_81c = 0;

  local_818 = 0;

  local_814 = 0;

  local_810 = &stack0xfffff7c8;

  local_4._0_1_ = 1;

  local_4._1_3_ = 0;

  ExceptionList = &local_c;

  FUN_0040aef0(&stack0xfffff7c8);

  FUN_0099cae0();

  _snwprintf(local_80c,0x400,L"%S");

  local_e = 0;

  uVar2 = FUN_00757b40(param_1,param_3,local_824,local_80c,param_6,param_7,param_8);

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_00424770();

  local_4 = 0xffffffff;

  if (param_4 != (int *)0x0) {

    piVar1 = param_4 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_4 + 8))();

    }

  }

  ExceptionList = local_c;

  return uVar2;

}
