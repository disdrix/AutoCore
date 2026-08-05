// =============================================================================
// FUN_00721f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00721f30
// Address:   0x00721f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00721f30 @ 0x00721f30
// Stable ID: aa_00721f30
// Embedded strings (evidence for future rename):
//   - "UpdateForegroundMusic::PlayMusic FAILED: %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~176 non-empty decompiler lines.
//  - Control keywords: if×24, do×4, while×4, goto×3, return×2, for×1.
//  - Notable callees: FUN_0071f810×2, QueryPerformanceCounter×2, Client_GetMissionCompleteAudioTable, FUN_00480560, FUN_0071e820, FUN_0071f760, FUN_0071fed0, FUN_00720720.
//  - Strings: "UpdateForegroundMusic::PlayMusic FAILED: %s\n".
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

int FUN_00721f30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  byte bVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  byte *pbVar9;

  char *pcVar10;

  int *piVar11;

  uint32_t /* width from decompiler */ *puVar12;

  byte *pbVar13;

  char *pcVar14;

  bool bVar15;

  LARGE_INTEGER local_d8;

  int local_d0;

  int local_cc;

  byte abStack_c8 [200];

  

  local_cc = -1;

  local_d0 = 0;

  piVar11 = (int *)(param_1 + 0x80);

  do {

    iVar7 = local_d0;

    if (*piVar11 != 0) {

      iVar6 = FUN_0071f760(1);

      if ((iVar6 == 0) && (iVar6 = *piVar11, *(char *)(iVar6 + 0x3a) == '\0')) {

        if ((iVar6 != 0) && (*(int *)(iVar6 + 0x308) == 4)) {

          *(uint8_t *)(param_1 + 0x18) = 0;

          FUN_0071fed0(param_1);

          *(uint32_t /* width from decompiler */ *)(*piVar11 + 0x308) = 0;

          pcVar10 = "";

          pcVar14 = (char *)(*piVar11 + 0x48);

          do {

            cVar2 = *pcVar10;

            *pcVar14 = cVar2;

            pcVar10 = pcVar10 + 1;

            pcVar14 = pcVar14 + 1;

          } while (cVar2 != '\0');

        }

      }

      else {

        iVar6 = *piVar11;

        if (*(char *)(iVar6 + 0x38) == '\0') {

          *(float *)(iVar6 + 0x1b0) = *(float *)(iVar6 + 0x2e4) * *(float *)(param_1 + 0x20);

        }

        iVar6 = *piVar11;

        if (((*(char *)(iVar6 + 0x1c5) == '\0') || (*(char *)(iVar6 + 0x38) == '\0')) ||

           (0.0 < *(float *)(iVar6 + 0x1a4))) {

          if (iVar6 != 0) {

            if (*(char *)(iVar6 + 0x1c5) != '\0') {

              local_d8.s.LowPart = 0;

              local_d8.s.HighPart = 0;

              local_cc = iVar7;

              QueryPerformanceCounter(&local_d8);

              iVar7 = *piVar11;

              *(DWORD *)(iVar7 + 0x2f8) = local_d8.s.LowPart;

              *(LONG *)(iVar7 + 0x2fc) = local_d8.s.HighPart;

              iVar7 = FUN_0071e820(0);

              if (iVar7 != 0) {

                QueryPerformanceCounter(&local_d8);

                iVar7 = *piVar11;

                *(DWORD *)(iVar7 + 0x2f8) = local_d8.s.LowPart;

                *(LONG *)(iVar7 + 0x2fc) = local_d8.s.HighPart;

                FUN_0071f810();

                if ((uint32_t /* width from decompiler */ *)*piVar11 != (uint32_t /* width from decompiler */ *)0x0) {

                  (*(code *)**(uint32_t /* width from decompiler */ **)*piVar11)(1);

                }

                goto LAB_0072205d;

              }

              iVar7 = *piVar11;

              if ((*(char *)(iVar7 + 0x2f4) != '\0') &&

                 (fVar4 = *(float *)(param_1 + 0x38) - *(float *)(iVar7 + 0x2d8),

                 fVar5 = *(float *)(param_1 + 0x30) - *(float *)(iVar7 + 0x2d0),

                 *(float *)(iVar7 + 0x2ec) < SQRT(fVar4 * fVar4 + fVar5 * fVar5))) {

                *(uint8_t *)(iVar7 + 0x38) = 1;

                *(uint32_t /* width from decompiler */ *)(*piVar11 + 0x1b0) = 0;

              }

            }

            iVar7 = *piVar11;

            if ((iVar7 != 0) && (*(float *)(iVar7 + 0x1a4) != *(float *)(iVar7 + 0x1b0))) {

              FUN_00720f40(param_2);

            }

          }

        }

        else {

          FUN_0071f810();

          if ((uint32_t /* width from decompiler */ *)*piVar11 == (uint32_t /* width from decompiler */ *)0x0) {

LAB_0072205d:

            *piVar11 = 0;

          }

          else {

            (*(code *)**(uint32_t /* width from decompiler */ **)*piVar11)(1);

            *piVar11 = 0;

          }

        }

      }

    }

    local_d0 = local_d0 + 1;

    piVar11 = piVar11 + 1;

  } while (local_d0 < 2);

  iVar7 = 0;

  if (*(int *)(param_1 + 0x54) != 0) {

    iVar6 = *(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x54);

    iVar7 = iVar6 * 0x51eb851f;

    local_d8.s.LowPart = iVar6 / 200;

    if (((local_d8.s.LowPart != 0) && (*(char *)(param_1 + 0x18) == '\0')) &&

       (iVar7 = FUN_00720720(), -1 < iVar7)) {

      iVar6 = iVar7 * 200;

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x54) + iVar6);

      puVar12 = puVar1;

      pbVar13 = abStack_c8;

      for (iVar8 = 0x32; iVar8 != 0; iVar8 = iVar8 + -1) {

        *(uint32_t /* width from decompiler */ *)pbVar13 = *puVar12;

        puVar12 = puVar12 + 1;

        pbVar13 = pbVar13 + 4;

      }

      if ((local_cc != -1) && (local_d0 = *(int *)(param_1 + 0x80 + local_cc * 4), local_d0 != 0)) {

        pbVar13 = abStack_c8;

        pbVar9 = (byte *)(local_d0 + 0x48);

        do {

          bVar3 = *pbVar9;

          bVar15 = bVar3 < *pbVar13;

          if (bVar3 != *pbVar13) {

LAB_007221f4:

            iVar8 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);

            goto LAB_007221f9;

          }

          if (bVar3 == 0) break;

          bVar3 = pbVar9[1];

          bVar15 = bVar3 < pbVar13[1];

          if (bVar3 != pbVar13[1]) goto LAB_007221f4;

          pbVar9 = pbVar9 + 2;

          pbVar13 = pbVar13 + 2;

        } while (bVar3 != 0);

        iVar8 = 0;

