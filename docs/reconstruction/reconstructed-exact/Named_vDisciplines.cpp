// =============================================================================
// Named_vDisciplines
// -----------------------------------------------------------------------------
// Stable ID: aa_007c29f0
// Address:   0x007c29f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_vDisciplines @ 0x007c29f0
// Stable ID: aa_007c29f0
// Embedded strings (evidence for future rename):
//   - "//vDisciplines/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~261 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, while×2, for×2, do×1.
//  - Notable callees: block×58, FUN_004231d0×19, _com_issue_error×3, CONCAT31×2, FUN_00415e90×2, FUN_0041a3e0×2, FUN_0041b5c0×2, FUN_0041c000×2.
//  - Strings: "//vDisciplines/row".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//vDisciplines/row"
 * Domain alias of FUN_007c29f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007c355f) */

/* WARNING: Removing unreachable block (ram,0x007c34df) */

/* WARNING: Removing unreachable block (ram,0x007c3140) */

/* WARNING: Removing unreachable block (ram,0x007c3113) */

/* WARNING: Removing unreachable block (ram,0x007c312b) */

/* WARNING: Removing unreachable block (ram,0x007c3146) */

/* WARNING: Removing unreachable block (ram,0x007c3168) */

/* WARNING: Removing unreachable block (ram,0x007c317d) */

/* WARNING: Removing unreachable block (ram,0x007c3183) */

/* WARNING: Removing unreachable block (ram,0x007c31a5) */

/* WARNING: Removing unreachable block (ram,0x007c31ba) */

/* WARNING: Removing unreachable block (ram,0x007c31c0) */

/* WARNING: Removing unreachable block (ram,0x007c31e1) */

/* WARNING: Removing unreachable block (ram,0x007c31f6) */

/* WARNING: Removing unreachable block (ram,0x007c31fc) */

/* WARNING: Removing unreachable block (ram,0x007c321e) */

/* WARNING: Removing unreachable block (ram,0x007c3233) */

/* WARNING: Removing unreachable block (ram,0x007c3239) */

/* WARNING: Removing unreachable block (ram,0x007c325b) */

/* WARNING: Removing unreachable block (ram,0x007c3270) */

/* WARNING: Removing unreachable block (ram,0x007c3276) */

/* WARNING: Removing unreachable block (ram,0x007c3298) */

/* WARNING: Removing unreachable block (ram,0x007c32ad) */

/* WARNING: Removing unreachable block (ram,0x007c32b3) */

/* WARNING: Removing unreachable block (ram,0x007c32d5) */

/* WARNING: Removing unreachable block (ram,0x007c32ea) */

/* WARNING: Removing unreachable block (ram,0x007c32f0) */

/* WARNING: Removing unreachable block (ram,0x007c3313) */

/* WARNING: Removing unreachable block (ram,0x007c3328) */

/* WARNING: Removing unreachable block (ram,0x007c332e) */

/* WARNING: Removing unreachable block (ram,0x007c3351) */

/* WARNING: Removing unreachable block (ram,0x007c3366) */

/* WARNING: Removing unreachable block (ram,0x007c336c) */

/* WARNING: Removing unreachable block (ram,0x007c338f) */

/* WARNING: Removing unreachable block (ram,0x007c33a4) */

/* WARNING: Removing unreachable block (ram,0x007c33aa) */

/* WARNING: Removing unreachable block (ram,0x007c33cd) */

/* WARNING: Removing unreachable block (ram,0x007c33e2) */

/* WARNING: Removing unreachable block (ram,0x007c33e8) */

/* WARNING: Removing unreachable block (ram,0x007c340b) */

/* WARNING: Removing unreachable block (ram,0x007c3420) */

/* WARNING: Removing unreachable block (ram,0x007c3426) */

/* WARNING: Removing unreachable block (ram,0x007c344e) */

/* WARNING: Removing unreachable block (ram,0x007c3463) */

/* WARNING: Removing unreachable block (ram,0x007c3469) */

/* WARNING: Removing unreachable block (ram,0x007c3490) */

/* WARNING: Removing unreachable block (ram,0x007c34a5) */

/* WARNING: Removing unreachable block (ram,0x007c34ab) */

/* WARNING: Removing unreachable block (ram,0x007c34ca) */

/* WARNING: Removing unreachable block (ram,0x007c34e5) */

/* WARNING: Removing unreachable block (ram,0x007c350a) */

/* WARNING: Removing unreachable block (ram,0x007c351f) */

/* WARNING: Removing unreachable block (ram,0x007c3525) */

/* WARNING: Removing unreachable block (ram,0x007c354a) */

/* WARNING: Removing unreachable block (ram,0x007c3565) */

/* WARNING: Removing unreachable block (ram,0x007c358a) */

/* WARNING: Removing unreachable block (ram,0x007c359f) */

/* WARNING: Removing unreachable block (ram,0x007c35a5) */



