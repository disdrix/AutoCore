// =============================================================================
// FUN_00503780
// -----------------------------------------------------------------------------
// Stable ID: aa_00503780
// Address:   0x00503780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t /* width from decompiler */ __thiscall FUN_00503780(void *param_1,float param_2,int param_3,int param_4)

{
  uint uVar1;
  short sVar2;
  uint16_t uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  uint32_t /* width from decompiler */ *puVar8;
  void *pArmorItem;
  short *psVar9;
  float local_b0;
  int local_ac;
  void *local_a8;
  int local_a4;
  void *local_a0;
  void *local_9c;
  void *pvStack_98;
  uint8_t *puStack_94;
  uint8_t auStack_90 [132];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2fc8;
  local_c = ExceptionList;
  local_a8 = (void *)0x0;
  local_9c = (void *)0x0;
  local_a0 = (void *)0x0;
  local_a4 = 0;
  local_ac = 0;
  if ((int)param_2 < 1) {
    return 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  *(float *)((int)param_1 + 0x14c) = param_2;
  local_b0 = param_2;
  iVar4 = FUN_0040b330(&local_b0);
  iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 8))
                    (*(uint32_t /* width from decompiler */ *)(iVar4 + 4),param_3,1);
  pvVar6 = (void *)0x0;
  if (iVar5 < 0) goto LAB_00503d20;
  uVar1 = *(uint *)(param_3 + 0xe6d8);
  iVar5 = *(int *)(param_3 + 0xe6dc);
  *(uint *)(param_3 + 0xe6dc) = iVar5 + (uint)(0xfffffffe < uVar1);
  *(uint *)(param_3 + 0xe6d8) = uVar1 + 1;
  FUN_00512160(uVar1,iVar5,0);
  (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 0x218))
            (param_3);
  pvVar6 = operator_new(0x2f0);
  if (pvVar6 == (void *)0x0) {
    local_b0 = 0.0;
  }
  else {
    local_b0 = (float)FUN_005a84f0(1);
  }
  iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)((int)local_b0 + 4) + 4) + 4 + (int)local_b0) + 8))
                    (*(uint32_t /* width from decompiler */ *)
                      (*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac +
                                        (int)param_1) + 0x3c) + 0x6f4),param_3,1);
  iVar5 = local_ac;
  pvVar6 = local_a0;
  if (iVar7 < 0) goto LAB_00503d20;
  uVar1 = *(uint *)(param_3 + 0xe6d8);
  iVar7 = *(int *)(param_3 + 0xe6dc);
  *(uint *)(param_3 + 0xe6dc) = iVar7 + (uint)(0xfffffffe < uVar1);
  *(uint *)(param_3 + 0xe6d8) = uVar1 + 1;
  FUN_00512160(uVar1,iVar7,0);
  (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x218))(param_3);
  Vehicle_SetWheelset(iVar5);
  local_a8 = operator_new(0x690);
  iVar5 = 0;
  puStack_8 = (uint8_t *)0x0;
  if (local_a8 != (void *)0x0) {
    iVar5 = FUN_004c9aa0(1);
  }
  puStack_8 = (uint8_t *)0xffffffff;
  local_a8 = (void *)iVar5;
  iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 8))
                    (*(uint32_t /* width from decompiler */ *)(iVar4 + 8),param_3,1);
  pvVar6 = local_a0;
  if (iVar7 < 0) goto LAB_00503d20;
  FUN_004c3700((int)*(short *)(iVar4 + 0x28));
  *(uint8_t *)(iVar5 + 0x100) = *(uint8_t *)(iVar4 + 0x2b);
  pvStack_98 = *(void **)(param_3 + 0xe6d8);
  iVar7 = *(int *)(param_3 + 0xe6dc);
  *(uint *)(param_3 + 0xe6dc) = iVar7 + (uint)((void *)0xfffffffe < pvStack_98);
  *(uint *)(param_3 + 0xe6d8) = (int)pvStack_98 + 1;
  FUN_00512160(pvStack_98,iVar7,0);
  (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x218))(param_3);
  puVar8 = (uint32_t /* width from decompiler */ *)FUN_00402d50(iVar4 + 0xf6);
  puStack_8 = (uint8_t *)0x1;
  FUN_00516720(*puVar8);
  puStack_8 = (uint8_t *)0xffffffff;
  if (puStack_94 != auStack_90) {
    free(puStack_94);
  }
  (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 0x158))
            (*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);
  FUN_004c49d0(param_1);
  local_b0 = g_flOne;
  if (param_4 != 0) {
    if (param_4 < 0) {
      local_b0 = (float)param_4 * DAT_00a0f70c;
    }
    else {
      if (param_4 < 1) goto LAB_00503aa6;
      local_b0 = (float)param_4 * DAT_00a10e78;
    }
    local_b0 = local_b0 + g_flOne;
    if (local_b0 <= 0.0) {
      local_b0 = g_flMultiKillCountBlend;
    }
  }
