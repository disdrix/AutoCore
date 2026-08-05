// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_004617a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004617a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxDevice
// Address:   0x004617a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×14, return×2.
//  - Notable callees: FUN_004620b0×4, CONCAT31×2, FUN_00461b80×2, FUN_00461c90×2, FUN_004540b0, FUN_00461780, FUN_004617a0, FUN_00461ac0.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_004617a0(int param_1,int param_2,uint param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  int *local_24;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be5d8;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  FUN_00461ac0();

  uVar6 = 0;

  local_8 = 0;

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 != 0) {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar3) / 0x1c;

  }

  if (param_3 != 0) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (0x9249249U - iVar3 < param_3) {

      FUN_004540b0();

      uVar6 = extraout_ECX;

    }

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

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar3 = FUN_004620b0(param_2,pvVar4,param_2);

      FUN_00461c90(iVar3,param_2);

      FUN_004620b0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar3 + param_3 * 0x1c,param_2);

      local_8 = 0;

      iVar3 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (*(int *)(param_1 + 4) != 0) {

        FUN_00461780();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 0x1c + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 0x1c);

      *(void **)(param_1 + 4) = pvVar4;

    }

    else {

      iVar3 = *(int *)(param_1 + 8);

      iVar2 = param_3 * 0x1c;

      if ((uint)((iVar3 - param_2) / 0x1c) < param_3) {

        FUN_004620b0(iVar3,iVar2 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00461c90(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;

        FUN_00461b80(*(int *)(param_1 + 8) + param_3 * -0x1c);

      }

      else {

        uVar5 = FUN_004620b0(iVar3,iVar3,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

        FUN_00461ef0(param_2,iVar3 + param_3 * -0x1c,param_2);

        FUN_00461b80(iVar2 + param_2);

      }

    }

  }

  local_8 = 0xffffffff;

  if (local_24 != (int *)0x0) {

    piVar1 = local_24 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*local_24 + 8))();

    }

  }

  ExceptionList = local_10;

  return;

}
