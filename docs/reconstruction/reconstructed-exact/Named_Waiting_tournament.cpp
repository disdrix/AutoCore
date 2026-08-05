// =============================================================================
// Named_Waiting_tournament
// -----------------------------------------------------------------------------
// Stable ID: aa_0086a2d0
// Address:   0x0086a2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Waiting_tournament @ 0x0086a2d0
// Stable ID: aa_0086a2d0
// Embedded strings (evidence for future rename):
//   - "Waiting for tournament"
//   - "registered"
//   - "%s\n(%d %s)"
//   - "Your team has a bye. Waiting for next round."
//   - "registered, Round"
//   - "%s\n(%d %s %d/%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~208 non-empty decompiler lines.
//  - Control keywords: if×20, do×11, while×11, for×7, goto×5, return×2.
//  - Notable callees: FUN_007a6de0×11, sprintf×4, FUN_00791f30×2, n×2, FUN_007a69d0, FUN_007fcdd0, Named_Waiting_tournament, SQRT.
//  - Strings: "Waiting for tournament"; "registered"; "%s\n(%d %s)"; "Your team has a bye. Waiting for next round.".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Waiting for tournament"
 * Domain alias of FUN_0086a2d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_Waiting_tournament(int *param_1,float param_2)



{

  char *pcVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int *piVar6;

  char *pcVar7;

  uint uVar8;

  float *pfVar9;

  uint uVar10;

  int iVar11;

  longlong lVar12;

  char *pcVar13;

  char cStack_511;

  char acStack_510 [256];

  char acStack_410 [1036];

  

  param_1[0x149] = (int)(param_2 + (float)param_1[0x149]);

  param_1[0x148] = (int)(param_2 + (float)param_1[0x148]);

  if ((int *)param_1[0x16d] != (int *)0x0) {

    lVar12 = (**(code **)(*(int *)param_1[0x16d] + 0x44c))();

    piVar6 = (int *)param_1[0x167];

    if (lVar12 == -1) {

      if ((piVar6 != (int *)0x0) && (cVar2 = (**(code **)(*piVar6 + 0xd8))(), cVar2 != '\0')) {

        (**(code **)(*(int *)param_1[0x167] + 0xd4))(0);

        (**(code **)(*(int *)param_1[0x167] + 0x34c))();

      }

      if (((int *)param_1[0x18b] != (int *)0x0) &&

         (cVar2 = (**(code **)(*(int *)param_1[0x18b] + 0xd8))(), cVar2 != '\0')) {

        (**(code **)(*(int *)param_1[0x18b] + 0xd4))(0);

        (**(code **)(*(int *)param_1[0x18b] + 0x34c))();

      }

    }

    else if ((piVar6 != (int *)0x0) && (cVar2 = (**(code **)(*piVar6 + 0xd8))(), cVar2 == '\0')) {

      (**(code **)(*(int *)param_1[0x167] + 0xd4))(1);

      (**(code **)(*(int *)param_1[0x167] + 0x34c))();

    }

  }

  if (((char)param_1[0x14a] == '\0') || (param_1[400] == 0)) {

    param_1[0x143] = (int)(param_2 + (float)param_1[0x143]);

    cVar2 = (**(code **)(*param_1 + 0x3d8))();

    if ((cVar2 != '\0') &&

       (((g_flOne < (float)param_1[0x143] && (DAT_00d1b6d8 != 0)) &&

        (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)))) {

      param_1[0x143] = 0;

      pfVar9 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                             DAT_00d1b6d8) + 0x1a0))();

      if (DAT_00aaa6fc <

          SQRT((*pfVar9 - (float)param_1[0x144]) * (*pfVar9 - (float)param_1[0x144]) +

               (pfVar9[1] - (float)param_1[0x145]) * (pfVar9[1] - (float)param_1[0x145]) +

               (pfVar9[2] - (float)param_1[0x146]) * (pfVar9[2] - (float)param_1[0x146]))) {

        FUN_007fcdd0(&DAT_00d1a840,0x28);

      }

    }

    FUN_00791f30(param_2);

    return;

  }

  FUN_007a69d0();

  uVar8 = param_1[0x154];

  if ((uVar8 == 0) || (uVar8 == 0x7fffffff)) {

    if (param_1[0x156] == 0) {

      pcVar7 = (char *)FUN_007a6de0("Waiting for tournament",0xffffffff);

      pcVar13 = acStack_510;

      do {

        cVar2 = *pcVar7;

        *pcVar13 = cVar2;

        pcVar7 = pcVar7 + 1;

        pcVar13 = pcVar13 + 1;

      } while (cVar2 != '\0');

    }

    else if (*(short *)((int)param_1 + 0x55e) == 0) {

      uVar3 = FUN_007a6de0("registered",0xffffffff);

      iVar5 = param_1[0x156];

      uVar4 = FUN_007a6de0("Waiting for tournament",0xffffffff);

      sprintf(acStack_510,"%s\n(%d %s)",uVar4,iVar5,uVar3);

    }

    else {

      if (uVar8 == 0x7fffffff) {

        pcVar7 = (char *)FUN_007a6de0("Your team has a bye. Waiting for next round.",0xffffffff);

        pcVar13 = acStack_410;

        do {

          cVar2 = *pcVar7;

          *pcVar13 = cVar2;

          pcVar7 = pcVar7 + 1;

          pcVar13 = pcVar13 + 1;

        } while (cVar2 != '\0');

      }

      else {

        pcVar7 = (char *)FUN_007a6de0("Waiting for tournament",0xffffffff);

        pcVar13 = acStack_410;

        do {

          cVar2 = *pcVar7;

          *pcVar13 = cVar2;

          pcVar7 = pcVar7 + 1;

          pcVar13 = pcVar13 + 1;

        } while (cVar2 != '\0');

      }

      uVar8 = (uint)*(ushort *)((int)param_1 + 0x55e);

      iVar5 = *(ushort *)(param_1 + 0x157) + 1;

      uVar3 = FUN_007a6de0("registered, Round",0xffffffff);

      sprintf(acStack_510,"%s\n(%d %s %d/%d)",acStack_410,param_1[0x156],uVar3,iVar5,uVar8);

    }

  }

  else {

    if (uVar8 < 2) {

      pcVar13 = "player";

    }

    else {

      pcVar13 = "players";

    }

    uVar3 = FUN_007a6de0(pcVar13,0xffffffff);

    iVar5 = param_1[0x154];

    uVar4 = FUN_007a6de0("Waiting for",0xffffffff);

    sprintf(acStack_510,"%s %d %s",uVar4,iVar5,uVar3);

  }

  if ((param_1[0x155] != -1) && (piVar6 = *(int **)param_1[0x159], piVar6 != (int *)param_1[0x159]))

  {

LAB_0086a570:

    if (*(int *)piVar6[2] != param_1[0x155]) goto code_r0x0086a577;

    if (*(int *)(piVar6[2] + 0x2e8) < DAT_00b04590) {

      pcVar13 = (char *)FUN_007a6de0("starting soon!",0xffffffff);

      pcVar7 = pcVar13;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      uVar8 = (int)pcVar7 - (int)pcVar13;

      pcVar7 = &cStack_511;

      do {

        pcVar1 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar1 != '\0');

    }

    else {

      iVar11 = *(int *)(piVar6[2] + 0x2e8) - DAT_00b04590;

      uVar3 = FUN_007a6de0("minutes left",0xffffffff);

      iVar5 = (iVar11 % 0xe10) / 0x3c;

      uVar4 = FUN_007a6de0("hours",0xffffffff);

      sprintf(acStack_410,"%d %s %d %s",iVar11 / 0xe10,uVar4,iVar5,uVar3);

      pcVar13 = acStack_410;

      pcVar7 = pcVar13;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      uVar8 = (int)pcVar7 - (int)pcVar13;

      pcVar7 = &cStack_511;

      do {

        pcVar1 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar1 != '\0');

    }

    for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar13;

      pcVar13 = pcVar13 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

      *pcVar7 = *pcVar13;

      pcVar13 = pcVar13 + 1;

      pcVar7 = pcVar7 + 1;

    }

  }

