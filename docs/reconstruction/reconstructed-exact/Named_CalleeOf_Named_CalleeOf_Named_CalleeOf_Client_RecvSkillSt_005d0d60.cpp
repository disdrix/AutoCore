// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt_005d0d60
// -----------------------------------------------------------------------------
// Stable ID: aa_005d0d60
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect
// Address:   0x005d0d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~167 non-empty decompiler lines.
//  - Control keywords: if×19, return×5, while×4, goto×2, do×1, switch×1.
//  - Notable callees: ABS×4, SQRT×2, CVOGPhysics_ApplyImpulseVector, CVOGSpawnPoint_SetObjectActiveState, FUN_00404c90, FUN_00404dc0, FUN_00404e00, FUN_0040d040.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvSkillSt_005d0d60(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  char *pcVar6;

  float *pfVar7;

  int *piVar8;

  uint uVar9;

  float fVar10;

  char local_41;

  int local_40;

  int *local_3c;

  int local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  uint8_t auStack_20 [28];

  

  iVar2 = *(int *)(param_1 + 0x18);

  if (iVar2 != 0) {

    local_38 = param_1;

    if ((*(char *)(param_1 + 0x21) != '\0') && (*(char *)(*(int *)(iVar2 + 0xa4) + 0x7e) == '\0')) {

      local_41 = '\x01';

      CVOGSpawnPoint_SetObjectActiveState(iVar2,&local_41,0);

    }

    piVar3 = *(int **)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) + 0xac

                                        + *(int *)(param_1 + 100)) + 0x3c) + 0x520);

    piVar8 = (int *)*piVar3;

    local_3c = (int *)0x0;

    local_41 = '\0';

    if (piVar8 != piVar3) {

      do {

        if (local_41 != '\0') goto LAB_005d0e90;

        uVar9 = 0;

        local_40 = 0;

        while( true ) {

          if ((piVar8[5] == 0) || ((uint)((piVar8[6] - piVar8[5]) / 0x18) <= uVar9))

          goto LAB_005d0e33;

          local_3c = (int *)(piVar8[5] + local_40);

          if (*local_3c == param_2) break;

          uVar9 = uVar9 + 1;

          local_40 = local_40 + 0x18;

        }

        local_41 = '\x01';

LAB_005d0e33:

        if (*(char *)((int)piVar8 + 0x21) == '\0') {

          piVar4 = (int *)piVar8[2];

          if (*(char *)((int)piVar4 + 0x21) == '\0') {

            cVar1 = *(char *)(*piVar4 + 0x21);

            piVar8 = piVar4;

            piVar4 = (int *)*piVar4;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar4 + 0x21);

              piVar8 = piVar4;

              piVar4 = (int *)*piVar4;

            }

          }

          else {

            cVar1 = *(char *)(piVar8[1] + 0x21);

            piVar5 = (int *)piVar8[1];

            piVar4 = piVar8;

            while ((piVar8 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar8[2]))) {

              cVar1 = *(char *)(piVar8[1] + 0x21);

              piVar5 = (int *)piVar8[1];

              piVar4 = piVar8;

            }

          }

        }

        param_1 = local_38;

      } while (piVar8 != piVar3);

      if (local_41 != '\0') {

LAB_005d0e90:

        local_34 = (float)(uint)*(ushort *)(local_3c + 1);

        fVar10 = (float)(int)g_dwClientTickMs;

        if ((int)g_dwClientTickMs < 0) {

          fVar10 = fVar10 + _DAT_00aaa5dc;

        }

        *(float *)(param_1 + 0x30) = (fVar10 + (float)(int)local_34) * g_flMsToSeconds_Inferred;

        if ((short)local_3c[1] != 0) {

          if (*(char *)((int)local_3c + 10) != '\0') {

            *(uint8_t *)(*(int *)(param_1 + 100) + 0x305) = 1;

            iVar2 = *(int *)(param_1 + 100);

            if ((*(char *)(iVar2 + 0x304) != '\0') && (*(int *)(iVar2 + 8) != 0)) {

              *(uint8_t *)(iVar2 + 0x304) = 0;

              local_2c = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 8) + 0x3c) + 0x44);

              local_30 = 0.0;

              local_28 = 0.0;

              local_24 = 0.0;

              CVOGPhysics_ApplyImpulseVector(&local_30);

            }

            if (*(int *)(*(int *)(param_1 + 100) + 0x250) != 0) {

              VehicleEntity_SetHandbrake(1);

            }

            iVar2 = *(int *)(param_1 + 100);

            piVar3 = *(int **)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa4 + iVar2);

            if ((((piVar3 != (int *)0x0) &&

                 (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) +

                                   0x3c) + 0x4e8) != 1)) && (*(int *)(iVar2 + 8) != 0)) &&

               ((local_34 = (float)(**(code **)(*piVar3 + 0x1c8))(), local_34 != 0.0 &&

                (*(int *)((int)local_34 + 8) != 0)))) {

              iVar2 = *(int *)(param_1 + 100);

              pcVar6 = (char *)FUN_00404e00(&local_41);

              if (*pcVar6 != '\0') {

                iVar2 = *(int *)(*(int *)(iVar2 + 8) + 0x3c);

                local_30 = ABS(*(float *)(iVar2 + 0x50) - (float)g_abInferredDefaultAimPos._0_4_);

                local_2c = ABS(*(float *)(iVar2 + 0x54) - (float)g_abInferredDefaultAimPos._4_4_);

                local_28 = ABS(*(float *)(iVar2 + 0x58) - (float)g_abInferredDefaultAimPos._8_4_);

                local_24 = ABS(*(float *)(iVar2 + 0x5c) - (float)g_abInferredDefaultAimPos._12_4_);

                if ((g_flMsToSeconds_Inferred < local_28 || g_flMsToSeconds_Inferred < local_2c) ||

                    g_flMsToSeconds_Inferred < local_30) {

                  FUN_0040d040(g_abInferredDefaultAimPos);

                }

                pfVar7 = (float *)FUN_00404c90();

                local_30 = *pfVar7;

                local_2c = pfVar7[1];

                local_28 = pfVar7[2];

                local_24 = pfVar7[3];

                pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) +

                                                                         4) + 4) + 4 +

                                                       *(int *)(param_1 + 100)) + 0x1a0))();

                local_30 = local_30 - *pfVar7;

                local_28 = local_28 - pfVar7[2];

                local_34 = local_30 * local_30 + local_28 * local_28;

                if (SQRT(local_34) <= _DAT_009da864) {

                  return;

                }

                if (local_34 == 0.0) {

                  fVar10 = 0.0;

                }

                else {

                  fVar10 = g_flOne / SQRT(local_34);

                  local_34 = fVar10;

                }

                local_30 = fVar10 * local_30;

                local_2c = fVar10 * 0.0;

                local_28 = local_28 * fVar10;

                local_24 = (local_24 - pfVar7[3]) * fVar10;

                FUN_004e8dc0(&local_30,auStack_20);

                FUN_00404dc0(auStack_20);

              }

            }

          }

          *(uint8_t *)(*(int *)(param_1 + 100) + 0x306) = 1;

        }

        switch(*(uint8_t *)((int)local_3c + 0xb)) {

        case 1:

          (**(code **)(**(int **)(param_1 + 100) + 100))(3,0x3dcccccd,1,0xbf800000);

          return;

        case 2:

          (**(code **)(**(int **)(param_1 + 100) + 100))(4,0x3dcccccd,1,0xbf800000);

          return;

        case 3:

          (**(code **)(**(int **)(param_1 + 100) + 100))(0x10,0x3dcccccd,1,0xbf800000);

          return;

        case 4:

          (**(code **)(**(int **)(param_1 + 100) + 100))(0x11,0x3dcccccd,1,0xbf800000);

        }

      }

    }

  }

  return;

}
