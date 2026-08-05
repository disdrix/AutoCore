// READABILITY (auto CF):
//  - Body size: ~197 non-empty decompiler lines.
//  - Control keywords: if×26, return×4, do×3, while×3, goto×1.
//  - Notable callees: FUN_00437050×6, FUN_00456780×6, FUN_007689e0×5, vog_LogMessage×5, FUN_00769e40×4, FUN_009871c0×3, FUN_007698e0×2, FUN_00436900.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp"; "Invalid TAG unserializing anmAnimMaster"; "unrecognized target type"; "Invalid chunk version unserializing anmAnimMaster".
//  - Return sites: 4.

// =============================================================================
// Named_anmAnimMaster
// -----------------------------------------------------------------------------
// Stable ID: aa_00964690
// Address:   0x00964690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmAnimMaster"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_anmAnimMaster(int param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  int local_2c;

  int local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20 [8];

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  uVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1fff;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 != 0x414e494d) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x101,3,

                   "Invalid TAG unserializing anmAnimMaster");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_10 == 0) {

    if (*(int *)(uVar2 + 0x4044) == 0) {

      FUN_00437050(&param_2);

    }

    else {

      FUN_007689e0(&param_2);

    }

    uVar5 = param_2;

    FUN_00456780(0);

    uVar4 = 0;

    if (uVar5 != 0) {

      do {

        if (*(int *)(uVar2 + 0x4044) == 0) {

          FUN_00437050(&local_2c);

        }

        else {

          FUN_007689e0(&local_2c);

        }

        if ((((local_2c != 0x4b535254) && (local_2c != 7)) && (local_2c != 0x4b455254)) &&

           (local_2c != 3)) {

          FUN_007698e0();

          goto LAB_00964828;

        }

        iVar1 = *(int *)(param_1 + 0xc);

        uVar3 = FUN_009871c0(uVar2);

        *(uint32_t /* width from decompiler */ *)(iVar1 + uVar4 * 4) = uVar3;

        if (*(int *)(*(int *)(param_1 + 0xc) + uVar4 * 4) == 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x11e,2

                         ,"unrecognized target type");

          param_2 = param_2 - 1;

          uVar4 = uVar4 - 1;

          FUN_00456780(0);

        }

        uVar4 = uVar4 + 1;

      } while (uVar4 < param_2);

    }

  }

  else {

    if (local_10 == 1) {

      FUN_007698e0();

LAB_00964828:

      uVar3 = FUN_00963fb0(param_1,uVar2,local_20);

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return uVar3;

    }

    if ((local_10 == 2) || (local_10 == 3)) {

      if (*(int *)(uVar2 + 0x4044) == 0) {

        FUN_00437050(&param_2);

      }

      else {

        FUN_007689e0(&param_2);

      }

      if (*(int *)(uVar2 + 0x4044) == 0) {

        FUN_00437000();

      }

      else {

        FUN_00769660((uint8_t *)(param_1 + 4));

      }

      uVar5 = param_2;

      if (local_10 == 2) {

        *(uint8_t *)(param_1 + 4) = 0;

      }

      FUN_00456780(0);

      uVar4 = 0;

      if (uVar5 != 0) {

        do {

          if (*(int *)(uVar2 + 0x4044) == 0) {

            FUN_00437050(&local_2c);

          }

          else {

            FUN_007689e0(&local_2c);

            uVar5 = param_2;

          }

          local_28 = *(int *)(param_1 + 0xc);

          uVar3 = FUN_009871c0(uVar2);

          *(uint32_t /* width from decompiler */ *)(local_28 + uVar4 * 4) = uVar3;

          if (*(int *)(*(int *)(param_1 + 0xc) + uVar4 * 4) == 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x146

                           ,2,"unrecognized target type");

            uVar5 = uVar5 - 1;

            uVar4 = uVar4 - 1;

            param_2 = uVar5;

            FUN_00456780(0);

          }

          uVar4 = uVar4 + 1;

        } while (uVar4 < uVar5);

      }

    }

    else {

      if (local_10 != 4) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x184,3,

                       "Invalid chunk version unserializing anmAnimMaster");

        local_4 = 0xffffffff;

        if (local_18 != '\0') {

          FUN_00769e40();

        }

        ExceptionList = local_c;

        return 0xffffffff;

      }

      FUN_00436900();

      FUN_00439a50();

      uVar5 = param_2;

      FUN_00456780(0);

      uVar4 = 0;

      if (uVar5 != 0) {

        do {

          if (*(int *)(uVar2 + 0x4044) == 0) {

            FUN_00437050(&local_2c);

          }

          else {

            FUN_007689e0(&local_2c);

            uVar5 = param_2;

          }

          local_28 = *(int *)(param_1 + 0xc);

          uVar3 = FUN_009871c0(uVar2);

          *(uint32_t /* width from decompiler */ *)(local_28 + uVar4 * 4) = uVar3;

          if (*(int *)(*(int *)(param_1 + 0xc) + uVar4 * 4) == 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x160

                           ,2,"unrecognized target type");

            uVar5 = uVar5 - 1;

            uVar4 = uVar4 - 1;

            param_2 = uVar5;

            FUN_00456780(0);

          }

          uVar4 = uVar4 + 1;

        } while (uVar4 < uVar5);

      }

      if (*(int *)(uVar2 + 0x4044) == 0) {

        FUN_00437050(&param_2);

      }

      else {

        FUN_00768760(&param_2);

      }

      *(uint *)(param_1 + 0x20) = param_2;

      if (param_2 == 1) {

        param_2 = 0;

        FUN_0096a7f0(&param_2,uVar2);

        FUN_00981f50(&param_2);

      }

      else if (param_2 == 2) {

        FUN_00981fb0(uVar2);

      }

      else {

        local_28 = 0;

        local_24 = 0;

        local_4._0_1_ = 1;

        FUN_00448f50();

        local_4 = (uint)local_4._1_3_ << 8;

        FUN_00448ed0();

      }

    }

  }

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0;

}
