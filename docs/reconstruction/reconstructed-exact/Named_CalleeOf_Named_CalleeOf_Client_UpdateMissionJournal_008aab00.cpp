// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_008aab00
// -----------------------------------------------------------------------------
// Stable ID: aa_008aab00
// Callee of Named_CalleeOf_Client_UpdateMissionJournal (+2 other named callers)
// Address:   0x008aab00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_UpdateMissionJournal: mission/objective helper. Evidence string: "[$/imp]". Supports parent flow (not a free-standing entry point). Named_CalleeOf_Client_UpdateMissionJournal (+2 other named callers).
// Embedded strings (evidence):
//   - "[$imp]"
//   - "[$/imp]"
//   - "[$npc]"
//   - "[$/npc]"
//   - "[$inst]"
//   - "[$/inst]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~215 non-empty decompiler lines.
//  - Control keywords: if×27, goto×8, while×5, do×3, return×3.
//  - Notable callees: _strnicmp×13, FUN_007a69d0×2, FUN_007a6de0×2, FUN_007f5120, FUN_007f9160, FUN_008aab00, _stricmp, sprintf.
//  - Strings: "[$imp]"; "[$/imp]"; "[$npc]"; "[$/npc]".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_UpdateMissionJournal (+2 other named callers)
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __thiscall Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_008aab00(char *param_1,int *param_2)



