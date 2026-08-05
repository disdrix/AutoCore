// =============================================================================
// FUN_007edf30
// -----------------------------------------------------------------------------
// Stable ID: aa_007edf30
// Address:   0x007edf30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007edf30 @ 0x007edf30
// Stable ID: aa_007edf30
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: block×7, FUN_0041a3e0×3, FUN_00423170×3, _com_issue_error×3, CONCAT31×2, FUN_0041a990×2, FUN_004231d0×2, FUN_007a4480×2.
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

/* WARNING: Removing unreachable block (ram,0x007ee2d9) */

/* WARNING: Removing unreachable block (ram,0x007ee265) */

/* WARNING: Removing unreachable block (ram,0x007ee23a) */

/* WARNING: Removing unreachable block (ram,0x007ee291) */

/* WARNING: Removing unreachable block (ram,0x007ee297) */

/* WARNING: Removing unreachable block (ram,0x007ee2df) */

/* WARNING: Removing unreachable block (ram,0x007ee2fa) */



int __thiscall FUN_007edf30(char *param_1,int *param_2)



{

  int iVar1;

  BSTR unaff_EBX;

  int iStack_70;

  uint8_t *puStack_6c;

  wchar_t awStack_68 [20];

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  int *piStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  int iStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ *puStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  int *piStack_4;

  

  piStack_4 = (int *)0xffffffff;

  puStack_8 = &LAB_009b0e1c;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return -0x7fffbffc;

  }

  ExceptionList = &local_c;

  iVar1 = FUN_007e59d0();

  if (-1 < iVar1) {

    iVar1 = *param_2;

    if (DAT_00d1793c == '\0') {

      puStack_28 = &uStack_40;

      uStack_40 = 0;

      uStack_3c = 0;

      piStack_38 = (int *)0x0;

      uStack_34 = 0;

      iStack_30 = 0;

      uStack_2c = 0;

      uStack_20 = 0;

      uStack_24 = 0;

      uStack_1c = 0;

      uStack_18 = 0;

      local_c = (void *)0x0;

      FUN_004230d0();

      iVar1 = FUN_00422fb0(1);

      if (-1 < iVar1) {

        iVar1 = FUN_0041a810(&uStack_40,param_1 + 0x28,0,0,&DAT_00a140c8);

      }

      piStack_38 = &iStack_70;

      if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0)) ||

          (iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0)) || (iStack_30 == 0)) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s");

        local_c = (void *)0xffffffff;

        FUN_0041a3e0();

      }

      else {

        iVar1 = FUN_0041a9b0();

        if (iVar1 == 0) {

          *param_2 = iStack_70;

          param_2[1] = (int)puStack_6c;

          FUN_0041a990();

          FUN_00423170();

          local_c = (void *)0xffffffff;

          FUN_0041a3e0();

        }

        else {

          FUN_0041a990();

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s");

          local_c = (void *)0xffffffff;

          FUN_0041a3e0();

        }

      }

    }

    else {

      FUN_00423670();

      local_c = (void *)0x1;

      _itow(iVar1,awStack_68,10);

      FUN_00422eb0();

      lstrlenW(L"\']");

      iVar1 = FUN_00422ee0();

      if (iVar1 < 0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

      puStack_6c = &stack0xffffff74;

      FUN_00419ca0();

      local_c._0_1_ = 2;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_c._0_1_ = 1;

      FUN_00419ed0();

      local_c = (void *)CONCAT31(local_c._1_3_,4);

      if (piStack_4 == (int *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      iVar1 = FUN_00419ff0();

      if (0 < iVar1) {

        if (piStack_4 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        (**(code **)(*piStack_4 + 0x1c))(piStack_4);

      }

      local_c = (void *)CONCAT31(local_c._1_3_,1);

      if (piStack_4 != (int *)0x0) {

        (**(code **)(*piStack_4 + 8))();

      }

      SysFreeString(unaff_EBX);

    }

    iVar1 = 0;

  }

  ExceptionList = pvStack_14;

  return iVar1;

}
