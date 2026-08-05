// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007d51b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007d51b0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007d51b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~350 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, do×2, while×2.
//  - Notable callees: block×103, FUN_004231d0×35, FUN_0041a3e0×4, _com_issue_error×3, CONCAT31×2, CoTaskMemAlloc×2, FUN_00423170×2, wcscpy×2.
//  - Strings: "//vPrefixPowerPlant/row".
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

/* WARNING: Removing unreachable block (ram,0x007d5c60) */

/* WARNING: Removing unreachable block (ram,0x007d5c33) */

/* WARNING: Removing unreachable block (ram,0x007d5c4b) */

/* WARNING: Removing unreachable block (ram,0x007d5c66) */

/* WARNING: Removing unreachable block (ram,0x007d5ca2) */

/* WARNING: Removing unreachable block (ram,0x007d5cb7) */

/* WARNING: Removing unreachable block (ram,0x007d5cbd) */

/* WARNING: Removing unreachable block (ram,0x007d5ce5) */

/* WARNING: Removing unreachable block (ram,0x007d5cfa) */

/* WARNING: Removing unreachable block (ram,0x007d5d00) */

/* WARNING: Removing unreachable block (ram,0x007d5d2a) */

/* WARNING: Removing unreachable block (ram,0x007d5d3f) */

/* WARNING: Removing unreachable block (ram,0x007d5d45) */

/* WARNING: Removing unreachable block (ram,0x007d5d6d) */

/* WARNING: Removing unreachable block (ram,0x007d5d82) */

/* WARNING: Removing unreachable block (ram,0x007d5d88) */

/* WARNING: Removing unreachable block (ram,0x007d5db2) */

/* WARNING: Removing unreachable block (ram,0x007d5dc7) */

/* WARNING: Removing unreachable block (ram,0x007d5dcd) */

/* WARNING: Removing unreachable block (ram,0x007d5df5) */

/* WARNING: Removing unreachable block (ram,0x007d5e0a) */

/* WARNING: Removing unreachable block (ram,0x007d5e10) */

/* WARNING: Removing unreachable block (ram,0x007d5e3a) */

/* WARNING: Removing unreachable block (ram,0x007d5e4f) */

/* WARNING: Removing unreachable block (ram,0x007d5e55) */

/* WARNING: Removing unreachable block (ram,0x007d5e7d) */

/* WARNING: Removing unreachable block (ram,0x007d5e92) */

/* WARNING: Removing unreachable block (ram,0x007d5e98) */

/* WARNING: Removing unreachable block (ram,0x007d5ec2) */

/* WARNING: Removing unreachable block (ram,0x007d5ed7) */

/* WARNING: Removing unreachable block (ram,0x007d5edd) */

/* WARNING: Removing unreachable block (ram,0x007d5f07) */

/* WARNING: Removing unreachable block (ram,0x007d5f1c) */

/* WARNING: Removing unreachable block (ram,0x007d5f22) */

/* WARNING: Removing unreachable block (ram,0x007d5f49) */

/* WARNING: Removing unreachable block (ram,0x007d5f5e) */

/* WARNING: Removing unreachable block (ram,0x007d5f64) */

/* WARNING: Removing unreachable block (ram,0x007d5f8b) */

/* WARNING: Removing unreachable block (ram,0x007d5fa0) */

/* WARNING: Removing unreachable block (ram,0x007d5fa6) */

/* WARNING: Removing unreachable block (ram,0x007d5fca) */

/* WARNING: Removing unreachable block (ram,0x007d5fdf) */

/* WARNING: Removing unreachable block (ram,0x007d5fe5) */

/* WARNING: Removing unreachable block (ram,0x007d600a) */

/* WARNING: Removing unreachable block (ram,0x007d601f) */

/* WARNING: Removing unreachable block (ram,0x007d6025) */

/* WARNING: Removing unreachable block (ram,0x007d604a) */

/* WARNING: Removing unreachable block (ram,0x007d605f) */

/* WARNING: Removing unreachable block (ram,0x007d6065) */

/* WARNING: Removing unreachable block (ram,0x007d608d) */

/* WARNING: Removing unreachable block (ram,0x007d60a2) */

/* WARNING: Removing unreachable block (ram,0x007d60a8) */

/* WARNING: Removing unreachable block (ram,0x007d60cd) */

/* WARNING: Removing unreachable block (ram,0x007d60e2) */

/* WARNING: Removing unreachable block (ram,0x007d60e8) */

/* WARNING: Removing unreachable block (ram,0x007d6110) */

/* WARNING: Removing unreachable block (ram,0x007d6125) */

