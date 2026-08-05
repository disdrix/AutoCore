// =============================================================================
// FUN_008f97c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f97c0
// Address:   0x008f97c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f97c0 @ 0x008f97c0
// Stable ID: aa_008f97c0
// Embedded strings (evidence for future rename):
//   - "Combat:\nFighting and driving ability.\nAffects Weapon and Skill Accuracy.\n\n"
//   - "Bonus"
//   - "%s: %d\n%s: %+d"
//   - " (capped)"
//   - "Accuracy Rating"
//   - "\n\n%s:\n%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~593 non-empty decompiler lines.
//  - Control keywords: if×34, do×31, while×31, for×26, return×2.
//  - Notable callees: FUN_007a6de0×24, sprintf×13, FUN_007a69d0×4, FUN_008f9290×4, ROUND×3, ceil×3, Character_GetTechForPoolCalcs×2, FUN_004c4070×2.
//  - Strings: "Bonus"; "%s: %d\n%s: %+d"; " (capped)"; "Accuracy Rating".
//  - Return sites: 2.

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

void __fastcall FUN_008f97c0(int *param_1)



{

  char cVar1;

  bool bVar2;

  short sVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  int iVar8;

  int *piVar9;

  uint uVar10;

  uint uVar11;

  char *pcVar12;

  int iVar13;

  char *pcVar14;

  float10 fVar15;

  float fVar16;

  double dVar17;

  int iVar18;

  uint64_t uVar19;

  char cStack_225;

  int aiStack_224 [2];

  float fStack_21c;

  uint32_t /* width from decompiler */ local_218;

  uint32_t /* width from decompiler */ uStack_214;

  char local_210 [243];

  char cStack_11d;

  char acStack_11c [19];

  char cStack_109;

  uint32_t /* width from decompiler */ local_108 [65];

  

  local_218 = FUN_007a69d0();

  if (DAT_00d1b6d8 == (void *)0x0) {

    if ((int *)param_1[0x520] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x520] + 0x1d8))(&DAT_00a1419b,1,1);

    }

    if ((int *)param_1[0x521] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x521] + 0x1d8))(&DAT_00a1419b,1,1);

    }

    if (param_1[0x536] != 0) {

      FUN_00855810();

    }

    if ((int *)param_1[0x529] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x529] + 0x1d8))(local_210,1,1);

    }

    if ((int *)param_1[0x52a] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x52a] + 0x1d8))(local_210,1,1);

    }

    if ((int *)param_1[0x52b] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x52b] + 0x1d8))(local_210,1,1);

    }

    if ((int *)param_1[0x52c] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x52c] + 0x1d8))(local_210,1,1);

    }

    if (((((int *)param_1[0x532] != (int *)0x0) && (param_1[0x533] != 0)) && (param_1[0x534] != 0))

       && (param_1[0x535] != 0)) {

      (**(code **)(*(int *)param_1[0x532] + 0xcc))();

      (**(code **)(*(int *)param_1[0x533] + 0xcc))(0);

      (**(code **)(*(int *)param_1[0x534] + 0xcc))(0);

      (**(code **)(*(int *)param_1[0x535] + 0xcc))();

    }

    if ((int *)param_1[0x52d] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x52d] + 0x1d8))(local_210,1,1);

    }

  }

  else {

    local_210[0] = '\0';

    if (param_1[0x520] != 0) {

      local_108[0]._0_1_ = '\0';

      FUN_0092e710();

      (**(code **)(*(int *)param_1[0x520] + 0x1d8))(local_108,1);

      (**(code **)(*(int *)param_1[0x520] + 0x34c))();

    }

    piVar9 = (int *)param_1[0x521];

    if (piVar9 != (int *)0x0) {

      local_108[0]._0_1_ = '\0';

      if (DAT_00d1da30 != 0) {

        pcVar4 = (char *)(DAT_00d1da30 + 4);

        iVar8 = (int)local_108 - (int)pcVar4;

        do {

          cVar1 = *pcVar4;

          pcVar4[iVar8] = cVar1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

      }

      (**(code **)(*piVar9 + 0x1d8))(local_108,1);

      (**(code **)(*(int *)param_1[0x521] + 0x34c))();

    }

    if ((param_1[0x536] != 0) && ((char)param_1[0x537] == '\0')) {

      FUN_00855810();

      *(uint8_t *)(param_1 + 0x537) = 1;

    }

    if (param_1[0x529] != 0) {

      FUN_004c4070();

      sprintf(local_210,"%d");

      (**(code **)(*(int *)param_1[0x529] + 0x1d8))(local_210,1);

      sVar3 = *(short *)((int)DAT_00d1b6d8 + 0x13e);

      if (199 < sVar3) {

        sVar3 = 200;

      }

      iVar13 = (int)sVar3;

      sVar3 = FUN_004c4070();

      iVar8 = *(int *)param_1[0x529];

      FUN_008f9290();

      (**(code **)(iVar8 + 0x15c))(1);

      (**(code **)(*(int *)param_1[0x529] + 0x34c))();

      pcVar4 = (char *)FUN_007a6de0("Combat:\nFighting and driving ability.\nAffects Weapon and Skill Accuracy.\n\n"

                                    ,0xffffffff);

      piVar9 = aiStack_224;

      do {

        cVar1 = *pcVar4;

        *(char *)piVar9 = cVar1;

        pcVar4 = pcVar4 + 1;

        piVar9 = (int *)((int)piVar9 + 1);

      } while (cVar1 != '\0');

      iVar18 = sVar3 - iVar13;

      uVar5 = FUN_007a6de0("Bonus",0xffffffff);

      iVar8 = iVar13;

      uVar6 = FUN_007a6de0(&DAT_00a35dc4,0xffffffff);

      sprintf(acStack_11c,"%s: %d\n%s: %+d",uVar6,iVar8,uVar5,iVar18);

      if ((sVar3 - iVar13) + iVar13 == 0xfa) {

        pcVar7 = (char *)FUN_007a6de0(" (capped)",0xffffffff);

        pcVar4 = pcVar7;

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar14 = &cStack_11d;

        do {

          pcVar12 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar12 != '\0');

        pcVar12 = pcVar7;

        for (uVar10 = (uint)((int)pcVar4 - (int)pcVar7) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar12;

          pcVar12 = pcVar12 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar4 - (int)pcVar7 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar12;

          pcVar12 = pcVar12 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      pcVar4 = acStack_11c;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)acStack_11c;

      pcVar4 = &cStack_225;

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      pcVar7 = acStack_11c;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      (**(code **)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 + (int)DAT_00d1b6d8) +

                  0x27c))();

      uVar5 = FUN_007a6de0("Accuracy Rating",0xffffffff);

      sprintf((char *)local_108,"\n\n%s:\n%d",uVar5);

      pcVar4 = (char *)local_108;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)local_108;

      pcVar4 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      pcVar7 = (char *)local_108;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      if ((int *)param_1[0x52e] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x52e] + 0x308))();

      }

    }

    if (param_1[0x52a] != 0) {

      Character_GetTechForPoolCalcs(DAT_00d1b6d8);

      sprintf(local_210,"%d");

      (**(code **)(*(int *)param_1[0x52a] + 0x1d8))(local_210,1,1);

      iVar13 = Character_GetTechForPoolCalcs(DAT_00d1b6d8);

      iVar8 = *(int *)param_1[0x52a];

      FUN_008f9290();

      (**(code **)(iVar8 + 0x15c))(1);

      (**(code **)(*(int *)param_1[0x52a] + 0x34c))();

      uVar19 = 0xffffffff00a35d48;

      FUN_007a69d0("Tech:\nPractical knowledge.\nAffects Hit Points and Heat Capacity.\n\n",

                   0xffffffff);

      pcVar7 = (char *)FUN_007a6de0(uVar19);

      pcVar4 = local_210;

      do {

        cVar1 = *pcVar7;

        *pcVar4 = cVar1;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      FUN_007a6de0("Bonus",0xffffffff);

      FUN_007a6de0(&DAT_00a35dc4,0xffffffff);

      sprintf((char *)local_108,"%s: %d\n%s: %+d");

      fStack_21c = (float)(int)(short)iVar13;

      if ((short)iVar13 == 0xfa) {

        pcVar7 = (char *)FUN_007a6de0(" (capped)",0xffffffff);

        pcVar4 = pcVar7;

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar14 = &cStack_109;

        do {

          pcVar12 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar12 != '\0');

        pcVar12 = pcVar7;

        for (uVar10 = (uint)((int)pcVar4 - (int)pcVar7) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar12;

          pcVar12 = pcVar12 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar4 - (int)pcVar7 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar12;

          pcVar12 = pcVar12 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      pcVar4 = (char *)local_108;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)local_108;

      pcVar4 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      fStack_21c = (float)(int)fStack_21c;

      pcVar7 = (char *)local_108;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      dVar17 = ceil((double)(fStack_21c * g_flVehicleHpTechCoeff));

      aiStack_224[0] = (int)ROUND(dVar17);

      uStack_214 = *(float *)(&DAT_00a15904 +

                             (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 +

                                                                                4) + 4) + 0xac +

                                                              (int)DAT_00d1b6d8) + 0x3c) + 0x532) *

                             4) * fStack_21c * DAT_00a0f298;

      dVar17 = ceil((double)uStack_214);

      uStack_214 = (float)(int)ROUND(dVar17);

      FUN_007a6de0("Heat Capacity Bonus",0xffffffff);

      FUN_007a6de0("Hit-Point Bonus",0xffffffff);

      sprintf((char *)local_108,"\n\n%s: %+d\n%s: %+d");

      pcVar4 = (char *)local_108;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)local_108;

      pcVar4 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      pcVar7 = (char *)local_108;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      if ((int *)param_1[0x52f] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x52f] + 0x308))();

      }

    }

    if (param_1[0x52b] != 0) {

      FUN_004c4140();

      sprintf(local_210,"%d");

      (**(code **)(*(int *)param_1[0x52b] + 0x1d8))(local_210,1,1);

      sVar3 = FUN_004c4140();

      iVar8 = *(int *)param_1[0x52b];

      FUN_008f9290();

      (**(code **)(iVar8 + 0x15c))(1);

      (**(code **)(*(int *)param_1[0x52b] + 0x34c))();

      uVar19 = 0xffffffff00a35ca0;

      FUN_007a69d0("Theory:\nHigh level intelligence and education.\nAffects Power Capacity and Exploiting Enemy Resistances.\n\n"

                   ,0xffffffff);

      pcVar7 = (char *)FUN_007a6de0(uVar19);

      pcVar4 = local_210;

      do {

        cVar1 = *pcVar7;

        *pcVar4 = cVar1;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      FUN_007a6de0("Bonus",0xffffffff);

      FUN_007a6de0(&DAT_00a35dc4,0xffffffff);

      sprintf((char *)local_108,"%s: %d\n%s: %+d");

      aiStack_224[0] = (int)sVar3;

      if (sVar3 == 0xfa) {

        pcVar7 = (char *)FUN_007a6de0(" (capped)",0xffffffff);

        pcVar4 = pcVar7;

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar14 = &cStack_109;

        do {

          pcVar12 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar12 != '\0');

        pcVar12 = pcVar7;

        for (uVar10 = (uint)((int)pcVar4 - (int)pcVar7) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar12;

          pcVar12 = pcVar12 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar4 - (int)pcVar7 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar12;

          pcVar12 = pcVar12 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      pcVar4 = (char *)local_108;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)local_108;

      pcVar4 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      fStack_21c = (float)aiStack_224[0];

      pcVar7 = (char *)local_108;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      dVar17 = ceil((double)(fStack_21c + fStack_21c));

      aiStack_224[0] = (int)ROUND(dVar17);

      dVar17 = (double)(fStack_21c * DAT_00a0f720);

      uVar5 = FUN_007a6de0();

      iVar8 = aiStack_224[0];

      uVar6 = FUN_007a6de0("Power Capacity Bonus",0xffffffff);

      sprintf((char *)local_108,"\n\n%s: %+d\n%s: %0.1f%%",uVar6,iVar8,uVar5,dVar17);

      pcVar4 = (char *)local_108;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)local_108;

      pcVar4 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      pcVar7 = (char *)local_108;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      if ((int *)param_1[0x530] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x530] + 0x308))();

      }

    }

    if (param_1[0x52c] != 0) {

      FUN_004c41c0();

      sprintf(local_210,"%d");

      (**(code **)(*(int *)param_1[0x52c] + 0x1d8))(local_210,1,1);

      sVar3 = *(short *)((int)DAT_00d1b6d8 + 0x142);

      if (199 < sVar3) {

        sVar3 = 200;

      }

      iVar13 = (int)sVar3;

      sVar3 = FUN_004c41c0();

      iVar8 = *(int *)param_1[0x52c];

      uVar5 = FUN_008f9290();

      (**(code **)(iVar8 + 0x15c))(1,uVar5);

      (**(code **)(*(int *)param_1[0x52c] + 0x34c))();

      uVar5 = 0xffffffff;

      pcVar4 = 

      "Perception:\nAwareness of your environment.\nAffects Critical Hit % and Defense.\n\n";

      FUN_007a69d0("Perception:\nAwareness of your environment.\nAffects Critical Hit % and Defense.\n\n"

                   ,0xffffffff);

      pcVar4 = (char *)FUN_007a6de0(pcVar4,uVar5);

      piVar9 = aiStack_224;

      do {

        cVar1 = *pcVar4;

        *(char *)piVar9 = cVar1;

        pcVar4 = pcVar4 + 1;

        piVar9 = (int *)((int)piVar9 + 1);

      } while (cVar1 != '\0');

      iVar18 = sVar3 - iVar13;

      uVar5 = FUN_007a6de0("Bonus",0xffffffff);

      iVar8 = iVar13;

      uVar6 = FUN_007a6de0(&DAT_00a35dc4,0xffffffff);

      sprintf(acStack_11c,"%s: %d\n%s: %+d",uVar6,iVar8,uVar5,iVar18);

      iVar13 = (sVar3 - iVar13) + iVar13;

      if (iVar13 == 0xfa) {

        pcVar7 = (char *)FUN_007a6de0(" (capped)",0xffffffff);

        pcVar4 = pcVar7;

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar14 = &cStack_11d;

        do {

          pcVar12 = pcVar14 + 1;

          pcVar14 = pcVar14 + 1;

        } while (*pcVar12 != '\0');

        pcVar12 = pcVar7;

        for (uVar10 = (uint)((int)pcVar4 - (int)pcVar7) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar14 = *(uint32_t /* width from decompiler */ *)pcVar12;

          pcVar12 = pcVar12 + 4;

          pcVar14 = pcVar14 + 4;

        }

        for (uVar10 = (int)pcVar4 - (int)pcVar7 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

          *pcVar14 = *pcVar12;

          pcVar12 = pcVar12 + 1;

          pcVar14 = pcVar14 + 1;

        }

      }

      pcVar4 = acStack_11c;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)acStack_11c;

      pcVar4 = &cStack_225;

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      fVar16 = (float)iVar13;

      pcVar7 = acStack_11c;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 +

                                   (int)DAT_00d1b6d8) + 0x27c))();

      fVar16 = (fVar16 - ((float)iVar8 * DAT_00a0f698 + DAT_00aaaad0)) + DAT_00a0f694;

      (**(code **)(*(int *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 + (int)DAT_00d1b6d8) +

                  0x27c))();

      fVar15 = (float10)FUN_004cd550();

      dVar17 = (double)(fVar15 * (float10)DAT_00aaa7ac);

      uVar5 = FUN_007a6de0();

      fVar15 = (float10)FUN_004c4dd0(uVar5,dVar17,fVar16);

      dVar17 = (double)(fVar15 * (float10)DAT_00aaa7ac);

      uVar5 = FUN_007a6de0("Base Critical Hit Chance",0xffffffff);

      sprintf((char *)local_108,"\n\n%s:\n%0.1f%%\n%s:\n%0.1f%%",uVar5,dVar17);

      pcVar4 = (char *)local_108;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)local_108;

      pcVar4 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      pcVar7 = (char *)local_108;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      uVar5 = FUN_007a6de0("Evasion Rating");

      sprintf((char *)local_108,"\n%s:\n%d",uVar5);

      pcVar4 = (char *)local_108;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar10 = (int)pcVar4 - (int)local_108;

      pcVar4 = (char *)((int)&uStack_214 + 3);

      do {

        pcVar7 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar7 != '\0');

      pcVar7 = (char *)local_108;

      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

        pcVar7 = pcVar7 + 4;

        pcVar4 = pcVar4 + 4;

      }

      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar4 = *pcVar7;

        pcVar7 = pcVar7 + 1;

        pcVar4 = pcVar4 + 1;

      }

      if ((int *)param_1[0x531] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x531] + 0x308))();

      }

    }

    piVar9 = (int *)param_1[0x532];

    if (((piVar9 != (int *)0x0) && (param_1[0x533] != 0)) &&

       ((param_1[0x534] != 0 && (param_1[0x535] != 0)))) {

      bVar2 = *(short *)((int)DAT_00d1b6d8 + 0x6ce) < 1;

      if (!bVar2) {

        FUN_0040de30();

      }

      (**(code **)(*piVar9 + 0xd4))();

      if ((bVar2) || (sVar3 = FUN_0040de10(), 199 < sVar3)) {

        uVar5 = 0;

      }

      else {

        uVar5 = 1;

      }

      (**(code **)(*(int *)param_1[0x533] + 0xd4))(uVar5);

      if ((bVar2) || (sVar3 = FUN_0040ddf0(), 199 < sVar3)) {

        uVar5 = 0;

      }

      else {

        uVar5 = 1;

      }

      (**(code **)(*(int *)param_1[0x534] + 0xd4))(uVar5);

      if (!bVar2) {

        FUN_0040ddd0();

      }

      (**(code **)(*(int *)param_1[0x535] + 0xd4))();

      (**(code **)(*(int *)param_1[0x532] + 0x34c))();

      (**(code **)(*(int *)param_1[0x533] + 0x34c))();

      (**(code **)(*(int *)param_1[0x534] + 0x34c))();

      (**(code **)(*(int *)param_1[0x535] + 0x34c))();

    }

    if (param_1[0x52d] != 0) {

      _itoa((int)*(short *)((int)DAT_00d1b6d8 + 0x6ce),local_210,10);

      (**(code **)(*(int *)param_1[0x52d] + 0x1d8))(local_210,1,1);

      (**(code **)(*(int *)param_1[0x52d] + 0x34c))();

      (**(code **)(*param_1 + 0x450))();

      return;

    }

  }

  (**(code **)(*param_1 + 0x450))();

  return;

}
