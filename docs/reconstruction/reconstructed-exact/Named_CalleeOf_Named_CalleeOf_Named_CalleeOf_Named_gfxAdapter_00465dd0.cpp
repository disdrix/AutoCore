// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter_00465dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00465dd0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
// Address:   0x00465dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×13, return×3.
//  - Notable callees: FUN_00466420×4, CONCAT31×2, FUN_00466190×2, FUN_00466330×2, FUN_00445550, FUN_004540b0, FUN_00465db0, FUN_00465dd0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxAdapter_00465dd0(int param_1,int param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_24 [4];

  void *local_20;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009be4a8;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffbc;

  ExceptionList = &local_10;

  FUN_004660e0(local_24);

  uVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x24;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x24;

    }

    if (0x71c71c7U - iVar1 < param_3) {

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x24;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x71c71c7 - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x24;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00445550();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0x24);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_00466420(pvVar3,param_2);

      FUN_00466330(iVar2,param_2);

      FUN_00466420(iVar2 + param_3 * 0x24,param_2);

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x24;

      }

      if (iVar2 != 0) {

        FUN_00465db0();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x24 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar1) * 0x24);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = param_3 * 0x24;

      if ((uint)((*(int *)(param_1 + 8) - param_2) / 0x24) < param_3) {

        FUN_00466420(iVar2 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00466330(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;

        FUN_00466190(*(int *)(param_1 + 8) + param_3 * -0x24);

      }

      else {

        uVar4 = FUN_00466420(*(int *)(param_1 + 8),param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_004663d0(param_2);

        FUN_00466190(iVar2 + param_2);

      }

    }

  }

  if (local_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_20);

  }

  ExceptionList = local_10;

  return;

}
