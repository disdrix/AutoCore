// =============================================================================
// Named_tRegion
// -----------------------------------------------------------------------------
// Stable ID: aa_007db630
// Address:   0x007db630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_tRegion @ 0x007db630
// Stable ID: aa_007db630
// Embedded strings (evidence for future rename):
//   - "//tRegion/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~232 non-empty decompiler lines.
//  - Control keywords: if×15, return×4, while×3, for×3, do×2, goto×1.
//  - Notable callees: block×22, FUN_004231d0×7, CONCAT31×2, FUN_00415e90×2, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, _com_issue_error×2.
//  - Strings: "//tRegion/row".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//tRegion/row"
 * Domain alias of FUN_007db630 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007dba9a) */

/* WARNING: Removing unreachable block (ram,0x007dbab2) */

/* WARNING: Removing unreachable block (ram,0x007dbac7) */

/* WARNING: Removing unreachable block (ram,0x007dbacd) */

/* WARNING: Removing unreachable block (ram,0x007dbaef) */

/* WARNING: Removing unreachable block (ram,0x007dbb04) */

/* WARNING: Removing unreachable block (ram,0x007dbb0a) */

/* WARNING: Removing unreachable block (ram,0x007dbb2c) */

/* WARNING: Removing unreachable block (ram,0x007dbb41) */

/* WARNING: Removing unreachable block (ram,0x007dbb47) */

/* WARNING: Removing unreachable block (ram,0x007dbb68) */

/* WARNING: Removing unreachable block (ram,0x007dbb7d) */

/* WARNING: Removing unreachable block (ram,0x007dbb83) */

/* WARNING: Removing unreachable block (ram,0x007dbba5) */

/* WARNING: Removing unreachable block (ram,0x007dbbba) */

/* WARNING: Removing unreachable block (ram,0x007dbbc0) */

/* WARNING: Removing unreachable block (ram,0x007dbbe3) */

/* WARNING: Removing unreachable block (ram,0x007dbbf8) */

/* WARNING: Removing unreachable block (ram,0x007dbbfe) */

/* WARNING: Removing unreachable block (ram,0x007dbc25) */

/* WARNING: Removing unreachable block (ram,0x007dbc3a) */

/* WARNING: Removing unreachable block (ram,0x007dbc40) */



