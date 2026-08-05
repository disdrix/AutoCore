// =============================================================================
// Client_CastBlockFeedback  (Ghidra: FUN_0093b7f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0093b7f0
// Address:   0x0093b7f0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Role:      cast-block feedback helper
// Generated: 2026-07-23 scaffold; dual A/B + string seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual reviews:
//   docs/reconstruction/reviews/A_aa_0093b7f0_Client_CastBlockFeedback.md
//   docs/reconstruction/reviews/B_aa_0093b7f0_Client_CastBlockFeedback.md
// =============================================================================
//
// PURPOSE: Before cast send, test local character state. If blocked, assemble
//   "You can't do that while you are " + <suffix> + "!" and toast (ch 0x18).
//   return 1 = blocked; 0 = allow cast. Null +0xe98 → return 1 (silent).
//
// SEALED STRINGS (read_memory + sole DATA xrefs in this unit, 2026-07-29):
//   0x00a2e098  "You can't do that while you are "
//   0x00a2e060  "in town."     xref 0x0093b934
//   0x00a2e06c  "waiting."     xref 0x0093b8e3
//   0x00a2e078  "dead."        xref 0x0093b892
//   0x00a2e080  "in your enhanced state."
//   DAT_00a156cc @ 0x00a156cc = word '!' (21 00)
//
// PRIORITY (first match): enhanced(+0x6b9) → dead(vtbl+0x198) → waiting(+0x194)
//   → town(*(dual+0xa8)+0xf5) → flags+0xb8 &8/0x80/0x40 (Stunned/Confused/Afraid)
//
// CALLERS: Client_CastSkillFromQuickBarSlot @ 0x00941927; FUN_00941ac0 @ 0x00941ac5
//
// Readability: control flow preserved from Ghidra decompile; types tentative.

uint8_t Client_CastBlockFeedback(void) /* FUN_0093b7f0; client in EAX */



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
