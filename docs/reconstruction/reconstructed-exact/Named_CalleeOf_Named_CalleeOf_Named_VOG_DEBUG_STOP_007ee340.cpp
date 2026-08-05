// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007ee340
// -----------------------------------------------------------------------------
// Stable ID: aa_007ee340
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x007ee340  (autoassault.exe, image base 0x400000)
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
//  - Body size: ~319 non-empty decompiler lines.
//  - Control keywords: if×19, return×7.
//  - Notable callees: block×65, FUN_004231d0×31, FUN_007e0230×4, FUN_0041a3e0×3, FUN_00423170×3, _com_issue_error×3, CONCAT31×2, FUN_0041a990×2.
//  - Strings: "DBReader: %u against %s".
//  - Return sites: 7.

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

/* WARNING: Removing unreachable block (ram,0x007ef2df) */

/* WARNING: Removing unreachable block (ram,0x007ef270) */

/* WARNING: Removing unreachable block (ram,0x007ef204) */

/* WARNING: Removing unreachable block (ram,0x007ef198) */

/* WARNING: Removing unreachable block (ram,0x007ef12c) */

/* WARNING: Removing unreachable block (ram,0x007ef0bd) */

/* WARNING: Removing unreachable block (ram,0x007ef050) */

/* WARNING: Removing unreachable block (ram,0x007eefe4) */

/* WARNING: Removing unreachable block (ram,0x007eef74) */

/* WARNING: Removing unreachable block (ram,0x007eef05) */

/* WARNING: Removing unreachable block (ram,0x007eee95) */

/* WARNING: Removing unreachable block (ram,0x007eee25) */

/* WARNING: Removing unreachable block (ram,0x007eed95) */

/* WARNING: Removing unreachable block (ram,0x007eed29) */

/* WARNING: Removing unreachable block (ram,0x007eecbb) */

/* WARNING: Removing unreachable block (ram,0x007eec4d) */

/* WARNING: Removing unreachable block (ram,0x007eec05) */

/* WARNING: Removing unreachable block (ram,0x007eec27) */

/* WARNING: Removing unreachable block (ram,0x007eec53) */

/* WARNING: Removing unreachable block (ram,0x007eec84) */

/* WARNING: Removing unreachable block (ram,0x007eec8a) */

/* WARNING: Removing unreachable block (ram,0x007eecc1) */

/* WARNING: Removing unreachable block (ram,0x007eecf2) */

/* WARNING: Removing unreachable block (ram,0x007eecf8) */

/* WARNING: Removing unreachable block (ram,0x007eed2f) */

/* WARNING: Removing unreachable block (ram,0x007eed60) */

/* WARNING: Removing unreachable block (ram,0x007eed66) */

/* WARNING: Removing unreachable block (ram,0x007eed9b) */

/* WARNING: Removing unreachable block (ram,0x007eedef) */

/* WARNING: Removing unreachable block (ram,0x007eedf5) */

/* WARNING: Removing unreachable block (ram,0x007eee2b) */

/* WARNING: Removing unreachable block (ram,0x007eee5d) */

/* WARNING: Removing unreachable block (ram,0x007eee63) */

/* WARNING: Removing unreachable block (ram,0x007eee9b) */

/* WARNING: Removing unreachable block (ram,0x007eeecd) */

/* WARNING: Removing unreachable block (ram,0x007eeed3) */

/* WARNING: Removing unreachable block (ram,0x007eef0b) */

/* WARNING: Removing unreachable block (ram,0x007eef3d) */

/* WARNING: Removing unreachable block (ram,0x007eef43) */

/* WARNING: Removing unreachable block (ram,0x007eef7a) */

/* WARNING: Removing unreachable block (ram,0x007eefac) */

/* WARNING: Removing unreachable block (ram,0x007eefb2) */

/* WARNING: Removing unreachable block (ram,0x007eefea) */

/* WARNING: Removing unreachable block (ram,0x007ef01a) */

/* WARNING: Removing unreachable block (ram,0x007ef020) */

/* WARNING: Removing unreachable block (ram,0x007ef056) */

/* WARNING: Removing unreachable block (ram,0x007ef086) */

/* WARNING: Removing unreachable block (ram,0x007ef08c) */

