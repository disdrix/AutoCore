// =============================================================================
// FUN_0091fd70
// -----------------------------------------------------------------------------
// Stable ID: aa_0091fd70
// Address:   0x0091fd70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091fd70 @ 0x0091fd70
// Stable ID: aa_0091fd70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~179 non-empty decompiler lines.
//  - Control keywords: do×17, while×17, if×8, for×4, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_00404060, FUN_008f8200, FUN_0091fd70, Object_ResolveFromTFID, OutputDebugStringA, __RTDynamicCast.
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

void FUN_0091fd70(void)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  char *pcVar7;

  char *pcVar8;

  uint uVar9;

  uint uVar10;

  int *piVar11;

  char cStack_401;

  char local_400 [4];

  char acStack_3fc [12];

  char acStack_3f0 [1008];

  

  if ((*(int *)(DAT_00d1b644 + 0xe8ec) != 0) &&

     (iVar3 = __RTDynamicCast(DAT_00d1b8dc,0,&CVOGDialog::RTTI_Type_Descriptor,

                              &CDlgChatLog::RTTI_Type_Descriptor,0), iVar3 != 0)) {

    piVar11 = (int *)**(int **)(DAT_00d1b644 + 0xe8e8);

    if (piVar11 != *(int **)(DAT_00d1b644 + 0xe8e8)) {

      do {

        piVar4 = (int *)CVOGReaction_ResolveObjectTarget(0,piVar11[6],piVar11[7]);

        piVar5 = Object_ResolveFromTFID((TFID_16 *)(piVar11 + 2));

        if (piVar4 != (int *)0x0) {

          local_400[0] = '\"';

          local_400[1] = '\0';

          if (*(int *)(piVar4[0x2a] + 0x38) == 0x38) {

            iVar6 = (**(code **)(*piVar4 + 0x1e8))();

            pcVar7 = (char *)(iVar6 + 0xe3);

            pcVar8 = pcVar7;

            do {

              cVar2 = *pcVar8;

              pcVar8 = pcVar8 + 1;

            } while (cVar2 != '\0');

            uVar9 = (int)pcVar8 - (int)pcVar7;

            pcVar8 = &cStack_401;

            do {

              pcVar1 = pcVar8 + 1;

              pcVar8 = pcVar8 + 1;

            } while (*pcVar1 != '\0');

          }

          else if (*(int *)(piVar4[0x2a] + 0x38) == 0x3a) {

            iVar6 = (**(code **)(*piVar4 + 0x1e4))();

            pcVar7 = (char *)(iVar6 + 400);

            pcVar8 = pcVar7;

            do {

              cVar2 = *pcVar8;

              pcVar8 = pcVar8 + 1;

            } while (cVar2 != '\0');

            uVar9 = (int)pcVar8 - (int)pcVar7;

            pcVar8 = &cStack_401;

            do {

              pcVar1 = pcVar8 + 1;

              pcVar8 = pcVar8 + 1;

            } while (*pcVar1 != '\0');

          }

          else {

            pcVar7 = (char *)(**(code **)(*piVar4 + 0x160))();

            pcVar8 = pcVar7;

            do {

              cVar2 = *pcVar8;

              pcVar8 = pcVar8 + 1;

            } while (cVar2 != '\0');

            uVar9 = (int)pcVar8 - (int)pcVar7;

            pcVar8 = &cStack_401;

            do {

              pcVar1 = pcVar8 + 1;

              pcVar8 = pcVar8 + 1;

            } while (*pcVar1 != '\0');

          }

          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

            *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

            pcVar7 = pcVar7 + 4;

            pcVar8 = pcVar8 + 4;

          }

          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

            *pcVar8 = *pcVar7;

            pcVar7 = pcVar7 + 1;

            pcVar8 = pcVar8 + 1;

          }

          pcVar8 = &cStack_401;

          do {

            pcVar7 = pcVar8;

            pcVar8 = pcVar7 + 1;

          } while (pcVar7[1] != '\0');

          *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s___activated_by___00a2fa94._0_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s___activated_by___00a2fa94._4_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar7 + 9) = s___activated_by___00a2fa94._8_4_;

          *(uint32_t /* width from decompiler */ *)(pcVar7 + 0xd) = s___activated_by___00a2fa94._12_4_;

          pcVar7[0x11] = s___activated_by___00a2fa94[0x10];

          if (piVar5 == (int *)0x0) {

            pcVar8 = &cStack_401;

            do {

              pcVar7 = pcVar8;

              pcVar8 = pcVar7 + 1;

            } while (pcVar7[1] != '\0');

            *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = DAT_00a2fa8c;

            pcVar7[5] = DAT_00a2fa90;

          }

          else {

            if (*(int *)(piVar5[0x2a] + 0x38) == 0x38) {

              iVar6 = (**(code **)(*piVar5 + 0x1e8))();

              pcVar7 = (char *)(iVar6 + 0xe3);

              pcVar8 = pcVar7;

              do {

                cVar2 = *pcVar8;

                pcVar8 = pcVar8 + 1;

              } while (cVar2 != '\0');

              uVar9 = (int)pcVar8 - (int)pcVar7;

              pcVar8 = &cStack_401;

              do {

                pcVar1 = pcVar8 + 1;

                pcVar8 = pcVar8 + 1;

              } while (*pcVar1 != '\0');

            }

            else if (*(int *)(piVar5[0x2a] + 0x38) == 0x3a) {

              iVar6 = (**(code **)(*piVar5 + 0x1e4))();

              pcVar7 = (char *)(iVar6 + 400);

              pcVar8 = pcVar7;

              do {

                cVar2 = *pcVar8;

                pcVar8 = pcVar8 + 1;

              } while (cVar2 != '\0');

              uVar9 = (int)pcVar8 - (int)pcVar7;

              pcVar8 = &cStack_401;

              do {

                pcVar1 = pcVar8 + 1;

                pcVar8 = pcVar8 + 1;

              } while (*pcVar1 != '\0');

            }

            else {

              pcVar7 = (char *)(**(code **)(*piVar5 + 0x160))();

              pcVar8 = pcVar7;

              do {

                cVar2 = *pcVar8;

                pcVar8 = pcVar8 + 1;

              } while (cVar2 != '\0');

              uVar9 = (int)pcVar8 - (int)pcVar7;

              pcVar8 = &cStack_401;

              do {

                pcVar1 = pcVar8 + 1;

                pcVar8 = pcVar8 + 1;

              } while (*pcVar1 != '\0');

            }

            for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

              *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

              pcVar7 = pcVar7 + 4;

              pcVar8 = pcVar8 + 4;

            }

            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

              *pcVar8 = *pcVar7;

              pcVar7 = pcVar7 + 1;

              pcVar8 = pcVar8 + 1;

            }

          }

          pcVar8 = &cStack_401;

          do {

            pcVar7 = pcVar8 + 1;

            pcVar8 = pcVar8 + 1;

          } while (*pcVar7 != '\0');

          *(uint16_t *)pcVar8 = DAT_00a2faa8;

          FUN_008f8200(iVar3,6,&DAT_00a1419b,local_400,0);

          pcVar8 = &cStack_401;

          do {

            pcVar7 = pcVar8 + 1;

            pcVar8 = pcVar8 + 1;

          } while (*pcVar7 != '\0');

          *(uint16_t *)pcVar8 = DAT_00a15104;

          OutputDebugStringA(local_400);

        }

        piVar11 = (int *)*piVar11;

      } while (piVar11 != (int *)*(int *)(DAT_00d1b644 + 0xe8e8));

    }

    FUN_00404060();

  }

  return;

}
