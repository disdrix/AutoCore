// =============================================================================
// FUN_004497d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004497d0
// Address:   0x004497d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004497d0 @ 0x004497d0
// Stable ID: aa_004497d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×16, return×2.
//  - Notable callees: FUN_00449c90×4, CONCAT31×2, FUN_00449ae0×2, FUN_00449bd0×2, FUN_00449610, FUN_004497d0, FUN_00449b80, FUN_004540b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_004497d0(int *param_1,int param_2,int param_3,uint param_4)



{

  int *piVar1;

  uint8_t *puVar2;

  uint uVar3;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  int extraout_ECX;

  uint uVar7;

  int iVar8;

  uint64_t uVar9;

  int *local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bdf98;

  local_10 = ExceptionList;

  piVar1 = (int *)*param_1;

  local_14 = &stack0xffffffd4;

  ExceptionList = &local_10;

  puVar2 = &stack0xffffffd4;

  if ((piVar1 != (int *)0x0) &&

     (ExceptionList = &local_10, piVar1[1] = piVar1[1] + 1, puVar2 = &stack0xffffffd4,

     piVar1[1] == 1)) {

    (**(code **)(*piVar1 + 4))();

    puVar2 = local_14;

  }

  local_14 = puVar2;

  local_18 = (int *)*param_1;

  local_8 = 0;

  iVar4 = *(int *)(param_2 + 4);

  if (iVar4 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_2 + 0xc) - iVar4 >> 2;

  }

  if (param_4 != 0) {

    if (iVar4 == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(param_2 + 8) - iVar4 >> 2;

    }

    uVar7 = param_4;

    if (0x3fffffffU - iVar8 < param_4) {

      uVar9 = FUN_004540b0();

      uVar7 = (uint)((ulonglong)uVar9 >> 0x20);

      uVar3 = (uint)uVar9;

      iVar4 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(param_2 + 8) - iVar4 >> 2;

    }

    if (uVar3 < iVar8 + uVar7) {

      if (0x3fffffff - (uVar3 >> 1) < uVar3) {

        uVar3 = 0;

      }

      else {

        uVar3 = uVar3 + (uVar3 >> 1);

      }

      if (iVar4 == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(param_2 + 8) - iVar4 >> 2;

      }

      if (uVar3 < iVar8 + uVar7) {

        if (iVar4 == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = *(int *)(param_2 + 8) - iVar4 >> 2;

        }

        uVar3 = iVar4 + uVar7;

      }

      pvVar5 = operator_new(uVar3 * 4);

      local_8 = CONCAT31(local_8._1_3_,1);

      iVar4 = FUN_00449c90(param_3,pvVar5,param_4);

      FUN_00449bd0(iVar4,&local_18,param_4);

      FUN_00449c90(*(uint32_t /* width from decompiler */ *)(param_2 + 8),iVar4 + param_4 * 4,param_4);

      local_8 = 0;

      iVar4 = *(int *)(param_2 + 4);

      if (iVar4 == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(param_2 + 8) - iVar4 >> 2;

      }

      if (iVar4 != 0) {

        FUN_00449610();

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_2 + 4));

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar3 * 4 + (int)pvVar5);

      *(void **)(param_2 + 8) = (void *)((int)pvVar5 + (param_4 + iVar8) * 4);

      *(void **)(param_2 + 4) = pvVar5;

    }

    else {

      iVar4 = *(int *)(param_2 + 8);

      if ((uint)(iVar4 - param_3 >> 2) < uVar7) {

        FUN_00449c90(iVar4,uVar7 * 4 + param_3,param_4);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_00449bd0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),&local_18,param_4);

        local_8 = 0;

        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + uVar7 * 4;

        FUN_00449ae0(&local_18);

      }

      else {

        iVar8 = iVar4 + uVar7 * -4;

        uVar6 = FUN_00449c90(iVar4,iVar4,iVar8);

        *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar6;

        FUN_00449b80(param_3,iVar8);

        FUN_00449ae0(&local_18);

      }

    }

  }

  local_8 = 0xffffffff;

  if (local_18 != (int *)0x0) {

    piVar1 = local_18 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*local_18 + 8))();

    }

  }

  ExceptionList = local_10;

  return;

}
