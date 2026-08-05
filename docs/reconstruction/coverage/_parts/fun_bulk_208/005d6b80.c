undefined4 * __thiscall FUN_005d6b80(undefined4 *param_1,void *param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a7138;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CVOGHBBase_ctor(param_1);
  local_4 = 0;
  *param_1 = &PTR_FUN_009daee8;
  param_1[2] = 0x1e;
  CVOGHBBase_SetPeriodAndCounter(param_1,-1000,true);
  param_1[9] = param_2;
  if (param_2 != (void *)0x0) {
    param_2 = (void *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2);
  }
  CVOGHBBase_AttachOwnerObject(param_1,param_2);
  *(undefined4 *)(param_1[9] + 0x11c) = 0;
  FUN_004c7bd0(param_1[2]);
  ExceptionList = local_c;
  return param_1;
}