{

  byte bVar1;

  char cVar2;

  int iVar3;

  byte *pbVar4;

  byte *pbVar5;

  uint8_t *puVar6;

  int iVar7;

  bool bVar8;

  char *pcVar9;

  int local_204c;

  char local_2040 [64];

  byte local_2000 [4096];

  byte local_1000 [6];

  byte local_ffa [4086];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x8aab0a;

  if ((param_2 != (int *)0x0) && (param_1 != (char *)0x0)) {

    FUN_007a69d0();

    iVar7 = -(int)param_1;

    do {

      cVar2 = *param_1;

      param_1[(int)(local_1000 + iVar7)] = cVar2;

      param_1 = param_1 + 1;

    } while (cVar2 != '\0');

    iVar7 = 0;

    local_204c = 0;

    if (local_1000[0] != 0) {

LAB_008aab70:

      pbVar5 = local_1000 + iVar7;

      if ((local_1000[iVar7] == 0x5b) && (local_1000[iVar7 + 1] == 0x24)) {

        if (0 < local_204c) {

          iVar3 = *param_2;

          local_2000[local_204c] = 0;

          (**(code **)(iVar3 + 0x250))(local_2000);

          local_204c = 0;

        }

        iVar3 = _strnicmp((char *)pbVar5,"[$imp]",6);

        if (iVar3 == 0) {

          (**(code **)(*param_2 + 0x230))(0xffff2d00);

          iVar7 = iVar7 + 6;

        }

        else {

          iVar3 = _strnicmp((char *)pbVar5,"[$/imp]",7);

          if (iVar3 == 0) {

            (**(code **)(*param_2 + 0x23c))();

            iVar7 = iVar7 + 7;

          }

          else {

            iVar3 = _strnicmp((char *)pbVar5,"[$npc]",6);

            if (iVar3 == 0) {

              (**(code **)(*param_2 + 0x230))(0xff256ec8);

              iVar7 = iVar7 + 6;

            }

            else {

              iVar3 = _strnicmp((char *)pbVar5,"[$/npc]",7);

              if (iVar3 == 0) {

                (**(code **)(*param_2 + 0x23c))();

                iVar7 = iVar7 + 7;

              }

              else {

                iVar3 = _strnicmp((char *)pbVar5,"[$inst]",7);

                if (iVar3 == 0) {

                  (**(code **)(*param_2 + 0x230))(0xffc5c025);

                  iVar7 = iVar7 + 7;

                }

                else {

                  iVar3 = _strnicmp((char *)pbVar5,"[$/inst]",8);

                  if (iVar3 == 0) {

                    (**(code **)(*param_2 + 0x23c))();

                    iVar7 = iVar7 + 8;

                  }

                  else {

                    iVar3 = _strnicmp((char *)pbVar5,"[$loc]",6);

                    if (iVar3 == 0) {

                      (**(code **)(*param_2 + 0x230))(0xfff59623);

                      iVar7 = iVar7 + 6;

                    }

                    else {

                      iVar3 = _strnicmp((char *)pbVar5,"[$/loc]",7);

                      if (iVar3 == 0) {

                        (**(code **)(*param_2 + 0x23c))();

                        iVar7 = iVar7 + 7;

                      }

                      else {

                        iVar3 = _strnicmp((char *)pbVar5,"[$emote]",8);

                        if (iVar3 == 0) {

                          (**(code **)(*param_2 + 0x230))(0xff29b525);

                          iVar7 = iVar7 + 8;

                        }

                        else {

                          iVar3 = _strnicmp((char *)pbVar5,"[$/emote]",9);

                          if (iVar3 == 0) {

                            (**(code **)(*param_2 + 0x23c))();

                            iVar7 = iVar7 + 9;

                          }

                          else {

                            iVar3 = _strnicmp((char *)pbVar5,"[$pause]",8);

                            if (iVar3 == 0) {

                              (**(code **)(*param_2 + 0x254))(0x14);

                              iVar7 = iVar7 + 8;

                            }

                            else {

                              iVar3 = _strnicmp((char *)pbVar5,"[$key]",6);

                              if (iVar3 != 0) {

                                local_2000[local_204c] = *pbVar5;

                                goto LAB_008aaf20;

                              }

                              pbVar5 = local_ffa + iVar7;

                              local_204c = 0;

                              bVar1 = *pbVar5;

                              iVar7 = iVar7 + 6;

                              while (bVar1 != 0) {

                                if (((bVar1 == 0x5b) && (local_1000[iVar7 + 1] == 0x24)) &&

                                   (iVar3 = _strnicmp((char *)pbVar5,"[$/key]",7), iVar3 == 0)) {

                                  iVar7 = iVar7 + 7;

                                  local_2000[local_204c] = 0;

                                  pbVar4 = (byte *)FUN_007a6de0("Free Look",0xffffffff);

                                  pbVar5 = local_2000;

                                  goto LAB_008aadf7;

                                }

                                local_2000[local_204c] = *pbVar5;

                                local_204c = local_204c + 1;

                                pbVar5 = local_1000 + iVar7 + 1;

                                iVar7 = iVar7 + 1;

                                bVar1 = *pbVar5;

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

      else {

        local_2000[local_204c] = local_1000[iVar7];

LAB_008aaf20:

        local_204c = local_204c + 1;

        iVar7 = iVar7 + 1;

      }

      goto LAB_008aaf23;

    }

  }

  return;

  while( true ) {

    bVar1 = pbVar5[1];

    bVar8 = bVar1 < pbVar4[1];

    if (bVar1 != pbVar4[1]) goto LAB_008aae1b;

    pbVar5 = pbVar5 + 2;

    pbVar4 = pbVar4 + 2;

    if (bVar1 == 0) break;

LAB_008aadf7:

    bVar1 = *pbVar5;

    bVar8 = bVar1 < *pbVar4;

    if (bVar1 != *pbVar4) {

LAB_008aae1b:

      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

      goto LAB_008aae20;

    }

    if (bVar1 == 0) break;

  }

  iVar3 = 0;

LAB_008aae20:

  if (iVar3 == 0) {

    pbVar5 = (byte *)FUN_007f5120();

    pcVar9 = "%s";

  }

  else {

    pbVar5 = local_2000;

    do {

      bVar1 = *pbVar5;

      pbVar5 = pbVar5 + 1;

    } while (bVar1 != 0);

    if ((pbVar5 != local_2000 + 1) && ((uint)((int)pbVar5 - (int)(local_2000 + 1)) < 0x22)) {

      FUN_007a69d0();

      cVar2 = '\0';

      puVar6 = &DAT_00d1bbf5;

      do {

        pcVar9 = (char *)FUN_007a6de0(puVar6,0xffffffff);

        iVar3 = _stricmp((char *)local_2000,pcVar9);

        if (iVar3 == 0) goto LAB_008aaea5;

        puVar6 = puVar6 + 0x34;

        cVar2 = cVar2 + '\x01';

      } while ((int)puVar6 < 0xd1d455);

    }

    cVar2 = '\0';

LAB_008aaea5:

    cVar2 = FUN_007f9160(cVar2,0);

    if (cVar2 != '\0') goto LAB_008aaedb;

    pbVar5 = local_2000;

    pcVar9 = "<%s>";

  }

  sprintf(local_2040,pcVar9,pbVar5);

LAB_008aaedb:

  (**(code **)(*param_2 + 0x250))(local_2040);

  local_204c = 0;

LAB_008aaf23:

  if (local_1000[iVar7] == 0) {

    if (local_204c == 0) {

      return;

    }

    iVar7 = *param_2;

    local_2000[local_204c] = 0;

    (**(code **)(iVar7 + 0x250))(local_2000);

    return;

  }

  goto LAB_008aab70;

}
