# Raw capture: FUN_005ea7a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ea7a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ea7a0` |
| **Canonical name** | `FUN_005ea7a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Type propagation algorithm not settling */

uint __fastcall FUN_005ea7a0(int param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  FILE *_File;
  FILE *_File_00;
  long lVar5;
  uint uVar6;
  int unaff_ESI;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 uStack_16c;
  undefined1 auStack_168 [4];
  int *piStack_164;
  int iStack_160;
  undefined1 auStack_15c [4];
  int *piStack_158;
  int iStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_144 [4];
  int *piStack_140;
  int iStack_13c;
  int *piStack_138;
  int aiStack_134 [2];
  undefined4 uStack_12c;
  undefined1 auStack_129 [5];
  undefined4 uStack_124;
  undefined1 uStack_120;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a780e;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_004da160();
  piStack_140 = (int *)FUN_0040fb90();
  iStack_13c = 0;
  uStack_14 = 0;
  piStack_164 = (int *)FUN_0040fb90();
  iStack_160 = 0;
  uStack_14._0_1_ = 1;
  piStack_158 = (int *)FUN_0040fb90();
  iStack_154 = 0;
  uStack_14 = CONCAT31(uStack_14._1_3_,2);
  aiStack_134[1] = 0;
  uStack_12c = 0;
  FUN_004dc030(auStack_144,auStack_168,auStack_15c,aiStack_134 + 1,0);
  aiStack_134[0] = iStack_154 + iStack_160;
  piStack_138 = (int *)(param_1 + 0x10);
  *piStack_138 = aiStack_134[0] + iStack_13c;
  auStack_129._1_4_ = DAT_00a95f84;
  pcVar1 = (char *)(param_1 + 0x20);
  uStack_124 = DAT_00a95f88;
  uStack_120 = DAT_00a95f8c;
  pcVar4 = pcVar1;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  pcVar8 = (char *)((int)register0x00000010 + 0xfffffed7);
  do {
    pcVar7 = pcVar8 + 1;
    pcVar8 = pcVar8 + 1;
  } while (*pcVar7 != '\0');
  pcVar7 = pcVar1;
  for (uVar6 = (uint)((int)pcVar4 - (int)pcVar1) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar6 = (int)pcVar4 - (int)pcVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar8 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  }
  puVar3 = (undefined4 *)((int)register0x00000010 + 0xfffffed7);
  do {
    puVar9 = puVar3;
    puVar3 = (undefined4 *)((int)puVar9 + 1);
  } while (*(char *)((int)puVar9 + 1) != '\0');
  *(undefined4 *)((int)puVar9 + 1) = DAT_009dcdcc;
  *(undefined1 *)((int)puVar9 + 5) = DAT_009dcdd0;
  _File = fopen((undefined1 *)((int)register0x00000010 + 0xfffffed7) + 1,"wb");
  if (_File == (FILE *)0x0) {
    FUN_00403430();
    FUN_00403430();
    uVar6 = FUN_00403430();
    ExceptionList = pvStack_1c;
    return uVar6 & 0xffffff00;
  }
  fwrite(&DAT_009dcc7c,4,1,_File);
  fwrite((void *)(param_1 + 0x1c),4,1,_File);
  fwrite((void *)(param_1 + 0x18),4,1,_File);
  fwrite((void *)(param_1 + 0x14),4,1,_File);
  fwrite(piStack_138,4,1,_File);
  fwrite(aiStack_134,4,1,_File);
  FUN_00512350(_File,aiStack_134 + 1);
  _File_00 = fopen("garbagefile","wb");
  piVar10 = (int *)*piStack_158;
  if (piVar10 != piStack_158) {
    do {
      if (*(int *)(piVar10[2] + 0xa8) == 0) {
        uStack_16c = 0xffffffff;
      }
      else {
        uStack_16c = *(undefined4 *)(*(int *)(piVar10[2] + 0xa8) + 0x34);
      }
      fwrite(&uStack_16c,4,1,_File);
      uStack_150 = *(undefined4 *)(piVar10[2] + 0x160);
      uStack_14c = *(undefined4 *)(piVar10[2] + 0x164);
      FUN_00512350(_File,&uStack_150);
      (**(code **)(*(int *)piVar10[2] + 0x38))(param_1);
      ftell(_File_00);
      (**(code **)(*(int *)piVar10[2] + 0xa0))(_File_00);
      lVar5 = ftell(_File_00);
      unaff_ESI = lVar5 - unaff_ESI;
      fwrite(&stack0xfffffe84,4,1,_File);
      (**(code **)(*(int *)piVar10[2] + 0xa0))(_File);
      (**(code **)(*(int *)piVar10[2] + 0x3c))(unaff_ESI);
      piVar10 = (int *)*piVar10;
    } while (piVar10 != piStack_158);
  }
  piVar10 = (int *)*piStack_164;
  if (piVar10 != piStack_164) {
    do {
      if (*(int *)(piVar10[2] + 0xa8) == 0) {
        uStack_16c = 0xffffffff;
      }
      else {
        uStack_16c = *(undefined4 *)(*(int *)(piVar10[2] + 0xa8) + 0x34);
      }
      fwrite(&uStack_16c,4,1,_File);
      uStack_150 = *(undefined4 *)(piVar10[2] + 0x160);
      uStack_14c = *(undefined4 *)(piVar10[2] + 0x164);
      FUN_00512350(_File,&uStack_150);
      (**(code **)(*(int *)piVar10[2] + 0x38))(param_1);
      ftell(_File_00);
      (**(code **)(*(int *)piVar10[2] + 0xa0))(_File_00);
      lVar5 = ftell(_File_00);
      unaff_ESI = lVar5 - unaff_ESI;
      fwrite(&stack0xfffffe84,4,1,_File);
      (**(code **)(*(int *)piVar10[2] + 0xa0))(_File);
      (**(code **)(*(int *)piVar10[2] + 0x3c))(unaff_ESI);
      piVar10 = (int *)*piVar10;
    } while (piVar10 != piStack_164);
  }
  piVar10 = (int *)*piStack_140;
  if (piVar10 != piStack_140) {
    do {
      if (*(int *)(piVar10[2] + 0xa8) == 0) {
        uStack_16c = 0xffffffff;
      }
      else {
        uStack_16c = *(undefined4 *)(*(int *)(piVar10[2] + 0xa8) + 0x34);
      }
      fwrite(&uStack_16c,4,1,_File);
      uStack_150 = *(undefined4 *)(piVar10[2] + 0x160);
      uStack_14c = *(undefined4 *)(piVar10[2] + 0x164);
      FUN_00512350(_File,&uStack_150);
      (**(code **)(*(int *)piVar10[2] + 0x38))(param_1);
      ftell(_File_00);
      (**(code **)(*(int *)piVar10[2] + 0xa0))(_File_00);
      lVar5 = ftell(_File_00);
      unaff_ESI = lVar5 - unaff_ESI;
      fwrite(&stack0xfffffe84,4,1,_File);
      (**(code **)(*(int *)piVar10[2] + 0xa0))(_File);
      (**(code **)(*(int *)piVar10[2] + 0x3c))(unaff_ESI);
      piVar10 = (int *)*piVar10;
    } while (piVar10 != piStack_140);
  }
  fclose(_File);
  fclose(_File_00);
  remove("garbagefile");
  piVar10 = (int *)*piStack_158;
  *piStack_158 = (int)piStack_158;
  piStack_158[1] = (int)piStack_158;
  iStack_154 = 0;
  if (piVar10 == piStack_158) {
                    /* WARNING: Subroutine does not return */
    operator_delete(piStack_158);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(piVar10);
}
```
