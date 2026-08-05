// =============================================================================
// FUN_007cd150
// -----------------------------------------------------------------------------
// Stable ID: aa_007cd150
// Address:   0x007cd150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007cd150 @ 0x007cd150
// Stable ID: aa_007cd150
// Embedded strings (evidence for future rename):
//   - "//tCreatureExperienceLevel/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×10, while×2, return×2, do×1.
//  - Notable callees: block×8, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, FUN_004231d0×2, FUN_004048e0.
//  - Strings: "//tCreatureExperienceLevel/row".
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x007cd444) */

/* WARNING: Removing unreachable block (ram,0x007cd3d3) */

/* WARNING: Removing unreachable block (ram,0x007cd3ef) */

/* WARNING: Removing unreachable block (ram,0x007cd404) */

/* WARNING: Removing unreachable block (ram,0x007cd40a) */

/* WARNING: Removing unreachable block (ram,0x007cd42f) */

/* WARNING: Removing unreachable block (ram,0x007cd44a) */

/* WARNING: Removing unreachable block (ram,0x007cd4a5) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall FUN_007cd150(int param_1)



{

  int iVar1;

  BSTR bstrString;

  ULONG UVar2;

  IUnknown *pIStack_74;

  IUnknown *local_6c;

  int local_64;

  uint8_t *local_60;

  BSTR local_5c;

  BSTR local_58;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  int *local_3c;

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

  puStack_10 = &LAB_009ae795;

  local_14 = ExceptionList;

  if (DAT_00d1793c == '\0') {

    local_2c = &local_44;

    local_44 = 0;

    local_40 = 0;

    local_3c = (int *)0x0;

    local_38 = 0;

    local_34 = 0;

    local_30 = 0;

    local_24 = 0;

    local_28 = 0;

    local_20 = 0;

    local_1c = 0;

    local_c = 0;

    ExceptionList = &local_14;

    iVar1 = FUN_0041a810(local_2c,param_1 + 0x28,0,0);

    local_3c = &local_64;

    if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) || (iVar1 = FUN_004231d0(), iVar1 < 0)

        ) || (local_34 == 0)) {

      FUN_00423170();

      FUN_007a4480(1);

      local_c = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      iVar1 = FUN_0041c000();

      while (iVar1 == 0) {

        FUN_0040ed60();

        iVar1 = FUN_0041c000();

      }

      if (local_34 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_c = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    ExceptionList = &local_14;

    bstrString = SysAllocString(L"//tCreatureExperienceLevel/row");

    local_58 = bstrString;

    if (bstrString == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_60 = &stack0xffffff7c;

    local_c = 1;

    FUN_00419ca0();

    local_c._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_c._0_1_ = 1;

    FUN_00419ed0();

    local_c = CONCAT31(local_c._1_3_,4);

    if (local_6c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar2 = (*local_6c->lpVtbl[2].Release)(local_6c);

    if ((int)UVar2 < 0) {

      _com_issue_errorex(UVar2,local_6c,(_GUID *)&DAT_00a86118);

    }

    local_64 = 0;

    if (0 < (int)local_6c) {

      do {

        iVar1 = local_64;

        _com_issue_error(-0x7fffbffd);

        if (pIStack_74 != (IUnknown *)0x0) {

          (*pIStack_74->lpVtbl->Release)(pIStack_74);

        }

        pIStack_74 = (IUnknown *)0x0;

        (**(code **)(_DAT_00000000 + 0x1c))(0);

        local_64 = iVar1 + 1;

        bstrString = local_5c;

      } while (local_64 < (int)local_6c);

    }

    puStack_10._0_1_ = 3;

    if (pIStack_74 != (IUnknown *)0x0) {

      (*pIStack_74->lpVtbl->Release)(pIStack_74);

    }

    puStack_10 = (uint8_t *)CONCAT31(puStack_10._1_3_,1);

    SysFreeString(bstrString);

  }

  ExceptionList = pvStack_18;

  return 0;

}
