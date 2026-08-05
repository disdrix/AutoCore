// =============================================================================
// FUN_005d9af0  (Ghidra symbol twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d9af0
// Address:   0x005d9af0 – 0x005d9e94
// Canonical: Drive_CollisionListener_PlayCollisionEffect
// Generated: 2026-07-29 W23-G — inventory glue twin; prefer named plate.
// =============================================================================

void __thiscall FUN_005d9af0(
    int param_1,
    float *param_2,
    uint32_t param_3,
    uint32_t param_4,
    int *in_stack_00000010,
    int8_t in_stack_00000014)
{
  int iVar1;
  void *pvVar2;
  uint32_t uVar3;
  void *local_1c;
  uint8_t *puStack_18;
  int local_14;

  (void)param_2;
  (void)param_3;
  (void)param_4;

  local_14 = 0xffffffff;
  puStack_18 = (uint8_t *)&LAB_009a71fa;
  local_1c = ExceptionList;
  if (in_stack_00000010 == (int *)0x0) {
    return;
  }
  ExceptionList = &local_1c;
  FUN_0076cf00("CollisionListener::PlayCollisionEffect");
  iVar1 = in_stack_00000010[0x2a];
  local_14 = 0;
  FUN_004eb3b0();
  if (*(int *)(iVar1 + 0x88) == 0) {
LAB_005d9b75:
    if (in_stack_00000014 == 0) goto LAB_005d9e70;
    if (*(int *)(param_1 + 4) == 0) {
      pvVar2 = operator_new(8);
      local_14 = (local_14 & ~0xff) | 1;
      if (pvVar2 == (void *)0x0) {
        uVar3 = 0;
      } else {
        uVar3 = FUN_004a1620();
      }
      local_14 = (int)((uint32_t)local_14 & 0xffffff00);
      *(uint32_t *)(param_1 + 4) = uVar3;
      FUN_004a6390();
    }
    if ((*(int *)(param_1 + 4) == 0) || (iVar1 = FUN_004a16d0(), iVar1 == 0)) goto LAB_005d9e70;
  } else {
    FUN_004eb3b0();
    iVar1 = FUN_004a16d0();
    if (iVar1 == 0) goto LAB_005d9b75;
  }
  (**(code **)(*in_stack_00000010 + 0x1c8))();
  (**(code **)(*in_stack_00000010 + 0x1c8))();
  FUN_004b7550();
  FUN_004b7550();
  FUN_004b7550();
  (**(code **)(*in_stack_00000010 + 0xf8))();
  FUN_004b7e50(0, 0, 0);
LAB_005d9e70:
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return;
}
