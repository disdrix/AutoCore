# Raw capture: CVOGSectorMap_LoadMapFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dc510` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004dc510` |
| **Canonical name** | `CVOGSectorMap_LoadMapFile` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Load .fam/.fat map: streams header including m_coidPerPlayerLoadTrigger at sector+0xE7E0,
   m_coidCreatorLoadTrigger at +0xE7E8, m_coidOnKillTrigger, m_coidLastTeamTrigger, then objects. */

undefined4 __thiscall
CVOGSectorMap_LoadMapFile(int param_1,char *param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int *piVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 *puVar12;
  undefined1 local_fd5;
  int local_fd4;
  undefined4 local_fd0;
  int local_fcc;
  undefined4 local_fc8;
  int local_fc4;
  undefined1 local_fc0 [4];
  undefined4 local_fbc;
  undefined4 local_fb8;
  undefined1 local_fb4 [4];
  undefined4 local_fb0;
  undefined4 local_fac;
  undefined1 local_fa8 [4];
  undefined4 local_fa4;
  int local_fa0;
  undefined1 local_f9c [4];
  undefined4 local_f98;
  int local_f94;
  undefined4 local_f90 [2];
  undefined4 local_f88;
  undefined4 local_f84;
  undefined4 local_f80;
  undefined4 local_f7c;
  undefined1 *local_f78 [3];
  undefined1 *local_f6c;
  char cStack_f69;
  undefined1 local_f68 [2];
  undefined1 auStack_f66 [6];
  undefined1 local_f60;
  undefined1 auStack_e64 [4];
  undefined **local_e60;
  char local_e5c;
  char local_e58;
  undefined4 local_7cc;
  undefined1 local_7c8;
  undefined4 uStack_7c1;
  undefined1 auStack_7bc [260];
  undefined **local_6b8;
  undefined1 local_6b4;
  undefined1 local_6b2;
  undefined4 uStack_28;
  undefined4 local_24;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a23cc;
  local_1c = ExceptionList;
  if (*(int *)(param_1 + 0xe4f8) != 0) {
    ExceptionList = &local_1c;
    local_fd4 = param_1;
    if (*(int *)(param_1 + 0xe50c) != 0) {
      ExceptionList = &local_1c;
      FUN_005aa890();
    }
    local_fbc = FUN_0040fb90();
    local_fb8 = 0;
    local_14 = 0;
    local_fa4 = FUN_0040fb90();
    local_fa0 = 0;
    local_14._0_1_ = 1;
    local_f98 = FUN_0040fb90();
    local_f94 = 0;
    local_14._0_1_ = 2;
    local_fb0 = FUN_0040fb90();
    local_fac = 0;
    local_14 = CONCAT31(local_14._1_3_,3);
    local_fc4 = 0;
    local_fd0 = 0;
    local_fc8 = 0;
    local_f88 = 0;
    local_f84 = 0;
    FUN_004dc030(local_fc0,local_fa8,local_f9c,&local_f88,local_fb4);
    local_fc4 = local_f94 + local_fa0;
    local_fd0 = local_fb8;
    _local_f68 = (uint)(ushort)auStack_f66._0_2_ << 0x10;
    puVar10 = (undefined4 *)(local_f68 + 2);
    for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = 0;
    local_fc8 = local_fac;
    pcVar4 = strchr(param_2,0x3a);
    if (pcVar4 == (char *)0x0) {
      _local_f68 = DAT_00a95f84;
      local_f60 = DAT_00a95f8c;
      auStack_f66._2_4_ = DAT_00a95f88;
      pcVar4 = param_2;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar5 = &cStack_f69;
      do {
        pcVar11 = pcVar5 + 1;
        pcVar5 = pcVar5 + 1;
      } while (*pcVar11 != '\0');
      pcVar11 = param_2;
      for (uVar7 = (uint)((int)pcVar4 - (int)param_2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar7 = (int)pcVar4 - (int)param_2 & 3; param_1 = local_fd4, uVar7 != 0;
          uVar7 = uVar7 - 1) {
        *pcVar5 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar5 = pcVar5 + 1;
      }
    }
    else {
      pcVar4 = param_2;
      do {
        cVar1 = *pcVar4;
        pcVar4[(int)(local_f68 + -(int)param_2)] = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
    }
    FUN_004ce020(param_2);
    pcVar4 = strrchr(local_f68,0x2e);
    if (pcVar4 == (char *)0x0) {
      pcVar5 = ".fat";
      pcVar4 = pcVar5;
      if (param_4 == '\0') {
        pcVar5 = ".fam";
        pcVar4 = pcVar5;
      }
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar11 = &cStack_f69;
      do {
        pcVar8 = pcVar11 + 1;
        pcVar11 = pcVar11 + 1;
      } while (*pcVar8 != '\0');
      pcVar8 = pcVar4;
      for (uVar7 = (uint)((int)pcVar5 - (int)pcVar4) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar7 = (int)pcVar5 - (int)pcVar4 & 3; param_1 = local_fd4, uVar7 != 0; uVar7 = uVar7 - 1
          ) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
    }
    iVar6 = 0;
    do {
      cVar1 = local_f68[iVar6];
      *(char *)((int)&uStack_7c1 + iVar6 + 1) = cVar1;
      iVar6 = iVar6 + 1;
    } while (cVar1 != '\0');
    puVar10 = &uStack_7c1;
    do {
      puVar12 = puVar10;
      puVar10 = (undefined4 *)((int)puVar12 + 1);
    } while (*(char *)((int)puVar12 + 1) != '\0');
    *(undefined4 *)((int)puVar12 + 1) = DAT_009cc944;
    *(undefined1 *)((int)puVar12 + 5) = DAT_009cc948;
    CopyFileA(local_f68,(LPCSTR)((int)&uStack_7c1 + 1),0);
    FUN_0079ce60();
    local_e60 = &PTR_FUN_009cbfd0;
    local_7cc = 0;
    local_7c8 = 0;
    local_14._0_1_ = 4;
    local_e58 = param_4;
    FUN_0079ca30(local_f68);
    if (local_e5c != '\0') {
      FUN_0079d290(1,"CVOGSectorMap");
      CVOGTerrain_StreamMapHeader(&local_e60);
      FUN_0079ce30("m_hv3EntryPoint",param_1 + 0xe4c0,0x10);
      FUN_00498740("lNumberModulePlacements",&local_fc8);
      FUN_00426c70("szNumberObjects",&local_fc4);
      FUN_00426c70("szNumberClientObjects",&local_fd0);
      FUN_00514320(&local_e60,"coidHighest",&local_f88);
      FUN_00514320(&local_e60,"m_coidPerPlayerLoadTrigger",param_1 + 0xe7e0);
      FUN_00514320(&local_e60,"m_coidCreatorLoadTrigger",param_1 + 0xe7e8);
      FUN_00514320(&local_e60,"m_coidOnKillTrigger",param_1 + 0xe7d8);
      FUN_00514320(&local_e60,"m_coidLastTeamTrigger",param_1 + 0xe7f0);
      FUN_004d0530(&local_e60);
      FUN_005afa60(&local_e60);
      FUN_0079ce60();
      local_6b8 = &PTR_FUN_009cc040;
      local_24 = 0;
      local_6b4 = 1;
      local_6b2 = 1;
      local_14 = CONCAT31(local_14._1_3_,5);
      local_f78[0] = local_fb4;
      local_f78[1] = local_f9c;
      local_f78[2] = local_fa8;
      local_f6c = local_fc0;
      local_fcc = 0;
      do {
        puVar2 = local_f78[local_fcc];
        piVar3 = *(int **)(puVar2 + 4);
        piVar9 = (int *)*piVar3;
        if (piVar9 != piVar3) {
          do {
            local_fd5 = *(undefined1 *)(piVar9[2] + 0x178);
            if (*(int *)(piVar9[2] + 0xa8) == 0) {
              local_f90[0] = 0xffffffff;
            }
            else {
              local_f90[0] = *(undefined4 *)(*(int *)(piVar9[2] + 0xa8) + 0x34);
            }
            local_f80 = *(undefined4 *)(piVar9[2] + 0x160);
            local_f7c = *(undefined4 *)(piVar9[2] + 0x164);
            FUN_004988c0("chLayer",&local_fd5);
            FUN_00498740(&DAT_009cc864,local_f90);
            FUN_00514320(&local_e60,&DAT_009cc85c,&local_f80);
            (**(code **)(*(int *)piVar9[2] + 0xa8))(&local_6b8);
            local_f90[0] = uStack_28;
            uStack_28 = 0;
            FUN_00498740(&DAT_009cc854,local_f90);
            (**(code **)(*(int *)piVar9[2] + 0xa8))(auStack_e64);
            piVar9 = (int *)*piVar9;
          } while (piVar9 != (int *)*(int *)(puVar2 + 4));
        }
        iVar6 = local_fd4;
        local_fcc = local_fcc + 1;
      } while (local_fcc < 4);
      FUN_00497d60(&local_e60);
      FUN_0079d1e0();
      FUN_0079cb60();
      FUN_00497760(iVar6 + 0xe198);
      FUN_005aa8f0();
      local_6b8 = &PTR_LAB_009cbf98;
      local_e60 = &PTR_FUN_009cbfd0;
      local_14 = CONCAT31(local_14._1_3_,6);
      FUN_0079cb60();
      local_e60 = &PTR_LAB_009cbf98;
      FUN_00403430();
      FUN_00403430();
      FUN_00403430();
      FUN_00403430();
      ExceptionList = local_1c;
      return 1;
    }
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_00405000();
    FUN_00403430();
    FUN_00403430();
    FUN_00403430();
    FUN_00403430();
  }
  ExceptionList = local_1c;
  return 0;
}
```