LAB_00503aa6:
  if (_DAT_009cd988 < (double)local_b0) {
    local_b0 = g_flVehicleHpTechCoeff;
  }
  if (0 < *(int *)(iVar4 + 0x10)) {
    local_a8 = operator_new(0x2e0);
    uStack_4 = 2;
    if (local_a8 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0056e730(1);
    }
    uStack_4 = 0xffffffff;
    local_a8 = (void *)iVar5;
    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 8))
                      (*(uint32_t /* width from decompiler */ *)(iVar4 + 0x10),param_3,1);
    pvVar6 = local_a0;
    if (iVar7 < 0) goto LAB_00503d20;
    Vehicle_AttachWeapon(iVar5,0,0);
    FUN_004f79d0(iVar5,param_3,local_b0);
  }
  if (0 < *(int *)(iVar4 + 0xc)) {
    local_9c = operator_new(0x2e0);
    uStack_4 = 3;
    if (local_9c == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_0056e730(1);
    }
    uStack_4 = 0xffffffff;
    local_9c = (void *)iVar5;
    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 8))
                      (*(uint32_t /* width from decompiler */ *)(iVar4 + 0xc),param_3,1);
    pvVar6 = local_a0;
    if (iVar7 < 0) goto LAB_00503d20;
    Vehicle_AttachWeapon(iVar5,1,0);
    FUN_004f79d0(iVar5,param_3,local_b0);
  }
  if (0 < *(int *)(iVar4 + 0x14)) {
    pvStack_98 = operator_new(0x2e0);
    uStack_4 = 4;
    if (pvStack_98 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_005ff910(1);
    }
    uStack_4 = 0xffffffff;
    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 8))
                      (*(uint32_t /* width from decompiler */ *)(iVar4 + 0x14),param_3,1);
    pvVar6 = local_a0;
    if (iVar7 < 0) goto LAB_00503d20;
    Vehicle_AttachWeapon(iVar5,2,0);
    FUN_004f79d0(iVar5,param_3,local_b0);
  }
  if (0 < *(int *)(iVar4 + 0x18)) {
    pvStack_98 = operator_new(0x2e0);
    uStack_4 = 5;
    if (pvStack_98 == (void *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_005ff780(1);
    }
    uStack_4 = 0xffffffff;
    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 8))
                      (*(uint32_t /* width from decompiler */ *)(iVar4 + 0x18),param_3,1);
    pvVar6 = local_a0;
    if (iVar7 < 0) goto LAB_00503d20;
    FUN_004fe800(iVar5,0,0);
    FUN_004f79d0(iVar5,param_3,local_b0);
  }
  if (0 < *(int *)(iVar4 + 0x1c)) {
    pvStack_98 = operator_new(0x270);
    uStack_4 = 6;
    if (pvStack_98 == (void *)0x0) {
      pArmorItem = (void *)0x0;
    }
    else {
      pArmorItem = (void *)FUN_005fe7a0(1);
    }
    uStack_4 = 0xffffffff;
    local_a0 = pArmorItem;
    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pArmorItem + 4) + 4) + 4 + (int)pArmorItem)
                        + 8))(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x1c),param_3,1);
    pvVar6 = local_a0;
    if (iVar4 < 0) {
LAB_00503d20:
      FUN_007a4480(1,"Found invalid template: %d",*(uint32_t /* width from decompiler */ *)((int)param_1 + 0x14c));
      if (pvVar6 != (void *)0x0) {
        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)((int)pvVar6 + 4) + 4) + 4 + (int)pvVar6))(1);
      }
      if (local_a8 != (void *)0x0) {
        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)((int)local_a8 + 4) + 4) + 4 + (int)local_a8))
                  (1);
      }
      if (local_9c != (void *)0x0) {
        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)((int)local_9c + 4) + 4) + 4 + (int)local_9c))
                  (1);
      }
      if (local_a4 != 0) {
        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(local_a4 + 4) + 4) + 4 + local_a4))(1);
      }
      if (local_ac != 0) {
        (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(local_ac + 4) + 4) + 4 + local_ac))(1);
      }
      ExceptionList = local_c;
      return 0;
    }
    Vehicle_SetEquippedArmor(param_1,pArmorItem,'\0');
    uVar1 = *(uint *)(param_3 + 0xe6d8);
    iVar4 = *(int *)(param_3 + 0xe6dc);
    *(uint *)(param_3 + 0xe6dc) = iVar4 + (uint)(0xfffffffe < uVar1);
    *(uint *)(param_3 + 0xe6d8) = uVar1 + 1;
    FUN_00512160(uVar1,iVar4,0);
    (**(code **)(*(int *)(*(int *)(*(int *)((int)pArmorItem + 4) + 4) + 4 + (int)pArmorItem) + 0x218
                ))(param_3);
    psVar9 = (short *)((int)pArmorItem + 0xb6);
    iVar4 = 6;
    do {
      sVar2 = FUN_0040dab0((float)(int)*psVar9 * local_b0);
      *psVar9 = sVar2;
      psVar9 = psVar9 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar3 = FUN_0040dab0((float)(int)*(short *)((int)pArmorItem + 0xb4) * local_b0);
    *(uint16_t *)((int)pArmorItem + 0xb4) = uVar3;
    uVar3 = FUN_0040dab0((float)(int)*(short *)((int)pArmorItem + 0xc2) * local_b0);
    *(uint16_t *)((int)pArmorItem + 0xc2) = uVar3;
    sVar2 = FUN_0040dab0((float)*(int *)((int)pArmorItem + 0xb0) * local_b0);
    *(int *)((int)pArmorItem + 0xb0) = (int)sVar2;
  }
  ExceptionList = local_c;
  return 1;
}
