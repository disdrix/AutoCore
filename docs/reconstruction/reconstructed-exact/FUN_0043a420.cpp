// =============================================================================
// FUN_0043a420
// -----------------------------------------------------------------------------
// Stable ID: aa_0043a420
// Address:   0x0043a420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043a420 @ 0x0043a420
// Stable ID: aa_0043a420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_0044ea70×4, FUN_0046d110×2, CONCAT44, FUN_0043a420, FUN_0044ea50, FUN_004540b0, FUN_00469470, FUN_0046d0f0.
//  - Return sites: 4.

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

void __thiscall FUN_0043a420(int param_1,int param_2,int param_3,int param_4)



{

  void *pvVar1;

  uint uVar2;

  uint uVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  int iVar7;

  int iVar8;

  uint64_t uVar9;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd620;

  local_10 = ExceptionList;

  iVar7 = *(int *)(param_1 + 4);

  uVar2 = param_4 - param_3 >> 2;

  uVar9 = CONCAT44(iVar7,uVar2);

  if (iVar7 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = *(int *)(param_1 + 0xc) - iVar7 >> 2;

  }

  if (uVar2 != 0) {

    if (iVar7 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar7 >> 2;

    }

    ExceptionList = &local_10;

    if (0x3fffffffU - iVar7 < uVar2) {

      ExceptionList = &local_10;

      uVar9 = FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    iVar7 = (int)((ulonglong)uVar9 >> 0x20);

    uVar3 = (uint)uVar9;

    if (iVar7 == 0) {

      iVar8 = 0;

    }

    else {

      iVar8 = *(int *)(param_1 + 8) - iVar7 >> 2;

    }

    if (uVar6 < iVar8 + uVar3) {

      if (0x3fffffff - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar7 == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(param_1 + 8) - iVar7 >> 2;

      }

      if (uVar6 < iVar8 + uVar3) {

        if (iVar7 == 0) {

          iVar7 = 0;

        }

        else {

          iVar7 = *(int *)(param_1 + 8) - iVar7 >> 2;

        }

        uVar6 = iVar7 + uVar3;

      }

      pvVar4 = operator_new(uVar6 * 4);

      local_8 = 0;

      FUN_0044ea70(param_3);

      FUN_00469470(param_3,param_4,param_3);

      FUN_0044ea70(param_3);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 4 + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (uVar2 + iVar7) * 4);

      *(void **)(param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    if ((uint)(*(int *)(param_1 + 8) - param_2 >> 2) < uVar3) {

      FUN_0044ea70(param_3);

      iVar7 = param_3 + (*(int *)(param_1 + 8) - param_2 >> 2) * 4;

      local_8 = 2;

      FUN_0046d0f0(param_1,iVar7,param_4,*(int *)(param_1 + 8));

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar3 * 4;

      FUN_0046d110(param_3,iVar7);

      ExceptionList = local_10;

      return;

    }

    uVar5 = FUN_0044ea70(param_3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

    FUN_0044ea50();

    FUN_0046d110(param_3,param_4);

  }

  ExceptionList = local_10;

  return;

}
