// READABILITY (auto CF):
//  - Body size: ~693 non-empty decompiler lines.
//  - Control keywords: if×89, while×41, do×40, return×27, goto×3, switch×1.
//  - Notable callees: sprintf×23, FUN_00412c60×12, FUN_005781a0, FUN_0058b8f0, FUN_0058ba20, FUN_0061aaa0, tolower.
//  - Strings: "aggro_radius"; "accuracy_all"; "%+g%%"; "accuracy_physical".
//  - Return sites: 27.

// =============================================================================
// Inv_dmgadd_equip_contamination_0061aaa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061aaa0
// Address:   0x0061aaa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "dmgadd_equip_contamination"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Inv_dmgadd_equip_contamination_0061aaa0(int param_1,char *param_2,char *param_3)



{

  short sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  short sVar4;

  float *pfVar5;

  char *pcVar6;

  char *pcVar7;

  bool bVar8;

  float10 fVar9;

  

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    return 0;

  }

  iVar2 = tolower((int)*param_2);

  switch(iVar2) {

  case 0x61:

    iVar2 = 0xd;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "aggro_radius";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (!bVar8) {

      iVar2 = 0xd;

      bVar8 = true;

      pcVar6 = param_2;

      pcVar7 = "accuracy_all";

      do {

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        bVar8 = *pcVar6 == *pcVar7;

        pcVar6 = pcVar6 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar8);

      if (bVar8) {

        iVar2 = 1;

        pfVar5 = (float *)(param_1 + 0xac);

        while ((iVar2 == 2 || (*pfVar5 == *(float *)(param_1 + 0xa8)))) {

          iVar2 = iVar2 + 1;

          pfVar5 = pfVar5 + 1;

          if (5 < iVar2) {

            fVar9 = (float10)FUN_00412c60();

            sprintf(param_3,"%+g%%",(double)fVar9);

            return 1;

          }

        }

        return 0;

      }

      iVar2 = 0x12;

      bVar8 = true;

      pcVar6 = param_2;

      pcVar7 = "accuracy_physical";

      do {

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        bVar8 = *pcVar6 == *pcVar7;

        pcVar6 = pcVar6 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar8);

      if (!bVar8) {

        iVar2 = 0xe;

        bVar8 = true;

        pcVar6 = param_2;

        pcVar7 = "accuracy_fire";

        do {

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          bVar8 = *pcVar6 == *pcVar7;

          pcVar6 = pcVar6 + 1;

          pcVar7 = pcVar7 + 1;

        } while (bVar8);

        if (!bVar8) {

          iVar2 = 0x13;

          bVar8 = true;

          pcVar6 = param_2;

          pcVar7 = "accuracy_corrosive";

          do {

            if (iVar2 == 0) break;

            iVar2 = iVar2 + -1;

            bVar8 = *pcVar6 == *pcVar7;

            pcVar6 = pcVar6 + 1;

            pcVar7 = pcVar7 + 1;

          } while (bVar8);

          if (!bVar8) {

            iVar2 = 0x17;

            bVar8 = true;

            pcVar6 = param_2;

            pcVar7 = "accuracy_contamination";

            do {

              if (iVar2 == 0) break;

              iVar2 = iVar2 + -1;

              bVar8 = *pcVar6 == *pcVar7;

              pcVar6 = pcVar6 + 1;

              pcVar7 = pcVar7 + 1;

            } while (bVar8);

            if (!bVar8) {

              iVar2 = 0x10;

              bVar8 = true;

              pcVar6 = param_2;

              pcVar7 = "accuracy_energy";

              do {

                if (iVar2 == 0) break;

                iVar2 = iVar2 + -1;

                bVar8 = *pcVar6 == *pcVar7;

                pcVar6 = pcVar6 + 1;

                pcVar7 = pcVar7 + 1;

              } while (bVar8);

              if (!bVar8) break;

            }

          }

        }

      }

    }

    fVar9 = (float10)FUN_00412c60();

    sprintf(param_3,"%+g%%",(double)fVar9);

    return 1;

  case 0x62:

    iVar2 = 6;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "boost";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar9);

      return 1;

    }

    break;

  case 99:

    iVar2 = 0x10;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "cooldown_amount";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar9);

      return 1;

    }

    iVar2 = 0x12;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "cooldown_category";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (!bVar8) break;

    pcVar6 = "%d";

    goto LAB_0061b470;

  case 100:

    iVar2 = 0x14;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "driving_improvement";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar9);

      return 1;

    }

    iVar2 = 0xd;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "dmg_physical";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      sVar1 = *(short *)(param_1 + 0x60);

      sVar4 = *(short *)(param_1 + 0x54);

    }

    else {

      iVar2 = 9;

      bVar8 = true;

      pcVar6 = param_2;

      pcVar7 = "dmg_fire";

      do {

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        bVar8 = *pcVar6 == *pcVar7;

        pcVar6 = pcVar6 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar8);

      if (bVar8) {

        sVar1 = *(short *)(param_1 + 0x62);

        sVar4 = *(short *)(param_1 + 0x56);

      }

      else {

        iVar2 = 0xe;

        bVar8 = true;

        pcVar6 = param_2;

        pcVar7 = "dmg_corrosive";

        do {

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          bVar8 = *pcVar6 == *pcVar7;

          pcVar6 = pcVar6 + 1;

          pcVar7 = pcVar7 + 1;

        } while (bVar8);

        if (bVar8) {

          sVar1 = *(short *)(param_1 + 0x66);

          sVar4 = *(short *)(param_1 + 0x5a);

        }

        else {

          iVar2 = 0x12;

          bVar8 = true;

          pcVar6 = param_2;

          pcVar7 = "dmg_contamination";

          do {

            if (iVar2 == 0) break;

            iVar2 = iVar2 + -1;

            bVar8 = *pcVar6 == *pcVar7;

            pcVar6 = pcVar6 + 1;

            pcVar7 = pcVar7 + 1;

          } while (bVar8);

          if (bVar8) {

            sVar1 = *(short *)(param_1 + 0x68);

            sVar4 = *(short *)(param_1 + 0x5c);

          }

          else {

            iVar2 = 0xb;

            bVar8 = true;

            pcVar6 = param_2;

            pcVar7 = "dmg_energy";

            do {

              if (iVar2 == 0) break;

              iVar2 = iVar2 + -1;

              bVar8 = *pcVar6 == *pcVar7;

              pcVar6 = pcVar6 + 1;

              pcVar7 = pcVar7 + 1;

            } while (bVar8);

            if (bVar8) {

              sVar1 = *(short *)(param_1 + 0x6a);

              sVar4 = *(short *)(param_1 + 0x5e);

            }

            else {

              iVar2 = 0x10;

              bVar8 = true;

              pcVar6 = param_2;

              pcVar7 = "dmgadd_physical";

              do {

                if (iVar2 == 0) break;

                iVar2 = iVar2 + -1;

                bVar8 = *pcVar6 == *pcVar7;

                pcVar6 = pcVar6 + 1;

                pcVar7 = pcVar7 + 1;

              } while (bVar8);

              if (bVar8) {

                sVar4 = *(short *)(param_1 + 0x78);

                sVar1 = *(short *)(param_1 + 0x90);

              }

              else {

                iVar2 = 0xc;

                bVar8 = true;

                pcVar6 = param_2;

                pcVar7 = "dmgadd_fire";

                do {

                  if (iVar2 == 0) break;

                  iVar2 = iVar2 + -1;

                  bVar8 = *pcVar6 == *pcVar7;

                  pcVar6 = pcVar6 + 1;

                  pcVar7 = pcVar7 + 1;

                } while (bVar8);

                if (bVar8) {

                  sVar4 = *(short *)(param_1 + 0x7a);

                  sVar1 = *(short *)(param_1 + 0x92);

                }

                else {

                  iVar2 = 0x11;

                  bVar8 = true;

                  pcVar6 = param_2;

                  pcVar7 = "dmgadd_corrosive";

                  do {

                    if (iVar2 == 0) break;

                    iVar2 = iVar2 + -1;

                    bVar8 = *pcVar6 == *pcVar7;

                    pcVar6 = pcVar6 + 1;

                    pcVar7 = pcVar7 + 1;

                  } while (bVar8);

                  if (bVar8) {

                    sVar4 = *(short *)(param_1 + 0x7e);

                    sVar1 = *(short *)(param_1 + 0x96);

                  }

                  else {

                    iVar2 = 0x15;

                    bVar8 = true;

                    pcVar6 = param_2;

                    pcVar7 = "dmgadd_contamination";

                    do {

                      if (iVar2 == 0) break;

                      iVar2 = iVar2 + -1;

                      bVar8 = *pcVar6 == *pcVar7;

                      pcVar6 = pcVar6 + 1;

                      pcVar7 = pcVar7 + 1;

                    } while (bVar8);

                    if (bVar8) {

                      sVar4 = *(short *)(param_1 + 0x80);

                      sVar1 = *(short *)(param_1 + 0x98);

                    }

                    else {

                      iVar2 = 0xe;

                      bVar8 = true;

                      pcVar6 = param_2;

                      pcVar7 = "dmgadd_energy";

                      do {

                        if (iVar2 == 0) break;

                        iVar2 = iVar2 + -1;

                        bVar8 = *pcVar6 == *pcVar7;

                        pcVar6 = pcVar6 + 1;

                        pcVar7 = pcVar7 + 1;

                      } while (bVar8);

                      if (bVar8) {

                        sVar4 = *(short *)(param_1 + 0x82);

                        sVar1 = *(short *)(param_1 + 0x9a);

                      }

                      else {

                        iVar2 = 0x16;

                        bVar8 = true;

                        pcVar6 = param_2;

                        pcVar7 = "dmgadd_equip_physical";

                        do {

                          if (iVar2 == 0) break;

                          iVar2 = iVar2 + -1;

                          bVar8 = *pcVar6 == *pcVar7;

                          pcVar6 = pcVar6 + 1;

                          pcVar7 = pcVar7 + 1;

                        } while (bVar8);

                        if (bVar8) {

                          sVar4 = *(short *)(param_1 + 0x84);

                          sVar1 = *(short *)(param_1 + 0x9c);

                        }

                        else {

                          iVar2 = 0x12;

                          bVar8 = true;

                          pcVar6 = param_2;

                          pcVar7 = "dmgadd_equip_fire";

                          do {

                            if (iVar2 == 0) break;

                            iVar2 = iVar2 + -1;

                            bVar8 = *pcVar6 == *pcVar7;

                            pcVar6 = pcVar6 + 1;

                            pcVar7 = pcVar7 + 1;

                          } while (bVar8);

                          if (bVar8) {

                            sVar4 = *(short *)(param_1 + 0x86);

                            sVar1 = *(short *)(param_1 + 0x9e);

                          }

                          else {

                            iVar2 = 0x17;

                            bVar8 = true;

                            pcVar6 = param_2;

                            pcVar7 = "dmgadd_equip_corrosive";

                            do {

                              if (iVar2 == 0) break;

                              iVar2 = iVar2 + -1;

                              bVar8 = *pcVar6 == *pcVar7;

                              pcVar6 = pcVar6 + 1;

                              pcVar7 = pcVar7 + 1;

                            } while (bVar8);

                            if (bVar8) {

                              sVar4 = *(short *)(param_1 + 0x8a);

                              sVar1 = *(short *)(param_1 + 0xa2);

                            }

                            else {

                              iVar2 = 0x1b;

                              bVar8 = true;

                              pcVar6 = param_2;

                              pcVar7 = "dmgadd_equip_contamination";

                              do {

                                if (iVar2 == 0) break;

                                iVar2 = iVar2 + -1;

                                bVar8 = *pcVar6 == *pcVar7;

                                pcVar6 = pcVar6 + 1;

                                pcVar7 = pcVar7 + 1;

                              } while (bVar8);

                              if (!bVar8) {

                                iVar2 = 0x14;

                                bVar8 = true;

                                pcVar6 = param_2;

                                pcVar7 = "dmgadd_equip_energy";

                                do {

                                  if (iVar2 == 0) break;

                                  iVar2 = iVar2 + -1;

                                  bVar8 = *pcVar6 == *pcVar7;

                                  pcVar6 = pcVar6 + 1;

                                  pcVar7 = pcVar7 + 1;

                                } while (bVar8);

                                if (!bVar8) break;

                                if (*(short *)(param_1 + 0x8e) != *(short *)(param_1 + 0xa6)) {

                                  sprintf(param_3,"%d-%d",(int)*(short *)(param_1 + 0x8e),

                                          (int)*(short *)(param_1 + 0xa6));

                                  return 1;

                                }

                                goto LAB_0061af8d;

                              }

                              sVar4 = *(short *)(param_1 + 0x8c);

                              sVar1 = *(short *)(param_1 + 0xa4);

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

    if (sVar4 != sVar1) {

      sprintf(param_3,"%d-%d",(int)sVar4,(int)sVar1);

      return 1;

    }

LAB_0061af8d:

    sprintf(param_3,"%d");

    return 1;

  case 0x68:

    iVar2 = 5;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "heat";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      if (g_flOne < *(float *)(param_1 + 0xf0) || *(float *)(param_1 + 0xf0) < DAT_00aaa668) {

        sprintf(param_3,"%+d");

        return 1;

      }

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar9);

      return 1;

    }

    iVar2 = 5;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "heal";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (!bVar8) break;

    if ((*(float *)(param_1 + 0x3c) <= g_flOne) && (DAT_00aaa668 <= *(float *)(param_1 + 0x3c))) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar9);

      return 1;

    }

    goto LAB_0061b46a;

  case 0x70:

    iVar2 = 6;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "power";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      if ((*(float *)(param_1 + 0x40) <= g_flOne) && (DAT_00aaa668 <= *(float *)(param_1 + 0x40))) {

        fVar9 = (float10)FUN_00412c60();

        sprintf(param_3,"%+g%%",(double)fVar9);

        return 1;

      }

      sprintf(param_3,"%+d");

      return 1;

    }

    iVar2 = 9;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "power2hp";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%g",(double)fVar9);

      return 1;

    }

    iVar2 = 0xb;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "power2heat";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%g",(double)fVar9);

      return 1;

    }

    break;

  case 0x72:

    iVar2 = 0xc;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "refire_rate";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar9);

      return 1;

    }

    iVar2 = 0xb;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "resist_all";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      sprintf(param_3,"%+d");

      return 1;

    }

    iVar2 = 0x10;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "resist_physical";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (!bVar8) {

      iVar2 = 0xc;

      bVar8 = true;

      pcVar6 = param_2;

      pcVar7 = "resist_fire";

      do {

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        bVar8 = *pcVar6 == *pcVar7;

        pcVar6 = pcVar6 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar8);

      if (bVar8) {

        sprintf(param_3,"%+d");

        return 1;

      }

      iVar2 = 0x11;

      bVar8 = true;

      pcVar6 = param_2;

      pcVar7 = "resist_corrosive";

      do {

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        bVar8 = *pcVar6 == *pcVar7;

        pcVar6 = pcVar6 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar8);

      if (!bVar8) {

        iVar2 = 0x15;

        bVar8 = true;

        pcVar6 = param_2;

        pcVar7 = "resist_contamination";

        do {

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          bVar8 = *pcVar6 == *pcVar7;

          pcVar6 = pcVar6 + 1;

          pcVar7 = pcVar7 + 1;

        } while (bVar8);

        if (bVar8) {

          sprintf(param_3,"%+d");

          return 1;

        }

        iVar2 = 0xe;

        bVar8 = true;

        pcVar6 = param_2;

        pcVar7 = "resist_energy";

        do {

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          bVar8 = *pcVar6 == *pcVar7;

          pcVar6 = pcVar6 + 1;

          pcVar7 = pcVar7 + 1;

        } while (bVar8);

        if (!bVar8) break;

      }

    }

    sprintf(param_3,"%+d");

    return 1;

  case 0x73:

    iVar2 = 8;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "shields";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (!bVar8) break;

    if ((*(float *)(param_1 + 0x120) <= g_flOne) && (DAT_00aaa668 <= *(float *)(param_1 + 0x120))) {

      fVar9 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar9);

      return 1;

    }

LAB_0061b46a:

    pcVar6 = "%+d";

LAB_0061b470:

    sprintf(param_3,pcVar6);

    return 1;

  case 0x74:

    iVar2 = 6;

    bVar8 = true;

    pcVar6 = param_2;

    pcVar7 = "taunt";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar8 = *pcVar6 == *pcVar7;

      pcVar6 = pcVar6 + 1;

      pcVar7 = pcVar7 + 1;

    } while (bVar8);

    if (bVar8) {

      sprintf(param_3,"%+d");

      return 1;

    }

  }

  if ((((*(byte *)(param_1 + 0x624) & 0x40) == 0) ||

      (iVar2 = FUN_0058b8f0(param_1,param_2,param_3,0x3f800000), iVar2 == 0)) &&

     (((*(byte *)(param_1 + 0x625) & 4) == 0 ||

      (iVar2 = FUN_0058ba20(param_1,param_2,param_3,0x3f800000), iVar2 == 0)))) {

    uVar3 = FUN_005781a0(param_1,param_2,param_3);

    return uVar3;

  }

  return 1;

}
