// =============================================================================
// FUN_007e0230
// -----------------------------------------------------------------------------
// Stable ID: aa_007e0230
// Address:   0x007e0230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007e0230 @ 0x007e0230
// Stable ID: aa_007e0230
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "//tDamage/row[@IDDamage=\'"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~192 non-empty decompiler lines.
//  - Control keywords: if×22, return×6.
//  - Notable callees: FUN_004231d0×6, FUN_00423670×6, FUN_007b8a60×6, FUN_004048e0×3, FUN_0041a3e0×3, FUN_00423170×3, _com_issue_error×3, CONCAT31×2.
//  - Strings: "DBReader: %u against %s"; "//tDamage/row[@IDDamage=\'".
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_007e0230(char *param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint16_t uVar1;

  int iVar2;

  BSTR pOVar3;

  wchar_t *lpString;

  ULONG UVar4;

  uint16_t unaff_BX;

  uint16_t unaff_BP;

  uint16_t unaff_SI;

  bool bVar5;

  uint16_t uStack_84;

  uint16_t uStack_80;

  BSTR pOStack_7c;

  int *piStack_78;

  IUnknown *pIStack_74;

  IUnknown *local_68;

  wchar_t local_60 [14];

  uint8_t auStack_44 [8];

  uint8_t *puStack_3c;

  uint32_t /* width from decompiler */ local_38;

  int local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aefa6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = 0;

  bVar5 = DAT_00d1793c == '\0';

  param_3[1] = 0;

  param_3[2] = 0;

  if (bVar5) {

    if (*param_1 == '\0') {

      ExceptionList = local_18;

      return 0x80004004;

    }

    local_20 = &local_38;

    local_38 = 0;

    local_34 = 0;

    local_30 = 0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_18 = (void *)0x0;

    local_1c = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    FUN_004230d0();

    iVar2 = FUN_00422fb0(1);

    if (-1 < iVar2) {

      iVar2 = FUN_0041a810(auStack_44,param_1 + 0x28,0,0,&DAT_00a140c8);

    }

    puStack_3c = &stack0xffffff70;

    if (((((iVar2 < 0) || (iVar2 = FUN_004231d0(auStack_44), iVar2 < 0)) ||

         (iVar2 = FUN_004231d0(auStack_44), iVar2 < 0)) ||

        ((iVar2 = FUN_004231d0(auStack_44), iVar2 < 0 ||

         (iVar2 = FUN_004231d0(auStack_44), iVar2 < 0)))) ||

       ((iVar2 = FUN_004231d0(auStack_44), iVar2 < 0 ||

        ((iVar2 = FUN_004231d0(auStack_44), iVar2 < 0 || (local_34 == 0)))))) {

      FUN_00423170();

      local_10 = 0xffffffff;

      FUN_0041a3e0();

      ExceptionList = local_18;

      return 1;

    }

    iVar2 = FUN_0041a9b0();

    if (iVar2 == 0) {

      *(uint16_t *)(param_3 + 1) = unaff_BX;

      *(uint16_t *)param_3 = unaff_SI;

      *(uint16_t *)((int)param_3 + 2) = unaff_BP;

      *(uint16_t *)((int)param_3 + 10) = pOStack_7c._0_2_;

      *(uint16_t *)((int)param_3 + 6) = uStack_84;

      *(uint16_t *)(param_3 + 2) = uStack_80;

      FUN_0041a990();

      FUN_00423170();

      local_10 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      FUN_0041a990();

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s");

      local_10 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    pOVar3 = SysAllocString(L"//tDamage/row[@IDDamage=\'");

    if (pOVar3 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_4 = 1;

    lpString = _itow(param_2,local_60,10);

    lstrlenW(lpString);

    iVar2 = FUN_00422ee0();

    if (iVar2 < 0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    lstrlenW(L"\']");

    iVar2 = FUN_00422ee0();

    if (iVar2 < 0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    if (local_68 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar4 = (*local_68->lpVtbl[2].Release)(local_68);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,local_68,(_GUID *)&DAT_00a86118);

    }

    if (0 < (int)local_68) {

      _com_issue_error(-0x7fffbffd);

      if (pOVar3 != (BSTR)0x0) {

        (**(code **)(*(int *)pOVar3 + 8))();

      }

      (**(code **)(_DAT_00000000 + 0x1c))((IUnknown *)0x0);

      if (piStack_78 != (int *)0x0) {

        FUN_00423670();

        if (piStack_78 != (int *)0x0) {

          (**(code **)(*piStack_78 + 4))(piStack_78);

        }

        uVar1 = FUN_007b8a60();

        *(uint16_t *)param_3 = uVar1;

        FUN_00423670();

        if (piStack_78 != (int *)0x0) {

          (**(code **)(*piStack_78 + 4))(piStack_78);

        }

        uVar1 = FUN_007b8a60();

        *(uint16_t *)((int)param_3 + 2) = uVar1;

        FUN_00423670();

        if (piStack_78 != (int *)0x0) {

          (**(code **)(*piStack_78 + 4))(piStack_78);

        }

        uVar1 = FUN_007b8a60();

        *(uint16_t *)(param_3 + 1) = uVar1;

        FUN_00423670();

        if (piStack_78 != (int *)0x0) {

          (**(code **)(*piStack_78 + 4))(piStack_78);

        }

        uVar1 = FUN_007b8a60();

        *(uint16_t *)((int)param_3 + 6) = uVar1;

        FUN_00423670();

        if (piStack_78 != (int *)0x0) {

          (**(code **)(*piStack_78 + 4))(piStack_78);

        }

        uVar1 = FUN_007b8a60();

        *(uint16_t *)(param_3 + 2) = uVar1;

        FUN_00423670();

        if (piStack_78 != (int *)0x0) {

          (**(code **)(*piStack_78 + 4))(piStack_78);

        }

        uVar1 = FUN_007b8a60();

        *(uint16_t *)((int)param_3 + 10) = uVar1;

      }

    }

    local_10._0_1_ = 3;

    if (piStack_78 != (int *)0x0) {

      (**(code **)(*piStack_78 + 8))();

    }

    local_10 = CONCAT31(local_10._1_3_,1);

    if (pIStack_74 != (IUnknown *)0x0) {

      (*pIStack_74->lpVtbl->Release)(pIStack_74);

    }

    SysFreeString(pOStack_7c);

  }

  ExceptionList = local_18;

  return 0;

}
