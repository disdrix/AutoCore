// =============================================================================
// FUN_007ca4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ca4e0
// Address:   0x007ca4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ca4e0 @ 0x007ca4e0
// Stable ID: aa_007ca4e0
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "//tLootTable/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~406 non-empty decompiler lines.
//  - Control keywords: if×15, return×4, while×2, for×1, do×1.
//  - Notable callees: block×138, FUN_004231d0×44, _com_issue_error×3, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, CONCAT31, FUN_004048e0.
//  - Strings: "DBReader: %u against %s"; "//tLootTable/row".
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

/* WARNING: Removing unreachable block (ram,0x007cbae1) */

/* WARNING: Removing unreachable block (ram,0x007cba63) */

/* WARNING: Removing unreachable block (ram,0x007cb9e5) */

/* WARNING: Removing unreachable block (ram,0x007cb967) */

/* WARNING: Removing unreachable block (ram,0x007cb8e9) */

/* WARNING: Removing unreachable block (ram,0x007cb843) */

/* WARNING: Removing unreachable block (ram,0x007cb7c7) */

/* WARNING: Removing unreachable block (ram,0x007cb74b) */

/* WARNING: Removing unreachable block (ram,0x007cb6cf) */

/* WARNING: Removing unreachable block (ram,0x007cb653) */

/* WARNING: Removing unreachable block (ram,0x007cb5d9) */

/* WARNING: Removing unreachable block (ram,0x007cb55c) */

/* WARNING: Removing unreachable block (ram,0x007cb4e0) */

/* WARNING: Removing unreachable block (ram,0x007cb464) */

/* WARNING: Removing unreachable block (ram,0x007cb3e8) */

/* WARNING: Removing unreachable block (ram,0x007cb36c) */

/* WARNING: Removing unreachable block (ram,0x007cb2f0) */

/* WARNING: Removing unreachable block (ram,0x007cb274) */

/* WARNING: Removing unreachable block (ram,0x007cb1f7) */

/* WARNING: Removing unreachable block (ram,0x007cb17a) */

/* WARNING: Removing unreachable block (ram,0x007cb0fc) */

/* WARNING: Removing unreachable block (ram,0x007cb082) */

/* WARNING: Removing unreachable block (ram,0x007cb033) */

/* WARNING: Removing unreachable block (ram,0x007cb053) */

/* WARNING: Removing unreachable block (ram,0x007cb046) */

/* WARNING: Removing unreachable block (ram,0x007cb04f) */

/* WARNING: Removing unreachable block (ram,0x007cb051) */

/* WARNING: Removing unreachable block (ram,0x007cb055) */

/* WARNING: Removing unreachable block (ram,0x007cb06d) */

/* WARNING: Removing unreachable block (ram,0x007cb088) */

/* WARNING: Removing unreachable block (ram,0x007cb0a9) */

/* WARNING: Removing unreachable block (ram,0x007cb0be) */

/* WARNING: Removing unreachable block (ram,0x007cb0c4) */

/* WARNING: Removing unreachable block (ram,0x007cb0e7) */

/* WARNING: Removing unreachable block (ram,0x007cb102) */

/* WARNING: Removing unreachable block (ram,0x007cb126) */

/* WARNING: Removing unreachable block (ram,0x007cb13b) */

/* WARNING: Removing unreachable block (ram,0x007cb141) */

/* WARNING: Removing unreachable block (ram,0x007cb165) */

/* WARNING: Removing unreachable block (ram,0x007cb180) */

/* WARNING: Removing unreachable block (ram,0x007cb1a4) */

/* WARNING: Removing unreachable block (ram,0x007cb1b9) */

/* WARNING: Removing unreachable block (ram,0x007cb1bf) */

/* WARNING: Removing unreachable block (ram,0x007cb1e2) */

/* WARNING: Removing unreachable block (ram,0x007cb1fd) */

/* WARNING: Removing unreachable block (ram,0x007cb220) */

/* WARNING: Removing unreachable block (ram,0x007cb235) */

/* WARNING: Removing unreachable block (ram,0x007cb23b) */

/* WARNING: Removing unreachable block (ram,0x007cb25f) */

/* WARNING: Removing unreachable block (ram,0x007cb27a) */

/* WARNING: Removing unreachable block (ram,0x007cb29d) */

/* WARNING: Removing unreachable block (ram,0x007cb2b2) */

/* WARNING: Removing unreachable block (ram,0x007cb2b8) */

