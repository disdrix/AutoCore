// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438520
// -----------------------------------------------------------------------------
// Stable ID: aa_00438520
// Callee of Named_CalleeOf_Named_gfxBody
// Address:   0x00438520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_0043aac0×4, CONCAT31×2, FUN_00439e00×2, FUN_0043a8c0×2, FUN_00437da0, FUN_004384f0, FUN_00438520, FUN_00439510.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxBody
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438520(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_4c [56];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bcc68;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffa8;

  ExceptionList = &local_10;

  FUN_00439510(param_4);

  uVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x38;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

    }

    if (0x4924924U - iVar2 < param_3) {

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

    }

    if (uVar5 < iVar2 + param_3) {

      if (0x4924924 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00690210();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x38);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_0043aac0(param_2,pvVar3,param_2);

      FUN_0043a8c0(iVar2,local_4c,param_2);

      FUN_0043aac0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x38,param_2);

      local_8 = 0;

      iVar2 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_004384f0(*(int *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x38 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar2) * 0x38);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      iVar1 = param_3 * 0x38;

      if ((uint)((iVar2 - param_2) / 0x38) < param_3) {

        FUN_0043aac0(iVar2,iVar1 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0043a8c0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_4c,param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar1;

        FUN_00439e00(*(int *)(param_1 + 8) + param_3 * -0x38);

      }

      else {

        uVar4 = FUN_0043aac0(iVar2,iVar2,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_0043a720(param_2);

        FUN_00439e00(iVar1 + param_2);

      }

    }

  }

  local_8 = 0xffffffff;

  FUN_00437da0();

  ExceptionList = local_10;

  return;

}
