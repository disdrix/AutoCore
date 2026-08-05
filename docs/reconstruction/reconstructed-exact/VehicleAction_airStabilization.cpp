// =============================================================================
// VehicleAction_airStabilization
// -----------------------------------------------------------------------------
// Stable ID: aa_00598320
// Address:   0x00598320  (autoassault.exe, image base 0x400000)
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
/* VehicleAction::airStabilization — AVD (Angular Velocity Damping) + collision response.
   
   Called from VehicleAction_applyAction (0x598650) AFTER calcWheelTorque.
   
   Two behaviors gated by a collision timer (DAT_00b041cc = global tick counter;
   stored collision time at entity+0x14):
   
   1. COLLISION WINDOW (if ticks_since_collision < 0x1900 = 6400):
      Sets this+0x1c = 1 (in-collision flag). If chassis speed > _DAT_009d54a8
      (~1.19e-7, i.e. moving at all), retrieves chassis transform + angular velocity
      and applies a corrective impulse via FUN_0040d260 (applyImpulse) and the
      physics body's vtable methods (+0x3c = applyAngularImpulse, +0x40 = applyPointImpulse).
      Uses AVDCollisionSpinDamping (entity+0xb0..0xb8 = angular velocity, +0xb4 modified
      by DAT_00a110d8 = 10.0 additive damping).
   
   2. POST-COLLISION RECOVERY (if was in collision, now expired):
      Iterates 3 slots (iVar6 = 0..0xC step 4 = 3 entries at entity+0x260), calls
      FUN_0056a260 (likely reset stabilizer). Then calls vtable+0x50 and +0x54
      (set angular velocity / clear flag), and FUN_004fbec0(0) to reset something.
      Final angular velocity set via FUN_004cfe60 (clamp/normalize).
   
   RESOLVED UNKNOWN #4 (AVD application):
     - AVDNormalSpinDamping: applied CONTINUOUSLY as chassisBody.angularDamping
       (set by applyAction before stepping the world).
     - AVDCollisionSpinDamping: applied ONLY within the 6400-tick (~1.07s at 60Hz)
       collision window, as an ADDITIVE to the angular velocity damping value
       (DAT_00a110d8 = 10.0 is the additive; the per-vehicle AVDCollisionSpinDamping
       field scales this).
     - Acts on ALL THREE angular velocity axes (x=roll, y=yaw, z=pitch), not just yaw.
     - AVDCollisionThreshold: gates which collision events trigger the window
       (checked in applyAction's collide handler, not here).
   
   Key constants:
     DAT_00b041cc = global tick counter
     DAT_00a110d8 = 10.0 (collision angular damping additive)
     DAT_009d54a8 = ~1.19e-7 (velocity epsilon) */

void __thiscall VehicleAction_airStabilization(int param_1,uint32_t /* width from decompiler */ *param_2)