/* WARNING: Removing unreachable block (ram,0x007cb2db) */

/* WARNING: Removing unreachable block (ram,0x007cb2f6) */

/* WARNING: Removing unreachable block (ram,0x007cb319) */

/* WARNING: Removing unreachable block (ram,0x007cb32e) */

/* WARNING: Removing unreachable block (ram,0x007cb334) */

/* WARNING: Removing unreachable block (ram,0x007cb357) */

/* WARNING: Removing unreachable block (ram,0x007cb372) */

/* WARNING: Removing unreachable block (ram,0x007cb395) */

/* WARNING: Removing unreachable block (ram,0x007cb3aa) */

/* WARNING: Removing unreachable block (ram,0x007cb3b0) */

/* WARNING: Removing unreachable block (ram,0x007cb3d3) */

/* WARNING: Removing unreachable block (ram,0x007cb3ee) */

/* WARNING: Removing unreachable block (ram,0x007cb411) */

/* WARNING: Removing unreachable block (ram,0x007cb426) */

/* WARNING: Removing unreachable block (ram,0x007cb42c) */

/* WARNING: Removing unreachable block (ram,0x007cb44f) */

/* WARNING: Removing unreachable block (ram,0x007cb46a) */

/* WARNING: Removing unreachable block (ram,0x007cb48d) */

/* WARNING: Removing unreachable block (ram,0x007cb4a2) */

/* WARNING: Removing unreachable block (ram,0x007cb4a8) */

/* WARNING: Removing unreachable block (ram,0x007cb4cb) */

/* WARNING: Removing unreachable block (ram,0x007cb4e6) */

/* WARNING: Removing unreachable block (ram,0x007cb509) */

/* WARNING: Removing unreachable block (ram,0x007cb51e) */

/* WARNING: Removing unreachable block (ram,0x007cb524) */

/* WARNING: Removing unreachable block (ram,0x007cb547) */

/* WARNING: Removing unreachable block (ram,0x007cb562) */

/* WARNING: Removing unreachable block (ram,0x007cb585) */

/* WARNING: Removing unreachable block (ram,0x007cb59a) */

/* WARNING: Removing unreachable block (ram,0x007cb5a0) */

/* WARNING: Removing unreachable block (ram,0x007cb5c4) */

/* WARNING: Removing unreachable block (ram,0x007cb5df) */

/* WARNING: Removing unreachable block (ram,0x007cb601) */

/* WARNING: Removing unreachable block (ram,0x007cb616) */

/* WARNING: Removing unreachable block (ram,0x007cb61c) */

/* WARNING: Removing unreachable block (ram,0x007cb63e) */

/* WARNING: Removing unreachable block (ram,0x007cb659) */

/* WARNING: Removing unreachable block (ram,0x007cb67c) */

/* WARNING: Removing unreachable block (ram,0x007cb691) */

/* WARNING: Removing unreachable block (ram,0x007cb697) */

/* WARNING: Removing unreachable block (ram,0x007cb6ba) */

/* WARNING: Removing unreachable block (ram,0x007cb6d5) */

/* WARNING: Removing unreachable block (ram,0x007cb6f8) */

/* WARNING: Removing unreachable block (ram,0x007cb70d) */

/* WARNING: Removing unreachable block (ram,0x007cb713) */

/* WARNING: Removing unreachable block (ram,0x007cb736) */

/* WARNING: Removing unreachable block (ram,0x007cb751) */

/* WARNING: Removing unreachable block (ram,0x007cb774) */

/* WARNING: Removing unreachable block (ram,0x007cb789) */

/* WARNING: Removing unreachable block (ram,0x007cb78f) */

/* WARNING: Removing unreachable block (ram,0x007cb7b2) */

/* WARNING: Removing unreachable block (ram,0x007cb7cd) */

/* WARNING: Removing unreachable block (ram,0x007cb7f0) */

/* WARNING: Removing unreachable block (ram,0x007cb805) */

/* WARNING: Removing unreachable block (ram,0x007cb80b) */

/* WARNING: Removing unreachable block (ram,0x007cb82e) */

/* WARNING: Removing unreachable block (ram,0x007cb849) */

/* WARNING: Removing unreachable block (ram,0x007cb895) */

/* WARNING: Removing unreachable block (ram,0x007cb8aa) */

/* WARNING: Removing unreachable block (ram,0x007cb8b0) */

/* WARNING: Removing unreachable block (ram,0x007cb8d4) */

