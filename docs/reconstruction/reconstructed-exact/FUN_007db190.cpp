// =============================================================================
// FUN_007db190
// -----------------------------------------------------------------------------
// Stable ID: aa_007db190
// Address:   0x007db190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007db190 @ 0x007db190
// Stable ID: aa_007db190
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "dcFetch::Open"
//   - "//tRegionMaps/row[@IDRegion=\'"
//   - "strFilename"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~212 non-empty decompiler lines.
//  - Control keywords: if×22, return×6, while×3, do×2, goto×2, for×1.
//  - Notable callees: FUN_004048e0×3, FUN_00415e90×2, FUN_0041a3e0×2, FUN_0041ac00×2, FUN_0041c000×2, FUN_00422ee0×2, FUN_00423170×2, SysAllocString×2.
//  - Strings: "DBReader: %u against %s"; "dcFetch::Open"; "//tRegionMaps/row[@IDRegion=\'"; "strFilename".
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

void FUN_007db190(char *param_1,int param_2)



{

  uint8_t *puVar1;

  IUnknownVtbl *pIVar2;

  int iVar3;

  _func_5022 *p_Var4;

  _func_5021 *p_Var5;

  wchar_t *lpString;

  int *piVar6;

  BSTR pOVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  code *pcVar10;

  uint32_t /* width from decompiler */ *puVar11;

  IUnknownVtbl *pIVar12;

  int *local_100;

  BSTR local_fc;

  IUnknownVtbl *local_f8;

  IUnknownVtbl *local_f0;

  uint32_t /* width from decompiler */ local_ec;

  IUnknownVtbl *local_e8;

  wchar_t *local_e4;

  uint8_t *local_e0;

  int local_dc;

  uint32_t /* width from decompiler */ local_d8;

  uint32_t /* width from decompiler */ local_d4;

  uint32_t /* width from decompiler */ local_d0;

  wchar_t **local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  wchar_t local_b8 [16];

  wchar_t awStack_98 [70];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aecc4;

  pvStack_c = ExceptionList;

  iVar9 = 0;

  ExceptionList = &pvStack_c;

  pIVar2 = (IUnknownVtbl *)FUN_0041c4e0();

  local_ec = 0;

  local_4 = 0;

  local_f0 = pIVar2;

  if (DAT_00d1793c == '\0') {

    if (*param_1 == '\0') {

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_f0);

    }

    local_cc = &local_e4;

    local_e4 = (wchar_t *)0x0;

    local_e0 = (uint8_t *)0x0;

    local_dc = 0;

    local_d8 = 0;

    local_d4 = 0;

    local_d0 = 0;

    local_c4 = 0;

    local_c8 = 0;

    local_c0 = 0;

    local_bc = 0;

    local_4 = 1;

    FUN_004230d0(local_cc);

    iVar3 = FUN_00422fb0(1,1,4);

    if (-1 < iVar3) {

      iVar3 = FUN_0041a810(&local_ec,local_4 + 0x28,0,0,&DAT_00a140c8,0,0);

    }

    local_e4 = (wchar_t *)&local_c0;

    if ((-1 < iVar3) && (iVar3 = FUN_004231d0(&local_ec,1,0x22), -1 < iVar3)) {

      if (local_dc != 0) {

        iVar3 = FUN_0041c000(0,1);

        while (iVar3 == 0) {

          wcscpy(awStack_98,(wchar_t *)&local_c0);

          p_Var4 = (_func_5022 *)FUN_0041ef60(pIVar2,pIVar2->AddRef,awStack_98);

          FUN_0041efa0();

          pIVar2->AddRef = p_Var4;

          **(int **)(p_Var4 + 4) = (int)p_Var4;

          iVar9 = iVar9 + 1;

          iVar3 = FUN_0041c000(0,1);

          pIVar2 = local_f8;

        }

        if (local_dc != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        FUN_0041ac00(param_1,iVar9);

        puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

        p_Var5 = local_f8->QueryInterface;

        if (0 < iVar9) {

          do {

            pcVar10 = p_Var5 + 8;

            puVar11 = puVar8;

            for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {

              *puVar11 = *(uint32_t /* width from decompiler */ *)pcVar10;

              pcVar10 = pcVar10 + 4;

              puVar11 = puVar11 + 1;

            }

            puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 0x82);

            iVar9 = iVar9 + -1;

            *(uint16_t *)puVar11 = *(uint16_t *)pcVar10;

            p_Var5 = *(_func_5021 **)p_Var5;

          } while (iVar9 != 0);

        }

        pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);

        FUN_0041a3e0(&local_ec);

        pIVar2 = local_f8;

        goto LAB_007db5e8;

      }

      iVar3 = -0x7fffbffb;

    }

    FUN_00423170();

    FUN_007a4480(1,"DBReader: %u against %s",iVar3,"dcFetch::Open");

    pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);

    FUN_0041a3e0(&local_ec);

    FUN_00415e90();

    pIVar2 = local_f8;

  }

  else {

    local_fc = SysAllocString(L"//tRegionMaps/row[@IDRegion=\'");

    if (local_fc == (BSTR)0x0) {

LAB_007db40b:

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_f8 = (IUnknownVtbl *)0x0;

    local_4._0_1_ = 4;

    lpString = _itow(param_2,local_b8,10);

    lstrlenW(lpString);

    iVar9 = FUN_00422ee0(lpString);

    if (iVar9 < 0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    lstrlenW(L"\']");

    iVar9 = FUN_00422ee0(&DAT_00a951ec);

    if (iVar9 < 0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_e8 = (IUnknownVtbl *)&stack0xfffffee8;

    FUN_00419ca0(&stack0xfffffee8);

    local_4._0_1_ = 5;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,4);

    piVar6 = (int *)FUN_00419ed0(&local_100);

    pIVar12 = (IUnknownVtbl *)*piVar6;

    if (pIVar12 != (IUnknownVtbl *)0x0) {

      local_f8 = pIVar12;

      (**(code **)(pIVar12->QueryInterface + 4))();

    }

    if (local_100 != (int *)0x0) {

      (**(code **)(*local_100 + 8))();

    }

    pIVar12 = local_f8;

    if (local_f8 == (IUnknownVtbl *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_100 = (int *)0x0;

    iVar9 = (**(code **)(pIVar12->QueryInterface + 0x20))(pIVar12);

    if (iVar9 < 0) {

      _com_issue_errorex(iVar9,(IUnknown *)pIVar12,(_GUID *)&DAT_00a86118);

    }

    pIVar12 = local_f8;

    FUN_0041ac00();

    iVar9 = 0;

    if (0 < (int)pIVar12) {

      do {

        if (local_fc != (BSTR)0x0) {

          (**(code **)(*(int *)local_fc + 8))();

        }

        local_fc = (BSTR)0x0;

        (**(code **)(local_f0->QueryInterface + 0x1c))();

        if (local_fc != (BSTR)0x0) {

          local_e0 = &stack0xfffffeec;

          pOVar7 = SysAllocString(L"strFilename");

          if (pOVar7 == (BSTR)0x0) goto LAB_007db40b;

          local_e0 = &stack0xfffffee8;

          puVar1 = &stack0xfffffee8;

          if (local_fc != (BSTR)0x0) {

            (**(code **)(*(int *)local_fc + 4))(local_fc);

            puVar1 = local_e0;

          }

          local_e0 = puVar1;

          FUN_007b8de0();

          pIVar12 = local_f8;

        }

        iVar9 = iVar9 + 1;

        pIVar2 = local_e8;

      } while (iVar9 < (int)pIVar12);

    }

    if (local_fc != (BSTR)0x0) {

      (**(code **)(*(int *)local_fc + 8))();

    }

    (**(code **)(local_f0->QueryInterface + 8))();

    SysFreeString((BSTR)0x0);

LAB_007db5e8:

    pIVar12 = (IUnknownVtbl *)pIVar2->QueryInterface;

    pIVar2->QueryInterface = (_func_5021 *)pIVar2;

    pIVar2->AddRef = (_func_5022 *)pIVar2;

    if (pIVar12 != pIVar2) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pIVar12);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pIVar2);

}
