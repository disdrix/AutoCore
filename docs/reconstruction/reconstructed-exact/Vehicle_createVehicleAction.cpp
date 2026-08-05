// =============================================================================
// Vehicle_createVehicleAction
// -----------------------------------------------------------------------------
// Stable ID: aa_004fb660
// Address:   0x004fb660  (autoassault.exe, image base 0x400000)
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

/* Vehicle_createVehicleAction: entity+0x1a0 = new 0xC { [0]=VehicleAction*,
   [4]=hkVehicleFramework*, [8]=driverInput from FUN_005fe020 }. Framework built with input;
   VehicleAction_ctor(entity, rb, framework, mode2). */

void __fastcall Vehicle_createVehicleAction(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint32_t /* width from decompiler */ uVar4;
  bool bVar5;
  uint32_t /* width from decompiler */ local_1c;
  uint32_t /* width from decompiler */ local_18;
  uint32_t /* width from decompiler */ local_14;
  uint8_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2cfa;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x1a0) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    iVar3 = iVar1 + param_1;
    ExceptionList = &local_c;
    FUN_007a4480(0xffffffff,"Would have duplicate vehicle actions for %d, %I64d",
                 *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xac) + 0x34),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164),
                 *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));
    FUN_004f7d60();
  }
  if (*(int *)(param_1 + 8) != 0) {
    pvVar2 = operator_new(0xc);
    *(void **)(param_1 + 0x1a0) = pvVar2;
    FUN_005fe5c0();
    local_1c = DAT_00a0f710;
    local_18 = DAT_009cd0d8;
    local_14 = 0;
    local_10 = 1;
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x40,10);
    *(uint16_t *)(iVar3 + 4) = 0x40;
    uStack_4 = 0;
    uVar4 = hkDefaultAnalogDriverInput_ctor(&local_1c);
    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a0) + 8) = uVar4;
    uStack_4 = 0xffffffff;
    uVar4 = Vehicle_buildHavokVehicleFramework
                      (param_1,*(uint32_t /* width from decompiler */ *)
                                (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +
                                0xe4a4),0,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a0) + 8),
                       *(uint32_t /* width from decompiler */ *)(param_1 + 8),0);
    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a0) + 4) = uVar4;
    iVar3 = *(int *)(param_1 + 600);
    if (iVar3 != 0) {
      bVar5 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c)
                       + 0x4ce) == '\x02';
      if (bVar5) {
        iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x48,0x24);
        *(uint16_t *)(iVar3 + 4) = 0x48;
        uStack_4 = 1;
      }
      else {
        iVar3 = (**(code **)(*DAT_00b05060 + 0x10))();
        *(uint16_t *)(iVar3 + 4) = 0x48;
        uStack_4 = 2;
      }
      uVar4 = VehicleAction_ctor(param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 8),
                                 *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a0) + 4),bVar5);
      uStack_4 = 0xffffffff;
      **(uint32_t /* width from decompiler */ **)(param_1 + 0x1a0) = uVar4;
    }
    FUN_0055fe50(**(uint32_t /* width from decompiler */ **)(param_1 + 0x1a0));
    FUN_005d4050(1);
  }
  ExceptionList = local_c;
  return;
}