LAB_0086a67b:

  uVar8 = (int)((float)param_1[0x149] * DAT_00aaa9f0) & 0x7f;

  pcVar13 = &cStack_511;

  if (uVar8 < 0x20) {

    do {

      pcVar7 = pcVar13 + 1;

      pcVar13 = pcVar13 + 1;

      uVar3 = DAT_00a5a678;

    } while (*pcVar7 != '\0');

  }

  else {

    if (uVar8 < 0x40) {

      do {

        pcVar7 = pcVar13 + 1;

        pcVar13 = pcVar13 + 1;

      } while (*pcVar7 != '\0');

      *(uint32_t /* width from decompiler */ *)pcVar13 = DAT_00a5a674;

      goto LAB_0086a6f6;

    }

    if (uVar8 < 0x60) {

      do {

        pcVar7 = pcVar13 + 1;

        pcVar13 = pcVar13 + 1;

      } while (*pcVar7 != '\0');

      *(uint32_t /* width from decompiler */ *)pcVar13 = DAT_00a5a670;

      goto LAB_0086a6f6;

    }

    do {

      pcVar7 = pcVar13 + 1;

      pcVar13 = pcVar13 + 1;

      uVar3 = DAT_00a5a66c;

    } while (*pcVar7 != '\0');

  }

  *(uint32_t /* width from decompiler */ *)pcVar13 = uVar3;

LAB_0086a6f6:

  (**(code **)(*(int *)param_1[400] + 0x1d8))(acStack_510,1,1);

  (**(code **)(*(int *)param_1[400] + 0x34c))();

  FUN_00791f30(param_2);

  return;

code_r0x0086a577:

  piVar6 = (int *)*piVar6;

  if (piVar6 == (int *)param_1[0x159]) goto LAB_0086a67b;

  goto LAB_0086a570;

}
