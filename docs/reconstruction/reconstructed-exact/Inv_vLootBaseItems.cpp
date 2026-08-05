// =============================================================================
// Inv_vLootBaseItems
// -----------------------------------------------------------------------------
// Stable ID: aa_007da570
// Address:   0x007da570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_vLootBaseItems @ 0x007da570
// Stable ID: aa_007da570
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "//vLootBaseItems/row[@intType=\'"
//   - "IDCloneBase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~206 non-empty decompiler lines.
//  - Control keywords: if×21, return×6, while×3, do×2, goto×1.
//  - Notable callees: FUN_004048e0×3, FUN_00415e90×3, CONCAT31×2, CoTaskMemAlloc×2, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00422ee0×2, FUN_00423170×2.
//  - Strings: "DBReader: %u against %s"; "//vLootBaseItems/row[@intType=\'"; "IDCloneBase".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//vLootBaseItems/row[@intType='"
 * Domain alias of FUN_007da570 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Inv_vLootBaseItems(char *param_1,int *param_2)



{

  IUnknown *This;

  int *piVar1;

  int iVar2;

  LPVOID pvVar3;

  int *piVar4;

  BSTR pOVar5;

  wchar_t *lpString;

  uint32_t /* width from decompiler */ *puVar6;

  ULONG UVar7;

  uint32_t /* width from decompiler */ uVar8;

  int *unaff_EBX;

  IUnknown *This_00;

  IUnknown *local_80;

  IUnknown *local_7c;

  int iStack_78;

  int *local_74;

  uint8_t *local_70;

  int *local_6c;

  int *local_68;

  uint32_t /* width from decompiler */ local_64;

  wchar_t local_60 [18];

  uint8_t auStack_3c [4];

  uint32_t /* width from decompiler */ local_38;

  IUnknown **local_34;

  uint32_t /* width from decompiler */ local_30;

  int local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aec1b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  piVar1 = (int *)FUN_0040fb90();

  local_64 = 0;

  local_4 = 0;

  local_68 = piVar1;

  if (DAT_00d1793c == '\0') {

    if (*param_1 == '\0') {

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_68);

    }

    local_20 = &local_38;

    local_38 = 0;

    local_34 = (IUnknown **)0x0;

    local_30 = 0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 1;

    FUN_004230d0();

    iVar2 = FUN_00422fb0(1);

    if (-1 < iVar2) {

      iVar2 = FUN_0041a810(auStack_3c,param_1 + 0x28,0,0,&DAT_00a140c8);

    }

    local_34 = &local_7c;

    if (((iVar2 < 0) || (iVar2 = FUN_004231d0(auStack_3c), iVar2 < 0)) || (local_2c == 0)) {

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s");

      puStack_8 = (uint8_t *)((uint)puStack_8 & 0xffffff00);

      FUN_0041a3e0();

      FUN_00415e90();

      piVar1 = local_6c;

    }

    else {

      iVar2 = FUN_0041c000();

      while (iVar2 == 0) {

        iVar2 = FUN_00418700(piVar1);

        FUN_00404840();

        piVar1[1] = iVar2;

        **(int **)(iVar2 + 4) = iVar2;

        iVar2 = FUN_0041c000();

        piVar1 = local_6c;

      }

      if (local_2c != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      *param_2 = (int)local_68;

      pvVar3 = CoTaskMemAlloc((int)local_68 * 4);

      param_2[1] = (int)pvVar3;

      piVar4 = (int *)*piVar1;

      if (piVar4 != piVar1) {

        iVar2 = 0;

        do {

          *(int *)(iVar2 + param_2[1]) = piVar4[2];

          piVar4 = (int *)*piVar4;

          iVar2 = iVar2 + 4;

        } while (piVar4 != piVar1);

      }

      puStack_8 = (uint8_t *)((uint)puStack_8 & 0xffffff00);

      FUN_0041a3e0();

      FUN_00415e90();

      piVar1 = local_6c;

    }

  }

  else {

    pOVar5 = SysAllocString(L"//vLootBaseItems/row[@intType=\'");

    if (pOVar5 == (BSTR)0x0) {

LAB_007da7c9:

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_7c = (IUnknown *)0x0;

    local_4._0_1_ = 4;

    lpString = _itow((int)param_2,local_60,10);

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

    local_70 = &stack0xffffff68;

    FUN_00419ca0();

    local_4._0_1_ = 5;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,4);

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    This = (IUnknown *)*puVar6;

    This_00 = local_7c;

    if (This != (IUnknown *)0x0) {

      local_7c = This;

      (*This->lpVtbl->AddRef)(This);

      This_00 = This;

    }

    if (local_74 != (int *)0x0) {

      (**(code **)(*local_74 + 8))();

    }

    if (This_00 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_74 = (int *)0x0;

    UVar7 = (*This_00->lpVtbl[2].Release)(This_00);

    if ((int)UVar7 < 0) {

      _com_issue_errorex(UVar7,This_00,(_GUID *)&DAT_00a86118);

    }

    *param_2 = iStack_78;

    pvVar3 = CoTaskMemAlloc(iStack_78 * 4);

    param_2[1] = (int)pvVar3;

    iVar2 = 0;

    if (0 < *param_2) {

      do {

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 8))();

        }

        local_80 = (IUnknown *)0x0;

        (*This_00->lpVtbl[2].AddRef)(This_00);

        if (unaff_EBX != (int *)0x0) {

          local_74 = (int *)&stack0xffffff64;

          pOVar5 = SysAllocString(L"IDCloneBase");

          if (pOVar5 == (BSTR)0x0) goto LAB_007da7c9;

          local_74 = (int *)&stack0xffffff60;

          piVar4 = (int *)&stack0xffffff60;

          if (unaff_EBX != (int *)0x0) {

            (**(code **)(*unaff_EBX + 4))(unaff_EBX);

            piVar4 = local_74;

          }

          local_74 = piVar4;

          uVar8 = FUN_007b8a60();

          *(uint32_t /* width from decompiler */ *)(param_2[1] + iVar2 * 4) = uVar8;

          This_00 = local_80;

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < *param_2);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    (*This_00->lpVtbl->Release)(This_00);

    SysFreeString((BSTR)0x0);

    piVar4 = (int *)*piVar1;

    *piVar1 = (int)piVar1;

    piVar1[1] = (int)piVar1;

    if (piVar4 != piVar1) {

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar4);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar1);

}
