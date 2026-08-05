// =============================================================================
// Inv_vPrefixArmor
// -----------------------------------------------------------------------------
// Stable ID: aa_007d6e20
// Address:   0x007d6e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_vPrefixArmor @ 0x007d6e20
// Stable ID: aa_007d6e20
// Embedded strings (evidence for future rename):
//   - "//vPrefixArmor/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~347 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, do×2, while×2.
//  - Notable callees: block×100, FUN_004231d0×34, FUN_0041a3e0×4, _com_issue_error×3, CONCAT31×2, CoTaskMemAlloc×2, FUN_00423170×2, wcscpy×2.
//  - Strings: "//vPrefixArmor/row".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//vPrefixArmor/row"
 * Domain alias of FUN_007d6e20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007d80d9) */

/* WARNING: Removing unreachable block (ram,0x007d7873) */

/* WARNING: Removing unreachable block (ram,0x007d788b) */

/* WARNING: Removing unreachable block (ram,0x007d78a0) */

/* WARNING: Removing unreachable block (ram,0x007d78a6) */

/* WARNING: Removing unreachable block (ram,0x007d78df) */

/* WARNING: Removing unreachable block (ram,0x007d78f4) */

/* WARNING: Removing unreachable block (ram,0x007d78fa) */

/* WARNING: Removing unreachable block (ram,0x007d7923) */

/* WARNING: Removing unreachable block (ram,0x007d7938) */

/* WARNING: Removing unreachable block (ram,0x007d793e) */

/* WARNING: Removing unreachable block (ram,0x007d7967) */

/* WARNING: Removing unreachable block (ram,0x007d797c) */

/* WARNING: Removing unreachable block (ram,0x007d7982) */

/* WARNING: Removing unreachable block (ram,0x007d79ab) */

/* WARNING: Removing unreachable block (ram,0x007d79c0) */

/* WARNING: Removing unreachable block (ram,0x007d79c6) */

/* WARNING: Removing unreachable block (ram,0x007d79ef) */

/* WARNING: Removing unreachable block (ram,0x007d7a04) */

/* WARNING: Removing unreachable block (ram,0x007d7a0a) */

/* WARNING: Removing unreachable block (ram,0x007d7a33) */

/* WARNING: Removing unreachable block (ram,0x007d7a48) */

/* WARNING: Removing unreachable block (ram,0x007d7a4e) */

/* WARNING: Removing unreachable block (ram,0x007d7a77) */

/* WARNING: Removing unreachable block (ram,0x007d7a8c) */

/* WARNING: Removing unreachable block (ram,0x007d7a92) */

/* WARNING: Removing unreachable block (ram,0x007d7abb) */

/* WARNING: Removing unreachable block (ram,0x007d7ad0) */

/* WARNING: Removing unreachable block (ram,0x007d7ad6) */

/* WARNING: Removing unreachable block (ram,0x007d7b00) */

/* WARNING: Removing unreachable block (ram,0x007d7b15) */

/* WARNING: Removing unreachable block (ram,0x007d7b1b) */

/* WARNING: Removing unreachable block (ram,0x007d7b42) */

/* WARNING: Removing unreachable block (ram,0x007d7b57) */

/* WARNING: Removing unreachable block (ram,0x007d7b5d) */

/* WARNING: Removing unreachable block (ram,0x007d7b84) */

/* WARNING: Removing unreachable block (ram,0x007d7b99) */

/* WARNING: Removing unreachable block (ram,0x007d7b9f) */

/* WARNING: Removing unreachable block (ram,0x007d7bc3) */

/* WARNING: Removing unreachable block (ram,0x007d7bd8) */

/* WARNING: Removing unreachable block (ram,0x007d7bde) */

/* WARNING: Removing unreachable block (ram,0x007d7c03) */

/* WARNING: Removing unreachable block (ram,0x007d7c18) */

/* WARNING: Removing unreachable block (ram,0x007d7c1e) */

/* WARNING: Removing unreachable block (ram,0x007d7c43) */

/* WARNING: Removing unreachable block (ram,0x007d7c58) */

/* WARNING: Removing unreachable block (ram,0x007d7c5e) */

/* WARNING: Removing unreachable block (ram,0x007d7c86) */

/* WARNING: Removing unreachable block (ram,0x007d7c9b) */

/* WARNING: Removing unreachable block (ram,0x007d7ca1) */

/* WARNING: Removing unreachable block (ram,0x007d7cc6) */

/* WARNING: Removing unreachable block (ram,0x007d7cdb) */

/* WARNING: Removing unreachable block (ram,0x007d7ce1) */

/* WARNING: Removing unreachable block (ram,0x007d7d09) */

/* WARNING: Removing unreachable block (ram,0x007d7d1e) */

/* WARNING: Removing unreachable block (ram,0x007d7d24) */

/* WARNING: Removing unreachable block (ram,0x007d7d4c) */

/* WARNING: Removing unreachable block (ram,0x007d7d61) */

