# Raw capture: FUN_004ec8b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ec8b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ec8b0` |
| **Canonical name** | `FUN_004ec8b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_004ec8b0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined4 in_stack_00000018;
  undefined4 uStack_3bc;
  int iStack_3b8;
  undefined4 uStack_3b4;
  undefined4 uStack_3b0;
  undefined4 uStack_3ac;
  undefined4 uStack_3a8;
  undefined4 uStack_3a4;
  undefined4 uStack_3a0;
  undefined4 uStack_39c;
  undefined4 uStack_398;
  undefined4 uStack_394;
  undefined1 auStack_38c [12];
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  undefined1 auStack_33c [3];
  char cStack_339;
  char local_338 [4];
  char local_334 [4];
  char local_330 [4];
  char local_32c [4];
  char local_328 [2];
  char local_326;
  char cStack_231;
  char local_230 [6];
  char local_22a [257];
  undefined4 uStack_129;
  void *pvStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a2867;
  local_1c = ExceptionList;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)&uStack_129 + (1 - (int)param_1)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  puVar9 = &uStack_129;
  do {
    pcVar2 = (char *)((int)puVar9 + 1);
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  } while (*pcVar2 != '\0');
  *puVar9 = DAT_009cb318;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_230 + -(int)param_1)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = &cStack_231;
  do {
    pcVar8 = pcVar2;
    pcVar2 = pcVar8 + 1;
  } while (pcVar8[1] != '\0');
  *(undefined4 *)(pcVar8 + 1) = s__cache_009ccf18._0_4_;
  *(undefined2 *)(pcVar8 + 5) = s__cache_009ccf18._4_2_;
  pcVar8[7] = s__cache_009ccf18[6];
  local_330 = (char  [4])s____physics_planes__00a95ff8._8_4_;
  local_334 = (char  [4])s____physics_planes__00a95ff8._4_4_;
  local_338 = (char  [4])s____physics_planes__00a95ff8._0_4_;
  local_326 = s____physics_planes__00a95ff8[0x12];
  local_328 = (char  [2])s____physics_planes__00a95ff8._16_2_;
  local_32c = (char  [4])s____physics_planes__00a95ff8._12_4_;
  pcVar2 = local_230;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = (int)pcVar2 - (int)local_230;
  pcVar2 = &cStack_339;
  do {
    pcVar8 = pcVar2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (*pcVar8 != '\0');
  pcVar8 = local_230;
  for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar2 = pcVar2 + 1;
  }
  iVar5 = (int)&uStack_129 + 1;
  ExceptionList = &local_1c;
  FUN_007b6a20(iVar5);
  piVar4 = (int *)FUN_007b7420(iVar5);
  if (piVar4 == (int *)0x0) {
    ExceptionList = local_1c;
    return 0;
  }
  iVar5 = (**(code **)(*piVar4 + 0x1c))();
  if (iVar5 == 0) {
    (**(code **)*piVar4)(1);
    FUN_007a4480(1,"Rigid body of object \'%s\' is zero length",param_1);
    ExceptionList = pvStack_20;
    return 0;
  }
  fStack_380 = g_flOne;
  fStack_37c = g_flOne;
  fStack_378 = g_flOne;
  fStack_374 = g_flOne;
  iVar5 = piVar4[1];
  uStack_3ac = 0;
  uVar6 = (**(code **)(*piVar4 + 0x1c))();
  FUN_005f3120(iVar5,uVar6);
  uStack_14 = 0;
  puVar9 = (undefined4 *)FUN_005f3740(auStack_38c,&fStack_380);
  (**(code **)*piVar4)(1);
  if (puVar9 != (undefined4 *)0x0) {
    iStack_3b8 = puVar9[1];
    if (iStack_3b8 * 4 < 0x801) {
      if (iStack_3b8 != 0) {
        uStack_3b4 = 0x10;
        uStack_3bc = *puVar9;
        FUN_007a4480(0xffffffff,"$$$$$$New TK cache:%s [%d]\n",auStack_33c,iStack_3b8);
        uStack_3a8 = 0;
        uStack_3a4 = 0;
        uStack_3a0 = 0x80000000;
        uStack_39c = 0;
        uStack_398 = 0;
        uStack_394 = 0x80000000;
        puStack_18 = (undefined1 *)CONCAT31(puStack_18._1_3_,1);
        FUN_006ba870(&uStack_3bc,&uStack_3a8,in_stack_00000018);
        iStack_3b8 = uStack_3a4;
        uStack_3b4 = 0x10;
        uStack_3bc = uStack_3a8;
        FUN_004f34b0();
                    /* WARNING: Subroutine does not return */
        operator_delete(puVar9);
      }
      FUN_007a4480(1,"Rigid body of object \'%s\' is empty or corrupt",param_1);
    }
    else {
      FUN_007a4480(1,"Rigid body of object \'%s\' had too many vertices - max is %d",param_1,0x200);
    }
    FUN_004f34b0();
                    /* WARNING: Subroutine does not return */
    operator_delete(puVar9);
  }
  puStack_18 = (undefined1 *)0xffffffff;
  FUN_005f3160();
  ExceptionList = pvStack_20;
  return uStack_3b0;
}
```
