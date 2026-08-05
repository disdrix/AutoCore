// =============================================================================
// VehicleAction_applyAction
// -----------------------------------------------------------------------------
// Stable ID: aa_00598650
// Address:   0x00598650  (autoassault.exe, image base 0x400000)
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
/* VehicleAction::applyAction — per-tick vehicle physics driver (Havok 2.3 vehicle SDK).
   
   Source: autoassault.exe, asserted via string "VehicleAction::havok code" @ 0x9d5534
          and "VehicleAction::applyAction" @ 0x9d5550 (xref from this fn @ 0x598773).
   
   Architecture: AA's VehicleAction is a custom layer OVER Havok's hkVehicleFramework.
     param_1 = VehicleAction instance (this)
     param_2 = pointer to {dt, throttle_input[2]}  (param_2[0]=dt, param_2[1]=throttle)
     this+0x44 = Vehicle entity (chassis + driver refs)
     this+0x40 = wheel array container (this+0x40->+0xc=count, +0x80=array, +0x28=output torque
   array)
     this+0x20 = current throttle (float), this+0x24 = current brake (float)
     this+0x28 = current steer (float), this+0x2c = all-wheels-grounded flag
     this+0x30 = boost timer, this+0x34 = boost cooldown timer
   
   Movement modes (checked via byte at entity+0x4ce):
     0x02 = analog throttle ramp (the common path). Throttle ramps toward target at
            rate DAT_00a10e74 (=2.0/sec). Speed factor = min(speed_norm/0.6, 1.0)
            where speed_norm = |chassis_vel| / DAT_00af3388.
            Steering = throttle_value * speed_factor, clamped to [-1, +1].
     else  = direct velocity-coupled steering (computes desired angular velocity from
            chassis orientation matrix and forward vector — the large quaternion math block).
   
   RESOLVED UNKNOWNS (from docs/vehicle-physics-port.md):
     1. Steering-speed falloff: LINEAR — speedFactor = min(speed/0.6, 1.0) in mode 0x02.
        The actual wheel-angle reduction is Havok's own hkVehicleSteering (standard
        inverse-speed: angle = maxAngle * clamp(fullSpeedLimit/max(speed,fullSpeedLimit))).
     2. AerodynamicsLift sign: handled by Havok hkVehicleAerodynamics (standard: +up).
     3. SpeedLimiter vs AbsoluteTopSpeed: STILL OPEN. Earlier guess that this is handled in
        FUN_00636410/VehicleAction_tickSubsystems (0x636a60) was WRONG — those decompile to a
        trivial float setter and a generic per-component tick dispatcher respectively, with no
        visible SpeedLimiter/AbsoluteTopSpeed math. Where AA actually applies these two fields
        is UNCONFIRMED; the JS port (tools/model-viewer/vehicle/controller.js) uses its own
        reasonable approximation (soft taper between SpeedLimiter and AbsoluteTopSpeed, then a
        hard velocity clamp at AbsoluteTopSpeed) rather than a verified formula.
   
   Calls:
     VehicleAction_calcWheelTorque (0x598040) — per-wheel traction + torque
     VehicleAction_airStabilization (0x598320) — collision/airborne AVD damping
     VehicleAction_tickSubsystems (0x636a60) — generic per-component tick dispatch (0x5987ab)
     FUN_00636410 — trivial float setter, purpose unconfirmed (0x598ad2)
     VehicleEngine_torqueCurve2D (0x4a9750) via calcWheelTorque — 2D torque lookup
   
   Key constants:
     DAT_00a0f2a0 = 1.0   (normalized max / identity)
     DAT_00aaa668 = -1.0  (min throttle / reverse floor)
     DAT_00a10e74 = 2.0   (throttle ramp rate per second)
     DAT_00af3388 = 0.6   (speed normalization divisor for speed factor)
     DAT_00af3380 = 0.7   (upright threshold — dot(up, worldUp) below this = special handling) */