/* WARNING: Removing unreachable block (ram,0x007d7d67) */

/* WARNING: Removing unreachable block (ram,0x007d7d8f) */

/* WARNING: Removing unreachable block (ram,0x007d7da4) */

/* WARNING: Removing unreachable block (ram,0x007d7daa) */

/* WARNING: Removing unreachable block (ram,0x007d7dd2) */

/* WARNING: Removing unreachable block (ram,0x007d7de7) */

/* WARNING: Removing unreachable block (ram,0x007d7ded) */

/* WARNING: Removing unreachable block (ram,0x007d7e15) */

/* WARNING: Removing unreachable block (ram,0x007d7e2a) */

/* WARNING: Removing unreachable block (ram,0x007d7e30) */

/* WARNING: Removing unreachable block (ram,0x007d7e58) */

/* WARNING: Removing unreachable block (ram,0x007d7e6d) */

/* WARNING: Removing unreachable block (ram,0x007d7e73) */

/* WARNING: Removing unreachable block (ram,0x007d7e9b) */

/* WARNING: Removing unreachable block (ram,0x007d7eb0) */

/* WARNING: Removing unreachable block (ram,0x007d7eb6) */

/* WARNING: Removing unreachable block (ram,0x007d7edf) */

/* WARNING: Removing unreachable block (ram,0x007d7ef4) */

/* WARNING: Removing unreachable block (ram,0x007d7efa) */

/* WARNING: Removing unreachable block (ram,0x007d7f24) */

/* WARNING: Removing unreachable block (ram,0x007d7f39) */

/* WARNING: Removing unreachable block (ram,0x007d7f3f) */

/* WARNING: Removing unreachable block (ram,0x007d7f68) */

/* WARNING: Removing unreachable block (ram,0x007d7f7d) */

/* WARNING: Removing unreachable block (ram,0x007d7f83) */

/* WARNING: Removing unreachable block (ram,0x007d7fac) */

/* WARNING: Removing unreachable block (ram,0x007d7fc1) */

/* WARNING: Removing unreachable block (ram,0x007d7fc7) */

/* WARNING: Removing unreachable block (ram,0x007d7ff0) */

/* WARNING: Removing unreachable block (ram,0x007d8005) */

/* WARNING: Removing unreachable block (ram,0x007d800b) */

/* WARNING: Removing unreachable block (ram,0x007d8034) */

/* WARNING: Removing unreachable block (ram,0x007d8049) */

/* WARNING: Removing unreachable block (ram,0x007d804f) */

/* WARNING: Removing unreachable block (ram,0x007d807f) */

/* WARNING: Removing unreachable block (ram,0x007d8094) */

/* WARNING: Removing unreachable block (ram,0x007d809a) */

/* WARNING: Removing unreachable block (ram,0x007d80c4) */

/* WARNING: Removing unreachable block (ram,0x007d80df) */

/* WARNING: Removing unreachable block (ram,0x007d80fe) */

/* WARNING: Removing unreachable block (ram,0x007d8113) */

/* WARNING: Removing unreachable block (ram,0x007d8119) */



uint32_t /* width from decompiler */ __thiscall Inv_vPrefixArmor(char *param_1,int *param_2,int *param_3)



