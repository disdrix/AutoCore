// =============================================================================
// FUN_007d9980
// -----------------------------------------------------------------------------
// Stable ID: aa_007d9980
// Address:   0x007d9980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007d9980 @ 0x007d9980
// Stable ID: aa_007d9980
// Embedded strings (evidence for future rename):
//   - "//tModule/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~212 non-empty decompiler lines.
//  - Control keywords: if×15, return×4, while×3, do×2, goto×1, for×1.
//  - Notable callees: block×22, FUN_004231d0×7, CONCAT31×2, FUN_00415e90×2, FUN_0041a3e0×2, FUN_0041ab70×2, FUN_0041c000×2, FUN_00423170×2.
//  - Strings: "//tModule/row".
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

/* WARNING: Removing unreachable block (ram,0x007d9f4e) */

/* WARNING: Removing unreachable block (ram,0x007d9dea) */

/* WARNING: Removing unreachable block (ram,0x007d9e02) */

/* WARNING: Removing unreachable block (ram,0x007d9e17) */

/* WARNING: Removing unreachable block (ram,0x007d9e1d) */

/* WARNING: Removing unreachable block (ram,0x007d9e3f) */

/* WARNING: Removing unreachable block (ram,0x007d9e54) */

/* WARNING: Removing unreachable block (ram,0x007d9e5a) */

/* WARNING: Removing unreachable block (ram,0x007d9e7c) */

/* WARNING: Removing unreachable block (ram,0x007d9e91) */

/* WARNING: Removing unreachable block (ram,0x007d9e97) */

/* WARNING: Removing unreachable block (ram,0x007d9eb8) */

/* WARNING: Removing unreachable block (ram,0x007d9ecd) */

/* WARNING: Removing unreachable block (ram,0x007d9ed3) */

/* WARNING: Removing unreachable block (ram,0x007d9efa) */

/* WARNING: Removing unreachable block (ram,0x007d9f0f) */

/* WARNING: Removing unreachable block (ram,0x007d9f15) */

/* WARNING: Removing unreachable block (ram,0x007d9f39) */

/* WARNING: Removing unreachable block (ram,0x007d9f54) */

/* WARNING: Removing unreachable block (ram,0x007d9f73) */

/* WARNING: Removing unreachable block (ram,0x007d9f88) */

/* WARNING: Removing unreachable block (ram,0x007d9f8e) */



void __thiscall FUN_007d9980(char *param_1,int param_2)



