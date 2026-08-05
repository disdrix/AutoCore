// =============================================================================
// Named_tFactions
// -----------------------------------------------------------------------------
// Stable ID: aa_007ce550
// Address:   0x007ce550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_tFactions @ 0x007ce550
// Stable ID: aa_007ce550
// Embedded strings (evidence for future rename):
//   - "//tFactions/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, for×2, while×1.
//  - Notable callees: block×18, FUN_004231d0×3, CONCAT31×2, FUN_00415e90×2, FUN_0041a3e0×2, FUN_0041b060×2, FUN_0041c000×2, FUN_00423170×2.
//  - Strings: "//tFactions/row".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "//tFactions/row"
 * Domain alias of FUN_007ce550 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007ce8e3) */

/* WARNING: Removing unreachable block (ram,0x007ce8ff) */

/* WARNING: Removing unreachable block (ram,0x007ce914) */

/* WARNING: Removing unreachable block (ram,0x007ce91a) */

/* WARNING: Removing unreachable block (ram,0x007ce945) */

/* WARNING: Removing unreachable block (ram,0x007ce95a) */

/* WARNING: Removing unreachable block (ram,0x007ce960) */

/* WARNING: Removing unreachable block (ram,0x007ce985) */

/* WARNING: Removing unreachable block (ram,0x007ce8a2) */

/* WARNING: Removing unreachable block (ram,0x007ce99a) */

/* WARNING: Removing unreachable block (ram,0x007ce9a0) */

/* WARNING: Removing unreachable block (ram,0x007ce9ac) */

/* WARNING: Removing unreachable block (ram,0x007ce8a5) */

/* WARNING: Removing unreachable block (ram,0x007ce8ab) */

/* WARNING: Removing unreachable block (ram,0x007ce8b9) */

/* WARNING: Removing unreachable block (ram,0x007ce8c1) */

/* WARNING: Removing unreachable block (ram,0x007ce8c7) */

/* WARNING: Removing unreachable block (ram,0x007ce9e1) */



uint32_t /* width from decompiler */ __thiscall Named_tFactions(char *param_1,int *param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  ULONG UVar5;

  uint32_t /* width from decompiler */ *puVar6;

  IUnknown *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *unaff_retaddr;

  IUnknown *local_11c;

  uint32_t /* width from decompiler */ *local_114;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  uint32_t /* width from decompiler */ local_100;

  uint32_t /* width from decompiler */ *local_fc;

  uint32_t /* width from decompiler */ local_f8;

  int local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ *local_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  BSTR local_dc;

  BSTR local_d8;

  wchar_t local_d4 [34];

  wchar_t local_90 [66];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae88b;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  ExceptionList = &local_c;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_004933f0();

  local_4 = 0;

  if (DAT_00d1793c == '\0') {

    local_ec = &local_104;

    local_104 = 0;

    local_100 = 0;

    local_fc = (uint32_t /* width from decompiler */ *)0x0;

    local_f8 = 0;

    local_f4 = 0;

    local_f0 = 0;

    local_e4 = 0;

    local_e8 = 0;

    local_e0 = 0;

    local_dc = (BSTR)0x0;

    local_4 = 1;

    iVar2 = FUN_0041a810(local_ec,param_1 + 0x28,0);

    local_fc = &local_108;

    if ((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) || (iVar2 = FUN_004231d0(), iVar2 < 0)

        ) || ((iVar2 = FUN_004231d0(), iVar2 < 0 || (local_f4 == 0)))) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = local_4 & 0xffffff00;

      local_114 = (uint32_t /* width from decompiler */ *)0x7ce6a4;

      FUN_0041a3e0();

      FUN_00415e90();

    }

    else {

      iVar2 = 0;

      iVar3 = FUN_0041c000();

      while (iVar3 == 0) {

        puVar4 = operator_new(0xc4);

        *puVar4 = local_108;

        wcscpy((wchar_t *)(puVar4 + 1),local_d4);

        wcscpy((wchar_t *)(puVar4 + 0x11),local_90);

        iVar3 = FUN_006759b0();

        FUN_0043fe60();

        puVar1[1] = iVar3;

        **(int **)(iVar3 + 4) = iVar3;

        iVar2 = iVar2 + 1;

        iVar3 = FUN_0041c000();

      }

      *param_2 = iVar2;

      if (local_f4 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      FUN_0041b060();

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_3 + 4);

      for (puVar4 = (uint32_t /* width from decompiler */ *)*puVar1; puVar4 != puVar1; puVar4 = (uint32_t /* width from decompiler */ *)*puVar4) {

        puVar7 = (uint32_t /* width from decompiler */ *)puVar4[2];

        puVar8 = puVar6;

        for (iVar2 = 0x31; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar8 = *puVar7;

          puVar7 = puVar7 + 1;

          puVar8 = puVar8 + 1;

        }

        puVar6 = puVar6 + 0x31;

      }

      local_4 = local_4 & 0xffffff00;

      local_114 = (uint32_t /* width from decompiler */ *)0x7ce7ba;

      FUN_0041a3e0();

      FUN_00415e90();

    }

  }

  else {

    local_d8 = SysAllocString(L"//tFactions/row");

    if (local_d8 == (BSTR)0x0) {

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

    if (local_11c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar5 = (*local_11c->lpVtbl[2].Release)(local_11c);

    if ((int)UVar5 < 0) {

      _com_issue_errorex(UVar5,local_11c,(_GUID *)&DAT_00a86118);

    }

    *unaff_retaddr = 0;

    FUN_0041b060();

    puStack_8._0_1_ = 4;

    if (unaff_EBX != (IUnknown *)0x0) {

      (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    SysFreeString(local_dc);

    puVar1 = (uint32_t /* width from decompiler */ *)*local_114;

    *local_114 = local_114;

    local_114[1] = local_114;

    if (puVar1 != local_114) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar1);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_114);

}
