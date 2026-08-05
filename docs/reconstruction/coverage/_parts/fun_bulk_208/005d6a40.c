void __thiscall FUN_005d6a40(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_3;
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  *param_1 = param_2[2] * fVar3 + param_2[1] * fVar2 + *param_2 * fVar1;
  param_1[1] = param_2[6] * fVar3 + param_2[5] * fVar2 + param_2[4] * fVar1;
  param_1[2] = param_2[10] * fVar3 + param_2[9] * fVar2 + param_2[8] * fVar1;
  param_1[3] = 0.0;
  return;
}
