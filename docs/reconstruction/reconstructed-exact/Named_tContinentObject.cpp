// =============================================================================
// Named_tContinentObject
// -----------------------------------------------------------------------------
// Stable ID: aa_007dbce0
// Address:   0x007dbce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_tContinentObject @ 0x007dbce0
// Stable ID: aa_007dbce0
// Embedded strings (evidence for future rename):
//   - "//tContinentObject/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~294 non-empty decompiler lines.
//  - Control keywords: if×15, return×4, while×3, do×2, goto×1, for×1.
//  - Notable callees: block×64, FUN_004231d0×21, CONCAT31×2, FUN_00415e90×2, FUN_0041a3e0×2, FUN_0041ab70×2, FUN_0041c000×2, FUN_00423170×2.
//  - Strings: "//tContinentObject/row".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//tContinentObject/row"
 * Domain alias of FUN_007dbce0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007dc938) */

/* WARNING: Removing unreachable block (ram,0x007dc8be) */

/* WARNING: Removing unreachable block (ram,0x007dc45a) */

/* WARNING: Removing unreachable block (ram,0x007dc472) */

/* WARNING: Removing unreachable block (ram,0x007dc487) */

/* WARNING: Removing unreachable block (ram,0x007dc48d) */

/* WARNING: Removing unreachable block (ram,0x007dc4af) */

/* WARNING: Removing unreachable block (ram,0x007dc4c4) */

/* WARNING: Removing unreachable block (ram,0x007dc4ca) */

/* WARNING: Removing unreachable block (ram,0x007dc4ec) */

/* WARNING: Removing unreachable block (ram,0x007dc501) */

/* WARNING: Removing unreachable block (ram,0x007dc507) */

/* WARNING: Removing unreachable block (ram,0x007dc528) */

/* WARNING: Removing unreachable block (ram,0x007dc53d) */

/* WARNING: Removing unreachable block (ram,0x007dc543) */

/* WARNING: Removing unreachable block (ram,0x007dc565) */

/* WARNING: Removing unreachable block (ram,0x007dc57a) */

/* WARNING: Removing unreachable block (ram,0x007dc580) */

/* WARNING: Removing unreachable block (ram,0x007dc5a2) */

/* WARNING: Removing unreachable block (ram,0x007dc5b7) */

/* WARNING: Removing unreachable block (ram,0x007dc5bd) */

/* WARNING: Removing unreachable block (ram,0x007dc5df) */

/* WARNING: Removing unreachable block (ram,0x007dc5f4) */

/* WARNING: Removing unreachable block (ram,0x007dc5fa) */

/* WARNING: Removing unreachable block (ram,0x007dc61c) */

/* WARNING: Removing unreachable block (ram,0x007dc631) */

/* WARNING: Removing unreachable block (ram,0x007dc637) */

/* WARNING: Removing unreachable block (ram,0x007dc65c) */

/* WARNING: Removing unreachable block (ram,0x007dc671) */

/* WARNING: Removing unreachable block (ram,0x007dc677) */

/* WARNING: Removing unreachable block (ram,0x007dc69e) */

/* WARNING: Removing unreachable block (ram,0x007dc6b3) */

/* WARNING: Removing unreachable block (ram,0x007dc6b9) */

/* WARNING: Removing unreachable block (ram,0x007dc6de) */

/* WARNING: Removing unreachable block (ram,0x007dc6f3) */

/* WARNING: Removing unreachable block (ram,0x007dc6f9) */

/* WARNING: Removing unreachable block (ram,0x007dc720) */

/* WARNING: Removing unreachable block (ram,0x007dc735) */

/* WARNING: Removing unreachable block (ram,0x007dc73b) */

/* WARNING: Removing unreachable block (ram,0x007dc762) */

/* WARNING: Removing unreachable block (ram,0x007dc777) */

/* WARNING: Removing unreachable block (ram,0x007dc77d) */

/* WARNING: Removing unreachable block (ram,0x007dc7a2) */

/* WARNING: Removing unreachable block (ram,0x007dc7b7) */

/* WARNING: Removing unreachable block (ram,0x007dc7bd) */

/* WARNING: Removing unreachable block (ram,0x007dc7e2) */