{

  IUnknown *This;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  ULONG UVar4;

  int *unaff_EBX;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  IUnknown *This_00;

  uint32_t /* width from decompiler */ *puVar7;

  int iStack_2f8;

  uint8_t *local_2f4;

  uint32_t /* width from decompiler */ uStack_2f0;

  int *local_2ec;

  IUnknown *local_2e8;

  uint32_t /* width from decompiler */ *local_2e0;

  uint32_t /* width from decompiler */ local_2dc;

  uint32_t /* width from decompiler */ local_2d8;

  uint32_t /* width from decompiler */ local_2d4;

  uint8_t **local_2d0;

  uint32_t /* width from decompiler */ local_2cc;

  int local_2c8;

  uint32_t /* width from decompiler */ local_2c4;

  uint32_t /* width from decompiler */ *local_2c0;

  uint32_t /* width from decompiler */ local_2bc;

  uint32_t /* width from decompiler */ local_2b8;

  uint32_t /* width from decompiler */ local_2b4;

  uint32_t /* width from decompiler */ local_2b0;

  BSTR local_2ac;

  wchar_t local_2a8 [38];

  uint8_t local_25c;

  wchar_t local_25a [33];

  uint8_t local_218;

  wchar_t local_216 [129];

  IUnknown *local_114;

  wchar_t local_110 [130];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aeb8c;

  pvStack_c = ExceptionList;

  iVar5 = 0;

  ExceptionList = &pvStack_c;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0041c5a0();

  local_2dc = 0;

  local_4 = 0;

  local_2e0 = puVar1;

  if (DAT_00d1793c == '\0') {

    if (*param_1 == '\0') {

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_2e0);

    }

    local_2c0 = &local_2d8;

    local_2d8 = 0;

    local_2d4 = 0;

    local_2d0 = (uint8_t **)0x0;

    local_2cc = 0;

    local_2c8 = 0;

    local_2c4 = 0;

    local_2b8 = 0;

    local_2bc = 0;

    local_2b4 = 0;

    local_2b0 = 0;

    local_4 = 1;

    iVar2 = FUN_0041a810(local_2c0,param_1 + 0x28,0);

    local_2d0 = &local_2f4;

    if ((((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

        ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

       (local_2c8 == 0)) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = local_4 & 0xffffff00;

      FUN_0041a3e0();

      FUN_00415e90();

      goto LAB_007da018;

    }

    iVar2 = FUN_0041c000();

    while (iVar2 == 0) {

      uStack_2f0._3_1_ = (uint8_t)((uint)uStack_2f0 >> 0x18);

      local_25c = uStack_2f0._3_1_;

      wcscpy(local_25a,local_2a8);

      local_218 = uStack_2f0._2_1_;

      wcscpy(local_216,local_110);

      local_114 = local_2e8;

      iVar2 = FUN_0041f340();

      FUN_0041eab0();

      puVar1[1] = iVar2;

      **(int **)(iVar2 + 4) = iVar2;

      iVar5 = iVar5 + 1;

      iVar2 = FUN_0041c000();

      puVar1 = local_2e0;

    }

    if (local_2c8 != 0) {

      FUN_00422de0();

      FUN_0041bf70();

    }

    FUN_00423170();

    FUN_0041ab70();

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

    puVar3 = (uint32_t /* width from decompiler */ *)*local_2e0;

    if (0 < iVar5) {

      do {

        iVar5 = iVar5 + -1;

        puVar6 = puVar3 + 2;

        puVar7 = puVar1;

        for (iVar2 = 0x55; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar7 = *puVar6;

          puVar6 = puVar6 + 1;

          puVar7 = puVar7 + 1;

        }

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

        puVar1 = puVar1 + 0x55;

      } while (iVar5 != 0);

    }

    local_4 = local_4 & 0xffffff00;

    FUN_0041a3e0();

  }

  else {

    local_2ac = SysAllocString(L"//tModule/row");

    if (local_2ac == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_2e8 = (IUnknown *)0x0;

    local_2f4 = &stack0xfffffcf0;

    local_4._0_1_ = 4;

    FUN_00419ca0();

    local_4._0_1_ = 5;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,4);

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    This = (IUnknown *)*puVar1;

    This_00 = (IUnknown *)0x0;

    if (This != (IUnknown *)0x0) {

      local_2e8 = This;

      (*This->lpVtbl->AddRef)(This);

      This_00 = local_2e8;

    }

    if (local_2ec != (int *)0x0) {

      (**(code **)(*local_2ec + 8))();

    }

    if (This_00 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_2f4 = (uint8_t *)0x0;

    UVar4 = (*This_00->lpVtbl[2].Release)(This_00);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,This_00,(_GUID *)&DAT_00a86118);

    }

    FUN_0041ab70();

    uStack_2f0 = 0;

    if (0 < iStack_2f8) {

      do {

        iVar5 = uStack_2f0;

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 8))();

        }

        (**(code **)(*local_2ec + 0x1c))();

        unaff_EBX = (int *)0x0;

        uStack_2f0 = iVar5 + 1;

      } while (uStack_2f0 < iStack_2f8);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    (**(code **)(*local_2ec + 8))();

    SysFreeString(local_2ac);

  }

  puVar1 = (uint32_t /* width from decompiler */ *)*local_2e0;

  *local_2e0 = local_2e0;

  local_2e0[1] = local_2e0;

  if (puVar1 != local_2e0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar1);

  }

LAB_007da018:

                    /* WARNING: Subroutine does not return */

  operator_delete(local_2e0);

}