void __thiscall Named_tRegion(char *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  ULONG UVar4;

  IUnknown *pIVar5;

  uint32_t /* width from decompiler */ *puVar6;

  IUnknown *unaff_EBX;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  IUnknown *This;

  BSTR *ppOVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ auStackY_168 [15];

  uint32_t /* width from decompiler */ uStackY_12c;

  uint32_t /* width from decompiler */ *puStackY_128;

  char *pcStackY_124;

  int *local_f8;

  IUnknown *local_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  int local_ec;

  uint8_t *local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  IUnknown **local_dc;

  uint32_t /* width from decompiler */ local_d8;

  int local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ *local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  uint32_t /* width from decompiler */ *local_b4;

  uint32_t /* width from decompiler */ local_b0;

  BSTR local_ac [3];

  wchar_t local_a0 [33];

  uint8_t local_5e;

  int local_5c;

  wchar_t local_50 [34];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aed12;

  pvStack_c = ExceptionList;

  iVar7 = 0;

  ExceptionList = &pvStack_c;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0041c420();

  local_b0 = 0;

  local_4 = 0;

  local_b4 = puVar1;

  if (DAT_00d1793c == '\0') {

    if (*param_1 == '\0') {

      FUN_00415e90();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_b4);

    }

    puStackY_128 = &local_e4;

    local_e4 = 0;

    local_e0 = 0;

    local_dc = (IUnknown **)0x0;

    local_d8 = 0;

    local_d4 = 0;

    local_d0 = 0;

    local_c4 = 0;

    local_c8 = 0;

    local_c0 = 0;

    local_bc = 0;

    pcStackY_124 = param_1 + 0x28;

    local_4 = 1;

    uStackY_12c = 0x7db6ed;

    local_cc = puStackY_128;

    iVar2 = FUN_0041a810();

    local_dc = &local_f4;

    if ((((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

          (iVar2 = FUN_004231d0(), iVar2 < 0)) ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||

        ((iVar2 = FUN_004231d0(), iVar2 < 0 ||

         ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||

       (local_d4 == 0)) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = local_4 & 0xffffff00;

      FUN_0041a3e0();

      FUN_00415e90();

      puVar1 = local_b4;

      goto LAB_007dbcb4;

    }

    iVar2 = FUN_0041c000();

    while (iVar2 == 0) {

      wcscpy(local_a0,local_50);

      local_5c = (int)(short)local_ec;

      local_5e = uStack_f0._3_1_;

      iVar2 = FUN_0041eba0();

      FUN_0041ebd0();

      puVar1[1] = iVar2;

      **(int **)(iVar2 + 4) = iVar2;

      iVar7 = iVar7 + 1;

      iVar2 = FUN_0041c000();

      puVar1 = local_b4;

    }

    if (local_d4 != 0) {

      FUN_00422de0();

      FUN_0041bf70();

    }

    FUN_00423170();

    FUN_0041abc0();

    puVar1 = local_b4;

    puVar3 = (uint32_t /* width from decompiler */ *)*local_b4;

    puVar6 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

    if (0 < iVar7) {

      do {

        iVar7 = iVar7 + -1;

        puVar8 = puVar3 + 2;

        puVar10 = puVar6;

        for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar10 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar10 = puVar10 + 1;

        }

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

        puVar6 = puVar6 + 0x16;

      } while (iVar7 != 0);

    }

    local_4 = local_4 & 0xffffff00;

    FUN_0041a3e0();

  }

  else {

    local_ac[0] = SysAllocString(L"//tRegion/row");

    if (local_ac[0] == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_f4 = (IUnknown *)0x0;

    local_e8 = &stack0xfffffef0;

    local_4._0_1_ = 4;

    FUN_00419ca0();

    local_4._0_1_ = 5;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,4);

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    pIVar5 = (IUnknown *)*puVar1;

    This = (IUnknown *)0x0;

    if (pIVar5 != (IUnknown *)0x0) {

      local_f4 = pIVar5;

      (*pIVar5->lpVtbl->AddRef)(pIVar5);

      This = local_f4;

    }

    if (local_f8 != (int *)0x0) {

      (**(code **)(*local_f8 + 8))();

    }

    if (This == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_ec = 0;

    UVar4 = (*This->lpVtbl[2].Release)(This);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,This,(_GUID *)&DAT_00a86118);

    }

    ppOVar9 = local_ac;

    for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {

      *ppOVar9 = (BSTR)0x0;

      ppOVar9 = ppOVar9 + 1;

    }

    ppOVar9 = local_ac;

    puVar1 = auStackY_168;

    for (iVar7 = 0x16; iVar7 != 0; iVar7 = iVar7 + -1) {

      *puVar1 = *ppOVar9;

      ppOVar9 = ppOVar9 + 1;

      puVar1 = puVar1 + 1;

    }

    FUN_0041c440();

    local_ec = 0;

    pIVar5 = unaff_EBX;

    if (0 < uStack_f0) {

      do {

        iVar7 = local_ec;

        if (pIVar5 != (IUnknown *)0x0) {

          (*pIVar5->lpVtbl->Release)(pIVar5);

        }

        (**(code **)(*local_f8 + 0x1c))();

        unaff_EBX = (IUnknown *)0x0;

        local_ec = iVar7 + 1;

        pIVar5 = (IUnknown *)0x0;

      } while (local_ec < uStack_f0);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (IUnknown *)0x0) {

      (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    (**(code **)(*local_f8 + 8))();

    SysFreeString(local_ac[0]);

    puVar1 = local_b4;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)*puVar1;

  *puVar1 = puVar1;

  puVar1[1] = puVar1;

  if (puVar3 != puVar1) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar3);

  }

LAB_007dbcb4:

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar1);

}