/* WARNING: Removing unreachable block (ram,0x007ef0c3) */

/* WARNING: Removing unreachable block (ram,0x007ef0f4) */

/* WARNING: Removing unreachable block (ram,0x007ef0fa) */

/* WARNING: Removing unreachable block (ram,0x007ef132) */

/* WARNING: Removing unreachable block (ram,0x007ef162) */

/* WARNING: Removing unreachable block (ram,0x007ef168) */

/* WARNING: Removing unreachable block (ram,0x007ef19e) */

/* WARNING: Removing unreachable block (ram,0x007ef1ce) */

/* WARNING: Removing unreachable block (ram,0x007ef1d4) */

/* WARNING: Removing unreachable block (ram,0x007ef20a) */

/* WARNING: Removing unreachable block (ram,0x007ef23a) */

/* WARNING: Removing unreachable block (ram,0x007ef240) */

/* WARNING: Removing unreachable block (ram,0x007ef276) */

/* WARNING: Removing unreachable block (ram,0x007ef2a7) */

/* WARNING: Removing unreachable block (ram,0x007ef2ad) */

/* WARNING: Removing unreachable block (ram,0x007ef2e5) */

/* WARNING: Removing unreachable block (ram,0x007ef30c) */



int __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007ee340(char *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uStack_e0;

  uint8_t uStack_db;

  uint8_t uStack_da;

  uint8_t uStack_d9;

  short sStack_d8;

  short sStack_d4;

  uint32_t /* width from decompiler */ uStack_d0;

  uint32_t /* width from decompiler */ uStack_cc;

  uint32_t /* width from decompiler */ *puStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  int iStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ *puStack_b8;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  BSTR pOStack_a4;

  int *piStack_a0;

  short sStack_9c;

  int iStack_98;

  uint16_t uStack_94;

  short sStack_90;

  uint16_t uStack_8c;

  short sStack_88;

  short sStack_84;

  short sStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  char *local_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

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

  puStack_8 = &LAB_009b0e5f;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    iVar1 = -0x7fffbffc;

  }

  else {

    ExceptionList = &local_c;

    local_78 = param_1;

    iVar1 = FUN_007e59d0();

    if (-1 < iVar1) {

      iStack_98 = *param_2;

      if (DAT_00d1793c == '\0') {

        puStack_b8 = &uStack_d0;

        uStack_d0 = 0;

        uStack_cc = 0;

        puStack_c8 = (uint32_t /* width from decompiler */ *)0x0;

        uStack_c4 = 0;

        iStack_c0 = 0;

        uStack_bc = 0;

        uStack_b0 = 0;

        uStack_b4 = 0;

        uStack_ac = 0;

        uStack_a8 = 0;

        uStack_4 = 0;

        FUN_004230d0();

        iVar1 = FUN_00422fb0(1);

        if (-1 < iVar1) {

          iVar1 = FUN_0041a810(&uStack_d0,param_1 + 0x28,0,0,&DAT_00a140c8);

        }

        puStack_c8 = &uStack_7c;

        if (((((((((iVar1 < 0) || (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

                 (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

                (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                  (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

                 ((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                  ((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                   (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)))))))) ||

               (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

              (((((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                  (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

                 (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

                ((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                 (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)))) ||

               (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)))) ||

             (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

               (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

              (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                  (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

                 (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)))) ||

               (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                 (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

                (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)))))))) ||

            (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

              (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

             ((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

              (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

                (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) ||

               (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)))))))) ||

           (((iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0 ||

             (iVar1 = FUN_004231d0(&uStack_d0), iVar1 < 0)) || (iStack_c0 == 0)))) {

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s");

          uStack_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = local_c;

          return 0;

        }

        iVar1 = FUN_0041a9b0();

        if (iVar1 != 0) {

          FUN_0041a990();

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s");

          uStack_4 = 0xffffffff;

          FUN_0041a3e0();

          ExceptionList = local_c;

          return 0;

        }

        param_4[0xf] = uStack_74;

        param_4[0x10] = uStack_44;

        param_4[0x11] = uStack_3c;

        param_4[0x12] = uStack_50;

        *(byte *)((int)param_4 + 0x76) =

             ((((((((byte)sStack_d8 ^ (byte)(sStack_d8 >> 7)) - (char)(sStack_d8 >> 7)) * '\x02' +

                 (((byte)sStack_d4 ^ (byte)(sStack_d4 >> 7)) - (char)(sStack_d4 >> 7))) * '\x02' +

                (((byte)sStack_80 ^ (byte)(sStack_80 >> 7)) - (char)(sStack_80 >> 7))) * '\x02' +

               (((byte)sStack_90 ^ (byte)(sStack_90 >> 7)) - (char)(sStack_90 >> 7))) * '\x04' +

              (((byte)sStack_88 ^ (byte)(sStack_88 >> 7)) - (char)(sStack_88 >> 7))) * '\x02' +

             (((byte)sStack_84 ^ (byte)(sStack_84 >> 7)) - (char)(sStack_84 >> 7))) * '\x02' +

             (((byte)sStack_9c ^ (byte)(sStack_9c >> 7)) - (char)(sStack_9c >> 7));

        param_4[0x13] = uStack_68;

        param_4[0x15] = uStack_7c;

        *(uint8_t *)(param_4 + 0x1d) = uStack_d9;

        *param_4 = uStack_40;

        param_4[0x1a] = uStack_58;

        param_4[1] = uStack_60;

        param_4[0x1b] = uStack_38;

        *(uint16_t *)(param_4 + 0x1c) = uStack_8c;

        *(uint16_t *)((int)param_4 + 0x72) = uStack_94;

        param_4[2] = uStack_48;

        *(uint8_t *)((int)param_4 + 0x75) = uStack_da;

        param_4[0x14] = uStack_70;

        *(uint8_t *)((int)param_4 + 0x77) = uStack_db;

        param_4[0x16] = uStack_6c;

        param_4[0x18] = uStack_64;

        param_4[0x17] = uStack_5c;

        param_4[0x1f] = uStack_4c;

        param_4[0x19] = uStack_54;

        *(uint16_t *)(param_4 + 0x1e) = pOStack_a4._0_2_;

        param_4[0x20] = uStack_e0;

        FUN_0041a990();

        FUN_00423170();

        uStack_4 = 0xffffffff;

        FUN_0041a3e0();

      }

      else {

        FUN_00423670();

        uStack_4 = 1;

        _itow(iStack_98,awStack_34,10);

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

        if (piStack_a0 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        iVar1 = FUN_00419ff0();

        if (0 < iVar1) {

          if (piStack_a0 == (int *)0x0) {

            _com_issue_error(-0x7fffbffd);

          }

          (**(code **)(*piStack_a0 + 0x1c))(piStack_a0);

        }

        uStack_4 = CONCAT31(uStack_4._1_3_,1);

        if (piStack_a0 != (int *)0x0) {

          (**(code **)(*piStack_a0 + 8))();

        }

        uStack_4 = 0xffffffff;

        SysFreeString(pOStack_a4);

      }

      if ((int)param_4[0x16] < 1) {

        param_4[3] = 0;

        param_4[4] = 0;

        param_4[5] = 0;

      }

      else {

        iVar1 = FUN_007e0230();

        if (iVar1 < 0) {

          ExceptionList = local_c;

          return iVar1;

        }

      }

      if ((int)param_4[0x17] < 1) {

        param_4[6] = 0;

        param_4[7] = 0;

        param_4[8] = 0;

      }

      else {

        iVar1 = FUN_007e0230();

        if (iVar1 < 0) {

          ExceptionList = local_c;

          return iVar1;

        }

      }

      if ((int)param_4[0x18] < 1) {

        param_4[9] = 0;

        param_4[10] = 0;

        param_4[0xb] = 0;

      }

      else {

        iVar1 = FUN_007e0230();

        if (iVar1 < 0) {

          ExceptionList = local_c;

          return iVar1;

        }

      }

      if ((int)param_4[0x19] < 1) {

        iVar1 = 0;

        param_4[0xc] = 0;

        param_4[0xd] = 0;

        param_4[0xe] = 0;

      }

      else {

        iVar1 = FUN_007e0230();

      }

    }

  }

  ExceptionList = local_c;

  return iVar1;

}
