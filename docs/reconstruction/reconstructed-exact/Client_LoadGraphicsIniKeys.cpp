// READABILITY (auto CF):
//  - Body size: ~1203 non-empty decompiler lines.
//  - Control keywords: if×137, do×26, while×26, return×3.
//  - Notable callees: strtok×98, _stricmp×77, atoi×61, atof×34, FUN_004a81c0×2, FUN_007a69d0×2, fgets×2, FUN_00401000.
//  - Strings: "CINCAM_VELOCITY_FACTOR_X"; "CINCAM_VELOCITY_FACTOR_Y"; "CINCAM_VELOCITY_FACTOR_Z"; "CINCAM_VELOCITY_MAX_X".
//  - Return sites: 3.

// =============================================================================
// Client_LoadGraphicsIniKeys
// -----------------------------------------------------------------------------
// Purpose:  Loads large graphics/UI INI key table including SET_NEW_MISSION_ACTIVE and FULL_QUICKBAR_RED.
//
// Address:  0x0095ae10  (autoassault.exe, image base 0x400000)
// Stable:   aa_0095ae10
// System:   missions-progression
//
// String evidence: "SET_NEW_MISSION_ACTIVE" / "FULL_QUICKBAR_RED" / CINCAM_* keys
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0095ae10.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0095ae10 using string evidence: "SET_NEW_MISSION_ACTIVE" / "FULL_QUICKBAR_RED" / CINCAM_* keys
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ Client_LoadGraphicsIniKeys(int param_1)

