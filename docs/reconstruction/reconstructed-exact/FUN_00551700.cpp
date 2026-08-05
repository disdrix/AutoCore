// =============================================================================
// FUN_00551700
// -----------------------------------------------------------------------------
// Stable ID: aa_00551700
// Address:   0x00551700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00551700 @ 0x00551700
// Stable ID: aa_00551700
// Embedded strings (evidence for future rename):
//   - "Must be Stealthed\n"
//   - "Cooldown"
//   - "%g %s %s\n"
//   - "Duration"
//   - "Power every"
//   - "%d %s %g %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~490 non-empty decompiler lines.
//  - Control keywords: if×38, do×20, while×20, for×17, goto×8, return×2.
//  - Notable callees: FUN_007a6de0×38, FUN_00412c60×19, SUB84×10, sprintf×10, FUN_00551700, FUN_007a69d0.
//  - Strings: "Must be Stealthed\n"; "Cooldown"; "%g %s %s\n"; "Duration".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



char __thiscall FUN_00551700(int param_1,int param_2)



{

  byte bVar1;

  char cVar2;

  short sVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iVar10;

  uint uVar11;

  uint uVar12;

  int iVar13;

  char *pcVar14;

  char *pcVar15;

  float10 fVar16;

  float fVar17;

  double dVar18;

  char local_415;

  char local_408 [2];

  uint32_t /* width from decompiler */ local_406 [256];

  

  FUN_007a69d0();

  bVar1 = *(byte *)(param_1 + 0x615);

  local_408[0] = '\0';

  local_408[1] = '\0';

  pcVar6 = local_408 + 2;

  for (iVar10 = 0xff; iVar10 != 0; iVar10 = iVar10 + -1) {

    pcVar6[0] = '\0';

    pcVar6[1] = '\0';

    pcVar6[2] = '\0';

    pcVar6[3] = '\0';

    pcVar6 = pcVar6 + 4;

  }

  local_415 = '\0';

  pcVar6[0] = '\0';

  pcVar6[1] = '\0';

  if ((bVar1 & 0x40) != 0) {

    pcVar5 = (char *)FUN_007a6de0("Must be Stealthed\n",0xffffffff);

    pcVar6 = pcVar5;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    pcVar15 = (char *)(param_2 + -1);

    do {

      pcVar14 = pcVar15 + 1;

      pcVar15 = pcVar15 + 1;

    } while (*pcVar14 != '\0');

    pcVar14 = pcVar5;

    for (uVar11 = (uint)((int)pcVar6 - (int)pcVar5) >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar15 = *(uint32_t /* width from decompiler */ *)pcVar14;

      pcVar14 = pcVar14 + 4;

      pcVar15 = pcVar15 + 4;

    }

    for (uVar11 = (int)pcVar6 - (int)pcVar5 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

      *pcVar15 = *pcVar14;

      pcVar14 = pcVar14 + 1;

      pcVar15 = pcVar15 + 1;

    }

    local_415 = '\x01';

  }

  if ((*(byte *)(param_1 + 0x615) & 1) != 0) goto LAB_00551e71;

  iVar10 = *(int *)(param_1 + 0x10);

  if (iVar10 != 0) {

    uVar7 = FUN_007a6de0("Cooldown",0xffffffff);

    if (iVar10 < 86400000) {

      if (iVar10 < 3600000) {

        if (iVar10 < 60000) {

          uVar8 = FUN_007a6de0(&DAT_00a69f58,0xffffffff);

          fVar17 = (float)iVar10 * g_flMsToSeconds_Inferred;

          goto LAB_0055185e;

        }

        uVar7 = FUN_007a6de0(&DAT_00a71bc8,0xffffffff);

        fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a0,uVar7);

        dVar18 = (double)fVar16;

      }

      else {

        uVar7 = FUN_007a6de0(&DAT_009d21a8,0xffffffff);

        fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a4,uVar7);

        dVar18 = (double)fVar16;

      }

    }

    else {

      uVar8 = FUN_007a6de0(&DAT_009d21bc,0xffffffff);

      fVar17 = (float)iVar10 * _DAT_009d21b8;

LAB_0055185e:

      fVar16 = (float10)FUN_00412c60(fVar17,uVar8,uVar7);

      dVar18 = (double)fVar16;

    }

    sprintf(local_408,"%g %s %s\n",SUB84(dVar18,0),(int)((ulonglong)dVar18 >> 0x20));

    pcVar6 = local_408;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    uVar11 = (int)pcVar6 - (int)local_408;

    pcVar6 = (char *)(param_2 + -1);

    do {

      pcVar5 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = local_408;

    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar6 = pcVar6 + 4;

    }

    local_415 = local_415 + '\x01';

    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

      *pcVar6 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar6 = pcVar6 + 1;

    }

  }

  iVar10 = *(int *)(param_1 + 0x18);

  if ((iVar10 == 0) || ((iVar10 != -1000 && ((iVar10 == 0 || (iVar10 < 2)))))) {

    iVar10 = *(int *)(param_1 + 0x1c);

    if (iVar10 < 1) goto LAB_00551e71;

    uVar7 = FUN_007a6de0("Duration",0xffffffff);

    if (iVar10 < 86400000) {

      if (iVar10 < 3600000) {

        if (iVar10 < 60000) {

          uVar8 = FUN_007a6de0(&DAT_00a69f58,0xffffffff);

          fVar17 = (float)iVar10 * g_flMsToSeconds_Inferred;

          goto LAB_005519a4;

        }

        uVar7 = FUN_007a6de0(&DAT_00a71bc8,0xffffffff);

        fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a0,uVar7);

        dVar18 = (double)fVar16;

      }

      else {

        uVar7 = FUN_007a6de0(&DAT_009d21a8,0xffffffff);

        fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a4,uVar7);

        dVar18 = (double)fVar16;

      }

    }

    else {

      uVar8 = FUN_007a6de0(&DAT_009d21bc,0xffffffff);

      fVar17 = (float)iVar10 * _DAT_009d21b8;

LAB_005519a4:

      fVar16 = (float10)FUN_00412c60(fVar17,uVar8,uVar7);

      dVar18 = (double)fVar16;

    }

    sprintf(local_408,"%g %s %s\n",SUB84(dVar18,0),(int)((ulonglong)dVar18 >> 0x20));

    pcVar6 = local_408;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    uVar11 = (int)pcVar6 - (int)local_408;

    pcVar6 = (char *)(param_2 + -1);

    do {

      pcVar5 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

    } while (*pcVar5 != '\0');

  }

  else {

    sVar3 = *(short *)(param_1 + 10);

    if (sVar3 == 0) goto LAB_00551e71;

    if (iVar10 == -1000) {

      iVar10 = *(int *)(param_1 + 0x1c);

      if (iVar10 < 1) goto LAB_00551e71;

      if (iVar10 < 86400000) {

        if (iVar10 < 3600000) {

          if (iVar10 < 60000) {

            uVar7 = FUN_007a6de0(&DAT_00a69f58,0xffffffff);

            fVar17 = (float)iVar10 * g_flMsToSeconds_Inferred;

            goto LAB_00551aef;

          }

          uVar7 = FUN_007a6de0(&DAT_00a71bc8,0xffffffff);

          fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a0,uVar7);

          dVar18 = (double)fVar16;

          uVar7 = FUN_007a6de0("Power every",0xffffffff);

        }

        else {

          uVar7 = FUN_007a6de0(&DAT_009d21a8,0xffffffff);

          fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a4,uVar7);

          dVar18 = (double)fVar16;

          uVar7 = FUN_007a6de0("Power every",0xffffffff);

        }

      }

      else {

        uVar7 = FUN_007a6de0(&DAT_009d21bc,0xffffffff);

        fVar17 = (float)iVar10 * _DAT_009d21b8;

LAB_00551aef:

        fVar16 = (float10)FUN_00412c60(fVar17,uVar7);

        dVar18 = (double)fVar16;

        uVar7 = FUN_007a6de0("Power every",0xffffffff);

      }

      sprintf(local_408,"%d %s %g %s\n",(int)sVar3,uVar7,SUB84(dVar18,0),

              (int)((ulonglong)dVar18 >> 0x20));

      pcVar6 = local_408;

      do {

        cVar2 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar2 != '\0');

      uVar11 = (int)pcVar6 - (int)local_408;

      pcVar6 = (char *)(param_2 + -1);

      do {

        pcVar5 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar5 != '\0');

    }

    else {

      iVar10 = *(int *)(param_1 + 0x1c);

      if (iVar10 < 86400000) {

        if (iVar10 < 3600000) {

          if (iVar10 < 60000) {

            uVar7 = FUN_007a6de0(&DAT_00a69f58,0xffffffff);

            fVar17 = (float)iVar10 * g_flMsToSeconds_Inferred;

            goto LAB_00551c2d;

          }

          uVar7 = FUN_007a6de0(&DAT_00a71bc8,0xffffffff);

          fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a0,uVar7);

          dVar18 = (double)fVar16;

          uVar7 = FUN_007a6de0("Power every",0xffffffff);

        }

        else {

          uVar7 = FUN_007a6de0(&DAT_009d21a8,0xffffffff);

          fVar16 = (float10)FUN_00412c60((float)iVar10 * _DAT_009d21a4,uVar7);

          dVar18 = (double)fVar16;

          uVar7 = FUN_007a6de0("Power every",0xffffffff);

        }

      }

      else {

        uVar7 = FUN_007a6de0(&DAT_009d21bc,0xffffffff);

        fVar17 = (float)iVar10 * _DAT_009d21b8;

LAB_00551c2d:

        fVar16 = (float10)FUN_00412c60(fVar17,uVar7);

        dVar18 = (double)fVar16;

        uVar7 = FUN_007a6de0("Power every",0xffffffff);

      }

      sprintf(local_408,"%d %s %g %s\n",(int)sVar3,uVar7,SUB84(dVar18,0),

              (int)((ulonglong)dVar18 >> 0x20));

      pcVar6 = local_408;

      do {

        cVar2 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar2 != '\0');

      uVar11 = (int)pcVar6 - (int)local_408;

      pcVar6 = (char *)(param_2 + -1);

      do {

        pcVar5 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar5 != '\0');

      local_415 = local_415 + '\x01';

      pcVar5 = local_408;

      for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar6 = pcVar6 + 4;

      }

      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

        *pcVar6 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar6 = pcVar6 + 1;

      }

      iVar10 = *(int *)(param_1 + 0x18);

      iVar13 = iVar10;

      if (iVar10 == 0) {

        iVar13 = 1;

      }

      iVar4 = *(int *)(param_1 + 0x1c);

      if (iVar4 * iVar13 < 86400000) {

        iVar13 = iVar10;

        if (iVar10 == 0) {

          iVar13 = 1;

        }

        if (iVar4 * iVar13 < 3600000) {

          iVar13 = iVar10;

          if (iVar10 == 0) {

            iVar13 = 1;

          }

          if (iVar4 * iVar13 < 60000) {

            if (iVar10 == 0) {

              iVar10 = 1;

            }

            uVar7 = FUN_007a6de0("Duration",0xffffffff);

            uVar8 = FUN_007a6de0(&DAT_00a69f58,0xffffffff);

            fVar16 = (float10)FUN_00412c60((float)(iVar10 * iVar4) * g_flMsToSeconds_Inferred,uVar8,

                                           uVar7);

            dVar18 = (double)fVar16;

          }

          else {

            if (iVar10 == 0) {

              iVar10 = 1;

            }

            uVar7 = FUN_007a6de0("Duration",0xffffffff);

            uVar8 = FUN_007a6de0(&DAT_00a71bc8,0xffffffff);

            fVar16 = (float10)FUN_00412c60((float)(iVar10 * iVar4) * _DAT_009d21a0,uVar8,uVar7);

            dVar18 = (double)fVar16;

          }

        }

        else {

          if (iVar10 == 0) {

            iVar10 = 1;

          }

          uVar7 = FUN_007a6de0("Duration",0xffffffff);

          uVar8 = FUN_007a6de0(&DAT_009d21a8,0xffffffff);

          fVar16 = (float10)FUN_00412c60((float)(iVar10 * iVar4) * _DAT_009d21a4,uVar8,uVar7);

          dVar18 = (double)fVar16;

        }

      }

      else {

        if (iVar10 == 0) {

          iVar10 = 1;

        }

        uVar7 = FUN_007a6de0("Duration",0xffffffff);

        uVar8 = FUN_007a6de0(&DAT_009d21bc,0xffffffff);

        fVar16 = (float10)FUN_00412c60((float)(iVar10 * iVar4) * _DAT_009d21b8,uVar8,uVar7);

        dVar18 = (double)fVar16;

      }

      sprintf(local_408,"%g %s %s\n",SUB84(dVar18,0),(int)((ulonglong)dVar18 >> 0x20));

      pcVar6 = local_408;

      do {

        cVar2 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar2 != '\0');

      uVar11 = (int)pcVar6 - (int)local_408;

      pcVar6 = (char *)(param_2 + -1);

      do {

        pcVar5 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar5 != '\0');

    }

  }

  pcVar5 = local_408;

  for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

    pcVar5 = pcVar5 + 4;

    pcVar6 = pcVar6 + 4;

  }

  local_415 = local_415 + '\x01';

  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

    *pcVar6 = *pcVar5;

    pcVar5 = pcVar5 + 1;

    pcVar6 = pcVar6 + 1;

  }