/* WARNING: Removing unreachable block (ram,0x007dc7f7) */

/* WARNING: Removing unreachable block (ram,0x007dc7fd) */

/* WARNING: Removing unreachable block (ram,0x007dc822) */

/* WARNING: Removing unreachable block (ram,0x007dc837) */

/* WARNING: Removing unreachable block (ram,0x007dc83d) */

/* WARNING: Removing unreachable block (ram,0x007dc867) */

/* WARNING: Removing unreachable block (ram,0x007dc87c) */

/* WARNING: Removing unreachable block (ram,0x007dc882) */

/* WARNING: Removing unreachable block (ram,0x007dc8a9) */

/* WARNING: Removing unreachable block (ram,0x007dc8c4) */

/* WARNING: Removing unreachable block (ram,0x007dc8e3) */

/* WARNING: Removing unreachable block (ram,0x007dc8f8) */

/* WARNING: Removing unreachable block (ram,0x007dc8fe) */

/* WARNING: Removing unreachable block (ram,0x007dc923) */

/* WARNING: Removing unreachable block (ram,0x007dc93e) */

/* WARNING: Removing unreachable block (ram,0x007dc963) */

/* WARNING: Removing unreachable block (ram,0x007dc978) */

/* WARNING: Removing unreachable block (ram,0x007dc97e) */



void __thiscall Named_tContinentObject(char *param_1,int param_2)



