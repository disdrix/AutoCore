// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0046b130
// -----------------------------------------------------------------------------
// Stable ID: aa_0046b130
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBodyMassa
// Address:   0x0046b130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBodyMassa: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×14, return×3.
//  - Notable callees: FUN_0046b730×4, CONCAT31×2, FUN_0046b610×2, FUN_0040f840, FUN_00426f20, FUN_004540b0, FUN_0046b130, FUN_0046b530.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBodyMassa
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0046b130(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  uint uVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int extraout_ECX;

  int iVar5;

  uint8_t local_24 [4];

  void *local_20;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be378;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffd0;

  ExceptionList = &local_10;

  FUN_0040f840(param_4);

  iVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 0xc) - iVar2 >> 4;

  }

  if (param_3 != 0) {

    if (iVar2 != 0) {

      iVar5 = *(int *)(param_1 + 8) - iVar2 >> 4;

    }

    if (0xfffffffU - iVar5 < param_3) {

      uVar1 = FUN_004540b0();

      iVar2 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 8) - iVar2 >> 4;

    }

    if (uVar1 < iVar5 + param_3) {

      if (0xfffffff - (uVar1 >> 1) < uVar1) {

        uVar1 = 0;

      }

      else {

        uVar1 = uVar1 + (uVar1 >> 1);

      }

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar2 >> 4;

      }

      if (uVar1 < iVar5 + param_3) {

        if (iVar2 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_1 + 8) - iVar2 >> 4;

        }

        uVar1 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar1 * 0x10);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_0046b730(param_2,pvVar3,param_1,param_2);

      FUN_0046b610(iVar2,local_24,param_1,param_2);

      FUN_0046b730(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0x10,param_1,param_2);

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar2 >> 4;

      }

      if (iVar2 != 0) {

        FUN_00426f20(param_2);

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar1 * 0x10 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar5) * 0x10 + (int)pvVar3);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      if ((uint)(iVar2 - param_2 >> 4) < param_3) {

        FUN_0046b730(iVar2,param_3 * 0x10 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0046b610(*(uint32_t /* width from decompiler */ *)(param_1 + 8),local_24,param_1,param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0x10;

      }

      else {

        uVar4 = FUN_0046b730(iVar2,iVar2,param_1,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_0046b550();

      }

      FUN_0046b530();

    }

  }

  if (local_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_20);

  }

  ExceptionList = local_10;

  return;

}
