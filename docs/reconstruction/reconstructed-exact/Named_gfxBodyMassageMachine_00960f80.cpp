// READABILITY (auto CF):
//  - Body size: ~237 non-empty decompiler lines.
//  - Control keywords: if×22, return×5, do×3, while×3.
//  - Notable callees: FUN_00748960×4, FUN_00437050×3, FUN_00445620×3, FUN_00768760×3, FUN_00769e40×3, FUN_004406e0×2, FUN_0044c010×2, FUN_0074ce60×2.
//  - Strings: ",899,3,

                   "; ",

                     0x3d9,3,".
//  - Return sites: 5.

// =============================================================================
// Named_gfxBodyMassageMachine_00960f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00960f80
// Address:   0x00960f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxBodyMassageMachine"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_gfxBodyMassageMachine_00960f80(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  void *pvVar1;

  int *piVar2;

  uint uVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  uint local_70;

  int *local_6c;

  int *local_68;

  uint32_t /* width from decompiler */ local_64;

  void *local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  char local_48;

  int local_44;

  int local_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3da0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  uVar7 = 0;

  local_4 = 0;

  if (local_44 != 0x474e4f44) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",899,3,

                   "Invalid TAG unserializing gfxGeometryNode");

    local_4 = 0xffffffff;

    if (local_48 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_40 == 1) {

    if (*(int *)(param_1 + 0x4044) == 0) {

      uVar7 = FUN_00437050(&local_6c);

    }

    else {

      uVar7 = FUN_00768760(&local_6c);

    }

    local_5c = (void *)0x0;

    local_58 = 0;

    local_54 = 0;

    local_4._0_1_ = 1;

    if (0 < (int)local_6c) {

      local_64 = param_3;

      piVar2 = local_6c;

      local_70 = uVar7;

      do {

        local_6c = operator_new(0xc4);

        local_4._0_1_ = 2;

        if (local_6c == (int *)0x0) {

          piVar4 = (int *)0x0;

        }

        else {

          piVar4 = (int *)FUN_00748960();

        }

        local_4._0_1_ = 1;

        local_6c = piVar4;

        uVar6 = FUN_0095ef50();

        uVar7 = uVar7 | uVar6;

        piVar4[0x25] = *param_2;

        FUN_0044c010();

        if (*(char *)(DAT_00d1f044 + 0x779) != '\0') {

          (**(code **)(*piVar4 + 0x50))(0x5000000);

        }

        local_68 = piVar4;

        FUN_00445620();

        FUN_004406e0();

        piVar2 = (int *)((int)piVar2 + -1);

      } while (piVar2 != (int *)0x0);

    }

    pvVar1 = local_5c;

    local_70 = uVar7;

    iVar5 = FUN_0076a900();

    if (iVar5 == 0x53484456) {

      local_6c = operator_new(0xc4);

      local_4._0_1_ = 3;

      if (local_6c == (int *)0x0) {

        piVar2 = (int *)0x0;

      }

      else {

        piVar2 = (int *)FUN_00748960();

      }

      local_4._0_1_ = 1;

      local_70 = FUN_0095ee00(param_1);

      local_70 = uVar7 | local_70;

      local_64 = param_3;

      local_68 = piVar2;

      FUN_00445620();

    }

    uStack_3c = 0;

    uStack_38 = 0;

    uStack_34 = 0;

    uStack_30 = 0;

    uStack_2c = 0;

    uStack_28 = DAT_00aaa630;

    uStack_24 = DAT_00aaa630;

    uStack_20 = DAT_00aaa630;

    uStack_1c = DAT_00aaa63c;

    uStack_18 = DAT_00aaa63c;

    uStack_14 = DAT_00aaa63c;

    uStack_10 = 1;

    uVar7 = FUN_0074ce60();

    uVar7 = local_70 | uVar7;

    local_70 = uVar7;

    if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

  }

  else {

    if (local_40 != 2) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",

                     0x3d9,3,"Invalid chunk version unserializing gfxGeometryNode");

      local_4 = 0xffffffff;

      if (local_48 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return 0xffffffff;

    }

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00437050(&local_70);

    }

    else {

      FUN_00768760(&local_70);

    }

    local_5c = (void *)0x0;

    local_58 = 0;

    local_54 = 0;

    local_4._0_1_ = 4;

    if (0 < (int)local_70) {

      local_64 = param_3;

      uVar6 = local_70;

      do {

        local_6c = operator_new(0xc4);

        local_4._0_1_ = 5;

        if (local_6c == (int *)0x0) {

          piVar2 = (int *)0x0;

        }

        else {

          piVar2 = (int *)FUN_00748960();

        }

        local_4._0_1_ = 4;

        local_6c = piVar2;

        uVar3 = FUN_0095ef50();

        uVar7 = uVar7 | uVar3;

        piVar2[0x25] = *param_2;

        FUN_0044c010();

        if (*(char *)(DAT_00d1f044 + 0x779) != '\0') {

          (**(code **)(*piVar2 + 0x50))(0x5000000);

        }

        local_68 = piVar2;

        FUN_00445620();

        FUN_004406e0();

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00437050(&local_70);

    }

    else {

      FUN_00768760(&local_70);

    }

    piVar2 = local_6c;

    if (0 < (int)local_70) {

      local_64 = param_3;

      do {

        local_6c = operator_new(0xc4);

        local_4._0_1_ = 6;

        if (local_6c == (int *)0x0) {

          piVar4 = (int *)0x0;

        }

        else {

          piVar4 = (int *)FUN_00748960();

        }

        local_4._0_1_ = 4;

        uVar6 = FUN_0095ee00(param_1);

        iVar5 = DAT_00d1ef84;

        uVar7 = uVar7 | uVar6;

        local_68 = piVar4;

        if ((DAT_00d1ef80 == 0) ||

           ((uint)(DAT_00d1ef88 - DAT_00d1ef80 >> 3) <= (uint)(DAT_00d1ef84 - DAT_00d1ef80 >> 3))) {

          FUN_00446f30(DAT_00d1ef84,&local_68);

        }

        else {

          FUN_0045f220(piVar2);

          DAT_00d1ef84 = iVar5 + 8;

        }

        local_70 = local_70 - 1;

      } while (local_70 != 0);

    }

    uStack_3c = 0;

    uStack_38 = 0;

    uStack_34 = 0;

    uStack_30 = 0;

    uStack_2c = 0;

    uStack_28 = DAT_00aaa630;

    uStack_24 = DAT_00aaa630;

    uStack_20 = DAT_00aaa630;

    uStack_1c = DAT_00aaa63c;

    uStack_18 = DAT_00aaa63c;

    uStack_14 = DAT_00aaa63c;

    uStack_10 = 1;

    uVar6 = FUN_0074ce60();

    uVar7 = uVar7 | uVar6;

    if (local_5c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_5c);

    }

  }

  local_4 = 0xffffffff;

  if (local_48 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return uVar7;

}