uint32_t /* width from decompiler */ __thiscall Named_vDisciplines(char *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  ULONG UVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *unaff_EBX;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int *unaff_retaddr;

  uint32_t /* width from decompiler */ *puVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ uStack_458;

  IUnknown *local_454;

  uint32_t /* width from decompiler */ local_450;

  uint32_t /* width from decompiler */ local_44c;

  BSTR *local_448;

  uint32_t /* width from decompiler */ local_444;

  int local_440;

  uint32_t /* width from decompiler */ local_43c;

  uint32_t /* width from decompiler */ *local_438;

  uint32_t /* width from decompiler */ local_434;

  uint32_t /* width from decompiler */ local_430;

  uint32_t /* width from decompiler */ local_42c;

  int local_428;

  uint8_t *local_424;

  uint32_t /* width from decompiler */ *local_41c;

  uint32_t /* width from decompiler */ *local_418;

  uint32_t /* width from decompiler */ local_414;

  BSTR local_3fc;

  BSTR local_3f8;

  int local_3e4;

  int local_3dc;

  int local_3d4;

  ushort local_3aa;

  wchar_t local_3a6 [51];

  wchar_t local_340 [176];

  uint local_1e0;

  uint local_1dc;

  uint local_1d8;

  wchar_t local_1d4 [52];

  wchar_t local_16c [176];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  pvVar2 = ExceptionList;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae266;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_2 = 0;

  if (*param_1 == '\0') {

    ExceptionList = pvVar2;

    return 0x80004004;

  }

  local_418 = (uint32_t /* width from decompiler */ *)FUN_0041d4b0();

  local_414 = 0;

  local_4 = 0;

  if (DAT_00d1793c == '\0') {

    local_438 = &local_450;

    local_450 = 0;

    local_44c = 0;

    local_448 = (BSTR *)0x0;

    local_444 = 0;

    local_440 = 0;

    local_43c = 0;

    local_430 = 0;

    local_434 = 0;

    local_42c = 0;

    local_428 = 0;

    local_4 = 1;

    iVar3 = FUN_0041a810(local_438,param_1 + 0x28,0);

    local_448 = &local_3fc;

    if (((((((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

          (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           ((iVar3 = FUN_004231d0(), iVar3 < 0 ||

            ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||

         ((iVar3 = FUN_004231d0(), iVar3 < 0 ||

          (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           (iVar3 = FUN_004231d0(), iVar3 < 0)))))) ||

        (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

         (((iVar3 = FUN_004231d0(), iVar3 < 0 ||

           ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||

          (iVar3 = FUN_004231d0(), iVar3 < 0)))))) ||

       (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

        (local_440 == 0)))) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = local_4 & 0xffffff00;

      puVar9 = (uint32_t /* width from decompiler */ *)0x7c2dc1;

      FUN_0041a3e0();

      FUN_00415e90();

      local_41c = puVar9;

    }

    else {

      iVar3 = FUN_0041c000();

      puVar9 = local_418;

      while (local_418 = puVar9, iVar3 == 0) {

        local_3aa = (ushort)uStack_458._3_1_;

        wcscpy(local_3a6,local_1d4);

        wcscpy(local_340,local_16c);

        local_1e0 = (uint)(local_3e4 == -1);

        local_1dc = (uint)(local_3d4 == -1);

        local_1d8 = (uint)(local_3dc == -1);

        piVar10 = local_418 + 1;

        iVar3 = FUN_00420a00();

        FUN_00420a40();

        *piVar10 = iVar3;

        **(int **)(iVar3 + 4) = iVar3;

        iVar3 = FUN_0041c000();

        puVar9 = local_418;

      }

      *param_2 = local_414;

      if (local_440 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      FUN_0041b5c0();

      puVar5 = *(uint32_t /* width from decompiler */ **)(param_3 + 4);

      for (puVar1 = (uint32_t /* width from decompiler */ *)*puVar9; puVar1 != puVar9; puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

        puVar7 = puVar1 + 2;

        puVar8 = puVar5;

        for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

          *puVar8 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar8 = puVar8 + 1;

        }

        puVar5 = puVar5 + 0x7f;

      }

      local_4 = local_4 & 0xffffff00;

      puVar9 = (uint32_t /* width from decompiler */ *)0x7c2fda;

      FUN_0041a3e0();

      FUN_00415e90();

      local_41c = puVar9;

    }

  }

  else {

    local_3f8 = SysAllocString(L"//vDisciplines/row");

    if (local_3f8 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_424 = &stack0xfffffb8c;

    local_4._0_1_ = 2;

    FUN_00419ca0();

    local_4._0_1_ = 3;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 2;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,5);

    if (local_454 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_424 = (uint8_t *)0x0;

    UVar4 = (*local_454->lpVtbl[2].Release)(local_454);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,local_454,(_GUID *)&DAT_00a86118);

    }

    iVar3 = local_428;

    *unaff_retaddr = local_428;

    FUN_0041b5c0();

    iVar6 = 0;

    piVar10 = unaff_EBX;

    if (0 < iVar3) {

      do {

        if (uStack_458 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        if (piVar10 != (int *)0x0) {

          (**(code **)(*piVar10 + 8))();

        }

        (**(code **)(*uStack_458 + 0x1c))();

        unaff_EBX = (int *)0x0;

        iVar6 = iVar6 + 1;

        piVar10 = (int *)0x0;

      } while (iVar6 < local_428);

    }

    puStack_8._0_1_ = 4;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    if (uStack_458 != (int *)0x0) {

      (**(code **)(*uStack_458 + 8))();

    }

    SysFreeString(local_3fc);

    puVar9 = (uint32_t /* width from decompiler */ *)*local_41c;

    *local_41c = local_41c;

    local_41c[1] = local_41c;

    if (puVar9 != local_41c) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar9);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_41c);

}