/* WARNING: Removing unreachable block (ram,0x007cb8ef) */

/* WARNING: Removing unreachable block (ram,0x007cb913) */

/* WARNING: Removing unreachable block (ram,0x007cb928) */

/* WARNING: Removing unreachable block (ram,0x007cb92e) */

/* WARNING: Removing unreachable block (ram,0x007cb952) */

/* WARNING: Removing unreachable block (ram,0x007cb96d) */

/* WARNING: Removing unreachable block (ram,0x007cb991) */

/* WARNING: Removing unreachable block (ram,0x007cb9a6) */

/* WARNING: Removing unreachable block (ram,0x007cb9ac) */

/* WARNING: Removing unreachable block (ram,0x007cb9d0) */

/* WARNING: Removing unreachable block (ram,0x007cb9eb) */

/* WARNING: Removing unreachable block (ram,0x007cba0f) */

/* WARNING: Removing unreachable block (ram,0x007cba24) */

/* WARNING: Removing unreachable block (ram,0x007cba2a) */

/* WARNING: Removing unreachable block (ram,0x007cba4e) */

/* WARNING: Removing unreachable block (ram,0x007cba69) */

/* WARNING: Removing unreachable block (ram,0x007cba8d) */

/* WARNING: Removing unreachable block (ram,0x007cbaa2) */

/* WARNING: Removing unreachable block (ram,0x007cbaa8) */

/* WARNING: Removing unreachable block (ram,0x007cbacc) */

/* WARNING: Removing unreachable block (ram,0x007cbae7) */

/* WARNING: Removing unreachable block (ram,0x007cbb0b) */

/* WARNING: Removing unreachable block (ram,0x007cbb20) */

/* WARNING: Removing unreachable block (ram,0x007cbb26) */



