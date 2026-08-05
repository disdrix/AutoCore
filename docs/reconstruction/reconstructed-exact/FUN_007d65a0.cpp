// =============================================================================
// FUN_007d65a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007d65a0
// Address:   0x007d65a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007d65a0 @ 0x007d65a0
// Stable ID: aa_007d65a0
// Embedded strings (evidence for future rename):
//   - "//tCreatureEnhancement/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~188 non-empty decompiler lines.
//  - Control keywords: if×13, return×5, while×2, do×1.
//  - Notable callees: block×36, FUN_004231d0×9, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2, FUN_0041c000×2, CoTaskMemAlloc, FUN_004048e0.
//  - Strings: "//tCreatureEnhancement/row".
//  - Return sites: 5.

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

/* WARNING: Removing unreachable block (ram,0x007d6b30) */

/* WARNING: Removing unreachable block (ram,0x007d6b49) */

/* WARNING: Removing unreachable block (ram,0x007d6b5e) */

/* WARNING: Removing unreachable block (ram,0x007d6b64) */

/* WARNING: Removing unreachable block (ram,0x007d6b8c) */

/* WARNING: Removing unreachable block (ram,0x007d6ba1) */

/* WARNING: Removing unreachable block (ram,0x007d6ba7) */

/* WARNING: Removing unreachable block (ram,0x007d6bce) */

/* WARNING: Removing unreachable block (ram,0x007d6be3) */

/* WARNING: Removing unreachable block (ram,0x007d6be9) */

/* WARNING: Removing unreachable block (ram,0x007d6c10) */

/* WARNING: Removing unreachable block (ram,0x007d6c25) */

/* WARNING: Removing unreachable block (ram,0x007d6c2b) */

/* WARNING: Removing unreachable block (ram,0x007d6c52) */

/* WARNING: Removing unreachable block (ram,0x007d6c67) */

/* WARNING: Removing unreachable block (ram,0x007d6c6d) */

/* WARNING: Removing unreachable block (ram,0x007d6c94) */

/* WARNING: Removing unreachable block (ram,0x007d6ca9) */

/* WARNING: Removing unreachable block (ram,0x007d6caf) */

/* WARNING: Removing unreachable block (ram,0x007d6cd4) */

/* WARNING: Removing unreachable block (ram,0x007d6ce9) */

/* WARNING: Removing unreachable block (ram,0x007d6cef) */

/* WARNING: Removing unreachable block (ram,0x007d6d15) */

/* WARNING: Removing unreachable block (ram,0x007d6d2a) */

/* WARNING: Removing unreachable block (ram,0x007d6d30) */

/* WARNING: Removing unreachable block (ram,0x007d6d5e) */

/* WARNING: Removing unreachable block (ram,0x007d6d73) */

/* WARNING: Removing unreachable block (ram,0x007d6d79) */

/* WARNING: Removing unreachable block (ram,0x007d68f6) */

/* WARNING: Removing unreachable block (ram,0x007d691b) */

/* WARNING: Removing unreachable block (ram,0x007d693f) */

/* WARNING: Removing unreachable block (ram,0x007d6949) */

/* WARNING: Removing unreachable block (ram,0x007d6950) */

/* WARNING: Removing unreachable block (ram,0x007d69bc) */

/* WARNING: Removing unreachable block (ram,0x007d69c4) */

/* WARNING: Removing unreachable block (ram,0x007d69d6) */



