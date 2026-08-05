// READABILITY (auto CF):
//  - Body size: ~345 non-empty decompiler lines.
//  - Control keywords: if×44, goto×11, return×8, do×3, while×3.
//  - Notable callees: CONCAT31×4, Client_GetMissionCompleteAudioTable×4, FUN_007258a0×2, CNDHash_LookupByKey, FUN_004b7e50, FUN_004ba740, FUN_004e9530, FUN_00541a80.
//  - Return sites: 8.

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b7e50
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Client_GetMissionCompleteAudioTable"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004b7e50 clean capture (not modernized).
//
// Address:  0x004b7e50  (autoassault.exe, image base 0x400000)
// Stable:   aa_004b7e50
// Stable ID: aa_004b7e50
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004b7e50_*.md
//           Original Ghidra symbol: FUN_004b7e50
//
// Exactness: Body mirrors reconstructed-exact/FUN_004b7e50*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b7e50
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7e50
// Address:   0x004b7e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "Client_GetMissionCompleteAudioTable"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall

Mission_Uses_Client_GetMissionCompleteAudioTable_004b7e50(int param_1,char param_2,int param_3,byte *param_4,float param_5,float param_6,

            float param_7)



{

  uint *puVar1;

  byte bVar2;

  void *pvVar3;

  int iVar4;

  int *piVar5;

  byte *pbVar6;

  int iVar7;

  int iVar8;

  byte *pbVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  undefined3 uVar12;

  bool bVar13;

  longlong lVar14;

  uint64_t uVar15;

  byte *pbVar16;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  uint uVar20;

  uint32_t /* width from decompiler */ uVar21;

  uint32_t /* width from decompiler */ uVar22;

  uint32_t /* width from decompiler */ uVar23;

  uint8_t *puVar24;

  uint32_t /* width from decompiler */ *puVar25;

  uint32_t /* width from decompiler */ uVar26;

  int iStack_7c;

  int *piStack_78;

  uint32_t /* width from decompiler */ auStack_6c [3];

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  TFID_16 TStack_50;

  uint8_t auStack_40 [16];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [28];

  

  if (*(int *)(param_1 + 0x1f0) == 0) {

    return;

  }

  if (param_3 == 0) {

    if (*(int *)(param_1 + 0x10) == 0) {

      param_3 = 0;

    }

    else {

      param_3 = (**(code **)(**(int **)(param_1 + 0x10) + 0x1cc))();

      if (param_3 != 0) goto LAB_004b7e90;

    }

  }

  else {

LAB_004b7e90:

    uVar17 = *(uint *)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 0xa8 + param_3) + 0xfc);

    pvVar3 = (void *)FUN_00541a80();

    pvVar3 = CNDHash_LookupByKey(pvVar3,uVar17);

    if ((((*(int *)(param_1 + 0x28) == 0) && (pvVar3 != (void *)0x0)) &&

        (*(int *)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 0xac + param_3) + 0x34) != 0x11e))

       && ((*(int *)((int)pvVar3 + 0x148) == 0 &&

           (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) + 0x1cc

                                ))(), iVar4 != 0)))) {

      return;

    }

  }

  if (DAT_00b036f0 == '\0') {

LAB_004b7fe1:

    if (param_3 != 0) {

      iVar4 = *(int *)(*(int *)(param_3 + 4) + 4);

      puVar1 = (uint *)(iVar4 + 0x164 + param_3);

      if (((*(uint *)(iVar4 + 0x164 + param_3) & *(uint *)(iVar4 + 0x168 + param_3)) != 0xffffffff)

         || ((char)puVar1[2] != '\0')) {

        TStack_50.dwCoidLo = *puVar1;

        TStack_50.dwCoidHi = puVar1[1];

        TStack_50._8_4_ = puVar1[2];

        TStack_50._12_4_ = puVar1[3];

        goto LAB_004b8053;

      }

    }

  }

  else if (param_3 != 0) {

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) + 0x1d8))();

    if (iVar4 != 0) {

      iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) + 0x1d8))();

      TStack_50.dwCoidLo = *(uint *)(iVar4 + 0x228);

      TStack_50.dwCoidHi = *(uint *)(iVar4 + 0x22c);

      TStack_50._8_4_ = *(uint *)(iVar4 + 0x230);

      TStack_50._12_4_ = *(uint *)(iVar4 + 0x234);

      piVar5 = Object_ResolveFromTFID(&TStack_50);

      if ((piVar5 != (int *)0x0) && (iVar4 = (**(code **)(*piVar5 + 0x210))(0), iVar4 != 0)) {

        puVar25 = &DAT_009cb2a0;

        pvVar3 = (void *)FUN_004ba740(&TStack_50);

        iVar4 = TFID_EqualsObjectId(pvVar3,puVar25);

        if ((char)iVar4 != '\0') {

          iVar4 = *(int *)(param_1 + 0x28);

          if (iVar4 == 0) {

            return;

          }

          if (iVar4 == 0xb) {

            return;

          }

          if (iVar4 == 10) {

            return;

          }

          if (iVar4 == 9) {

            return;

          }

          if (iVar4 == 2) {

            return;

          }

        }

      }

    }

    goto LAB_004b7fe1;

  }

  iVar4 = Client_GetMissionCompleteAudioTable();

  TStack_50.dwCoidLo = *(uint *)(iVar4 + 0x2e8);

  *(uint *)(iVar4 + 0x2e8) = TStack_50.dwCoidLo - 1;

  TStack_50.dwCoidHi = (int)TStack_50.dwCoidLo >> 0x1f;

  TStack_50._8_4_ = TStack_50._8_4_ & 0xffffff00;

