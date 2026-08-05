// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007d0250
// -----------------------------------------------------------------------------
// Stable ID: aa_007d0250
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007d0250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~345 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, do×2, while×2.
//  - Notable callees: block×100, FUN_004231d0×34, FUN_0041a3e0×4, _com_issue_error×3, CONCAT31×2, CoTaskMemAlloc×2, FUN_00423170×2, wcscpy×2.
//  - Strings: "//vPrefixOrnament/row".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007d0cc7) */

/* WARNING: Removing unreachable block (ram,0x007d0c9a) */

/* WARNING: Removing unreachable block (ram,0x007d0cb2) */

/* WARNING: Removing unreachable block (ram,0x007d0ccd) */

/* WARNING: Removing unreachable block (ram,0x007d0d00) */

/* WARNING: Removing unreachable block (ram,0x007d0d15) */

/* WARNING: Removing unreachable block (ram,0x007d0d1b) */

/* WARNING: Removing unreachable block (ram,0x007d0d44) */

/* WARNING: Removing unreachable block (ram,0x007d0d59) */

/* WARNING: Removing unreachable block (ram,0x007d0d5f) */

/* WARNING: Removing unreachable block (ram,0x007d0d88) */

/* WARNING: Removing unreachable block (ram,0x007d0d9d) */

/* WARNING: Removing unreachable block (ram,0x007d0da3) */

/* WARNING: Removing unreachable block (ram,0x007d0dcc) */

/* WARNING: Removing unreachable block (ram,0x007d0de1) */

/* WARNING: Removing unreachable block (ram,0x007d0de7) */

/* WARNING: Removing unreachable block (ram,0x007d0e11) */

/* WARNING: Removing unreachable block (ram,0x007d0e26) */

/* WARNING: Removing unreachable block (ram,0x007d0e2c) */

/* WARNING: Removing unreachable block (ram,0x007d0e56) */

/* WARNING: Removing unreachable block (ram,0x007d0e6b) */

/* WARNING: Removing unreachable block (ram,0x007d0e71) */

/* WARNING: Removing unreachable block (ram,0x007d0e9b) */

/* WARNING: Removing unreachable block (ram,0x007d0eb0) */

/* WARNING: Removing unreachable block (ram,0x007d0eb6) */

/* WARNING: Removing unreachable block (ram,0x007d0ee0) */

/* WARNING: Removing unreachable block (ram,0x007d0ef5) */

/* WARNING: Removing unreachable block (ram,0x007d0efb) */

/* WARNING: Removing unreachable block (ram,0x007d0f25) */

/* WARNING: Removing unreachable block (ram,0x007d0f3a) */

/* WARNING: Removing unreachable block (ram,0x007d0f40) */

/* WARNING: Removing unreachable block (ram,0x007d0f67) */

/* WARNING: Removing unreachable block (ram,0x007d0f7c) */

/* WARNING: Removing unreachable block (ram,0x007d0f82) */

/* WARNING: Removing unreachable block (ram,0x007d0fa9) */

/* WARNING: Removing unreachable block (ram,0x007d0fbe) */

/* WARNING: Removing unreachable block (ram,0x007d0fc4) */

/* WARNING: Removing unreachable block (ram,0x007d0fe8) */

/* WARNING: Removing unreachable block (ram,0x007d0ffd) */

/* WARNING: Removing unreachable block (ram,0x007d1003) */

/* WARNING: Removing unreachable block (ram,0x007d1028) */

/* WARNING: Removing unreachable block (ram,0x007d103d) */

/* WARNING: Removing unreachable block (ram,0x007d1043) */

/* WARNING: Removing unreachable block (ram,0x007d1068) */

/* WARNING: Removing unreachable block (ram,0x007d107d) */

/* WARNING: Removing unreachable block (ram,0x007d1083) */

/* WARNING: Removing unreachable block (ram,0x007d10ab) */

/* WARNING: Removing unreachable block (ram,0x007d10c0) */

/* WARNING: Removing unreachable block (ram,0x007d10c6) */

/* WARNING: Removing unreachable block (ram,0x007d10eb) */

/* WARNING: Removing unreachable block (ram,0x007d1100) */

/* WARNING: Removing unreachable block (ram,0x007d1106) */

/* WARNING: Removing unreachable block (ram,0x007d112e) */

/* WARNING: Removing unreachable block (ram,0x007d1143) */

/* WARNING: Removing unreachable block (ram,0x007d1149) */

/* WARNING: Removing unreachable block (ram,0x007d1171) */

/* WARNING: Removing unreachable block (ram,0x007d1186) */

/* WARNING: Removing unreachable block (ram,0x007d118c) */

/* WARNING: Removing unreachable block (ram,0x007d11b4) */

/* WARNING: Removing unreachable block (ram,0x007d11c9) */

