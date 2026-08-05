// =============================================================================
// Vehicle_buildHavokVehicleFramework
// -----------------------------------------------------------------------------
// Stable ID: aa_005fd390
// Address:   0x005fd390  (autoassault.exe, image base 0x400000)
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
/* Vehicle::buildHavokVehicleFramework — THE vehicle-physics setup function (sole caller of every
   hkVehicle component ctor). Called from Vehicle_createVehicleAction (0x4fb660).
   
   Constructs, in order (new-size → ctor → class, identified via the Havok reflection blocks in
   .rdata 0x9e4a00–0x9e5300: layout per class = [vtable][member table
   {namePtr,type,offset}][member-name strings][class-name string]):
     0x390 → hkDefaultWheels_ctor      (0x64fee0, vtable 0x9e5010) — desc built by FUN_005fcce0
     0x40  → hkDefaultChassis_ctor     (0x64fdf0, vtable 0x9e4fd0) — holds the hkRigidBody at
   +0x3c
     0x38  → TankSteering_ctor         (0x64fc80, vtable 0x9e4f1c) IF vehicleData byte +0x4c0 == 4
             else hkDefaultSteering_ctor (0x64fac0, vtable 0x9e4ee4) — desc by FUN_005fc710
     0x3c  → FUN_005d6640              (vtable 0x9dad44) — wheel-collide component (10-dword
   desc by FUN_005fc3d0; class name unconfirmed)
     0x60  → hkDefaultTransmission_ctor (0x64f610, vtable 0x9e4dac) — desc by FUN_005fc840
     0x54  → hkDefaultBrake_ctor       (0x64ed40, vtable 0x9e4cb8) — desc by FUN_005fcb00
     0x68  → hkDefaultSuspension_ctor  (0x64e510, vtable 0x9e4c00) — desc by FUN_005fcff0
     0x50  → hkDefaultAerodynamics_ctor (0x64da90, vtable 0x9e4b20) — desc by FUN_005fc4f0
     0x14  → hkAngularVelocityDamper_ctor (0x64d900, vtable 0x9e4a68) — 3 floats
   {normalSpinDamping, collisionSpinDamping, collisionThreshold} from entityData
   +0x5b8/+0x5bc/+0x5c0 × param_1[0x84]
     0x360 → hkVehicleFramework_ctor   (0x64cd30, vtable 0x9e4a40) — receives descriptor with
   all component ptrs; returned.
   
   IMPORTANT: there is NO hkDefaultEngine — AA replaced Havok's engine component; engine torque
   comes from VehicleAction_calcWheelTorque (0x598040) + VehicleEngine_torqueCurve2D (0x4a9750) in
   the AA layer.
   
   Tail computes a gear-ratio-weighted speed constant into vehicle+0x110 (param_1[0x44]) from
   vehicleData fields: +0x699 NumberOfGears(byte), +0x600 GearRatios[], +0x6b4/+0x6c4
   (TransmissionRatio-related), +0x5e8/+0x5ec, ×DAT_009dd348 — speed-governor precompute
   (SpeedLimiter/AbsoluteTopSpeed investigation anchor!). */

int Vehicle_buildHavokVehicleFramework
              (float *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5)

