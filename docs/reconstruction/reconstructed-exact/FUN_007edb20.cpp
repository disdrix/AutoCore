// =============================================================================
// FUN_007edb20
// -----------------------------------------------------------------------------
// Stable ID: aa_007edb20
// Address:   0x007edb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007edb20 @ 0x007edb20
// Stable ID: aa_007edb20
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×16, return×3.
//  - Notable callees: FUN_00423670×3, _com_issue_error×3, block×3, CONCAT31×2, FUN_004231d0×2, FUN_007b8a60×2, FUN_004048e0, FUN_00419ca0.
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

/* WARNING: Removing unreachable block (ram,0x007edca1) */

/* WARNING: Removing unreachable block (ram,0x007edcf1) */

/* WARNING: Removing unreachable block (ram,0x007edcb0) */



int __thiscall FUN_007edb20(char *param_1,int *param_2)



{

  uint16_t uVar1;

  int iVar2;

  int *unaff_EBP;

  BSTR pOStack_70;

  wchar_t awStack_68 [20];

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  int *piStack_4;

  

  piStack_4 = (int *)0xffffffff;

  puStack_8 = &LAB_009b0de8;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return -0x7fffbffc;

  }

  ExceptionList = &local_c;

  iVar2 = FUN_007e59d0();

  if (-1 < iVar2) {

    iVar2 = *param_2;

    if (DAT_00d1793c == '\0') {

      uStack_40 = 0;

      uStack_3c = 0;

      local_c = (void *)0x0;

      FUN_004230d0();

      iVar2 = FUN_00422fb0(1);

      if (-1 < iVar2) {

        iVar2 = FUN_0041a810(&uStack_40,param_1 + 0x28,0,0,&DAT_00a140c8);

      }

      if ((-1 < iVar2) && (iVar2 = FUN_004231d0(&uStack_40), -1 < iVar2)) {

        FUN_004231d0(&uStack_40);

      }

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s");

      local_c = (void *)0xffffffff;

      FUN_0041a3e0();

    }

    else {

      FUN_00423670();

      local_c = (void *)0x1;

      _itow(iVar2,awStack_68,10);

      FUN_00422eb0();

      lstrlenW(L"\']");

      iVar2 = FUN_00422ee0();

      if (iVar2 < 0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

      FUN_00419ca0();

      local_c._0_1_ = 2;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_c._0_1_ = 1;

      FUN_00419ed0();

      piStack_4 = (int *)0x0;

      local_c = (void *)CONCAT31(local_c._1_3_,4);

      if (unaff_EBP == (int *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      iVar2 = FUN_00419ff0();

      if (0 < iVar2) {

        if (unaff_EBP == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        if (piStack_4 != (int *)0x0) {

          (**(code **)(*piStack_4 + 8))();

        }

        piStack_4 = (int *)0x0;

        (**(code **)(*unaff_EBP + 0x1c))(unaff_EBP);

        if (piStack_4 != (int *)0x0) {

          FUN_00423670();

          if (piStack_4 != (int *)0x0) {

            (**(code **)(*piStack_4 + 4))(piStack_4);

          }

          uVar1 = FUN_007b8a60();

          *(uint16_t *)param_2 = uVar1;

          FUN_00423670();

          if (piStack_4 != (int *)0x0) {

            (**(code **)(*piStack_4 + 4))(piStack_4);

          }

          iVar2 = FUN_007b8a60();

          param_2[1] = iVar2;

        }

      }

      local_c._0_1_ = 3;

      if (piStack_4 != (int *)0x0) {

        (**(code **)(*piStack_4 + 8))();

      }

      local_c = (void *)CONCAT31(local_c._1_3_,1);

      if (unaff_EBP != (int *)0x0) {

        (**(code **)(*unaff_EBP + 8))();

      }

      SysFreeString(pOStack_70);

    }

    iVar2 = 0;

  }

  ExceptionList = pvStack_14;

  return iVar2;

}
