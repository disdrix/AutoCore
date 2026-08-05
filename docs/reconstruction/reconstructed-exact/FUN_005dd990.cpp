// =============================================================================
// FUN_005dd990
// -----------------------------------------------------------------------------
// Stable ID: aa_005dd990
// Address:   0x005dd990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dd990 @ 0x005dd990
// Stable ID: aa_005dd990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_005dd920×6, FUN_0043fb00×2, FUN_004cb1d0, FUN_0051b6e0, FUN_005dd990.
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

void __thiscall FUN_005dd990(int param_1,int param_2,int param_3,int param_4)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int extraout_ECX;

  int iVar6;

  uint uVar7;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a7240;

  local_10 = ExceptionList;

  iVar3 = *(int *)(param_1 + 4);

  uVar7 = param_4 - param_3 >> 4;

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_1 + 0xc) - iVar3 >> 4;

  }

  if (uVar7 != 0) {

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

    }

    ExceptionList = &local_10;

    if (0xfffffffU - iVar6 < uVar7) {

      ExceptionList = &local_10;

      uVar2 = FUN_004cb1d0();

      iVar3 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_1 + 8) - iVar3 >> 4;

    }

    if (uVar2 < iVar6 + uVar7) {

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

      if (uVar2 < iVar6 + uVar7) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_1 + 8) - iVar3 >> 4;

        }

        uVar2 = iVar3 + uVar7;

      }

      pvVar4 = operator_new(uVar2 * 0x10);

      local_8 = 0;

      uVar5 = FUN_005dd920(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar4,param_1,param_3);

      uVar5 = FUN_005dd920(param_3,param_4,uVar5,param_1,param_3);

      FUN_005dd920(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar5,param_1,param_3);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 8) - (int)pvVar1 >> 4;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 0x10 + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((uVar7 + iVar3) * 0x10 + (int)pvVar4);

      *(void **)(param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)(param_1 + 8);

    if ((uint)(iVar3 - param_2 >> 4) < uVar7) {

      FUN_005dd920(param_2,iVar3,uVar7 * 0x10 + param_2,param_1,param_3);

      iVar3 = (*(int *)(param_1 + 8) - param_2 >> 4) * 0x10 + param_3;

      local_8 = 2;

      FUN_005dd920(iVar3,param_4,*(int *)(param_1 + 8),param_1,param_3);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar7 * 0x10;

      FUN_0043fb00(param_3,iVar3,param_2,param_3);

      ExceptionList = local_10;

      return;

    }

    iVar6 = iVar3 + uVar7 * -0x10;

    uVar5 = FUN_005dd920(iVar6,iVar3,iVar3,param_1,param_3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

    FUN_0051b6e0(param_2,iVar6,iVar3,param_3);

    FUN_0043fb00(param_3,param_4,param_2,param_3);

  }

  ExceptionList = local_10;

  return;

}