/* WARNING: Removing unreachable block (ram,0x007d612b) */

/* WARNING: Removing unreachable block (ram,0x007d6153) */

/* WARNING: Removing unreachable block (ram,0x007d6168) */

/* WARNING: Removing unreachable block (ram,0x007d616e) */

/* WARNING: Removing unreachable block (ram,0x007d6196) */

/* WARNING: Removing unreachable block (ram,0x007d61ab) */

/* WARNING: Removing unreachable block (ram,0x007d61b1) */

/* WARNING: Removing unreachable block (ram,0x007d61d9) */

/* WARNING: Removing unreachable block (ram,0x007d61ee) */

/* WARNING: Removing unreachable block (ram,0x007d61f4) */

/* WARNING: Removing unreachable block (ram,0x007d621c) */

/* WARNING: Removing unreachable block (ram,0x007d6231) */

/* WARNING: Removing unreachable block (ram,0x007d6237) */

/* WARNING: Removing unreachable block (ram,0x007d6267) */

/* WARNING: Removing unreachable block (ram,0x007d627c) */

/* WARNING: Removing unreachable block (ram,0x007d6282) */

/* WARNING: Removing unreachable block (ram,0x007d62a1) */

/* WARNING: Removing unreachable block (ram,0x007d62b6) */

/* WARNING: Removing unreachable block (ram,0x007d62bc) */

/* WARNING: Removing unreachable block (ram,0x007d62e4) */

/* WARNING: Removing unreachable block (ram,0x007d62f9) */

/* WARNING: Removing unreachable block (ram,0x007d62ff) */

/* WARNING: Removing unreachable block (ram,0x007d6328) */

/* WARNING: Removing unreachable block (ram,0x007d633d) */

/* WARNING: Removing unreachable block (ram,0x007d6343) */

/* WARNING: Removing unreachable block (ram,0x007d636d) */

/* WARNING: Removing unreachable block (ram,0x007d6382) */

/* WARNING: Removing unreachable block (ram,0x007d6388) */

/* WARNING: Removing unreachable block (ram,0x007d63b1) */

/* WARNING: Removing unreachable block (ram,0x007d63c6) */

/* WARNING: Removing unreachable block (ram,0x007d63cc) */

/* WARNING: Removing unreachable block (ram,0x007d63f5) */

/* WARNING: Removing unreachable block (ram,0x007d640a) */

/* WARNING: Removing unreachable block (ram,0x007d6410) */

/* WARNING: Removing unreachable block (ram,0x007d6439) */

/* WARNING: Removing unreachable block (ram,0x007d644e) */

/* WARNING: Removing unreachable block (ram,0x007d6454) */

/* WARNING: Removing unreachable block (ram,0x007d647d) */

/* WARNING: Removing unreachable block (ram,0x007d6492) */

/* WARNING: Removing unreachable block (ram,0x007d6498) */

/* WARNING: Removing unreachable block (ram,0x007d64cb) */

/* WARNING: Removing unreachable block (ram,0x007d64e0) */

/* WARNING: Removing unreachable block (ram,0x007d64e6) */

/* WARNING: Removing unreachable block (ram,0x007d6505) */

/* WARNING: Removing unreachable block (ram,0x007d651a) */

