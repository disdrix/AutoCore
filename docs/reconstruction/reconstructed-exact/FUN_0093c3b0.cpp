// =============================================================================
// FUN_0093c3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093c3b0
// Address:   0x0093c3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093c3b0 @ 0x0093c3b0
// Stable ID: aa_0093c3b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: if×16, return×7, goto×2, do×1, while×1.
//  - Notable callees: CONCAT31×2, Client_SendSectorPacket×2, FUN_00571620×2, Client_RefreshOpenMissionUiWindows, FUN_00404060, FUN_0040fb90, FUN_005714e0, FUN_00571b80.
//  - Return sites: 7.

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

void __thiscall FUN_0093c3b0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  uint8_t uVar3;

  char cVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint8_t local_58 [4];

  int *local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ auStack_4c [2];

  int iStack_44;

  int iStack_40;

  uint8_t uStack_3c;

  uint8_t uStack_34;

  uint8_t uStack_33;

  uint8_t uStack_32;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ auStack_2c [2];

  int iStack_24;

  int iStack_20;

  uint8_t uStack_1c;

  uint8_t uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009bad45;

  local_c = ExceptionList;

  if (((*(char *)(param_1 + 0xb6) == '\0') &&

      (ExceptionList = &local_c, FUN_0093bac0(param_1,0), param_2 != 0)) &&

     (iVar1 = *(int *)(param_2 + 0x56c), iVar1 != 0)) {

    if (*(int *)(param_1 + 0x3108) == 1) {

      if (*(int *)(param_1 + 0xe98) == 0) {

        ExceptionList = local_c;

        return;

      }

      iVar5 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

      if (iVar5 == 0) {

        ExceptionList = local_c;

        return;

      }

      iVar5 = *(int *)(iVar5 + 0x2b0);

    }

    else {

      if (*(int *)(param_1 + 0x3108) != 3) {

        ExceptionList = local_c;

        return;

      }

      if (*(int *)(param_1 + 0xe98) == 0) {

        ExceptionList = local_c;

        return;

      }

      if (*(char *)(*(int *)(param_1 + 0xe04) + 0xf5) == '\0') {

        ExceptionList = local_c;

        return;

      }

      iVar5 = *(int *)(*(int *)(param_1 + 0xe98) + 0xcbc);

    }

    if (iVar5 != 0) {

      local_54 = (int *)FUN_0040fb90();

      local_50 = 0;

      local_4 = 0;

      FUN_00572060(*(uint32_t /* width from decompiler */ *)(param_1 + 0x310c),local_58);

      piVar8 = (int *)*local_54;

      if (piVar8 != local_54) {

        do {

          piVar2 = (int *)piVar8[2];

          if ((piVar2 != (int *)0x0) &&

             ((*(int *)(iVar1 + 4) != 5 ||

              ((*(char *)(*(int *)(piVar2[0x2a] + 0x3c) + 0x4be) == '\0' &&

               (((uint)piVar2[0x5f] >> 0x14 & 1) == 0)))))) {

            iVar5 = (**(code **)(*piVar2 + 0x1e0))();

            if (iVar5 == 0) {

LAB_0093c512:

              iVar5 = (**(code **)(*piVar2 + 0x1e0))();

              if ((iVar5 != 0) ||

                 (*(short *)(*(int *)(piVar2[0x2a] + 0x3c) + 0x3f4) != *(short *)(param_1 + 0x3110))

                 ) goto LAB_0093c6a5;

            }

            else {

              piVar6 = (int *)(**(code **)(*piVar2 + 0x1e0))();

              iVar5 = (**(code **)(*piVar6 + 0x60))();

              if (iVar5 != *(short *)(param_1 + 0x3110)) goto LAB_0093c512;

            }

            uVar3 = (**(code **)(*piVar2 + 0x250))();

            uStack_5c = CONCAT31(uStack_5c._1_3_,uVar3);

            uVar3 = (**(code **)(*piVar2 + 0x254))();

            uStack_60 = CONCAT31(uStack_60._1_3_,uVar3);

            cVar4 = FUN_005714e0(piVar2,&uStack_68,&uStack_64,0,*(uint8_t *)(param_2 + 0x564));

            if (cVar4 != '\0') {

              uVar9 = 0;

              uVar7 = (**(code **)(*piVar2 + 0x25c))(0);

              iVar5 = FUN_00571b80(piVar2,uVar7,uVar9);

              if (iVar5 != 0) {

                uVar7 = (**(code **)(*piVar2 + 0x25c))();

                cVar4 = FUN_00571620(piVar2,uStack_68,uStack_64,uVar7);

                if (cVar4 == '\0') {

                  uVar7 = (**(code **)(*piVar2 + 0x25c))();

                  FUN_00571620(piVar2,uStack_5c,uStack_60,uVar7);

                }

                else {

                  uStack_1c = (uint8_t)piVar2[0x5a];

                  iStack_24 = piVar2[0x58];

                  iStack_20 = piVar2[0x59];

                  uStack_14 = *(uint8_t *)(param_1 + 0x3108);

                  auStack_2c[0] = 0x2038;

                  uStack_10 = (**(code **)(*piVar2 + 0x25c))();

                  Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_2c);

                  uStack_3c = (uint8_t)piVar2[0x5a];

                  iStack_40 = piVar2[0x59];

                  iStack_44 = piVar2[0x58];

                  uStack_34 = (uint8_t)uStack_68;

                  uStack_32 = (uint8_t)*(uint32_t /* width from decompiler */ *)(iVar1 + 4);

                  auStack_4c[0] = 0x203a;

                  uStack_33 = (uint8_t)uStack_64;

                  uStack_30 = (**(code **)(*piVar2 + 0x25c))();

                  Client_SendSectorPacket(&DAT_00d1a840,0x20,auStack_4c);

                }

              }

            }

          }

LAB_0093c6a5:

          piVar8 = (int *)*piVar8;

        } while (piVar8 != local_54);

      }

      Client_RefreshOpenMissionUiWindows(param_1);

      FUN_0092ce90();

      local_4 = 0xffffffff;

      FUN_00404060();

                    /* WARNING: Subroutine does not return */

      operator_delete(local_54);

    }

  }

  ExceptionList = local_c;

  return;

}
