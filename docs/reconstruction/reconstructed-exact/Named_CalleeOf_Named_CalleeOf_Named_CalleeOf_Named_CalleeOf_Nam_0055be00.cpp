// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0055be00
// -----------------------------------------------------------------------------
// Stable ID: aa_0055be00
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x0055be00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_0055b6a0×4, FUN_0055b5d0×2, FUN_00469c50, FUN_0055b3a0, FUN_0055b4d0, FUN_0055b7a0, FUN_0055bd90, FUN_0055be00.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0055be00(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint8_t *puVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  int iVar7;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a4860;

  local_10 = ExceptionList;

  local_30 = *param_4;

  local_2c = param_4[1];

  local_28 = param_4[2];

  local_24 = param_4[3];

  local_20 = param_4[4];

  iVar3 = *(int *)(param_1 + 4);

  local_1c = param_4[5];

  local_14 = &stack0xffffffc4;

  local_18 = param_4[6];

  if (iVar3 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar3) / 0x1c;

  }

  if (param_3 != 0) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    ExceptionList = &local_10;

    puVar2 = &stack0xffffffc4;

    if (0x9249249U - iVar3 < param_3) {

      ExceptionList = &local_10;

      FUN_0055b3a0();

      uVar6 = extraout_ECX;

      puVar2 = local_14;

    }

    local_14 = puVar2;

    if (*(int *)(param_1 + 4) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (uVar6 < iVar3 + param_3) {

      if (0x9249249 - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (uVar6 < iVar3 + param_3) {

        iVar3 = FUN_00469c50();

        uVar6 = iVar3 + param_3;

      }

      pvVar4 = operator_new(uVar6 * 0x1c);

      local_8 = 0;

      iVar3 = FUN_0055b6a0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar4,param_1,param_2);

      FUN_0055b7a0(iVar3,param_3,&local_30,param_1,param_2);

      FUN_0055b6a0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar3 + param_3 * 0x1c,param_1,param_2);

      iVar3 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 0x1c + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 0x1c);

      *(void **)(param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)(param_1 + 8);

    if ((uint)((iVar3 - param_2) / 0x1c) < param_3) {

      iVar1 = param_3 * 0x1c;

      FUN_0055b6a0(param_2,iVar3,iVar1 + param_2,param_1,iVar1);

      local_8 = 2;

      FUN_0055bd90(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x1c,

                   &local_30);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;

      FUN_0055b5d0(param_2,*(int *)(param_1 + 8) + param_3 * -0x1c,&local_30);

      ExceptionList = local_10;

      return;

    }

    iVar1 = param_3 * 0x1c;

    iVar7 = iVar3 + param_3 * -0x1c;

    uVar5 = FUN_0055b6a0(iVar7,iVar3,iVar3,param_1,iVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

    FUN_0055b4d0(param_2,iVar7,iVar3,iVar1);

    FUN_0055b5d0(param_2,iVar1 + param_2,&local_30);

  }

  ExceptionList = local_10;

  return;

}
