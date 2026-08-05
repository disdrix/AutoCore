// READABILITY (auto CF):
//  - Body size: ~751 non-empty decompiler lines.
//  - Control keywords: if×90, return×7, goto×4, for×3, do×1, switch×1, while×1.
//  - Notable callees: _wcsicmp×38, FUN_00799300×12, FUN_007996d0×12, FUN_00798bb0×6, FUN_004a79e0×3, FUN_004b99c0×3, FUN_00799460×3, SysFreeString×3.
//  - Strings: "Create"; "Death"; "DeathOverkill"; "DeathFiery".
//  - Return sites: 7.

// =============================================================================
// Drive_driver
// -----------------------------------------------------------------------------
// Stable ID: aa_004a4fa0
// Address:   0x004a4fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "driver"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x004a5789) */



void * Drive_driver(BSTR param_1,int *param_2,byte *param_3)



{

  float fVar1;

  char cVar2;

  byte bVar3;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  char *pcVar8;

  int *piVar9;

  int *piVar10;

  int *unaff_ESI;

  code *pcVar11;

  BSTR unaff_EDI;

  int *piVar12;

  uint32_t /* width from decompiler */ uStack_980;

  int *piStack_97c;

  int *piStack_96c;

  BSTR pOStack_968;

  uint32_t /* width from decompiler */ uStack_964;

  void *local_960;

  int *piStack_95c;

  void *pvStack_958;

  int iStack_954;

  int iStack_950;

  int *piStack_94c;

  int local_948;

  uint32_t /* width from decompiler */ uStack_944;

  wchar_t awStack_938 [4];

  wchar_t awStack_930 [252];

  uint8_t *puStack_738;

  uint8_t auStack_734 [128];

  uint8_t *puStack_6b4;

  uint8_t auStack_6b0 [128];

  uint8_t auStack_630 [1016];

  uint32_t /* width from decompiler */ uStack_238;

  uint32_t /* width from decompiler */ auStack_234 [128];

  void *pvStack_34;

  void *pvStack_1c;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009a112f;

  pvStack_14 = ExceptionList;

  local_960 = (void *)0x0;

  piStack_97c = &local_948;

  uStack_980 = param_1;

  local_c = 0;

  ExceptionList = &pvStack_14;

  iVar4 = (**(code **)(*(int *)param_1 + 0x44))();

  if ((iVar4 == 0) && (iStack_950 != 0)) {

    cVar2 = FUN_00798bb0();

    pcVar11 = _wcsicmp_exref;

    if (cVar2 != '\0') {

      iVar4 = _wcsicmp(L"Create",awStack_930);

      if (iVar4 == 0) {

        *param_2 = 0;

      }

      else {

        iVar4 = _wcsicmp(L"Death",awStack_930);

        if (iVar4 == 0) {

          *param_2 = 1;

        }

        else {

          iVar4 = _wcsicmp(L"DeathOverkill",awStack_930);

          if (iVar4 == 0) {

            *param_2 = 0x10;

          }

          else {

            iVar4 = _wcsicmp(L"DeathFiery",awStack_930);

            if (iVar4 == 0) {

              *param_2 = 0x11;

            }

            else {

              iVar4 = _wcsicmp(L"DeathPeaceful",awStack_930);

              if (iVar4 == 0) {

                *param_2 = 0x12;

              }

              else {

                iVar4 = _wcsicmp(L"Status",awStack_930);

                if (iVar4 == 0) {

                  *param_2 = 2;

                }

                else {

                  iVar4 = _wcsicmp(L"StatusFirer",awStack_930);

                  if (iVar4 == 0) {

                    *param_2 = 0x13;

                  }

                  else {

                    iVar4 = _wcsicmp(L"PersistentStatus",awStack_930);

                    if (iVar4 == 0) {

                      *param_2 = 0x16;

                    }

                    else {

                      iVar4 = _wcsicmp(L"Charge",awStack_930);

                      if (iVar4 == 0) {

                        *param_2 = 3;

                      }

                      else {

                        iVar4 = _wcsicmp(L"Fire",awStack_930);

                        if (iVar4 == 0) {

                          *param_2 = 4;

                        }

                        else {

                          iVar4 = _wcsicmp(L"Hit",awStack_930);

                          if (iVar4 == 0) {

                            *param_2 = 5;

                          }

                          else {

                            iVar4 = _wcsicmp(L"AOE",awStack_930);

                            if (iVar4 == 0) {

                              *param_2 = 0x14;

                            }

                            else {

                              iVar4 = _wcsicmp(L"AOEFirer",awStack_930);

                              if (iVar4 == 0) {

                                *param_2 = 0x15;

                              }

                              else {

                                iVar4 = _wcsicmp(L"HitVehicle",awStack_930);

                                if (iVar4 == 0) {

                                  *param_2 = 6;

                                }

                                else {

                                  iVar4 = _wcsicmp(L"HitFirer",awStack_930);

                                  if (iVar4 == 0) {

                                    *param_2 = 0xe;

                                  }

                                  else {

                                    iVar4 = _wcsicmp(L"Miss",awStack_930);

                                    if (iVar4 == 0) {

                                      *param_2 = 0xc;

                                    }

                                    else {

                                      iVar4 = _wcsicmp(L"Stop",awStack_930);

                                      if (iVar4 == 0) {

                                        *param_2 = 7;

                                      }

                                      else {

                                        iVar4 = _wcsicmp(L"Light",awStack_930);

                                        if (iVar4 == 0) {

                                          *param_2 = 8;

                                        }

                                        else {

                                          iVar4 = _wcsicmp(L"DamagedNone",awStack_930);

                                          if (iVar4 == 0) {

                                            *param_2 = 9;

                                          }

                                          else {

                                            iVar4 = _wcsicmp(L"DamagedLow",awStack_930);

                                            if (iVar4 == 0) {

                                              *param_2 = 10;

                                            }

                                            else {

                                              iVar4 = _wcsicmp(L"DamagedHigh",awStack_930);

                                              if (iVar4 == 0) {

                                                *param_2 = 0xb;

                                              }

                                              else {

                                                iVar4 = _wcsicmp(L"Collision",awStack_930);

                                                if (iVar4 == 0) {

                                                  *param_2 = 0xd;

                                                }

                                                else {

                                                  iVar4 = _wcsicmp(L"Suspension",awStack_930);

                                                  if (iVar4 == 0) {

                                                    *param_2 = 0x17;

                                                  }

                                                  else {

                                                    iVar4 = _wcsicmp(L"Activate",awStack_930);

                                                    if (iVar4 == 0) {

                                                      *param_2 = 0xf;

                                                    }

                                                    else {

                                                      *param_2 = *param_3 + 100;

                                                      *param_3 = *param_3 + 1;

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

      piStack_94c = operator_new(0x240);

      pvStack_14._0_1_ = 1;

      if (piStack_94c == (int *)0x0) {

        pvVar5 = (void *)0x0;

      }

      else {

        pvVar5 = (void *)FUN_004ba310();

      }

      pvStack_14 = (void *)((uint)pvStack_14._1_3_ << 8);

      *(int *)((int)pvVar5 + 0x28) = *param_2;

      pvStack_958 = pvVar5;

      FUN_004b6850();

      cVar2 = FUN_00799460(iStack_950);

      if (cVar2 != '\0') {

        *(uint32_t /* width from decompiler */ *)((int)pvVar5 + 0x58) = uStack_944;

        FUN_00799300();

      }

      piVar12 = &iStack_954;

      iStack_954 = 0;

      (**(code **)(*(int *)param_1 + 0x30))();

      if (piStack_95c == (int *)0x0) {

LAB_004a5e8c:

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar5);

      }

      (**(code **)(*piStack_95c + 0x20))(piStack_95c);

      piVar10 = (int *)0x0;

      piStack_97c = (int *)0x0;

      piStack_95c = (int *)0x0;

      if (0 < (int)pvStack_958) {

        do {

          iVar4 = (**(code **)(*uStack_964 + 0x1c))(uStack_964,piStack_95c,&stack0xfffff68c);

          if ((iVar4 < 0) || (unaff_ESI == (int *)0x0)) {

            FUN_007a4480(0,"VOG_DEBUG_STOP");

            break;

          }

          SysFreeString(unaff_EDI);

          unaff_EDI = (BSTR)0x0;

          (**(code **)(*unaff_ESI + 0x1c))(unaff_ESI,&stack0xfffff688);

          iVar4 = (*pcVar11)(L"Group",uStack_980);

          if (iVar4 == 0) {

            iVar4 = (**(code **)(*piStack_97c + 0x44))(piStack_97c,&stack0xfffff674);

            if ((-1 < iVar4) && (piStack_97c != (int *)0x0)) {

              FUN_00798bb0(piStack_97c,L"owner");

              iVar4 = (*pcVar11)(L"wheels",auStack_630);

              if (iVar4 == 0) {

                unaff_ESI = (int *)0xb;

              }

              else {

                iVar4 = (*pcVar11)(L"exhaust");

                if (iVar4 == 0) {

                  unaff_ESI = (int *)0xf;

                }

                else {

                  iVar4 = (*pcVar11)(L"lights");

                  if (iVar4 == 0) {

                    unaff_ESI = (int *)0x11;

                  }

                  else {

                    iVar4 = (*pcVar11)(L"brakes");

                    if (iVar4 == 0) {

                      unaff_ESI = (int *)0x10;

                    }

                    else {

                      iVar4 = (*pcVar11)(L"front");

                      if (iVar4 == 0) {

                        unaff_ESI = (int *)0x1;

                      }

                      else {

                        iVar4 = (*pcVar11)(L"back");

                        if (iVar4 == 0) {

                          unaff_ESI = (int *)0x2;

                        }

                        else {

                          iVar4 = (*pcVar11)(L"left");

                          if (iVar4 == 0) {

                            unaff_ESI = (int *)0x8;

                          }

                          else {

                            iVar4 = (*pcVar11)(L"right");

                            if (iVar4 == 0) {

                              unaff_ESI = (int *)0x7;

                            }

                            else {

                              iVar4 = (*pcVar11)(&DAT_009c9ef0);

                              if (iVar4 == 0) {

                                unaff_ESI = (int *)0x9;

                              }

                              else {

                                iVar4 = (*pcVar11)(L"bottom");

                                if (iVar4 == 0) {

                                  unaff_ESI = (int *)0xa;

                                }

                                else {

                                  iVar4 = (*pcVar11)(L"frontLeft");

                                  if (iVar4 == 0) {

                                    unaff_ESI = (int *)0x4;

                                  }

                                  else {

                                    iVar4 = (*pcVar11)(L"frontRight");

                                    if (iVar4 == 0) {

                                      unaff_ESI = (int *)0x3;

                                    }

                                    else {

                                      iVar4 = (*pcVar11)(L"rearLeft");

                                      if (iVar4 == 0) {

                                        unaff_ESI = (int *)0x6;

                                      }

                                      else {

                                        iVar4 = (*pcVar11)(L"rearRight");

                                        if (iVar4 == 0) {

                                          unaff_ESI = (int *)0x5;

                                        }

                                        else {

                                          iVar4 = (*pcVar11)(L"driver");

                                          if (iVar4 == 0) {

                                            unaff_ESI = (int *)0xc;

                                          }

                                          else {

                                            iVar4 = (*pcVar11)(L"engine");

                                            if (iVar4 == 0) {

                                              unaff_ESI = (int *)0xd;

                                            }

                                            else {

                                              iVar4 = (*pcVar11)(L"ornament");

                                              if (iVar4 == 0) {

                                                unaff_ESI = (int *)0xe;

                                              }

                                              else {

                                                iVar4 = (*pcVar11)(L"weaponTurret");

                                                if (iVar4 == 0) {

                                                  unaff_ESI = (int *)0x12;

                                                }

                                                else {

                                                  iVar4 = (*pcVar11)(L"weaponFront");

                                                  if (iVar4 == 0) {

                                                    unaff_ESI = (int *)0x13;

                                                  }

                                                  else {

                                                    iVar4 = (*pcVar11)(L"weaponRear");

                                                    if (iVar4 == 0) {

                                                      unaff_ESI = (int *)0x14;

                                                    }

                                                    else {

                                                      iVar4 = (*pcVar11)(L"weaponMelee");

                                                      unaff_ESI = (int *)((-(uint)(iVar4 != 0) &

                                                                          0xffffffeb) + 0x15);

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

              FUN_004a7f80();

              (**(code **)(*piStack_97c + 8))();

              piVar10 = unaff_ESI;

            }

          }

          else {

            iVar4 = (*pcVar11)(L"Particle",uStack_980);

            if (iVar4 == 0) {

              cVar2 = FUN_004a34f0(piStack_96c,pvVar5);

joined_r0x004a5e86:

              if (cVar2 == '\0') goto LAB_004a5e8c;

            }

            else {

              iVar4 = (*pcVar11)(L"Geometry");

              if (iVar4 == 0) {

                FUN_004a3fa0(piStack_96c,pvVar5);

              }

              else {

                iVar4 = (*pcVar11)(L"Trail");

                if (iVar4 == 0) {

                  puVar6 = (uint32_t /* width from decompiler */ *)FUN_0049e540(piStack_96c);

                  if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

LAB_004a60f6:

                    FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

                    operator_delete(pvVar5);

                  }

                }

                else {

                  iVar4 = (*pcVar11)(L"Lightning");

                  if (iVar4 != 0) {

                    iVar4 = (*pcVar11)(L"Sound");

                    if (iVar4 == 0) {

                      iVar4 = (**(code **)(*piStack_96c + 0x44))(piStack_96c);

                      if ((-1 < iVar4) && (piStack_97c != (int *)0x0)) {

                        pcVar7 = operator_new(0x138);

                        fVar1 = g_flOne;

                        pcVar8 = pcVar7;

                        for (iVar4 = 0x4e; iVar4 != 0; iVar4 = iVar4 + -1) {

                          pcVar8[0] = '\0';

                          pcVar8[1] = '\0';

                          pcVar8[2] = '\0';

                          pcVar8[3] = '\0';

                          pcVar8 = pcVar8 + 4;

                        }

                        *(float *)(pcVar7 + 0x11c) = fVar1;

                        *(uint32_t /* width from decompiler */ *)(pcVar7 + 0x110) = DAT_009c7c28;

                        *(uint32_t /* width from decompiler */ *)(pcVar7 + 0x114) = DAT_009c7c2c;

                        pcVar7[0x104] = '\0';

                        pcVar7[0x105] = '\0';

                        pcVar7[0x106] = '\0';

                        pcVar7[0x107] = '\0';

                        switch(*param_2) {

                        case 0:

                          pcVar7[0x104] = 'F';

                          pcVar7[0x105] = '\0';

                          pcVar7[0x106] = '\0';

                          pcVar7[0x107] = '\0';

                          break;

                        case 1:

                        case 0x10:

                        case 0x11:

                        case 0x12:

                          pcVar7[0x104] = '2';

                          pcVar7[0x105] = '\0';

                          pcVar7[0x106] = '\0';

                          pcVar7[0x107] = '\0';

                          break;

                        case 4:

                          pcVar7[0x104] = '\n';

                          pcVar7[0x105] = '\0';

                          pcVar7[0x106] = '\0';

                          pcVar7[0x107] = '\0';

                          break;

                        case 5:

                        case 6:

                        case 0xe:

                          pcVar7[0x104] = '\r';

                          pcVar7[0x105] = '\0';

                          pcVar7[0x106] = '\0';

                          pcVar7[0x107] = '\0';

                          break;

                        case 0xc:

                          pcVar7[0x104] = '\f';

                          pcVar7[0x105] = '\0';

                          pcVar7[0x106] = '\0';

                          pcVar7[0x107] = '\0';

                          break;

                        case 0xd:

                          pcVar7[0x104] = '(';

                          pcVar7[0x105] = '\0';

                          pcVar7[0x106] = '\0';

                          pcVar7[0x107] = '\0';

                        }

                        FUN_00798bb0(piStack_97c,L"soundName");

                        puVar6 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

                        strncpy(pcVar7,(char *)*puVar6,0x103);

                        if (puStack_6b4 != auStack_6b0) {

                          free(puStack_6b4);

                        }

                        FUN_007996d0(piStack_97c,L"looping");

                        FUN_007996d0(piStack_97c,L"unlinked",pcVar7 + 0x108);

                        FUN_007996d0(piStack_97c,L"Sound3D",pcVar7 + 0x109);

                        FUN_007996d0(piStack_97c,L"eventPlay",pcVar7 + 0x10a);

                        FUN_007996d0(piStack_97c,L"soundRegion",pcVar7 + 0x10c);

                        FUN_00799300(piStack_97c,L"radius",pcVar7 + 0x110);

                        cVar2 = FUN_00799300(piStack_97c,L"maxradius");

                        if ((cVar2 == '\0') &&

                           (cVar2 = FUN_00799300(piStack_97c,L"maxRadius"), cVar2 == '\0')) {

                          *(uint32_t /* width from decompiler */ *)(pcVar7 + 0x114) = DAT_009c7c2c;

                        }

                        FUN_00799300(piStack_97c,L"fadeTime");

                        FUN_00799300(piStack_97c,L"volume",pcVar7 + 0x11c);

                        FUN_007996d0(piStack_97c,L"hasStereo",pcVar7 + 0x130);

                        FUN_00799300(piStack_97c,L"rpmMultiplier",pcVar7 + 0x134);

                        FUN_007996d0(piStack_97c,L"localOnly",pcVar7 + 0x131);

                        bVar3 = FUN_00798bb0(piStack_97c,L"soundType",awStack_938);

                        unaff_EDI = (BSTR)((uint)bVar3 << 0x18);

                        if (bVar3 != 0) {

                          iVar4 = _wcsicmp(L"Generic",awStack_938);

                          if (iVar4 == 0) {

                            pcVar7[0x104] = '\0';

                            pcVar7[0x105] = '\0';

                            pcVar7[0x106] = '\0';

                            pcVar7[0x107] = '\0';

                          }

                          else {

                            iVar4 = _wcsicmp(L"ENGINE_MY_IDLE",awStack_938);

                            if (iVar4 == 0) {

                              pcVar7[0x104] = '\x18';

                              pcVar7[0x105] = '\0';

                              pcVar7[0x106] = '\0';

                              pcVar7[0x107] = '\0';

                            }

                            else {

                              iVar4 = _wcsicmp(L"ENGINE_MY_ACCEL",awStack_938);

                              if (iVar4 == 0) {

                                pcVar7[0x104] = '\x14';

                                pcVar7[0x105] = '\0';

                                pcVar7[0x106] = '\0';

                                pcVar7[0x107] = '\0';

                              }

                              else {

                                iVar4 = _wcsicmp(L"ENGINE_MY_DECEL",awStack_938);

                                if (iVar4 == 0) {

                                  pcVar7[0x104] = '\x15';

                                  pcVar7[0x105] = '\0';

                                  pcVar7[0x106] = '\0';

                                  pcVar7[0x107] = '\0';

                                }

                                else {

                                  iVar4 = _wcsicmp(L"MY_BRAKING",awStack_938);

                                  if (iVar4 == 0) {

                                    pcVar7[0x104] = '\x16';

                                    pcVar7[0x105] = '\0';

                                    pcVar7[0x106] = '\0';

                                    pcVar7[0x107] = '\0';

                                  }

                                  else {

                                    iVar4 = _wcsicmp(L"MY_HORN",awStack_938);

                                    if (iVar4 == 0) {

                                      pcVar7[0x104] = '\x17';

                                      pcVar7[0x105] = '\0';

                                      pcVar7[0x106] = '\0';

                                      pcVar7[0x107] = '\0';

                                    }

                                    else {

                                      iVar4 = _wcsicmp(L"Collision",awStack_938);

                                      if (iVar4 == 0) {

                                        pcVar7[0x104] = '(';

                                        pcVar7[0x105] = '\0';

                                        pcVar7[0x106] = '\0';

                                        pcVar7[0x107] = '\0';

                                      }

                                      else {

                                        iVar4 = _wcsicmp(L"Weather",awStack_938);

                                        if (iVar4 == 0) {

                                          pcVar7[0x104] = 'P';

                                          pcVar7[0x105] = '\0';

                                          pcVar7[0x106] = '\0';

                                          pcVar7[0x107] = '\0';

                                        }

                                      }

                                    }

                                  }

                                }

                              }

                            }

                          }

                        }

                        pcVar8 = pcVar7;

                        Client_GetMissionCompleteAudioTable(pcVar7);

                        iVar4 = FUN_007249c0(pcVar8);

                        if (iVar4 == 0) {

                    /* WARNING: Subroutine does not return */

                          operator_delete(pcVar7);

                        }

                        FUN_004a79e0();

                        (**(code **)(*piStack_97c + 8))();

                        piVar10 = unaff_ESI;

                        pcVar11 = _wcsicmp_exref;

                        pvVar5 = local_960;

                      }

                    }

                    else {

                      iVar4 = (*pcVar11)(L"MusicEvent");

                      if (iVar4 == 0) {

                        iVar4 = (**(code **)(*piStack_96c + 0x44))(piStack_96c);

                        if (((-1 < iVar4) && (piStack_97c != (int *)0x0)) &&

                           (pcVar8 = operator_new(200), fVar1 = g_flOne, pcVar11 = _wcsicmp_exref,

                           *param_2 == 0)) {

                          pcVar7 = pcVar8;

                          for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {

                            pcVar7[0] = '\0';

                            pcVar7[1] = '\0';

                            pcVar7[2] = '\0';

                            pcVar7[3] = '\0';

                            pcVar7 = pcVar7 + 4;

                          }

                          *(float *)(pcVar8 + 0x94) = fVar1;

                          FUN_00798bb0(piStack_97c,L"name");

                          puVar6 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

                          strncpy(pcVar8,(char *)*puVar6,0x7f);

                          if (puStack_738 != auStack_734) {

                            free(puStack_738);

                          }

                          FUN_007996d0(piStack_97c,L"looping");

                          FUN_00799300(piStack_97c,L"fadeIn",pcVar8 + 0x8c);

                          FUN_00799300(piStack_97c,L"fadeOut",pcVar8 + 0x90);

                          FUN_00799300(piStack_97c,L"maxRadius",pcVar8 + 0x9c);

                          FUN_00799300(piStack_97c,L"timeBetweenLoop",pcVar8 + 0x98);

                          FUN_007996d0(piStack_97c,L"muteAtMaxRadius",pcVar8 + 0xa4);

                          uStack_964 = (int *)CONCAT13(1,(undefined3)uStack_964);

                          FUN_007996d0(piStack_97c,L"isBackground");

                          FUN_007996d0(piStack_97c,L"isRegion",pcVar8 + 0xbc);

                          FUN_00799300(piStack_97c,L"volumeMultipler",pcVar8 + 0x94);

                          pcVar8[0xb8] = '\x02';

                          pcVar8[0xb9] = '\0';

                          pcVar8[0xba] = '\0';

                          pcVar8[0xbb] = '\0';

                          FUN_004a79e0();

                          (**(code **)(*piStack_97c + 8))();

                          pcVar11 = _wcsicmp_exref;

                          pvVar5 = local_960;

                        }

                      }

                      else {

                        iVar4 = (*pcVar11)(L"Force");

                        if (iVar4 == 0) {

                          iVar4 = FUN_0049f2a0(piStack_96c);

                          *(int *)((int)pvVar5 + 0x60) = iVar4;

                          *(void **)(iVar4 + 0x2c) = pvVar5;

                        }

                        else {

                          iVar4 = (*pcVar11)(L"Include");

                          if (iVar4 == 0) {

                            cVar2 = FUN_0049f9a0(piStack_96c,&piStack_95c);

                            goto joined_r0x004a5e86;

                          }

                          iVar4 = (*pcVar11)(L"Parameter");

                          if (iVar4 == 0) {

                            iVar4 = (**(code **)(*piStack_96c + 0x44))(piStack_96c);

                            if ((-1 < iVar4) && (piVar12 != (int *)0x0)) {

                              piVar9 = operator_new(0x28);

                              *piVar9 = 0;

                              piVar9[1] = 0;

                              piVar9[2] = 0;

                              piVar9[3] = 0;

                              piVar9[4] = 0;

                              piVar9[5] = 0;

                              piVar9[6] = 0;

                              piVar9[7] = 0;

                              piVar9[8] = 0;

                              piVar9[9] = 0;

                              FUN_00799460(piVar12,&DAT_009c9b2c,piVar9,10);

                              cVar2 = FUN_00799460(piVar12,L"CPAttacherID",piVar9 + 9,10);

                              if (cVar2 == '\0') {

                                piVar9[9] = -1;

                              }

                              uStack_980 = (BSTR)((uint)uStack_980 & 0xffffff);

                              FUN_007996d0(piVar12,L"update",(int)&uStack_980 + 3);

                              *(uint8_t *)(piVar9 + 8) = uStack_980._3_1_;

                              FUN_007994c0(piVar12,L"multiplier",piVar9 + 2,0,0,0);

                              uStack_238 = 0;

                              puVar6 = auStack_234;

                              for (iVar4 = 0x81; iVar4 != 0; iVar4 = iVar4 + -1) {

                                *puVar6 = 0;

                                puVar6 = puVar6 + 1;

                              }

                              FUN_00798bb0(piVar12,L"type",&uStack_238);

                              iVar4 = _wcsicmp(L"targetDirection",(wchar_t *)&uStack_238);

                              if (iVar4 == 0) {

                                piVar9[1] = 1;

                              }

                              else {

                                iVar4 = _wcsicmp(L"target",(wchar_t *)&uStack_238);

                                if (iVar4 == 0) {

                                  piVar9[1] = 0;

                                }

                                else {

                                  iVar4 = _wcsicmp(L"missAbsolute",(wchar_t *)&uStack_238);

                                  if (iVar4 == 0) {

                                    piVar9[1] = 5;

                                  }

                                  else {

                                    iVar4 = _wcsicmp(L"missRelative",(wchar_t *)&uStack_238);

                                    if (iVar4 == 0) {

                                      piVar9[1] = 6;

                                    }

                                    else {

                                      iVar4 = _wcsicmp(L"targetLength",(wchar_t *)&uStack_238);

                                      if (iVar4 == 0) {

                                        piVar9[1] = 4;

                                      }

                                      else {

                                        iVar4 = _wcsicmp(L"number",(wchar_t *)&uStack_238);

                                        piVar9[1] = 3 - (uint)(iVar4 != 0);

                                      }

                                    }

                                  }

                                }

                              }

                              iStack_950 = *piVar9;

                              piStack_94c = piVar9;

                              FUN_004a7580(&local_948,&iStack_950);

                              if ((char)uStack_944 == '\0') {

                    /* WARNING: Subroutine does not return */

                                operator_delete(piVar9);

                              }

                            }

                            (**(code **)(*piVar12 + 8))(piVar12);

                            pcVar11 = _wcsicmp_exref;

                            pvVar5 = local_960;

                          }

                          else {

                            iVar4 = (*pcVar11)(L"Fluid");

                            if (((iVar4 == 0) && (DAT_00af06e8 != '\0')) &&

                               (cVar2 = FUN_004a6910(), cVar2 != '\0')) {

                              iVar4 = FUN_0049f430(piStack_96c);

                              if (iVar4 == 0) goto LAB_004a60f6;

                              FUN_004b92b0();

                            }

                          }

                        }

                      }

                    }

                    goto LAB_004a5c50;

                  }

                  puVar6 = (uint32_t /* width from decompiler */ *)FUN_0049e830(piStack_96c);

                  if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

                    FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

                    operator_delete(pvVar5);

                  }

                }

                puVar6[9] = piVar10;

                *puVar6 = pvVar5;

                puVar6[10] = 0;

                FUN_004a79e0();

              }

            }

          }

LAB_004a5c50:

          (**(code **)(*piStack_96c + 8))();

          piStack_95c = (int *)((int)piStack_95c + 1);

        } while ((int)piStack_95c < (int)pvStack_958);

      }

      (**(code **)(*uStack_964 + 8))(uStack_964);

      (**(code **)(*uStack_964 + 8))(uStack_964);

      SysFreeString(uStack_980);

      ExceptionList = pvStack_34;

      return pvVar5;

    }

  }

  else {

    FUN_007a4480();

  }

  SysFreeString(pOStack_968);

  ExceptionList = pvStack_1c;

  return (void *)0x0;

}