/* WARNING: Removing unreachable block (ram,0x007d11cf) */

/* WARNING: Removing unreachable block (ram,0x007d11f7) */

/* WARNING: Removing unreachable block (ram,0x007d120c) */

/* WARNING: Removing unreachable block (ram,0x007d1212) */

/* WARNING: Removing unreachable block (ram,0x007d123a) */

/* WARNING: Removing unreachable block (ram,0x007d124f) */

/* WARNING: Removing unreachable block (ram,0x007d1255) */

/* WARNING: Removing unreachable block (ram,0x007d1285) */

/* WARNING: Removing unreachable block (ram,0x007d129a) */

/* WARNING: Removing unreachable block (ram,0x007d12a0) */

/* WARNING: Removing unreachable block (ram,0x007d12bf) */

/* WARNING: Removing unreachable block (ram,0x007d12d4) */

/* WARNING: Removing unreachable block (ram,0x007d12da) */

/* WARNING: Removing unreachable block (ram,0x007d1302) */

/* WARNING: Removing unreachable block (ram,0x007d1317) */

/* WARNING: Removing unreachable block (ram,0x007d131d) */

/* WARNING: Removing unreachable block (ram,0x007d1346) */

/* WARNING: Removing unreachable block (ram,0x007d135b) */

/* WARNING: Removing unreachable block (ram,0x007d1361) */

/* WARNING: Removing unreachable block (ram,0x007d138b) */

/* WARNING: Removing unreachable block (ram,0x007d13a0) */

/* WARNING: Removing unreachable block (ram,0x007d13a6) */

/* WARNING: Removing unreachable block (ram,0x007d13cf) */

/* WARNING: Removing unreachable block (ram,0x007d13e4) */

/* WARNING: Removing unreachable block (ram,0x007d13ea) */

/* WARNING: Removing unreachable block (ram,0x007d1413) */

/* WARNING: Removing unreachable block (ram,0x007d1428) */

/* WARNING: Removing unreachable block (ram,0x007d142e) */

/* WARNING: Removing unreachable block (ram,0x007d1457) */

/* WARNING: Removing unreachable block (ram,0x007d146c) */

/* WARNING: Removing unreachable block (ram,0x007d1472) */

/* WARNING: Removing unreachable block (ram,0x007d149b) */

/* WARNING: Removing unreachable block (ram,0x007d14b0) */

/* WARNING: Removing unreachable block (ram,0x007d14b6) */

/* WARNING: Removing unreachable block (ram,0x007d14e9) */

/* WARNING: Removing unreachable block (ram,0x007d14fe) */

/* WARNING: Removing unreachable block (ram,0x007d1504) */

/* WARNING: Removing unreachable block (ram,0x007d1523) */

/* WARNING: Removing unreachable block (ram,0x007d1538) */

/* WARNING: Removing unreachable block (ram,0x007d153e) */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007d0250(char *param_1,int *param_2,int *param_3)



