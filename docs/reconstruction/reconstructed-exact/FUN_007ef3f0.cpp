// =============================================================================
// FUN_007ef3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ef3f0
// Address:   0x007ef3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ef3f0 @ 0x007ef3f0
// Stable ID: aa_007ef3f0
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~172 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: block×25, FUN_004231d0×11, FUN_0041a3e0×3, FUN_00423170×3, _com_issue_error×3, CONCAT31×2, FUN_0041a990×2, FUN_007a4480×2.
//  - Strings: "DBReader: %u against %s".
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x007efad2) */

/* WARNING: Removing unreachable block (ram,0x007efa66) */

/* WARNING: Removing unreachable block (ram,0x007ef9fa) */

/* WARNING: Removing unreachable block (ram,0x007ef98e) */

/* WARNING: Removing unreachable block (ram,0x007ef922) */

/* WARNING: Removing unreachable block (ram,0x007ef8b0) */

/* WARNING: Removing unreachable block (ram,0x007ef868) */

/* WARNING: Removing unreachable block (ram,0x007ef88a) */

/* WARNING: Removing unreachable block (ram,0x007ef8b6) */

/* WARNING: Removing unreachable block (ram,0x007ef8ec) */

/* WARNING: Removing unreachable block (ram,0x007ef8f2) */

/* WARNING: Removing unreachable block (ram,0x007ef928) */

/* WARNING: Removing unreachable block (ram,0x007ef958) */

/* WARNING: Removing unreachable block (ram,0x007ef95e) */

/* WARNING: Removing unreachable block (ram,0x007ef994) */

/* WARNING: Removing unreachable block (ram,0x007ef9c4) */

/* WARNING: Removing unreachable block (ram,0x007ef9ca) */

/* WARNING: Removing unreachable block (ram,0x007efa00) */

/* WARNING: Removing unreachable block (ram,0x007efa30) */

/* WARNING: Removing unreachable block (ram,0x007efa36) */

/* WARNING: Removing unreachable block (ram,0x007efa6c) */

/* WARNING: Removing unreachable block (ram,0x007efa9c) */

/* WARNING: Removing unreachable block (ram,0x007efaa2) */

/* WARNING: Removing unreachable block (ram,0x007efad8) */

/* WARNING: Removing unreachable block (ram,0x007efaf5) */



int __thiscall FUN_007ef3f0(char *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uStack_90;

  uint8_t uStack_8a;

  uint8_t uStack_89;

  int *piStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ *puStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  int iStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ *puStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  BSTR pOStack_58;

  int iStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  wchar_t awStack_34 [20];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b0e9f;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    iVar1 = -0x7fffbffc;

  }

  else {

    ExceptionList = &local_c;

    iVar1 = FUN_007e59d0();

    if (-1 < iVar1) {

      iStack_54 = *param_2;

      if (DAT_00d1793c == '\0') {

        puStack_6c = &uStack_84;

        uStack_50 = 0xffffffff;

        uStack_84 = 0;

        uStack_80 = 0;

        puStack_7c = (uint32_t /* width from decompiler */ *)0x0;

        uStack_78 = 0;

        iStack_74 = 0;

        uStack_70 = 0;

        uStack_64 = 0;

        uStack_68 = 0;

        uStack_60 = 0;

        uStack_5c = 0;

        uStack_4 = 0;

        FUN_004230d0();

        iVar1 = FUN_00422fb0(1);

        if (-1 < iVar1) {

          iVar1 = FUN_0041a810(&uStack_84,param_1 + 0x28,0,0,&DAT_00a140c8);

        }

        puStack_7c = &uStack_4c;

        if (((((iVar1 < 0) || (iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0)) ||

             (iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0)) ||

            (((iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0 ||

              (iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0)) ||

             ((iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0 ||

              ((iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0 ||

               (iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0)))))))) ||

           ((iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0 ||

            ((((iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0 ||

               (iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0)) ||

              (iVar1 = FUN_004231d0(&uStack_84), iVar1 < 0)) || (iStack_74 == 0)))))) {

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s");

          uStack_4 = 0xffffffff;

          FUN_0041a3e0();

        }

        else {

          iVar1 = FUN_0041a9b0();

          if (iVar1 == 0) {

            *param_4 = uStack_4c;

            param_4[1] = uStack_3c;

            *(uint8_t *)(param_4 + 2) = uStack_89;

            *(uint8_t *)((int)param_4 + 9) = uStack_8a;

            param_4[3] = uStack_38;

            param_4[4] = uStack_50;

            *(uint8_t *)(param_4 + 5) = 0;

            param_4[6] = uStack_44;

            param_4[7] = uStack_40;

            param_4[8] = uStack_48;

            param_4[9] = uStack_90;

            FUN_0041a990();

            FUN_00423170();

            uStack_4 = 0xffffffff;

            FUN_0041a3e0();

          }

          else {

            FUN_0041a990();

            FUN_00423170();

            FUN_007a4480(1,"DBReader: %u against %s");

            uStack_4 = 0xffffffff;

            FUN_0041a3e0();

          }

        }

      }

      else {

        FUN_00423670();

        uStack_4 = 1;

        _itow(iStack_54,awStack_34,10);

        FUN_00422eb0();

        lstrlenW(L"\']");

        iVar1 = FUN_00422ee0();

        if (iVar1 < 0) {

                    /* WARNING: Subroutine does not return */

          FUN_004048e0();

        }

        FUN_00419ca0();

        uStack_4._0_1_ = 2;

        if (DAT_00d1e56c == 0) {

          _com_issue_error(-0x7fffbffd);

        }

        uStack_4._0_1_ = 1;

        FUN_00419ed0();

        uStack_4 = CONCAT31(uStack_4._1_3_,4);

        if (piStack_88 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        iVar1 = FUN_00419ff0();

        if (0 < iVar1) {

          if (piStack_88 == (int *)0x0) {

            _com_issue_error(-0x7fffbffd);

          }

          (**(code **)(*piStack_88 + 0x1c))(piStack_88);

        }

        uStack_4 = CONCAT31(uStack_4._1_3_,1);

        if (piStack_88 != (int *)0x0) {

          (**(code **)(*piStack_88 + 8))();

        }

        SysFreeString(pOStack_58);

      }

      iVar1 = 0;

    }

  }

  ExceptionList = local_c;

  return iVar1;

}