LAB_004b8053:

  piStack_78 = (int *)**(int **)(param_1 + 0x1ec);

  if (piStack_78 != *(int **)(param_1 + 0x1ec)) {

    do {

      pbVar16 = (byte *)piStack_78[2];

      if (param_2 != '\0') {

        pbVar16[0x104] = 0x32;

        pbVar16[0x105] = 0;

        pbVar16[0x106] = 0;

        pbVar16[0x107] = 0;

      }

      if (param_4 == (byte *)0x0) {

        bVar13 = pbVar16[0x10a] == 0;

LAB_004b80d6:

        if (bVar13) {

          pbVar6 = pbVar16;

          do {

            bVar2 = *pbVar6;

            pbVar6 = pbVar6 + 1;

          } while (bVar2 != 0);

          if (pbVar6 != pbVar16 + 1) {

            uStack_60 = 0;

            uStack_5c = 0;

            uStack_58 = 0;

            uStack_54 = 0;

            if ((pbVar16[0x108] == 0) && (param_3 != 0)) {

              *(uint *)(pbVar16 + 0x120) = TStack_50.dwCoidLo;

              *(uint *)(pbVar16 + 0x124) = TStack_50.dwCoidHi;

              *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x128) = TStack_50._8_4_;

              *(uint32_t /* width from decompiler */ *)(pbVar16 + 300) = TStack_50._12_4_;

              if (pbVar16[0x109] != 0) {

                iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) +

                                    0x214))();

                if (iVar4 == 0) {

                  puVar25 = (uint32_t /* width from decompiler */ *)

                            (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3)

                                        + 0x1a0))();

                  uStack_60 = *puVar25;

                  uStack_5c = puVar25[1];

                  uStack_58 = puVar25[2];

                  uStack_54 = puVar25[3];

                  piVar5 = (int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3);

                }

                else {

                  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) +

                                      0x214))();

                  puVar25 = (uint32_t /* width from decompiler */ *)

                            (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) +

                                        0x1a0))();

                  uStack_60 = *puVar25;

                  uStack_5c = puVar25[1];

                  uStack_58 = puVar25[2];

                  uStack_54 = puVar25[3];

                  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) +

                                      0x214))();

                  piVar5 = (int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);

                }

                (**(code **)(*piVar5 + 0x1a8))();

              }

              uVar17 = *(uint *)(*(int *)(param_3 + 4) + 4);

              piVar5 = *(int **)(uVar17 + 0xb0 + param_3);

              lVar14 = (ulonglong)uVar17 << 0x20;

              if ((piVar5 != (int *)0x0) &&

                 (lVar14 = (ulonglong)uVar17 << 0x20, *(int *)(piVar5[0x2a] + 0x38) == 0xe)) {

                lVar14 = (**(code **)(*piVar5 + 0x1d4))();

              }

              uVar11 = (uint32_t /* width from decompiler */)((ulonglong)lVar14 >> 0x20);

              iStack_7c = (int)lVar14;

              iVar4 = *(int *)(pbVar16 + 0x104);

              if ((iVar4 < 0x14) || (0x18 < iVar4)) {

                if (pbVar16[0x10c] == 0) {

                  if (pbVar16[0x109] != 0) {

                    if (*(int *)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 0xac + param_3) +

                                0x38) != 0xc) {

                      if (((*(int *)(param_1 + 0x2c) != 0) &&

                          (*(int *)(*(int *)(param_1 + 0x2c) + 0xe8a0) != 0)) &&

                         (iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 +

                                                       param_3) + 0x1c8))(), iVar4 != 0)) {

                        iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 0x2c) + 0xe8a0) + 0x1dc))

                                          ();

                        iVar4 = *(int *)(*(int *)(iVar7 + 4) + 4);

                        iVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 +

                                                     param_3) + 0x1c8))();

                        uVar15 = (**(code **)(*(int *)(iVar4 + 4 + iVar7) + 0x19c))();

                        uVar11 = (uint32_t /* width from decompiler */)((ulonglong)uVar15 >> 0x20);

                        if ((iVar8 == (int)uVar15) && (*(int *)(pbVar16 + 0x104) != 0x28))

                        goto LAB_004b841b;

                      }