uint32_t /* width from decompiler */ __fastcall FUN_007ca4e0(char *param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  IUnknown *This;

  ULONG UVar4;

  int *piVar5;

  int *local_108;

  uint32_t /* width from decompiler */ local_100;

  uint32_t /* width from decompiler */ local_fc;

  int *local_f8;

  uint32_t /* width from decompiler */ local_f4;

  int local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ *local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  IUnknown *local_d4;

  int *local_d0;

  uint8_t *local_cc;

  int local_c8;

  uint16_t local_c4;

  uint16_t local_c0;

  uint16_t local_bc;

  int local_b8;

  uint16_t local_b4;

  int local_b0;

  uint16_t local_ac;

  uint16_t local_a8;

  uint16_t local_a4;

  uint16_t local_a0;

  uint16_t local_9c;

  uint16_t local_98;

  uint16_t local_94;

  uint16_t local_90;

  uint16_t local_8c;

  uint16_t local_88;

  int local_84;

  uint16_t local_80;

  int local_7c;

  int local_78;

  int local_74;

  int local_70;

  int local_6c;

  uint16_t local_68;

  int local_64;

  uint16_t local_60;

  int local_5c;

  uint16_t local_58;

  int local_54;

  uint16_t local_50;

  int local_4c;

  uint16_t local_48;

  int local_44;

  uint16_t local_40;

  int local_3c;

  uint16_t local_38;

  int local_34;

  uint16_t local_30;

  BSTR local_2c;

  BSTR local_28;

  int local_24;

  int local_20;

  uint32_t /* width from decompiler */ local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae654;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    ExceptionList = puStack_8;

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_e8 = &local_100;

    local_100 = 0;

    local_fc = 0;

    local_f8 = (int *)0x0;

    local_f4 = 0;

    local_f0 = 0;

    local_ec = 0;

    local_e0 = 0;

    local_e4 = 0;

    local_dc = 0;

    local_d8 = 0;

    local_4 = 0;

    ExceptionList = &local_c;

    iVar1 = FUN_0041a810(local_e8,param_1 + 0x28,0,0,&DAT_00a140c8,0);

    local_f8 = &local_c8;

    if ((((((((-1 < iVar1) && (iVar1 = FUN_004231d0(&local_100,1), -1 < iVar1)) &&

            (iVar1 = FUN_004231d0(&local_100,2), -1 < iVar1)) &&

           ((iVar1 = FUN_004231d0(&local_100,3), -1 < iVar1 &&

            (iVar1 = FUN_004231d0(&local_100,4), -1 < iVar1)))) &&

          ((iVar1 = FUN_004231d0(&local_100,5), -1 < iVar1 &&

           ((iVar1 = FUN_004231d0(&local_100,6), -1 < iVar1 &&

            (iVar1 = FUN_004231d0(&local_100,7), -1 < iVar1)))))) &&

         (iVar1 = FUN_004231d0(&local_100,8), -1 < iVar1)) &&

        ((((iVar1 = FUN_004231d0(&local_100,9), -1 < iVar1 &&

           (iVar1 = FUN_004231d0(&local_100,10), -1 < iVar1)) &&

          (iVar1 = FUN_004231d0(&local_100,0xb), -1 < iVar1)) &&

         (((iVar1 = FUN_004231d0(&local_100,0xc), -1 < iVar1 &&

           (iVar1 = FUN_004231d0(&local_100,0xd), -1 < iVar1)) &&

          ((iVar1 = FUN_004231d0(&local_100,0xe), -1 < iVar1 &&

           ((iVar1 = FUN_004231d0(&local_100,0xf), -1 < iVar1 &&

            (iVar1 = FUN_004231d0(&local_100,0x10), -1 < iVar1)))))))))) &&

       ((((iVar1 = FUN_004231d0(&local_100,0x11), -1 < iVar1 &&

          (((iVar1 = FUN_004231d0(&local_100,0x12), -1 < iVar1 &&

            (iVar1 = FUN_004231d0(&local_100,0x13), -1 < iVar1)) &&

           (iVar1 = FUN_004231d0(&local_100,0x14), -1 < iVar1)))) &&

         (((iVar1 = FUN_004231d0(&local_100,0x15), -1 < iVar1 &&

           (iVar1 = FUN_004231d0(&local_100,0x16), -1 < iVar1)) &&

          (((iVar1 = FUN_004231d0(&local_100,0x17), -1 < iVar1 &&

            ((iVar1 = FUN_004231d0(&local_100,0x18), -1 < iVar1 &&

             (iVar1 = FUN_004231d0(&local_100,0x19), -1 < iVar1)))) &&

           (iVar1 = FUN_004231d0(&local_100,0x1a), -1 < iVar1)))))) &&

        (((((((iVar1 = FUN_004231d0(&local_100,0x1b), -1 < iVar1 &&

              (iVar1 = FUN_004231d0(&local_100,0x1c), -1 < iVar1)) &&

             (iVar1 = FUN_004231d0(&local_100,0x1d), -1 < iVar1)) &&

            ((iVar1 = FUN_004231d0(&local_100,0x1e), -1 < iVar1 &&

             (iVar1 = FUN_004231d0(&local_100,0x1f), -1 < iVar1)))) &&

           (iVar1 = FUN_004231d0(&local_100,0x20), -1 < iVar1)) &&

          (((((iVar1 = FUN_004231d0(&local_100,0x21), -1 < iVar1 &&

              (iVar1 = FUN_004231d0(&local_100,0x22), -1 < iVar1)) &&

             ((iVar1 = FUN_004231d0(&local_100,0x23), -1 < iVar1 &&

              (((iVar1 = FUN_004231d0(&local_100,0x24), -1 < iVar1 &&

                (iVar1 = FUN_004231d0(&local_100,0x25), -1 < iVar1)) &&

               (iVar1 = FUN_004231d0(&local_100,0x26), -1 < iVar1)))))) &&

            ((iVar1 = FUN_004231d0(&local_100,0x27), -1 < iVar1 &&

             (iVar1 = FUN_004231d0(&local_100,0x28), -1 < iVar1)))) &&

           (iVar1 = FUN_004231d0(&local_100,0x29), -1 < iVar1)))) &&

         (((iVar1 = FUN_004231d0(&local_100,0x2a), -1 < iVar1 &&

           (iVar1 = FUN_004231d0(&local_100,0x2b), -1 < iVar1)) &&

          (iVar1 = FUN_004231d0(&local_100,0x2c), -1 < iVar1)))))))) {

      if (local_f0 != 0) {

        iVar1 = FUN_0041c000(0);

        while (iVar1 == 0) {

          piVar2 = operator_new(0x84);

          piVar3 = (int *)0x0;

          if (piVar2 != (int *)0x0) {

            piVar5 = piVar2;

            for (iVar1 = 0x21; piVar3 = piVar2, iVar1 != 0; iVar1 = iVar1 + -1) {

              *piVar5 = 0;

              piVar5 = piVar5 + 1;

            }

          }

          *piVar3 = local_c8;

          *(uint16_t *)(piVar3 + 1) = local_c4;

          piVar3[2] = local_78;

          piVar3[3] = local_24;

          piVar3[4] = local_10;

          *(uint16_t *)(piVar3 + 5) = local_bc;

          *(uint16_t *)((int)piVar3 + 0x16) = local_c0;

          piVar3[6] = local_b0;

          *(uint16_t *)(piVar3 + 7) = local_60;

          *(uint16_t *)((int)piVar3 + 0x1e) = local_a8;

          *(uint16_t *)(piVar3 + 8) = local_38;

          *(uint16_t *)((int)piVar3 + 0x22) = local_a0;

          *(uint16_t *)((int)piVar3 + 0x2a) = local_58;

          *(uint16_t *)(piVar3 + 0xb) = local_98;

          *(uint16_t *)((int)piVar3 + 0x2e) = (uint16_t)local_14;

          *(uint16_t *)(piVar3 + 0xc) = local_90;

          *(uint16_t *)((int)piVar3 + 0x26) = local_50;

          *(uint16_t *)(piVar3 + 10) = local_88;

          *(uint16_t *)(piVar3 + 9) = local_30;

          *(uint16_t *)((int)piVar3 + 0x32) = local_80;

          *(uint16_t *)(piVar3 + 0xd) = local_48;

          piVar3[0xe] = local_b8;

          piVar3[0xf] = local_20;

          piVar3[0x10] = local_70;

          *(uint16_t *)(piVar3 + 0x11) = local_40;

          *(uint16_t *)((int)piVar3 + 0x46) = local_68;

          *(uint16_t *)(piVar3 + 0x12) = local_28._0_2_;

          *(uint16_t *)((int)piVar3 + 0x4a) = local_b4;

          *(uint16_t *)(piVar3 + 0x13) = local_ac;

          *(uint16_t *)((int)piVar3 + 0x4e) = local_a4;

          *(uint16_t *)(piVar3 + 0x14) = local_9c;

          *(uint16_t *)((int)piVar3 + 0x52) = local_94;

          *(uint16_t *)(piVar3 + 0x15) = local_8c;

          piVar3[0x16] = local_84;

          piVar3[0x17] = local_7c;

          piVar3[0x18] = local_74;

          piVar3[0x19] = local_6c;

          piVar3[0x1a] = local_64;

          piVar3[0x1b] = local_5c;

          piVar3[0x1c] = local_54;

          piVar3[0x1d] = local_4c;

          piVar3[0x1e] = local_44;

          piVar3[0x1f] = local_3c;

          piVar3[0x20] = local_34;

          FUN_0041b360();

          iVar1 = FUN_0041c000(0);

        }

        if (local_f0 != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        local_4 = 0xffffffff;

        FUN_0041a3e0();

        ExceptionList = puStack_8;

        return 0;

      }

      iVar1 = -0x7fffbffb;

    }

    FUN_00423170();

    FUN_007a4480(1,"DBReader: %u against %s",iVar1);

    local_4 = 0xffffffff;

    FUN_0041a3e0();

  }

  else {

    ExceptionList = &local_c;

    local_2c = SysAllocString(L"//tLootTable/row");

    if (local_2c == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_cc = &stack0xfffffee0;

    local_4 = 1;

    FUN_00419ca0(&stack0xfffffee0);

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0(&local_d4);

    local_4 = CONCAT31(local_4._1_3_,4);

    This = local_d4;

    if (local_d4 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

      This = local_d4;

    }

    local_d0 = (int *)0x0;

    UVar4 = (*This->lpVtbl[2].Release)(This);

    if ((int)UVar4 < 0) {

      _com_issue_errorex(UVar4,This,(_GUID *)&DAT_00a86118);

    }

    local_c8 = 0;

    if (0 < (int)local_cc) {

      do {

        iVar1 = local_c8;

        if (local_d0 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        piVar3 = local_d0;

        if (local_108 != (int *)0x0) {

          (**(code **)(*local_108 + 8))();

        }

        local_108 = (int *)0x0;

        (**(code **)(*piVar3 + 0x1c))(piVar3);

        local_c8 = iVar1 + 1;

      } while (local_c8 < (int)local_cc);

    }

    if (local_108 != (int *)0x0) {

      (**(code **)(*local_108 + 8))();

    }

    if (local_d0 != (int *)0x0) {

      (**(code **)(*local_d0 + 8))();

    }

    SysFreeString(local_28);

  }

  ExceptionList = puStack_8;

  return 0;

}
