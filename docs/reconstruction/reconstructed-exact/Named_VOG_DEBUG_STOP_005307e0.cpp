// READABILITY (auto CF):
//  - Body size: ~276 non-empty decompiler lines.
//  - Control keywords: if×35, while×6, for×6, do×5, return×4, goto×4.
//  - Notable callees: FUN_007a4480×10, Client_SendLogicUiPacket×2, FUN_004e2ca0×2, FUN_007a6de0×2, Client_GetMissionCompleteAudioTable, Client_PlayNamedInterfaceSound, FUN_0040c5c0, FUN_004de9f0.
//  - Strings: "HashError:remove, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:Destroy, already locked for traversal"; "Failed".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_005307e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005307e0
// Address:   0x005307e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_005307e0(int param_1)



{

  int iVar1;

  uint uVar2;

  int *piVar3;

  bool bVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint uVar12;

  int *piVar13;

  char *pcVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint32_t /* width from decompiler */ uVar16;

  uint32_t /* width from decompiler */ uVar17;

  uint32_t /* width from decompiler */ uVar18;

  uint32_t /* width from decompiler */ uVar19;

  int local_728;

  int local_720;

  int local_71c;

  void *pvStack_714;

  uint local_710;

  void *pvStack_70c;

  char acStack_708 [128];

  uint32_t /* width from decompiler */ uStack_688;

  uint32_t /* width from decompiler */ uStack_684;

  uint32_t /* width from decompiler */ uStack_680;

  uint32_t /* width from decompiler */ uStack_67c;

  uint32_t /* width from decompiler */ uStack_678;

  uint32_t /* width from decompiler */ uStack_674;

  uint32_t /* width from decompiler */ auStack_670 [7];

  uint32_t /* width from decompiler */ uStack_654;

  uint32_t /* width from decompiler */ auStack_538 [7];

  uint32_t /* width from decompiler */ uStack_51c;

  char acStack_400 [1024];

  

  uVar12 = 0;

  do {

    iVar9 = *(int *)(param_1 + 0x564);

    if ((iVar9 == 0) || ((uint)(*(int *)(param_1 + 0x568) - iVar9 >> 2) <= uVar12)) {

      if (*(void **)(param_1 + 0x564) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + 0x564));

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x564) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xd6c) = 0;

      *(uint8_t *)(param_1 + 0xd68) = 0;

      return;

    }

    iVar1 = *(int *)(param_1 + 0x540);

    uVar2 = *(uint *)(iVar9 + uVar12 * 4);

    iVar7 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) + (*(uint *)(iVar1 + 8) & uVar2) * 4) + 4);

    if (iVar7 == 0) {

LAB_0053084b:

      local_728 = 0;

    }

    else {

      do {

        if (uVar2 == *(uint *)(iVar7 + 0x10)) {

          if (iVar7 == 0) goto LAB_0053084b;

          local_728 = *(int *)(iVar7 + 8);

          goto LAB_0053085c;

        }

        iVar7 = *(int *)(iVar7 + 0xc);

      } while (iVar7 != 0);

      local_728 = 0;

    }