void __thiscall VehicleAction_applyAction(int param_1,float *param_2)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  float10 fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fStack_64;
  float afStack_50 [4];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [5];
  void *local_1c;
  uint8_t *puStack_18;
  int iStack_14;
  
  iStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a5ae7;
  local_1c = ExceptionList;
  iVar5 = *(int *)(param_1 + 0x44);
  iVar1 = *(int *)(*(int *)(iVar5 + 4) + 4) + iVar5;
  if ((((*(char *)(*(int *)(iVar1 + 0xa8) + 0x7e) == '\0') && (*(char *)(iVar5 + 0x103) == '\0')) &&
      ((*(uint *)(iVar1 + 0x180) >> 1 & 1) == 0)) &&
     ((0x77a1 < g_dwClientTickMs - *(int *)(iVar5 + 0x14) && (*(int *)(iVar1 + 0x18) == 0)))) {
    ExceptionList = &local_1c;
    FUN_007a4480();
    *(uint32_t /* width from decompiler */ *)
     (*(int *)(*(int *)(*(int *)(param_1 + 0x44) + 4) + 4) + 0xd0 + *(int *)(param_1 + 0x44)) = 0;
    FUN_004d4790();
    ExceptionList = local_1c;
    return;
  }
  ExceptionList = &local_1c;
  if ((*(int *)(iVar5 + 8) != 0) &&
     (ExceptionList = &local_1c,
     iVar1 = (**(code **)(**(int **)(*(int *)(iVar5 + 8) + 0x3c) + 0x18))(), iVar1 == 6)) {
    ExceptionList = local_1c;
    return;
  }
                    /* xref to "VehicleAction::applyAction" assert string @ 0x9d5550 — confirms
                       this fn IS VehicleAction::applyAction */
  FUN_0076cf00();
  iStack_14 = 0;
  FUN_0076cf00();
  iStack_14._0_1_ = 1;
  VehicleAction_tickSubsystems();
  iStack_14 = (uint)iStack_14._1_3_ << 8;
  FUN_0076cef0();
  iVar1 = *(int *)(*(int *)(param_1 + 0x40) + 0xc);
  iVar5 = *(int *)(iVar1 + 0xc);
  bVar7 = 0;
  fVar9 = 0.0;
  if (0 < iVar5) {
    iVar1 = *(int *)(iVar1 + 0x80);
    uVar2 = 0;
    do {
      pfVar3 = (float *)(uVar2 * 0xc0 + 0xb0 + iVar1);
      if (*pfVar3 <= fVar9 && fVar9 != *pfVar3) {
        fVar9 = *(float *)(uVar2 * 0xc0 + 0xb0 + iVar1);
      }
      bVar7 = bVar7 + 1;
      uVar2 = (uint)bVar7;
    } while ((int)uVar2 < iVar5);
    if (fVar9 < 0.0) {
      iVar1 = *(int *)(param_1 + 0x44);
      if (*(int *)(iVar1 + 8) == 0) {
        pfVar3 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);
      }
      else {
        pfVar3 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);
      }
      fStack_40 = *pfVar3;
      fStack_38 = pfVar3[2];
      fStack_34 = pfVar3[3];
      fStack_3c = pfVar3[1] - fVar9;
      iVar1 = *(int *)(iVar1 + 8);
      pcVar4 = (char *)FUN_005070b0();
      if ((*pcVar4 == '\0') && (*(int *)(iVar1 + 0x44) != 0)) {
        FUN_005070d0();
      }
      if ((*(char *)(iVar1 + 0x40) == '\0') || (*(int *)(iVar1 + 8) == 0)) {
        (**(code **)(**(int **)(iVar1 + 0x3c) + 0x40))();
      }
    }
  }
  fVar12 = DAT_00aaa668;
  fVar13 = g_flLevelUpUiBase_Inferred;
  fVar9 = g_flOne;
  iVar1 = *(int *)(param_1 + 0x44);
                    /* WI-MOV-002: entity+0x618 (steer axis) ramps into VehicleAction+0x24 →
                       [wheelsDesc+0x1c]; mode 0x02 scales by min(|v|/0.6,1) into VA+0x28 →
                       setSteeringAngle */
  fVar10 = *(float *)(iVar1 + 0x618) - *(float *)(param_1 + 0x24);
  if (fVar10 != 0.0) {
    if (((*(float *)(param_1 + 0x24) <= 0.0 && *(float *)(param_1 + 0x24) != 0.0) &&
        (DAT_00aaa668 < *(float *)(iVar1 + 0x618))) ||
       ((fVar11 = g_flOne, 0.0 < *(float *)(param_1 + 0x24) && (*(float *)(iVar1 + 0x618) < g_flOne)
        ))) {
      fVar11 = g_flLevelUpUiBase_Inferred;
    }
    fVar11 = *(float *)(param_1 + 0x20) * *param_2 * fVar11;
    if (ABS(fVar10) < fVar11) {
      fVar11 = ABS(fVar10);
    }
    if (0.0 <= fVar10) {
      if ((0.0 < fVar10) &&
         (fVar11 = *(float *)(param_1 + 0x24) + fVar11, *(float *)(param_1 + 0x24) = fVar11,
         fVar9 < fVar11)) {
        *(float *)(param_1 + 0x24) = fVar9;
      }
    }
    else {
      fVar11 = *(float *)(param_1 + 0x24) - fVar11;
      *(float *)(param_1 + 0x24) = fVar11;
      if (fVar11 < fVar12) {
        *(float *)(param_1 + 0x24) = fVar12;
        *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x40) + 0x14) + 0x1c) =
             *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);
        goto LAB_00598999;
      }
    }
    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x40) + 0x14) + 0x1c) =
         *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);
  }
