# Raw capture: FUN_0093ffb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093ffb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0093ffb0` |
| **Canonical name** | `FUN_0093ffb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0093ffb0(int param_1)

{
  ushort uVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  int *piVar7;
  float *pfVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  void *pvVar14;
  int *piVar15;
  char *pcVar16;
  int *piVar17;
  char *pcVar18;
  char *pcVar19;
  int *piVar20;
  int *piVar21;
  char *pcVar22;
  undefined2 *puVar23;
  undefined4 *puVar24;
  float fVar25;
  undefined4 auStackY_f4 [7];
  undefined4 uStackY_d8;
  int iStackY_d4;
  undefined1 *puStackY_d0;
  int iStackY_cc;
  undefined4 *puStack_ac;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  char acStack_5c [80];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009bb2c1;
  local_c = ExceptionList;
  iVar12 = *(int *)(param_1 + 0xe98);
  if ((iVar12 != 0) && (*(int *)(iVar12 + 0x250) != 0)) {
    ExceptionList = &local_c;
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar12 + 4) + 4) + 4 + iVar12) + 0x1a0))();
    FUN_004e88e0();
    puStack_ac = *(undefined4 **)(*(int *)(param_1 + 0xe04) + 0xe8a8);
    if (puStack_ac != *(undefined4 **)(*(int *)(param_1 + 0xe04) + 0xe8ac)) {
      do {
        piVar15 = puStack_ac + 4;
        iStackY_cc = 0x94004f;
        piVar7 = (int *)CVOGReaction_ResolveObjectTarget();
        if ((piVar7 != (int *)0x0) &&
           (((iVar12 = *(int *)(piVar7[0x2a] + 0x38), iVar12 == 0xe || (iVar12 == 0x12)) ||
            (iVar12 == 0x14)))) {
          (**(code **)(*piVar7 + 0x144))();
          if ((puStack_ac[0xc] == 4) && (*(int *)(param_1 + 0xe98) != 0)) {
            (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +
                                 *(int *)(param_1 + 0xe98)) + 0x1a0))();
            pfVar8 = (float *)FUN_004e88e0();
            fStack_9c = *pfVar8;
            fStack_98 = pfVar8[1];
            fStack_94 = pfVar8[2];
          }
          else {
            pfVar8 = (float *)FUN_004e88e0();
            fStack_9c = *pfVar8;
            fStack_98 = pfVar8[1];
            fStack_94 = pfVar8[2];
          }
          if (SQRT((fStack_9c - fStack_78) * (fStack_9c - fStack_78) +
                   (fStack_98 - fStack_74) * (fStack_98 - fStack_74) +
                   (fStack_94 - fStack_70) * (fStack_94 - fStack_70)) <= DAT_00aaa9f0) {
            if (puStack_ac[0xc] == 3) {
              if (puStack_ac[8] != 0) {
                Client_MaybeShowFirstTimeTip();
                iVar12 = *(int *)(param_1 + 0xe98);
                if ((((*(uint *)(iVar12 + 0xd34) >> 10 & 1) == 0) && (iVar12 != 0)) &&
                   ((0 < *(short *)(iVar12 + 0x6ce) || (0 < *(short *)(iVar12 + 0x6cc))))) {
                  uVar9 = Experience_GetCumulativeThreshold(3);
                  uVar10 = Experience_GetCumulativeThreshold(2);
                  if ((int)((int)(uVar9 - uVar10) / 2 + uVar10) <
                      *(int *)(*(int *)(param_1 + 0xe98) + 0x730)) {
                    Client_MaybeShowFirstTimeTip();
                  }
                }
LAB_0094020b:
                iVar12 = *(int *)(param_1 + 0xe98);
                bVar4 = false;
                if ((iVar12 != 0) &&
                   ((iVar11 = TFID_EqualsObjectId(piVar15,(void *)(*(int *)(*(int *)(iVar12 + 4) + 4
                                                                           ) + 0x164 + iVar12)),
                    (char)iVar11 != '\0' ||
                    ((iVar11 = *(int *)(iVar12 + 0x250), iVar11 != 0 &&
                     (iVar11 = TFID_EqualsObjectId(piVar15,(void *)(*(int *)(*(int *)(iVar11 + 4) +
                                                                            4) + 0x164 + iVar11)),
                     (char)iVar11 != '\0')))))) {
                  bVar4 = true;
                }
                bVar5 = false;
                if ((iVar12 != 0) &&
                   ((iVar11 = TFID_EqualsObjectId(puStack_ac,
                                                  (void *)(*(int *)(*(int *)(*(int *)(param_1 +
                                                                                     0xe98) + 4) + 4
                                                                   ) + 0x164 +
                                                          *(int *)(param_1 + 0xe98))),
                    (char)iVar11 != '\0' ||
                    ((iVar12 = *(int *)(iVar12 + 0x250), iVar12 != 0 &&
                     (iVar12 = TFID_EqualsObjectId(puStack_ac,
                                                   (void *)(*(int *)(*(int *)(iVar12 + 4) + 4) +
                                                            0x164 + iVar12)), (char)iVar12 != '\0'))
                    )))) {
                  bVar5 = true;
                }
                piVar7 = operator_new(0x60);
                if (piVar7 == (int *)0x0) {
                  piVar7 = (int *)0x0;
                }
                else {
                  *piVar7 = 0;
                  *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                  *(undefined1 *)((int)piVar7 + 0x25) = 0xff;
                  *(undefined1 *)(piVar7 + 9) = 0xff;
                  *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                  piVar7[0x17] = 0;
                }
                uStack_4 = 0xffffffff;
                piVar21 = piVar7;
                for (iVar12 = 0x18; iVar12 != 0; iVar12 = iVar12 + -1) {
                  *piVar21 = 0;
                  piVar21 = piVar21 + 1;
                }
                puVar13 = operator_new__(0x20);
                fVar25 = g_flLevelUpUiBase_Inferred;
                *piVar7 = (int)puVar13;
                *puVar13 = 0;
                piVar7[4] = (int)fStack_9c;
                piVar7[5] = (int)fStack_98;
                piVar7[6] = (int)fStack_94;
                piVar7[1] = 0;
                piVar7[2] = (int)fVar25;
                piVar7[3] = 0;
                piVar7[8] = (int)fVar25;
                piVar7[7] = (int)fVar25;
                piVar7[10] = 0;
                piVar7[0xb] = 0;
                piVar7[0xc] = 0;
                piVar7[0x12] = 0;
                piVar21 = piVar7 + 0xe;
                *piVar21 = *piVar15;
                piVar7[0xf] = puStack_ac[5];
                piVar7[0x10] = puStack_ac[6];
                piVar7[0x11] = puStack_ac[7];
                iVar12 = CVOGReaction_RandomUnitScalar();
                if (0xfffff < *(int *)(iVar12 + 0xc)) {
                  *(undefined4 *)(iVar12 + 0xc) = 0;
                }
                uVar1 = *(ushort *)(*(int *)(iVar12 + 8) + *(int *)(iVar12 + 0xc) * 2);
                *(int *)(iVar12 + 0xc) = *(int *)(iVar12 + 0xc) + 1;
                piVar7[0x13] = (int)(float)(int)(((uint)uVar1 % 3 - 1) *
                                                (int)((float)DAT_00d1e818 * _DAT_00aaacb0));
                fVar25 = (float)DAT_00d1e818 * DAT_00a10e78;
                piVar7[0x15] = 0;
                piVar7[0x16] = (int)(0.0 - (float)(int)fVar25);
                iStackY_cc = 0x940438;
                sprintf(acStack_5c,"%d");
                FUN_007a69d0();
                switch(puStack_ac[0xc]) {
                case 0:
                  if (*(char *)((int)puStack_ac + 0x2a) == '\0') {
                    if (*(char *)((int)puStack_ac + 0x2b) == '\0') {
                      if (*(char *)(puStack_ac + 0xb) == '\0') {
                        if (puStack_ac[8] == 0) {
                          if ((void *)*piVar7 != (void *)0x0) {
                            operator_delete__((void *)*piVar7);
                          }
                          *piVar7 = 0;
                    /* WARNING: Subroutine does not return */
                          operator_delete(piVar7);
                        }
                        pcVar18 = acStack_5c;
                        do {
                          cVar6 = *pcVar18;
                          pcVar18 = pcVar18 + 1;
                        } while (cVar6 != '\0');
                        uVar9 = (int)pcVar18 - (int)acStack_5c;
                        pcVar18 = (char *)(*piVar7 + -1);
                        do {
                          pcVar16 = pcVar18 + 1;
                          pcVar18 = pcVar18 + 1;
                        } while (*pcVar16 != '\0');
                        pcVar16 = acStack_5c;
                        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                          *(undefined4 *)pcVar18 = *(undefined4 *)pcVar16;
                          pcVar16 = pcVar16 + 4;
                          pcVar18 = pcVar18 + 4;
                        }
                        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                          *pcVar18 = *pcVar16;
                          pcVar16 = pcVar16 + 1;
                          pcVar18 = pcVar18 + 1;
                        }
                        if (bVar4) {
                          *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                          *(undefined1 *)((int)piVar7 + 0x25) = 0;
                          *(undefined1 *)(piVar7 + 9) = 0;
                          *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                          iVar12 = *(int *)(param_1 + 0xe98);
                          if ((((iVar12 != 0) && (*(char *)(iVar12 + 0x30c) != '\0')) &&
                              ((*(uint *)(iVar12 + 0xd30) >> 0x15 & 1) == 0)) &&
                             ((*(int *)(iVar12 + 0x250) != 0 &&
                              (pfVar8 = (float *)(*(int *)(iVar12 + 0x250) + 0x138),
                              *pfVar8 <= DAT_00a111b0 && DAT_00a111b0 != *pfVar8)))) {
                            Client_MaybeShowFirstTimeTip();
                          }
                        }
                        else if (bVar5) {
                          cVar6 = *(char *)((int)puStack_ac + 0x29);
                          *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                          *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                          if (cVar6 != '\0') {
                            *(undefined1 *)((int)piVar7 + 0x25) = 0xc4;
                            goto LAB_0094060b;
                          }
                          *(undefined1 *)((int)piVar7 + 0x25) = 0xff;
                          *(undefined1 *)(piVar7 + 9) = 0xff;
                        }
                        else {
                          cVar6 = *(char *)((int)puStack_ac + 0x29);
                          *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                          *(undefined1 *)((int)piVar7 + 0x26) = 0xb4;
                          if (cVar6 == '\0') {
                            *(undefined1 *)((int)piVar7 + 0x25) = 0xb4;
                            *(undefined1 *)(piVar7 + 9) = 0xb4;
                          }
                          else {
                            *(undefined1 *)((int)piVar7 + 0x25) = 0x82;
LAB_0094060b:
                            *(undefined1 *)(piVar7 + 9) = 0;
                          }
                        }
                        if (*(char *)((int)puStack_ac + 0x29) == '\0') {
                          piVar7[0x12] = 0xb;
                        }
                        else {
                          puVar23 = (undefined2 *)(*piVar7 + -1);
                          do {
                            pcVar18 = (char *)((int)puVar23 + 1);
                            puVar23 = (undefined2 *)((int)puVar23 + 1);
                          } while (*pcVar18 != '\0');
                          *puVar23 = DAT_00a156cc;
                        }
                      }
                      else {
                        *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                        *(undefined1 *)((int)piVar7 + 0x25) = 0xff;
                        *(undefined1 *)(piVar7 + 9) = 0;
                        *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                        pcVar18 = (char *)*piVar7;
                        *(undefined4 *)pcVar18 = s_Deflect_00a2dbc4._0_4_;
                        *(undefined4 *)(pcVar18 + 4) = s_Deflect_00a2dbc4._4_4_;
                        piVar7[0x12] = 10;
                      }
                    }
                    else {
                      *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                      *(undefined1 *)((int)piVar7 + 0x25) = 0xff;
                      *(undefined1 *)(piVar7 + 9) = 0;
                      *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                      pcVar18 = (char *)*piVar7;
                      *(undefined4 *)pcVar18 = s_Resist_00a2dbcc._0_4_;
                      *(undefined4 *)(pcVar18 + 4) = s_Resist_00a2dbcc._4_4_;
                      piVar7[0x12] = 10;
                    }
                  }
                  else {
                    *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                    *(undefined1 *)((int)piVar7 + 0x25) = 0xff;
                    *(undefined1 *)(piVar7 + 9) = 0;
                    *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                    puVar24 = (undefined4 *)*piVar7;
                    *puVar24 = DAT_00a2dbd4;
                    *(undefined1 *)(puVar24 + 1) = DAT_00a2dbd8;
                    piVar7[0x12] = 10;
                  }
                  break;
                case 1:
                  piVar7[0x12] = 0xb;
                  *(undefined1 *)((int)piVar7 + 0x26) = 0x46;
                  *(undefined1 *)((int)piVar7 + 0x25) = 0xcc;
                  *(undefined1 *)(piVar7 + 9) = 0x46;
                  *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                  puVar23 = (undefined2 *)(*piVar7 + -1);
                  do {
                    pcVar18 = (char *)((int)puVar23 + 1);
                    puVar23 = (undefined2 *)((int)puVar23 + 1);
                  } while (*pcVar18 != '\0');
                  *puVar23 = DAT_00a2e620;
                  pcVar18 = acStack_5c;
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  uVar9 = (int)pcVar18 - (int)acStack_5c;
                  pcVar18 = (char *)(*piVar7 + -1);
                  do {
                    pcVar16 = pcVar18 + 1;
                    pcVar18 = pcVar18 + 1;
                  } while (*pcVar16 != '\0');
                  pcVar16 = acStack_5c;
                  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar16;
                    pcVar16 = pcVar16 + 4;
                    pcVar18 = pcVar18 + 4;
                  }
                  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *pcVar18 = *pcVar16;
                    pcVar16 = pcVar16 + 1;
                    pcVar18 = pcVar18 + 1;
                  }
                  pcVar16 = (char *)FUN_007a6de0();
                  pcVar18 = pcVar16;
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  pcVar22 = (char *)(*piVar7 + -1);
                  do {
                    pcVar19 = pcVar22 + 1;
                    pcVar22 = pcVar22 + 1;
                  } while (*pcVar19 != '\0');
                  pcVar19 = pcVar16;
                  for (uVar9 = (uint)((int)pcVar18 - (int)pcVar16) >> 2; uVar9 != 0;
                      uVar9 = uVar9 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar19;
                    pcVar19 = pcVar19 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar9 = (int)pcVar18 - (int)pcVar16 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *pcVar22 = *pcVar19;
                    pcVar19 = pcVar19 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  break;
                case 2:
                  piVar7[0x12] = 0xb;
                  *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                  *(undefined1 *)((int)piVar7 + 0x25) = 200;
                  *(undefined1 *)(piVar7 + 9) = 0x33;
                  *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                  puVar23 = (undefined2 *)(*piVar7 + -1);
                  if ((int)puStack_ac[8] < 0) {
                    do {
                      pcVar18 = (char *)((int)puVar23 + 1);
                      puVar23 = (undefined2 *)((int)puVar23 + 1);
                    } while (*pcVar18 != '\0');
                    *puVar23 = DAT_00a2dbb8;
                  }
                  else {
                    do {
                      pcVar18 = (char *)((int)puVar23 + 1);
                      puVar23 = (undefined2 *)((int)puVar23 + 1);
                    } while (*pcVar18 != '\0');
                    *puVar23 = DAT_00a2e620;
                  }
                  pcVar18 = acStack_5c;
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  uVar9 = (int)pcVar18 - (int)acStack_5c;
                  pcVar18 = (char *)(*piVar7 + -1);
                  do {
                    pcVar16 = pcVar18 + 1;
                    pcVar18 = pcVar18 + 1;
                  } while (*pcVar16 != '\0');
                  pcVar16 = acStack_5c;
                  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar16;
                    pcVar16 = pcVar16 + 4;
                    pcVar18 = pcVar18 + 4;
                  }
                  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *pcVar18 = *pcVar16;
                    pcVar16 = pcVar16 + 1;
                    pcVar18 = pcVar18 + 1;
                  }
                  pcVar16 = (char *)FUN_007a6de0();
                  pcVar18 = pcVar16;
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  pcVar22 = (char *)(*piVar7 + -1);
                  do {
                    pcVar19 = pcVar22 + 1;
                    pcVar22 = pcVar22 + 1;
                  } while (*pcVar19 != '\0');
                  pcVar19 = pcVar16;
                  for (uVar9 = (uint)((int)pcVar18 - (int)pcVar16) >> 2; uVar9 != 0;
                      uVar9 = uVar9 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar19;
                    pcVar19 = pcVar19 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar9 = (int)pcVar18 - (int)pcVar16 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *pcVar22 = *pcVar19;
                    pcVar19 = pcVar19 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  break;
                case 3:
                  pcVar18 = acStack_5c;
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  uVar9 = (int)pcVar18 - (int)acStack_5c;
                  pcVar18 = (char *)(*piVar7 + -1);
                  do {
                    pcVar16 = pcVar18 + 1;
                    pcVar18 = pcVar18 + 1;
                  } while (*pcVar16 != '\0');
                  pcVar16 = acStack_5c;
                  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar16;
                    pcVar16 = pcVar16 + 4;
                    pcVar18 = pcVar18 + 4;
                  }
                  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *pcVar18 = *pcVar16;
                    pcVar16 = pcVar16 + 1;
                    pcVar18 = pcVar18 + 1;
                  }
                  *(undefined1 *)((int)piVar7 + 0x26) = 0xbb;
                  *(undefined1 *)((int)piVar7 + 0x25) = 100;
                  *(undefined1 *)(piVar7 + 9) = 0xf9;
                  *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                  pcVar16 = (char *)FUN_007a6de0();
                  pcVar18 = pcVar16;
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  pcVar22 = (char *)(*piVar7 + -1);
                  do {
                    pcVar19 = pcVar22 + 1;
                    pcVar22 = pcVar22 + 1;
                  } while (*pcVar19 != '\0');
                  pcVar19 = pcVar16;
                  for (uVar9 = (uint)((int)pcVar18 - (int)pcVar16) >> 2; uVar9 != 0;
                      uVar9 = uVar9 - 1) {
                    *(undefined4 *)pcVar22 = *(undefined4 *)pcVar19;
                    pcVar19 = pcVar19 + 4;
                    pcVar22 = pcVar22 + 4;
                  }
                  for (uVar9 = (int)pcVar18 - (int)pcVar16 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *pcVar22 = *pcVar19;
                    pcVar19 = pcVar19 + 1;
                    pcVar22 = pcVar22 + 1;
                  }
                  fVar25 = (float)DAT_00d1e818 * DAT_00aaabe8;
                  piVar7[0x15] = 0;
                  piVar7[0x16] = (int)(0.0 - (float)(int)fVar25);
                  fVar25 = g_flVehicleHpTechCoeff;
                  piVar7[8] = (int)g_flVehicleHpTechCoeff;
                  piVar7[7] = (int)fVar25;
                  break;
                case 4:
                  *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
                  *(undefined1 *)((int)piVar7 + 0x25) = 0xff;
                  *(undefined1 *)(piVar7 + 9) = 0xcc;
                  *(undefined1 *)((int)piVar7 + 0x27) = 0xff;
                  pcVar18 = acStack_5c;
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  uVar9 = (int)pcVar18 - (int)acStack_5c;
                  pcVar18 = (char *)(*piVar7 + -1);
                  do {
                    pcVar16 = pcVar18 + 1;
                    pcVar18 = pcVar18 + 1;
                  } while (*pcVar16 != '\0');
                  pcVar16 = acStack_5c;
                  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *(undefined4 *)pcVar18 = *(undefined4 *)pcVar16;
                    pcVar16 = pcVar16 + 4;
                    pcVar18 = pcVar18 + 4;
                  }
                  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                    *pcVar18 = *pcVar16;
                    pcVar16 = pcVar16 + 1;
                    pcVar18 = pcVar18 + 1;
                  }
                  pvVar14 = operator_new(0xd0);
                  uStack_4 = 1;
                  if (pvVar14 == (void *)0x0) {
                    iVar12 = 0;
                  }
                  else {
                    iStackY_cc = 0x940917;
                    iVar12 = FUN_007972f0();
                  }
                  uStack_4 = 0xffffffff;
                  piVar7[0x17] = iVar12;
                  *(undefined1 *)(iVar12 + 0xb6) = 0;
                  FUN_00797a10();
                  iStackY_cc = piVar7[9];
                  iStackY_d4 = piVar7[0x17];
                  puStackY_d0 = &DAT_00a1419b;
                  uStackY_d8 = 0x94095c;
                  FUN_00798720();
                  if (*(int *)(param_1 + 0x4f0) != 0) {
                    iStackY_cc = 0x940987;
                    FUN_00977a10();
                  }
                  FUN_007979c0();
                }
                if (bVar4) {
                  uVar9 = puStack_ac[8];
                  if ((((int)uVar9 < 1) || (puStack_ac[0xc] != 0)) ||
                     ((*(char *)((int)puStack_ac + 0x2b) != '\0' ||
                      ((*(char *)(puStack_ac + 0xb) != '\0' ||
                       (*(char *)((int)puStack_ac + 0x2a) != '\0')))))) {
                    if (((int)uVar9 < 0) && (puStack_ac[0xc] == 1)) {
                      iVar12 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +
                                                    DAT_00d1b6d8) + 0x1ac))();
                      if ((int)((float)iVar12 * DAT_00a10e78) <
                          (int)((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f))) {
                        iVar12 = *(int *)(param_1 + 0x3c10);
                      }
                      else {
                        iVar12 = *(int *)(param_1 + 0x3c10);
                      }
                    }
                    else if (puStack_ac[0xc] == 3) {
                      iVar12 = *(int *)(param_1 + 0x3c10);
                    }
                    else {
                      if (puStack_ac[0xc] != 4) goto LAB_00940c23;
                      iVar12 = *(int *)(param_1 + 0x3c10);
                    }
                    if (iVar12 != 0) {
                      FUN_0048a780();
                    }
                  }
                  else {
                    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4
                                         + *(int *)(param_1 + 0xe98)) + 0x1ac))();
                    if (((*(int *)(param_1 + 0xf38) != 0) &&
                        (cVar6 = (**(code **)(**(int **)(param_1 + 0xf38) + 0x3d8))(), cVar6 != '\0'
                        )) && (*(int *)(*(int *)(param_1 + 0xf38) + 0xcb0) != 0)) {
                      puStackY_d0 = (undefined1 *)*puStack_ac;
                      iStackY_cc = puStack_ac[1];
                      iStackY_d4 = 0x940a6a;
                      FUN_008352d0();
                    }
                    if ((*(int *)(param_1 + 0x10ac) != 0) &&
                       (cVar6 = (**(code **)(**(int **)(param_1 + 0x10ac) + 0x3d8))(), cVar6 != '\0'
                       )) {
                      puStackY_d0 = *(undefined1 **)(param_1 + 0x10ac);
                      iStackY_cc = 0;
                      iStackY_d4 = 0x940aa6;
                      piVar15 = (int *)__RTDynamicCast();
                      (**(code **)(*piVar15 + 0x454))();
                    }
                    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4
                                         + *(int *)(param_1 + 0xe98)) + 0x1ac))();
                    iStackY_cc = 0x940adc;
                    FUN_007fb4d0();
                    iVar12 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);
                    if ((iVar12 == 0) || (*(int *)(iVar12 + 0x144) < 1)) {
                      iVar12 = *(int *)(param_1 + 0x3c10);
                    }
                    else {
                      iVar12 = *(int *)(param_1 + 0x3c10);
                    }
                    if (iVar12 != 0) {
                      FUN_0048a780();
                    }
                    Client_MaybeShowFirstTimeTip();
                    if ((*(int *)(param_1 + 0xe04) != 0) &&
                       (*(char *)(*(int *)(param_1 + 0xe04) + 0x100) != '\0')) {
                      Client_MaybeShowFirstTimeTip();
                    }
                  }
LAB_00940c23:
                  if ((((*(char *)(param_1 + 0x9d9) != '\0') && (*(int *)(param_1 + 0x3048) == 0))
                      && (-1 < (int)puStack_ac[8])) && (puStack_ac[0xc] == 0)) {
                    iStackY_cc = 0x940c68;
                    piVar15 = (int *)CVOGReaction_ResolveObjectTarget();
                    if (piVar15 != (int *)0x0) {
                      iVar12 = (**(code **)(*piVar15 + 0x19c))();
                      if (iVar12 == 0) {
                        FUN_0093e120();
                      }
                      else {
                        FUN_0093e120();
                      }
                    }
                  }
                }
                if (*(char *)(*(int *)(*(int *)(param_1 + 0xe98) + 0x250) + 0x106) != '\0') {
                  FUN_007a69d0();
                  pcVar16 = (char *)FUN_007a6de0();
                  pcVar18 = (char *)*piVar7;
                  do {
                    cVar6 = *pcVar16;
                    *pcVar18 = cVar6;
                    pcVar16 = pcVar16 + 1;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  if (puStack_ac[0xc] == 3) {
                    FUN_004027f0();
                  }
                  else {
                    FUN_004027f0();
                    piVar15 = *(int **)(param_1 + 0xaac);
                    piVar17 = (int *)*piVar15;
                    if (piVar15 != piVar17) {
                      do {
                        piVar15 = (int *)piVar15[1];
                        iVar12 = piVar15[2];
                        if (((*(int *)(iVar12 + 0x38) == *piVar21) &&
                            (*(int *)(iVar12 + 0x3c) == piVar7[0xf])) &&
                           ((*(char *)(iVar12 + 0x40) == (char)piVar7[0x10] &&
                            (&DAT_00d1e7e0 + *(int *)(iVar12 + 0x48) != (int *)0x0)))) {
                          iVar12 = (&DAT_00d1e7e0)[*(int *)(iVar12 + 0x48)];
                          fVar25 = (float)*(int *)(iVar12 + 0x7c);
                          if (*(int *)(iVar12 + 0x7c) < 0) {
                            fVar25 = fVar25 + _DAT_00aaa5dc;
                          }
                          piVar20 = piVar15;
                          if (piVar15 != piVar17) {
                            do {
                              piVar20 = (int *)piVar20[1];
                              iVar12 = piVar20[2];
                              iVar11 = piVar15[2];
                              if (((iVar12 != iVar11) && (*(int *)(iVar12 + 0x38) == *piVar21)) &&
                                 ((*(int *)(iVar12 + 0x3c) == piVar7[0xf] &&
                                  ((*(char *)(iVar12 + 0x40) == (char)piVar7[0x10] &&
                                   (&DAT_00d1e7e0 + *(int *)(iVar12 + 0x48) != (int *)0x0)))))) {
                                iVar2 = *(int *)((&DAT_00d1e7e0)[*(int *)(iVar12 + 0x48)] + 0x7c);
                                fVar3 = (float)iVar2;
                                if (iVar2 < 0) {
                                  fVar3 = fVar3 + _DAT_00aaa5dc;
                                }
                                if ((*(float *)(iVar11 + 0x50) <= fVar3 + *(float *)(iVar12 + 0x50))
                                   && (*(float *)(iVar12 + 0x50) <=
                                       *(float *)(iVar11 + 0x50) + fVar25)) {
                                  *(float *)(iVar12 + 0x50) =
                                       (*(float *)(iVar11 + 0x50) - fVar3) - g_flOne;
                                }
                              }
                            } while (piVar20 != (int *)**(int **)(param_1 + 0xaac));
                          }
                        }
                        piVar17 = (int *)**(undefined4 **)(param_1 + 0xaac);
                      } while (piVar15 != piVar17);
                    }
                  }
                  FUN_007ffef0();
                }
              }
            }
            else if ((puStack_ac[8] != 0) || (puStack_ac[0xc] == 0)) goto LAB_0094020b;
          }
        }
        puStack_ac = puStack_ac + 0xe;
      } while (puStack_ac != *(undefined4 **)(*(int *)(param_1 + 0xe04) + 0xe8ac));
    }
    pcVar18 = acStack_5c;
    for (iVar12 = 0xe; iVar12 != 0; iVar12 = iVar12 + -1) {
      pcVar18[0] = '\0';
      pcVar18[1] = '\0';
      pcVar18[2] = '\0';
      pcVar18[3] = '\0';
      pcVar18 = pcVar18 + 4;
    }
    pcVar18 = acStack_5c;
    puVar24 = auStackY_f4;
    for (iVar12 = 0xe; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar24 = *(undefined4 *)pcVar18;
      pcVar18 = pcVar18 + 4;
      puVar24 = puVar24 + 1;
    }
    FUN_00406790();
  }
  ExceptionList = local_c;
  return;
}
```
