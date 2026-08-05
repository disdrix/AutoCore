// =============================================================================
// FUN_00504ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00504ab0
// Address:   0x00504ab0  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_00504ab0(VehicleCombatPools_Inferred *param_1)

{
  int iVar1;
  uint uVar2;
  uint32_t /* width from decompiler */ local_e0 [3];
  uint32_t /* width from decompiler */ uStack_d4;
  int iStack_cc;
  void *pvStack_1c;
  uint8_t *puStack_18;
  uint32_t /* width from decompiler */ local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a2ffd;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  if (*(int *)(param_1->pOpaqueHeader_Inferred + 8) != 0) {
    ExceptionList = &pvStack_1c;
    FUN_005e1c80();
    local_14 = 0;
    FUN_005d3ef0(local_e0);
    local_e0[0] = (**(code **)(*(int *)param_1->pOpaqueHeader_Inferred + 0x18))();
    FUN_005d4810(local_e0);
    local_14 = 0xffffffff;
    if (-1 < iStack_cc) {
      (**(code **)(*DAT_00b05060 + 0x14))(uStack_d4,iStack_cc * 8,0x12);
    }
  }
  (**(code **)(*(int *)param_1->pOpaqueHeader_Inferred + 8))();
  if (*(int **)(param_1->pOpaqueHeader_Inferred +
               *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                                   *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) +
                                   0xb0) + 0x1dc))();
    if (iVar1 != 0) {
      uVar2 = 0;
      do {
        if (*(int *)(uVar2 + *(int *)(param_1->pPad_248_267_Inferred + 0x18)) != 0) {
          FUN_0056be70();
        }
        uVar2 = uVar2 + 4;
      } while (uVar2 < 0xc);
      if (*(int *)(param_1->pPad_248_267_Inferred + 0x1c) != 0) {
        FUN_0056be70();
      }
      iVar1 = *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4);
      if (((*(int *)(param_1->pOpaqueHeader_Inferred + iVar1 + 0xa8) != 0) &&
          (*(int *)(param_1->pOpaqueHeader_Inferred + iVar1 + 0xb0) != 0)) &&
         (*(int *)(*(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + iVar1 + 0xb0) + 0xa8) + 0x38)
          == 0x14)) {
        Vehicle_EnsureRegenerationHeartbeat(param_1);
      }
      if (*(int **)(param_1->pOpaqueHeader_Inferred +
                   *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xb0) == (int *)0x0
         ) {
        iVar1 = 0;
      }
      else {
        iVar1 = (**(code **)(**(int **)(param_1->pOpaqueHeader_Inferred +
                                       *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) +
                                       0xb0) + 0x1dc))();
      }
      if (((*(int *)(param_1->pOpaqueHeader_Inferred +
                    *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xa8) != 0) &&
          (iVar1 != 0)) &&
         ((*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1 ==
           *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred +
                            *(int *)(*(int *)(param_1->pOpaqueHeader_Inferred + 4) + 4) + 0xa8) +
                   0xe8a0) &&
          ((*(VehicleCombatPools_Inferred **)(iVar1 + 0x250) != (VehicleCombatPools_Inferred *)0x0
           && (*(VehicleCombatPools_Inferred **)(iVar1 + 0x250) == param_1)))))) {
        param_1->pOpaqueHeader_Inferred[0x103] = 1;
        Vehicle_RecalcCombatPools(param_1);
        FUN_004f39c0();
        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[1].pOpaqueHeader_Inferred + 4) + 0x5c) = DAT_00a0f704;
      }
      if (*(int *)(param_1->pOpaqueHeader_Inferred + 0x48) != 0) {
        FUN_004fcd80(0);
      }
    }
  }
  ExceptionList = pvStack_1c;
  return;
}
