// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0053c9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053c9b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0053c9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_0053c2a0×4, CONCAT31×2, FUN_0053ae40×2, FUN_0040f840, FUN_0040f9d0, FUN_00418130, FUN_0045c230, FUN_0053a7e0.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0053c9b0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ local_30 [2];

  void *local_28;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a3f38;

  local_10 = ExceptionList;

  local_30[0] = *param_4;

  local_14 = &stack0xffffffc4;

  ExceptionList = &local_10;

  local_18 = param_1;

  FUN_0040f840(param_4 + 1);

  iVar2 = *(int *)(param_1 + 4);

  uVar5 = 0;

  local_8 = 0;

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x14;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

    }

    if (0xcccccccU - iVar1 < param_3) {

      FUN_00418130();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0xccccccc - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x14;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_0045c230();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x14);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_1c = pvVar3;

      iVar2 = FUN_0053c2a0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      FUN_0053c860(iVar2,param_3,local_30,param_1,param_2);

      FUN_0053c2a0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x14,param_1,param_2);

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_0040f9d0(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x14 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar2) * 0x14);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      if ((uint)((iVar2 - param_2) / 0x14) < param_3) {

        FUN_0053c2a0(param_2,iVar2,param_3 * 0x14 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0053c980(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x14,

                     local_30);

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x14;

        local_8 = 0;

        FUN_0053ae40(param_2,*(int *)(param_1 + 8) + param_3 * -0x14,local_30);

      }

      else {

        iVar1 = iVar2 + param_3 * -0x14;

        uVar4 = FUN_0053c2a0(iVar1,iVar2,iVar2,param_1,iVar1);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_0053a7e0(param_2,iVar1,iVar2,iVar1);

        FUN_0053ae40(param_2,param_3 * 0x14 + param_2,local_30);

      }

    }

  }

  if (local_28 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_28);

  }

  ExceptionList = local_10;

  return;

}
