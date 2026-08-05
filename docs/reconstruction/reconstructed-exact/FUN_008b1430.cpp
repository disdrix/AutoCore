// =============================================================================
// FUN_008b1430
// -----------------------------------------------------------------------------
// Stable ID: aa_008b1430
// Address:   0x008b1430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b1430 @ 0x008b1430
// Stable ID: aa_008b1430
// Embedded strings (evidence for future rename):
//   - "Contested "
//   - "%s %d"
//   - "%s %d %d/%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×10, do×6, while×6, for×4, return×2.
//  - Notable callees: FUN_007a6de0×3, sprintf×3, CNDHash_LookupByKey, FUN_00541a80, FUN_007a69d0, FUN_008b1430.
//  - Strings: "*%s"; "Contested "; "%s %d"; "%s %d %d/%d".
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

void FUN_008b1430(void)



{

  char cVar1;

  void *pvVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  int iVar7;

  int *unaff_EBX;

  int iVar8;

  char *pcVar9;

  char *pcVar10;

  char *pcVar11;

  int iStack_194;

  int iStack_18c;

  char acStack_184 [127];

  char acStack_105 [261];

  

  iVar8 = 0;

  if ((((DAT_00d1b6d8 != 0) && (unaff_EBX[0x149] != 0)) &&

      (cVar1 = (**(code **)(*unaff_EBX + 0x3d8))(), cVar1 != '\0')) &&

     ((DAT_00d1b644 != 0 && (*(int *)(DAT_00d1b644 + 0xe50c) != 0)))) {

    (**(code **)(*(int *)unaff_EBX[0x149] + 0x450))();

    uVar6 = *(uint *)(DAT_00d1b644 + 0xfc);

    pvVar2 = (void *)FUN_00541a80();

    pvVar2 = CNDHash_LookupByKey(pvVar2,uVar6);

    if (pvVar2 != (void *)0x0) {

      iStack_18c = *(int *)((int)pvVar2 + 0x144);

      if (iStack_18c == 0) {

        iStack_18c = 0x32;

      }

      FUN_007a69d0();

      if (DAT_00d1b4a8 < 1) {

        uVar5 = FUN_007a6de0(*(int *)(DAT_00d1b644 + 0xe50c) + 0xc,0xffffffff);

        sprintf(acStack_184,"*%s",uVar5);

        (**(code **)(*(int *)unaff_EBX[0x149] + 0x448))(acStack_184);

      }

      else {

        iStack_194 = 0;

        iVar4 = DAT_00d1b6d8;

        iVar7 = DAT_00d1b4ac;

        do {

          if ((*(int *)(iVar7 + 0xc + iVar8) < iStack_18c) || (0 < *(int *)(iVar4 + 0x6b4))) {

            acStack_105[1] = 0;

            iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa8 + iVar4);

            if ((*(int *)(iVar7 + iVar8) == *(int *)(iVar4 + 0x948)) &&

               (*(int *)(iVar7 + 4 + iVar8) == *(int *)(iVar4 + 0x94c))) {

              pcVar10 = acStack_105;

              do {

                pcVar3 = pcVar10 + 1;

                pcVar10 = pcVar10 + 1;

              } while (*pcVar3 != '\0');

              *(uint16_t *)pcVar10 = DAT_00a49ce8;

            }

            if (*(char *)(iVar7 + 0x10 + iVar8) != '\0') {

              pcVar3 = (char *)FUN_007a6de0("Contested ",0xffffffff);

              pcVar10 = pcVar3;

              do {

                cVar1 = *pcVar10;

                pcVar10 = pcVar10 + 1;

              } while (cVar1 != '\0');

              pcVar11 = acStack_105;

              do {

                pcVar9 = pcVar11 + 1;

                pcVar11 = pcVar11 + 1;

              } while (*pcVar9 != '\0');

              pcVar9 = pcVar3;

              for (uVar6 = (uint)((int)pcVar10 - (int)pcVar3) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

                *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

                pcVar9 = pcVar9 + 4;

                pcVar11 = pcVar11 + 4;

              }

              for (uVar6 = (int)pcVar10 - (int)pcVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

                *pcVar11 = *pcVar9;

                pcVar9 = pcVar9 + 1;

                pcVar11 = pcVar11 + 1;

              }

            }

            pcVar3 = (char *)FUN_007a6de0(*(int *)(DAT_00d1b644 + 0xe50c) + 0xc,0xffffffff);

            pcVar10 = pcVar3;

            do {

              cVar1 = *pcVar10;

              pcVar10 = pcVar10 + 1;

            } while (cVar1 != '\0');

            pcVar11 = acStack_105;

            do {

              pcVar9 = pcVar11 + 1;

              pcVar11 = pcVar11 + 1;

            } while (*pcVar9 != '\0');

            pcVar9 = pcVar3;

            for (uVar6 = (uint)((int)pcVar10 - (int)pcVar3) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

              *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

              pcVar9 = pcVar9 + 4;

              pcVar11 = pcVar11 + 4;

            }

            for (uVar6 = (int)pcVar10 - (int)pcVar3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

              *pcVar11 = *pcVar9;

              pcVar9 = pcVar9 + 1;

              pcVar11 = pcVar11 + 1;

            }

            if (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1) {

              sprintf(acStack_184,"%s %d",acStack_105 + 1,iStack_194);

            }

            else {

              sprintf(acStack_184,"%s %d %d/%d",acStack_105 + 1,iStack_194,

                      *(uint32_t /* width from decompiler */ *)(DAT_00d1b4ac + 0xc + iVar8),iStack_18c);

            }

            iVar4 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8);

            if ((*(int *)(DAT_00d1b4ac + iVar8) == *(int *)(iVar4 + 0x948)) &&

               (*(int *)(DAT_00d1b4ac + 4 + iVar8) == *(int *)(iVar4 + 0x94c))) {

              (**(code **)(*(int *)unaff_EBX[0x149] + 0x448))(acStack_184);

              iVar4 = DAT_00d1b6d8;

              iVar7 = DAT_00d1b4ac;

            }

            else {

              (**(code **)(*(int *)unaff_EBX[0x149] + 0x448))(acStack_184);

              iVar4 = DAT_00d1b6d8;

              iVar7 = DAT_00d1b4ac;

            }

          }

          iStack_194 = iStack_194 + 1;

          iVar8 = iVar8 + 0x18;

        } while (iStack_194 < DAT_00d1b4a8);

      }

      (**(code **)(*(int *)unaff_EBX[0x149] + 0x460))(0);

      iVar8 = (**(code **)(*(int *)unaff_EBX[0x149] + 0x464))();

      unaff_EBX[0x14d] = iVar8;

      if (iStack_194 == -1) {

        (**(code **)(*(int *)unaff_EBX[0x149] + 0x460))(0);

        return;

      }

      (**(code **)(*(int *)unaff_EBX[0x149] + 0x45c))(iStack_194);

    }

  }

  return;

}
