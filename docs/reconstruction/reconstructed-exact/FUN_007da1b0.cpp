// =============================================================================
// FUN_007da1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007da1b0
// Address:   0x007da1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007da1b0 @ 0x007da1b0
// Stable ID: aa_007da1b0
// Embedded strings (evidence for future rename):
//   - "//vGeneratableCreatures/row"
//   - "IDCloneBase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~185 non-empty decompiler lines.
//  - Control keywords: if×18, return×4, while×3, do×2, goto×1.
//  - Notable callees: CONCAT31×2, CoTaskMemAlloc×2, FUN_00415e90×2, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, SysAllocString×2, _com_issue_error×2.
//  - Strings: "//vGeneratableCreatures/row"; "IDCloneBase".
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

uint32_t /* width from decompiler */ __thiscall FUN_007da1b0(char *param_1,int *param_2)



{

  IUnknown *This;

  uint8_t *puVar1;

  int *piVar2;

  int iVar3;

  LPVOID pvVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  ULONG UVar7;

  BSTR pOVar8;

  uint32_t /* width from decompiler */ uVar9;

  IUnknown *unaff_EBX;

  int *unaff_ESI;

  IUnknown *This_00;

  int *unaff_retaddr;

  IUnknown *local_5c;

  uint8_t *local_54;

  BSTR local_50;

  BSTR local_4c;

  uint8_t *local_48;

  int *local_40;

  int local_3c;

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

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aebdc;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  ExceptionList = &local_c;

  piVar2 = (int *)FUN_0040fb90();

  local_3c = 0;

  local_4 = 0;

  local_40 = piVar2;

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

    local_10 = 0;

    local_4 = 1;

    iVar3 = FUN_0041a810(local_20,param_1 + 0x28,0);

    local_30 = &local_54;

    if (((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) || (local_28 == 0)) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = local_4 & 0xffffff00;

      piVar2 = (int *)0x7da2c5;

      FUN_0041a3e0();

      FUN_00415e90();

    }

    else {

      iVar3 = FUN_0041c000();

      while (iVar3 == 0) {

        iVar3 = FUN_00418700();

        FUN_00404840();

        piVar2[1] = iVar3;

        **(int **)(iVar3 + 4) = iVar3;

        iVar3 = FUN_0041c000();

        piVar2 = local_40;

      }

      if (local_28 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      *param_2 = local_3c;

      pvVar4 = CoTaskMemAlloc(local_3c * 4);

      param_2[1] = (int)pvVar4;

      piVar5 = (int *)*piVar2;

      if (piVar5 != piVar2) {

        iVar3 = 0;

        do {

          *(int *)(iVar3 + param_2[1]) = piVar5[2];

          piVar5 = (int *)*piVar5;

          iVar3 = iVar3 + 4;

        } while (piVar5 != piVar2);

      }

      local_4 = local_4 & 0xffffff00;

      piVar2 = (int *)0x7da395;

      FUN_0041a3e0();

      FUN_00415e90();

    }

  }

  else {

    local_4c = SysAllocString(L"//vGeneratableCreatures/row");

    if (local_4c == (BSTR)0x0) {

LAB_007da3bb:

                    /* WARNING: Subroutine does not return */

      FUN_004048e0(0x8007000e);

    }

    local_5c = (IUnknown *)0x0;

    local_48 = &stack0xffffff90;

    local_4._0_1_ = 4;

    FUN_00419ca0();

    local_4._0_1_ = 5;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,4);

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    This = (IUnknown *)*puVar6;

    This_00 = (IUnknown *)0x0;

    if (This != (IUnknown *)0x0) {

      (*This->lpVtbl->AddRef)(This);

      This_00 = This;

    }

    if (local_50 != (BSTR)0x0) {

      (**(code **)(*(int *)local_50 + 8))();

    }

    if (This_00 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_50 = (BSTR)0x0;

    UVar7 = (*This_00->lpVtbl[2].Release)(This_00);

    if ((int)UVar7 < 0) {

      _com_issue_errorex(UVar7,This_00,(_GUID *)&DAT_00a86118);

    }

    *unaff_retaddr = (int)local_54;

    pvVar4 = CoTaskMemAlloc((int)local_54 * 4);

    unaff_retaddr[1] = (int)pvVar4;

    iVar3 = 0;

    if (0 < *unaff_retaddr) {

      do {

        if (unaff_EBX != (IUnknown *)0x0) {

          (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

        }

        (*This_00->lpVtbl[2].AddRef)(This_00);

        if (unaff_ESI != (int *)0x0) {

          local_54 = &stack0xffffff84;

          pOVar8 = SysAllocString(L"IDCloneBase");

          if (pOVar8 == (BSTR)0x0) goto LAB_007da3bb;

          local_54 = &stack0xffffff88;

          puVar1 = &stack0xffffff88;

          if (unaff_ESI != (int *)0x0) {

            (**(code **)(*unaff_ESI + 4))(unaff_ESI);

            puVar1 = local_54;

          }

          local_54 = puVar1;

          uVar9 = FUN_007b8a60();

          *(uint32_t /* width from decompiler */ *)(unaff_retaddr[1] + iVar3 * 4) = uVar9;

          This_00 = local_5c;

        }

        unaff_EBX = (IUnknown *)0x0;

        iVar3 = iVar3 + 1;

      } while (iVar3 < *unaff_retaddr);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (IUnknown *)0x0) {

      (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    (*This_00->lpVtbl->Release)(This_00);

    SysFreeString(local_50);

    piVar5 = (int *)*piVar2;

    *piVar2 = (int)piVar2;

    piVar2[1] = (int)piVar2;

    if (piVar5 != piVar2) {

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar5);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar2);

}