/* WARNING: Removing unreachable block (ram,0x007d6520) */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007d51b0(char *param_1,int *param_2,int *param_3)



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

  uint32_t /* width from decompiler */ local_178;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ *local_170;

  uint32_t /* width from decompiler */ local_16c;

  int local_168;

  uint32_t /* width from decompiler */ local_164;

  uint32_t /* width from decompiler */ *local_160;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  int *local_150;

  IUnknown *local_14c;

  uint8_t *local_148;

  uint16_t local_144;

  int local_140;

  short local_138;

  uint16_t local_134;

  short local_130;

  uint16_t local_12c;

  short local_128;

  uint16_t local_124;

  short local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

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

  puStack_8 = &LAB_009aea1d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_3 = 0;

  *param_2 = 0;

  if (*param_1 == '\0') {

    ExceptionList = pvStack_10;

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_160 = &local_178;

    local_178 = 0;

    local_174 = 0;

    local_170 = (uint32_t /* width from decompiler */ *)0x0;

    local_16c = 0;

    local_168 = 0;

    local_164 = 0;

    local_158 = 0;

    local_15c = 0;

    local_154 = 0;

    local_150 = (int *)0x0;

    local_4 = 0;

    iVar3 = FUN_0041a810(local_160,param_1 + 0x28,0);

    local_170 = &local_11c;

    if ((((((((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

            (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

           ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||

          ((iVar3 = FUN_004231d0(), iVar3 < 0 ||

           ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))) ||

         (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

        (((((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||

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

           ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))))) ||

       ((((iVar3 = FUN_004231d0(), iVar3 < 0 ||

          ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||

         (iVar3 = FUN_004231d0(), iVar3 < 0)) || (local_168 == 0)))) {

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

        if (local_120 < 1) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0;

        }

        *param_2 = (int)local_120;

        pvVar4 = CoTaskMemAlloc(local_120 * 300);

        *param_3 = (int)pvVar4;

        if (pvVar4 == (LPVOID)0x0) {

          local_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = pvStack_10;

          return 0x8007000e;

        }

        iVar3 = 0;

        do {

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x108 + iVar3) = local_c8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x10c + iVar3) = local_cc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x110 + iVar3) = local_c4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x114 + iVar3) = local_110;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x118 + iVar3) = local_e0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x11c + iVar3) = local_108;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x120 + iVar3) = local_118;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x124 + iVar3) = local_100;

          *(BSTR *)(*param_3 + 0x128 + iVar3) = local_d8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x84 + iVar3) = local_f8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x10 + iVar3) = local_bc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 8 + iVar3) = local_f0;

          *(uint32_t /* width from decompiler */ *)(iVar3 + *param_3) = local_11c;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x14 + iVar3) = local_d0;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x18 + iVar3) = local_e8;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x88 + iVar3) = local_c0;

          *(uint *)(*param_3 + 0xc + iVar3) = (uint)(local_138 == -1);

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x8c + iVar3) = local_114;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x90 + iVar3) = local_10c;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x94 + iVar3) = local_104;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x98 + iVar3) = local_fc;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0x9c + iVar3) = local_f4;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xa0 + iVar3) = local_ec;

          *(uint *)(*param_3 + 0xa4 + iVar3) = (uint)(local_130 == -1);

          *(uint16_t *)(*param_3 + 0xa8 + iVar3) = (uint16_t)local_140;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xac + iVar3) = local_e4;

          *(uint16_t *)(*param_3 + 0xb0 + iVar3) = local_134;

          *(uint16_t *)(*param_3 + 0xb2 + iVar3) = local_124;

          *(uint16_t *)(*param_3 + 0xb4 + iVar3) = local_12c;

          *(uint16_t *)(*param_3 + 0xb6 + iVar3) = local_144;

          *(uint32_t /* width from decompiler */ *)(*param_3 + 0xbc + iVar3) = local_dc;

          wcscpy((wchar_t *)(*param_3 + 0x1c + iVar3),local_74);

          wcscpy((wchar_t *)(*param_3 + 0xc4 + iVar3),local_b8);

          iVar3 = iVar3 + 300;

          *(uint *)(*param_3 + -0x6c + iVar3) = (uint)(local_128 == -1);

          iVar5 = FUN_0041c000();

        } while (iVar5 == 0);

      }

      if (local_168 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    local_d4 = SysAllocString(L"//vPrefixPowerPlant/row");

    if (local_d4 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_148 = &stack0xfffffe6c;

    local_4 = 1;

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4 = CONCAT31(local_4._1_3_,4);

    if (local_14c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    pIVar2 = local_14c;

    local_148 = (uint8_t *)0x0;

    UVar6 = (*local_14c->lpVtbl[2].Release)(local_14c);

    if ((int)UVar6 < 0) {

      _com_issue_errorex(UVar6,pIVar2,(_GUID *)&DAT_00a86118);

    }

    pIVar2 = local_14c;

    *unaff_retaddr = local_14c;

    pvVar4 = CoTaskMemAlloc((int)local_14c * 300);

    *param_3 = (int)pvVar4;

    local_140 = 0;

    piVar7 = unaff_EBX;

    if (0 < (int)pIVar2) {

      do {

        iVar3 = local_140;

        if (local_150 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        piVar1 = local_150;

        if (piVar7 != (int *)0x0) {

          (**(code **)(*piVar7 + 8))();

        }

        piVar7 = (int *)0x0;

        (**(code **)(*piVar1 + 0x1c))();

        unaff_EBX = (int *)0x0;

        local_140 = iVar3 + 1;

      } while (local_140 < (int)local_14c);

    }

    puStack_8._0_1_ = 3;

    if (unaff_EBX != (int *)0x0) {

      (**(code **)(*unaff_EBX + 8))();

    }

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

    if (local_150 != (int *)0x0) {

      (**(code **)(*local_150 + 8))();

    }

    SysFreeString(local_d8);

  }

  ExceptionList = pvStack_10;

  return 0;

}