LAB_004b83ba:

                      if ((pbVar16[0x131] == 0) ||

                         ((iStack_7c != 0 && (*(char *)(iStack_7c + 0x103) != '\0')))) {

                        *(uint *)(pbVar16 + 0x120) = TStack_50.dwCoidLo;

                        *(uint *)(pbVar16 + 0x124) = TStack_50.dwCoidHi;

                        puVar25 = &uStack_60;

                        *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x128) = TStack_50._8_4_;

                        *(uint32_t /* width from decompiler */ *)(pbVar16 + 300) = TStack_50._12_4_;

                        Client_GetMissionCompleteAudioTable(pbVar16,puVar25);

                        FUN_007258a0(pbVar16,puVar25);

                      }

                      goto LAB_004b85a2;

                    }

                    uVar15 = (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3

                                                  ) + 0x1e0))();

                    uVar11 = (uint32_t /* width from decompiler */)((ulonglong)uVar15 >> 0x20);

                    if ((int)uVar15 != 0) {

                      if ((*(char *)((int)uVar15 + 199) == '\0') &&

                         (*(int *)(pbVar16 + 0x104) == 10)) goto LAB_004b85a2;

                      if ((iStack_7c == 0) || (*(char *)(iStack_7c + 0x103) == '\0'))

                      goto LAB_004b83ba;

                      pbVar16[0x109] = 0;

                    }

                  }

