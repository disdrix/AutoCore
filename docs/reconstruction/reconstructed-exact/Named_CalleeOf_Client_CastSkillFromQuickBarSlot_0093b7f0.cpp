// =============================================================================
// Named_CalleeOf_Client_CastSkillFromQuickBarSlot_0093b7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093b7f0
// Callee of Client_CastSkillFromQuickBarSlot
// Address:   0x0093b7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_CastSkillFromQuickBarSlot: skill/cast helper. Evidence string: "You can\'t do that while you are ". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "You can\'t do that while you are "
//   - "in town."
//   - "waiting."
//   - "dead."
//   - "in your enhanced state."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~171 non-empty decompiler lines.
//  - Control keywords: do×17, while×17, if×9, return×3, for×2.
//  - Notable callees: FUN_007a6de0×8, FUN_00580a20×3, FUN_007a69d0, FUN_008f8200, FUN_0093b7f0.
//  - Strings: "You can\'t do that while you are "; "in town."; "waiting."; "dead.".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_CastSkillFromQuickBarSlot
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

uint8_t Named_CalleeOf_Client_CastSkillFromQuickBarSlot_0093b7f0(void)



{

  char *pcVar1;

  char cVar2;

  int in_EAX;

  char *pcVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  char *pcVar7;

  uint16_t *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  char local_100 [256];

  

  if (*(int *)(in_EAX + 0xe98) == 0) {

    return 1;

  }

  FUN_007a69d0();

  pcVar3 = (char *)FUN_007a6de0("You can\'t do that while you are ",0xffffffff);

  pcVar7 = local_100;

  do {

    cVar2 = *pcVar3;

    *pcVar7 = cVar2;

    pcVar3 = pcVar3 + 1;

    pcVar7 = pcVar7 + 1;

  } while (cVar2 != '\0');

  if (*(char *)(*(int *)(in_EAX + 0xe98) + 0x6b9) == '\0') {

    cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +

                                 *(int *)(in_EAX + 0xe98)) + 0x198))();

    if (cVar2 == '\0') {

      cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +

                                   *(int *)(in_EAX + 0xe98)) + 0x194))();

      if (cVar2 == '\0') {

        if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xa8 +

                              *(int *)(in_EAX + 0xe98)) + 0xf5) == '\0') {

          if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xb8 +

                        *(int *)(in_EAX + 0xe98)) & 8) == 0) {

            if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xb8 +

                          *(int *)(in_EAX + 0xe98)) & 0x80) == 0) {

              if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 0xb8 +

                            *(int *)(in_EAX + 0xe98)) & 0x40) == 0) {

                return 0;

              }

              uVar9 = 0xffffffff;

              uVar5 = FUN_00580a20(0x40,0xffffffff);

              pcVar3 = (char *)FUN_007a6de0(uVar5,uVar9);

              pcVar7 = pcVar3;

              do {

                cVar2 = *pcVar7;

                pcVar7 = pcVar7 + 1;

              } while (cVar2 != '\0');

              uVar4 = (int)pcVar7 - (int)pcVar3;

              pcVar7 = &stack0xfffffeff;

              do {

                pcVar1 = pcVar7 + 1;

                pcVar7 = pcVar7 + 1;

              } while (*pcVar1 != '\0');

            }

            else {

              uVar9 = 0xffffffff;

              uVar5 = FUN_00580a20(0x80,0xffffffff);

              pcVar3 = (char *)FUN_007a6de0(uVar5,uVar9);

              pcVar7 = pcVar3;

              do {

                cVar2 = *pcVar7;

                pcVar7 = pcVar7 + 1;

              } while (cVar2 != '\0');

              uVar4 = (int)pcVar7 - (int)pcVar3;

              pcVar7 = &stack0xfffffeff;

              do {

                pcVar1 = pcVar7 + 1;

                pcVar7 = pcVar7 + 1;

              } while (*pcVar1 != '\0');

            }

          }

          else {

            uVar9 = 0xffffffff;

            uVar5 = FUN_00580a20(2,0xffffffff);

            pcVar3 = (char *)FUN_007a6de0(uVar5,uVar9);

            pcVar7 = pcVar3;

            do {

              cVar2 = *pcVar7;

              pcVar7 = pcVar7 + 1;

            } while (cVar2 != '\0');

            uVar4 = (int)pcVar7 - (int)pcVar3;

            pcVar7 = &stack0xfffffeff;

            do {

              pcVar1 = pcVar7 + 1;

              pcVar7 = pcVar7 + 1;

            } while (*pcVar1 != '\0');

          }

        }

        else {

          pcVar3 = (char *)FUN_007a6de0("in town.",0xffffffff);

          pcVar7 = pcVar3;

          do {

            cVar2 = *pcVar7;

            pcVar7 = pcVar7 + 1;

          } while (cVar2 != '\0');

          uVar4 = (int)pcVar7 - (int)pcVar3;

          pcVar7 = &stack0xfffffeff;

          do {

            pcVar1 = pcVar7 + 1;

            pcVar7 = pcVar7 + 1;

          } while (*pcVar1 != '\0');

        }

      }

      else {

        pcVar3 = (char *)FUN_007a6de0("waiting.",0xffffffff);

        pcVar7 = pcVar3;

        do {

          cVar2 = *pcVar7;

          pcVar7 = pcVar7 + 1;

        } while (cVar2 != '\0');

        uVar4 = (int)pcVar7 - (int)pcVar3;

        pcVar7 = &stack0xfffffeff;

        do {

          pcVar1 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

        } while (*pcVar1 != '\0');

      }

    }

    else {

      pcVar3 = (char *)FUN_007a6de0("dead.",0xffffffff);

      pcVar7 = pcVar3;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      uVar4 = (int)pcVar7 - (int)pcVar3;

      pcVar7 = &stack0xfffffeff;

      do {

        pcVar1 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar1 != '\0');

    }

  }

  else {

    pcVar3 = (char *)FUN_007a6de0("in your enhanced state.",0xffffffff);

    pcVar7 = pcVar3;

    do {

      cVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    uVar4 = (int)pcVar7 - (int)pcVar3;

    pcVar7 = &stack0xfffffeff;

    do {

      pcVar1 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar1 != '\0');

  }

  for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar3;

    pcVar3 = pcVar3 + 4;

    pcVar7 = pcVar7 + 4;

  }

  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *pcVar7 = *pcVar3;

    pcVar3 = pcVar3 + 1;

    pcVar7 = pcVar7 + 1;

  }

  puVar8 = (uint16_t *)&stack0xfffffeff;

  do {

    pcVar7 = (char *)((int)puVar8 + 1);

    puVar8 = (uint16_t *)((int)puVar8 + 1);

  } while (*pcVar7 != '\0');

  *puVar8 = DAT_00a156cc;

  if (DAT_00d1b8dc != 0) {

    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,local_100,0);

  }

  return 1;

}
