// =============================================================================
// FUN_007c8890
// -----------------------------------------------------------------------------
// Stable ID: aa_007c8890
// Address:   0x007c8890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007c8890 @ 0x007c8890
// Stable ID: aa_007c8890
// Embedded strings (evidence for future rename):
//   - "//tWeaponGroup/row"
//   - "strName"
//   - "IDWeaponGroup"
//   - "//tWeaponGroup_x/row"
//   - "CBIDWeapon"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~370 non-empty decompiler lines.
//  - Control keywords: if×36, return×8, while×8, goto×4, do×2.
//  - Notable callees: CONCAT31×8, SysAllocString×6, _com_issue_error×6, FUN_0041a3e0×5, block×5, FUN_0041c000×4, FUN_00423170×4, FUN_004231d0×4.
//  - Strings: "//tWeaponGroup/row"; "strName"; "IDWeaponGroup"; "//tWeaponGroup_x/row".
//  - Return sites: 8.

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

/* WARNING: Removing unreachable block (ram,0x007c8f4d) */

/* WARNING: Removing unreachable block (ram,0x007c904c) */

/* WARNING: Removing unreachable block (ram,0x007c8ece) */

/* WARNING: Removing unreachable block (ram,0x007c9062) */

/* WARNING: Removing unreachable block (ram,0x007c8d81) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall FUN_007c8890(char *param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  int iVar6;

  wchar_t *_Dest;

  uint32_t /* width from decompiler */ *puVar7;

  ULONG UVar8;

  void *pvVar9;

  BSTR pOVar10;

  uint32_t /* width from decompiler */ uVar11;

  LPVOID pvVar12;

  int *unaff_EBX;

  int unaff_EBP;

  IUnknown *pIVar13;

  int iVar14;

  int *unaff_ESI;

  int *piVar15;

  IUnknown *pIVar16;

  IUnknown *local_100;

  IUnknown *local_fc;

  uint32_t /* width from decompiler */ *local_f4;

  int local_f0;

  void *local_ec;

  uint32_t /* width from decompiler */ *local_e8;

  int local_e4;

  int local_e0;

  BSTR local_dc;

  BSTR pOStack_d8;

  BSTR local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ **local_c8;

  uint32_t /* width from decompiler */ local_c4;

  int local_c0;

  uint32_t /* width from decompiler */ local_bc;

  uint32_t /* width from decompiler */ *local_b8;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ **local_9c;

  uint32_t /* width from decompiler */ local_98;

  int local_94;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ *local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  wchar_t local_74 [52];

  void *pvStack_c;

  uint8_t *puStack_8;

  int *local_4;

  

  local_4 = (int *)0xffffffff;

  puStack_8 = &LAB_009ae551;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_e0 = FUN_00439770();

  *(uint8_t *)(local_e0 + 0x15) = 1;

  *(int *)(local_e0 + 4) = local_e0;

  *(int *)local_e0 = local_e0;

  *(int *)(local_e0 + 8) = local_e0;

  local_dc = (BSTR)0x0;

  local_4 = (int *)0x0;

  local_ec = (void *)FUN_004933f0();

  local_e8 = (uint32_t /* width from decompiler */ *)0x0;

  local_4._0_1_ = 1;

  if (DAT_00d1793c == '\0') {

    if (*param_1 == '\0') {

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_ec);

    }

    local_b8 = &local_d0;

    local_d0 = 0;

    local_cc = 0;

    local_c8 = (uint32_t /* width from decompiler */ **)0x0;

    local_c4 = 0;

    local_c0 = 0;

    local_bc = 0;

    local_b0 = 0;

    local_b4 = 0;

    local_ac = 0;

    local_a8 = 0;

    local_4 = (int *)CONCAT31(local_4._1_3_,2);

    iVar6 = FUN_0041a810();

    local_c8 = &local_f4;

    if ((((iVar6 < 0) || (iVar6 = FUN_004231d0(), iVar6 < 0)) || (iVar6 = FUN_004231d0(), iVar6 < 0)

        ) || (local_c0 == 0)) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = (int *)CONCAT31(local_4._1_3_,1);

      FUN_0041a3e0();

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_ec);

    }

    iVar6 = FUN_0041c000();

    while (iVar6 == 0) {

      _Dest = operator_new__(0x66);

      wcscpy(_Dest,local_74);

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_0041b440();

      *puVar7 = _Dest;

      iVar6 = FUN_0041c000();

    }

    if (local_c0 != 0) {

      FUN_00422de0();

      FUN_0041bf70();

    }

    FUN_00423170();

    local_8c = &local_a4;

    local_a4 = 0;

    local_a0 = 0;

    local_9c = (uint32_t /* width from decompiler */ **)0x0;

    local_98 = 0;

    local_94 = 0;

    local_90 = 0;

    local_84 = 0;

    local_88 = 0;

    local_80 = 0;

    local_7c = 0;

    local_4 = (int *)CONCAT31(local_4._1_3_,3);

    iVar6 = FUN_0041a810();

    local_9c = &local_f4;

    if (((iVar6 < 0) || (iVar6 = FUN_004231d0(), iVar6 < 0)) ||

       ((iVar6 = FUN_004231d0(), iVar6 < 0 || (local_94 == 0)))) {

      FUN_00423170();

      FUN_007a4480();

      local_4._0_1_ = 2;

      FUN_0041a3e0();

      local_4 = (int *)CONCAT31(local_4._1_3_,1);

      FUN_0041a3e0();

      FUN_00415d60();

      local_4 = (int *)0xffffffff;

      FUN_0041a440();

      ExceptionList = pvStack_c;

      return 0;

    }

    iVar6 = FUN_0041c000();

    pvVar9 = local_ec;

    while (local_ec = pvVar9, iVar6 == 0) {

      puVar7 = operator_new(8);

      *puVar7 = local_78;

      puVar7[1] = local_f4;

      iVar6 = FUN_006759b0();

      FUN_0043fe60();

      *(int *)((int)pvVar9 + 4) = iVar6;

      **(int **)(iVar6 + 4) = iVar6;

      iVar6 = FUN_0041c000();

      pvVar9 = local_ec;

    }

    FUN_0041a990();

    FUN_00423170();

    local_4._0_1_ = 2;

    FUN_0041a3e0();

    local_4 = (int *)CONCAT31(local_4._1_3_,1);

    FUN_0041a3e0();

  }

  else {

    local_d4 = SysAllocString(L"//tWeaponGroup/row");

    if (local_d4 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_4._0_1_ = 4;

    FUN_00419ca0();

    local_4._0_1_ = 5;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 4;

    FUN_00419ed0();

    local_100 = (IUnknown *)0x0;

    local_4 = (int *)CONCAT31(local_4._1_3_,7);

    while( true ) {

      if (local_fc == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      UVar8 = (*local_fc->lpVtbl[2].Release)(local_fc);

      if ((int)UVar8 < 0) {

        _com_issue_errorex(UVar8,local_fc,(_GUID *)&DAT_00a86118);

      }

      if ((int)unaff_EBX <= (int)local_fc) break;

      _com_issue_error(-0x7fffbffd);

      unaff_EBX = (int *)0x0;

      (**(code **)(_DAT_00000000 + 0x1c))((IUnknown *)0x0);

      if (unaff_ESI != (int *)0x0) {

        pvVar9 = operator_new__(0x66);

        pOVar10 = SysAllocString(L"strName");

        if (pOVar10 == (BSTR)0x0) goto LAB_007c8e5d;

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))(unaff_ESI);

        }

        FUN_007b8de0();

        pOVar10 = SysAllocString(L"IDWeaponGroup");

        if (pOVar10 == (BSTR)0x0) goto LAB_007c8e5d;

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

        }

        FUN_007b8a60();

        puVar7 = (uint32_t /* width from decompiler */ *)FUN_0041b440();

        *puVar7 = pvVar9;

      }

    }

    if (pOStack_d8 != L"//tWeaponGroup_x/row") {

      SysFreeString(pOStack_d8);

      pOStack_d8 = SysAllocString(L"//tWeaponGroup_x/row");

      if (pOStack_d8 == (BSTR)0x0) {

LAB_007c8e5d:

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

    }

    FUN_00419ca0();

    puStack_8._0_1_ = 8;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,7);

    puVar7 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    pIVar13 = (IUnknown *)*puVar7;

    if ((pIVar13 != (IUnknown *)0x0) && (local_100 = pIVar13, pIVar13 != (IUnknown *)0x0)) {

      (*pIVar13->lpVtbl->AddRef)(pIVar13);

    }

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    local_fc = (IUnknown *)0x0;

    pIVar13 = (IUnknown *)local_f0;

    while( true ) {

      if (local_100 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      UVar8 = (*local_100->lpVtbl[2].Release)(local_100);

      if ((int)UVar8 < 0) {

        _com_issue_errorex(UVar8,local_100,(_GUID *)&DAT_00a86118);

      }

      if (unaff_EBP <= (int)local_fc) break;

      _com_issue_error(-0x7fffbffd);

      (**(code **)(_DAT_00000000 + 0x1c))((IUnknown *)0x0);

      pIVar16 = local_fc;

      if (unaff_ESI != (int *)0x0) {

        puVar7 = operator_new(8);

        local_e8 = (uint32_t /* width from decompiler */ *)&stack0xfffffed8;

        pOVar10 = SysAllocString(L"CBIDWeapon");

        if (pOVar10 == (BSTR)0x0) goto LAB_007c8e5d;

        local_e8 = (uint32_t /* width from decompiler */ *)&stack0xfffffed4;

        puVar4 = (uint32_t /* width from decompiler */ *)&stack0xfffffed4;

        if (unaff_ESI != (int *)0x0) {

          (**(code **)(*unaff_ESI + 4))();

          puVar4 = local_e8;

        }

        local_e8 = puVar4;

        uVar11 = FUN_007b8a60();

        local_e8 = (uint32_t /* width from decompiler */ *)&stack0xfffffed8;

        *puVar7 = uVar11;

        pOVar10 = SysAllocString(L"IDWeaponGroup");

        if (pOVar10 == (BSTR)0x0) goto LAB_007c8e5d;

        local_e8 = (uint32_t /* width from decompiler */ *)&stack0xfffffed4;

        if (unaff_ESI != (int *)0x0) {

          local_e8 = (uint32_t /* width from decompiler */ *)&stack0xfffffed4;

          (**(code **)(*unaff_ESI + 4))();

        }

        uVar11 = FUN_007b8a60();

        puVar7[1] = uVar11;

        iVar6 = FUN_006759b0();

        FUN_0043fe60();

        *(int *)((int)pIVar13 + 4) = iVar6;

        pIVar16 = (IUnknown *)0x0;

        **(int **)(iVar6 + 4) = iVar6;

        pIVar13 = local_fc;

      }

      local_fc = (IUnknown *)((int)pIVar16 + 1);

    }

    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);

    SysFreeString(local_dc);

  }

  piVar3 = local_4;

  *local_4 = local_e4;

  if (local_e4 == 0) {

    local_4[1] = 0;

  }

  else {

    pvVar12 = CoTaskMemAlloc(local_e4 * 0x6c);

    piVar3[1] = (int)pvVar12;

  }

  piVar3[2] = local_f0;

  if (local_f0 == 0) {

    piVar3[3] = 0;

    piVar3[4] = 0;

  }

  else {

    pvVar12 = CoTaskMemAlloc(local_f0 * 4);

    piVar3[3] = (int)pvVar12;

    pvVar12 = CoTaskMemAlloc(piVar3[2] * 4);

    piVar3[4] = (int)pvVar12;

  }

  piVar15 = (int *)*local_e8;

  puVar7 = (uint32_t /* width from decompiler */ *)*local_f4;

  iVar6 = 0;

  if (0 < *piVar3) {

    iVar14 = 0;

    do {

      *(int *)(piVar3[1] + iVar14) = piVar15[3];

      wcscpy((wchar_t *)(piVar3[1] + 4 + iVar14),(wchar_t *)piVar15[4]);

      operator_delete__((void *)piVar15[4]);

      if (*(char *)((int)piVar15 + 0x15) == '\0') {

        piVar2 = (int *)piVar15[2];

        if (*(char *)((int)piVar2 + 0x15) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x15);

          piVar15 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x15);

            piVar15 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar15[1] + 0x15);

          piVar5 = (int *)piVar15[1];

          piVar2 = piVar15;

          while ((piVar15 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar15[2]))) {

            cVar1 = *(char *)(piVar15[1] + 0x15);

            piVar5 = (int *)piVar15[1];

            piVar2 = piVar15;

          }

        }

      }

      iVar6 = iVar6 + 1;

      iVar14 = iVar14 + 0x6c;

    } while (iVar6 < *piVar3);

  }

  iVar6 = 0;

  if (0 < piVar3[2]) {

    do {

      *(uint32_t /* width from decompiler */ *)(piVar3[3] + iVar6 * 4) = *(uint32_t /* width from decompiler */ *)(puVar7[2] + 4);

      *(uint32_t /* width from decompiler */ *)(piVar3[4] + iVar6 * 4) = *(uint32_t /* width from decompiler */ *)puVar7[2];

      if ((void *)puVar7[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)puVar7[2]);

      }

      puVar7[2] = 0;

      puVar7 = (uint32_t /* width from decompiler */ *)*puVar7;

      iVar6 = iVar6 + 1;

    } while (iVar6 < piVar3[2]);

  }

  puVar7 = (uint32_t /* width from decompiler */ *)*local_f4;

  *local_f4 = local_f4;

  local_f4[1] = local_f4;

  if (puVar7 == local_f4) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_f4);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar7);

}
