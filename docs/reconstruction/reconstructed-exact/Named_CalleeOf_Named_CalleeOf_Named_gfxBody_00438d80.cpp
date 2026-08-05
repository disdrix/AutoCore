// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00438d80
// Callee of Named_CalleeOf_Named_gfxBody
// Address:   0x00438d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: if×17, return×2.
//  - Notable callees: FUN_0043ac00×4, CONCAT31×2, FUN_00439e60×2, FUN_0043a660×2, CONCAT44, FUN_00438d60, FUN_00438d80, FUN_0043a7e0.
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxBody_00438d80(int param_1,int param_2,uint param_3,int param_4)



{

  int *piVar1;

  uint8_t *puVar2;

  int iVar3;

  uint uVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint extraout_ECX;

  uint uVar7;

  int *piVar8;

  int iVar9;

  uint64_t uVar10;

  undefined **local_20;

  int *local_1c;

  void *local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be158;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffd4;

  if (param_4 == 0) {

    piVar8 = (int *)0x0;

  }

  else {

    piVar8 = (int *)(param_4 + 4);

  }

  piVar1 = (int *)*piVar8;

  ExceptionList = &local_10;

  puVar2 = &stack0xffffffd4;

  if ((piVar1 != (int *)0x0) &&

     (ExceptionList = &local_10, piVar1[1] = piVar1[1] + 1, puVar2 = &stack0xffffffd4,

     piVar1[1] == 1)) {

    (**(code **)(*piVar1 + 4))();

    puVar2 = local_14;

  }

  local_14 = puVar2;

  local_1c = (int *)*piVar8;

  local_20 = &PTR_FUN_00a9da78;

  local_8 = 0;

  iVar9 = *(int *)(param_1 + 4);

  if (iVar9 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(param_1 + 0xc) - iVar9 >> 3;

  }

  uVar10 = CONCAT44(iVar9,iVar3);

  if (param_3 != 0) {

    if (iVar9 == 0) {

      iVar9 = 0;

    }

    else {

      iVar9 = *(int *)(param_1 + 8) - iVar9 >> 3;

    }

    uVar7 = param_3;

    if (0x1fffffffU - iVar9 < param_3) {

      uVar10 = FUN_004540b0();

      uVar7 = extraout_ECX;

    }

    iVar9 = (int)((ulonglong)uVar10 >> 0x20);

    uVar4 = (uint)uVar10;

    if (iVar9 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 8) - iVar9 >> 3;

    }

    if (uVar4 < iVar3 + uVar7) {

      if (0x1fffffff - (uVar4 >> 1) < uVar4) {

        uVar4 = 0;

      }

      else {

        uVar4 = uVar4 + (uVar4 >> 1);

      }

      if (iVar9 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 8) - iVar9 >> 3;

      }

      if (uVar4 < iVar3 + uVar7) {

        if (iVar9 == 0) {

          iVar9 = 0;

        }

        else {

          iVar9 = *(int *)(param_1 + 8) - iVar9 >> 3;

        }

        uVar4 = iVar9 + uVar7;

      }

      pvVar5 = operator_new(uVar4 * 8);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_18 = pvVar5;

      iVar9 = FUN_0043ac00(pvVar5,param_3);

      FUN_0043a660(iVar9,param_3);

      FUN_0043ac00(iVar9 + param_3 * 8,param_3);

      local_8 = 0;

      iVar9 = *(int *)(param_1 + 4);

      if (iVar9 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 8) - iVar9 >> 3;

      }

      if (iVar9 != 0) {

        FUN_00438d60();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar4 * 8 + (int)pvVar5);

      *(void **)(param_1 + 8) = (void *)((int)pvVar5 + (param_3 + iVar3) * 8);

      *(void **)(param_1 + 4) = pvVar5;

    }

    else {

      iVar9 = *(int *)(param_1 + 8);

      if ((uint)(iVar9 - param_2 >> 3) < uVar7) {

        FUN_0043ac00(uVar7 * 8 + param_2,param_3);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0043a660(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar7 * 8;

        FUN_00439e60(&local_20);

      }

      else {

        iVar3 = iVar9 + uVar7 * -8;

        uVar6 = FUN_0043ac00(iVar9,iVar3);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

        FUN_0043a7e0(param_2,iVar3);

        FUN_00439e60(&local_20);

      }

    }

  }

  local_8 = 0xffffffff;

  if (local_1c != (int *)0x0) {

    piVar8 = local_1c + 1;

    *piVar8 = *piVar8 + -1;

    if (*piVar8 == 0) {

      (**(code **)(*local_1c + 8))();

    }

  }

  ExceptionList = local_10;

  return;

}
