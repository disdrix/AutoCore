# Raw capture: FUN_008e1ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e1ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008e1ff0` |
| **Canonical name** | `FUN_008e1ff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x008e2c50) */
/* WARNING: Type propagation algorithm not settling */

void __fastcall FUN_008e1ff0(int *param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  float *pfVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 *puVar15;
  char *pcVar16;
  char **ppcVar17;
  float fVar18;
  int *piVar19;
  int iVar20;
  int *piStack_c04;
  uint uStack_bf0;
  void *pvStack_bec;
  uint uVar21;
  int *piStack_be4;
  int aiStack_be0 [2];
  char *pcStack_bd8;
  int iStack_bbc;
  void *pvStack_bb8;
  void *pvStack_bb4;
  void *pvStack_bb0;
  int *local_bac;
  undefined1 auStack_ba8 [4];
  char *local_ba4;
  char *pcStack_ba0;
  undefined4 uStack_b9c;
  char acStack_b90 [12];
  undefined1 auStack_b84 [36];
  undefined2 uStack_b60;
  undefined4 auStack_b5e [3];
  char acStack_b50 [12];
  char acStack_b44 [36];
  undefined2 uStack_b20;
  undefined4 auStack_b1e [60];
  char *pcStack_a2c;
  char acStack_a28 [148];
  char acStack_994 [4];
  char acStack_990 [4];
  char acStack_98c [16];
  char acStack_97c [236];
  undefined1 auStack_890 [15];
  char acStack_881 [11];
  char acStack_876 [2];
  undefined4 auStack_874 [9];
  undefined2 uStack_850;
  undefined4 auStack_84e [249];
  char cStack_469;
  char acStack_468 [24];
  undefined2 uStack_450;
  undefined4 auStack_44e [237];
  undefined1 uStack_98;
  undefined1 uStack_74;
  undefined1 uStack_5c;
  void *pvStack_4c;
  undefined1 uStack_44;
  undefined3 uStack_43;
  undefined4 uStack_20;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009b73b6;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  local_bac = param_1;
  FUN_00792600();
  pcStack_bd8 = (char *)0x8e202a;
  pcStack_bd8 = operator_new(0x488);
  local_c = 0;
  local_ba4 = pcStack_bd8;
  if (pcStack_bd8 == (char *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    aiStack_be0[1] = 0x8e2045;
    piVar4 = (int *)FUN_007b5dd0();
  }
  local_c = 0xffffffff;
  pcStack_bd8 = (char *)0x8e2061;
  (**(code **)(*param_1 + 0xa8))();
  pcStack_bd8 = "i_d_d_2d_wnd_title.xml";
  aiStack_be0[1] = 0x8e206d;
  (**(code **)(*piVar4 + 0x28))();
  aiStack_be0[1] = 0x3f000000;
  aiStack_be0[0] = 1;
  (**(code **)(*piVar4 + 0xfc))();
  iVar5 = param_1[0x1a] + 1;
  param_1[0x146] = (int)piVar4;
  param_1[0x1a] = iVar5;
  param_1[0x1d] = (int)(float)-iVar5;
  if (param_1[0x1c] < iVar5) {
    param_1[0x1c] = iVar5;
  }
  piStack_be4 = &iRam00000001;
  (**(code **)(*param_1 + 0x3f4))();
  pvStack_bb8 = operator_new(0x488);
  uStack_20 = 1;
  if (pvStack_bb8 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_007b5dd0();
  }
  uStack_20 = 0xffffffff;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*piVar4 + 0x28))();
  (**(code **)(*piVar4 + 0xfc))();
  param_1[0x147] = (int)piVar4;
  piStack_c04 = (int *)0x8e2133;
  sprintf(acStack_97c,"%i");
  pcVar12 = acStack_97c;
  piStack_c04 = (int *)0x8e2150;
  (**(code **)(*(int *)param_1[0x147] + 0x1d8))();
  iVar5 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar5;
  param_1[0x1d] = (int)(float)-iVar5;
  if (param_1[0x1c] < iVar5) {
    param_1[0x1c] = iVar5;
  }
  piStack_c04 = &iRam00000001;
  (**(code **)(*param_1 + 0x3f4))();
  iVar5 = param_1[0x1a] + 1;
  param_1[0x1a] = iVar5;
  param_1[0x1d] = (int)(float)-iVar5;
  if (param_1[0x1c] < iVar5) {
    param_1[0x1c] = iVar5;
  }
  (**(code **)(*param_1 + 0x3f4))(1);
  iStack_bbc = 0;
  uStack_44 = 3;
  uStack_43 = 0;
  pvStack_bec = operator_new(0x1fc);
  uVar21 = 0;
  aiStack_be0[0] = 0;
  uStack_bf0 = 0;
  while( true ) {
    iVar5 = FUN_0040fa00(auStack_ba8);
    if (*(int *)(iVar5 + 4) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4)) / 0x14;
    }
    uStack_44 = 3;
    pcVar10 = local_ba4;
    if (local_ba4 != (char *)0x0) {
      while( true ) {
        if (pcVar10 == pcStack_ba0) {
          uStack_44 = 3;
                    /* WARNING: Subroutine does not return */
          operator_delete(local_ba4);
        }
        uStack_44 = 3;
        if (*(void **)(pcVar10 + 8) != (void *)0x0) break;
        pcVar10[8] = '\0';
        pcVar10[9] = '\0';
        pcVar10[10] = '\0';
        pcVar10[0xb] = '\0';
        pcVar10[0xc] = '\0';
        pcVar10[0xd] = '\0';
        pcVar10[0xe] = '\0';
        pcVar10[0xf] = '\0';
        pcVar10[0x10] = '\0';
        pcVar10[0x11] = '\0';
        pcVar10[0x12] = '\0';
        pcVar10[0x13] = '\0';
        pcVar10 = pcVar10 + 0x14;
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(pcVar10 + 8));
    }
    local_ba4 = (char *)0x0;
    pcStack_ba0 = (char *)0x0;
    uStack_b9c = 0;
    if (uVar6 <= uVar21) {
      if (pvStack_bec != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvStack_bec);
      }
      param_1[0x127] = 40000;
      (**(code **)(*param_1 + 0x448))();
      (**(code **)(*param_1 + 0x34c))();
      ExceptionList = pvStack_4c;
      return;
    }
    iVar5 = FUN_0040fa00(&pvStack_bb8);
    uStack_44 = 6;
    uVar9 = *(undefined4 *)(uStack_bf0 + *(int *)(iVar5 + 4));
    FUN_0040f5b0(uStack_bf0 + 4 + *(int *)(iVar5 + 4));
    uStack_44 = 3;
    pvVar7 = pvStack_bb4;
    if (pvStack_bb4 != (void *)0x0) break;
    pvStack_bb4 = (void *)0x0;
    pvStack_bb0 = (void *)0x0;
    local_bac = (int *)0x0;
    FUN_0052b040(uVar9,pvStack_bec);
    if ((pvStack_bec != (void *)0x0) && (uStack_bf0 < 0x140)) {
      uStack_850 = 0;
      puVar15 = auStack_84e;
      for (iVar5 = 0xff; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      *(undefined2 *)puVar15 = 0;
      uStack_b60 = 0;
      puVar15 = auStack_b5e;
      for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      *(undefined2 *)puVar15 = 0;
      uStack_b20 = 0;
      puVar15 = auStack_b1e;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      *(undefined2 *)puVar15 = 0;
      uStack_450 = 0;
      puVar15 = auStack_44e;
      for (iVar5 = 0xff; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      *(undefined2 *)puVar15 = 0;
      pvVar7 = operator_new(0x488);
      uStack_44 = 8;
      if (pvVar7 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_007b5dd0(pvVar7,0);
      }
      uStack_44 = 3;
      (**(code **)(iRam00000001 + 0xa8))(piVar4);
      (**(code **)(*piVar4 + 0x28))("i_d_d_2d_wnd_discipline_title.xml");
      (**(code **)(*piVar4 + 0xfc))();
      iVar5 = (**(code **)(*piVar4 + 0x124))(acStack_b90);
      iVar5 = (int)*(float *)(iVar5 + 4);
      pfVar8 = (float *)(**(code **)(*piVar4 + 0x124))(auStack_b84);
      pvStack_bec = (void *)(int)*pfVar8;
      pcStack_a2c = acStack_a28;
      uVar9 = (*(code *)PTR_FUN_00af8c9c)();
      piVar3 = piStack_c04;
      FUN_00403450((int)piStack_c04 + 0x2a,uVar9);
      uStack_5c = 9;
      pcVar10 = pcStack_a2c;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      pcVar16 = &cStack_469;
      do {
        pcVar14 = pcVar16 + 1;
        pcVar16 = pcVar16 + 1;
      } while (*pcVar14 != '\0');
      pcVar14 = pcStack_a2c;
      for (uVar6 = (uint)((int)pcVar10 - (int)pcStack_a2c) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar16 = *(undefined4 *)pcVar14;
        pcVar14 = pcVar14 + 4;
        pcVar16 = pcVar16 + 4;
      }
      for (uVar6 = (int)pcVar10 - (int)pcStack_a2c & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar16 = *pcVar14;
        pcVar14 = pcVar14 + 1;
        pcVar16 = pcVar16 + 1;
      }
      uStack_5c = 3;
      if (pcStack_a2c != acStack_a28) {
        free(pcStack_a2c);
      }
      iVar20 = 1;
      (**(code **)(*piVar4 + 0x1d8))(acStack_468,1,1);
      pcVar10 = acStack_876 + 1;
      do {
        puVar15 = (undefined4 *)pcVar10;
        pcVar10 = (char *)((int)puVar15 + 1);
      } while (*(char *)((int)puVar15 + 1) != '\0');
      iVar11 = *piVar3;
      *(undefined4 *)((int)puVar15 + 1) = DAT_00a3bedc;
      *(undefined2 *)((int)puVar15 + 5) = DAT_00a3bee0;
      piRam00000081 = piVar4;
      uVar9 = FUN_0052ad60(iVar11);
      sprintf(acStack_b44,"%i",uVar9);
      pcVar10 = acStack_b44;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar6 = (int)pcVar10 - (int)acStack_b44;
      pcVar10 = acStack_876 + 1;
      do {
        pcVar16 = pcVar10 + 1;
        pcVar10 = pcVar10 + 1;
      } while (*pcVar16 != '\0');
      pcVar16 = acStack_b44;
      for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar16;
        pcVar16 = pcVar16 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar16;
        pcVar16 = pcVar16 + 1;
        pcVar10 = pcVar10 + 1;
      }
      sprintf(acStack_b44," ID:%i",*piVar3);
      pcVar10 = acStack_b44;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      uVar6 = (int)pcVar10 - (int)acStack_b44;
      pcVar10 = acStack_876 + 1;
      do {
        pcVar16 = pcVar10 + 1;
        pcVar10 = pcVar10 + 1;
      } while (*pcVar16 != '\0');
      pcVar16 = acStack_b44;
      for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar16;
        pcVar16 = pcVar16 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar10 = *pcVar16;
        pcVar16 = pcVar16 + 1;
        pcVar10 = pcVar10 + 1;
      }
      (**(code **)(*piVar4 + 0x308))(acStack_876 + 2);
      iVar11 = (**(code **)(*piVar4 + 0x134))(acStack_b90);
      piStack_c04 = (int *)(float)(int)pcVar12;
      iStack_bbc = (int)((float)DAT_00d1e818 * (float)piStack_c04 * DAT_00aaa67c);
      pvStack_bb8 = (void *)(int)((float)((int)*(float *)(iVar11 + 4) + iVar5 + iVar20) *
                                  (float)DAT_00d1e81c * DAT_00aaa678);
      piVar19 = &iStack_bbc;
      (**(code **)(*piVar4 + 0x110))();
      pvVar7 = operator_new(0x1fc);
      acStack_881[1] = 0;
      if ((piVar3[2] != -1) && (FUN_0052b040(piVar3[2],pvVar7), pvVar7 != (void *)0x0)) {
        _snprintf(acStack_b50,0x104,"%S:%i",(int)pvVar7 + 0x2a,(int)(short)piVar3[7]);
        pcVar12 = acStack_b50;
        do {
          cVar1 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar1 != '\0');
        uVar6 = (int)pcVar12 - (int)acStack_b50;
        pcVar12 = acStack_881;
        do {
          pcVar10 = pcVar12 + 1;
          pcVar12 = pcVar12 + 1;
        } while (*pcVar10 != '\0');
        pcVar10 = acStack_b50;
        for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar12 = pcVar12 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar12 = pcVar12 + 1;
        }
      }
      if ((piVar3[3] != -1) && (FUN_0052b040(piVar3[3],pvVar7), pvVar7 != (void *)0x0)) {
        _snprintf(acStack_b50,0x104," %S:%i",(int)pvVar7 + 0x2a,(int)*(short *)((int)piVar3 + 0x1e))
        ;
        pcVar12 = acStack_b50;
        do {
          cVar1 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar1 != '\0');
        uVar6 = (int)pcVar12 - (int)acStack_b50;
        pcVar12 = acStack_881;
        do {
          pcVar10 = pcVar12 + 1;
          pcVar12 = pcVar12 + 1;
        } while (*pcVar10 != '\0');
        pcVar10 = acStack_b50;
        for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar12 = pcVar12 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar12 = pcVar12 + 1;
        }
      }
      if ((piVar3[4] != -1) && (FUN_0052b040(piVar3[4],pvVar7), pvVar7 != (void *)0x0)) {
        _snprintf(acStack_b50,0x104," %S:%i",(int)pvVar7 + 0x2a,(int)(short)piVar3[8]);
        pcVar12 = acStack_b50;
        do {
          cVar1 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar1 != '\0');
        uVar6 = (int)pcVar12 - (int)acStack_b50;
        pcVar12 = acStack_881;
        do {
          pcVar10 = pcVar12 + 1;
          pcVar12 = pcVar12 + 1;
        } while (*pcVar10 != '\0');
        pcVar10 = acStack_b50;
        for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar12 = pcVar12 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar12 = pcVar12 + 1;
        }
      }
      if ((piVar3[5] != -1) && (FUN_0052b040(piVar3[5],pvVar7), pvVar7 != (void *)0x0)) {
        _snprintf(acStack_b50,0x104," %S:%i",(int)pvVar7 + 0x2a,(int)*(short *)((int)piVar3 + 0x22))
        ;
        pcVar12 = acStack_b50;
        do {
          cVar1 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar1 != '\0');
        uVar6 = (int)pcVar12 - (int)acStack_b50;
        pcVar12 = acStack_881;
        do {
          pcVar10 = pcVar12 + 1;
          pcVar12 = pcVar12 + 1;
        } while (*pcVar10 != '\0');
        pcVar10 = acStack_b50;
        for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar12 = pcVar12 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar12 = pcVar12 + 1;
        }
      }
      if ((piVar3[6] != -1) && (FUN_0052b040(piVar3[6],pvVar7), pvVar7 != (void *)0x0)) {
        _snprintf(acStack_b50,0x104," %S:%i",(int)pvVar7 + 0x2a,(int)(short)piVar3[9]);
        pcVar12 = acStack_b50;
        do {
          cVar1 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar1 != '\0');
        uVar6 = (int)pcVar12 - (int)acStack_b50;
        pcVar12 = acStack_881;
        do {
          pcVar10 = pcVar12 + 1;
          pcVar12 = pcVar12 + 1;
        } while (*pcVar10 != '\0');
        pcVar10 = acStack_b50;
        for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar12 = pcVar12 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar12 = pcVar12 + 1;
        }
      }
      sVar2 = *(short *)((int)piVar3 + 0x26);
      if (0 < sVar2) {
        pcVar12 = acStack_881;
        do {
          pcVar10 = pcVar12;
          pcVar12 = pcVar10 + 1;
        } while (pcVar10[1] != '\0');
        *(undefined4 *)(pcVar10 + 1) = DAT_00a3beb8;
        *(undefined4 *)(pcVar10 + 5) = DAT_00a3bebc;
        *(undefined2 *)(pcVar10 + 9) = DAT_00a3bec0;
        pcVar10[0xb] = DAT_00a3bec2;
        sprintf(acStack_b90,"%i",(int)sVar2);
        pcVar12 = acStack_b90;
        do {
          cVar1 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar1 != '\0');
        uVar6 = (int)pcVar12 - (int)acStack_b90;
        pcVar12 = acStack_881;
        do {
          pcVar10 = pcVar12 + 1;
          pcVar12 = pcVar12 + 1;
        } while (*pcVar10 != '\0');
        pcVar10 = acStack_b90;
        for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar12 = pcVar12 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar12 = pcVar12 + 1;
        }
      }
      if (pvVar7 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar7);
      }
      pvVar7 = operator_new(0x488);
      uStack_74 = 10;
      if (pvVar7 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_007b5dd0(pvVar7,0);
      }
      uStack_74 = 3;
      (**(code **)(iRam3f000000 + 0xa8))(piVar4);
      (**(code **)(*piVar4 + 0x28))("i_d_d_2d_wnd_discipline_bar.xml");
      iVar20 = 0x3f000000;
      fVar18 = 1.4013e-45;
      (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);
      (**(code **)(*piVar4 + 0x308))(auStack_890);
      piVar19[0x10] = (int)piVar4;
      iVar5 = FUN_0052ad60(*piVar3);
      uVar9 = FUN_0052ada0(*piVar3);
      if (iVar5 < 1) {
        acStack_994[0] = s_UNLEARNED_00a3be84[0];
        acStack_994[1] = s_UNLEARNED_00a3be84[1];
        acStack_994[2] = s_UNLEARNED_00a3be84[2];
        acStack_994[3] = s_UNLEARNED_00a3be84[3];
        acStack_990[0] = s_UNLEARNED_00a3be84[4];
        acStack_990[1] = s_UNLEARNED_00a3be84[5];
        acStack_990[2] = s_UNLEARNED_00a3be84[6];
        acStack_990[3] = s_UNLEARNED_00a3be84[7];
        acStack_98c[0] = s_UNLEARNED_00a3be84[8];
        acStack_98c[1] = s_UNLEARNED_00a3be84[9];
      }
      else {
        sprintf(acStack_994,"%i/%i",uVar9,iVar5);
      }
      (**(code **)(*piVar4 + 0x1d8))(acStack_994,1,1);
      pcStack_bd8 = (char *)(int)((float)DAT_00d1e818 * (float)pvVar7 * DAT_00aaa67c);
      ppcVar17 = &pcStack_bd8;
      (**(code **)(*piVar4 + 0x110))();
      pvVar7 = operator_new(0x4cc);
      uStack_98 = 0xb;
      if (pvVar7 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_0079c860();
      }
      uStack_98 = 3;
      (**(code **)(*piVar19 + 0xa8))(piVar4);
      (**(code **)(*piVar4 + 0x28))("i_d_d_2d_btn_add.xml");
      (**(code **)(*piVar4 + 0x74))(iVar20 + 0x9c43);
      (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);
      *ppcVar17 = (char *)piVar4;
      pfVar8 = (float *)(**(code **)(*piVar4 + 0x124))(aiStack_be0);
      piStack_c04 = (int *)(int)((float)DAT_00d1e818 * (float)(int)*pfVar8 * DAT_00aaa67c);
      pcVar12 = (char *)(int)((float)DAT_00d1e81c * fVar18 * DAT_00aaa678);
      (**(code **)(*(int *)*ppcVar17 + 0x110))(&piStack_c04);
      (**(code **)(*(int *)*ppcVar17 + 0xd4))(0);
      ppcVar17[0x30] = (char *)*piVar3;
      param_1 = piStack_be4;
    }
    uVar21 = uVar21 + 1;
    uStack_bf0 = uStack_bf0 + 0x14;
    aiStack_be0[0] = aiStack_be0[0] + 0x37;
  }
  while( true ) {
    if (pvVar7 == pvStack_bb0) {
      uStack_44 = 3;
                    /* WARNING: Subroutine does not return */
      operator_delete(pvStack_bb4);
    }
    uStack_44 = 3;
    if (*(void **)((int)pvVar7 + 8) != (void *)0x0) break;
    *(undefined4 *)((int)pvVar7 + 8) = 0;
    *(undefined4 *)((int)pvVar7 + 0xc) = 0;
    *(undefined4 *)((int)pvVar7 + 0x10) = 0;
    pvVar7 = (void *)((int)pvVar7 + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)((int)pvVar7 + 8));
}
```
