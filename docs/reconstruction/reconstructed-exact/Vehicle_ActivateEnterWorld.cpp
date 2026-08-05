// =============================================================================
// Vehicle_ActivateEnterWorld
// -----------------------------------------------------------------------------
// Stable ID: aa_00503f30
// Address:   0x00503f30  (autoassault.exe, image base 0x400000)
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

/* Vehicle_ActivateEnterWorld — owner enter-world / physics activate.
   
   Creates several TimedActions when owner is present:
     1) TimedAction_CreateTokenFlagAction (period g_dwTokenFlagActionPeriodMs=300000) — NOT combat
   pools
     2) Vehicle_CreateWeaponTrackAction (period 30 ms) — weapon tracking
     3) Vehicle_CreateCombatPoolAction → VehicleCombatPoolAction_ctor
          period 3000 ms (race 0/1/2) or 5000 ms — HP/shield/heat/power tick
   
   Also zeros heat (+0x150/+0x154) and fills shield from max (+0x144 ← +0x148) for player path. */

void __fastcall Vehicle_ActivateEnterWorld(VehicleCombatPools_Inferred *param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  void *pvVar5;
  CVOGHBBase *pCVar6;
  uint32_t /* width from decompiler */ uVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  void *unaff_ESI;
  float10 fVar11;
  float fVar12;
  uint32_t /* width from decompiler */ uVar13;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2fe8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_1->pOpaqueHeader_Inferred +
              *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) != 0) {
    pbVar1 = (byte *)(*(int *)(param_1->pOpaqueHeader_Inferred +
                              *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) +
                     0x17d);
    ExceptionList = &pvStack_c;
    *pbVar1 = *pbVar1 & 0xfe;
    (**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                           *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) + 600
                ))(DAT_009cd0f8,DAT_009cd0fc,DAT_009cd100,DAT_009cd104);
    if (*(int *)(*(int *)(param_1->pOpaqueHeader_Inferred +
                         *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) + 0xac)
        == 0) {
      *(uint32_t /* width from decompiler */ *)
       (*(int *)(param_1->pOpaqueHeader_Inferred +
                *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) + 0x60) = 0;
    }
    else {
      FUN_005063c0(0);
    }
  }
  (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                       *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 4) + 600))
            (DAT_009cd0f8,DAT_009cd0fc,DAT_009cd100);
  iVar4 = *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4);
  if (*(int *)(param_1->pOpaqueHeader_Inferred + iVar4 + 0xb0) == 0) {
    pbVar1 = param_1->pOpaqueHeader_Inferred + iVar4 + 100;
    pbVar1[0] = 0;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
  }
  else {
    FUN_005063c0(0);
  }
  if (*(int **)(param_1->pOpaqueHeader_Inferred +
               *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) != (int *)0x0) {
    iVar4 = (**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                                   *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) +
                                   0xb0) + 0x210))(0);
    if (iVar4 != 0) {
      iVar4 = (**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                                     *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) +
                                     0xb0) + 0x210))(0);
      if (*(char *)(iVar4 + 0x529) == '\0') {
        pvVar5 = operator_new(0x24);
        if (pvVar5 == (void *)0x0) {
          pCVar6 = (CVOGHBBase *)0x0;
        }
        else {
          pCVar6 = (CVOGHBBase *)
                   TimedAction_CreateTokenFlagAction(param_1,g_dwTokenFlagActionPeriodMs);
        }
        CVOGHBList_Enqueue(*(void **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                                              *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4)
                                                      + 4) + 0xa8) + 0xe4ec),pCVar6);
        CVOGHBBase_Start(pCVar6);
      }
    }
  }
  bVar3 = (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                               *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 4) +
                      0x198))();
  iVar4 = (uint)bVar3 << 0x18;
  FUN_0053d970(0);
  if (*(int *)(param_1->pPad_158_1DF_Inferred + 0x48) == 0) {
    (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                         *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 4) + 0x144))
              ();
    iVar9 = *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4);
    fVar11 = (float10)FUN_004cd220(*(uint32_t /* width from decompiler */ *)(param_1->pOpaqueHeader_Inferred + iVar9 + 0x84),
                                   *(uint32_t /* width from decompiler */ *)(param_1->pOpaqueHeader_Inferred + iVar9 + 0x8c));
    iVar9 = *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4);
    fVar12 = (float)fVar11 + g_flLevelUpUiBase_Inferred;
    if ((*(float *)(param_1->pOpaqueHeader_Inferred + iVar9 + 0x88) <= fVar12 &&
         fVar12 != *(float *)(param_1->pOpaqueHeader_Inferred + iVar9 + 0x88)) &&
       (*(float *)(param_1->pOpaqueHeader_Inferred + iVar9 + 0x88) = fVar12,
       *(int *)(param_1->pOpaqueHeader_Inferred + 8) != 0)) {
      FUN_0040d2a0(param_1->pOpaqueHeader_Inferred +
                   *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0x84);
    }
    Vehicle_createVehicleAction();
  }
  if ((char)((uint)iVar4 >> 0x18) != '\0') {
    iVar9 = *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4);
    if (*(char *)(*(int *)(param_1->pOpaqueHeader_Inferred +
                          *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xa8) + 0xf6
                 ) == '\0') {
      (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred + iVar9 + 4) + 0x240))(1);
      if (*(int **)(param_1->pOpaqueHeader_Inferred +
                   *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) != (int *)0x0
         ) {
        piVar10 = (int *)(**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                                                *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred +
                                                                 4) + 4) + 0xb0) + 0x1dc))();
        (**(code **)(*piVar10 + 0xac))(1);
      }
    }
    else {
      iVar2 = *(int *)(param_1->pOpaqueHeader_Inferred + iVar9 + 4);
      uVar7 = (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred + iVar9 + 4) + 0x244))();
      (**(code **)(iVar2 + 0x240))(uVar7);
      piVar10 = *(int **)(param_1->pOpaqueHeader_Inferred +
                         *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0);
      if (piVar10 != (int *)0x0) {
        piVar8 = (int *)(**(code **)(*piVar10 + 0x1dc))();
        iVar9 = (**(code **)(*piVar10 + 0x1dc))();
        (**(code **)(*piVar8 + 0xac))(*(uint16_t *)(iVar9 + 0x12e));
      }
      param_1->nCurrentShield = param_1->nMaxShield & (param_1->nMaxShield < 1) - 1;
    }
    iVar9 = *(int *)(param_1->pOpaqueHeader_Inferred + 4);
    param_1->nCurrentHeat = 0;
    param_1->nCoolAccumulator = 0;
    if (*(void **)(param_1->pOpaqueHeader_Inferred + *(int *)(iVar9 + 4) + 0x18) != (void *)0x0) {
      NetObject_SetMaskBits
                (*(void **)(param_1->pOpaqueHeader_Inferred + *(int *)(iVar9 + 4) + 0x18),0x20000000
                 ,0);
    }
  }
  param_1->pPad_158_1DF_Inferred[*(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0x29]
       = param_1->pPad_158_1DF_Inferred
         [*(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0x29] & 0xfe;
  if (*(int *)(param_1->pPad_248_267_Inferred + 0x10) != 0) {
    *(uint8_t *)(*(int *)(param_1->pPad_248_267_Inferred + 0x10) + 0x11c) = 1;
  }
  if ((char)((uint)iVar4 >> 0x18) != '\0') {
    (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                         *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 4) + 0x104))
              (1);
  }
  iVar9 = 0;
  do {
    if (*(int *)(iVar9 + *(int *)(param_1->pPad_248_267_Inferred + 0x18)) != 0) {
      FUN_0056b400(0);
      FUN_0056a260(0);
    }
    iVar9 = iVar9 + 4;
  } while (iVar9 < 0xc);
  if ((char)((uint)iVar4 >> 0x18) != '\0') {
    param_1->pOpaqueHeader_Inferred[0x104] = 1;
    iVar4 = *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4);
    (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred + iVar4 + 4) + 0x218))
              (*(uint32_t /* width from decompiler */ *)(param_1->pOpaqueHeader_Inferred + iVar4 + 0xa8));
    pvVar5 = operator_new(0x28);
    if (pvVar5 == (void *)0x0) {
      pCVar6 = (CVOGHBBase *)0x0;
    }
    else {
      pCVar6 = (CVOGHBBase *)Vehicle_CreateWeaponTrackAction(param_1);
    }
    CVOGHBList_Enqueue(*(void **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                                          *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4
                                                  ) + 0xa8) + 0xe4ec),pCVar6);
    CVOGHBBase_Start(pCVar6);
    if (*(int *)(param_1->pOpaqueHeader_Inferred +
                *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) != 0) {
      Vehicle_EnsureRegenerationHeartbeat(param_1);
      Vehicle_RecalcCombatPools(param_1);
      FUN_00516a00(0);
      iVar4 = (**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                                     *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) +
                                     0xb0) + 0x214))();
      if (iVar4 != 0) {
        piVar10 = (int *)(**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                                                *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred +
                                                                 4) + 4) + 0xb0) + 0x214))();
        (**(code **)(*piVar10 + 0xc0))(1,0xffffffff);
      }
      iVar4 = (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                                   *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 4)
                          + 0x210))(0);
      if (iVar4 != 0) {
        uVar13 = 0;
        iVar4 = (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                                     *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 4
                                     ) + 0x210))(0);
        uVar7 = 1;
        (**(code **)(*(int *)(param_1->pOpaqueHeader_Inferred +
                             *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 4) +
                    0x210))(0,*(uint32_t /* width from decompiler */ *)(iVar4 + 0xd64),1);
        FUN_00525cc0(uVar7,uVar13);
      }
      if (*(char *)(*(int *)(param_1->pOpaqueHeader_Inferred +
                            *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xa8) +
                   0x7e) != '\0') {
        FUN_004ff350(1);
      }
    }
  }
  ExceptionList = unaff_ESI;
  return;
}
