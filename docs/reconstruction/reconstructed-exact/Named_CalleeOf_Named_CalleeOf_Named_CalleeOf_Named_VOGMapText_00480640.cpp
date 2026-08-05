// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGMapText_00480640
// -----------------------------------------------------------------------------
// Stable ID: aa_00480640
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGMapText
// Address:   0x00480640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOGMapText: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×12, return×4, for×1.
//  - Notable callees: FUN_00480610×2, FUN_00480900×2, FUN_00480920×2, FUN_00480a30×2, FUN_00410e70, FUN_004540b0, FUN_00480640, FUN_00480950.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGMapText
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGMapText_00480640(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_dc [50];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc860;

  local_10 = ExceptionList;

  puVar6 = local_dc;

  for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *param_4;

    param_4 = param_4 + 1;

    puVar6 = puVar6 + 1;

  }

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar4) / 200;

  }

  if (param_3 != 0) {

    if (iVar4 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar4) / 200;

    }

    ExceptionList = &local_10;

    local_14 = &stack0xffffff18;

    if (0x147ae14U - iVar1 < param_3) {

      ExceptionList = &local_10;

      local_14 = &stack0xffffff18;

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar4) / 200;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x147ae14 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - iVar4) / 200;

      }

      if (uVar5 < iVar4 + param_3) {

        iVar4 = FUN_00410e70();

        uVar5 = iVar4 + param_3;

      }

      pvVar2 = operator_new(uVar5 * 200);

      local_8 = 0;

      uVar3 = FUN_00480a30(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar2,param_1,param_2);

      uVar3 = FUN_00480610(uVar3,param_3,local_dc);

      FUN_00480a30(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar3,param_1,param_2);

      iVar4 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 200;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 200 + (int)pvVar2);

      *(void **)(param_1 + 8) = (void *)((int)pvVar2 + (param_3 + iVar4) * 200);

      *(void **)(param_1 + 4) = pvVar2;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)((iVar4 - param_2) / 200) < param_3) {

      FUN_00480900(param_2,iVar4,param_3 * 200 + param_2);

      local_8 = 2;

      FUN_00480610(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 200,local_dc)

      ;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 200;

      FUN_00480920(param_2,*(int *)(param_1 + 8) + param_3 * -200,local_dc);

      ExceptionList = local_10;

      return;

    }

    iVar1 = iVar4 + param_3 * -200;

    uVar3 = FUN_00480900(iVar1,iVar4,iVar4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    FUN_00480950(param_2,iVar1,iVar4);

    FUN_00480920(param_2,param_3 * 200 + param_2,local_dc);

  }

  ExceptionList = local_10;

  return;

}