LAB_004b841b:

                  if ((pbVar16[0x131] == 0) ||

                     ((iStack_7c != 0 && (*(char *)(iStack_7c + 0x103) != '\0')))) {

                    uVar12 = (undefined3)((uint)uVar11 >> 8);

                    uVar26 = CONCAT31(uVar12,pbVar16[0x130]);

                    uVar11 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x104);

                    uVar23 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x118);

                    uVar22 = CONCAT31(uVar12,pbVar16[0x128]);

                    iVar4 = *(int *)(pbVar16 + 0x124);

                    uVar21 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x120);

                    uVar10 = CONCAT31(uVar12,pbVar16[0x10b]);

                    goto LAB_004b8595;

                  }

                }

                else {

                  uVar11 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x11c);

                  uVar23 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x114);

                  uVar21 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x110);

                  puVar25 = &uStack_60;

                  uVar17 = TStack_50.dwCoidLo;

                  uVar18 = TStack_50.dwCoidHi;

                  uVar19 = TStack_50._8_4_;

                  uVar20 = TStack_50._12_4_;

                  Client_GetMissionCompleteAudioTable

                            (pbVar16,TStack_50.dwCoidLo,TStack_50.dwCoidHi,TStack_50._8_4_,

                             TStack_50._12_4_,puVar25,uVar21,uVar23,iVar4,uVar11);

                  FUN_00723120(pbVar16,uVar17,uVar18,uVar19,uVar20,puVar25,uVar21,uVar23,iVar4,

                               uVar11);

                }

              }

            }

            else if ((pbVar16[0x109] == 0) || (param_3 == 0)) {

              iVar4 = Client_GetMissionCompleteAudioTable();

              iVar7 = *(int *)(iVar4 + 0x2e8);

              *(int *)(iVar4 + 0x2e8) = iVar7 + -1;

              uVar23 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x118);

              iVar4 = iVar7 >> 0x1f;

              uVar26 = 0;

              *(int *)(pbVar16 + 0x120) = iVar7;

              uVar11 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x104);

              uVar21 = *(uint32_t /* width from decompiler */ *)(pbVar16 + 0x120);

              uVar10 = CONCAT31((int3)((uint)uVar23 >> 8),pbVar16[0x10b]);

              uVar22 = 0;

              *(int *)(pbVar16 + 0x124) = iVar4;

              pbVar16[0x128] = 0;

LAB_004b8595:

              Client_GetMissionCompleteAudioTable

                        (pbVar16,uVar10,uVar21,iVar4,uVar22,uVar23,uVar11,uVar26);

              Client_PlayNamedInterfaceSound

                        (pbVar16,uVar10,uVar21,iVar4,uVar22,uVar23,uVar11,uVar26);

            }

            else if (*(int *)(param_3 + 8) != 0) {

              (**(code **)(*(int *)(*(int *)(*(int *)(param_3 + 4) + 4) + 4 + param_3) + 0x108))

                        (0,auStack_6c,auStack_40,0);

              if (g_flZero == SQRT(param_6 * param_6 + param_7 * param_7 + param_5 * param_5)) {

                puVar25 = auStack_6c;

                puVar24 = auStack_20;

              }

              else {

                puVar25 = &param_5;

                puVar24 = auStack_30;

              }

              puVar25 = (uint32_t /* width from decompiler */ *)FUN_004e9530(puVar24,puVar25);

              uStack_60 = *puVar25;

              uStack_5c = puVar25[1];

              uStack_58 = puVar25[2];

              uStack_54 = puVar25[3];

              puVar25 = &uStack_60;

              pbVar16[0x120] = 0xff;

              pbVar16[0x121] = 0xff;

              pbVar16[0x122] = 0xff;

              pbVar16[0x123] = 0xff;

              pbVar16[0x124] = 0xff;

              pbVar16[0x125] = 0xff;

              pbVar16[0x126] = 0xff;

              pbVar16[0x127] = 0xff;

              pbVar16[0x128] = 0;

              Client_GetMissionCompleteAudioTable(pbVar16,puVar25);

              FUN_007258a0(pbVar16,puVar25);

            }

          }

        }

      }

      else {

        pbVar6 = param_4;

        pbVar9 = pbVar16;

        if (pbVar16[0x10a] != 0) {

          do {

            bVar2 = *pbVar6;

            bVar13 = bVar2 < *pbVar9;

            if (bVar2 != *pbVar9) {

LAB_004b80c6:

              bVar13 = 1 - bVar13 == (uint)(bVar13 != 0);

              goto LAB_004b80d6;

            }

            if (bVar2 == 0) break;

            bVar2 = pbVar6[1];

            bVar13 = bVar2 < pbVar9[1];

            if (bVar2 != pbVar9[1]) goto LAB_004b80c6;

            pbVar6 = pbVar6 + 2;

            pbVar9 = pbVar9 + 2;

          } while (bVar2 != 0);

          bVar13 = true;

          goto LAB_004b80d6;

        }

      }

LAB_004b85a2:

      piStack_78 = (int *)*piStack_78;

    } while (piStack_78 != (int *)*(int *)(param_1 + 0x1ec));

  }

  return;

}
