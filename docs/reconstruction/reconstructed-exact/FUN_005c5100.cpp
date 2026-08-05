// =============================================================================
// FUN_005c5100
// -----------------------------------------------------------------------------
// Stable ID: aa_005c5100
// Address:   0x005c5100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c5100 @ 0x005c5100
// Stable ID: aa_005c5100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_004560f0×6, FUN_0057fb40×2, FUN_004540b0, FUN_00456080, FUN_00480c80, FUN_005c5100.
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

void __thiscall FUN_005c5100(int param_1,int param_2,int param_3,int param_4)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a6d50;

  local_10 = ExceptionList;

  iVar3 = *(int *)(param_1 + 4);

  uVar1 = (param_4 - param_3) / 0xc;

  if (iVar3 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)(param_1 + 0xc) - iVar3) / 0xc;

  }

  if (uVar1 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0xc;

    }

    ExceptionList = &local_10;

    if (0x15555555U - iVar2 < uVar1) {

      ExceptionList = &local_10;

      FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0xc;

    }

    if (uVar6 < iVar2 + uVar1) {

      if (0x15555555 - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar3 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)(param_1 + 8) - iVar3) / 0xc;

      }

      if (uVar6 < iVar3 + uVar1) {

        iVar3 = FUN_00480c80();

        uVar6 = iVar3 + uVar1;

      }

      pvVar4 = operator_new(uVar6 * 0xc);

      local_8 = 0;

      uVar5 = FUN_004560f0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar4,param_1,param_3);

      uVar5 = FUN_004560f0(param_3,param_4,uVar5,param_1,param_3);

      FUN_004560f0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar5,param_1,param_3);

      iVar3 = 0;

      if (*(int *)(param_1 + 4) != 0) {

        iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;

      }

      if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 4));

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 0xc + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0xc);

      *(void **)(param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    iVar3 = *(int *)(param_1 + 8);

    if ((uint)((iVar3 - param_2) / 0xc) < uVar1) {

      FUN_004560f0(param_2,iVar3,uVar1 * 0xc + param_2,param_1,param_3);

      iVar3 = param_3 + ((*(int *)(param_1 + 8) - param_2) / 0xc) * 0xc;

      local_8 = 2;

      FUN_004560f0(iVar3,param_4,*(int *)(param_1 + 8),param_1,param_3);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar1 * 0xc;

      FUN_0057fb40(param_3,iVar3,param_2,param_3);

      ExceptionList = local_10;

      return;

    }

    iVar2 = iVar3 + uVar1 * -0xc;

    uVar5 = FUN_004560f0(iVar2,iVar3,iVar3,param_1,param_3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

    FUN_00456080(param_2,iVar2,iVar3,param_3);

    FUN_0057fb40(param_3,param_4,param_2,param_3);

  }

  ExceptionList = local_10;

  return;

}
