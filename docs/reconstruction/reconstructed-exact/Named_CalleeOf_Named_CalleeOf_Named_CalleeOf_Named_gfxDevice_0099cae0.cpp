// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_0099cae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099cae0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
// Address:   0x0099cae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004278d0, FUN_0044edb0, FUN_0099cae0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_0099cae0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint param_4)



{

  int *piVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009afa58;

  pvStack_c = ExceptionList;

  local_4._0_1_ = 2;

  local_4._1_3_ = 0;

  ExceptionList = &pvStack_c;

  if ((param_2 != (int *)0x0) &&

     (ExceptionList = &pvStack_c, param_2[1] = param_2[1] + 1, param_2[1] == 1)) {

    (**(code **)(*param_2 + 4))();

  }

  if ((param_2 != (int *)0x0) && (*(uint *)(param_1 + 0x10) < (uint)param_2[0x1f])) {

    *(int *)(param_1 + 0x10) = param_2[0x1f];

  }

  param_4 = param_4 & 0xffffff00;

  FUN_004278d0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_4);

  FUN_0044edb0(param_1,param_4,1);

  local_4 = (uint)local_4._1_3_ << 8;

  if (param_2 != (int *)0x0) {

    piVar1 = param_2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_2 + 8))();

    }

  }

  local_4 = 0xffffffff;

  if (param_2 != (int *)0x0) {

    piVar1 = param_2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_2 + 8))();

    }

  }

  ExceptionList = pvStack_c;

  return;

}
