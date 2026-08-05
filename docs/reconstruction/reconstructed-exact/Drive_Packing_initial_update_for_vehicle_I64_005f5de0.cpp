// READABILITY (auto CF):
//  - Body size: ~762 non-empty decompiler lines.
//  - Control keywords: if×80, do×4, while×4, for×2, return×2, goto×2.
//  - Notable callees: BitStream_writeBits×67, BitStream_writeFlag×59, CONCAT31×27, BitStream_writeInt×15, CONCAT22×15, NAN×14, CONCAT21×7, CONCAT13×6.
//  - Strings: "Can\'t save ghost data for vehicle!"; "Packing initial update for vehicle %I64".
//  - Return sites: 2.

// =============================================================================
// Drive_Packing_initial_update_for_vehicle_I64_005f5de0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f5de0
// Address:   0x005f5de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Packing initial update for vehicle %I64"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint * __thiscall

VehicleNet_PackUpdate(int param_1,uint32_t /* or float bits */ param_2,uint param_3,uint param_4,uint32_t /* or float bits */ param_5)



{

  int iVar1;

  void *pWeapon;

  bool bVar2;

  char cVar3;

  uint8_t uVar4;

  short sVar5;

  int iVar6;

  undefined2 extraout_var;

  uint32_t /* or float bits */ uVar7;

  uint3 uVar12;

  float *pfVar8;

  undefined2 extraout_var_00;

  undefined2 extraout_var_01;

  undefined2 extraout_var_02;

  uint uVar9;

  undefined2 *puVar10;

  undefined2 extraout_var_03;

  undefined2 extraout_var_04;

  undefined2 extraout_var_05;

  uint32_t /* or float bits */ *puVar11;

  int iVar13;

  undefined2 extraout_var_06;

  undefined2 extraout_var_07;

  undefined2 extraout_var_08;

  undefined2 extraout_var_09;

  undefined2 extraout_var_10;

  undefined2 extraout_var_11;

  undefined2 extraout_var_12;

  undefined2 extraout_var_13;

  byte bVar14;

  short sVar15;

  int unaff_EBX;

  int iVar16;

  float *pfVar17;

  uint32_t /* or float bits */ uVar18;

  int iStack_54;

  int iStack_50;

  uint32_t /* or float bits */ uStack_4c;

  uint *puStack_48;

  int local_44;

  uint *puStack_40;

  uint32_t /* or float bits */ uStack_3c;

  uint32_t /* or float bits */ local_38;

  uint32_t /* or float bits */ uStack_34;

  uint32_t /* or float bits */ uStack_28;

  uint32_t /* or float bits */ uStack_24;

  uint32_t /* or float bits */ uStack_20;

  uint uStack_1c;

  uint32_t /* or float bits */ uStack_18;

  uint32_t /* or float bits */ uStack_14;

  

  local_38 = 0;

  local_44 = param_1;

  if (*(int *)(param_1 + 0x50) == 0) {

    FUN_007a4480(1,"Can\'t save ghost data for vehicle!");

    return (uint *)0x0;

  }

  iVar6 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1d4))();

  if (DAT_00d1798c == '\0') {

LAB_005f65ca:

    cVar3 = BitStream_writeFlag((param_3 & 0x80) != 0);

    if (cVar3 != '\0') {

      cVar3 = BitStream_writeFlag(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6) != 0);

      if (cVar3 != '\0') {

        FUN_005b2830(param_5,*(uint32_t /* or float bits */ *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6));

      }

      FUN_005b2830(param_5,*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6);

    }

  }

  else {

    if (DAT_00d02820 != '\0') {

      iVar13 = *(int *)(*(int *)(iVar6 + 4) + 4);

      FUN_007a4480(0xffffffff,"Packing initial update for vehicle %I64",

                   *(uint32_t /* or float bits */ *)(iVar13 + 0x164 + iVar6),*(uint32_t /* or float bits */ *)(iVar13 + 0x168 + iVar6));

    }

    FUN_005b1290(param_5);

    puStack_48 = *(uint **)(iVar6 + 0x1a8);

    BitStream_writeBits(0x20,&puStack_48);

    puStack_48 = *(uint **)(iVar6 + 0x1ac);

    BitStream_writeBits(0x20,&puStack_48);

    BitStream_writeFlag(*(uint8_t *)(iVar6 + 0x114));

    uStack_4c = CONCAT13(*(uint8_t *)(iVar6 + 0x288),(undefined3)uStack_4c);

    BitStream_writeBits(8,(int)&uStack_4c + 3);

    puStack_48 = *(uint **)(iVar6 + 0x1fc);

    uVar12 = CONCAT21(extraout_var,

                      ((float)puStack_48 == g_flOne) << 6 |

                      (NAN((float)puStack_48) || NAN(g_flOne)) << 2 | 2U |

                      (float)puStack_48 < g_flOne);

    if ((float)puStack_48 == g_flOne) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    uVar7 = BitStream_writeFlag(iVar13);

    if ((char)uVar7 != '\0') {

      puStack_40 = puStack_48;

      uVar7 = BitStream_writeBits(0x20,&puStack_40);

    }

    puStack_48 = *(uint **)(iVar6 + 0x200);

    uVar12 = CONCAT21((short)((uint)uVar7 >> 0x10),

                      ((float)puStack_48 == g_flOne) << 6 |

                      (NAN((float)puStack_48) || NAN(g_flOne)) << 2 | 2U |

                      (float)puStack_48 < g_flOne);

    if ((float)puStack_48 == g_flOne) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    uVar7 = BitStream_writeFlag(iVar13);

    if ((char)uVar7 != '\0') {

      puStack_40 = puStack_48;

      uVar7 = BitStream_writeBits(0x20,&puStack_40);

    }

    puStack_48 = *(uint **)(iVar6 + 0x204);

    uVar12 = CONCAT21((short)((uint)uVar7 >> 0x10),

                      ((float)puStack_48 == g_flOne) << 6 |

                      (NAN((float)puStack_48) || NAN(g_flOne)) << 2 | 2U |

                      (float)puStack_48 < g_flOne);

    if ((float)puStack_48 == g_flOne) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    uVar7 = BitStream_writeFlag(iVar13);

    if ((char)uVar7 != '\0') {

      puStack_40 = puStack_48;

      uVar7 = BitStream_writeBits(0x20,&puStack_40);

    }

    puStack_48 = *(uint **)(iVar6 + 0x208);

    uVar12 = CONCAT21((short)((uint)uVar7 >> 0x10),

                      ((float)puStack_48 == g_flOne) << 6 |

                      (NAN((float)puStack_48) || NAN(g_flOne)) << 2 | 2U |

                      (float)puStack_48 < g_flOne);

    if ((float)puStack_48 == g_flOne) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    uVar7 = BitStream_writeFlag(iVar13);

    if ((char)uVar7 != '\0') {

      puStack_40 = puStack_48;

      uVar7 = BitStream_writeBits(0x20,&puStack_40);

    }

    puStack_48 = *(uint **)(iVar6 + 0x20c);

    uVar12 = CONCAT21((short)((uint)uVar7 >> 0x10),

                      ((float)puStack_48 == g_flOne) << 6 |

                      (NAN((float)puStack_48) || NAN(g_flOne)) << 2 | 2U |

                      (float)puStack_48 < g_flOne);

    if ((float)puStack_48 == g_flOne) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    uVar7 = BitStream_writeFlag(iVar13);

    if ((char)uVar7 != '\0') {

      puStack_40 = puStack_48;

      uVar7 = BitStream_writeBits(0x20,&puStack_40);

    }

    puStack_48 = *(uint **)(iVar6 + 0x210);

    uVar12 = CONCAT21((short)((uint)uVar7 >> 0x10),

                      ((float)puStack_48 == g_flOne) << 6 |

                      (NAN((float)puStack_48) || NAN(g_flOne)) << 2 | 2U |

                      (float)puStack_48 < g_flOne);

    if ((float)puStack_48 == g_flOne) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    uVar7 = BitStream_writeFlag(iVar13);

    if ((char)uVar7 != '\0') {

      puStack_40 = puStack_48;

      uVar7 = BitStream_writeBits(0x20,&puStack_40);

    }

    puStack_48 = *(uint **)(iVar6 + 0x210);

    uVar12 = CONCAT21((short)((uint)uVar7 >> 0x10),

                      ((float)puStack_48 == g_flOne) << 6 |

                      (NAN((float)puStack_48) || NAN(g_flOne)) << 2 | 2U |

                      (float)puStack_48 < g_flOne);

    if ((float)puStack_48 == g_flOne) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    cVar3 = BitStream_writeFlag(iVar13);

    if (cVar3 != '\0') {

      puStack_40 = puStack_48;

      BitStream_writeBits(0x20,&puStack_40);

    }

    iVar13 = *(int *)(iVar6 + 0xf8);

    iVar16 = -1;

    uVar12 = (uint3)((uint)iVar13 >> 8);

    if ((*(uint *)(iVar13 + 0x40) & *(uint *)(iVar13 + 0x44)) == 0xffffffff) {

      iVar13 = (uint)uVar12 << 8;

    }

    else {

      iVar13 = CONCAT31(uVar12,1);

    }

    cVar3 = BitStream_writeFlag(iVar13);

    if (cVar3 != '\0') {

      BitStream_writeInt(*(uint32_t /* or float bits */ *)(*(int *)(iVar6 + 0xf8) + 0x40),0x12);

      puStack_40 = *(uint **)(*(int *)(iVar6 + 0xf8) + 0x48);

      BitStream_writeBits(0x20,&puStack_40);

      BitStream_writeFlag(*(uint8_t *)(*(int *)(iVar6 + 0xf8) + 0x51));

      BitStream_writeFlag(*(char *)(*(int *)(iVar6 + 0xf8) + 0x50) != '\0');

      puStack_40 = *(uint **)(*(int *)(iVar6 + 0xf8) + 0x4c);

      BitStream_writeBits(0x20,&puStack_40);

    }

    cVar3 = BitStream_writeFlag(*(int *)(iVar6 + 0x14c) != -1);

    if (cVar3 != '\0') {

      BitStream_writeInt(*(uint32_t /* or float bits */ *)(iVar6 + 0x14c),0x14);

    }

    iVar13 = *(int *)(iVar6 + 0x280);

    if (iVar13 == 0) {

      uStack_3c = 0xffffffff;

      uVar7 = 0;

    }

    else {

      iVar1 = *(int *)(*(int *)(iVar13 + 4) + 4);

      iVar16 = *(int *)(iVar1 + 0x164 + iVar13);

      uVar7 = *(uint32_t /* or float bits */ *)(iVar1 + 0x168 + iVar13);

      uStack_3c = uVar7;

    }

    cVar3 = BitStream_writeFlag(CONCAT31((int3)((uint)uVar7 >> 8),iVar16 != -1));

    if (cVar3 != '\0') {

      BitStream_writeInt(iVar16,0x14);

    }

    pfVar17 = (float *)(iVar6 + 0x28c);

    cVar3 = '\0';

    iVar13 = 8;

    pfVar8 = pfVar17;

    do {

      if (*pfVar8 != -NAN) {

        cVar3 = cVar3 + '\x01';

      }

      pfVar8 = pfVar8 + 1;

      iVar13 = iVar13 + -1;

    } while (iVar13 != 0);

    uStack_4c = CONCAT13(cVar3,(undefined3)uStack_4c);

    BitStream_writeBits(8,(int)&uStack_4c + 3);

    puStack_48 = (uint *)0x8;

    do {

      if ((uint *)*pfVar17 != (uint *)0xffffffff) {

        puStack_40 = (uint *)*pfVar17;

        BitStream_writeBits(0x10,&puStack_40);

      }

      pfVar17 = pfVar17 + 1;

      puStack_48 = (uint *)((int)puStack_48 + -1);

    } while (puStack_48 != (uint *)0x0);

    BitStream_writeFlag(*(int *)(iVar6 + 0x278) != 0);

    cVar3 = BitStream_writeFlag(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6) != 0);

    if (cVar3 != '\0') {

      iVar13 = *(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6);

      puStack_40 = *(uint **)(iVar13 + 0x160);

      uStack_3c = *(uint32_t /* or float bits */ *)(iVar13 + 0x164);

      BitStream_writeBits(0x40,&puStack_40);

      BitStream_writeFlag(CONCAT31((int3)((uint)*(int *)(iVar6 + 4) >> 8),

                                   *(uint8_t *)

                                    (*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6) +

                                    0x168)));

      BitStream_writeInt(*(uint32_t /* or float bits */ *)

                          (*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6) +

                                   0xa8) + 0x34),0x14);

      iVar13 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6) + 0x1dc))()

      ;

      cVar3 = BitStream_writeFlag(iVar13 != 0);

      iVar13 = **(int **)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6);

      if (cVar3 == '\0') {

        iVar13 = (**(code **)(iVar13 + 0x1d8))();

        cVar3 = BitStream_writeFlag(*(int *)(iVar13 + 0x128) != -1);

        if (cVar3 != '\0') {

          BitStream_writeInt(*(uint32_t /* or float bits */ *)(iVar13 + 0x128),0x14);

        }

        cVar3 = BitStream_writeFlag((*(uint *)(iVar13 + 0x218) & *(uint *)(iVar13 + 0x21c)) !=

                                    0xffffffff);

        if (cVar3 != '\0') {

          BitStream_writeInt(*(uint32_t /* or float bits */ *)(iVar13 + 0x218),0x14);

        }

        cVar3 = BitStream_writeFlag((*(uint *)(iVar13 + 0x220) & *(uint *)(iVar13 + 0x224)) !=

                                    0xffffffff);

        if (cVar3 != '\0') {

          BitStream_writeInt(*(uint32_t /* or float bits */ *)(iVar13 + 0x220),0x14);

        }

        uStack_1c = *(uint *)(iVar13 + 0x22c);

        uStack_14 = *(uint32_t /* or float bits */ *)(iVar13 + 0x234);

        if (((*(uint *)(iVar13 + 0x228) & uStack_1c) == 0xffffffff) &&

           ((char)*(uint32_t /* or float bits */ *)(iVar13 + 0x230) == '\0')) {

          bVar2 = true;

        }

        else {

          bVar2 = false;

        }

        cVar3 = BitStream_writeFlag(!bVar2);

        if (cVar3 != '\0') {

          puStack_40 = *(uint **)(iVar13 + 0x228);

          uStack_3c = *(uint32_t /* or float bits */ *)(iVar13 + 0x22c);

          uStack_18 = *(uint32_t /* or float bits */ *)(iVar13 + 0x230);

          uStack_14 = *(uint32_t /* or float bits */ *)(iVar13 + 0x234);

          uStack_1c = uStack_3c;

          BitStream_writeBits(0x40,&puStack_40);

          uStack_20 = *(uint32_t /* or float bits */ *)(iVar13 + 0x228);

          uStack_1c = *(uint *)(iVar13 + 0x22c);

          uStack_14 = *(uint32_t /* or float bits */ *)(iVar13 + 0x234);

          BitStream_writeFlag(*(uint32_t /* or float bits */ *)(iVar13 + 0x230));

        }

        BitStream_writeFlag(*(char *)(iVar13 + 0x205) == '\0');

        uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 4 + iVar13) + 0x27c))();

        uStack_4c = CONCAT13(uVar4,(undefined3)uStack_4c);

        BitStream_writeBits(8,(int)&uStack_4c + 3);

        BitStream_writeFlag(*(uint8_t *)(iVar13 + 0x30b));

      }

      else {

        iVar13 = (**(code **)(iVar13 + 0x1dc))();

        uVar18 = 0x11;

        uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 4 + iVar13) + 0x160))

                          (0x11);

        FUN_0042bb40(uVar7,uVar18);

        FUN_0042bb40(iVar13 + 0xcfc,0x33);

        uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 4 + iVar13) + 0x27c))();

        uStack_4c = CONCAT13(uVar4,(undefined3)uStack_4c);

        BitStream_writeBits(8,(int)&uStack_4c + 3);

        BitStream_writeFlag(*(uint8_t *)(iVar13 + 0x6b9));

        FUN_0042bb40(iVar6 + 0x1b0,0x21);

        puStack_40 = (uint *)CONCAT22(extraout_var_06,*(undefined2 *)(iVar13 + 0x6fc));

        BitStream_writeBits(0x10,&puStack_40);

        puStack_40 = (uint *)CONCAT22(extraout_var_00,*(undefined2 *)(iVar13 + 0x6f8));

        BitStream_writeBits(0x10,&puStack_40);

        puStack_40 = (uint *)CONCAT22(extraout_var_11,*(undefined2 *)(iVar13 + 0x708));

        BitStream_writeBits(0x10,&puStack_40);

        puStack_40 = (uint *)CONCAT22(extraout_var_07,*(undefined2 *)(iVar13 + 0x70c));

        BitStream_writeBits(0x10,&puStack_40);

        puStack_40 = (uint *)CONCAT22(extraout_var_01,*(undefined2 *)(iVar13 + 0x714));

        BitStream_writeBits(0x10,&puStack_40);

        puStack_40 = (uint *)CONCAT22(extraout_var_12,*(undefined2 *)(iVar13 + 0x710));

        BitStream_writeBits(0x10,&puStack_40);

        puStack_40 = (uint *)CONCAT22(extraout_var_08,*(undefined2 *)(iVar13 + 0x704));

        BitStream_writeBits(0x10,&puStack_40);

        puStack_40 = (uint *)CONCAT22(extraout_var_02,*(undefined2 *)(iVar13 + 0x700));

        BitStream_writeBits(0x10,&puStack_40);

      }

    }

    if (DAT_00d1798c == '\0') goto LAB_005f65ca;

    local_38 = 0x80;

  }

  cVar3 = BitStream_writeFlag((param_4 & 1) != 0);

  if (cVar3 != '\0') {

    BitStream_writeInt(*(uint32_t /* or float bits */ *)

                        (*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 600) + 4) + 4) + 0xac +

                                 *(int *)(iVar6 + 600)) + 0x34),0x14);

    iVar13 = *(int *)(iVar6 + 600);

    iVar16 = *(int *)(*(int *)(iVar13 + 4) + 4);

    puStack_40 = *(uint **)(iVar16 + 0x164 + iVar13);

    uStack_3c = *(uint32_t /* or float bits */ *)(iVar16 + 0x168 + iVar13);

    BitStream_writeBits(0x40,&puStack_40);

    iVar13 = *(int *)(*(int *)(iVar6 + 600) + 4);

    BitStream_writeFlag(CONCAT31((int3)((uint)iVar13 >> 8),

                                 *(uint8_t *)

                                  (*(int *)(iVar13 + 4) + 0x16c + *(int *)(iVar6 + 600))));

  }

  iVar13 = 0;

  puStack_48 = &DAT_009dd198;

  do {

    uVar9 = *puStack_48 & param_3 | puStack_48[1] & param_4;

    if (uVar9 == 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = CONCAT31((int3)(uVar9 >> 8),1);

    }

    cVar3 = BitStream_writeFlag(uVar7);

    if ((cVar3 != '\0') &&

       (cVar3 = BitStream_writeFlag(*(int *)(iVar13 + *(int *)(iVar6 + 0x260)) != 0), cVar3 != '\0')

       ) {

      iVar16 = *(int *)(iVar13 + *(int *)(iVar6 + 0x260));

      BitStream_writeInt(*(uint32_t /* or float bits */ *)

                          (*(int *)(*(int *)(*(int *)(iVar16 + 4) + 4) + 0xac + iVar16) + 0x34),0x14

                        );

      iVar16 = *(int *)(iVar13 + *(int *)(iVar6 + 0x260));

      iVar1 = *(int *)(*(int *)(iVar16 + 4) + 4);

      puStack_40 = *(uint **)(iVar1 + 0x164 + iVar16);

      uStack_3c = *(uint32_t /* or float bits */ *)(iVar1 + 0x168 + iVar16);

      BitStream_writeBits(0x40,&puStack_40);

      iVar16 = *(int *)(iVar13 + *(int *)(iVar6 + 0x260));

      iVar1 = *(int *)(iVar16 + 4);

      BitStream_writeFlag(CONCAT31((int3)((uint)iVar1 >> 8),

                                   *(uint8_t *)(*(int *)(iVar1 + 4) + 0x16c + iVar16)));

    }

    puStack_48 = puStack_48 + 2;

    iVar13 = iVar13 + 4;

  } while ((int)puStack_48 < 0x9dd1b0);

  cVar3 = BitStream_writeFlag((param_4 & 0x20) != 0);

  if ((cVar3 != '\0') && (cVar3 = BitStream_writeFlag(*(int *)(iVar6 + 0x264) != 0), cVar3 != '\0'))

  {

    BitStream_writeInt(*(uint32_t /* or float bits */ *)

                        (*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x264) + 4) + 4) + 0xac +

                                 *(int *)(iVar6 + 0x264)) + 0x34),0x14);

    iVar13 = *(int *)(iVar6 + 0x264);

    iVar16 = *(int *)(*(int *)(iVar13 + 4) + 4);

    puStack_40 = *(uint **)(iVar16 + 0x164 + iVar13);

    uStack_3c = *(uint32_t /* or float bits */ *)(iVar16 + 0x168 + iVar13);

    BitStream_writeBits(0x40,&puStack_40);

    iVar13 = *(int *)(*(int *)(iVar6 + 0x264) + 4);

    BitStream_writeFlag(CONCAT31((int3)((uint)iVar13 >> 8),

                                 *(uint8_t *)

                                  (*(int *)(iVar13 + 4) + 0x16c + *(int *)(iVar6 + 0x264))));

  }

  cVar3 = BitStream_writeFlag((param_4 & 0x40) != 0);

  if ((cVar3 != '\0') && (cVar3 = BitStream_writeFlag(*(int *)(iVar6 + 0x26c) != 0), cVar3 != '\0'))

  {

    BitStream_writeInt(*(uint32_t /* or float bits */ *)

                        (*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x26c) + 4) + 4) + 0xac +

                                 *(int *)(iVar6 + 0x26c)) + 0x34),0x14);

    iVar13 = *(int *)(iVar6 + 0x26c);

    iVar16 = *(int *)(*(int *)(iVar13 + 4) + 4);

    puStack_40 = *(uint **)(iVar16 + 0x164 + iVar13);

    uStack_3c = *(uint32_t /* or float bits */ *)(iVar16 + 0x168 + iVar13);

    BitStream_writeBits(0x40,&puStack_40);

    iVar13 = *(int *)(*(int *)(iVar6 + 0x26c) + 4);

    BitStream_writeFlag(CONCAT31((int3)((uint)iVar13 >> 8),

                                 *(uint8_t *)

                                  (*(int *)(iVar13 + 4) + 0x16c + *(int *)(iVar6 + 0x26c))));

  }

  if ((param_3 & 0x40000000) == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x40000000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if ((cVar3 != '\0') && (cVar3 = BitStream_writeFlag(*(int *)(iVar6 + 0x254) != 0), cVar3 != '\0'))

  {

    BitStream_writeInt(*(uint32_t /* or float bits */ *)

                        (*(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x254) + 4) + 4) + 0xac +

                                 *(int *)(iVar6 + 0x254)) + 0x34),0x14);

    iVar13 = *(int *)(iVar6 + 0x254);

    iVar16 = *(int *)(*(int *)(iVar13 + 4) + 4);

    puStack_40 = *(uint **)(iVar16 + 0x164 + iVar13);

    uStack_3c = *(uint32_t /* or float bits */ *)(iVar16 + 0x168 + iVar13);

    BitStream_writeBits(0x40,&puStack_40);

    iVar13 = *(int *)(*(int *)(iVar6 + 0x254) + 4);

    BitStream_writeFlag(CONCAT31((int3)((uint)iVar13 >> 8),

                                 *(uint8_t *)

                                  (*(int *)(iVar13 + 4) + 0x16c + *(int *)(iVar6 + 0x254))));

    puVar10 = (undefined2 *)(**(code **)(**(int **)(iVar6 + 0x254) + 0x38))();

    puStack_40 = (uint *)CONCAT22(extraout_var_09,*puVar10);

    BitStream_writeBits(0x10,&puStack_40);

    puStack_40 = (uint *)CONCAT22(extraout_var_03,puVar10[1]);

    BitStream_writeBits(0x10,&puStack_40);

    puStack_40 = (uint *)CONCAT22(extraout_var_13,puVar10[3]);

    BitStream_writeBits(0x10,&puStack_40);

    puStack_40 = (uint *)CONCAT22(extraout_var_10,puVar10[4]);

    BitStream_writeBits(0x10,&puStack_40);

    puStack_40 = (uint *)CONCAT22(extraout_var_04,puVar10[5]);

    BitStream_writeBits(0x10,&puStack_40);

    puStack_40 = (uint *)CONCAT22(extraout_var_05,*(undefined2 *)(*(int *)(iVar6 + 0x254) + 0xcc));

    BitStream_writeBits(0x10,&puStack_40);

  }

  iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

  if ((iVar13 == 0) || ((param_3 & 0x10000000) == 0)) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x10000000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

    BitStream_writeInt(*(uint8_t *)(iVar13 + 0x6b4),4);

  }

  iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

  if ((iVar13 == 0) || ((param_3 & 0x400000) == 0)) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x400000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

    uStack_4c = *(int *)(iVar13 + 0xcf4);

    BitStream_writeBits(0x20,&uStack_4c);

    iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

    iStack_50 = *(int *)(iVar13 + 0xcf8);

    BitStream_writeBits(0x20,&iStack_50);

    iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

    FUN_0042bb40(iVar13 + 0xcfc,0x33);

  }

  if (((param_3 & 0x1000000) == 0) ||

     (iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0),

     iVar13 == 0)) {

    uVar7 = 0;

  }

  else {

    uVar7 = 1;

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

    puStack_48 = (uint *)CONCAT22((short)((uint)iVar13 >> 0x10),*(undefined2 *)(iVar13 + 0x514));

    BitStream_writeBits(0x10,&puStack_48);

  }

  cVar3 = BitStream_writeFlag((param_3 & 0x20) != 0);

  if (cVar3 != '\0') {

    iVar13 = *(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6);

    puStack_48 = *(uint **)(iVar13 + 0x40);

    local_44 = *(int *)(iVar13 + 0x44);

    uStack_20 = *(uint32_t /* or float bits */ *)(iVar13 + 0x48);

    uStack_1c = *(uint *)(iVar13 + 0x4c);

    BitStream_writeBits(0x40,&puStack_48);

  }

  cVar3 = BitStream_writeFlag((param_3 & 8) != 0);

  iVar13 = uStack_4c;

  if (cVar3 != '\0') {

    iVar16 = (**(code **)(**(int **)(uStack_4c + 0x50) + 0x23c))();

    if (iVar16 < 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = (**(code **)(**(int **)(iVar13 + 0x50) + 0x23c))();

    }

    BitStream_writeInt(uVar7,0x12);

    uVar7 = (**(code **)(**(int **)(iVar13 + 0x50) + 0x198))();

    BitStream_writeFlag(uVar7);

  }

  cVar3 = BitStream_writeFlag((param_3 & 0x40) != 0);

  if (cVar3 != '\0') {

    iVar16 = (**(code **)(**(int **)(iVar13 + 0x50) + 0x244))();

    if (iVar16 < 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = (**(code **)(**(int **)(iVar13 + 0x50) + 0x244))();

    }

    BitStream_writeInt(uVar7,0x12);

  }

  uVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

  if (uVar9 == 0) {

    param_4 = param_3 & 0x80000000 | param_4;

    uVar9 = 0;

    if (param_4 != 0) {

      uVar9 = CONCAT31((int3)(param_4 >> 8),1);

      goto LAB_005f6cdd;

    }

  }

  uVar9 = uVar9 & 0xffffff00;

