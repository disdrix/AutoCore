void __fastcall FUN_005d7ca0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  int local_4;
  
  puVar5 = &local_8;
  local_8 = *(undefined4 *)
             (*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xac + param_1[0x19]) +
                      0x3c) + 0x4dc);
  piVar4 = &local_4;
  FUN_00540890(0);
  FUN_004cbd50(piVar4,puVar5);
  iVar2 = FUN_00540890(0);
  if (local_4 == *(int *)(iVar2 + 4)) {
    return;
  }
  FUN_004c3c80(0);
  if (*(char *)(param_1[0x19] + 0x26c) == '\0') {
    NPC_TryCastSkillFromSet(param_1,0);
    FUN_005cedf0();
    if ((char)param_1[0x18] == '\0') {
      cVar1 = FUN_005cc980();
      if (cVar1 != '\0') {
        return;
      }
      (**(code **)(*param_1 + 0x1c))();
      if (*(int *)(param_1[6] + 0xa0) != 0) {
        (**(code **)(*param_1 + 0x2c))(2);
      }
      cVar1 = FUN_005cebd0(0);
      if (cVar1 != '\0') {
        return;
      }
      iVar2 = *param_1;
      uVar3 = (**(code **)(*(int *)param_1[6] + 0x1a0))(0);
      (**(code **)(iVar2 + 0x4c))(uVar3);
      return;
    }
  }
  else {
    NPC_TryCastSkillFromSet(param_1,2);
    FUN_005cedf0();
    if ((char)param_1[0x18] == '\0') {
      cVar1 = FUN_005cc980();
      if (cVar1 != '\0') {
        return;
      }
      if (*(int *)(param_1[6] + 0xa0) != 0) {
        FUN_005cf560();
      }
      if (*(int *)(param_1[6] + 0xa0) != 0) {
        return;
      }
      (**(code **)(*param_1 + 0x2c))(0);
      return;
    }
  }
  FUN_005cc450();
  return;
}