{

  int *piVar1;

  int iVar2;

  LPVOID pvVar3;

  int iVar4;

  IUnknown *pIVar5;

  ULONG UVar6;

  int *unaff_EBX;

  int *unaff_retaddr;

  int *piVar7;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ local_170;

  uint32_t /* width from decompiler */ *local_16c;

  uint32_t /* width from decompiler */ local_168;

  int local_164;

  uint32_t /* width from decompiler */ local_160;

  uint32_t /* width from decompiler */ *local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  uint32_t /* width from decompiler */ local_150;

  int *local_14c;

  IUnknown *local_148;

  uint8_t *local_144;

  uint16_t local_140;

  uint16_t local_13c;

  uint16_t local_138;

  short local_134;

  short local_130;

  uint16_t local_12c;

  uint16_t local_128;

  uint16_t local_124;

  int local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint16_t local_118;

  short local_114;

  uint16_t local_110;

  uint16_t local_10c;

  short local_108;

  uint16_t local_104;

  uint16_t local_100;

  uint32_t /* width from decompiler */ local_fc;

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  BSTR local_d8;

  BSTR local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  wchar_t local_b8 [34];

  wchar_t local_74 [50];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aeaab;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = 0;

  *param_2 = 0;

  if (*param_1 == '\0') {

    ExceptionList = pvStack_10;

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_15c = &local_174;

    local_174 = 0;

    local_170 = 0;

    local_16c = (uint32_t /* width from decompiler */ *)0x0;

    local_168 = 0;

    local_164 = 0;

    local_160 = 0;

    local_154 = 0;

    local_158 = 0;

    local_150 = 0;

    local_14c = (int *)0x0;

    local_4 = 0;

    iVar2 = FUN_0041a810(local_15c,param_1 + 0x28,0);

    local_16c = &local_fc;

    if (((((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

        (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

       ((((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

            ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

         ((((iVar2 = FUN_004231d0(), iVar2 < 0 ||

            (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

             (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

           (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

            (((iVar2 = FUN_004231d0(), iVar2 < 0 ||

              ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

             (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

          ((((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

            (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

           ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))))) ||

        (((iVar2 = FUN_004231d0(), iVar2 < 0 ||

          ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

         (local_164 == 0)))))) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      *param_3 = 0;

      *param_2 = 0;

      iVar2 = FUN_0041a9b0();

      if (iVar2 == 0) {

        if (local_108 < 1) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0;

        }

        *param_2 = (int)local_108;

        pvVar3 = CoTaskMemAlloc(local_108 * 0x11c);

        *param_3 = (int)pvVar3;

        if (pvVar3 == (LPVOID)0x0) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0x8007000e;

        }

        iVar2 = 0;

        do {

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x108 + iVar2) = local_cc;

          *(uint16_t *)(*param_3 + 0x10c + iVar2) = local_12c;

          *(uint16_t *)(*param_3 + 0x10e + iVar2) = local_124;

          *(uint16_t *)(*param_3 + 0x110 + iVar2) = local_104;

          *(uint16_t *)(*param_3 + 0x112 + iVar2) = local_10c;

          *(uint16_t *)(*param_3 + 0x114 + iVar2) = local_100;

          *(uint16_t *)(*param_3 + 0x116 + iVar2) = local_138;

          *(uint16_t *)(*param_3 + 0x118 + iVar2) = local_118;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x84 + iVar2) = local_f8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x10 + iVar2) = local_c4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 8 + iVar2) = local_f0;

          *(uint32_t /* width from decompiler */ *)(iVar2 + *param_3) = local_fc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x14 + iVar2) = local_d0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x18 + iVar2) = local_e8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x88 + iVar2) = local_c0;

          *(uint *)(*param_3 + 0xc + iVar2) = (uint)(local_130 == -1);

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x8c + iVar2) = local_e0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x90 + iVar2) = local_c8;

          *(BSTR *)(*param_3 + 0x94 + iVar2) = local_d8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x98 + iVar2) = local_bc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x9c + iVar2) = local_f4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xa0 + iVar2) = local_ec;

          *(uint *)(*param_3 + 0xa4 + iVar2) = (uint)(local_114 == -1);

          *(uint16_t *)(*param_3 + 0xa8 + iVar2) = local_128;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xac + iVar2) = local_e4;

          *(uint16_t *)(*param_3 + 0xb0 + iVar2) = local_110;

          *(uint16_t *)(*param_3 + 0xb2 + iVar2) = (uint16_t)local_120;

          *(uint16_t *)(*param_3 + 0xb4 + iVar2) = local_140;

          *(uint16_t *)(*param_3 + 0xb6 + iVar2) = local_13c;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xbc + iVar2) = local_dc;

          wcscpy((wchar_t *)(*param_3 + 0x1c + iVar2),local_74);

          wcscpy((wchar_t *)(*param_3 + 0xc4 + iVar2),local_b8);

          iVar2 = iVar2 + 0x11c;

          *(uint *)(*param_3 + -0x5c + iVar2) = (uint)(local_134 == -1);

          iVar4 = FUN_0041c000();

        } while (iVar4 == 0);

      }

      if (local_164 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    local_d4 = SysAllocString(L"//vPrefixArmor/row");

    if (local_d4 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_144 = &stack0xfffffe70;

    local_4 = 1;

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    pIVar5 = local_148;

    if (local_148 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

      pIVar5 = local_148;

    }

    local_11c = 0;

    UVar6 = (*pIVar5->lpVtbl[2].Release)(pIVar5);

    if ((int)UVar6 < 0) {

      _com_issue_errorex(UVar6,pIVar5,(_GUID *)&DAT_00a86118);

    }

    iVar2 = local_120;

    *unaff_retaddr = local_120;

    pvVar3 = CoTaskMemAlloc(local_120 * 0x11c);

    *param_3 = (int)pvVar3;

    local_148 = (IUnknown *)0x0;

    piVar7 = unaff_EBX;

    if (0 < iVar2) {

      do {

        pIVar5 = local_148;

        if (local_14c == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        piVar1 = local_14c;

        if (piVar7 != (int *)0x0) {

          (**(code **)(*piVar7 + 8))();

        }

        (**(code **)(*piVar1 + 0x1c))();

        unaff_EBX = (int *)0x0;

        local_148 = (IUnknown *)((int)pIVar5 + 1);

        piVar7 = (int *)0x0;

      } while ((int)local_148 < local_120);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

    if (local_14c != (int *)0x0) {

      (**(code **)(*local_14c + 8))();

    }

    SysFreeString(local_d8);

  }

  ExceptionList = pvStack_10;

  return 0;

}
