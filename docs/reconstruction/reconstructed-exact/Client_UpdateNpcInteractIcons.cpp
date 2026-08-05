// READABILITY (auto CF):
//  - Body size: ~258 non-empty decompiler lines.
//  - Control keywords: if×33, goto×8, while×4, do×1, switch×1, return×1.
//  - Notable callees: CNDHash_LookupByKey×3, CVOGObject_SetInteractSpecialFX×3, FUN_004024b0×2, FUN_0040c6b0×2, FUN_00411900×2, FUN_00411e10×2, FUN_00411e40×2, NDSpecialFX_LoadFromScriptName×2.
//  - Strings: "generic_interact"; "generic_interact_npc"; "interact_npc_available_old_mission"; "interact_npc_active_mission".
//  - Return sites: 1.

// =============================================================================
// Client_UpdateNpcInteractIcons
// -----------------------------------------------------------------------------
// Stable ID: aa_0091b8d0
// Address:   0x0091b8d0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Client_UpdateNpcInteractIcons

   

   Periodic pass over in-scope interactive objects. Updates cached interact state at entry+0x10

   and attaches NDSpecialFX when object has no current FX (object+0x4c == 0).

   

   State enum (stored entry+0x10):

     0 clear / 1 generic_interact / 2 generic_interact_npc

     3 available_old_mission / 4 active_mission / 5 active_pending

     6 available_new_mission / 7 available_new_mission_core

     8 active_mission_target_complete

   

   State 6 vs 7: CoreMission flag on mission def (offset +0x169).

   After mission complete, next core offers flip to 7 and load FX → same MSXML crash site. */



void Client_UpdateNpcInteractIcons(void)



