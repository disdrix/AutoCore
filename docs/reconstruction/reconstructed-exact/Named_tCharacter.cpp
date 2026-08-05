// =============================================================================
// Named_tCharacter
// -----------------------------------------------------------------------------
// Stable ID: aa_007dfd10
// Address:   0x007dfd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_tCharacter @ 0x007dfd10
// Stable ID: aa_007dfd10
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "//tCharacter/row[@IDCloneBase=\'"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~183 non-empty decompiler lines.
//  - Control keywords: if×21, return×6.
//  - Notable callees: FUN_004231d0×5, FUN_00423670×5, FUN_007b8a60×4, FUN_004048e0×3, FUN_00423170×3, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2.
//  - Strings: "DBReader: %u against %s"; "//tCharacter/row[@IDCloneBase=\'".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//tCharacter/row[@IDCloneBase='"
 * Domain alias of FUN_007dfd10 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall Named_tCharacter(char *param_1,int param_2,int *param_3)



{

  uint8_t uVar1;

  uint16_t uVar2;

  int iVar3;

  BSTR pOVar4;

  wchar_t *lpString;

  ULONG UVar5;

  uint uVar6;

  uint16_t unaff_BX;

  uint16_t unaff_BP;

  uint32_t /* width from decompiler */ unaff_ESI;

  BSTR pOStack_80;

  int *piStack_7c;

  IUnknown *pIStack_78;

  IUnknown *local_6c;

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

  puStack_8 = &LAB_009aef72;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    ExceptionList = local_18;

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

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

    ExceptionList = &local_c;

    FUN_004230d0();

    iVar3 = FUN_00422fb0(1);

    if (-1 < iVar3) {

      iVar3 = FUN_0041a810(auStack_44,param_1 + 0x28,0,0,&DAT_00a140c8);

    }

    puStack_3c = &stack0xffffff76;

    if ((((iVar3 < 0) || (iVar3 = FUN_004231d0(auStack_44), iVar3 < 0)) ||

        (iVar3 = FUN_004231d0(auStack_44), iVar3 < 0)) ||

       (((iVar3 = FUN_004231d0(auStack_44), iVar3 < 0 ||

         (iVar3 = FUN_004231d0(auStack_44), iVar3 < 0)) ||

        ((iVar3 = FUN_004231d0(auStack_44), iVar3 < 0 || (local_34 == 0)))))) {

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s");

    }

    else {

      iVar3 = FUN_0041a9b0();

      if (iVar3 != 0) {

        FUN_0041a990();

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s");

        local_10 = 0xffffffff;

        FUN_0041a3e0();

        ExceptionList = local_18;

        return 0;

      }

      *(uint16_t *)((int)param_3 + 6) = unaff_BP;

      *(char *)((int)param_3 + 9) = (char)((uint)unaff_ESI >> 0x10);

      uVar6 = (int)(short)pOStack_80 >> 0x1f;

      iVar3 = ((int)(short)pOStack_80 ^ uVar6) - uVar6;

      *(char *)((int)param_3 + 10) = (char)((uint)unaff_ESI >> 0x18);

      *param_3 = iVar3;

      *(char *)(param_3 + 2) = (char)iVar3;

      *(uint16_t *)(param_3 + 1) = unaff_BX;

      FUN_0041a990();

      FUN_00423170();

    }

    local_10 = 0xffffffff;

    FUN_0041a3e0();

  }

  else {

    ExceptionList = &local_c;

    pOVar4 = SysAllocString(L"//tCharacter/row[@IDCloneBase=\'");

    if (pOVar4 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_4 = 1;

    lpString = _itow(param_2,local_60,10);

    lstrlenW(lpString);

    iVar3 = FUN_00422ee0();

    if (iVar3 < 0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    lstrlenW(L"\']");

    iVar3 = FUN_00422ee0();

    if (iVar3 < 0) {

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

    if (local_6c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar5 = (*local_6c->lpVtbl[2].Release)(local_6c);

    if ((int)UVar5 < 0) {

      _com_issue_errorex(UVar5,local_6c,(_GUID *)&DAT_00a86118);

    }

    if (0 < param_2) {

      _com_issue_error(-0x7fffbffd);

      if (pOVar4 != (BSTR)0x0) {

        (**(code **)(*(int *)pOVar4 + 8))();

      }

      (**(code **)(_DAT_00000000 + 0x1c))((IUnknown *)0x0);

      if (piStack_7c != (int *)0x0) {

        FUN_00423670();

        if (piStack_7c != (int *)0x0) {

          (**(code **)(*piStack_7c + 4))(piStack_7c);

        }

        uVar1 = FUN_007b8a60();

        *(uint8_t *)((int)param_3 + 10) = uVar1;

        FUN_00423670();

        if (piStack_7c != (int *)0x0) {

          (**(code **)(*piStack_7c + 4))(piStack_7c);

        }

        uVar1 = FUN_007b8a60();

        *(uint8_t *)((int)param_3 + 9) = uVar1;

        FUN_00423670();

        if (piStack_7c != (int *)0x0) {

          (**(code **)(*piStack_7c + 4))(piStack_7c);

        }

        uVar2 = FUN_007b8a60();

        *(uint16_t *)((int)param_3 + 6) = uVar2;

        FUN_00423670();

        if (piStack_7c != (int *)0x0) {

          (**(code **)(*piStack_7c + 4))(piStack_7c);

        }

        uVar2 = FUN_007b8a60();

        *(uint16_t *)(param_3 + 1) = uVar2;

        FUN_00423670();

        if (piStack_7c != (int *)0x0) {

          (**(code **)(*piStack_7c + 4))(piStack_7c);

        }

        iVar3 = FUN_007b8910();

        *param_3 = iVar3;

        *(bool *)(param_3 + 2) = iVar3 != 0;

      }

    }

    local_10._0_1_ = 3;

    if (piStack_7c != (int *)0x0) {

      (**(code **)(*piStack_7c + 8))();

    }

    local_10 = CONCAT31(local_10._1_3_,1);

    if (pIStack_78 != (IUnknown *)0x0) {

      (*pIStack_78->lpVtbl->Release)(pIStack_78);

    }

    SysFreeString(pOStack_80);

  }

  ExceptionList = local_18;

  return 0;

}
