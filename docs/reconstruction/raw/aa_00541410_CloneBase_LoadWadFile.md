# Raw capture: CloneBase_LoadWadFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541410` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00541410` |
| **Canonical name** | `CloneBase_LoadWadFile` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 CloneBase_LoadWadFile(void)

{
  FILE *_File;
  int *piVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  size_t *psVar7;
  size_t asStack_328 [5];
  undefined4 auStack_314 [12];
  undefined4 uStack_2e4;
  size_t sStack_2e0;
  size_t asStack_2dc [66];
  undefined4 uStack_1d4;
  size_t sStack_1a0;
  int local_19c;
  int local_198;
  void *local_194;
  undefined4 auStack_190 [95];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009a3fd2;
  local_14 = ExceptionList;
  if (DAT_00b04694 != '\0') {
    ExceptionList = &local_14;
    _File = fopen("../clonebase.wad","rb");
    if (_File == (FILE *)0x0) {
      vog_LogMessage();
      ExceptionList = local_14;
      return 0;
    }
    local_19c = 0;
    fread(&local_19c,4,1,_File);
    if (local_19c != 0x1b) {
      FUN_007a4480();
      fclose(_File);
      ExceptionList = local_14;
      return 0;
    }
    fread(&local_198,4,1,_File);
    local_19c = 0;
    if (0 < local_198) {
      do {
        fread(&local_194,4,1,_File);
        piVar1 = (int *)FUN_0059b370();
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))();
          FUN_00545990();
        }
        local_19c = local_19c + 1;
      } while (local_19c < local_198);
    }
    fread(&local_19c,4,1,_File);
    local_198 = 0;
    if (0 < local_19c) {
      do {
        local_194 = operator_new(0x170);
        uStack_c = 0;
        if (local_194 == (void *)0x0) {
          pvVar2 = (void *)0x0;
        }
        else {
          pvVar2 = (void *)FUN_005480d0();
        }
        uStack_c = 0xffffffff;
        local_194 = pvVar2;
        FUN_00547f90();
        if ((DAT_00b0434c == 0) ||
           ((uint)(DAT_00b04354 - DAT_00b0434c >> 2) <=
            (uint)((int)DAT_00b04350 - DAT_00b0434c >> 2))) {
          FUN_004e39d0();
        }
        else {
          *DAT_00b04350 = pvVar2;
          DAT_00b04350 = DAT_00b04350 + 1;
        }
        local_198 = local_198 + 1;
      } while (local_198 < local_19c);
    }
    local_19c = 0;
    fread(&local_19c,4,1,_File);
    local_198 = 0;
    if (0 < local_19c) {
      do {
        iVar5 = 0;
        pvVar2 = operator_new(0x934);
        *(undefined4 *)((int)pvVar2 + 0x930) = 0;
        local_194 = pvVar2;
        fread(pvVar2,0x930,1,_File);
        if (*(short *)((int)pvVar2 + 0x92c) < 1) {
          *(undefined4 *)((int)pvVar2 + 0x930) = 0;
        }
        else {
          pvVar3 = operator_new__(*(short *)((int)pvVar2 + 0x92c) * 0x14);
          *(void **)((int)pvVar2 + 0x930) = pvVar3;
        }
        if (0 < *(short *)((int)pvVar2 + 0x92c)) {
          sStack_1a0 = 0;
          do {
            fread((void *)(*(int *)((int)pvVar2 + 0x930) + sStack_1a0),0x14,1,_File);
            sStack_1a0 = sStack_1a0 + 0x14;
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(short *)((int)pvVar2 + 0x92c));
        }
        if ((DAT_00b0435c == 0) ||
           ((uint)(DAT_00b04364 - DAT_00b0435c >> 2) <=
            (uint)((int)DAT_00b04360 - DAT_00b0435c >> 2))) {
          FUN_004e39d0();
        }
        else {
          *DAT_00b04360 = pvVar2;
          DAT_00b04360 = DAT_00b04360 + 1;
        }
        local_198 = local_198 + 1;
      } while (local_198 < local_19c);
    }
    sStack_1a0 = 0;
    fread(&sStack_1a0,4,1,_File);
    asStack_2dc[3] = sStack_1a0;
    puVar4 = auStack_190;
    for (iVar5 = 0x47; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = auStack_190;
    psVar7 = asStack_2dc + 4;
    for (iVar5 = 0x47; iVar5 != 0; iVar5 = iVar5 + -1) {
      *psVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      psVar7 = psVar7 + 1;
    }
    asStack_2dc[2] = 0x54175a;
    FUN_00511040();
    fread(DAT_00b046c8,0x11c,sStack_1a0,_File);
    uStack_1d4 = 0x54177a;
    fread(&sStack_1a0,4,1,_File);
    sStack_2e0 = sStack_1a0;
    puVar4 = auStack_190;
    for (iVar5 = 0x4b; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = auStack_190;
    psVar7 = asStack_2dc;
    for (iVar5 = 0x4b; iVar5 != 0; iVar5 = iVar5 + -1) {
      *psVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      psVar7 = psVar7 + 1;
    }
    uStack_2e4 = 0x5417b2;
    FUN_00511100();
    fread(DAT_00b046d8,300,sStack_1a0,_File);
    uStack_1d4 = 0x5417d2;
    fread(&sStack_1a0,4,1,_File);
    puVar4 = auStack_190;
    for (iVar5 = 0x5e; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = auStack_190;
    psVar7 = asStack_328;
    for (iVar5 = 0x5e; iVar5 != 0; iVar5 = iVar5 + -1) {
      *psVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      psVar7 = psVar7 + 1;
    }
    FUN_00510f90(sStack_1a0);
    fread(DAT_00b046b8,0x178,sStack_1a0,_File);
    uStack_1d4 = 0x541829;
    fread(&sStack_1a0,4,1,_File);
    asStack_328[4] = sStack_1a0;
    puVar4 = auStack_190;
    for (iVar5 = 0x59; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = auStack_190;
    puVar6 = auStack_314;
    for (iVar5 = 0x59; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    asStack_328[3] = 0x54185e;
    FUN_005111b0();
    fread(DAT_00b046e8,0x164,sStack_1a0,_File);
    uStack_1d4 = 0x54187e;
    fread(&sStack_1a0,4,1,_File);
    asStack_2dc[2] = sStack_1a0;
    puVar4 = auStack_190;
    for (iVar5 = 0x48; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = auStack_190;
    psVar7 = asStack_2dc + 3;
    for (iVar5 = 0x48; iVar5 != 0; iVar5 = iVar5 + -1) {
      *psVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      psVar7 = psVar7 + 1;
    }
    asStack_2dc[1] = 0x5418b6;
    FUN_00511270();
    fread(DAT_00b046f8,0x120,sStack_1a0,_File);
    uStack_1d4 = 0x5418d6;
    fread(&sStack_1a0,4,1,_File);
    puVar4 = auStack_190;
    for (iVar5 = 0x46; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = auStack_190;
    psVar7 = asStack_2dc + 5;
    for (iVar5 = 0x46; iVar5 != 0; iVar5 = iVar5 + -1) {
      *psVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      psVar7 = psVar7 + 1;
    }
    asStack_2dc[4] = sStack_1a0;
    asStack_2dc[3] = 0x54190e;
    FUN_00511320();
    fread(DAT_00b04708,0x118,sStack_1a0,_File);
    fclose(_File);
  }
  ExceptionList = local_14;
  return 1;
}
```
