// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_004464d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004464d0
// Callee of Named_CalleeOf_Named_effDeviceEffect
// Address:   0x004464d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_00448820×4, CONCAT31×2, FUN_00445600, FUN_004464b0, FUN_004464d0, FUN_00447170, FUN_00447320, FUN_00447cc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_effDeviceEffect
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

void Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_004464d0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint8_t local_e8 [212];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bee6b;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff0c;

  ExceptionList = &local_10;

  FUN_00447170(local_e8,param_4);

  uVar5 = 0;

  local_8 = 0;

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 != 0) {

    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0xd4;

  }

  if (param_3 != 0) {

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0xd4;

    }

    if (0x13521cfU - iVar1 < param_3) {

      FUN_004540b0();

      uVar5 = extraout_ECX;

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0xd4;

    }

    if (uVar5 < iVar1 + param_3) {

      if (0x13521cf - (uVar5 >> 1) < uVar5) {

        uVar5 = 0;

      }

      else {

        uVar5 = uVar5 + (uVar5 >> 1);

      }

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0xd4;

      }

      if (uVar5 < iVar2 + param_3) {

        iVar2 = FUN_00445600();

        uVar5 = iVar2 + param_3;

      }

      pvVar3 = operator_new(uVar5 * 0xd4);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar2 = FUN_00448820(param_2,pvVar3,param_2);

      FUN_00448380(iVar2,local_e8,param_2);

      FUN_00448820(*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar2 + param_3 * 0xd4,param_2);

      iVar2 = *(int *)(param_1 + 4);

      if (iVar2 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0xd4;

      }

      if (iVar2 != 0) {

        FUN_004464b0();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0xd4 + (int)pvVar3);

      *(void **)(param_1 + 8) = (void *)((int)pvVar3 + (param_3 + iVar1) * 0xd4);

      *(void **)(param_1 + 4) = pvVar3;

    }

    else {

      iVar2 = *(int *)(param_1 + 8);

      if ((uint)((iVar2 - param_2) / 0xd4) < param_3) {

        FUN_00448820(iVar2,param_3 * 0xd4 + param_2,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00447320(param_1);

        local_8 = 0;

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3 * 0xd4;

      }

      else {

        uVar4 = FUN_00448820(iVar2,iVar2,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        FUN_004482d0(param_2);

      }

      FUN_00447cc0();

    }

  }

  FUN_00964b70();

  ExceptionList = local_10;

  return;

}
