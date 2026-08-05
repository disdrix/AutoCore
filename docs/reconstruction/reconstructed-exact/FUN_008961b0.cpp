// =============================================================================
// FUN_008961b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008961b0
// Address:   0x008961b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008961b0 @ 0x008961b0
// Stable ID: aa_008961b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~239 non-empty decompiler lines.
//  - Control keywords: if×14, do×10, while×10, for×4, goto×1, return×1.
//  - Notable callees: sprintf×4, FUN_00521080, FUN_008961b0.
//  - Strings: "_%i".
//  - Return sites: 1.

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

void __fastcall FUN_008961b0(int param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  uint uVar7;

  uint uVar8;

  int *piVar9;

  char *pcVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ uStack_2e8;

  uint8_t *puStack_2e4;

  float fStack_2e0;

  uint32_t /* width from decompiler */ uStack_2dc;

  int *piStack_2d8;

  uint8_t *puStack_2d4;

  uint32_t /* width from decompiler */ uStack_2d0;

  float fVar12;

  int local_2b0;

  uint8_t auStack_2a4 [8];

  char acStack_29c [4];

  uint8_t auStack_298 [4];

  uint8_t auStack_294 [4];

  int local_290;

  int local_28c;

  char acStack_288 [48];

  char acStack_258 [63];

  char acStack_219 [5];

  char acStack_214 [259];

  char acStack_111 [15];

  char acStack_102 [254];

  

  if ((DAT_00d1b6d8 != 0) && (*(char *)(param_1 + 0x518) == '\0')) {

    piVar9 = (int *)(param_1 + 0x58c);

    local_2b0 = 0x36;

    do {

      if ((piVar9[0x36] != 0) && (iVar4 = *(int *)(piVar9[0x36] + 0x60c), iVar4 != 0)) {

        uVar7 = *(byte *)(iVar4 + 0x5fb) / 5;

        if ((uint)*(byte *)(iVar4 + 0x5f8) == *(uint *)(param_1 + 0x51c)) {

          local_290 = (int)((float)DAT_00d1e818 *

                            (float)(int)((*(int *)(param_1 + 0x530) + *(int *)(param_1 + 0x528)) *

                                         (*(byte *)(iVar4 + 0x5f9) - 1) + *(int *)(param_1 + 0x520))

                           * DAT_00aaa67c);

          local_28c = (int)((float)DAT_00d1e81c *

                            (float)(int)((*(int *)(param_1 + 0x534) + *(int *)(param_1 + 0x52c)) *

                                         (uVar7 - *(int *)(param_1 + 0x50c)) +

                                        *(int *)(param_1 + 0x524)) * DAT_00aaa678);

          (**(code **)(*(int *)piVar9[0x36] + 0x118))();

          if (((int)uVar7 < *(int *)(param_1 + 0x50c)) ||

             (*(int *)(param_1 + 0x514) <= (int)(uVar7 - *(int *)(param_1 + 0x50c)))) {

            (**(code **)(*(int *)piVar9[0x36] + 0xcc))();

            (**(code **)(*(int *)piVar9[0x36] + 0x444))();

          }

          else {

            (**(code **)(*(int *)piVar9[0x36] + 0xcc))();

            (**(code **)(*(int *)piVar9[0x36] + 0x444))();

          }

        }

        else {

          (**(code **)(*(int *)piVar9[0x36] + 0xcc))();

        }

        (**(code **)(*(int *)piVar9[0x36] + 0x34c))();

        if (*piVar9 != 0) {

          if (((uint)*(byte *)(iVar4 + 0x5f8) == *(uint *)(param_1 + 0x51c)) &&

             ((0 < *(short *)(iVar4 + 0x5f6) || (*(short *)(iVar4 + 0x174) != 0)))) {

            uStack_2d0 = 0x896394;

            sprintf(acStack_29c,"%i");

            if (*(short *)(iVar4 + 0x174) < 1) {

              (**(code **)(*(int *)*piVar9 + 0x160))();

            }

            else {

              (**(code **)(*(int *)*piVar9 + 0x160))();

            }

            fVar12 = 1.4013e-45;

            uStack_2d0 = 1;

            puStack_2d4 = auStack_2a4;

            piStack_2d8 = (int *)0x8963d3;

            (**(code **)(*(int *)*piVar9 + 0x1d8))();

            piStack_2d8 = &local_28c;

            uStack_2dc = 0x8963e2;

            (**(code **)(*(int *)*piVar9 + 0x124))();

            uStack_2dc = 0;

            fStack_2e0 = 1.4013e-45;

            puStack_2e4 = auStack_298;

            uStack_2e8 = 0x896417;

            piVar2 = (int *)(**(code **)(*(int *)piVar9[0x36] + 0x120))();

            uStack_2e8 = 1;

            piVar3 = (int *)(**(code **)(*(int *)piVar9[0x36] + 0x140))(auStack_294);

            piStack_2d8 = (int *)((int)fVar12 + *piVar3 + *piVar2);

            iVar4 = (**(code **)(*(int *)*piVar9 + 0x124))(&local_28c);

            puStack_2d4 = (uint8_t *)((float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678)

            ;

            iVar4 = (**(code **)(*(int *)piVar9[0x36] + 0x120))(auStack_298,1,0);

            puStack_2e4 = (uint8_t *)((int)fStack_2e0 + *(int *)(iVar4 + 4));

            (**(code **)(*(int *)*piVar9 + 0x118))(&uStack_2e8);

            if ((*(int *)(param_1 + 0x50c) <= (int)uVar7) &&

               ((int)(uVar7 - *(int *)(param_1 + 0x50c)) < *(int *)(param_1 + 0x514)))

            goto LAB_008964c5;

            (**(code **)(*(int *)*piVar9 + 0xcc))();

          }

          else {

LAB_008964c5:

            (**(code **)(*(int *)*piVar9 + 0xcc))();

          }

          (**(code **)(*(int *)*piVar9 + 0x34c))();

        }

      }

      piVar9 = piVar9 + 1;

      local_2b0 = local_2b0 + -1;

    } while (local_2b0 != 0);

    iVar4 = 0;

    piVar9 = (int *)(param_1 + 0x570);

    do {

      if (*piVar9 != 0) {

        uStack_2d0 = 0x89651b;

        sprintf(acStack_258,"%d");

        uStack_2d0 = 0x896531;

        (**(code **)(*(int *)*piVar9 + 0x1d8))();

        uStack_2d0 = 0x89653b;

        (**(code **)(*(int *)*piVar9 + 0x34c))();

      }

      iVar4 = iVar4 + 1;

      piVar9 = piVar9 + 1;

    } while (iVar4 < 7);

    if (*(int *)(param_1 + 0x56c) != 0) {

      uStack_2d0 = 0x89656d;

      sprintf(acStack_29c,"%i");

      uStack_2d0 = 0x896587;

      (**(code **)(**(int **)(param_1 + 0x56c) + 0x1d8))();

      uStack_2d0 = 0x896595;

      (**(code **)(**(int **)(param_1 + 0x56c) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x544) != 0) {

      acStack_219[1] = 0;

      pcVar6 = acStack_219;

      do {

        pcVar5 = pcVar6;

        pcVar6 = pcVar5 + 1;

      } while (pcVar5[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = DAT_00a4fc10;

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = DAT_00a4fc14;

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 9) = DAT_00a4fc18;

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 0xd) = DAT_00a4fc1c;

      pcVar5 = (char *)FUN_00521080();

      pcVar6 = pcVar5;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      pcVar11 = acStack_219;

      do {

        pcVar10 = pcVar11 + 1;

        pcVar11 = pcVar11 + 1;

      } while (*pcVar10 != '\0');

      pcVar10 = pcVar5;

      for (uVar7 = (uint)((int)pcVar6 - (int)pcVar5) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar11 = pcVar11 + 4;

      }

      for (uVar7 = (int)pcVar6 - (int)pcVar5 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

        *pcVar11 = *pcVar10;

        pcVar10 = pcVar10 + 1;

        pcVar11 = pcVar11 + 1;

      }

      uStack_2d0 = 0x896636;

      sprintf(acStack_288,"_%i");

      pcVar6 = acStack_288;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      uVar7 = (int)pcVar6 - (int)acStack_288;

      pcVar6 = acStack_219;

      do {

        pcVar5 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar5 != '\0');

      pcVar5 = acStack_288;

      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar6 = pcVar6 + 4;

      }

      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

        *pcVar6 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar6 = pcVar6 + 1;

      }

      pcVar6 = acStack_219;

      do {

        pcVar5 = pcVar6;

        pcVar6 = pcVar5 + 1;

      } while (pcVar5[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = DAT_00a2c53c;

      pcVar5[5] = DAT_00a2c540;

      iVar4 = **(int **)(param_1 + 0x544);

      (**(code **)(**(int **)(param_1 + 0x544) + 0x2c8))();

      uStack_2d0 = 0x8966c0;

      (**(code **)(iVar4 + 0x50))();

      uStack_2d0 = 0x8966ce;

      (**(code **)(**(int **)(param_1 + 0x544) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x568) != 0) {

      acStack_111[1] = 0;

      if (*(int *)(param_1 + 0x51c) == 1) {

        pcVar6 = acStack_111;

        do {

          pcVar5 = pcVar6;

          pcVar6 = pcVar5 + 1;

        } while (pcVar5[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = s_Faction_Skills_00a4fbfc._0_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = s_Faction_Skills_00a4fbfc._4_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 9) = s_Faction_Skills_00a4fbfc._8_4_;

        *(uint16_t *)(pcVar5 + 0xd) = s_Faction_Skills_00a4fbfc._12_2_;

        pcVar5[0xf] = s_Faction_Skills_00a4fbfc[0xe];

      }

      else if (*(int *)(param_1 + 0x51c) == 2) {

        pcVar6 = acStack_111;

        do {

          pcVar5 = pcVar6;

          pcVar6 = pcVar5 + 1;

        } while (pcVar5[1] != '\0');

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 1) = s_Specialty_Skills_00a4fbe8._0_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 5) = s_Specialty_Skills_00a4fbe8._4_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 9) = s_Specialty_Skills_00a4fbe8._8_4_;

        *(uint32_t /* width from decompiler */ *)(pcVar5 + 0xd) = s_Specialty_Skills_00a4fbe8._12_4_;

        pcVar5[0x11] = s_Specialty_Skills_00a4fbe8[0x10];

      }

      uStack_2d0 = 0x89678e;

      (**(code **)(**(int **)(param_1 + 0x568) + 0x1d8))();

      uStack_2d0 = 0x89679f;

      (**(code **)(**(int **)(param_1 + 0x568) + 0x34c))();

    }

  }

  return;

}
