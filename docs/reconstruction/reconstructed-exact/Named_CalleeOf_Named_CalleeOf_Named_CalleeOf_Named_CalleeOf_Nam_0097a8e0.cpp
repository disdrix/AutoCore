// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0097a8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0097a8e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0097a8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "i_w_tut_2d_wnd_highlight.dds". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_w_tut_2d_wnd_highlight.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00792d20, FUN_0096efd0, FUN_0096f3e0, FUN_0097a8e0, FUN_00989e00.
//  - Strings: "i_w_tut_2d_wnd_highlight.dds".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0097a8e0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  float fVar5;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b45a4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  param_1[0x14c] = 0;

  param_1[0x14b] = 0;

  *param_1 = &PTR_FUN_00a6f61c;

  fVar5 = (float)DAT_00d1e81c * _DAT_00aaabc8;

  param_1[0x149] = (int)((float)DAT_00d1e818 * _DAT_00aaabcc);

  uVar2 = DAT_00a0f70c;

  param_1[0x14a] = (int)fVar5;

  param_1[0x14d] = uVar2;

  *(uint8_t *)(param_1 + 0x150) = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x146] = 0;

  param_1[0x14e] = 0xffffffff;

  param_1[0x140] = 0;

  param_1[0x141] = 0xffffff9c;

  param_1[0x142] = 0xffffff9c;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  local_10 = operator_new(4);

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *local_10 = 0;

    puVar3 = local_10;

  }

  local_4 = local_4 & 0xffffff00;

  param_1[0x13f] = puVar3;

  FUN_00989e00(&local_10,"i_w_tut_2d_wnd_highlight.dds");

  iVar4 = FUN_0096f3e0(&local_10,0);

  if (iVar4 < 0) {

    pvVar1 = (void *)param_1[0x13f];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[0x13f] = 0;

    ExceptionList = local_c;

    return param_1;

  }

  ExceptionList = local_c;

  return param_1;

}