{

  char cVar1;

  bool bVar2;

  TFID_16 *pTfid;

  int *piVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  void *pvVar7;

  int *piVar8;

  uint uVar9;

  uint *pSpecialFx;

  void *pvVar10;

  uint uVar11;

  char *pszName;

  char cStack_22;

  int iStack_20;

  int *piStack_1c;

  uint32_t /* width from decompiler */ local_18;

  TFID_16 *local_14;

  int *local_10;

  uint8_t auStack_c [4];

  float fStack_8;

  

  if ((((DAT_00d1a8dd == '\0') && (DAT_00d1b6d8 != (void *)0x0)) &&

      (*(char *)((int)DAT_00d1b6d8 + 0x4f1) == '\0')) &&

     (((local_18 = 0, DAT_00d1b644 != 0 && (*(int *)(DAT_00d1b644 + 0xe8f4) != 0)) &&

      ((*(int *)((int)DAT_00d1b6d8 + 0x250) != 0 && (*(int *)(DAT_00d1b644 + 0xe4e8) != 0)))))) {

    DAT_00d1f0b4 = DAT_00d1f0b4 + 1;

    if (0x1d < DAT_00d1f0b4) {

      DAT_00d1f0b4 = 0;

    }

    FUN_00411e10();

    pTfid = (TFID_16 *)FUN_0040c6b0();

    while (pTfid != (TFID_16 *)0x0) {

      local_14 = pTfid;

      piVar3 = Object_ResolveFromTFID(pTfid);

      local_10 = piVar3;

      if (((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x1cc))(), iVar4 != 0)) &&

         (*(int *)(iVar4 + 8) != 0)) {

        if (*(int *)(piVar3[0x2a] + 0x38) == 0x12) {

          iVar5 = (**(code **)(*piVar3 + 0x1d8))();

          piVar8 = *(int **)(iVar5 + 0x284);

          if (piVar8 != (int *)0x0) {

            piStack_1c = *(int **)(iVar4 + 8);

            iStack_20 = (**(code **)(*piVar8 + 0x54))();

            iVar5 = (**(code **)(*piStack_1c + 0x54))();

            if (*(float *)(iVar5 + 0x24) <= *(float *)(iStack_20 + 0x24) &&

                *(float *)(iStack_20 + 0x24) != *(float *)(iVar5 + 0x24)) {

              (**(code **)(*piVar8 + 0x54))();

            }

          }

        }

        FUN_004e88e0(auStack_c,*(int *)(*(int *)(iVar4 + 4) + 4) + 0x84 + iVar4);

        iVar5 = (**(code **)(**(int **)(iVar4 + 8) + 0x54))();

        fStack_8 = *(float *)(iVar5 + 0xc) + fStack_8;

        iVar5 = (**(code **)(**(int **)(iVar4 + 8) + 0x54))();

        fStack_8 = (float)(fStack_8 < *(float *)(iVar5 + 0x24)) + fStack_8;

        if (fStack_8 != g_flZero) {

          piVar8 = *(int **)(iVar4 + 8);

          iVar4 = (**(code **)(*piVar8 + 0x54))();

          iVar5 = (**(code **)(*piVar8 + 0x54))();

          fStack_8 = (*(float *)(iVar4 + 0x24) - *(float *)(iVar5 + 0xc)) + fStack_8;

        }

        if (DAT_00d1f0b4 == 0) {

          if (pTfid[1].dwCoidHi == 0) {

            uVar6._0_1_ = pTfid[1].bGlobal;

            uVar6._1_1_ = pTfid[1].bPad0;

            uVar6._2_1_ = pTfid[1].bPad1;

            uVar6._3_1_ = pTfid[1].bPad2;

            uVar11._0_1_ = pTfid[1].bPad3;

            uVar11._1_1_ = pTfid[1].bPad4;

            uVar11._2_1_ = pTfid[1].bPad5;

            uVar11._3_1_ = pTfid[1].bPad6;

            if ((uVar6 & uVar11) != 0xffffffff) {

              uVar6 = FUN_004bb1c0(0,uVar6,uVar11);

              pTfid[1].dwCoidHi = uVar6;

            }

          }

          pvVar10 = DAT_00d1b6d8;

          if ((int *)pTfid[1].dwCoidHi == (int *)0x0) {

            if (pTfid[2].dwCoidLo == 0xffffffff) {

              pTfid[1].dwCoidLo = (*(int *)(piVar3[0x2a] + 0x38) == 0x12) + 1;

            }

            else {

              pvVar7 = CNDHash_LookupByKey(*(void **)((int)DAT_00d1b6d8 + 0x548),pTfid[2].dwCoidLo);

              if ((pvVar7 == (void *)0x0) ||

                 (bVar2 = CVOGCharacter_HasCompletedMission

                                    (pvVar10,**(uint **)((int)pvVar7 + 0x14c)),

                 pvVar10 = DAT_00d1b6d8, bVar2)) {

                local_10 = (int *)0x0;

                cVar1 = CVOGObject_EvalOfferableMissionInteractState(piVar3,pvVar10,&local_10);

              }

              else {

                cVar1 = CVOGMission_EvalActiveObjectiveInteractState

                                  (*(uint32_t /* width from decompiler */ *)((int)pvVar7 + 0x14c),piVar3,DAT_00d1b6d8);

              }

              if ((int)cVar1 != pTfid[1].dwCoidLo) {

                if (piVar3[0x4c] != 0) {

                  CVOGObject_SetInteractSpecialFX(piVar3,(void *)0x0);

                }

                pTfid[1].dwCoidLo = (int)cVar1;

              }

            }

          }

          else {

            uVar6 = pTfid[1].dwCoidLo;

            iVar4 = *(int *)((int)DAT_00d1b6d8 + 0x250);

            cStack_22 = '\0';

            if (iVar4 != 0) {

              iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

            }

            cVar1 = (**(code **)(*(int *)pTfid[1].dwCoidHi + 100))(iVar4);

            if (cVar1 != '\0') {

              cStack_22 = CVOGObject_EvalInteractStateFromChildren

                                    (DAT_00d1b6d8,piVar3,0,pTfid[1].dwCoidHi);

            }

            pvVar10 = DAT_00d1b6d8;

            pvVar7 = CNDHash_LookupByKey(*(void **)((int)DAT_00d1b6d8 + 0x548),pTfid[2].dwCoidLo);

            piStack_1c = (int *)0x0;

            if (pvVar7 == (void *)0x0) {

              iStack_20 = 0;

              FUN_00402c40();

              iVar4 = FUN_00411900(&iStack_20);

              piVar8 = piStack_1c;

              pTfid = local_14;

              while (piStack_1c = piVar8, local_14 = pTfid, iVar4 != 0) {

                uVar11 = 0;

                iVar5 = FUN_004024b0();

                if (iVar5 != 0) {

                  do {

                    piVar8 = *(int **)(*(int *)(iVar4 + 0x158) + uVar11 * 4);

                    iVar5 = (**(code **)(*piVar8 + 0x50))();

                    pvVar10 = DAT_00d1b6d8;

                    if ((iVar5 == 3) && (piVar8[6] == *(int *)(piVar3[0x2a] + 0x34))) {

                      pvVar7 = CNDHash_LookupByKey(*(void **)((int)DAT_00d1b6d8 + 0x55c),

                                                   *(uint *)(iVar4 + 0x10));

                      cVar1 = (**(code **)(*piVar8 + 0xc))(pvVar10,pvVar7);

                      piStack_1c = (int *)((-(uint)(cVar1 != '\0') & 3) + 5);

                      piVar3 = local_10;

                    }

                    uVar11 = uVar11 + 1;

                    uVar9 = FUN_004024b0();

                  } while (uVar11 < uVar9);

                }

                iVar4 = FUN_00411900(&iStack_20);

                piVar8 = piStack_1c;

                pTfid = local_14;

              }

              *(uint8_t *)(*(int *)((int)DAT_00d1b6d8 + 0x548) + 0x1d) = 0;

            }

            else {

              cVar1 = CVOGMission_EvalActiveObjectiveInteractState

                                (*(uint32_t /* width from decompiler */ *)((int)pvVar7 + 0x14c),piVar3,pvVar10);

              piVar8 = (int *)(int)cVar1;

            }

            if ((int)piVar8 <= (int)cStack_22) {

              piVar8 = (int *)(int)cStack_22;

            }

            pTfid[1].dwCoidLo = (uint)piVar8;

            if (((char)uVar6 != cStack_22) && (piVar3[0x4c] != 0)) {

              CVOGObject_SetInteractSpecialFX(piVar3,(void *)0x0);

            }

          }

        }

        switch(pTfid[1].dwCoidLo) {

        case 0:

          if (piVar3[0x4c] != 0) {

            pSpecialFx = (uint *)0x0;

LAB_0091be0f:

            CVOGObject_SetInteractSpecialFX(piVar3,pSpecialFx);

          }

          break;

        case 1:

          if (piVar3[0x4c] == 0) {

            pszName = "generic_interact";

LAB_0091bdff:

            pSpecialFx = NDSpecialFX_LoadFromScriptName(pszName,4,0);

            if (pSpecialFx != (uint *)0x0) {

              *pSpecialFx = *pSpecialFx | 2;

              goto LAB_0091be0f;

            }

          }

          break;

        case 2:

          if (piVar3[0x4c] == 0) {

            pszName = "generic_interact_npc";

            goto LAB_0091bdff;

          }

          break;

        case 3:

          if (piVar3[0x4c] == 0) {

            pszName = "interact_npc_available_old_mission";

            goto LAB_0091bdff;

          }

          break;

        case 4:

          if (piVar3[0x4c] == 0) {

            pszName = "interact_npc_active_mission";

            goto LAB_0091bdff;

          }

          break;

        case 5:

          if (piVar3[0x4c] == 0) {

            pszName = "interact_npc_active_mission_target_pending";

            goto LAB_0091bdff;

          }

          break;

        case 6:

          if (piVar3[0x4c] == 0) {

            pszName = "interact_npc_available_new_mission";

            goto LAB_0091bdff;

          }

          break;

        case 7:

          if (piVar3[0x4c] == 0) {

            pszName = "interact_npc_available_new_mission_core";

            goto LAB_0091bdff;

          }

          break;

        case 8:

          if (piVar3[0x4c] == 0) {

            pszName = "interact_npc_active_mission_target_complete";

            goto LAB_0091bdff;

          }

        }

      }

      pTfid = (TFID_16 *)FUN_0040c6b0();

    }

    *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe8f4) + 0x1d) = 0;

    local_14 = (TFID_16 *)0x0;

    FUN_00411e10();

    iVar4 = FUN_00411e40();

    while (iVar4 != 0) {

      if ((((*(char *)(iVar4 + 4) == '\x01') &&

           (piVar3 = (int *)CVOGReaction_ResolveObjectTarget

                                      (0,*(uint32_t /* width from decompiler */ *)(iVar4 + 8),*(uint32_t /* width from decompiler */ *)(iVar4 + 0xc)),

           piVar3 != (int *)0x0)) && (*(int *)(piVar3[0x2a] + 0x38) == 0x3a)) &&

         (pvVar10 = NDSpecialFX_LoadFromScriptName("generic_interact_secondary",4,0),

         pvVar10 != (void *)0x0)) {

        (**(code **)(*piVar3 + 0xf8))(pvVar10,1,0);

      }

      iVar4 = FUN_00411e40();

    }

    *(uint8_t *)(*(int *)((int)DAT_00d1b6d8 + 0x6f0) + 0x1d) = 0;

  }

  return;

}