LAB_007221f9:

        if ((iVar8 == 0) &&

           ((*(char *)(local_d0 + 0x1c5) != '\0' || (*(char *)(local_d0 + 0x3a) != '\0')))) {

          *(uint8_t *)(local_d0 + 0x38) = 0;

          iVar7 = *(int *)(param_1 + 0x80 + local_cc * 4);

          *(float *)(iVar7 + 0x1b0) = *(float *)(iVar7 + 0x2e4) * *(float *)(param_1 + 0x20);

          return iVar7;

        }

      }

      if (iVar7 != -1) {

        local_d8.s.LowPart = (DWORD)puVar1;

        iVar7 = Client_GetMissionCompleteAudioTable();

        local_d8.s.LowPart._0_1_ = *(uint8_t *)(iVar7 + 0x25a);

        iVar8 = FUN_00721a80(puVar1,local_d8.s.LowPart,0);

        iVar7 = 0;

        if (iVar8 != 0) {

          if (puVar1[0x2e] == 4) {

            *(uint8_t *)(param_1 + 0x18) = 0;

          }

          pcVar14 = *(char **)(param_1 + 0x54);

          if (pcVar14 != *(char **)(param_1 + 0x58)) {

            do {

              iVar7 = _stricmp(pcVar14,(char *)(*(int *)(param_1 + 0x54) + iVar6));

              if (iVar7 == 0) {

                FUN_00480560(&local_d8,pcVar14);

                break;

              }

              pcVar14 = pcVar14 + 200;

            } while (pcVar14 != *(char **)(param_1 + 0x58));

          }

          iVar7 = FUN_007a4480(0,"UpdateForegroundMusic::PlayMusic FAILED: %s\n",

                               *(int *)(param_1 + 0x54) + iVar6);

        }

      }

    }

  }

  return iVar7;

}