LAB_005f6cdd:

  cVar3 = BitStream_writeFlag(uVar9);

  if (cVar3 != '\0') {

    iVar16 = (**(code **)(**(int **)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xb0 + iVar6) + 0x1d8))();

    unaff_EBX = CONCAT13(*(uint8_t *)(iVar16 + 0x26c),(int3)unaff_EBX);

    BitStream_writeBits(8,&stack0xffffffab);

  }

  cVar3 = BitStream_writeFlag((param_3 & 2) != 0);

  if (cVar3 != '\0') {

    if (*(int *)(iVar6 + 8) == 0) {

      puVar11 = (uint32_t /* or float bits */ *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0x84 + iVar6);

    }

    else {

      puVar11 = (uint32_t /* or float bits */ *)(*(int *)(*(int *)(iVar6 + 8) + 0x3c) + 0xb0);

    }

    local_38 = puVar11[1];

    uStack_4c = *puVar11;

    uStack_34 = puVar11[2];

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = local_38;

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = uStack_34;

    BitStream_writeBits(0x20,&uStack_4c);

    if (*(int *)(iVar6 + 8) == 0) {

      puVar11 = (uint32_t /* or float bits */ *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0x94 + iVar6);

    }

    else {

      puVar11 = (uint32_t /* or float bits */ *)(*(int *)(*(int *)(iVar6 + 8) + 0x3c) + 0x30);

    }

    uStack_28 = puVar11[1];

    uStack_4c = *puVar11;

    uStack_24 = puVar11[2];

    uStack_20 = puVar11[3];

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = uStack_28;

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = uStack_24;

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = uStack_20;

    BitStream_writeBits(0x20,&uStack_4c);

    if (*(int *)(iVar6 + 8) == 0) {

      puVar11 = &DAT_00d02830;

    }

    else {

      puVar11 = (uint32_t /* or float bits */ *)(*(int *)(*(int *)(iVar6 + 8) + 0x3c) + 0x40);

    }

    local_38 = puVar11[1];

    uStack_4c = *puVar11;

    uStack_34 = puVar11[2];

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = local_38;

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = uStack_34;

    BitStream_writeBits(0x20,&uStack_4c);

    if (*(int *)(iVar6 + 8) == 0) {

      local_38 = DAT_00d02834;

      uStack_4c = DAT_00d02830;

      uStack_34 = DAT_00d02838;

    }

    else {

      iVar13 = *(int *)(*(int *)(iVar6 + 8) + 0x3c);

      local_38 = *(uint32_t /* or float bits */ *)(iVar13 + 0x54);

      uStack_4c = *(uint32_t /* or float bits */ *)(iVar13 + 0x50);

      uStack_34 = *(uint32_t /* or float bits */ *)(iVar13 + 0x58);

    }

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = local_38;

    BitStream_writeBits(0x20,&uStack_4c);

    uStack_4c = uStack_34;

    BitStream_writeBits(0x20,&uStack_4c);

    iVar13 = 0;

    iStack_54 = 3;

    do {

      pWeapon = *(void **)(*(int *)(iVar6 + 0x260) + iVar13 * 4);

      if ((pWeapon != (void *)0x0) && (*(char *)((int)pWeapon + 199) != '\0')) {

        Weapon_CanFireHeatCheck(pWeapon);

      }

      iVar13 = iVar13 + 1;

      iStack_54 = iStack_54 + -1;

    } while (iStack_54 != 0);

    BitStream_writeBits(8,&stack0xffffffab);

    if ((*(char *)(iVar6 + 0x61c) == '\0') && (*(char *)(iVar6 + 0x109) == '\0')) {

      bVar14 = 0;

    }

    else {

      bVar14 = 1;

    }

    cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x198))();

    if (cVar3 != '\0') {

      bVar14 = bVar14 | 4;

    }

    unaff_EBX = CONCAT13(bVar14,(int3)unaff_EBX);

    BitStream_writeBits(8,&stack0xffffffab);

    BitStream_writeQuantizedFloat(*(uint32_t /* or float bits */ *)(iVar6 + 0x614),6);

    BitStream_writeQuantizedFloat(*(uint32_t /* or float bits */ *)(iVar6 + 0x618),6);

    uStack_4c = *(int *)(iVar6 + 0x158);

    BitStream_writeBits(0x20,&uStack_4c);

    iVar13 = iStack_50;

  }

  cVar3 = BitStream_writeFlag((param_3 & 4) != 0);

  if (cVar3 != '\0') {

    if (*(int *)(*(int *)(iVar13 + 0x50) + 0xa0) == 0) {

      uStack_4c = -1;

      puStack_48 = (uint *)0xffffffff;

      iStack_50 = (uint)iStack_50._1_3_ << 8;

    }

    else {

      iVar16 = *(int *)(*(int *)(iVar13 + 0x50) + 0xa0);

      uStack_4c = *(int *)(iVar16 + 0x160);

      puStack_48 = *(uint **)(iVar16 + 0x164);

      iStack_50 = CONCAT31(iStack_50._1_3_,*(uint8_t *)(iVar16 + 0x168));

    }

    BitStream_writeBits(0x40,&uStack_4c);

    BitStream_writeFlag(iStack_50);

  }

  iVar16 = (**(code **)(**(int **)(iVar13 + 0x50) + 0x210))(0);

  if ((iVar16 == 0) || ((param_3 & 0x200000) == 0)) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x200000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iVar16 = (**(code **)(**(int **)(iVar13 + 0x50) + 0x210))(0);

    sVar5 = *(short *)(iVar16 + 0x13e);

    if (199 < sVar5) {

      sVar5 = 200;

    }

    (**(code **)(**(int **)(iVar13 + 0x50) + 0x210))(0);

    (**(code **)(**(int **)(iVar13 + 0x50) + 0x210))(0);

    iVar13 = (**(code **)(**(int **)(iVar13 + 0x50) + 0x210))(0);

    sVar15 = *(short *)(iVar13 + 0x140);

    if (199 < sVar15) {

      sVar15 = 200;

    }

    BitStream_writeBits(0x20,&iStack_50);

    iStack_50 = (int)sVar5;

    BitStream_writeBits(0x20,&iStack_50);

    iStack_50 = unaff_EBX;

    BitStream_writeBits(0x20,&iStack_50);

    iStack_50 = (int)sVar15;

    BitStream_writeBits(0x20,&iStack_50);

  }

  if ((param_3 & 0x20000000) == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x20000000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iStack_50 = *(int *)(iVar6 + 0x150);

    BitStream_writeBits(0x20,&iStack_50);

  }

  if ((param_3 & 0x2000000) == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x2000000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iStack_50 = *(int *)(iVar6 + 0x148);

    BitStream_writeBits(0x20,&iStack_50);

  }

  if ((param_3 & 0x4000000) == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x4000000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iStack_50 = *(int *)(iVar6 + 0x144);

    BitStream_writeBits(0x20,&iStack_50);

  }

  if ((param_3 & 0x8000000) == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x8000000) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if ((cVar3 != '\0') &&

     (iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x214))(),

     iVar13 != 0)) {

    iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x214))();

    iStack_50 = (int)*(short *)(iVar13 + 300);

    BitStream_writeBits(0x20,&iStack_50);

  }

  if ((param_3 & 0x100) == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = CONCAT31((int3)((param_3 & 0x100) >> 8),1);

  }

  cVar3 = BitStream_writeFlag(uVar7);

  if (cVar3 != '\0') {

    iVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

    uVar4 = 0;

    if (iVar13 != 0) {

      iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x210))(0);

      uVar4 = *(uint8_t *)(iVar6 + 0x529);

    }

    BitStream_writeFlag(uVar4);

  }

  return puStack_48;

}
