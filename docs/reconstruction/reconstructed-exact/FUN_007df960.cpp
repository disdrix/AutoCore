// =============================================================================
// FUN_007df960
// -----------------------------------------------------------------------------
// Stable ID: aa_007df960
// Address:   0x007df960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007df960 @ 0x007df960
// Stable ID: aa_007df960
// Embedded strings (evidence for future rename):
//   - "//vCreatureLevel/row"
//   - "IDCloneBase"
//   - "sinBaseLevel"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~148 non-empty decompiler lines.
//  - Control keywords: if×18, return×4, while×2, goto×2.
//  - Notable callees: SysAllocString×3, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2, FUN_0041b1e0×2, FUN_0041bf70×2, FUN_0041c000×2, FUN_00422de0×2.
//  - Strings: "//vCreatureLevel/row"; "IDCloneBase"; "sinBaseLevel".
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

/* WARNING: Removing unreachable block (ram,0x007dfce2) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_007df960(char *param_1)



{

  short sVar1;

  int iVar2;

  ULONG UVar3;

  BSTR pOVar4;

  BSTR pOVar5;

  int *unaff_EBX;

  int *unaff_ESI;

  int *piVar6;

  short local_68;

  IUnknown *local_60;

  uint8_t *local_5c;

  BSTR pOStack_58;

  BSTR local_54;

  int local_50;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint8_t **local_3c;

  uint32_t /* width from decompiler */ local_38;

  int local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ *local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  void *pvStack_18;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009aef3e;

  local_14 = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_2c = &local_44;

    local_44 = 0;

    local_40 = 0;

    local_3c = (uint8_t **)0x0;

    local_38 = 0;

    local_34 = 0;

    local_30 = 0;

    local_24 = 0;

    local_28 = 0;

    local_20 = 0;

    local_1c = 0;

    local_c = 0;

    ExceptionList = &local_14;

    iVar2 = FUN_0041a810(local_2c,param_1 + 0x28);

    local_3c = &local_5c;

    if (((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) || (iVar2 = FUN_004231d0(), iVar2 < 0))

    {

      if (local_34 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

    }

    else if (local_34 != 0) {

      iVar2 = FUN_0041c000();

      while (iVar2 == 0) {

        local_50 = (int)local_68;

        FUN_0041b1e0();

        iVar2 = FUN_0041c000();

      }

      if (local_34 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_c = 0xffffffff;

      FUN_0041a3e0();

      ExceptionList = pvStack_18;

      return 0;

    }

    FUN_00423170();

    FUN_007a4480();

    local_c = 0xffffffff;

    FUN_0041a3e0();

  }

  else {

    ExceptionList = &local_14;

    local_54 = SysAllocString(L"//vCreatureLevel/row");

    if (local_54 == (BSTR)0x0) {

LAB_007dfb41:

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_5c = &stack0xffffff84;

    local_c = 1;

    FUN_00419ca0();

    local_c._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_c._0_1_ = 1;

    FUN_00419ed0();

    local_c = CONCAT31(local_c._1_3_,4);

    piVar6 = (int *)0x0;

    while( true ) {

      if (local_60 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_5c = (uint8_t *)0x0;

      UVar3 = (*local_60->lpVtbl[2].Release)(local_60);

      if ((int)UVar3 < 0) {

        _com_issue_errorex(UVar3,local_60,(_GUID *)&DAT_00a86118);

      }

      if ((int)local_60 <= (int)piVar6) break;

      _com_issue_error(-0x7fffbffd);

      if (piVar6 != (int *)0x0) {

        (**(code **)(*piVar6 + 8))();

      }

      (**(code **)(_DAT_00000000 + 0x1c))((IUnknown *)0x0);

      if (unaff_EBX != (int *)0x0) {

        pOVar4 = SysAllocString(L"IDCloneBase");

        if (pOVar4 == (BSTR)0x0) goto LAB_007dfb41;

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 4))(unaff_EBX);

        }

        pOVar4 = (BSTR)FUN_007b8a60();

        pOVar5 = SysAllocString(L"sinBaseLevel");

        if (pOVar5 == (BSTR)0x0) goto LAB_007dfb41;

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 4))(unaff_EBX);

        }

        sVar1 = FUN_007b8a60();

        local_54 = (BSTR)(int)sVar1;

        pOStack_58 = pOVar4;

        FUN_0041b1e0();

        piVar6 = unaff_ESI;

      }

      piVar6 = (int *)((int)piVar6 + 1);

    }

    puStack_10._0_1_ = 3;

    if (piVar6 != (int *)0x0) {

      (**(code **)(*piVar6 + 8))();

    }

    puStack_10 = (uint8_t *)CONCAT31(puStack_10._1_3_,1);

    SysFreeString(pOStack_58);

  }

  ExceptionList = pvStack_18;

  return 0;

}
