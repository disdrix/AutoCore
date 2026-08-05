// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0043e080
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e080
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0043e080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×7, for×5, return×3, while×1.
//  - Notable callees: FUN_0043d670×3, FUN_0043e3d0×3, FUN_0043e910×3, FUN_0043e080, FUN_0043ebb0, FUN_0043ec50.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0043e080(int param_1,int param_2,uint param_3,uint param_4,uint32_t /* width from decompiler */ *param_5)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int local_24;

  int local_20;

  int local_1c;

  uint local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  uVar3 = param_4;

  puStack_c = &LAB_009bd5f0;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffd0;

  local_24 = param_2;

  uVar4 = param_3 - *(int *)(param_1 + 0xc);

  local_20 = *(int *)(param_1 + 0x10);

  local_18 = local_20 - uVar4;

  param_3 = uVar4;

  local_1c = param_1;

  if (uVar4 < local_18) {

    local_8 = 0;

    ExceptionList = &local_10;

    if (uVar4 < param_4) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffffd0;

      for (param_4 = param_4 - uVar4; uVar1 = uVar4, param_4 != 0; param_4 = param_4 + -1) {

        FUN_0043e3d0(param_5);

      }

      while (param_4 = uVar1, param_4 != 0) {

        uVar4 = *(int *)(param_1 + 0xc) + -1 + uVar3;

        uVar1 = uVar4 >> 2;

        iVar2 = uVar1 * -4;

        if (*(uint *)(param_1 + 8) <= uVar1) {

          uVar1 = uVar1 - *(uint *)(param_1 + 8);

        }

        FUN_0043e3d0(*(int *)(*(int *)(param_1 + 4) + uVar1 * 4) + (uVar4 + iVar2) * 4);

        uVar4 = param_3;

        uVar1 = param_4 - 1;

      }

      iVar2 = *(int *)(param_1 + 0xc) + uVar3;

      FUN_0043e910(param_1,iVar2,param_1,iVar2 + uVar4,param_5);

      ExceptionList = local_10;

      return;

    }

    for (; param_4 != 0; param_4 = param_4 - 1) {

      uVar4 = *(int *)(param_1 + 0xc) + -1 + uVar3;

      uVar1 = uVar4 >> 2;

      iVar2 = uVar1 * -4;

      if (*(uint *)(param_1 + 8) <= uVar1) {

        uVar1 = uVar1 - *(uint *)(param_1 + 8);

      }

      FUN_0043e3d0(*(int *)(*(int *)(param_1 + 4) + uVar1 * 4) + (uVar4 + iVar2) * 4);

    }

    param_5 = (uint32_t /* width from decompiler */ *)*param_5;

    iVar5 = *(int *)(param_1 + 0xc) + uVar3;

    FUN_0043ec50(&local_24,param_1,iVar5 + uVar3,param_1,iVar5 + param_3,param_1,iVar5,param_5);

    iVar5 = iVar5 + param_3;

    iVar2 = *(int *)(param_1 + 0xc) + param_3;

  }

  else {

    local_8 = 2;

    if (local_18 < param_4) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffffd0;

      for (iVar2 = param_4 - local_18; iVar2 != 0; iVar2 = iVar2 + -1) {

        FUN_0043d670(param_5);

      }

      for (param_4 = 0; param_4 < local_18; param_4 = param_4 + 1) {

        uVar1 = *(int *)(param_1 + 0xc) + param_4 + uVar4;

        uVar3 = uVar1 >> 2;

        iVar2 = uVar3 * -4;

        if (*(uint *)(param_1 + 8) <= uVar3) {

          uVar3 = uVar3 - *(uint *)(param_1 + 8);

        }

        FUN_0043d670(*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) + (uVar1 + iVar2) * 4);

      }

      iVar2 = *(int *)(param_1 + 0xc) + uVar4;

      FUN_0043e910(param_1,iVar2,param_1,iVar2 + local_18,param_5);

      ExceptionList = local_10;

      return;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xffffffd0;

    for (param_4 = 0; param_4 < uVar3; param_4 = param_4 + 1) {

      uVar1 = *(int *)(param_1 + 0xc) + (param_4 - uVar3) + local_18 + param_3;

      uVar4 = uVar1 >> 2;

      iVar2 = uVar4 * -4;

      if (*(uint *)(param_1 + 8) <= uVar4) {

        uVar4 = uVar4 - *(uint *)(param_1 + 8);

      }

      FUN_0043d670(*(int *)(*(int *)(param_1 + 4) + uVar4 * 4) + (uVar1 + iVar2) * 4);

    }

    iVar2 = *(int *)(param_1 + 0xc) + param_3;

    param_5 = (uint32_t /* width from decompiler */ *)*param_5;

    param_2 = param_1;

    FUN_0043ebb0(&param_2,param_1,iVar2,param_1,(iVar2 + local_18) - uVar3,param_1,iVar2 + local_18,

                 param_5);

    iVar5 = iVar2 + uVar3;

  }

  FUN_0043e910(param_1,iVar2,param_1,iVar5,&param_5);

  ExceptionList = local_10;

  return;

}
