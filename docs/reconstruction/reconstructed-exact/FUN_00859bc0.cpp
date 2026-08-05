// =============================================================================
// FUN_00859bc0  (scaffold twin of Client_UI_MapView_DrawEntitiesFovOverlay)
// -----------------------------------------------------------------------------
// Stable ID: aa_00859bc0
// Address:   0x00859bc0 – 0x0085a9ef  (autoassault.exe, image base 0x400000)
// System:    client UI / map-view overlay
// Generated: 2026-07-23 scaffold; W23-N dual seal header 2026-07-29
// Exactness: Decompiler-mirror body below. Sealed phase contract lives in
//            Client_UI_MapView_DrawEntitiesFovOverlay.cpp + raw W23-N append.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// W23-N SEALED FACTS:
//   ABI: __thiscall (ECX=this); plain ret C3; frame sub esp,0x104; align 16
//   Body: 3631 B; gate this+0x488 + world/local + list heads A/B
//   Phases: worldA → worldB → markers → patrol → mission → special → squad → FOV
//   Constants: 0.5 (a0f298); optional scale min(af931c,af9320)=1.0
//   Vtbl DATA @ 00a65a54
// =============================================================================

// READABILITY (auto CF):
//  - Body size: ~417 non-empty decompiler lines.
//  - Control keywords: if×37, while×8, do×6, return×2, goto×1.
//  - Notable callees: FUN_004141c0×4, FUN_00859a90×4, FUN_00859260×3, FUN_005134e0×2, FUN_00757890×2, FUN_00930fc0×2.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 * - Prefer named clean file for port contract; this file preserves decomp CF.
 */

void __fastcall FUN_00859bc0(int param_1)



