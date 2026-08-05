// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007ec7e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ec7e0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x007ec7e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper. Evidence string: "DBReader: %u against %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DBReader: %u against %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~160 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: block×21, FUN_004231d0×9, FUN_00423170×3, _com_issue_error×3, CONCAT31×2, FUN_0041a3e0×2, FUN_0041a990×2, FUN_007a4480×2.
//  - Strings: "DBReader: %u against %s".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

/* WARNING: Removing unreachable block (ram,0x007ecdf8) */

/* WARNING: Removing unreachable block (ram,0x007ecd8c) */

/* WARNING: Removing unreachable block (ram,0x007ecd1e) */

/* WARNING: Removing unreachable block (ram,0x007eccb0) */

/* WARNING: Removing unreachable block (ram,0x007ecc3b) */

/* WARNING: Removing unreachable block (ram,0x007ecbf3) */

/* WARNING: Removing unreachable block (ram,0x007ecc15) */

/* WARNING: Removing unreachable block (ram,0x007ecc41) */

/* WARNING: Removing unreachable block (ram,0x007ecc79) */

/* WARNING: Removing unreachable block (ram,0x007ecc7f) */

/* WARNING: Removing unreachable block (ram,0x007eccb6) */

/* WARNING: Removing unreachable block (ram,0x007ecce7) */

/* WARNING: Removing unreachable block (ram,0x007ecced) */

/* WARNING: Removing unreachable block (ram,0x007ecd24) */

/* WARNING: Removing unreachable block (ram,0x007ecd55) */

/* WARNING: Removing unreachable block (ram,0x007ecd5b) */

/* WARNING: Removing unreachable block (ram,0x007ecd92) */

/* WARNING: Removing unreachable block (ram,0x007ecdc3) */

/* WARNING: Removing unreachable block (ram,0x007ecdc9) */

/* WARNING: Removing unreachable block (ram,0x007ecdfe) */

/* WARNING: Removing unreachable block (ram,0x007ece1a) */



int __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007ec7e0(char *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uStack_90;

  uint16_t auStack_8c [2];

  int *piStack_88;

  uint16_t uStack_84;

  uint16_t uStack_80;

  int iStack_7c;

  uint16_t uStack_78;

  BSTR pOStack_74;

  uint16_t uStack_70;

  uint16_t uStack_6c;

  uint16_t uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint16_t *puStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  int iStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ *puStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint16_t uStack_38;

  wchar_t awStack_34 [20];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b0d3d;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    iVar1 = -0x7fffbffc;

  }

  else {

    ExceptionList = &local_c;

    iVar1 = FUN_007e59d0();

    if (-1 < iVar1) {

      iStack_7c = *param_2;

      if (DAT_00d1793c == '\0') {

        puStack_4c = &uStack_64;

        uStack_64 = 0;

        uStack_60 = 0;

        puStack_5c = (uint16_t *)0x0;

        uStack_58 = 0;

        iStack_54 = 0;

        uStack_50 = 0;

        uStack_44 = 0;

        uStack_48 = 0;

        uStack_40 = 0;

        uStack_3c = 0;

        uStack_4 = 0;

        FUN_004230d0();

        iVar1 = FUN_00422fb0(1);

        if (-1 < iVar1) {

          iVar1 = FUN_0041a810(&uStack_64,param_1 + 0x28,0,0,&DAT_00a140c8);

        }

        puStack_5c = auStack_8c;

        if ((((((iVar1 < 0) || (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)) ||

              (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)) ||

             ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||

              (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)))) ||

            ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||

             ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||

              (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)))))) ||

           ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||

            ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 || (iStack_54 == 0)))))) {

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s");

          uStack_4 = 0xffffffff;

          FUN_0041a3e0();

        }

        else {

          iVar1 = FUN_0041a9b0();

          if (iVar1 == 0) {

            *(uint16_t *)((int)param_4 + 6) = auStack_8c[0];

            *(uint16_t *)((int)param_4 + 10) = uStack_70;

            *(uint16_t *)(param_4 + 2) = uStack_68;

            *(uint16_t *)((int)param_4 + 0xe) = uStack_6c;

            *(uint16_t *)(param_4 + 3) = uStack_80;

            *(uint16_t *)(param_4 + 1) = uStack_78;

            *(uint16_t *)(param_4 + 4) = uStack_38;

            *param_4 = uStack_90;

            *(uint16_t *)((int)param_4 + 0x12) = uStack_84;

            FUN_0041a990();

            FUN_00423170();

          }

          else {

            FUN_0041a990();

            FUN_00423170();

            FUN_007a4480(1,"DBReader: %u against %s");

          }

          uStack_4 = 0xffffffff;

          FUN_0041a3e0();

        }

      }

      else {

        FUN_00423670();

        uStack_4 = 1;

        _itow(iStack_7c,awStack_34,10);

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

        SysFreeString(pOStack_74);

      }

      iVar1 = 0;

    }

  }

  ExceptionList = local_c;

  return iVar1;

}