{
  int *piVar1;
  char cVar2;
  float *pfVar3;
  uint32_t /* width from decompiler */ *puVar4;
  char *pcVar5;
  int iVar6;
  float10 fVar7;
  uint32_t /* width from decompiler */ *puStack_70;
  uint32_t /* width from decompiler */ *puStack_6c;
  uint32_t /* width from decompiler */ *puStack_68;
  uint32_t /* width from decompiler */ *puStack_64;
  uint8_t auStack_55 [4];
  uint8_t local_51;
  uint32_t /* width from decompiler */ local_50;
  uint32_t /* width from decompiler */ local_4c;
  uint32_t /* width from decompiler */ local_48;
  uint32_t /* width from decompiler */ local_44;
  uint32_t /* width from decompiler */ local_40;
  uint32_t /* width from decompiler */ local_3c;
  uint32_t /* width from decompiler */ local_38;
  uint32_t /* width from decompiler */ local_34;
  uint32_t /* width from decompiler */ local_30;
  uint32_t /* width from decompiler */ local_2c;
  uint32_t /* width from decompiler */ local_28;
  float local_24;
  uint32_t /* width from decompiler */ local_20;
  uint32_t /* width from decompiler */ local_1c;
  uint32_t /* width from decompiler */ local_18;
  uint32_t /* width from decompiler */ local_14;
  
  iVar6 = *(int *)(param_1 + 0x44);
  if ((*(char *)(iVar6 + 0x103) == '\0') &&
     (*(char *)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xa8 + iVar6) + 0x7e) == '\0')) {
    if (g_dwClientTickMs - *(int *)(iVar6 + 0x14) < 0x1900) {
      *(uint8_t *)(param_1 + 0x1c) = 1;
      puStack_64 = (uint32_t /* width from decompiler */ *)0x598372;
      pfVar3 = (float *)FUN_0053e0b0();
      if (_DAT_009d54a8 < SQRT(pfVar3[2] * pfVar3[2] + pfVar3[1] * pfVar3[1] + *pfVar3 * *pfVar3)) {
        piVar1 = *(int **)(param_1 + 0x44);
        puStack_64 = (uint32_t /* width from decompiler */ *)0x5983ae;
        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00404c90();
        local_20 = *puVar4;
        local_1c = puVar4[1];
        local_18 = puVar4[2];
        local_14 = puVar4[3];
        if (piVar1[2] == 0) {
          puVar4 = &DAT_00b04eb0;
        }
        else {
          puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(piVar1[2] + 0x3c) + 0x40);
        }
        local_50 = *puVar4;
        local_4c = puVar4[1];
        local_48 = puVar4[2];
        local_44 = puVar4[3];
        iVar6 = *(int *)(piVar1[2] + 0x3c);
        local_30 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x50);
        local_2c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x54);
        local_28 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x58);
        local_24 = *(float *)(iVar6 + 0x5c);
        puStack_64 = (uint32_t /* width from decompiler */ *)0x598454;
        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00404a20();
        local_40 = *puVar4;
        puStack_64 = (uint32_t /* width from decompiler */ *)0x1;
        local_3c = puVar4[1];
        puStack_68 = (uint32_t /* width from decompiler */ *)0x0;
        local_38 = puVar4[2];
        puStack_6c = (uint32_t /* width from decompiler */ *)0x3f800000;
        local_34 = puVar4[3];
        puStack_70 = &local_40;
        cVar2 = (**(code **)(*piVar1 + 0x3c))(*param_2,&local_20,&local_50,&local_30);
        if (cVar2 != '\0') {
          CVOGPhysics_ApplyImpulseVector(&puStack_70);
          FUN_00404dc0(&stack0xffffffa0);
          FUN_0040d040(&DAT_00b04eb0);
          return;
        }
      }
    }
    else if (*(char *)(param_1 + 0x1c) != '\0') {
      *(uint8_t *)(param_1 + 0x1c) = 0;
      iVar6 = 0;
      do {
        if (*(int *)(iVar6 + *(int *)(*(int *)(param_1 + 0x44) + 0x260)) != 0) {
          puStack_64 = (uint32_t /* width from decompiler */ *)0x0;
          puStack_68 = (uint32_t /* width from decompiler */ *)0x598517;
          FUN_0056a260();
        }
        iVar6 = iVar6 + 4;
      } while (iVar6 < 0xc);
      iVar6 = *(int *)(*(int *)(param_1 + 0x44) + 8);
      puStack_64 = (uint32_t /* width from decompiler */ *)&local_51;
      puStack_68 = (uint32_t /* width from decompiler */ *)0x598531;
      pcVar5 = (char *)FUN_005070b0();
      if ((*pcVar5 == '\0') && (*(int *)(iVar6 + 0x44) != 0)) {
        puStack_64 = (uint32_t /* width from decompiler */ *)0x598543;
        FUN_005070d0();
      }
      puStack_64 = &DAT_00b04eb0;
      puStack_68 = (uint32_t /* width from decompiler */ *)0x598550;
      (**(code **)(**(int **)(iVar6 + 0x3c) + 0x50))();
      iVar6 = *(int *)(*(int *)(param_1 + 0x44) + 8);
      puStack_68 = (uint32_t /* width from decompiler */ *)auStack_55;
      puStack_6c = (uint32_t /* width from decompiler */ *)0x598562;
      pcVar5 = (char *)FUN_005070b0();
      if ((*pcVar5 == '\0') && (*(int *)(iVar6 + 0x44) != 0)) {
        puStack_68 = (uint32_t /* width from decompiler */ *)0x598574;
        FUN_005070d0();
      }
      puStack_68 = &DAT_00b04eb0;
      puStack_6c = (uint32_t /* width from decompiler */ *)0x598581;
      (**(code **)(**(int **)(iVar6 + 0x3c) + 0x54))();
      puStack_6c = (uint32_t /* width from decompiler */ *)0x1;
      puStack_70 = (uint32_t /* width from decompiler */ *)0x0;
      VehicleEntity_SetDriveAxes(0);
      iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x44) + 8) + 0x3c);
      puStack_70 = (uint32_t /* width from decompiler */ *)(*(float *)(iVar6 + 0xb4) + DAT_00a110d8);
      puStack_6c = (uint32_t /* width from decompiler */ *)0x0;
      fVar7 = (float10)CVOGMap_CastTerrainHeight
                                 (*(uint32_t /* width from decompiler */ *)(iVar6 + 0xb0),*(uint32_t /* width from decompiler */ *)(iVar6 + 0xb8));
      iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x44) + 8) + 0x3c);
      local_20 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xb8);
      local_28 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xb0);
      local_24 = (float)fVar7;
      local_1c = 0;
      iVar6 = *(int *)(*(int *)(param_1 + 0x44) + 8);
      puStack_6c = (uint32_t /* width from decompiler */ *)&stack0xffffffa7;
      puStack_70 = (uint32_t /* width from decompiler */ *)0x598613;
      pcVar5 = (char *)FUN_005070b0();
      if ((*pcVar5 == '\0') && (*(int *)(iVar6 + 0x44) != 0)) {
        puStack_6c = (uint32_t /* width from decompiler */ *)0x598625;
        FUN_005070d0();
      }
      if ((*(char *)(iVar6 + 0x40) == '\0') || (*(int *)(iVar6 + 8) == 0)) {
        puStack_6c = &local_28;
        puStack_70 = (uint32_t /* width from decompiler */ *)0x59863e;
        (**(code **)(**(int **)(iVar6 + 0x3c) + 0x40))();
      }
    }
  }
  return;
}
