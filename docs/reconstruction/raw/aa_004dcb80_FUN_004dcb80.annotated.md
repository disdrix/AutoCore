# Annotated low-level: FUN_004dcb80

| Field | Value |
|---|---|
| Stable ID | `aa_004dcb80` |
| VA | `0x004dcb80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004dcb80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __thiscall FUN_004dcb80(int param_1,char *param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  FILE *_File;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  FILE *_File_00;
  uint uVar5;
  char *pcVar6;
  int *piVar7;
  int *piVar8;
  long lVar9;
  undefined4 uVar10;
  int *piVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined4 uStack_b58;
  FILE *local_b54;
  int *local_b50;
  size_t local_b4c;
  undefined4 local_b48;
  undefined1 uStack_b41;
  undefined4 local_b40;
  uint local_b3c;
  int local_b38;
  int local_b34;
  int local_b2c;
  undefined1 local_b28 [4];
  int *local_b24;
  undefined4 local_b20;
  undefined1 local_b1c [4];
  int *local_b18;
  int local_b14;
  undefined4 local_b10;
  undefined1 local_b0c [4];
  int *local_b08;
  int local_b04;
  undefined4 local_b00;
  undefined1 local_afc [4];
  int *local_af8;
  undefined4 local_af4;
  int local_af0;
  undefined4 local_aec;
  undefined4 local_ae8;
  undefined4 local_ae4;
  undefined1 local_adc [4];
  undefined4 local_ad8;
  undefined4 local_ad4;
  undefined1 local_ad0;
  undefined4 uStack_9d1;
  undefined1 auStack_9cc [780];
  undefined **appuStack_6c0 [421];
  undefined4 uStack_2c;
  undefined1 uStack_28;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a2423;
  local_1c = ExceptionList;
  uVar5 = 0;
  if (*(int *)(param_1 + 0xe4f8) != 0) {
    ExceptionList = &local_1c;
    local_b2c = param_1;
    FUN_007a4400("CVOGSectorMap::SaveToFile");
    local_14 = 0;
    if (*(int *)(param_1 + 0xe50c) != 0) {
      FUN_005aa890();
    }
    local_af8 = (int *)FUN_0040fb90();
    local_af4 = 0;
    local_14._0_1_ = 1;
    local_b08 = (int *)FUN_0040fb90();
    local_b04 = 0;
    local_14._0_1_ = 2;
    local_b18 = (int *)FUN_0040fb90();
    local_b14 = 0;
    local_14._0_1_ = 3;
    local_b24 = (int *)FUN_0040fb90();
    local_b20 = 0;
    local_14 = CONCAT31(local_14._1_3_,4);
    local_af0 = 0;
    local_b00 = 0;
    local_b10 = 0;
    local_ae8 = 0;
    local_ae4 = 0;
    FUN_004dc030(local_afc,local_b0c,local_b1c,&local_ae8,local_b28);
    local_af0 = local_b14 + local_b04;
    local_b00 = local_af4;
    local_b10 = local_b20;
    pcVar3 = strchr(param_2,0x3a);
    if (pcVar3 == (char *)0x0) {
      local_ad8 = DAT_00a95f84;
      local_ad0 = DAT_00a95f8c;
      local_ad4 = DAT_00a95f88;
      pcVar3 = param_2;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcVar6 = local_adc + 3;
      do {
        pcVar12 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar12 != '\0');
      pcVar12 = param_2;
      for (uVar5 = (uint)((int)pcVar3 - (int)param_2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar5 = (int)pcVar3 - (int)param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar6 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar6 = pcVar6 + 1;
      }
    }
    else {
      pcVar3 = param_2;
      do {
        cVar1 = *pcVar3;
        pcVar3[(int)&local_ad8 - (int)param_2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    }
    FUN_004ce020(param_2);
    local_aec = *(undefined4 *)(DAT_00d1f050 + 100);
    pcVar3 = strrchr((char *)&local_ad8,0x2e);
    if (pcVar3 == (char *)0x0) {
      puVar2 = (undefined4 *)(local_adc + 3);
      do {
        puVar13 = puVar2;
        puVar2 = (undefined4 *)((int)puVar13 + 1);
      } while (*(char *)((int)puVar13 + 1) != '\0');
      *(undefined4 *)((int)puVar13 + 1) = DAT_00a285c4;
      *(undefined1 *)((int)puVar13 + 5) = DAT_00a285c8;
    }
    iVar4 = 0;
    do {
      cVar1 = *(char *)((int)&local_ad8 + iVar4);
      *(char *)((int)&uStack_9d1 + iVar4 + 1) = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
    puVar2 = &uStack_9d1;
    do {
      puVar13 = puVar2;
      puVar2 = (undefined4 *)((int)puVar13 + 1);
    } while (*(char *)((int)puVar13 + 1) != '\0');
    *(undefined4 *)((int)puVar13 + 1) = DAT_009cc944;
    *(undefined1 *)((int)puVar13 + 5) = DAT_009cc948;
    CopyFileA((LPCSTR)&local_ad8,(LPCSTR)((int)&uStack_9d1 + 1),0);
    _File_00 = fopen((char *)&local_ad8,"wb");
    if (_File_00 != (FILE *)0x0) {
      FUN_004a8390(_File_00);
      fwrite((void *)(param_1 + 0xe4c0),0x10,1,_File_00);
      fwrite(&local_b10,4,1,_File_00);
      fwrite(&local_af0,4,1,_File_00);
      fwrite(&local_b00,4,1,_File_00);
      FUN_00512350(_File_00,&local_ae8);
      fwrite((void *)(param_1 + 0xe7e0),8,1,_File_00);
      fwrite((void *)(param_1 + 0xe7e8),8,1,_File_00);
      fwrite((void *)(param_1 + 0xe7d8),8,1,_File_00);
      fwrite((void *)(param_1 + 0xe7f0),8,1,_File_00);
      FUN_004d0410(_File_00);
      FUN_004d0640(_File_00);
      FUN_005af970(_File_00);
      pcVar3 = (char *)(*(int *)(param_1 + 0x78) + 0x44);
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      local_b4c = (int)pcVar3 - (*(int *)(param_1 + 0x78) + 0x45);
      fwrite(&local_b4c,4,1,_File_00);
      fwrite((void *)(*(int *)(param_1 + 0x78) + 0x44),1,local_b4c,_File_00);
      iVar4 = *(int *)(param_1 + 0x78);
      local_b4c = *(size_t *)(iVar4 + 0x178);
      local_adc = (undefined1  [4])iVar4;
      fwrite(&local_b4c,4,1,_File_00);
      local_b50 = (int *)**(int **)(iVar4 + 0x174);
      uVar5 = local_b3c;
      if (local_b50 != *(int **)(iVar4 + 0x174)) {
        do {
          piVar8 = local_b50;
          piVar11 = local_b50 + 4;
          uStack_b58 = (FILE *)CONCAT13((char)local_b50[3],(undefined3)uStack_b58);
          fwrite((void *)((int)&uStack_b58 + 3),1,1,_File_00);
          if (piVar8[0x111] == 0) {
            local_b4c = 0;
          }
          else {
            local_b4c = (piVar8[0x112] - piVar8[0x111]) / 0x134;
          }
          fwrite(&local_b4c,4,1,_File_00);
          local_b54 = (FILE *)0x0;
          for (local_b3c = 0;
              (piVar8[0x111] != 0 && (local_b3c < (uint)((piVar8[0x112] - piVar8[0x111]) / 0x134)));
              local_b3c = local_b3c + 1) {
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x110),4,1,_File_00);
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x10c),4,1,_File_00);
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x118),4,1,_File_00);
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x114),4,1,_File_00);
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x11c),1,1,_File_00);
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x120),4,1,_File_00);
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x124),4,1,_File_00);
            fwrite((void *)(piVar8[0x111] + (int)local_b54 + 0x130),4,1,_File_00);
            pcVar6 = (char *)(piVar8[0x111] + (int)local_b54);
            pcVar3 = pcVar6 + 1;
            do {
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            local_b4c = (int)pcVar6 - (int)pcVar3;
            fwrite(&local_b4c,4,1,_File_00);
            if (local_b4c != 0) {
              fwrite((void *)(piVar8[0x111] + (int)local_b54),1,local_b4c,_File_00);
            }
            local_b54 = (FILE *)((int)local_b54 + 0x134);
          }
          piVar7 = piVar8 + 0x114;
          do {
            iVar4 = *piVar7;
            piVar7 = (int *)((int)piVar7 + 1);
          } while ((char)iVar4 != '\0');
          local_b4c = (int)piVar7 - ((int)piVar8 + 0x451);
          fwrite(&local_b4c,4,1,_File_00);
          if (local_b4c != 0) {
            fwrite(piVar8 + 0x114,1,local_b4c,_File_00);
          }
          local_b3c = 4;
          do {
            piVar8 = piVar11;
            do {
              iVar4 = *piVar8;
              piVar8 = (int *)((int)piVar8 + 1);
            } while ((char)iVar4 != '\0');
            local_b4c = (int)piVar8 - (int)((int)piVar11 + 1);
            fwrite(&local_b4c,4,1,_File_00);
            if (local_b4c != 0) {
              fwrite(piVar11,1,local_b4c,_File_00);
            }
            piVar11 = piVar11 + 0x43;
            local_b3c = local_b3c + -1;
          } while (local_b3c != 0);
          if (*(char *)((int)local_b50 + 0x571) == '\0') {
            piVar11 = (int *)local_b50[2];
            if (*(char *)((int)piVar11 + 0x571) == '\0') {
              cVar1 = *(char *)(*piVar11 + 0x571);
              local_b50 = piVar11;
              piVar11 = (int *)*piVar11;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar11 + 0x571);
                local_b50 = piVar11;
                piVar11 = (int *)*piVar11;
              }
            }
            else {
              cVar1 = *(char *)(local_b50[1] + 0x571);
              piVar8 = (int *)local_b50[1];
              piVar11 = local_b50;
              while ((local_b50 = piVar8, cVar1 == '\0' && (piVar11 == (int *)local_b50[2]))) {
                cVar1 = *(char *)(local_b50[1] + 0x571);
                piVar8 = (int *)local_b50[1];
                piVar11 = local_b50;
              }
            }
          }
          local_b3c = 0;
          uVar5 = 0;
        } while (local_b50 != *(int **)((int)local_adc + 0x174));
      }
      local_b3c = uVar5;
      uStack_b58 = (FILE *)CONCAT13(*(int *)(local_b2c + 0xe4fc) != 0,(undefined3)uStack_b58);
      fwrite((void *)((int)&uStack_b58 + 3),1,1,_File_00);
      if (uStack_b58._3_1_ != '\0') {
        FUN_005b3f00(_File_00);
      }
      local_b54 = fopen("garbagefile","wb");
      local_b50 = (int *)*local_b24;
      if (local_b50 != local_b24) {
        do {
          piVar11 = (int *)local_b50[2];
          uStack_b58 = (FILE *)CONCAT13((char)piVar11[0x5e],(undefined3)uStack_b58);
          fwrite((void *)((int)&uStack_b58 + 3),1,1,_File_00);
          if (piVar11[0x2a] == 0) {
            local_b40 = 0xffffffff;
          }
          else {
            local_b40 = *(undefined4 *)(piVar11[0x2a] + 0x34);
          }
          fwrite(&local_b40,4,1,_File_00);
          local_b38 = piVar11[0x58];
          local_b34 = piVar11[0x59];
          FUN_00512350(_File_00,&local_b38);
          local_b48 = ftell(local_b54);
          (**(code **)(*piVar11 + 0xa0))(local_b54);
          lVar9 = ftell(uStack_b58);
          local_b4c = lVar9 - local_b4c;
          fwrite(&local_b4c,4,1,_File_00);
          (**(code **)(*piVar11 + 0xa0))(_File_00);
          local_b50 = (int *)*local_b50;
        } while (local_b50 != local_b24);
      }
      local_b50 = (int *)*local_b18;
      if (local_b50 != local_b18) {
        do {
          piVar11 = (int *)local_b50[2];
          uStack_b58 = (FILE *)CONCAT13((char)piVar11[0x5e],(undefined3)uStack_b58);
          fwrite((void *)((int)&uStack_b58 + 3),1,1,_File_00);
          if (piVar11[0x2a] == 0) {
            local_b40 = 0xffffffff;
          }
          else {
            local_b40 = *(undefined4 *)(piVar11[0x2a] + 0x34);
          }
          fwrite(&local_b40,4,1,_File_00);
          local_b38 = piVar11[0x58];
          local_b34 = piVar11[0x59];
          FUN_00512350(_File_00,&local_b38);
          local_b48 = ftell(local_b54);
          (**(code **)(*piVar11 + 0xa0))(local_b54);
          lVar9 = ftell(uStack_b58);
          local_b4c = lVar9 - local_b4c;
          fwrite(&local_b4c,4,1,_File_00);
          pcVar3 = (char *)FUN_005d6870((int)&local_b48 + 3);
          if (((*pcVar3 == '\0') || ((float)piVar11[0x20] <= 0.0 && (float)piVar11[0x20] != 0.0)) ||
             ((float)piVar11[0x22] <= 0.0 && (float)piVar11[0x22] != 0.0)) {
            uVar10 = (**(code **)(*piVar11 + 0x160))
                               (piVar11[0x58],piVar11[0x59],(double)(float)piVar11[0x20],
                                (double)(float)piVar11[0x22]);
            FUN_007a4480(1,
                         "Object %s (%I64d) is at a weird location: %0.2f,%0.2f. Please fix this and resave the map."
                         ,uVar10);
          }
          (**(code **)(*piVar11 + 0xa0))(_File_00);
          if (param_4 != '\0') {
            FUN_004d7230();
          }
          local_b50 = (int *)*local_b50;
        } while (local_b50 != local_b18);
      }
      local_b50 = (int *)*local_b08;
      if (local_b50 != local_b08) {
        do {
          piVar11 = (int *)local_b50[2];
          uStack_b58 = (FILE *)CONCAT13((char)piVar11[0x5e],(undefined3)uStack_b58);
          fwrite((void *)((int)&uStack_b58 + 3),1,1,_File_00);
          if (piVar11[0x2a] == 0) {
            local_b40 = 0xffffffff;
          }
          else {
            local_b40 = *(undefined4 *)(piVar11[0x2a] + 0x34);
          }
          fwrite(&local_b40,4,1,_File_00);
          local_b38 = piVar11[0x58];
          local_b34 = piVar11[0x59];
          FUN_00512350(_File_00,&local_b38);
          local_b48 = ftell(local_b54);
          pcVar3 = (char *)FUN_005d6870(&uStack_b41);
          if (((*pcVar3 == '\0') || ((float)piVar11[0x20] <= 0.0 && (float)piVar11[0x20] != 0.0)) ||
             ((float)piVar11[0x22] <= 0.0 && (float)piVar11[0x22] != 0.0)) {
            uVar10 = (**(code **)(*piVar11 + 0x160))
                               (piVar11[0x58],piVar11[0x59],(double)(float)piVar11[0x20],
                                (double)(float)piVar11[0x22]);
            FUN_007a4480(1,
                         "Object %s (%I64d) is at a weird location: %0.2f,%0.2f. Please fix this and resave the map."
                         ,uVar10);
          }
          (**(code **)(*piVar11 + 0xa0))(local_b54);
          lVar9 = ftell(uStack_b58);
          local_b4c = lVar9 - local_b4c;
          fwrite(&local_b4c,4,1,_File_00);
          (**(code **)(*piVar11 + 0xa0))(_File_00);
          local_b50 = (int *)*local_b50;
        } while (local_b50 != local_b08);
      }
      local_b50 = (int *)*local_af8;
      if (local_b50 != local_af8) {
        do {
          piVar11 = (int *)local_b50[2];
          uStack_b58 = (FILE *)CONCAT13((char)piVar11[0x5e],(undefined3)uStack_b58);
          fwrite((void *)((int)&uStack_b58 + 3),1,1,_File_00);
          if (piVar11[0x2a] == 0) {
            local_b40 = 0xffffffff;
          }
          else {
            local_b40 = *(undefined4 *)(piVar11[0x2a] + 0x34);
          }
          fwrite(&local_b40,4,1,_File_00);
          local_b38 = piVar11[0x58];
          local_b34 = piVar11[0x59];
          FUN_00512350(_File_00,&local_b38);
          local_b48 = ftell(local_b54);
          (**(code **)(*piVar11 + 0xa0))(local_b54);
          lVar9 = ftell(uStack_b58);
          local_b4c = lVar9 - local_b4c;
          fwrite(&local_b4c,4,1,_File_00);
          pcVar3 = (char *)FUN_005d6870((int)&local_b48 + 3);
          if (((*pcVar3 == '\0') || ((float)piVar11[0x20] <= 0.0 && (float)piVar11[0x20] != 0.0)) ||
             ((float)piVar11[0x22] <= 0.0 && (float)piVar11[0x22] != 0.0)) {
            uVar10 = (**(code **)(*piVar11 + 0x160))
                               (piVar11[0x58],piVar11[0x59],(double)(float)piVar11[0x20],
                                (double)(float)piVar11[0x22]);
            FUN_007a4480(1,
                         "Object %s (%I64d) is at a weird location: %0.2f,%0.2f. Please fix this and resave the map."
                         ,uVar10);
          }
          (**(code **)(*piVar11 + 0xa0))(_File_00);
          if (param_4 != '\0') {
            FUN_004d7230();
          }
          local_b50 = (int *)*local_b50;
        } while (local_b50 != local_af8);
      }
      iVar4 = local_b2c;
      fwrite((void *)(local_b2c + 0xe7d4),4,1,_File_00);
      _File = local_b54;
      FUN_004d20c0(_File_00,local_b54);
      FUN_004d1a80(_File_00,_File,1);
      fclose(_File);
      remove("garbagefile");
      FUN_0079ce60();
      appuStack_6c0[0] = &PTR_FUN_009cbfd0;
      uStack_2c = 0;
      uStack_28 = 0;
      local_14 = CONCAT31(local_14._1_3_,5);
      FUN_0079c9a0(_File_00);
      FUN_00497d60(appuStack_6c0);
      fclose(_File_00);
      FUN_00497760(iVar4 + 0xe198);
      if (param_4 != '\0') {
        FUN_0099bfe0(iVar4 + 0xe198);
      }
      FUN_005aa8f0();
      appuStack_6c0[0] = &PTR_FUN_009cbfd0;
      local_14 = CONCAT31(local_14._1_3_,6);
      FUN_0079cb60();
      appuStack_6c0[0] = &PTR_LAB_009cbf98;
      piVar11 = (int *)*local_b24;
      *local_b24 = (int)local_b24;
      local_b24[1] = (int)local_b24;
      if (piVar11 != local_b24) {
                    /* WARNING: Subroutine does not return */
        operator_delete(piVar11);
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(local_b24);
    }
    FUN_00403430();
    FUN_00403430();
    FUN_00403430();
    FUN_00403430();
    local_14 = 0xffffffff;
    uVar5 = FUN_007a4390();
  }
  ExceptionList = local_1c;
  return uVar5 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