{

  int *piVar1;

  IUnknown *pIVar2;

  int iVar3;

  LPVOID pvVar4;

  int iVar5;

  ULONG UVar6;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_retaddr;

  int *piVar7;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ local_170;

  uint32_t /* width from decompiler */ *local_16c;

  uint32_t /* width from decompiler */ local_168;

  int local_164;

  uint32_t /* width from decompiler */ local_160;

  uint32_t /* width from decompiler */ *local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  uint32_t /* width from decompiler */ local_150;

  int *local_14c;

  IUnknown *local_148;

  uint8_t *local_144;

  uint16_t local_140;

  short local_13c;

  uint16_t local_138;

  uint16_t local_134;

  uint16_t local_130;

  int local_12c;

  uint16_t local_124;

  uint16_t local_120;

  uint16_t local_11c;

  uint16_t local_118;

  short local_114;

  short local_110;

  short local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  uint32_t /* width from decompiler */ local_100;

  uint32_t /* width from decompiler */ local_fc;

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  BSTR local_d8;

  BSTR local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  wchar_t local_b8 [34];

  wchar_t local_74 [50];

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae954;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = 0;

  *param_2 = 0;

  if (*param_1 == '\0') {

    ExceptionList = pvStack_10;

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_15c = &local_174;

    local_174 = 0;

    local_170 = 0;

    local_16c = (uint32_t /* width from decompiler */ *)0x0;

    local_168 = 0;

    local_164 = 0;

    local_160 = 0;

    local_154 = 0;

    local_158 = 0;

    local_150 = 0;

    local_14c = (int *)0x0;

    local_4 = 0;

    iVar3 = FUN_0041a810(local_15c,param_1 + 0x28,0);

    local_16c = &local_108;

    if (((((((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

          ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||

         ((iVar3 = FUN_004231d0(), iVar3 < 0 ||

          ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))) ||

        (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

       ((((((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

          (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           ((iVar3 = FUN_004231d0(), iVar3 < 0 ||

            ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||

         ((((iVar3 = FUN_004231d0(), iVar3 < 0 ||

            (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

             (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||

           (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

            (((iVar3 = FUN_004231d0(), iVar3 < 0 ||

              ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||

             (iVar3 = FUN_004231d0(), iVar3 < 0)))))) ||

          ((((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

            (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||

        (((iVar3 = FUN_004231d0(), iVar3 < 0 ||

          ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||

         (local_164 == 0)))))) {

      FUN_00423170();

      FUN_007a4480();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      *param_3 = 0;

      *param_2 = 0;

      iVar3 = FUN_0041a9b0();

      if (iVar3 == 0) {

        if (local_10c < 1) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0;

        }

        *param_2 = (int)local_10c;

        pvVar4 = CoTaskMemAlloc(local_10c * 0x120);

        *param_3 = (int)pvVar4;

        if (pvVar4 == (LPVOID)0x0) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0x8007000e;

        }

        iVar3 = 0;

        do {

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x110 + iVar3) = local_c4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x114 + iVar3) = local_cc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x11c + iVar3) = local_104;

          *(BSTR *)(*param_3 + 0x118 + iVar3) = local_d8;

          *(uint16_t *)(*param_3 + 0x108 + iVar3) = (uint16_t)local_12c;

          *(uint16_t *)(*param_3 + 0x10a + iVar3) = local_138;

          *(uint16_t *)(*param_3 + 0x10e + iVar3) = local_130;

          *(uint16_t *)(*param_3 + 0x10c + iVar3) = local_120;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x84 + iVar3) = local_f8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x10 + iVar3) = local_bc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 8 + iVar3) = local_f0;

          *(uint32_t /* width from decompiler */ *)(iVar3 + *param_3) = local_108;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x14 + iVar3) = local_d0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x18 + iVar3) = local_e8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x88 + iVar3) = local_c0;

          *(uint *)(*param_3 + 0xc + iVar3) = (uint)(local_110 == -1);

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x8c + iVar3) = local_e0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x90 + iVar3) = local_c8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x94 + iVar3) = local_100;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x98 + iVar3) = local_fc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x9c + iVar3) = local_f4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xa0 + iVar3) = local_ec;

          *(uint *)(*param_3 + 0xa4 + iVar3) = (uint)(local_114 == -1);

          *(uint16_t *)(*param_3 + 0xa8 + iVar3) = local_134;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xac + iVar3) = local_e4;

          *(uint16_t *)(*param_3 + 0xb0 + iVar3) = local_11c;

          *(uint16_t *)(*param_3 + 0xb2 + iVar3) = local_140;

          *(uint16_t *)(*param_3 + 0xb4 + iVar3) = local_118;

          *(uint16_t *)(*param_3 + 0xb6 + iVar3) = local_124;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xbc + iVar3) = local_dc;

          wcscpy((wchar_t *)(*param_3 + 0x1c + iVar3),local_74);

          wcscpy((wchar_t *)(*param_3 + 0xc4 + iVar3),local_b8);

          iVar3 = iVar3 + 0x120;

          *(uint *)(*param_3 + -0x60 + iVar3) = (uint)(local_13c == -1);

          iVar5 = FUN_0041c000();

        } while (iVar5 == 0);

      }

      if (local_164 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    local_d4 = SysAllocString(L"//vPrefixOrnament/row");

    if (local_d4 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_144 = &stack0xfffffe70;

    local_4 = 1;

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    if (local_148 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    pIVar2 = local_148;

    local_144 = (uint8_t *)0x0;

    UVar6 = (*local_148->lpVtbl[2].Release)(local_148);

    if ((int)UVar6 < 0) {

      _com_issue_errorex(UVar6,pIVar2,(_GUID *)&DAT_00a86118);

    }

    pIVar2 = local_148;

    *unaff_retaddr = local_148;

    pvVar4 = CoTaskMemAlloc((int)local_148 * 0x120);

    *param_3 = (int)pvVar4;

    local_12c = 0;

    piVar7 = unaff_EBX;

    if (0 < (int)pIVar2) {

      do {

        iVar3 = local_12c;

        if (local_14c == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        piVar1 = local_14c;

        if (piVar7 != (int *)0x0) {

          (**(code **)(*piVar7 + 8))();

        }

        piVar7 = (int *)0x0;

        (**(code **)(*piVar1 + 0x1c))();

        unaff_EBX = (int *)0x0;

        local_12c = iVar3 + 1;

      } while (local_12c < (int)local_148);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

    if (local_14c != (int *)0x0) {

      (**(code **)(*local_14c + 8))();

    }

    SysFreeString(local_d8);

  }

  ExceptionList = pvStack_10;

  return 0;

}
