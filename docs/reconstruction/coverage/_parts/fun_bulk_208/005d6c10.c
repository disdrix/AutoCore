undefined4 __fastcall FUN_005d6c10(CVOGHBBase *param_1,uint *param_2,undefined4 param_3)

{
  uint *extraout_EDX;
  
  if (param_1->pOwnerObject != (void *)0x0) {
    FUN_004c7bd0(param_1->nPeriodMs);
    param_2 = extraout_EDX;
  }
  CVOGHBBase_RescheduleAfterFire(param_1,param_2);
  return param_3;
}
