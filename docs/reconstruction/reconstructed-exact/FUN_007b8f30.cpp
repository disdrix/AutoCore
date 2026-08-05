// =============================================================================
// FUN_007b8f30
// -----------------------------------------------------------------------------
// Stable ID: aa_007b8f30
// Address:   0x007b8f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b8f30 @ 0x007b8f30
// Stable ID: aa_007b8f30
// Embedded strings (evidence for future rename):
//   - "//tRemovedObjects/row"
//   - "IDCloneBaseOld"
//   - "IDCloneBaseNew"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×18, return×4, while×2, goto×1.
//  - Notable callees: _com_issue_error×4, SysAllocString×3, CONCAT31×2, FUN_0041a630×2, FUN_0041c000×2, FUN_00423170×2, FUN_004231d0×2, FUN_007b8a60×2.
//  - Strings: "//tRemovedObjects/row"; "IDCloneBaseOld"; "IDCloneBaseNew".
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

/* WARNING: Removing unreachable block (ram,0x007b928a) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall FUN_007b8f30(char *param_1)



{

  uint8_t *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  ULONG UVar4;

  BSTR pOVar5;

  uint32_t /* width from decompiler */ uVar6;

  IUnknown *unaff_EBX;

  IUnknown *unaff_EBP;

  IUnknown *unaff_EDI;

  IUnknown *local_50;

  uint8_t *local_4c;

  uint8_t *local_48;

  BSTR local_44;

  BSTR local_40;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t **local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adddd;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_20 = &local_38;

    local_38 = 0;

    local_34 = 0;

    local_30 = (uint8_t **)0x0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = (void *)0x0;

    local_4 = 0;

    ExceptionList = &local_c;

    iVar2 = FUN_0041a810(local_20);

    local_30 = &local_4c;

    if ((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) || (iVar2 = FUN_004231d0(), iVar2 < 0)

        ) || (local_28 == 0)) {

      FUN_00423170();

      FUN_007a4480();

    }

    else {

      iVar2 = FUN_0041c000();

      while (iVar2 == 0) {

        puVar3 = (uint32_t /* width from decompiler */ *)FUN_0041a630();

        *puVar3 = local_4c;

        iVar2 = FUN_0041c000();

      }

      if (local_28 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

    }

    local_4 = 0xffffffff;

    FUN_0041a3e0();

    ExceptionList = local_10;

    return 0;

  }

  ExceptionList = &local_c;

  local_40 = SysAllocString(L"//tRemovedObjects/row");

  if (local_40 != (BSTR)0x0) {

    local_48 = &stack0xffffff98;

    local_4 = 1;

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    if (local_50 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_48 = (uint8_t *)0x0;

    UVar4 = (*local_50->lpVtbl[2].Release)(local_50);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,local_50,(_GUID *)&DAT_00a86118);

    }

    if ((int)local_4c < 1) {

LAB_007b926a:

      puStack_8._0_1_ = 3;

      if (unaff_EBX != (IUnknown *)0x0) {

        (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

      }

      puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

      SysFreeString(local_44);

      ExceptionList = local_10;

      return 0;

    }

    iVar2 = 0;

    while( true ) {

      _com_issue_error(-0x7fffbffd);

      local_4c = (uint8_t *)0x0;

      UVar4 = (**(code **)(_DAT_00000000 + 0x20))((IUnknown *)0x0);

      if ((int)UVar4 < 0) {

        _com_issue_errorex(UVar4,(IUnknown *)0x0,(_GUID *)&DAT_00a86118);

      }

      if ((int)local_50 <= iVar2) goto LAB_007b926a;

      if (unaff_EBX == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      if (unaff_EBP != (IUnknown *)0x0) {

        (*unaff_EBP->lpVtbl->Release)(unaff_EBP);

      }

      unaff_EBP = (IUnknown *)0x0;

      (*unaff_EBX->lpVtbl[2].AddRef)(unaff_EBX);

      pOVar5 = SysAllocString(L"IDCloneBaseOld");

      if (pOVar5 == (BSTR)0x0) break;

      if (unaff_EDI != (IUnknown *)0x0) {

        (*unaff_EDI->lpVtbl->AddRef)(unaff_EDI);

      }

      unaff_EBX = (IUnknown *)FUN_007b8a60();

      local_4c = &stack0xffffff88;

      pOVar5 = SysAllocString(L"IDCloneBaseNew");

      if (pOVar5 == (BSTR)0x0) break;

      local_4c = &stack0xffffff84;

      puVar1 = &stack0xffffff84;

      if (unaff_EDI != (IUnknown *)0x0) {

        (*unaff_EDI->lpVtbl->AddRef)(unaff_EDI);

        puVar1 = local_4c;

      }

      local_4c = puVar1;

      uVar6 = FUN_007b8a60();

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_0041a630();

      *puVar3 = uVar6;

      iVar2 = iVar2 + 1;

    }

  }

                    /* WARNING: Subroutine does not return */

  FUN_004048e0();

}