LAB_00598999:
  iVar1 = *(int *)(param_1 + 0x44);
  if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 600) + 4) + 4) + 0xac +
                                 *(int *)(iVar1 + 600)) + 0x3c) + 0x4ce) == '\x02') {
    if (*(char *)(iVar1 + 0x102) == '\0') {
      *(uint8_t *)(*(int *)(param_1 + 0x3c) + 0x5c) = 1;
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x44) + 8) + 0x3c);
      fVar13 = SQRT(*(float *)(iVar1 + 0x40) * *(float *)(iVar1 + 0x40) +
                    *(float *)(iVar1 + 0x44) * *(float *)(iVar1 + 0x44) +
                    *(float *)(iVar1 + 0x48) * *(float *)(iVar1 + 0x48)) / _DAT_00af3388;
      fVar10 = fVar9;
      if (fVar13 <= g_flOne) {
        fVar10 = fVar13;
      }
      fVar10 = *(float *)(*(int *)(*(int *)(param_1 + 0x40) + 0x14) + 0x1c) * fVar10;
      if (fVar10 != *(float *)(param_1 + 0x28)) {
        if (fVar10 - *(float *)(param_1 + 0x28) <= 0.0) {
          fVar13 = *(float *)(param_1 + 0x28) - DAT_00a10e78;
        }
        else {
          fVar13 = *(float *)(param_1 + 0x28) + DAT_00a10e78;
        }
        *(float *)(param_1 + 0x28) = fVar13;
        if (ABS(fVar10 - *(float *)(param_1 + 0x28)) < DAT_00a10e78) {
          *(float *)(param_1 + 0x28) = fVar10;
        }
      }
      if (*(float *)(param_1 + 0x28) <= fVar9) {
        if (*(float *)(param_1 + 0x28) <= fVar12 && fVar12 != *(float *)(param_1 + 0x28)) {
          *(float *)(param_1 + 0x28) = fVar12;
        }
      }
      else {
        *(float *)(param_1 + 0x28) = fVar9;
      }
      hkpVehicleSteering_setSteeringAngle();
    }
    else {
      *(uint8_t *)(*(int *)(param_1 + 0x3c) + 0x5c) = 0;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar1 + 8) + 0x3c);
    fVar9 = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x3c) * fVar13 - fVar9;
    fVar10 = *(float *)(iVar1 + 0x3c) * fVar13;
    fVar12 = (*(float *)(iVar1 + 0x34) * DAT_00af3394 + *(float *)(iVar1 + 0x38) * DAT_00af3398 +
             *(float *)(iVar1 + 0x30) * DAT_00af3390) * fVar13;
    fStack_3c = (*(float *)(iVar1 + 0x38) * DAT_00af3390 - *(float *)(iVar1 + 0x30) * DAT_00af3398)
                * fVar10 + fVar12 * *(float *)(iVar1 + 0x34) + fVar9 * DAT_00af3394;
    fStack_38 = (*(float *)(iVar1 + 0x30) * DAT_00af3394 - *(float *)(iVar1 + 0x34) * DAT_00af3390)
                * fVar10 + fVar12 * *(float *)(iVar1 + 0x38) + fVar9 * DAT_00af3398;
    fVar12 = (*(float *)(iVar1 + 0x34) * DAT_00af3398 - *(float *)(iVar1 + 0x38) * DAT_00af3394) *
             fVar10 + fVar12 * *(float *)(iVar1 + 0x30) + fVar9 * DAT_00af3390;
    fVar9 = fStack_38 * fStack_38 + fStack_3c * fStack_3c + fVar12 * fVar12;
    if (fVar9 == 0.0) {
      fStack_40 = 0.0;
    }
    else {
      fStack_40 = g_flOne / SQRT(fVar9);
    }
    fStack_38 = fStack_38 * fStack_40;
    fStack_3c = fStack_3c * fStack_40;
    fStack_40 = fStack_40 * fVar12;
    fVar9 = (*(float *)(iVar1 + 0x30) * DAT_00af33a0 + DAT_00af33a4 * *(float *)(iVar1 + 0x34) +
            DAT_00af33a8 * *(float *)(iVar1 + 0x38)) * fVar13;
    fVar12 = *(float *)(iVar1 + 0x3c) * fVar13;
    fVar10 = *(float *)(iVar1 + 0x3c) * *(float *)(iVar1 + 0x3c) * fVar13 - g_flOne;
    afStack_50[1] =
         (DAT_00af33a0 * *(float *)(iVar1 + 0x38) - *(float *)(iVar1 + 0x30) * DAT_00af33a8) *
         fVar12 + fVar9 * *(float *)(iVar1 + 0x34) + DAT_00af33a4 * fVar10;
    fVar11 = (DAT_00af33a8 * *(float *)(iVar1 + 0x34) - DAT_00af33a4 * *(float *)(iVar1 + 0x38)) *
             fVar12 + *(float *)(iVar1 + 0x30) * fVar9 + fVar10 * DAT_00af33a0;
    afStack_50[2] =
         (*(float *)(iVar1 + 0x30) * DAT_00af33a4 - DAT_00af33a0 * *(float *)(iVar1 + 0x34)) *
         fVar12 + fVar9 * *(float *)(iVar1 + 0x38) + fVar10 * DAT_00af33a8;
    fVar13 = afStack_50[2] * afStack_50[2] + afStack_50[1] * afStack_50[1] + fVar11 * fVar11;
    if (fVar13 == 0.0) {
      afStack_50[0] = 0.0;
    }
    else {
      afStack_50[0] = g_flOne / SQRT(fVar13);
    }
    afStack_50[1] = afStack_50[1] * afStack_50[0];
    afStack_50[3] =
         (fVar12 * 0.0 + fVar9 * *(float *)(iVar1 + 0x3c) + DAT_00af33ac * fVar10) * afStack_50[0];
    afStack_50[2] = afStack_50[2] * afStack_50[0];
    afStack_50[0] = afStack_50[0] * fVar11;
    fVar9 = fStack_3c * DAT_00af3394 + fStack_38 * DAT_00af3398 + fStack_40 * DAT_00af3390;
    if ((fVar9 < DAT_00af3380) && (g_flMultiKillCountBlend < fVar9)) {
      fVar9 = 0.0 - (afStack_50[2] * DAT_00af3398 + afStack_50[1] * DAT_00af3394 +
                    afStack_50[0] * DAT_00af3390);
      afStack_30[1] = afStack_50[1] * fVar9 + DAT_00af3394;
      afStack_30[2] = afStack_50[2] * fVar9 + DAT_00af3398;
      afStack_30[0] = afStack_50[0] * fVar9 + DAT_00af3390;
      fVar9 = afStack_30[2] * afStack_30[2] + afStack_30[1] * afStack_30[1] +
              afStack_30[0] * afStack_30[0];
      if (fVar9 == 0.0) {
        fVar9 = 0.0;
      }
      else {
        fVar9 = g_flOne / SQRT(fVar9);
      }
      afStack_30[0] = fVar9 * afStack_30[0];
      afStack_30[2] = afStack_30[2] * fVar9;
      afStack_30[1] = afStack_30[1] * fVar9;
      fVar9 = afStack_30[2] * fStack_38 + afStack_30[1] * fStack_3c + afStack_30[0] * fStack_40;
      if (ABS(fVar9) < g_flOne) {
        fVar8 = (float10)_CIacos();
        fStack_64 = (float)fVar8;
      }
      else {
        fStack_64 = 0.0;
        if (fVar9 <= 0.0) {
          fStack_64 = DAT_009d54a4;
        }
      }
      fVar12 = afStack_30[2] * fStack_3c - afStack_30[1] * fStack_38;
      fVar9 = ABS(fVar12);
      fVar10 = fStack_38 * afStack_30[0] - afStack_30[2] * fStack_40;
      fVar13 = ABS(fVar10);
      afStack_30[2] = afStack_30[1] * fStack_40 - fStack_3c * afStack_30[0];
      afStack_30[2] = ABS(afStack_30[2]);
      afStack_30[0] = fVar12;
      afStack_30[1] = fVar10;
      if (fVar13 <= fVar9) {
        if (afStack_30[2] <= fVar9) {
          iVar5 = 0;
        }
        else {
          iVar5 = 2;
        }
      }
      else if (afStack_30[2] <= fVar13) {
        iVar5 = 1;
      }
      else {
        iVar5 = 2;
      }
      if (ABS(afStack_50[1]) <= ABS(afStack_50[0])) {
        if (ABS(afStack_50[2]) <= ABS(afStack_50[0])) {
          iVar6 = 0;
        }
        else {
          iVar6 = 2;
        }
      }
      else if (ABS(afStack_50[2]) <= ABS(afStack_50[1])) {
        iVar6 = 1;
      }
      else {
        iVar6 = 2;
      }
      if (0.0 <= afStack_30[iVar5]) {
        iVar5 = 0;
      }
      else {
        iVar5 = 8;
      }
      if (0.0 <= afStack_50[iVar6]) {
        iVar6 = 0;
      }
      else {
        iVar6 = 8;
      }
      if (iVar5 != iVar6) {
        fStack_64 = 0.0 - fStack_64;
      }
      fVar9 = DAT_00af337c * param_2[1];
      afStack_30[2] = *(float *)(iVar1 + 0x58) * fVar9;
      afStack_30[3] = *(float *)(iVar1 + 0x5c) * fVar9;
      if (*(float *)(iVar1 + 0x2c) == 0.0) {
        fVar13 = 0.0;
      }
      else {
        fVar13 = g_flOne / *(float *)(iVar1 + 0x2c);
      }
      fVar13 = fVar13 * *param_2 * _DAT_00af3378 * fStack_64 * param_2[1];
      fStack_38 = afStack_50[2] * fVar13 - afStack_30[2];
      fStack_34 = afStack_50[3] * fVar13 - afStack_30[3];
      fStack_40 = fVar13 * afStack_50[0] - *(float *)(iVar1 + 0x50) * fVar9;
      fStack_3c = afStack_50[1] * fVar13 - *(float *)(iVar1 + 0x54) * fVar9;
      pcVar4 = (char *)FUN_005d6870();
      if (*pcVar4 == '\0') {
        FUN_007a4480(0,"\n!&!&!&!&!&!&!&! Illegal Impulse Detected: A:%f X:%f, Y:%f, Z:%f\n",
                     (double)fStack_64,(double)fStack_40,(double)fStack_3c,(double)fStack_38);
      }
      else {
        FUN_005994e0();
      }
    }
  }
  VehicleAction_calcWheelTorque();
  VehicleAction_airStabilization();
  if (*(char *)(param_1 + 0x2c) == '\0') {
    iVar1 = *(int *)(param_1 + 0x44);
    if (*(int *)(iVar1 + 8) == 0) {
      pfVar3 = (float *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);
    }
    else {
      pfVar3 = (float *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);
    }
    afStack_30[0] = *pfVar3;
    afStack_30[1] = pfVar3[1];
    afStack_30[2] = pfVar3[2];
    FUN_0053e090();
    FUN_004f3680();
  }
  iVar1 = *(int *)(param_1 + 0x44);
  if (*(char *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) + 0x7d) == '\0') {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x110))();
  }
  fVar9 = DAT_00af3374;
  iVar1 = *(int *)(param_1 + 0x44);
  if ((*(char *)(iVar1 + 0x103) != '\0') ||
     (*(char *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) + 0x7e) != '\0')) {
    if ((*(char *)(param_1 + 0x2c) == '\0') ||
       ((*(float *)(param_1 + 0x30) <= DAT_00a0f70c && (0.0 < *(float *)(param_1 + 0x30))))) {
      fVar13 = *param_2 + *(float *)(param_1 + 0x30);
      *(float *)(param_1 + 0x30) = fVar13;
      if ((fVar13 < fVar9) && (_DAT_00af3370 < *(float *)(param_1 + 0x34))) {
        iVar5 = *(int *)(*(int *)(iVar1 + 8) + 0x3c);
        fStack_40 = *(float *)(iVar5 + 0x40);
        fVar9 = *(float *)(iVar5 + 0x44);
        fStack_38 = *(float *)(iVar5 + 0x48);
        fStack_34 = *(float *)(iVar5 + 0x4c);
        fStack_3c = fVar9;
        if (_DAT_00af336c < fVar9) {
          fStack_3c = 0.0;
          FUN_004e8a40(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0x30,afStack_50);
          fVar13 = DAT_00af3364;
          if (fVar9 * _DAT_00af3368 < DAT_00af3364) {
            fVar13 = fVar9 * _DAT_00af3368;
          }
          afStack_50[0] = afStack_50[0] * fVar13;
          afStack_50[1] = fVar13 * g_flZero;
          afStack_50[2] = afStack_50[2] * fVar13;
          afStack_50[3] = afStack_50[3] * fVar13;
          fStack_40 = afStack_50[0] + fStack_40;
          fStack_3c = afStack_50[1] + fStack_3c;
          fStack_38 = afStack_50[2] + fStack_38;
          fStack_34 = afStack_50[3] + fStack_34;
          CVOGPhysics_ApplyImpulseVector();
        }
      }
    }
    else if (*(float *)(param_1 + 0x30) <= 0.0) {
      *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) + *param_2;
    }
    else {
      *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;
      *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;
    }
  }
  iStack_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return;
}
