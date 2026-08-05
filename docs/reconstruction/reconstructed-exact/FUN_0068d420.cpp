// =============================================================================
// FUN_0068d420
// -----------------------------------------------------------------------------
// Stable ID: aa_0068d420
// Address:   0x0068d420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068d420 @ 0x0068d420
// Stable ID: aa_0068d420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×14, return×3.
//  - Notable callees: FUN_0068cec0×4, CONCAT31×2, FUN_0068c570×2, CONCAT44, FUN_0068b650, FUN_0068c370, FUN_0068c4b0, FUN_0068cfe0.
//  - Return sites: 3.

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

void __thiscall FUN_0068d420(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint64_t uVar7;

  uint8_t local_2c [4];

  void *local_28;

  void *local_1c;

  int local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aa408;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffc8;

  ExceptionList = &local_10;

  local_18 = param_1;

  FUN_0068c4b0(param_4);

  iVar3 = *(int *)(param_1 + 4);

  iVar6 = 0;

  local_8 = 0;

  if (iVar3 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0xc) - iVar3 >> 4;

  }

  uVar7 = CONCAT44(iVar3,iVar1);

  if (param_3 != 0) {

    if (iVar3 != 0) {

      iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

    }

    if (0xfffffffU - iVar6 < param_3) {

      uVar7 = FUN_0068b650();

    }

    iVar3 = (int)((ulonglong)uVar7 >> 0x20);

    uVar2 = (uint)uVar7;

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

    }

    if (uVar2 < iVar6 + param_3) {

      if (0xfffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar3 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

      }

      if (uVar2 < iVar6 + param_3) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_1 + 8) - iVar3 >> 4;

        }

        uVar2 = iVar3 + param_3;

      }

      pvVar4 = operator_new(uVar2 * 0x10);

      local_8 = CONCAT31(local_8._1_3_,1);

      local_1c = pvVar4;

      iVar3 = FUN_0068cec0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar4,param_1,param_2);

      FUN_0068d020(iVar3,param_3,local_2c,param_1,param_2);

      FUN_0068cec0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),iVar3 + param_3 * 0x10,param_1,param_2);

      iVar3 = *(int *)(param_1 + 4);

      if (iVar3 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

      }

      if (iVar3 != 0) {

        FUN_0068cfe0(iVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,param_2);

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 0x10 + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((param_3 + iVar6) * 0x10 + (int)pvVar4);

      *(void **)(param_1 + 4) = pvVar4;

    }

    else {

      local_1c = *(void **)(param_1 + 8);

      if ((uint)((int)local_1c - param_2 >> 4) < param_3) {

        FUN_0068cec0(param_2,local_1c,param_3 * 0x10 + param_2,param_1,param_2);

        local_8 = CONCAT31(local_8._1_3_,3);

        FUN_0068d210(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 4),local_2c

                    );

        iVar3 = *(int *)(param_1 + 8) + param_3 * 0x10;

        *(int *)(param_1 + 8) = iVar3;

        local_8 = 0;

        FUN_0068c570(param_2,iVar3 + param_3 * -0x10,local_2c);

      }

      else {

        pvVar4 = (void *)((int)local_1c + param_3 * -0x10);

        uVar5 = FUN_0068cec0(pvVar4,local_1c,local_1c,param_1,param_2);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

        FUN_0068c370(param_2,pvVar4,local_1c,param_2);

        FUN_0068c570(param_2,param_3 * 0x10 + param_2,local_2c);

      }

    }

  }

  if (local_28 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_28);

  }

  ExceptionList = local_10;

  return;

}
