// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005441d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005441d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005441d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×9, while×3, return×3, for×3.
//  - Notable callees: FUN_0043ec50×4, FUN_0043d670×3, FUN_0043e3d0×3, FUN_0043ebb0, FUN_005441d0.
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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005441d0(int param_1,uint32_t /* width from decompiler */ param_2,uint param_3,int param_4,uint param_5,int param_6,

            uint param_7)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  iVar3 = param_4;

  puStack_c = &LAB_009a4170;

  local_10 = ExceptionList;

  uVar5 = param_3 - *(int *)(param_1 + 0xc);

  uVar4 = *(int *)(param_1 + 0x10) - uVar5;

  uVar7 = param_7 - param_5;

  param_2 = param_4;

  if (uVar5 < uVar4) {

    local_8 = 0;

    ExceptionList = &local_10;

    uVar4 = uVar7;

    if (uVar5 < uVar7) {

      uVar6 = param_5 + (uVar7 - uVar5);

      uVar4 = uVar6;

      ExceptionList = &local_10;

      while ((param_4 != iVar3 || (param_5 != uVar4))) {

        uVar4 = uVar4 - 1;

        uVar2 = uVar4 >> 2;

        iVar1 = uVar2 * -4;

        if (*(uint *)(iVar3 + 8) <= uVar2) {

          uVar2 = uVar2 - *(uint *)(iVar3 + 8);

        }

        FUN_0043e3d0(*(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + (uVar4 + iVar1) * 4);

      }

      while (param_3 = uVar5, uVar5 != 0) {

        uVar5 = *(int *)(param_1 + 0xc) + (uVar7 - 1);

        uVar4 = uVar5 >> 2;

        iVar1 = uVar4 * -4;

        if (*(uint *)(param_1 + 8) <= uVar4) {

          uVar4 = uVar4 - *(uint *)(param_1 + 8);

        }

        FUN_0043e3d0(*(int *)(*(int *)(param_1 + 4) + uVar4 * 4) + (uVar5 + iVar1) * 4);

        uVar5 = param_3 - 1;

      }

      FUN_0043ec50(&param_4,iVar3,uVar6,param_6,param_7,param_1,*(int *)(param_1 + 0xc) + uVar7,

                   param_5);

      ExceptionList = local_10;

      return;

    }

    while (param_3 = uVar4, param_3 != 0) {

      uVar6 = *(int *)(param_1 + 0xc) + (uVar7 - 1);

      uVar4 = uVar6 >> 2;

      iVar3 = uVar4 * -4;

      if (*(uint *)(param_1 + 8) <= uVar4) {

        uVar4 = uVar4 - *(uint *)(param_1 + 8);

      }

      FUN_0043e3d0(*(int *)(*(int *)(param_1 + 4) + uVar4 * 4) + (uVar6 + iVar3) * 4);

      uVar4 = param_3 - 1;

    }

    iVar3 = *(int *)(param_1 + 0xc) + uVar7;

    param_2 = param_1;

    FUN_0043ec50(&param_2,param_1,iVar3 + uVar7,param_1,iVar3 + uVar5,param_1,iVar3,param_5);

    iVar3 = *(int *)(param_1 + 0xc) + uVar5;

  }

  else {

    local_8 = 2;

    if (uVar4 < uVar7) {

      uVar7 = param_5 + uVar4;

      ExceptionList = &local_10;

      param_3 = uVar7;

      for (; (iVar3 != param_6 || (uVar7 != param_7)); uVar7 = uVar7 + 1) {

        uVar6 = uVar7 >> 2;

        iVar1 = uVar6 * -4;

        if (*(uint *)(iVar3 + 8) <= uVar6) {

          uVar6 = uVar6 - *(uint *)(iVar3 + 8);

        }

        FUN_0043d670(*(int *)(*(int *)(iVar3 + 4) + uVar6 * 4) + (uVar7 + iVar1) * 4);

      }

      for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {

        uVar2 = *(int *)(param_1 + 0xc) + uVar5 + uVar7;

        uVar6 = uVar2 >> 2;

        iVar3 = uVar6 * -4;

        if (*(uint *)(param_1 + 8) <= uVar6) {

          uVar6 = uVar6 - *(uint *)(param_1 + 8);

        }

        FUN_0043d670(*(int *)(*(int *)(param_1 + 4) + uVar6 * 4) + (uVar2 + iVar3) * 4);

      }

      FUN_0043ec50(&param_4,param_4,param_5,param_2,param_3,param_1,*(int *)(param_1 + 0xc) + uVar5,

                   param_5);

      ExceptionList = local_10;

      return;

    }

    ExceptionList = &local_10;

    for (param_3 = 0; param_3 < uVar7; param_3 = param_3 + 1) {

      uVar2 = *(int *)(param_1 + 0xc) + (param_3 - uVar7) + uVar4 + uVar5;

      uVar6 = uVar2 >> 2;

      iVar3 = uVar6 * -4;

      if (*(uint *)(param_1 + 8) <= uVar6) {

        uVar6 = uVar6 - *(uint *)(param_1 + 8);

      }

      FUN_0043d670(*(int *)(*(int *)(param_1 + 4) + uVar6 * 4) + (uVar2 + iVar3) * 4);

    }

    iVar3 = *(int *)(param_1 + 0xc) + uVar5;

    FUN_0043ebb0(&param_2,param_1,iVar3,param_1,(iVar3 + uVar4) - uVar7,param_1,iVar3 + uVar4,

                 param_5);

  }

  FUN_0043ec50(&param_4,param_4,param_5,param_6,param_7,param_1,iVar3,param_5);

  ExceptionList = local_10;

  return;

}