{

  char cVar1;

  char *in_EAX;

  char *pcVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  int iVar6;

  char *pcVar7;

  bool bVar8;

  double dVar9;

  uint16_t local_510;

  uint8_t local_50e;

  uint16_t local_50c;

  uint8_t local_50a;

  FILE *local_508;

  char local_504 [260];

  char local_400 [1024];

  

  if (in_EAX == (char *)0x0) {

    pcVar2 = *(char **)(param_1 + 0xe8);

    if (pcVar2 == (char *)0x0) {

      return 0;

    }

    iVar6 = -(int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)(local_504 + iVar6)] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  else {

    iVar6 = -(int)in_EAX;

    do {

      cVar1 = *in_EAX;

      in_EAX[(int)(local_504 + iVar6)] = cVar1;

      in_EAX = in_EAX + 1;

    } while (cVar1 != '\0');

  }

  local_508 = fopen(local_504,"r");

  if (local_508 == (FILE *)0x0) {

    return 0;

  }

  local_510 = DAT_00a152e0;

  local_50e = DAT_00a152e2;

  local_50c = DAT_00a152dc;

  local_50a = DAT_00a152de;

  pcVar2 = fgets(local_400,0x400,local_508);

  do {

    if (pcVar2 == (char *)0x0) {

      pcVar2 = local_504;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      if (*(void **)(param_1 + 0xe8) != (void *)0x0) {

        operator_delete__(*(void **)(param_1 + 0xe8));

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = 0;

      pcVar5 = operator_new__((uint)(pcVar2 + (1 - (int)(local_504 + 1))));

      *(char **)(param_1 + 0xe8) = pcVar5;

      pcVar2 = local_504;

      do {

        cVar1 = *pcVar2;

        *pcVar5 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      fclose(local_508);

      return 1;

    }

    pcVar2 = strstr(local_400,(char *)&local_50c);

    if (pcVar2 != (char *)0x0) {

      *pcVar2 = '\0';

    }

    pcVar2 = strtok(local_400,(char *)&local_510);

    if (pcVar2 != (char *)0x0) {

      iVar6 = 0x19;

      bVar8 = true;

      pcVar5 = pcVar2;

      pcVar7 = "CINCAM_VELOCITY_FACTOR_X";

      do {

        if (iVar6 == 0) break;

        iVar6 = iVar6 + -1;

        bVar8 = *pcVar5 == *pcVar7;

        pcVar5 = pcVar5 + 1;

        pcVar7 = pcVar7 + 1;

      } while (bVar8);

      if (bVar8) {

        pcVar2 = strtok((char *)0x0,(char *)&local_510);

        dVar9 = atof(pcVar2);

        *(float *)(param_1 + 0x80) = (float)dVar9;

      }

      else {

        iVar6 = 0x19;

        bVar8 = true;

        pcVar5 = pcVar2;

        pcVar7 = "CINCAM_VELOCITY_FACTOR_Y";

        do {

          if (iVar6 == 0) break;

          iVar6 = iVar6 + -1;

          bVar8 = *pcVar5 == *pcVar7;

          pcVar5 = pcVar5 + 1;

          pcVar7 = pcVar7 + 1;

        } while (bVar8);

        if (bVar8) {

          pcVar2 = strtok((char *)0x0,(char *)&local_510);

          dVar9 = atof(pcVar2);

          *(float *)(param_1 + 0x84) = (float)dVar9;

        }

        else {

          iVar6 = 0x19;

          bVar8 = true;

          pcVar5 = pcVar2;

          pcVar7 = "CINCAM_VELOCITY_FACTOR_Z";

          do {

            if (iVar6 == 0) break;

            iVar6 = iVar6 + -1;

            bVar8 = *pcVar5 == *pcVar7;

            pcVar5 = pcVar5 + 1;

            pcVar7 = pcVar7 + 1;

          } while (bVar8);

          if (bVar8) {

            pcVar2 = strtok((char *)0x0,(char *)&local_510);

            dVar9 = atof(pcVar2);

            *(float *)(param_1 + 0x88) = (float)dVar9;

          }

          else {

            iVar6 = 0x16;

            bVar8 = true;

            pcVar5 = pcVar2;

            pcVar7 = "CINCAM_VELOCITY_MAX_X";

            do {

              if (iVar6 == 0) break;

              iVar6 = iVar6 + -1;

              bVar8 = *pcVar5 == *pcVar7;

              pcVar5 = pcVar5 + 1;

              pcVar7 = pcVar7 + 1;

            } while (bVar8);

            if (bVar8) {

              pcVar2 = strtok((char *)0x0,(char *)&local_510);

              dVar9 = atof(pcVar2);

              *(float *)(param_1 + 0x8c) = (float)dVar9;

            }

            else {

              iVar6 = 0x16;

              bVar8 = true;

              pcVar5 = pcVar2;

              pcVar7 = "CINCAM_VELOCITY_MAX_Y";

              do {

                if (iVar6 == 0) break;

                iVar6 = iVar6 + -1;

                bVar8 = *pcVar5 == *pcVar7;

                pcVar5 = pcVar5 + 1;

                pcVar7 = pcVar7 + 1;

              } while (bVar8);

              if (bVar8) {

                pcVar2 = strtok((char *)0x0,(char *)&local_510);

                dVar9 = atof(pcVar2);

                *(float *)(param_1 + 0x90) = (float)dVar9;

              }

              else {

                iVar6 = 0x16;

                bVar8 = true;

                pcVar5 = pcVar2;

                pcVar7 = "CINCAM_VELOCITY_MAX_Z";

                do {

                  if (iVar6 == 0) break;

                  iVar6 = iVar6 + -1;

                  bVar8 = *pcVar5 == *pcVar7;

                  pcVar5 = pcVar5 + 1;

                  pcVar7 = pcVar7 + 1;

                } while (bVar8);

                if (bVar8) {

                  pcVar2 = strtok((char *)0x0,(char *)&local_510);

                  dVar9 = atof(pcVar2);

                  *(float *)(param_1 + 0x94) = (float)dVar9;

                }

                else {

                  iVar6 = 0x19;

                  bVar8 = true;

                  pcVar5 = pcVar2;

                  pcVar7 = "CINCAM_ROTATION_FACTOR_X";

                  do {

                    if (iVar6 == 0) break;

                    iVar6 = iVar6 + -1;

                    bVar8 = *pcVar5 == *pcVar7;

                    pcVar5 = pcVar5 + 1;

                    pcVar7 = pcVar7 + 1;

                  } while (bVar8);

                  if (bVar8) {

                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                    dVar9 = atof(pcVar2);

                    *(float *)(param_1 + 0xa4) = (float)dVar9;

                  }

                  else {

                    iVar6 = 0x19;

                    bVar8 = true;

                    pcVar5 = pcVar2;

                    pcVar7 = "CINCAM_ROTATION_FACTOR_Y";

                    do {

                      if (iVar6 == 0) break;

                      iVar6 = iVar6 + -1;

                      bVar8 = *pcVar5 == *pcVar7;

                      pcVar5 = pcVar5 + 1;

                      pcVar7 = pcVar7 + 1;

                    } while (bVar8);

                    if (bVar8) {

                      pcVar2 = strtok((char *)0x0,(char *)&local_510);

                      dVar9 = atof(pcVar2);

                      *(float *)(param_1 + 0xa8) = (float)dVar9;

                    }

                    else {

                      iVar6 = 0x19;

                      bVar8 = true;

                      pcVar5 = pcVar2;

                      pcVar7 = "CINCAM_ROTATION_FACTOR_Z";

                      do {

                        if (iVar6 == 0) break;

                        iVar6 = iVar6 + -1;

                        bVar8 = *pcVar5 == *pcVar7;

                        pcVar5 = pcVar5 + 1;

                        pcVar7 = pcVar7 + 1;

                      } while (bVar8);

                      if (bVar8) {

                        pcVar2 = strtok((char *)0x0,(char *)&local_510);

                        dVar9 = atof(pcVar2);

                        *(float *)(param_1 + 0xac) = (float)dVar9;

                      }

                      else {

                        iVar6 = 0x16;

                        bVar8 = true;

                        pcVar5 = pcVar2;

                        pcVar7 = "CINCAM_ROTATION_MAX_X";

                        do {

                          if (iVar6 == 0) break;

                          iVar6 = iVar6 + -1;

                          bVar8 = *pcVar5 == *pcVar7;

                          pcVar5 = pcVar5 + 1;

                          pcVar7 = pcVar7 + 1;

                        } while (bVar8);

                        if (bVar8) {

                          pcVar2 = strtok((char *)0x0,(char *)&local_510);

                          dVar9 = atof(pcVar2);

                          *(float *)(param_1 + 0xb0) = (float)dVar9;

                        }

                        else {

                          iVar6 = 0x16;

                          bVar8 = true;

                          pcVar5 = pcVar2;

                          pcVar7 = "CINCAM_ROTATION_MAX_Y";

                          do {

                            if (iVar6 == 0) break;

                            iVar6 = iVar6 + -1;

                            bVar8 = *pcVar5 == *pcVar7;

                            pcVar5 = pcVar5 + 1;

                            pcVar7 = pcVar7 + 1;

                          } while (bVar8);

                          if (bVar8) {

                            pcVar2 = strtok((char *)0x0,(char *)&local_510);

                            dVar9 = atof(pcVar2);

                            *(float *)(param_1 + 0xb4) = (float)dVar9;

                          }

                          else {

                            iVar6 = 0x16;

                            bVar8 = true;

                            pcVar5 = pcVar2;

                            pcVar7 = "CINCAM_ROTATION_MAX_Z";

                            do {

                              if (iVar6 == 0) break;

                              iVar6 = iVar6 + -1;

                              bVar8 = *pcVar5 == *pcVar7;

                              pcVar5 = pcVar5 + 1;

                              pcVar7 = pcVar7 + 1;

                            } while (bVar8);

                            if (bVar8) {

                              pcVar2 = strtok((char *)0x0,(char *)&local_510);

                              dVar9 = atof(pcVar2);

                              *(float *)(param_1 + 0xb8) = (float)dVar9;

                            }

                            else {

                              iVar6 = 0x13;

                              bVar8 = true;

                              pcVar5 = pcVar2;

                              pcVar7 = "CINCAM_ZOOM_FACTOR";

                              do {

                                if (iVar6 == 0) break;

                                iVar6 = iVar6 + -1;

                                bVar8 = *pcVar5 == *pcVar7;

                                pcVar5 = pcVar5 + 1;

                                pcVar7 = pcVar7 + 1;

                              } while (bVar8);

                              if (bVar8) {

                                pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                dVar9 = atof(pcVar2);

                                *(float *)(param_1 + 0xcc) = (float)dVar9;

                              }

                              else {

                                iVar6 = 0x19;

                                bVar8 = true;

                                pcVar5 = pcVar2;

                                pcVar7 = "CINCAM_ZOOM_MAX_VELOCITY";

                                do {

                                  if (iVar6 == 0) break;

                                  iVar6 = iVar6 + -1;

                                  bVar8 = *pcVar5 == *pcVar7;

                                  pcVar5 = pcVar5 + 1;

                                  pcVar7 = pcVar7 + 1;

                                } while (bVar8);

                                if (bVar8) {

                                  pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                  dVar9 = atof(pcVar2);

                                  *(float *)(param_1 + 0xd0) = (float)dVar9;

                                }

                                else {

                                  iVar6 = 0x16;

                                  bVar8 = true;

                                  pcVar5 = pcVar2;

                                  pcVar7 = "CINCAM_ZOOM_MAX_VALUE";

                                  do {

                                    if (iVar6 == 0) break;

                                    iVar6 = iVar6 + -1;

                                    bVar8 = *pcVar5 == *pcVar7;

                                    pcVar5 = pcVar5 + 1;

                                    pcVar7 = pcVar7 + 1;

                                  } while (bVar8);

                                  if (bVar8) {

                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                    dVar9 = atof(pcVar2);

                                    *(float *)(param_1 + 0xd4) = (float)dVar9;

                                  }

                                  else {

                                    iVar6 = 0x16;

                                    bVar8 = true;

                                    pcVar5 = pcVar2;

                                    pcVar7 = "CINCAM_ZOOM_MIN_VALUE";

                                    do {

                                      if (iVar6 == 0) break;

                                      iVar6 = iVar6 + -1;

                                      bVar8 = *pcVar5 == *pcVar7;

                                      pcVar5 = pcVar5 + 1;

                                      pcVar7 = pcVar7 + 1;

                                    } while (bVar8);

                                    if (bVar8) {

                                      pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                      dVar9 = atof(pcVar2);

                                      *(float *)(param_1 + 0xd8) = (float)dVar9;

                                    }

                                    else {

                                      iVar6 = 8;

                                      bVar8 = true;

                                      pcVar5 = pcVar2;

                                      pcVar7 = "E3_DEMO";

                                      do {

                                        if (iVar6 == 0) break;

                                        iVar6 = iVar6 + -1;

                                        bVar8 = *pcVar5 == *pcVar7;

                                        pcVar5 = pcVar5 + 1;

                                        pcVar7 = pcVar7 + 1;

                                      } while (bVar8);

                                      if (bVar8) {

                                        pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                        iVar6 = atoi(pcVar2);

                                        *(bool *)(param_1 + 0x11) = 0 < iVar6;

                                      }

                                      else {

                                        iVar6 = 0x12;

                                        bVar8 = true;

                                        pcVar5 = pcVar2;

                                        pcVar7 = "MOUSE_SENSITIVITY";

                                        do {

                                          if (iVar6 == 0) break;

                                          iVar6 = iVar6 + -1;

                                          bVar8 = *pcVar5 == *pcVar7;

                                          pcVar5 = pcVar5 + 1;

                                          pcVar7 = pcVar7 + 1;

                                        } while (bVar8);

                                        if (bVar8) {

                                          pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                          dVar9 = atof(pcVar2);

                                          *(float *)(param_1 + 0xdc) = (float)dVar9;

                                        }

                                        else {

                                          iVar6 = _stricmp(pcVar2,"REMEMBER_USERNAME");

                                          if (iVar6 == 0) {

                                            pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                            iVar6 = atoi(pcVar2);

                                            *(bool *)(param_1 + 4) = iVar6 == 1;

                                          }

                                          else {

                                            iVar6 = _stricmp(pcVar2,"USERNAME");

                                            if (iVar6 == 0) {

                                              pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                              if (DAT_00d1b64c != 0) {

                                                iVar6 = 2;

                                                bVar8 = true;

                                                pcVar5 = pcVar2;

                                                pcVar7 = "\n";

                                                do {

                                                  if (iVar6 == 0) break;

                                                  iVar6 = iVar6 + -1;

                                                  bVar8 = *pcVar5 == *pcVar7;

                                                  pcVar5 = pcVar5 + 1;

                                                  pcVar7 = pcVar7 + 1;

                                                } while (bVar8);

                                                if (!bVar8) {

                                                  pcVar5 = pcVar2;

                                                  do {

                                                    cVar1 = *pcVar5;

                                                    pcVar5 = pcVar5 + 1;

                                                  } while (cVar1 != '\0');

                                                  if ((uint)((int)pcVar5 - (int)(pcVar2 + 1)) < 0x20

                                                     ) {

                                                    FUN_004a81c0(pcVar2);

                                                  }

                                                  else {

                                                    FUN_004a81c0(&DAT_00a1419b);

                                                  }

                                                }

                                              }

                                            }

                                            else {

                                              iVar6 = _stricmp(pcVar2,"MODE_WINDOWED");

                                              if (iVar6 == 0) {

                                                pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                iVar6 = atoi(pcVar2);

                                                *(bool *)(param_1 + 5) = iVar6 == 1;

                                              }

                                              else {

                                                iVar6 = _stricmp(pcVar2,"DRAW_WINDOW_BORDER");

                                                if (iVar6 == 0) {

                                                  pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                  iVar6 = atoi(pcVar2);

                                                  *(bool *)(param_1 + 6) = iVar6 == 1;

                                                }

                                                else {

                                                  iVar6 = _stricmp(pcVar2,"RESOLUTIONX");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(int *)(param_1 + 0x5c) = iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"RESOLUTIONY");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(int *)(param_1 + 0x60) = iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"ALLOW_UI_SCALE");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 0x68) = iVar6 == 1;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,

                                                  "UI_RESOLUTION_SCALE");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    dVar9 = atof(pcVar2);

                                                    *(float *)(param_1 + 100) = (float)dVar9;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"GAMMA");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      dVar9 = atof(pcVar2);

                                                      *(float *)(param_1 + 0x6c) = (float)dVar9;

                                                    }

                                                    else {

                                                      iVar6 = 0xf;

                                                      bVar8 = true;

                                                      pcVar5 = pcVar2;

                                                      pcVar7 = "LOAD_SPEC_GLOW";

                                                      do {

                                                        if (iVar6 == 0) break;

                                                        iVar6 = iVar6 + -1;

                                                        bVar8 = *pcVar5 == *pcVar7;

                                                        pcVar5 = pcVar5 + 1;

                                                        pcVar7 = pcVar7 + 1;

                                                      } while (bVar8);

                                                      if (bVar8) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 0x12) = iVar6 == 1;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"SHADOW_MODE");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          DAT_00afa2dc = atoi(pcVar2);

                                                          if (DAT_00afa2dc == 0) {

                                                            DAT_00afa2d8 = 0;

                                                          }

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,"SHADOW_DISTANCE")

                                                          ;

                                                          if (iVar6 == 0) {

                                                            pcVar2 = strtok((char *)0x0,

                                                                            (char *)&local_510);

                                                            dVar9 = atof(pcVar2);

                                                            DAT_00afa2e0 = (float)dVar9;

                                                            _DAT_00afa2e4 =

                                                                 DAT_00b01a9c + (float)dVar9;

                                                          }

                                                          else {

                                                            iVar6 = _stricmp(pcVar2,

                                                  "BETTER_SHADOW_CULLING");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    DAT_00aefa54 = iVar6 != 0;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"LOD_BIAS");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      dVar9 = atof(pcVar2);

                                                      DAT_00d1a540 = (float)dVar9;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"LOD_SCALAR");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        dVar9 = atof(pcVar2);

                                                        DAT_00afa2ec = (float)dVar9;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"ADVANCED_SHADERS");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          iVar6 = atoi(pcVar2);

                                                          *(bool *)(param_1 + 0x14) = iVar6 != 0;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,

                                                  "TEXTURE_RESOLUTION");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(byte *)(param_1 + 0x51) = (byte)iVar6;

                                                    if (2 < (byte)iVar6) {

                                                      *(uint8_t *)(param_1 + 0x51) = 2;

                                                    }

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"MODE_ANTIALIASED");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(bool *)(param_1 + 10) = iVar6 == 1;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"TERRAIN_DRAW_DIST");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        dVar9 = atof(pcVar2);

                                                        DAT_00b036ac = (float)dVar9;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"PARTICLE_CULLING");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          dVar9 = atof(pcVar2);

                                                          DAT_00af06e0 = (float)dVar9;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,

                                                  "BACKGROUND_LOADING");

                                                  if (iVar6 == 0) {

                                                    strtok((char *)0x0,(char *)&local_510);

                                                    *(bool *)(param_1 + 0x18) = DAT_00d1a8f3 != '\0'

                                                    ;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"FLOATING_POINT_24BIT");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      if (pcVar2 != (char *)0x0) {

                                                        *(uint8_t *)(param_1 + 0x19) = 1;

                                                      }

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"AGE_FLUSH_PRELOADER")

                                                      ;

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        DAT_00d1793d = iVar6 == 1;

                                                        *(uint8_t *)(param_1 + 0x23) = 1;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"DRAW_FLAIR");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          iVar6 = atoi(pcVar2);

                                                          *(bool *)(param_1 + 0x22) = iVar6 == 1;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,"FIRST_TIME_LOAD")

                                                          ;

                                                          if (iVar6 == 0) {

                                                            pcVar2 = strtok((char *)0x0,

                                                                            (char *)&local_510);

                                                            iVar6 = atoi(pcVar2);

                                                            *(bool *)(param_1 + 0x21) = iVar6 == 1;

                                                          }

                                                          else {

                                                            iVar6 = _stricmp(pcVar2,"LOOT_QUEUE");

                                                            if (iVar6 == 0) {

                                                              pcVar2 = strtok((char *)0x0,

                                                                              (char *)&local_510);

                                                              iVar6 = atoi(pcVar2);

                                                              DAT_00d1a8f0 = iVar6 == 1;

                                                            }

                                                            else {

                                                              iVar6 = _stricmp(pcVar2,"USESOUND");

                                                              if (iVar6 == 0) {

                                                                pcVar2 = strtok((char *)0x0,

                                                                                (char *)&local_510);

                                                                iVar6 = atoi(pcVar2);

                                                                *(bool *)(param_1 + 0x2a) =

                                                                     iVar6 != 0;

                                                              }

                                                              else {

                                                                iVar6 = _stricmp(pcVar2,"USEMUSIC");

                                                                if (iVar6 == 0) {

                                                                  pcVar2 = strtok((char *)0x0,

                                                                                  (char *)&local_510

                                                                                 );

                                                                  iVar6 = atoi(pcVar2);

                                                                  *(bool *)(param_1 + 0x2b) =

                                                                       iVar6 != 0;

                                                                }

                                                                else {

                                                                  iVar6 = _stricmp(pcVar2,

                                                  "USE3DBUFFERS");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x2e) = iVar6 != 0;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"SOUND_MUSIC");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      dVar9 = atof(pcVar2);

                                                      *(float *)(param_1 + 0x30) =

                                                           (float)dVar9 * DAT_00a0f718;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,

                                                  "SOUND_MUSIC_ENVIRONMENT");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    dVar9 = atof(pcVar2);

                                                    *(float *)(param_1 + 0x34) =

                                                         (float)dVar9 * DAT_00a0f718;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"SOUND_3DLOCAL");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      dVar9 = atof(pcVar2);

                                                      *(float *)(param_1 + 0x38) =

                                                           (float)dVar9 * DAT_00a0f718;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"SOUND_3D");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        dVar9 = atof(pcVar2);

                                                        *(float *)(param_1 + 0x3c) =

                                                             (float)dVar9 * DAT_00a0f718;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"SOUND_COLLISION");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          dVar9 = atof(pcVar2);

                                                          *(float *)(param_1 + 0x40) =

                                                               (float)dVar9 * DAT_00a0f718;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,"SOUND_2D");

                                                          if (iVar6 == 0) {

                                                            pcVar2 = strtok((char *)0x0,

                                                                            (char *)&local_510);

                                                            dVar9 = atof(pcVar2);

                                                            *(float *)(param_1 + 0x44) =

                                                                 (float)dVar9 * DAT_00a0f718;

                                                          }

                                                          else {

                                                            iVar6 = _stricmp(pcVar2,"SOUND_CAR");

                                                            if (iVar6 == 0) {

                                                              pcVar2 = strtok((char *)0x0,

                                                                              (char *)&local_510);

                                                              dVar9 = atof(pcVar2);

                                                              *(float *)(param_1 + 0x48) =

                                                                   (float)dVar9 * DAT_00a0f718;

                                                            }

                                                            else {

                                                              iVar6 = _stricmp(pcVar2,"SOUND_ALL");

                                                              if (iVar6 == 0) {

                                                                pcVar2 = strtok((char *)0x0,

                                                                                (char *)&local_510);

                                                                dVar9 = atof(pcVar2);

                                                                *(float *)(param_1 + 0x4c) =

                                                                     (float)dVar9 * DAT_00a0f718;

                                                              }

                                                              else {

                                                                iVar6 = _stricmp(pcVar2,

                                                  "SOUND_USE_SOFTWARE");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x2c) = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"SOUND_PERFORMANCE");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(bool *)(param_1 + 0x2d) = 0 < iVar6;

                                                      if (DAT_00d1a851 != '\0') {

                                                        *(uint8_t *)(param_1 + 0x2d) = 1;

                                                      }

                                                    }

                                                    else {

                                                      iVar6 = strncmp(pcVar2,"SOUND_PRIORITY",0xe);

                                                      if (iVar6 == 0) {

                                                        iVar6 = atoi(pcVar2 + 0xe);

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar3 = atoi(pcVar2);

                                                        iVar4 = Client_GetMissionCompleteAudioTable

                                                                          ();

                                                        if ((-1 < iVar3) && (iVar3 < 9)) {

                                                          *(int *)(iVar4 + 0x260 + iVar3 * 4) =

                                                               iVar6;

                                                        }

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,

                                                  "NEVER_PLAY_SOUND_FOR_SUMMONS");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x50) = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"USE_JOYSTICK");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(bool *)(param_1 + 0x13) = 0 < iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"WORD_FILTER");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 0x29) = 0 < iVar6;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,

                                                  "ALL_WINDOWS_MOVEABLE");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    DAT_00afa140 = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"DISTANCE_UNITS");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(char *)(param_1 + 0x53) = (char)iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"TARGET_SELF");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 9) = 0 < iVar6;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"COMBAT_CURSOR");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          iVar6 = atoi(pcVar2);

                                                          *(bool *)(param_1 + 0x17) = 0 < iVar6;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,

                                                  "SCREENSHOT_FORMAT");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(char *)(param_1 + 0x54) = (char)iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"NETWORK_TYPE");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(char *)(param_1 + 0x52) = (char)iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"USE_EXTENDED_ZOOM");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 0x70) = 0 < iVar6;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"USE_SLOWER_CAMERA")

                                                        ;

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          iVar6 = atoi(pcVar2);

                                                          *(bool *)(param_1 + 0x71) = 0 < iVar6;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,"INVERT_MOUSE");

                                                          if (iVar6 == 0) {

                                                            pcVar2 = strtok((char *)0x0,

                                                                            (char *)&local_510);

                                                            iVar6 = atoi(pcVar2);

                                                            *(bool *)(param_1 + 0xf) = 0 < iVar6;

                                                          }

                                                          else {

                                                            iVar6 = _stricmp(pcVar2,

                                                  "MOUSE_MOVE_IN_TOWN");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x25) = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"MOUSE_MOVE_IN_VEHICLE")

                                                    ;

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(bool *)(param_1 + 0x26) = 0 < iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"USE_VIBRATION");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 0x10) = 0 < iVar6;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"CAMERA_SNAP_LOCK");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          iVar6 = atoi(pcVar2);

                                                          *(bool *)(param_1 + 0x15) = 0 < iVar6;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,

                                                  "CAMERA_SNAPS_BEHIND_PLAYER");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x16) = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"CAMERA_EASIER_LOOK_UP")

                                                    ;

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(bool *)(param_1 + 0x72) = 0 < iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,

                                                  "SET_NEW_MISSION_ACTIVE");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x1a) = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,

                                                  "HIDE_WAYPOINTS_FOR_KILL");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x1b) = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"AUTO_UPDATE_TARGET");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(bool *)(param_1 + 0x1c) = 0 < iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"AUTO_TARGET_ATTACKER"

                                                                      );

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 0x1d) = 0 < iVar6;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,

                                                  "MOUSE_DRAGS_TOOLTIPS");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    *(bool *)(param_1 + 0x1e) = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"PREFER_STRAFE_IN_TOWN")

                                                    ;

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(bool *)(param_1 + 0x1f) = 0 < iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"DIALOGUE_FADES_IN");

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(bool *)(param_1 + 0x20) = 0 < iVar6;

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"CHAT_FILTER");

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          DAT_00af9218 = atoi(pcVar2);

                                                          if ((int)DAT_00af9218 < 0) {

                                                            DAT_00af9218 = DAT_00af9218 & 0x7fffffff

                                                            ;

                                                            iVar6 = FUN_007a69d0();

                                                            if (*(int *)(iVar6 + 0x2c) != 1) {

                                                              DAT_00af9218 = DAT_00af9218 &

                                                                             0xffffbfff;

                                                            }

                                                            iVar6 = FUN_007a69d0();

                                                            if (*(int *)(iVar6 + 0x2c) != 2) {

                                                              DAT_00af9218 = DAT_00af9218 &

                                                                             0xffff7fff;

                                                            }

                                                          }

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,

                                                  "CHAT_FILTER_SPECIALIZED");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    DAT_00af921c = atoi(pcVar2);

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"SUMMON_AI_STATE");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      *(byte *)(param_1 + 0x55) = (byte)iVar6;

                                                      if (2 < (byte)iVar6) {

                                                        *(uint8_t *)(param_1 + 0x55) = 0;

                                                      }

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,"SUMMON_DISTANCE_MODE"

                                                                      );

                                                      if (iVar6 == 0) {

                                                        pcVar2 = strtok((char *)0x0,

                                                                        (char *)&local_510);

                                                        iVar6 = atoi(pcVar2);

                                                        *(byte *)(param_1 + 0x56) = (byte)iVar6;

                                                        if (2 < (byte)iVar6) {

                                                          *(uint8_t *)(param_1 + 0x56) = 0;

                                                        }

                                                      }

                                                      else {

                                                        iVar6 = _stricmp(pcVar2,"FULL_QUICKBAR_RED")

                                                        ;

                                                        if (iVar6 == 0) {

                                                          pcVar2 = strtok((char *)0x0,

                                                                          (char *)&local_510);

                                                          iVar6 = atoi(pcVar2);

                                                          *(bool *)(param_1 + 0x27) = 0 < iVar6;

                                                        }

                                                        else {

                                                          iVar6 = _stricmp(pcVar2,"SHOW_STUNTS");

                                                          if (iVar6 == 0) {

                                                            pcVar2 = strtok((char *)0x0,

                                                                            (char *)&local_510);

                                                            iVar6 = atoi(pcVar2);

                                                            *(bool *)(param_1 + 0x28) = 0 < iVar6;

                                                          }

                                                          else {

                                                            iVar6 = _stricmp(pcVar2,"USE_FADING");

                                                            if (iVar6 == 0) {

                                                              pcVar2 = strtok((char *)0x0,

                                                                              (char *)&local_510);

                                                              iVar6 = atoi(pcVar2);

                                                              DAT_00aef950 = 0 < iVar6;

                                                            }

                                                            else {

                                                              iVar6 = _stricmp(pcVar2,

                                                  "PHYSX_ENABLED_TMP");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    DAT_00b036d9 = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"PHYSX_CARD_PRESENT");

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      DAT_00b036d8 = 0 < iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,

                                                  "PHYSX_ALLOW_FLUID_TMP");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    DAT_00af06e8 = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,

                                                  "PHYSX_ALLOW_DESTRUCTION_TMP");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    iVar6 = atoi(pcVar2);

                                                    DAT_00af06e9 = 0 < iVar6;

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,"PHYSX_ALLOW_CLOTH_TMP")

                                                    ;

                                                    if (iVar6 == 0) {

                                                      pcVar2 = strtok((char *)0x0,(char *)&local_510

                                                                     );

                                                      iVar6 = atoi(pcVar2);

                                                      DAT_00af06ea = 0 < iVar6;

                                                    }

                                                    else {

                                                      iVar6 = _stricmp(pcVar2,

                                                  "PHYSX_LIQUID_PARTICLE_SCALE");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    dVar9 = atof(pcVar2);

                                                    FUN_00401000((float)dVar9);

                                                  }

                                                  else {

                                                    iVar6 = _stricmp(pcVar2,

                                                  "PHYSX_DEBRIS_PARTICLE_SCALE");

                                                  if (iVar6 == 0) {

                                                    pcVar2 = strtok((char *)0x0,(char *)&local_510);

                                                    dVar9 = atof(pcVar2);

                                                    FUN_00401030((float)dVar9);

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

                }

              }

            }

          }

        }

      }

    }

    pcVar2 = fgets(local_400,0x400,local_508);

  } while( true );

}