{
  char cVar1;
  int iVar2;
  uint32_t /* width from decompiler */ uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float fVar10;
  float *pfStack_24c;
  uint32_t /* width from decompiler */ uStack_248;
  uint8_t *puStack_244;
  float fStack_240;
  float *pfStack_23c;
  uint32_t /* width from decompiler */ uStack_238;
  uint32_t /* width from decompiler */ *puStack_234;
  uint8_t auStack_21c [8];
  uint8_t uStack_214;
  float afStack_210 [2];
  uint8_t auStack_208 [4];
  uint32_t /* width from decompiler */ uStack_204;
  uint32_t /* width from decompiler */ uStack_1f8;
  uint32_t /* width from decompiler */ uStack_1f4;
  uint32_t /* width from decompiler */ uStack_1f0;
  uint32_t /* width from decompiler */ uStack_1ec;
  uint32_t /* width from decompiler */ uStack_1e4;
  uint32_t /* width from decompiler */ local_1e0 [2];
  int local_1d8;
  uint uStack_1d4;
  uint uStack_1d0;
  uint8_t auStack_1c0 [4];
  uint32_t /* width from decompiler */ local_1bc;
  uint8_t auStack_1b8 [52];
  uint8_t auStack_184 [8];
  uint8_t auStack_17c [44];
  uint8_t auStack_150 [8];
  uint8_t auStack_148 [48];
  uint8_t auStack_118 [8];
  float afStack_110 [2];
  uint8_t auStack_108 [8];
  uint8_t auStack_100 [112];
  uint8_t auStack_90 [8];
  uint32_t /* width from decompiler */ local_88 [7];
  void *pvStack_6c;
  int iStack_64;
  uint8_t uStack_5c;
  uint8_t uStack_54;
  uint8_t uStack_4c;
  uint8_t uStack_44;
  uint8_t uStack_3c;
  uint8_t uStack_34;
  uint8_t uStack_2c;
  uint8_t uStack_24;
  void *pvStack_1c;
  uint8_t *puStack_18;
  uint32_t /* width from decompiler */ local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a7cd6;
  pvStack_1c = ExceptionList;
  puStack_234 = (uint32_t /* width from decompiler */ *)0x5fd3bd;
  ExceptionList = &pvStack_1c;
  FUN_00650020();
  puStack_234 = local_1e0;
  uStack_238 = param_3;
  pfStack_23c = param_1;
  local_14 = 0;
  fStack_240 = 8.80037e-39;
  FUN_005fc620();
  local_1bc = param_5;
  local_1d8 = param_4;
  puStack_234 = (uint32_t /* width from decompiler */ *)0x5fd3fa;
  FUN_0064ff90();
  puStack_234 = local_88;
  uStack_238 = param_3;
  pfStack_23c = param_1;
  local_14 = CONCAT31(local_14._1_3_,1);
  fStack_240 = 8.800447e-39;
  FUN_005fcce0();
  puStack_234 = (uint32_t /* width from decompiler */ *)0xa;
  local_88[0] = 8;
  uStack_238 = 0x390;
  pfStack_23c = (float *)0x5fd431;
  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))();
  *(uint16_t *)(iVar2 + 4) = 0x390;
  pfStack_23c = (float *)auStack_90;
  pvStack_1c._0_1_ = 2;
  fStack_240 = 8.800538e-39;
  uStack_1e4 = hkDefaultWheels_ctor();
  pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,1);
  pfStack_23c = (float *)0x5fd467;
  FUN_0064fe40();
  pfStack_23c = (float *)0x5fd46e;
  fVar6 = (float10)(**(code **)((int)*param_1 + 0x28))();
  afStack_210[0] = (float)fVar6;
  pfStack_23c = (float *)0xa;
  uStack_214 = 6;
  fStack_240 = 8.96831e-44;
  puStack_244 = (uint8_t *)0x5fd487;
  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))();
  *(uint16_t *)(iVar2 + 4) = 0x40;
  puStack_244 = auStack_21c;
  uStack_24 = 3;
  uStack_248 = 0x5fd4a5;
  uStack_1f0 = hkDefaultChassis_ctor();
  uStack_24 = 1;
  puStack_244 = (uint8_t *)0x5fd4ba;
  FUN_0064fd30();
  puStack_244 = auStack_208;
  uStack_248 = param_3;
  pfStack_24c = param_1;
  uStack_24 = 4;
  Vehicle_BuildSteeringDescriptor();
  puStack_244 = (uint8_t *)0xa;
  uStack_248 = 0x38;
  if (*(char *)(*(int *)(*(int *)(*(int *)((int)param_1[1] + 4) + 0xac + (int)param_1) + 0x3c) +
               0x4c0) == '\x04') {
    pfStack_24c = (float *)0x5fd4f9;
    puStack_234 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))();
    *(uint16_t *)((int)puStack_234 + 4) = 0x38;
    pfStack_24c = afStack_210;
    uStack_2c = 5;
    uStack_1ec = TankSteering_ctor();
  }
  else {
    pfStack_24c = (float *)0x5fd51e;
    puStack_234 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))();
    *(uint16_t *)((int)puStack_234 + 4) = 0x38;
    pfStack_24c = afStack_210;
    uStack_2c = 6;
    uStack_1ec = hkDefaultSteering_ctor();
  }
  uStack_2c = 4;
  pfStack_24c = (float *)0x5fd553;
  FUN_005d6720();
  pfStack_24c = afStack_110;
  FUN_005fc3d0(param_1,param_3);
  pfStack_24c = (float *)0xa;
  pfStack_23c = (float *)(**(code **)(*DAT_00b05060 + 0x10))(0x3c);
  *(uint16_t *)((int)pfStack_23c + 4) = 0x3c;
  uStack_34 = 7;
  uStack_1f0 = FUN_005d6640(auStack_118);
  uStack_34 = 4;
  FUN_0064f750();
  uStack_34 = 8;
  Vehicle_BuildTransmissionDescriptor(param_1,param_3,auStack_148);
  puStack_244 = (uint8_t *)(**(code **)(*DAT_00b05060 + 0x10))(0x60,10);
  *(uint16_t *)((int)puStack_244 + 4) = 0x60;
  uStack_3c = 9;
  uStack_1f4 = hkDefaultTransmission_ctor(auStack_150);
  uStack_3c = 8;
  FUN_0064ef20();
  uStack_3c = 10;
  FUN_005fcb00(param_1,param_3,auStack_17c);
  pfStack_24c = (float *)(**(code **)(*DAT_00b05060 + 0x10))(0x54,10);
  *(uint16_t *)(pfStack_24c + 1) = 0x54;
  uStack_44 = 0xb;
  uStack_1f8 = hkDefaultBrake_ctor(auStack_184);
  uStack_44 = 10;
  FUN_0064e670();
  uStack_44 = 0xc;
  Vehicle_BuildSuspensionDescriptor(param_1,param_3,auStack_100);
  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x68,10);
  *(uint16_t *)(iVar2 + 4) = 0x68;
  uStack_4c = 0xd;
  uStack_1f8 = hkDefaultSuspension_ctor(auStack_108);
  uStack_4c = 0xc;
  FUN_0064dda0();
  Vehicle_BuildAerodynamicsDescriptor(param_1,param_3,auStack_1b8);
  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x50,10);
  *(uint16_t *)(iVar2 + 4) = 0x50;
  uStack_54 = 0xe;
  uStack_204 = hkDefaultAerodynamics_ctor(auStack_1c0);
  uStack_54 = 0xc;
  FUN_0064d930();
  fVar10 = param_1[1];
  puStack_244 = (uint8_t *)
                (param_1[0x84] *
                *(float *)(*(int *)(*(int *)((int)param_1 + *(int *)((int)fVar10 + 4) + 0xac) + 0x3c
                                   ) + 0x5b8));
  fStack_240 = param_1[0x84] *
               *(float *)(*(int *)(*(int *)((int)param_1 + *(int *)((int)fVar10 + 4) + 0xac) + 0x3c)
                         + 0x5bc);
  pfStack_23c = *(float **)
                 (*(int *)(*(int *)((int)param_1 + *(int *)((int)fVar10 + 4) + 0xac) + 0x3c) + 0x5c0
                 );
  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x14,10);
  *(uint16_t *)(iVar2 + 4) = 0x14;
  uStack_5c = 0xf;
  uVar3 = hkAngularVelocityDamper_ctor(&pfStack_24c);
  uStack_5c = 0xc;
  if (uStack_1d4 == (uStack_1d0 & 0x7fffffff)) {
    FUN_005b3370(&local_1d8,4);
  }
  *(uint32_t /* width from decompiler */ *)(local_1d8 + uStack_1d4 * 4) = uVar3;
  uStack_1d4 = uStack_1d4 + 1;
  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x360,10);
  *(uint16_t *)(iVar2 + 4) = 0x360;
  iStack_64._0_1_ = 0x10;
  iVar4 = hkVehicleFramework_ctor(&stack0xfffffdd0);
  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x34) = param_2;
  iVar2 = *(int *)(*(int *)(*(int *)((int)param_1[1] + 4) + 0xac + (int)param_1) + 0x3c);
  fVar8 = (*(float *)(iVar2 + 0x6b4) /
          (*(float *)(iVar2 + 0x6c4) *
          *(float *)(iVar2 + 0x6d0 + (char)(*(char *)(iVar2 + 0x699) + -1) * 4))) * _DAT_009dd348;
  iStack_64 = CONCAT31(iStack_64._1_3_,0xc);
  fVar10 = 0.0;
  iVar9 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1[0x96] + 4) + 4) + 0xac +
                                           (int)param_1[0x96]) + 0x3c) + 0x4cc) << 0x18;
  iVar2 = 0;
  cVar1 = FUN_004f5560();
  if ('\0' < cVar1) {
    do {
      iVar5 = (int)(char)((uint)iVar9 >> 0x18);
      if (iVar2 < iVar5) {
        fVar7 = *(float *)(*(int *)(*(int *)(*(int *)((int)param_1[1] + 4) + 0xac + (int)param_1) +
                                   0x3c) + 0x5e8);
      }
      else {
        iVar5 = *(int *)(*(int *)(*(int *)((int)param_1[1] + 4) + 0xac + (int)param_1) + 0x3c);
        cVar1 = FUN_004f5560();
        fVar7 = *(float *)(iVar5 + 0x5ec);
        iVar5 = (int)cVar1 - (int)(char)((uint)iVar9 >> 0x18);
      }
      fVar10 = (fVar7 / (float)iVar5) *
               *(float *)(*(int *)(*(int *)(*(int *)((int)param_1[1] + 4) + 0xac + (int)param_1) +
                                  0x3c) + 0x600 + (char)iVar2 * 4) * fVar8 + fVar10;
      iVar2 = iVar2 + 1;
      cVar1 = FUN_004f5560();
    } while (iVar2 < cVar1);
  }
  param_1[0x44] = fVar10;
  iStack_64._0_1_ = 10;
  FUN_005fde60();
  iStack_64._0_1_ = 8;
  FUN_005fdb80();
  iStack_64._0_1_ = 4;
  FUN_005fdaf0();
  iStack_64._0_1_ = 1;
  if (-1 < (int)puStack_234) {
    (**(code **)(*DAT_00b05060 + 0x14))(pfStack_23c,(uint)puStack_234 & 0x7fffffff,0x12);
  }
  iStack_64 = (uint)iStack_64._1_3_ << 8;
  FUN_005fdc30();
  iStack_64 = 0xffffffff;
  if (-1 < local_1d8) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_1e0[0],local_1d8 * 4,0x12);
  }
  ExceptionList = pvStack_6c;
  return iVar4;
}
