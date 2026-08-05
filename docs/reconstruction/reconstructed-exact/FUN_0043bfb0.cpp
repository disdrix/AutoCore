// =============================================================================
// FUN_0043bfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043bfb0
// Address:   0x0043bfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043bfb0 @ 0x0043bfb0
// Stable ID: aa_0043bfb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×16, return×4, for×2, do×1, while×1.
//  - Notable callees: FUN_0044ea70×4, FUN_00436ef0×2, FUN_0043bfb0, FUN_0043c710, FUN_004540b0.
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

void __thiscall FUN_0043bfb0(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint extraout_ECX;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bcbb0;

  local_10 = ExceptionList;

  param_4 = (uint32_t /* width from decompiler */ *)*param_4;

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = *(int *)(param_1 + 0xc) - iVar1 >> 2;

  }

  if (param_3 != 0) {

    if (iVar1 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;

    }

    uVar4 = param_3;

    ExceptionList = &local_10;

    if (0x3fffffffU - iVar5 < param_3) {

      ExceptionList = &local_10;

      iVar1 = FUN_004540b0();

      uVar4 = extraout_ECX;

    }

    if (iVar1 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;

    }

    if (uVar6 < iVar5 + uVar4) {

      if (0x3fffffff - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar1 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;

      }

      if (uVar6 < iVar5 + uVar4) {

        if (iVar1 == 0) {

          iVar1 = 0;

        }

        else {

          iVar1 = *(int *)(param_1 + 8) - iVar1 >> 2;

        }

        uVar6 = iVar1 + uVar4;

      }

      pvVar2 = operator_new(uVar6 * 4);

      local_8 = 0;

      FUN_0044ea70(param_3);

      FUN_00436ef0(param_3);

      FUN_0044ea70(param_3);

      iVar1 = *(int *)(param_1 + 4);

      if (iVar1 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;

      }

      if (iVar1 == 0) {

        *(void **)(param_1 + 0xc) = (void *)((int)pvVar2 + uVar6 * 4);

        *(void **)(param_1 + 8) = (void *)((int)pvVar2 + (param_3 + iVar5) * 4);

        *(void **)(param_1 + 4) = pvVar2;

        ExceptionList = local_10;

        return;

      }

      for (; iVar1 != *(int *)(param_1 + 8); iVar1 = iVar1 + 4) {

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 4));

    }

    if ((uint)(*(int *)(param_1 + 8) - (int)param_2 >> 2) < uVar4) {

      FUN_0044ea70(param_3);

      local_8 = 2;

      FUN_00436ef0(param_3);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar4 * 4;

      puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + uVar4 * -4);

      if (param_2 != puVar7) {

        do {

          if ((uint32_t /* width from decompiler */ **)param_2 != &param_4) {

            *param_2 = param_4;

          }

          param_2 = param_2 + 1;

        } while (param_2 != puVar7);

        ExceptionList = local_10;

        return;

      }

    }

    else {

      uVar3 = FUN_0044ea70(*(int *)(param_1 + 8) + uVar4 * -4);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

      FUN_0043c710();

      puVar7 = param_2 + uVar4;

      for (; param_2 != puVar7; param_2 = param_2 + 1) {

        if ((uint32_t /* width from decompiler */ **)param_2 != &param_4) {

          *param_2 = param_4;

        }

      }

    }

  }

  ExceptionList = local_10;

  return;

}
