// READABILITY (auto CF):
//  - Body size: ~210 non-empty decompiler lines.
//  - Control keywords: if×25, do×2, while×2, return×2.
//  - Notable callees: FUN_00435df0×6, FUN_00767fd0×4, FUN_00768760×4, vog_LogMessage×3, FUN_00437000×2, FUN_00437050×2, FUN_0043ffb0×2, FUN_00769660×2.
//  - Strings: "

                       ,0x132,3,"; "

                       ,0x14f,3,"; ";

    uVar9 = 0x155;

  }

  else {

    pcVar10 = "; ";

    uVar9 = 0x10e;

  }

  vog_LogMessage(".
//  - Return sites: 2.

// =============================================================================
// Named_gfxLODHandler_SimpleDistance
// -----------------------------------------------------------------------------
// Stable ID: aa_0075a980
// Address:   0x0075a980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLODHandler_SimpleDistance"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_gfxLODHandler_SimpleDistance(int param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  char *pcVar10;

  int local_30;

  int local_2c;

  int local_28;

  uint32_t /* width from decompiler */ *local_24;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1c55;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_28 = param_1;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 == 0x4c445344) {

    if (local_10 == 1) {

      if (*(int *)(param_2 + 0x4044) == 0) {

        param_2 = FUN_00437050(&local_30);

      }

      else {

        param_2 = FUN_00768760(&local_30);

      }

      FUN_0043ffb0(0,0,0,0);

      local_24 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

      puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

      if (puVar8 != local_24) {

        do {

          local_2c = 0;

          if (*(int *)(iVar2 + 0x4044) == 0) {

            if ((*(int *)(iVar2 + 0x20) < *(int *)(iVar2 + 0x18) + 4) &&

               ((iVar3 = FUN_00435df0(*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x18)), iVar3 < 0 ||

                (*(int *)(iVar2 + 0x20) < 4)))) {

              uVar4 = 0xffffffff;

            }

            else {

              local_2c = *(int *)(*(int *)(iVar2 + 0x18) + iVar2 + 0x2c);

              *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 4;

              uVar4 = 0;

            }

          }

          else {

            uVar4 = FUN_00768760(&local_2c);

          }

          if (*(int *)(iVar2 + 0x4044) == 0) {

            uVar5 = FUN_00437000();

          }

          else {

            uVar5 = FUN_00769660(puVar8 + 1);

          }

          if (*(int *)(iVar2 + 0x4044) == 0) {

            if ((*(int *)(iVar2 + 0x20) < *(int *)(iVar2 + 0x18) + 4) &&

               ((iVar3 = FUN_00435df0(*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x18)), iVar3 < 0 ||

                (*(int *)(iVar2 + 0x20) < 4)))) {

              uVar6 = 0xffffffff;

            }

            else {

              puVar8[2] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c + *(int *)(iVar2 + 0x18));

              *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 4;

              uVar6 = 0;

            }

          }

          else {

            uVar6 = FUN_00767fd0(puVar8 + 2);

          }

          if (*(int *)(iVar2 + 0x4044) == 0) {

            if ((*(int *)(iVar2 + 0x20) < *(int *)(iVar2 + 0x18) + 4) &&

               ((iVar3 = FUN_00435df0(*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x18)), iVar3 < 0 ||

                (*(int *)(iVar2 + 0x20) < 4)))) {

              uVar7 = 0xffffffff;

            }

            else {

              puVar8[3] = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x18) + iVar2 + 0x2c);

              *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 4;

              uVar7 = 0;

            }

          }

          else {

            uVar7 = FUN_00767fd0(puVar8 + 3);

          }

          param_2 = param_2 | uVar4 | uVar5 | uVar6 | uVar7;

          *puVar8 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(local_28 + 4) + 0xc0) + local_2c * 4);

          puVar8 = puVar8 + 4;

          param_1 = local_28;

        } while (puVar8 != local_24);

      }

      if ((int)param_2 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_SimpleDistance.cpp"

                       ,0x132,3,"Error unserializing pieces in gfxLODHandler_SimpleDistance!");

      }

      if (*(int *)(iVar2 + 0x4044) == 0) {

        uVar4 = FUN_00437050(&local_30);

      }

      else {

        uVar4 = FUN_00768760(&local_30);

      }

      param_2 = param_2 | uVar4;

      FUN_0043ffb0(0,0,0,0);

      local_24 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20);

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x1c) != local_24) {

        puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c) + 2;

        do {

          local_2c = 0;

          if (*(int *)(iVar2 + 0x4044) == 0) {

            if ((*(int *)(iVar2 + 0x20) < *(int *)(iVar2 + 0x18) + 4) &&

               ((iVar3 = FUN_00435df0(*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x18)), iVar3 < 0 ||

                (*(int *)(iVar2 + 0x20) < 4)))) {

              uVar4 = 0xffffffff;

            }

            else {

              local_2c = *(int *)(*(int *)(iVar2 + 0x18) + iVar2 + 0x2c);

              *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 4;

              uVar4 = 0;

            }

          }

          else {

            uVar4 = FUN_00768760(&local_2c);

          }

          if (*(int *)(iVar2 + 0x4044) == 0) {

            uVar5 = FUN_00437000();

          }

          else {

            uVar5 = FUN_00769660(puVar8 + -1);

          }

          if (*(int *)(iVar2 + 0x4044) == 0) {

            if ((*(int *)(iVar2 + 0x20) < *(int *)(iVar2 + 0x18) + 4) &&

               ((iVar3 = FUN_00435df0(*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x18)), iVar3 < 0 ||

                (*(int *)(iVar2 + 0x20) < 4)))) {

              uVar6 = 0xffffffff;

            }

            else {

              *puVar8 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x18) + iVar2 + 0x2c);

              *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 4;

              uVar6 = 0;

            }

          }

          else {

            uVar6 = FUN_00767fd0(puVar8);

          }

          if (*(int *)(iVar2 + 0x4044) == 0) {

            if ((*(int *)(iVar2 + 0x20) < *(int *)(iVar2 + 0x18) + 4) &&

               ((iVar3 = FUN_00435df0(*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x18)), iVar3 < 0 ||

                (*(int *)(iVar2 + 0x20) < 4)))) {

              uVar7 = 0xffffffff;

            }

            else {

              puVar8[1] = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x18) + iVar2 + 0x2c);

              *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 4;

              uVar7 = 0;

            }

          }

          else {

            uVar7 = FUN_00767fd0(puVar8 + 1);

          }

          param_2 = param_2 | uVar4 | uVar5 | uVar6 | uVar7;

          iVar3 = *(int *)(local_28 + 4);

          if ((*(int *)(iVar3 + 0xd0) == 0) ||

             (local_30 = *(int *)(iVar3 + 0xd4) - *(int *)(iVar3 + 0xd0) >> 2, local_30 == 0)) {

            uVar9 = 0;

          }

          else {

            uVar9 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xd0) + local_2c * 4);

          }

          puVar8[-2] = uVar9;

          puVar1 = puVar8 + 2;

          puVar8 = puVar8 + 4;

        } while (puVar1 != local_24);

      }

      if ((int)param_2 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_SimpleDistance.cpp"

                       ,0x14f,3,"Error unserializing shadows in gfxLODHandler_SimpleDistance!");

      }

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return param_2;

    }

    pcVar10 = "Invalid chunk version unserializing gfxLODHandler_SimpleDistance";

    uVar9 = 0x155;

  }

  else {

    pcVar10 = "Invalid TAG unserializing gfxGeometryPiece";

    uVar9 = 0x10e;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_SimpleDistance.cpp",

                 uVar9,3,pcVar10);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