{

  int *piVar1;

  byte *pbVar2;

  int *piVar3;

  char cVar4;

  float *pfVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int *piVar10;

  float fVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint32_t /* width from decompiler */ uVar16;

  float fStack_114;

  float fStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  float fStack_104;

  float fStack_100;

  float fStack_fc;

  float fStack_f8;

  float fStack_f4;

  float fStack_e4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  float fStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

  float fStack_a0;

  float fStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  float fStack_88;

  float fStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  float fStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  float fStack_70;

  float fStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  float fStack_44;

  uint uStack_40;

  uint uStack_3c;

  char cStack_38;

  uint8_t auStack_28 [4];

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  if ((((*(int *)(param_1 + 0x488) != 0) && (DAT_00d1b6d8 != 0)) && (DAT_00d1b644 != 0)) &&

     (*(int *)(DAT_00d1b644 + 0xe4e8) != 0)) {

    pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                           DAT_00d1b6d8) + 0x1a0))();

    fStack_e0 = *pfVar5;

    fStack_dc = pfVar5[1];

    fStack_d8 = pfVar5[2];

    fStack_d4 = pfVar5[3];

    iVar6 = *(int *)(DAT_00d1b644 + 0xe4e8);

    fStack_114 = (float)(iVar6 + 0x28);

    fStack_104 = (float)(iVar6 + 0x48);

    if ((fStack_114 != 0.0) && (fStack_104 != 0.0)) {

      piVar10 = *(int **)(iVar6 + 0x2c);

      if (piVar10 != *(int **)(iVar6 + 0x30)) {

        do {

          piVar1 = (int *)*piVar10;

          if (((piVar1 != (int *)0x0) &&

              (uStack_10c = piVar10, cVar4 = (**(code **)(*piVar1 + 0x198))(), cVar4 == '\0')) &&

             ((((uint)piVar1[0x5f] >> 3 & 1) == 0 &&

              ((cVar4 = FUN_005134e0(), cVar4 == '\0' &&

               (iVar6 = (**(code **)(*piVar1 + 0x210))(0), iVar6 != DAT_00d1b6d8)))))) {

            iVar6 = (**(code **)(*piVar1 + 0x1d4))();

            if (iVar6 == 0) {

              (**(code **)(*piVar1 + 0x1d8))();

            }

            else {

              iVar6 = (**(code **)(*piVar1 + 0x210))(0);

              if (iVar6 == 0) {

                uVar16 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x488) + 0x530);

                uStack_24 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x488) + 0x534);

                FUN_00930fc0(&DAT_00d1a840,&fStack_e4,1,1);

                uVar12 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x488) + 0x5d0);

                uVar15 = 0;

                uVar14 = 0;

                pfVar5 = &fStack_e4;

                uVar13 = uStack_24;

                uVar7 = (**(code **)(*piVar1 + 0x1a0))(pfVar5,uVar16,uStack_24,uVar12,0,0);

                FUN_00859260(uVar7,pfVar5,uVar16,uVar13,uVar12,uVar14,uVar15);

                piVar10 = uStack_10c;

              }

            }

          }

          piVar10 = piVar10 + 1;

        } while (piVar10 != *(int **)((int)fStack_114 + 8));

      }

      iVar6 = *(int *)(param_1 + 0x68) + 1;

      *(int *)(param_1 + 0x68) = iVar6;

      *(float *)(param_1 + 0x74) = (float)-iVar6;

      if (*(int *)(param_1 + 0x70) < iVar6) {

        *(int *)(param_1 + 0x70) = iVar6;

      }

      piVar10 = *(int **)((int)fStack_104 + 4);

      uStack_10c = piVar10;

      if (piVar10 != *(int **)((int)fStack_104 + 8)) {

        do {

          piVar1 = (int *)*piVar10;

          if ((((piVar1 != (int *)0x0) &&

               (uStack_10c = piVar10, iVar6 = (**(code **)(*piVar1 + 0x1dc))(), iVar6 != 0)) &&

              (cVar4 = (**(code **)(*piVar1 + 0x198))(), cVar4 == '\0')) &&

             (iVar6 = (**(code **)(*piVar1 + 0x19c))(),

             (*(uint *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0x180 + iVar6) >> 3 & 1) == 0)) {

            (**(code **)(*piVar1 + 0x19c))();

            cVar4 = FUN_005134e0();

            if ((cVar4 == '\0') && (iVar6 = (**(code **)(*piVar1 + 0x1dc))(), iVar6 != DAT_00d1b6d8)

               ) {

              fStack_e4 = (float)((uint)fStack_e4 & 0xffffff00);

              if (*(char *)(DAT_00d1b644 + 0xf6) == '\0') {

                if (*(int *)(DAT_00d1b6d8 + 0xcb0) != 0) {

                  iVar6 = (**(code **)(*piVar1 + 0x1dc))();

                  piVar10 = uStack_10c;

                  if ((*(int *)(iVar6 + 0xca8) == *(int *)(DAT_00d1b6d8 + 0xca8)) &&

                     (*(int *)(iVar6 + 0xcac) == *(int *)(DAT_00d1b6d8 + 0xcac))) goto LAB_00859e9a;

                }

              }

              else {

LAB_00859e9a:

                fStack_e4 = (float)CONCAT31(fStack_e4._1_3_,1);

              }

              FUN_00930fc0(&DAT_00d1a840,&fStack_114,1,1);

              iVar6 = *(int *)(param_1 + 0x488);

              uVar16 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x5d0);

              uVar14 = 0;

              uVar12 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x520);

              uVar13 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x524);

              pfVar5 = &fStack_114;

              fVar11 = fStack_e4;

              uVar7 = (**(code **)(*piVar1 + 0x1a0))(pfVar5,uVar12,uVar13,uVar16,fStack_e4,0);

              FUN_00859260(uVar7,pfVar5,uVar12,uVar13,uVar16,fVar11,uVar14);

            }

          }

          piVar10 = piVar10 + 1;

          uStack_10c = piVar10;

        } while (piVar10 != *(int **)((int)fStack_104 + 8));

      }

      iVar6 = *(int *)(param_1 + 0x68) + 1;

      *(int *)(param_1 + 0x68) = iVar6;

      *(float *)(param_1 + 0x74) = (float)-iVar6;

      if (*(int *)(param_1 + 0x70) < iVar6) {

        *(int *)(param_1 + 0x70) = iVar6;

      }

      if (DAT_00d1b6d8 != 0) {

        piVar10 = (int *)*DAT_00d1d964;

        if (piVar10 != DAT_00d1d964) {

          do {

            iVar6 = piVar10[2];

            if (*(int **)(iVar6 + 0x20) == (int *)0x0) {

              fStack_100 = *(float *)(iVar6 + 0x10);

              fStack_fc = *(float *)(iVar6 + 0x14);

              fStack_f8 = *(float *)(iVar6 + 0x18);

              fStack_f4 = *(float *)(iVar6 + 0x1c);

            }

            else {

              (**(code **)(**(int **)(iVar6 + 0x20) + 0x144))();

              iVar6 = piVar10[2];

              iVar8 = *(int *)(iVar6 + 0x20);

              fStack_100 = *(float *)(iVar8 + 0x80);

              fStack_fc = *(float *)(iVar8 + 0x84);

              fStack_f8 = *(float *)(iVar8 + 0x88);

              fStack_f4 = *(float *)(iVar8 + 0x8c);

            }

            iVar6 = *(int *)(iVar6 + 8);

            if ((-1 < iVar6) && (iVar6 < 9)) {

              iVar8 = *(int *)(param_1 + 0x488);

              FUN_00859260(&fStack_100,piVar10[2] + 0xc,*(uint32_t /* width from decompiler */ *)(iVar8 + 0x538),

                           *(uint32_t /* width from decompiler */ *)(iVar8 + 0x53c),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x624 + iVar6 * 4)

                           ,0,0);

            }

            piVar10 = (int *)*piVar10;

          } while (piVar10 != DAT_00d1d964);

        }

        *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;

        iVar6 = *(int *)(param_1 + 0x68);

        *(float *)(param_1 + 0x74) = (float)-iVar6;

        if (*(int *)(param_1 + 0x70) < iVar6) {

          *(int *)(param_1 + 0x70) = iVar6;

        }

        if (((*(int *)((int)DAT_00d1ad10 + 0x11c) != 0) &&

            (fStack_104 = (float)(*(int *)((int)DAT_00d1ad10 + 0x120) -

                                  *(int *)((int)DAT_00d1ad10 + 0x11c) >> 2), fStack_104 != 0.0)) &&

           (uStack_10c = (int *)0x0, 0 < (int)fStack_104)) {

          do {

            piVar10 = uStack_10c;

            Client_EvalAutoPatrolWaypoint(DAT_00d1ad10,&uStack_40,&fStack_ac);

            if (((uStack_40 & uStack_3c) != 0xffffffff) || (cStack_38 != '\0')) {

              fStack_100 = fStack_ac;

              fStack_fc = (float)uStack_a8;

              fStack_f8 = (float)uStack_a4;

              fStack_114 = (float)(CONCAT31(fStack_114._1_3_,

                                            -(*(char *)((int)DAT_00d1ad10 + 8) != '\0')) &

                                  0xffffff02);

              fStack_f4 = 0.0;

              FUN_00859a90(param_1,fStack_114);

              piVar10 = uStack_10c;

            }

            uStack_10c = (int *)((int)piVar10 + 1);

          } while ((int)uStack_10c < (int)fStack_104);

        }

        *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;

        iVar6 = *(int *)(param_1 + 0x68);

        *(float *)(param_1 + 0x74) = (float)-iVar6;

        if (*(int *)(param_1 + 0x70) < iVar6) {

          *(int *)(param_1 + 0x70) = iVar6;

        }

        fStack_114 = DAT_00d1b938;

        if ((DAT_00d1b938 != 0.0) &&

           (piVar10 = (int *)**(int **)((int)DAT_00d1b938 + 0x524), fVar11 = DAT_00d1b938,

           uStack_10c = piVar10, piVar10 != *(int **)((int)DAT_00d1b938 + 0x524))) {

          do {

            if ((int *)piVar10[4] != (int *)0x0) {

              uVar16 = 0x65;

              (**(code **)(*(int *)piVar10[4] + 0x1a0))(0x65);

              FUN_00859a90(param_1,uVar16);

              piVar10 = uStack_10c;

              fVar11 = fStack_114;

            }

            if (*(char *)((int)piVar10 + 0x15) == '\0') {

              piVar1 = (int *)piVar10[2];

              if (*(char *)((int)piVar1 + 0x15) == '\0') {

                cVar4 = *(char *)(*piVar1 + 0x15);

                piVar10 = piVar1;

                piVar1 = (int *)*piVar1;

                while (uStack_10c = piVar10, cVar4 == '\0') {

                  cVar4 = *(char *)(*piVar1 + 0x15);

                  piVar10 = piVar1;

                  piVar1 = (int *)*piVar1;

                }

              }

              else {

                cVar4 = *(char *)(piVar10[1] + 0x15);

                piVar3 = (int *)piVar10[1];

                piVar1 = piVar10;

                while ((piVar10 = piVar3, uStack_10c = piVar10, cVar4 == '\0' &&

                       (piVar1 == (int *)piVar10[2]))) {

                  cVar4 = *(char *)(piVar10[1] + 0x15);

                  piVar3 = (int *)piVar10[1];

                  piVar1 = piVar10;

                }

              }

            }

          } while (piVar10 != *(int **)((int)fVar11 + 0x524));

        }

        *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;

        iVar6 = *(int *)(param_1 + 0x68);

        *(float *)(param_1 + 0x74) = (float)-iVar6;

        if (*(int *)(param_1 + 0x70) < iVar6) {

          *(int *)(param_1 + 0x70) = iVar6;

        }

        if (DAT_00d1ad1c != '\0') {

          fStack_ac = DAT_00d1ad20;

          uStack_a8 = DAT_00d1ad24;

          uStack_a4 = DAT_00d1ad28;

          FUN_004e9530(&uStack_40,&fStack_ac);

          FUN_00859a90(param_1,100);

        }

        *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;

        iVar6 = *(int *)(param_1 + 0x68);

        *(float *)(param_1 + 0x74) = (float)-iVar6;

        if (*(int *)(param_1 + 0x70) < iVar6) {

          *(int *)(param_1 + 0x70) = iVar6;

        }

        fStack_114 = *(float *)(DAT_00d1b6d8 + 0xcb0);

        if (fStack_114 != 0.0) {

          fStack_104 = 0.0;

          do {

            fVar11 = fStack_104;

            iVar6 = FUN_00574760(fStack_104);

            if (((iVar6 != 0) && (iVar6 != DAT_00d1b6d8)) &&

               (iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x19c

                                    ))(),

               (*(uint *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x180 + iVar8) >> 3 & 1) == 0)) {

              uVar16 = 1;

              (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0x1a0))(1);

              FUN_00859a90(param_1,uVar16);

              fVar11 = fStack_104;

            }

            fStack_104 = (float)((int)fVar11 + 1);

          } while ((int)fStack_104 < 4);

        }

      }

      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;

      iVar6 = *(int *)(param_1 + 0x68);

      *(float *)(param_1 + 0x74) = (float)-iVar6;

      if (*(int *)(param_1 + 0x70) < iVar6) {

        *(int *)(param_1 + 0x70) = iVar6;

      }

      uStack_94 = 0xffffffff;

      uStack_7c = 0xffffffff;

      uStack_64 = 0xffffffff;

      uStack_4c = 0xffffffff;

      uStack_98 = 0;

      uStack_80 = 0;

      uStack_68 = 0;

      uStack_50 = 0;

      if ((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 == DAT_00d1b778)) {

        puVar9 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8)

                             + 0x1a4))();

        uStack_20 = *puVar9;

        uStack_1c = puVar9[1];

        uStack_18 = puVar9[2];

        uStack_14 = puVar9[3];

        FUN_004e8a40(&uStack_20,&fStack_c0);

        FUN_004e8ad0(&uStack_20,&fStack_d0);

        iVar6 = *(int *)(param_1 + 0x488);

        uStack_10c = (int *)0xff32ff32;

        if (*(int *)(iVar6 + 0x224) != 0) {

          pbVar2 = *(byte **)(iVar6 + 0x224);

          uStack_10c = (int *)CONCAT13((char)(((uint)pbVar2[3] * 0xff) / 0xff),

                                       CONCAT21(CONCAT11((char)(((uint)pbVar2[2] * 0x32) / 0xff),

                                                         (char)(((uint)pbVar2[1] * 0xff) / 0xff)),

                                                (char)(((uint)*pbVar2 * 0x32) / 0xff)));

        }

        fStack_104 = *(float *)(iVar6 + 0x514);

        if (*(char *)(iVar6 + 0x5b9) == '\0') {

          fVar11 = DAT_00af9320;

          if (DAT_00af931c < DAT_00af9320) {

            fVar11 = DAT_00af931c;

          }

          fStack_104 = (fVar11 / *(float *)(iVar6 + 0x500)) * fStack_104;

        }

        fStack_104 = fStack_104 * *(float *)(iVar6 + 0x50c) * DAT_00a0f298;

        fStack_e4 = 0.0 - fStack_104;

        fStack_fc = fStack_cc * fStack_e4 + fStack_bc * fStack_104 + fStack_dc;

        fStack_100 = fStack_e4 * fStack_d0 + fStack_c0 * fStack_104 + fStack_e0;

        fStack_f8 = fStack_c8 * fStack_e4 + fStack_b8 * fStack_104 + fStack_d8;

        fStack_f4 = fStack_c4 * fStack_e4 + fStack_b4 * fStack_104 + fStack_d4;

        pfVar5 = (float *)FUN_004141c0(auStack_28);

        uVar16 = uStack_10c;

        fStack_114 = *pfVar5;

        fStack_110 = pfVar5[1];

        fStack_a0 = *(float *)(*(int *)(param_1 + 0x488) + 0x590) + fStack_114;

        fStack_9c = *(float *)(*(int *)(param_1 + 0x488) + 0x594) + fStack_110;

        uStack_90 = 0;

        uStack_8c = 0;

        fStack_fc = fStack_cc * fStack_104 + fStack_bc * fStack_104 + fStack_dc;

        fStack_100 = fStack_d0 * fStack_104 + fStack_c0 * fStack_104 + fStack_e0;

        uStack_94 = uStack_10c;

        fStack_f8 = fStack_c8 * fStack_104 + fStack_b8 * fStack_104 + fStack_d8;

        fStack_f4 = fStack_c4 * fStack_104 + fStack_b4 * fStack_104 + fStack_d4;

        pfVar5 = (float *)FUN_004141c0(&uStack_10c);

        fStack_114 = *pfVar5;

        fStack_110 = pfVar5[1];

        fStack_88 = *(float *)(*(int *)(param_1 + 0x488) + 0x590) + fStack_114;

        fStack_84 = *(float *)(*(int *)(param_1 + 0x488) + 0x594) + fStack_110;

        fStack_78 = g_flOne;

        uStack_74 = 0;

        fStack_fc = fStack_cc * fStack_104 + fStack_bc * fStack_e4 + fStack_dc;

        fStack_100 = fStack_d0 * fStack_104 + fStack_e4 * fStack_c0 + fStack_e0;

        fStack_f8 = fStack_c8 * fStack_104 + fStack_b8 * fStack_e4 + fStack_d8;

        fStack_f4 = fStack_c4 * fStack_104 + fStack_b4 * fStack_e4 + fStack_d4;

        uStack_7c = uVar16;

        pfVar5 = (float *)FUN_004141c0(&uStack_40);

        fStack_114 = *pfVar5;

        fStack_110 = pfVar5[1];

        fStack_70 = *(float *)(*(int *)(param_1 + 0x488) + 0x590) + fStack_114;

        fStack_6c = *(float *)(*(int *)(param_1 + 0x488) + 0x594) + fStack_110;

        fStack_60 = g_flOne;

        fStack_5c = g_flOne;

        uStack_64 = uVar16;

        fStack_fc = fStack_cc * fStack_e4 + fStack_bc * fStack_e4 + fStack_dc;

        fStack_100 = fStack_e4 * fStack_d0 + fStack_e4 * fStack_c0 + fStack_e0;

        fStack_f8 = fStack_c8 * fStack_e4 + fStack_b8 * fStack_e4 + fStack_d8;

        fStack_f4 = fStack_c4 * fStack_e4 + fStack_b4 * fStack_e4 + fStack_d4;

        pfVar5 = (float *)FUN_004141c0(&fStack_ac);

        fStack_114 = *pfVar5;

        fStack_110 = pfVar5[1];

        iVar6 = *(int *)(param_1 + 0x488);

        fStack_58 = *(float *)(iVar6 + 0x590) + fStack_114;

        fStack_54 = *(float *)(iVar6 + 0x594) + fStack_110;

        uStack_48 = 0;

        uStack_4c = uVar16;

        fStack_44 = g_flOne;

        if (*(int *)(iVar6 + 0x5cc) != 0) {

          FUN_00757890(&fStack_a0,4,*(int *)(iVar6 + 0x5cc),1,&DAT_00d1ecac);

          return;

        }

        FUN_00757890(&fStack_a0,4,&DAT_00d1ec78,1,&DAT_00d1ecac);

      }

    }

  }

  return;

}
