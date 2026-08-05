// =============================================================================
// Vehicle_ApplyHardpointFireMask_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005021d0
// Address:   0x005021d0  (autoassault.exe, image base 0x400000)
// System:    combat / vehicle hardpoint weapons
// Generated: 2026-07-29 W21-H dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Apply a 3-bit fire mask to vehicle hardpoint weapons at vehicle+0x260[0..2].
//   Used by CVOGHBAIFollowVehicle::FireWeapons (geometry mask) and
//   VehicleNet_ReconcilePrediction (net reconcile sites).
//
//   Per occupied slot:
//     want = (mask & (1<<i)) != 0
//     if want && weapon+0xCB==0 && world+0x7E!=0:
//       canFire = weapon->vtbl+0x4C(0)
//       Weapon_SetFireFlagPair(weapon, canFire)
//       if canFire:
//         Weapon_FireHelper(...); optional LogicUi 0x31 if local player;
//         new CVOGHBWeaponFire HB (0x24) → enqueue world+0xE4EC → Start
//     else:
//       Weapon_SetFireFlagPair(weapon, want)
//
// CALLEES (named where dual-sealed):
//   Weapon_SetFireFlagPair_Inferred (FUN_0056a260)
//   Weapon_FireHelper_Inferred      (FUN_0056d160)
//   CVOGHBWeaponFire_ctor_Inferred  (FUN_005fe6a0)
//   Client_SendLogicUiPacket, CVOGHBList_Enqueue, CVOGHBBase_Start, operator_new
// =============================================================================

// Scaffold alias: FUN_005021d0.cpp

void __thiscall Vehicle_ApplyHardpointFireMask_Inferred(
    int vehicle /* ECX */,
    char fireMask /* stack, RET 4 */)
{
  int *weapon;
  char canFire;
  int localObj;
  void *mem;
  CVOGHBBase *action;
  int i;
  bool want;
  int uiPacket[7];
  undefined4 uiOpcodeField;
  void *excPrev;
  undefined1 *excHandler;
  undefined4 excState;

  excState = 0xffffffff;
  excHandler = &LAB_009a2edf;
  excPrev = ExceptionList;
  i = 0;
  ExceptionList = &excPrev;

  do {
    weapon = *(int **)(*(int *)(vehicle + 0x260) + i * 4);
    action = (CVOGHBBase *)0x0;
    if (weapon != (int *)0x0) {
      want = ((int)fireMask & (1 << ((byte)i & 0x1f))) != 0;
      if ((want && (*(char *)((int)weapon + 0xcb) == '\0')) &&
          (*(char *)(*(int *)(*(int *)(*(int *)(vehicle + 4) + 4) + 0xa8 + vehicle) + 0x7e) !=
           '\0')) {
        canFire = (**(code **)(*weapon + 0x4c))(0);
        FUN_0056a260(canFire); // Weapon_SetFireFlagPair_Inferred
        if (canFire != '\0') {
          // Decomp shows DAT_00b041b0; live this is weapon (see dual B).
          FUN_0056d160(&DAT_00b041b0, 0); // Weapon_FireHelper_Inferred
          localObj =
              (**(code **)(*(int *)(*(int *)(*(int *)(vehicle + 4) + 4) + 4 + vehicle) + 0x210))(0);
          if (localObj == 0) {
            localObj = 0;
          } else {
            localObj = *(int *)(*(int *)(localObj + 4) + 4) + 4 + localObj;
          }
          if (*(int *)(*(int *)(*(int *)(*(int *)(vehicle + 4) + 4) + 0xa8 + vehicle) + 0xe8a0) ==
              localObj) {
            uiOpcodeField = 0x31;
            uiPacket[0] = i;
            Client_SendLogicUiPacket(uiPacket);
          }
          mem = operator_new(0x24);
          excState = 0;
          if (mem != (void *)0x0) {
            action = (CVOGHBBase *)FUN_005fe6a0(
                *(undefined4 *)(*(int *)(vehicle + 0x260) + i * 4), 1000);
          }
          excState = 0xffffffff;
          CVOGHBList_Enqueue(
              *(void **)(*(int *)(*(int *)(*(int *)(vehicle + 4) + 4) + 0xa8 + vehicle) + 0xe4ec),
              action);
          CVOGHBBase_Start(action);
        }
      } else {
        FUN_0056a260(want); // clear or latch desired bit without HB fire path
      }
    }
    i = i + 1;
  } while (i < 3);

  ExceptionList = excPrev;
  return;
}
