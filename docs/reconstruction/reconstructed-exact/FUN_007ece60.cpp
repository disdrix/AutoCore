// =============================================================================
// FUN_007ece60
// -----------------------------------------------------------------------------
// Stable ID: aa_007ece60
// Address:   0x007ece60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ece60 @ 0x007ece60
// Stable ID: aa_007ece60
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~142 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: block×13, FUN_004231d0×5, FUN_0041a3e0×3, FUN_00423170×3, _com_issue_error×3, CONCAT31×2, FUN_0041a990×2, FUN_007a4480×2.
//  - Strings: "DBReader: %u against %s".
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x007ed34b) */

/* WARNING: Removing unreachable block (ram,0x007ed2d1) */

/* WARNING: Removing unreachable block (ram,0x007ed252) */

/* WARNING: Removing unreachable block (ram,0x007ed204) */

/* WARNING: Removing unreachable block (ram,0x007ed226) */

/* WARNING: Removing unreachable block (ram,0x007ed258) */

/* WARNING: Removing unreachable block (ram,0x007ed295) */

/* WARNING: Removing unreachable block (ram,0x007ed29b) */

/* WARNING: Removing unreachable block (ram,0x007ed2d7) */

/* WARNING: Removing unreachable block (ram,0x007ed30e) */

/* WARNING: Removing unreachable block (ram,0x007ed314) */

/* WARNING: Removing unreachable block (ram,0x007ed351) */

/* WARNING: Removing unreachable block (ram,0x007ed373) */



int __thiscall

FUN_007ece60(char *param_1,int *param_2,uint8_t param_3,uint8_t *param_4,int *param_5)



{

  int iVar1;

  uint uVar2;

  uint16_t uStack_78;

  short sStack_74;

  int *local_6c;

  BSTR local_64;

  wchar_t local_60 [20];

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

  puStack_8 = &LAB_009b0d71;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return -0x7fffbffc;

  }

  ExceptionList = &local_c;

  iVar1 = FUN_007eaf20(param_2);

  if (-1 < iVar1) {

    iVar1 = *param_2;

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

      FUN_004230d0();

      iVar1 = FUN_00422fb0(1);

      if (-1 < iVar1) {

        iVar1 = FUN_0041a810(&local_38,param_1 + 0x28,0,0,&DAT_00a140c8);

      }

      local_30 = &param_4;

      if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

          (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

         (((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||

           (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||

          ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 || (local_28 == 0)))))) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s");

        local_4 = 0xffffffff;

        FUN_0041a3e0();

      }

      else {

        iVar1 = FUN_0041a9b0();

        if (iVar1 == 0) {

          *(uint8_t *)((int)param_5 + 10) = param_3;

          *(uint16_t *)((int)param_5 + 6) = param_2._0_2_;

          *(uint8_t *)((int)param_5 + 9) = param_4._0_1_;

          *(uint16_t *)(param_5 + 1) = uStack_78;

          uVar2 = (int)sStack_74 >> 0x1f;

          iVar1 = ((int)sStack_74 ^ uVar2) - uVar2;

          *param_5 = iVar1;

          *(char *)(param_5 + 2) = (char)iVar1;

          FUN_0041a990();

          FUN_00423170();

          local_4 = 0xffffffff;

          FUN_0041a3e0();

        }

        else {

          FUN_0041a990();

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s");

          local_4 = 0xffffffff;

          FUN_0041a3e0();

        }

      }

    }

    else {

      FUN_00423670();

      local_4 = 1;

      _itow(iVar1,local_60,10);

      FUN_00422eb0();

      lstrlenW(L"\']");

      iVar1 = FUN_00422ee0();

      if (iVar1 < 0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

      param_4 = &stack0xffffff74;

      FUN_00419ca0();

      local_4._0_1_ = 2;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_4._0_1_ = 1;

      FUN_00419ed0();

      local_4 = CONCAT31(local_4._1_3_,4);

      if (local_6c == (int *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      iVar1 = FUN_00419ff0();

      if (0 < iVar1) {

        if (local_6c == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        (**(code **)(*local_6c + 0x1c))(local_6c);

      }

      local_4 = CONCAT31(local_4._1_3_,1);

      if (local_6c != (int *)0x0) {

        (**(code **)(*local_6c + 8))();

      }

      SysFreeString(local_64);

    }

    iVar1 = 0;

  }

  ExceptionList = local_c;

  return iVar1;

}
