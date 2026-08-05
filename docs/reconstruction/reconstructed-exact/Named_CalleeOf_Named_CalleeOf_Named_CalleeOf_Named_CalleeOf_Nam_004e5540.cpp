// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004e5540
// -----------------------------------------------------------------------------
// Stable ID: aa_004e5540
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004e5540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_004e2590×4, FUN_004e2530×2, FUN_004e5360×2, FUN_004e0e90, FUN_004e1050, FUN_004e1440, FUN_004e5540.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004e5540(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  uint extraout_ECX;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ local_148 [77];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a2550;

  local_10 = ExceptionList;

  puVar8 = local_148;

  for (iVar5 = 0x4d; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar8 = *param_4;

    param_4 = param_4 + 1;

    puVar8 = puVar8 + 1;

  }

  iVar5 = *(int *)(param_1 + 4);

  if (iVar5 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar5) / 0x134;

  }

  if (param_3 != 0) {

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar5) / 0x134;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xfffffeac;

    if (0xd4c77bU - iVar2 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xfffffeac;

      FUN_004e1050();

      uVar6 = extraout_ECX;

    }

    if (iVar5 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar5) / 0x134;

    }

    if (uVar6 < iVar2 + param_3) {

      if (0xd4c77b - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar5 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_1 + 8) - iVar5) / 0x134;

      }

      if (uVar6 < iVar5 + param_3) {

        iVar5 = FUN_004e0e90();

        uVar6 = iVar5 + param_3;

      }

      pvVar3 = operator_new(uVar6 * 0x134);

      local_8 = 0;

      uVar4 = FUN_004e2590(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar3,param_1,param_2);

      uVar4 = FUN_004e5360(uVar4,param_3,local_148);

      FUN_004e2590(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar4,param_1,param_2);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x134;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 0x134 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar5) * 0x134);

      *(void **)(param_1 + 4) = pvVar3;

      ExceptionList = local_10;

      return;

    }

    iVar5 = *(int *)(param_1 + 8);

    iVar2 = param_3 * 0x134;

    if ((uint)((iVar5 - param_2) / 0x134) < param_3) {

      FUN_004e2590(param_2,iVar5,iVar2 + param_2,param_1,param_2);

      local_8 = 2;

      FUN_004e5360(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x134,

                   local_148);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;

      FUN_004e2530(param_2,*(int *)(param_1 + 8) + param_3 * -0x134,local_148);

      ExceptionList = local_10;

      return;

    }

    iVar7 = iVar5 + param_3 * -0x134;

    uVar4 = FUN_004e2590(iVar7,iVar5,iVar5,param_1,param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_004e1440(param_2,iVar7,iVar5,param_2);

    FUN_004e2530(param_2,iVar2 + param_2,local_148);

  }

  ExceptionList = local_10;

  return;

}
