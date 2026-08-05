// =============================================================================
// FUN_007c6c50
// -----------------------------------------------------------------------------
// Stable ID: aa_007c6c50
// Address:   0x007c6c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007c6c50 @ 0x007c6c50
// Stable ID: aa_007c6c50
// Embedded strings (evidence for future rename):
//   - "//tPrefixWeight/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~202 non-empty decompiler lines.
//  - Control keywords: if×18, return×6, do×3, while×3, goto×2.
//  - Notable callees: block×14, FUN_0041a3e0×4, CONCAT31×3, FUN_00415e90×3, FUN_004231d0×3, _com_issue_error×3, CoTaskMemAlloc×2, FUN_00415d60×2.
//  - Strings: "//tPrefixWeight/row".
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

/* WARNING: Removing unreachable block (ram,0x007c71b9) */

/* WARNING: Removing unreachable block (ram,0x007c7119) */

/* WARNING: Removing unreachable block (ram,0x007c709e) */

/* WARNING: Removing unreachable block (ram,0x007c70ba) */

/* WARNING: Removing unreachable block (ram,0x007c70d2) */

/* WARNING: Removing unreachable block (ram,0x007c70d8) */

/* WARNING: Removing unreachable block (ram,0x007c7101) */

/* WARNING: Removing unreachable block (ram,0x007c711f) */

/* WARNING: Removing unreachable block (ram,0x007c714a) */

/* WARNING: Removing unreachable block (ram,0x007c7162) */

/* WARNING: Removing unreachable block (ram,0x007c7168) */

/* WARNING: Removing unreachable block (ram,0x007c7189) */

/* WARNING: Removing unreachable block (ram,0x007c718c) */

/* WARNING: Removing unreachable block (ram,0x007c700e) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_007c6c50(char *param_1,short *param_2,int *param_3,int *param_4)



{

  int *piVar1;

  int iVar2;

  LPVOID pvVar3;

  BSTR bstrString;

  ULONG UVar4;

  void *pvVar5;

  IUnknown *local_60;

  IUnknown *local_58;

  BSTR local_50;

  BSTR local_4c;

  uint16_t local_48;

  uint16_t local_46;

  void *local_44;

  int *local_40;

  int local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  BSTR *local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  pvVar5 = ExceptionList;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae3f8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_4 = 0;

  *param_3 = 0;

  *param_2 = 0;

  if (*param_1 == '\0') {

    ExceptionList = pvVar5;

    return 0x80004004;

  }

  piVar1 = (int *)FUN_004397f0();

  local_3c = 0;

  local_4 = 0;

  local_40 = piVar1;

  if (DAT_00d1793c == '\0') {

    local_20 = &local_38;

    local_38 = 0;

    local_34 = 0;

    local_30 = (BSTR *)0x0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 1;

    iVar2 = FUN_0041a810(local_20,param_1 + 0x28,0,0);

    local_30 = &local_50;

    if ((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) || (iVar2 = FUN_004231d0(), iVar2 < 0)

        ) || ((iVar2 = FUN_004231d0(), iVar2 < 0 || (local_28 == 0)))) {

      FUN_00423170();

      FUN_007a4480(1);

      local_4 = local_4 & 0xffffff00;

      pvVar5 = (void *)0x7c6dbe;

      FUN_0041a3e0();

      FUN_00415e90();

      local_44 = pvVar5;

      goto LAB_007c71d8;

    }

    iVar2 = FUN_0041c000();

    if (iVar2 != 0) {

LAB_007c6e4b:

      local_4 = local_4 & 0xffffff00;

      FUN_0041a3e0();

      FUN_00415d60();

      ExceptionList = local_c;

      return 0;

    }

    do {

      local_4c = local_50;

      local_48 = param_4._0_2_;

      local_46 = local_60._0_2_;

      iVar2 = FUN_0046c2a0();

      FUN_0046c230();

      piVar1[1] = iVar2;

      **(int **)(iVar2 + 4) = iVar2;

      iVar2 = FUN_0041c000();

      piVar1 = local_40;

    } while (iVar2 == 0);

    if (local_3c < 1) goto LAB_007c6e4b;

    *param_3 = local_3c;

    pvVar3 = CoTaskMemAlloc(local_3c * 8);

    *param_4 = (int)pvVar3;

    if (pvVar3 == (LPVOID)0x0) {

      local_4 = local_4 & 0xffffff00;

      FUN_0041a3e0();

      FUN_00415d60();

      ExceptionList = local_c;

      return 0x8007000e;

    }

    piVar1 = (int *)*local_40;

    if (piVar1 != local_40) {

      iVar2 = 0;

      do {

        if (*param_2 < (short)piVar1[3]) {

          *param_2 = (short)piVar1[3];

        }

        *(int *)(iVar2 + *param_4) = piVar1[2];

        *(short *)(*param_4 + 4 + iVar2) = (short)piVar1[3];

        *(uint16_t *)(*param_4 + 6 + iVar2) = *(uint16_t *)((int)piVar1 + 0xe);

        piVar1 = (int *)*piVar1;

        iVar2 = iVar2 + 8;

      } while (piVar1 != local_40);

    }

    if (local_28 != 0) {

      FUN_00422de0();

      FUN_0041bf70();

    }

    FUN_00423170();

    local_4 = local_4 & 0xffffff00;

    FUN_0041a3e0();

  }

  else {

    bstrString = SysAllocString(L"//tPrefixWeight/row");

    local_4c = bstrString;

    if (bstrString == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_4._0_1_ = 2;

    FUN_00419ca0();

    local_4._0_1_ = 3;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 2;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,5);

    if (local_58 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar4 = (*local_58->lpVtbl[2].Release)(local_58);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,local_58,(_GUID *)&DAT_00a86118);

    }

    *(IUnknown **)param_2 = local_58;

    pvVar3 = CoTaskMemAlloc((int)local_58 * 8);

    *param_4 = (int)pvVar3;

    if (pvVar3 == (LPVOID)0x0) {

      puStack_8._0_1_ = 4;

      if (local_60 != (IUnknown *)0x0) {

        (*local_60->lpVtbl->Release)(local_60);

      }

      puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

      SysFreeString(bstrString);

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_44);

    }

    iVar2 = 0;

    if (0 < (int)local_58) {

      do {

        _com_issue_error(-0x7fffbffd);

        if (local_60 != (IUnknown *)0x0) {

          (*local_60->lpVtbl->Release)(local_60);

        }

        local_60 = (IUnknown *)0x0;

        (**(code **)(_DAT_00000000 + 0x1c))(0);

        iVar2 = iVar2 + 1;

      } while (iVar2 < (int)local_58);

    }

    puStack_8._0_1_ = 4;

    if (local_60 != (IUnknown *)0x0) {

      (*local_60->lpVtbl->Release)(local_60);

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    SysFreeString(local_50);

  }

  FUN_00415e90();

LAB_007c71d8:

                    /* WARNING: Subroutine does not return */

  operator_delete(local_44);

}