{

  int *piVar1;

  IUnknown *This;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  ULONG UVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  short local_2f0;

  int *local_2ec;

  IUnknown *local_2e8;

  int local_2e4;

  uint32_t /* width from decompiler */ local_2e0;

  uint32_t /* width from decompiler */ local_2dc;

  uint32_t /* width from decompiler */ local_2d8;

  uint32_t /* width from decompiler */ *local_2d4;

  uint32_t /* width from decompiler */ local_2d0;

  int local_2cc;

  uint32_t /* width from decompiler */ local_2c8;

  uint32_t /* width from decompiler */ *local_2c4;

  uint32_t /* width from decompiler */ local_2c0;

  uint32_t /* width from decompiler */ local_2bc;

  uint32_t /* width from decompiler */ local_2b8;

  uint32_t /* width from decompiler */ local_2b4;

  short local_2b0;

  short local_2ac;

  short local_2a8;

  short local_2a4;

  BSTR local_2a0;

  short local_29c;

  uint32_t /* width from decompiler */ *local_294;

  uint32_t /* width from decompiler */ local_290;

  uint8_t *local_28c;

  uint32_t /* width from decompiler */ local_288;

  uint32_t /* width from decompiler */ local_280;

  uint32_t /* width from decompiler */ local_27c;

  uint32_t /* width from decompiler */ local_278;

  uint32_t /* width from decompiler */ local_270;

  uint local_258;

  uint local_254;

  uint local_250;

  wchar_t local_24c [66];

  uint local_1c8;

  uint32_t /* width from decompiler */ local_1c4;

  uint32_t /* width from decompiler */ local_1c0;

  uint32_t /* width from decompiler */ local_1bc;

  uint32_t /* width from decompiler */ local_1b8;

  wchar_t local_1b4 [66];

  uint32_t /* width from decompiler */ local_130;

  uint8_t *local_12c;

  BSTR local_128;

  uint local_120;

  uint local_11c;

  uint local_118;

  wchar_t local_114 [66];

  wchar_t local_90 [66];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aed60;

  pvStack_c = ExceptionList;

  local_2e8 = (IUnknown *)0x0;

  ExceptionList = &pvStack_c;

  local_294 = (uint32_t /* width from decompiler */ *)FUN_0041c5a0();

  local_290 = 0;

  local_4 = 0;

  if (DAT_00d1793c == '\0') {

    if (*param_1 == '\0') {

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_294);

    }

    local_2c4 = &local_2dc;

    local_2dc = 0;

    local_2d8 = 0;

    local_2d4 = (uint32_t /* width from decompiler */ *)0x0;

    local_2d0 = 0;

    local_2cc = 0;

    local_2c8 = 0;

    local_2bc = 0;

    local_2c0 = 0;

    local_2b8 = 0;

    local_2b4 = 0;

    local_4 = 1;

    iVar2 = FUN_0041a810(local_2c4,param_1 + 0x28,0);

    local_2d4 = &local_2e0;

    if ((((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

         (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

           ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

        ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

         ((((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

             (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

            ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

           ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

            ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

          (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

       ((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

         (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

        ((iVar2 = FUN_004231d0(), iVar2 < 0 || (local_2cc == 0)))))) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = local_4 & 0xffffff00;

      FUN_0041a3e0();

      FUN_00415e90();

      puVar4 = local_294;

      goto LAB_007dca02;

    }

    iVar2 = FUN_0041c000();

    puVar4 = local_294;

    while (local_294 = puVar4, iVar2 == 0) {

      local_258 = (uint)(local_2b0 == -1);

      local_250 = (uint)(local_2a8 == -1);

      wcscpy(local_24c,local_114);

      local_1c8 = (uint)(local_29c == -1);

      local_1c0 = local_280;

      local_254 = (uint)(local_2a4 == -1);

      local_128 = local_2a0;

      local_130 = local_27c;

      local_12c = local_28c;

      local_1c4 = local_288;

      local_120 = (uint)(local_2ac == -1);

      local_1bc = local_278;

      local_11c = (uint)((short)local_2e4 == -1);

      local_118 = (uint)(local_2f0 == -1);

      local_1b8 = local_270;

      wcscpy(local_1b4,local_90);

      piVar1 = local_294 + 1;

      iVar2 = FUN_0041f340();

      FUN_0041eab0();

      local_2e8 = (IUnknown *)((int)local_2e8 + 1);

      *piVar1 = iVar2;

      **(int **)(iVar2 + 4) = iVar2;

      iVar2 = FUN_0041c000();

      puVar4 = local_294;

    }

    if (local_2cc != 0) {

      FUN_00422de0();

      FUN_0041bf70();

    }

    FUN_00423170();

    FUN_0041ab70();

    puVar6 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

    puVar3 = (uint32_t /* width from decompiler */ *)*puVar4;

    if (0 < (int)local_2e8) {

      do {

        local_2e8 = (IUnknown *)((int)local_2e8 + -1);

        puVar7 = puVar3 + 2;

        puVar8 = puVar6;

        for (iVar2 = 0x55; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar8 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar8 = puVar8 + 1;

        }

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

        puVar6 = puVar6 + 0x55;

      } while (local_2e8 != (IUnknown *)0x0);

    }

    local_4 = local_4 & 0xffffff00;

    FUN_0041a3e0();

  }

  else {

    local_2a0 = SysAllocString(L"//tContinentObject/row");

    if (local_2a0 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_2e8 = (IUnknown *)0x0;

    local_28c = &stack0xfffffcfc;

    local_4._0_1_ = 4;

    FUN_00419ca0();

    local_4._0_1_ = 5;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,4);

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    This = (IUnknown *)*puVar4;

    if (This != (IUnknown *)0x0) {

      (*This->lpVtbl->AddRef)(This);

      local_2e8 = This;

    }

    if (local_2ec != (int *)0x0) {

      (**(code **)(*local_2ec + 8))();

    }

    if (local_2e8 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar5 = (*local_2e8->lpVtbl[2].Release)(local_2e8);

    if ((int)UVar5 < 0) {

      _com_issue_errorex(UVar5,local_2e8,(_GUID *)&DAT_00a86118);

    }

    FUN_0041ab70();

    local_2e4 = 0;

    if (0 < (int)local_2e8) {

      do {

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 8))();

        }

        (**(code **)(*local_2ec + 0x1c))();

        unaff_EBX = (int *)0x0;

        local_2e4 = local_2e4 + 1;

      } while (local_2e4 < (int)local_2e8);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    (**(code **)(*local_2ec + 8))();

    SysFreeString(local_2a0);

    puVar4 = local_294;

  }

  puVar6 = (uint32_t /* width from decompiler */ *)*puVar4;

  *puVar4 = puVar4;

  puVar4[1] = puVar4;

  if (puVar6 != puVar4) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar6);

  }

LAB_007dca02:

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar4);

}