LAB_00551e71:

  if (*(float *)(param_1 + 0x28) != 0.0) {

    if (*(float *)(param_1 + 0x2c) == 0.0) {

      uVar7 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

      uVar8 = FUN_007a6de0("Range",0xffffffff);

      fVar16 = (float10)FUN_00412c60(uVar7,uVar8);

      sprintf(local_408,"%g m %s\n",SUB84((double)fVar16,0),(int)((ulonglong)(double)fVar16 >> 0x20)

             );

    }

    else {

      uVar7 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

      uVar8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

      uVar9 = FUN_007a6de0("Range",0xffffffff);

      fVar16 = (float10)FUN_00412c60(uVar7,uVar9);

      fVar16 = (float10)FUN_00412c60(uVar8,(double)fVar16);

      sprintf(local_408,"%g-%g m %s\n",SUB84((double)fVar16,0),

              (int)((ulonglong)(double)fVar16 >> 0x20));

    }

    pcVar6 = local_408;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    uVar11 = (int)pcVar6 - (int)local_408;

    pcVar6 = (char *)(param_2 + -1);

    do {

      pcVar5 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = local_408;

    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar6 = pcVar6 + 4;

    }

    local_415 = local_415 + '\x01';

    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

      *pcVar6 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar6 = pcVar6 + 1;

    }

  }

  if (0.0 < *(float *)(param_1 + 0x30)) {

    fVar17 = *(float *)(param_1 + 0x30) * DAT_00a110d8;

    if (0.0 <= fVar17) {

      fVar17 = fVar17 + g_flMissionXpRoundBias;

    }

    else {

      fVar17 = fVar17 - g_flMissionXpRoundBias;

    }

    uVar7 = FUN_007a6de0("Maintain Limit",0xffffffff);

    sprintf(local_408,"%g m %s\n",SUB84((double)((float)(int)fVar17 * g_flMultiKillCountBlend),0),

            (int)((ulonglong)(double)((float)(int)fVar17 * g_flMultiKillCountBlend) >> 0x20),uVar7);

    pcVar6 = local_408;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    uVar11 = (int)pcVar6 - (int)local_408;

    pcVar6 = (char *)(param_2 + -1);

    do {

      pcVar5 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = local_408;

    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar6 = pcVar6 + 4;

    }

    local_415 = local_415 + '\x01';

    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

      *pcVar6 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar6 = pcVar6 + 1;

    }

  }

  if (0.0 < *(float *)(param_1 + 0x38)) {

    fVar17 = *(float *)(param_1 + 0x38) * DAT_00a110d8;

    if (0.0 <= fVar17) {

      fVar17 = fVar17 + g_flMissionXpRoundBias;

    }

    else {

      fVar17 = fVar17 - g_flMissionXpRoundBias;

    }

    uVar7 = FUN_007a6de0("Splash",0xffffffff);

    sprintf(local_408,"%g m %s\n",SUB84((double)((float)(int)fVar17 * g_flMultiKillCountBlend),0),

            (int)((ulonglong)(double)((float)(int)fVar17 * g_flMultiKillCountBlend) >> 0x20),uVar7);

    pcVar6 = local_408;

    do {

      cVar2 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    uVar11 = (int)pcVar6 - (int)local_408;

    pcVar6 = (char *)(param_2 + -1);

    do {

      pcVar5 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = local_408;

    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar6 = pcVar6 + 4;

    }

    local_415 = local_415 + '\x01';

    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

      *pcVar6 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar6 = pcVar6 + 1;

    }

  }

  if (*(float *)(param_1 + 0xe4) == 0.0) {

    return local_415;

  }

  fVar17 = *(float *)(param_1 + 0xe4) * DAT_00a0f520;

  if (0.0 <= fVar17) {

    fVar17 = fVar17 + g_flMissionXpRoundBias;

  }

  else {

    fVar17 = fVar17 - g_flMissionXpRoundBias;

  }

  uVar7 = FUN_007a6de0("Chance",0xffffffff);

  sprintf(local_408,"%g%% %s\n",SUB84((double)((float)(int)fVar17 * g_flMultiKillCountBlend),0),

          (int)((ulonglong)(double)((float)(int)fVar17 * g_flMultiKillCountBlend) >> 0x20),uVar7);

  pcVar6 = local_408;

  do {

    cVar2 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar2 != '\0');

  uVar11 = (int)pcVar6 - (int)local_408;

  pcVar6 = (char *)(param_2 + -1);

  do {

    pcVar5 = pcVar6 + 1;

    pcVar6 = pcVar6 + 1;

  } while (*pcVar5 != '\0');

  pcVar5 = local_408;

  for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

    pcVar5 = pcVar5 + 4;

    pcVar6 = pcVar6 + 4;

  }

  for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {

    *pcVar6 = *pcVar5;

    pcVar5 = pcVar5 + 1;

    pcVar6 = pcVar6 + 1;

  }

  return local_415 + '\x01';

}
