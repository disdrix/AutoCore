// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00567950
// -----------------------------------------------------------------------------
// Stable ID: aa_00567950
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa
// Address:   0x00567950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_006a2be0×4, FUN_00419110×2, FUN_004af9e0, FUN_00566e80, FUN_00567420, FUN_00567950, FUN_006731e0.
//  - Return sites: 4.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00567950(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  uint8_t *puVar2;

  uint uVar3;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int extraout_ECX;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  void *local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a4c20;

  local_10 = ExceptionList;

  local_1c = param_4[1];

  local_20 = *param_4;

  iVar4 = *(int *)(param_1 + 4);

  local_14 = &stack0xffffffd4;

  if (iVar4 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_1 + 0xc) - iVar4 >> 3;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar4 >> 3;

    }

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffd4;

    if (0x1fffffffU - iVar7 < param_3) {

      ExceptionList = &local_10;

      uVar3 = FUN_00566e80();

      iVar4 = extraout_ECX;

      puVar2 = local_14;

    }

    local_14 = puVar2;

    if (iVar4 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar4 >> 3;

    }

    if (uVar3 < iVar7 + param_3) {

      if (0x1fffffff - (uVar3 >> 1) < uVar3) {

        uVar3 = 0;

      }

      else {

        uVar3 = uVar3 + (uVar3 >> 1);

      }

      if (iVar4 == 0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - iVar4 >> 3;

      }

      if (uVar3 < iVar7 + param_3) {

        if (iVar4 == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = *(int *)(param_1 + 8) - iVar4 >> 3;

        }

        uVar3 = iVar4 + param_3;

      }

      pvVar5 = operator_new(uVar3 * 8);

      local_8 = 0;

      local_18 = pvVar5;

      iVar4 = FUN_006a2be0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar5,param_1,param_2);

      FUN_00567420(iVar4,param_3,&local_20,param_1,param_2);

      FUN_006a2be0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar4 + param_3 * 8,param_1,param_2);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 8) - (int)pvVar1 >> 3;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar3 * 8 + (int)pvVar5);

      *(void **)(param_1 + 8) = (void *)((int)pvVar5 + (param_3 + iVar4) * 8);

      *(void **)(param_1 + 4) = pvVar5;

      ExceptionList = local_10;

      return;

    }

    iVar7 = *(int *)(param_1 + 8);

    iVar4 = param_3 * 8;

    if ((uint)(iVar7 - param_2 >> 3) < param_3) {

      FUN_006a2be0(param_2,iVar7,iVar4 + param_2,param_1,iVar4);

      local_8 = 2;

      FUN_004af9e0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 3),&local_20)

      ;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar4;

      FUN_00419110(param_2,*(int *)(param_1 + 8) + param_3 * -8,&local_20);

      ExceptionList = local_10;

      return;

    }

    iVar8 = iVar7 + param_3 * -8;

    uVar6 = FUN_006a2be0(iVar8,iVar7,iVar7,param_1,iVar4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

    FUN_006731e0(param_2,iVar8,iVar7);

    FUN_00419110(param_2,iVar4 + param_2,&local_20);

  }

  ExceptionList = local_10;

  return;

}