uint32_t /* width from decompiler */ __thiscall FUN_007d65a0(char *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  ULONG UVar5;

  LPVOID pvVar6;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_retaddr;

  int *piVar7;

  uint32_t /* width from decompiler */ uStack_d0;

  IUnknown *local_cc;

  uint32_t /* width from decompiler */ *local_c4;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ local_b0;

  BSTR *local_ac;

  uint32_t /* width from decompiler */ local_a8;

  int local_a4;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ *local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  int local_8c;

  BSTR local_78;

  BSTR local_74;

  uint8_t local_54;

  wchar_t local_52 [17];

  wchar_t local_30 [18];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  pvVar2 = ExceptionList;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aea68;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = 0;

  *param_2 = 0;

  if (*param_1 == '\0') {

    ExceptionList = pvVar2;

    return 0x80004004;

  }

  iVar3 = FUN_0041c9d0();

  local_4 = 0;

  if (DAT_00d1793c == '\0') {

    local_9c = &local_b4;

    local_b4 = 0;

    local_b0 = 0;

    local_ac = (BSTR *)0x0;

    local_a8 = 0;

    local_a4 = 0;

    local_a0 = 0;

    local_94 = 0;

    local_98 = 0;

    local_90 = 0;

    local_8c = 0;

    local_4 = 1;

    iVar4 = FUN_0041a810(local_9c,param_1 + 0x28,0);

    local_ac = &local_78;

    if ((((((-1 < iVar4) && (iVar4 = FUN_004231d0(), -1 < iVar4)) &&

          (iVar4 = FUN_004231d0(), -1 < iVar4)) &&

         ((iVar4 = FUN_004231d0(), -1 < iVar4 && (iVar4 = FUN_004231d0(), -1 < iVar4)))) &&

        ((iVar4 = FUN_004231d0(), -1 < iVar4 &&

         ((iVar4 = FUN_004231d0(), -1 < iVar4 && (iVar4 = FUN_004231d0(), -1 < iVar4)))))) &&

       ((iVar4 = FUN_004231d0(), -1 < iVar4 &&

        ((iVar4 = FUN_004231d0(), -1 < iVar4 && (local_a4 != 0)))))) {

      iVar4 = FUN_0041c000();

      while (iVar4 == 0) {

        local_54 = uStack_d0._3_1_;

        wcscpy(local_52,local_30);

        iVar4 = FUN_0041fa50();

        FUN_0044de90();

        *(int *)(iVar3 + 4) = iVar4;

        **(int **)(iVar4 + 4) = iVar4;

        iVar4 = FUN_0041c000();

      }

      local_4 = local_4 & 0xffffff00;

      FUN_0041a3e0();

      FUN_00415d60();

      ExceptionList = local_c;

      return 0;

    }

    FUN_00423170();

    FUN_007a4480();

    local_4 = local_4 & 0xffffff00;

    local_c4 = (uint32_t /* width from decompiler */ *)0x7d67e4;

    FUN_0041a3e0();

    FUN_00415e90();

  }

  else {

    local_74 = SysAllocString(L"//tCreatureEnhancement/row");

    if (local_74 == (BSTR)0x0) {

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

    if (local_cc == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    UVar5 = (*local_cc->lpVtbl[2].Release)(local_cc);

    if ((int)UVar5 < 0) {

      _com_issue_errorex(UVar5,local_cc,(_GUID *)&DAT_00a86118);

    }

    *unaff_retaddr = local_cc;

    pvVar6 = CoTaskMemAlloc((int)local_cc * 0x38);

    *param_3 = pvVar6;

    local_8c = 0;

    piVar7 = unaff_EBX;

    if (0 < (int)local_cc) {

      do {

        if (uStack_d0 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        if (piVar7 != (int *)0x0) {

          (**(code **)(*piVar7 + 8))();

        }

        (**(code **)(*uStack_d0 + 0x1c))();

        unaff_EBX = (int *)0x0;

        local_8c = local_8c + 1;

        piVar7 = (int *)0x0;

      } while (local_8c < (int)local_cc);

    }

    puStack_8._0_1_ = 4;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,2);

    if (uStack_d0 != (int *)0x0) {

      (**(code **)(*uStack_d0 + 8))();

    }

    SysFreeString(local_78);

    puVar1 = (uint32_t /* width from decompiler */ *)*local_c4;

    *local_c4 = local_c4;

    local_c4[1] = local_c4;

    if (puVar1 != local_c4) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar1);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_c4);

}
