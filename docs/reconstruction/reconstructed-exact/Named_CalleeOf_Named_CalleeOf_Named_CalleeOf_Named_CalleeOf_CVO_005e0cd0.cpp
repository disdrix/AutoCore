// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_005e0cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0cd0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa
// Address:   0x005e0cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, switch×1.
//  - Notable callees: block×6, FUN_00410420×2, FUN_005e1860×2, FUN_0040f5b0, FUN_005e0480, FUN_005e0590, FUN_005e0cd0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa
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

/* WARNING: Removing unreachable block (ram,0x005e0f38) */

/* WARNING: Removing unreachable block (ram,0x005e0f03) */

/* WARNING: Removing unreachable block (ram,0x005e0e3c) */

/* WARNING: Removing unreachable block (ram,0x005e0e8e) */

/* WARNING: Removing unreachable block (ram,0x005e0ef2) */

/* WARNING: Removing unreachable block (ram,0x005e0f27) */



uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_005e0cd0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5,int param_6)



{

  short sVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int local_30;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a7420;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar2 = FUN_005e0480(param_2);

  switch(param_5) {

  case 0:

    param_2 = 0;

    break;

  case 1:

    param_2 = 1;

    break;

  case 2:

    param_2 = 2;

    break;

  case 3:

    param_2 = 3;

    break;

  default:

    param_2 = 4;

  }

  if (param_4 == 0) {

    local_30 = 0;

  }

  else if (param_4 == 1) {

    local_30 = 1;

  }

  else if (param_4 == 2) {

    local_30 = 2;

  }

  else {

    local_30 = 3;

  }

  sVar1 = FUN_005e0590();

  iVar2 = (int)sVar1 + iVar2 * 0x32;

  iVar4 = iVar2 * 4;

  local_4 = 1;

  iVar2 = iVar2 * 0x140 + 0x10e13c + param_1;

  if (((-1 < param_4) && (param_4 < 3)) || ((-1 < param_5 && (param_5 < 4)))) {

    if (param_4 == 0) {

      iVar3 = 0;

    }

    else if (param_4 == 1) {

      iVar3 = 1;

    }

    else if (param_4 == 2) {

      iVar3 = 2;

    }

    else {

      iVar3 = 3;

    }

    FUN_0040f5b0((iVar3 + iVar4) * 0x50 + 0x10e04c + param_1);

    param_1 = param_2 * 0x10 + (iVar4 + local_30) * 0x50 + 0x10e00c + param_1;

    if (*(int *)(param_1 + 4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;

    }

    FUN_00410420(iVar4,0);

    FUN_005e1860(&param_3,0,0,*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8),0);

  }

  iVar4 = param_6;

  if (*(int *)(iVar2 + 4) == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2;

  }

  FUN_00410420(iVar3,0);

  FUN_005e1860(&param_3,0,0,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),*(uint32_t /* width from decompiler */ *)(iVar2 + 8),

               *(uint32_t /* width from decompiler */ *)(iVar4 + 4));

  if ((*(int *)(iVar4 + 4) != 0) && (*(int *)(iVar4 + 8) - *(int *)(iVar4 + 4) >> 2 != 0)) {

    ExceptionList = local_c;

    return 1;

  }

  ExceptionList = local_c;

  return 0;

}
