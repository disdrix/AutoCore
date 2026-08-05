// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068a1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068a1d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068a1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_00687d10×4, FUN_006860f0×2, FUN_00469c50, FUN_00686070, FUN_00687ce0, FUN_00688550, FUN_0068a1a0, FUN_0068a1d0.
//  - Return sites: 4.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068a1d0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_30 [7];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aa170;

  local_10 = ExceptionList;

  puVar6 = local_30;

  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *param_4;

    param_4 = param_4 + 1;

    puVar6 = puVar6 + 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar4) / 0x1c;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xffffffc4;

    if (0x9249249U - iVar4 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffffc4;

      FUN_00686070();

      uVar5 = extraout_ECX;

    }

    if (*(int *)(param_1 + 4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

    }

    if (uVar5 < iVar4 + param_3) {

      if (0x9249249 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (*(int *)(param_1 + 4) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (uVar5 < iVar4 + param_3) {

        iVar4 = FUN_00469c50();

        uVar5 = iVar4 + param_3;

      }

      pvVar1 = operator_new(uVar5 * 0x1c);

      local_8 = 0;

      iVar4 = FUN_00687d10(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar1,param_1,param_2);

      FUN_00688550(iVar4,param_3,local_30,param_1,param_2);

      FUN_00687d10(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar4 + param_3 * 0x1c,param_1,param_2);

      iVar4 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x1c + (int)pvVar1);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar4) * 0x1c + (int)pvVar1);

      *(void **)(param_1 + 4) = pvVar1;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)((iVar4 - param_2) / 0x1c) < param_3) {

      iVar2 = param_3 * 0x1c;

      FUN_00687d10(param_2,iVar4,iVar2 + param_2,param_1,iVar2);

      local_8 = 2;

      FUN_0068a1a0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x1c,

                   local_30);

      iVar2 = *(int *)(param_1 + 8) + iVar2;

      *(int *)(param_1 + 8) = iVar2;

      FUN_006860f0(param_2,iVar2 + param_3 * -0x1c,local_30);

      ExceptionList = local_10;

      return;

    }

    iVar2 = iVar4 + param_3 * -0x1c;

    uVar3 = FUN_00687d10(iVar2,iVar4,iVar4,param_1,iVar2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    FUN_00687ce0(param_2,iVar2,iVar4);

    FUN_006860f0(param_2,param_3 * 0x1c + param_2,local_30);

  }

  ExceptionList = local_10;

  return;

}