LAB_0053085c:

    if (local_728 != 0) {

      uVar10 = *(uint32_t /* width from decompiler */ *)(iVar9 + uVar12 * 4);

      if (*(char *)(iVar1 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:remove, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      puVar8 = (uint32_t /* width from decompiler */ *)FUN_004e2ca0(uVar10);

      if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar8[2] = 0;

        if (puVar8 == *(uint32_t /* width from decompiler */ **)(iVar1 + 0x14)) {

          *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14) = puVar8[5];

        }

        else {

          *(uint32_t /* width from decompiler */ *)(puVar8[6] + 0x14) = puVar8[5];

        }

        if (puVar8 == *(uint32_t /* width from decompiler */ **)(iVar1 + 0x18)) {

          *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18) = puVar8[6];

        }

        else {

          *(uint32_t /* width from decompiler */ *)(puVar8[5] + 0x18) = puVar8[6];

        }

        *puVar8 = &PTR_LAB_009cf024;

        *puVar8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20);

        *(uint32_t /* width from decompiler */ **)(iVar1 + 0x20) = puVar8;

        *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -1;

      }

      iVar9 = *(int *)(param_1 + 0x544);

      uVar10 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x564) + uVar12 * 4);

      if (*(char *)(iVar9 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:remove, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      puVar8 = (uint32_t /* width from decompiler */ *)FUN_004e2ca0(uVar10);

      if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar8[2] = 0;

        if (puVar8 == *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14)) {

          *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14) = puVar8[5];

        }

        else {

          *(uint32_t /* width from decompiler */ *)(puVar8[6] + 0x14) = puVar8[5];

        }

        if (puVar8 == *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18)) {

          *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18) = puVar8[6];

        }

        else {

          *(uint32_t /* width from decompiler */ *)(puVar8[5] + 0x18) = puVar8[6];

        }

        *puVar8 = &PTR_LAB_009cf024;

        *puVar8 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x20);

        *(uint32_t /* width from decompiler */ **)(iVar9 + 0x20) = puVar8;

        *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + -1;

      }

      local_710 = (uint)*(byte *)(local_728 + 0x130);

      bVar4 = false;

      local_720 = 0;

      if (local_710 != 0) {

        do {

          uVar2 = *(uint *)(*(int *)(*(int *)(local_728 + 0x13c) + local_720 * 4) + 0x10);

          if (*(int *)(param_1 + 0xd6c) == 1) {

            iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x548) + 0x10) +

                                     (*(uint *)(*(int *)(param_1 + 0x548) + 8) & uVar2) * 4) + 4);

            if (iVar9 == 0) {

LAB_005309e7:

              local_71c = 0;

            }

            else {

              do {

                if (uVar2 == *(uint *)(iVar9 + 0x10)) {

                  if (iVar9 == 0) goto LAB_005309e7;

                  local_71c = *(int *)(iVar9 + 8);

                  goto LAB_005309f8;

                }

                iVar9 = *(int *)(iVar9 + 0xc);

              } while (iVar9 != 0);

              local_71c = 0;

            }

