// =============================================================================
// FUN_00502380
// -----------------------------------------------------------------------------
// Stable ID: aa_00502380
// Address:   0x00502380  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_00502380(int param_1,int *param_2)

{
  RE_VehicleCombatPoolFields *pVehicle;
  int iVar1;
  
  if ((*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) != 0) &&
     (param_2 != (int *)0x0)) {
    iVar1 = (**(code **)(*param_2 + 0x214))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_2 + 0x214))();
      if (*(int *)(iVar1 + 0x250) != param_1 + -0x670) {
        FUN_004ff350(0);
      }
    }
  }
  FUN_005131b0(param_2);
  if ((*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) != 0) &&
     (param_2 != (int *)0x0)) {
    iVar1 = (**(code **)(*param_2 + 0x214))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_2 + 0x214))();
      if (*(int *)(iVar1 + 0x250) == param_1 + -0x670) {
        pVehicle = (RE_VehicleCombatPoolFields *)(param_1 + -0x670);
        FUN_004ff350(1);
        iVar1 = Vehicle_CalcHeatMaximum(pVehicle);
        *(int *)(param_1 + -0x42c) = iVar1;
        Vehicle_RecalcCombatPools(pVehicle);
        (**(code **)(*(int *)pVehicle + 0x4c))();
      }
    }
  }
  return;
}
