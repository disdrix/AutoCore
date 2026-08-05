// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_007cd9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007cd9a0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x007cd9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper. Evidence string: "DBReader: %u against %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DBReader: %u against %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~160 non-empty decompiler lines.
//  - Control keywords: if×9, return×3.
//  - Notable callees: block×29, FUN_004231d0×13, FUN_0041a3e0×2, FUN_00423170×2, _com_issue_error×2, CONCAT31, FUN_004048e0, FUN_00419ca0.
//  - Strings: "DBReader: %u against %s"; "//tLootConfig/row".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

/* WARNING: Removing unreachable block (ram,0x007ce0c5) */

/* WARNING: Removing unreachable block (ram,0x007ce055) */

/* WARNING: Removing unreachable block (ram,0x007cdfe5) */

/* WARNING: Removing unreachable block (ram,0x007cdf75) */

/* WARNING: Removing unreachable block (ram,0x007cdf05) */

/* WARNING: Removing unreachable block (ram,0x007cde96) */

/* WARNING: Removing unreachable block (ram,0x007cde21) */

/* WARNING: Removing unreachable block (ram,0x007cddd9) */

/* WARNING: Removing unreachable block (ram,0x007cddfb) */

/* WARNING: Removing unreachable block (ram,0x007cde27) */

/* WARNING: Removing unreachable block (ram,0x007cde5f) */

/* WARNING: Removing unreachable block (ram,0x007cde65) */

/* WARNING: Removing unreachable block (ram,0x007cde9c) */

/* WARNING: Removing unreachable block (ram,0x007cdecd) */

/* WARNING: Removing unreachable block (ram,0x007cded3) */

/* WARNING: Removing unreachable block (ram,0x007cdf0b) */

/* WARNING: Removing unreachable block (ram,0x007cdf3d) */

/* WARNING: Removing unreachable block (ram,0x007cdf43) */

/* WARNING: Removing unreachable block (ram,0x007cdf7b) */

/* WARNING: Removing unreachable block (ram,0x007cdfad) */

/* WARNING: Removing unreachable block (ram,0x007cdfb3) */

/* WARNING: Removing unreachable block (ram,0x007cdfeb) */

/* WARNING: Removing unreachable block (ram,0x007ce01d) */

/* WARNING: Removing unreachable block (ram,0x007ce023) */

/* WARNING: Removing unreachable block (ram,0x007ce05b) */

/* WARNING: Removing unreachable block (ram,0x007ce08d) */

/* WARNING: Removing unreachable block (ram,0x007ce093) */

/* WARNING: Removing unreachable block (ram,0x007ce0cb) */

/* WARNING: Removing unreachable block (ram,0x007ce0e8) */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_007cd9a0(char *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  BSTR bstrString;

  uint16_t local_7c;

  uint16_t local_78;

  int *local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  BSTR local_40;

  uint8_t *local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ *local_30;

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

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae7fd;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_20 = &local_38;

    local_38 = 0;

    local_34 = 0;

    local_30 = (uint32_t /* width from decompiler */ *)0x0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_18 = 0;

    local_1c = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    ExceptionList = &local_c;

    iVar1 = FUN_0041a810(local_20,param_1 + 0x28,0,0,&DAT_00a140c8);

    local_30 = &local_6c;

    if (((((iVar1 < 0) || (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

         (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

        (((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||

          (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

         ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||

          ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||

           (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)))))))) ||

       ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||

        (((((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||

            (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

           (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

          ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||

           (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)))) || (local_28 == 0)))))) {

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s");

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      iVar1 = FUN_0041c000();

      if (iVar1 == 0) {

        *param_2 = local_6c;

        param_2[2] = local_68;

        param_2[3] = local_64;

        param_2[4] = local_60;

        param_2[5] = local_5c;

        param_2[6] = local_58;

        param_2[7] = local_54;

        param_2[8] = local_50;

        param_2[9] = local_4c;

        param_2[10] = local_48;

        *(uint16_t *)(param_2 + 1) = local_7c;

        *(uint16_t *)((int)param_2 + 6) = local_78;

        param_2[0xb] = local_44;

      }

      if (local_28 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_4 = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    ExceptionList = &local_c;

    bstrString = SysAllocString(L"//tLootConfig/row");

    local_40 = bstrString;

    if (bstrString == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_3c = &stack0xffffff70;

    local_4 = 1;

    FUN_00419ca0();

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0();

    local_4._0_1_ = 4;

    if (local_70 == (int *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    (**(code **)(*local_70 + 0x1c))(local_70);

    local_4 = CONCAT31(local_4._1_3_,1);

    if (local_70 != (int *)0x0) {

      (**(code **)(*local_70 + 8))();

    }

    SysFreeString(bstrString);

  }

  ExceptionList = local_c;

  return 0;

}