LAB_005309f8:

            piVar13 = *(int **)(local_71c + 0x158);

            if (piVar13 != *(int **)(local_71c + 0x15c)) {

              do {

                piVar3 = (int *)*piVar13;

                iVar9 = (**(code **)(*piVar3 + 0x50))();

                if ((iVar9 == 0xe) && (g_flZero < (float)piVar3[0x28])) {

                  bVar4 = true;

                  uStack_51c = 0x30;

                  auStack_538[0] = 0;

                  Client_SendLogicUiPacket(auStack_538);

                }

                piVar13 = piVar13 + 1;

              } while (piVar13 != *(int **)(local_71c + 0x15c));

            }

          }

          iVar9 = *(int *)(param_1 + 0x55c);

          for (iVar1 = *(int *)(*(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & uVar2) * 4

                                        ) + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {

            if (uVar2 == *(uint *)(iVar1 + 0x10)) {

              if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {

                if (*(char *)(iVar9 + 0x1d) != '\0') {

                  FUN_007a4480(0,"HashError:Destroy, already locked for traversal");

                  FUN_007a4480(0,"VOG_DEBUG_STOP");

                }

                iVar9 = FUN_00538000(uVar2,&pvStack_714);

                if (-1 < iVar9) {

                    /* WARNING: Subroutine does not return */

                  operator_delete(pvStack_714);

                }

              }

              break;

            }

          }

          iVar9 = *(int *)(param_1 + 0x548);

          if (*(char *)(iVar9 + 0x1d) != '\0') {

            FUN_007a4480(0,"HashError:remove, already locked for traversal");

            FUN_007a4480(0,"VOG_DEBUG_STOP");

          }

          iVar1 = *(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & uVar2) * 4);

          puVar6 = *(uint32_t /* width from decompiler */ **)(iVar1 + 4);

          puVar8 = (uint32_t /* width from decompiler */ *)0x0;

          while (puVar5 = puVar6, puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

            if (uVar2 == puVar5[4]) {

              if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

                if (puVar8 == (uint32_t /* width from decompiler */ *)0x0) {

                  *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = puVar5[3];

                }

                else {

                  puVar8[3] = puVar5[3];

                }

              }

              break;

            }

            puVar8 = puVar5;

            puVar6 = (uint32_t /* width from decompiler */ *)puVar5[3];

          }

          FUN_00537d30();

          if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar5[2] = 0;

            if (puVar5 == *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14)) {

              *(uint32_t /* width from decompiler */ *)(iVar9 + 0x14) = puVar5[5];

            }

            else {

              *(uint32_t /* width from decompiler */ *)(puVar5[6] + 0x14) = puVar5[5];

            }

            if (puVar5 == *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18)) {

              *(uint32_t /* width from decompiler */ *)(iVar9 + 0x18) = puVar5[6];

            }

            else {

              *(uint32_t /* width from decompiler */ *)(puVar5[5] + 0x18) = puVar5[6];

            }

            *puVar5 = &PTR_LAB_009cf02c;

            *puVar5 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x20);

            *(uint32_t /* width from decompiler */ **)(iVar9 + 0x20) = puVar5;

            *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + -1;

          }

          local_720 = local_720 + 1;

        } while (local_720 < (int)local_710);

      }

      uVar10 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x564) + uVar12 * 4);

      if (*(char *)(*(int *)(param_1 + 0x530) + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:Destroy, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      iVar9 = FUN_00537f30(uVar10,&pvStack_70c);

      if (-1 < iVar9) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvStack_70c);

      }

      iVar9 = *(int *)(*(int *)(param_1 + 4) + 4);

      if ((*(int *)(*(int *)(iVar9 + 0xa8 + param_1) + 0xe8a0) == iVar9 + param_1 + 4) &&

         ((bVar4 || (*(int *)(param_1 + 0xd6c) == 0)))) {

        FUN_007a69d0();

        auStack_670[0] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x564) + uVar12 * 4);

        uStack_654 = 0xd;

        Client_SendLogicUiPacket(auStack_670);

        uVar10 = FUN_007a6de0(*(uint32_t /* width from decompiler */ *)(local_728 + 0x14c),0xffffffff);

        uVar11 = FUN_007a6de0("Failed",0xffffffff);

        sprintf(acStack_400,"%s %s",uVar11,uVar10);

        uStack_688 = 0xffffffff;

        acStack_708[0] = '\0';

        strncpy(acStack_708,acStack_400,0x80);

        uStack_684 = DAT_00a110d8;

        uStack_67c = 0;

        uStack_680 = DAT_00aaa68c;

        uStack_688 = 0xffeee3d8;

        uStack_678 = 0xffffffff;

        uStack_674 = 0xffffffff;

        FUN_0040c5c0(acStack_708);

        uVar19 = 0;

        uVar18 = 0x1e;

        uVar17 = 0;

        uVar16 = 0;

        uVar15 = 0xffffffff;

        uVar11 = 0xffffffff;

        uVar10 = 0;

        pcVar14 = "gen_end_quest";

        Client_GetMissionCompleteAudioTable("gen_end_quest",0,0xffffffff,0xffffffff,0,0,0x1e,0);

        Client_PlayNamedInterfaceSound(pcVar14,uVar10,uVar11,uVar15,uVar16,uVar17,uVar18,uVar19);

      }

      FUN_004de9f0();

      FUN_0052d8b0(0,0xffffffff);

    }

    uVar12 = uVar12 + 1;

  } while( true );

}
