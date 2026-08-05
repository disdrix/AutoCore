// =============================================================================
// Weapon_ApplyShotHeatAndPowerCost
// -----------------------------------------------------------------------------
// Stable ID: aa_0056ad00
// Address:   0x0056ad00  (autoassault.exe, image base 0x400000)
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

/* Weapon_ApplyShotHeatAndPowerCost
   
   Parameters:
     pWeapon - weapon object (fastcall ECX)
   
   Algorithm:
     only for player vehicle owner type 0xE:
       1) Weapon_CanFireHeatCheck — abort if overheated
       2) optional power cost weapon short +0xD6 vs creature power
       3) Vehicle_AddHeat(weapon.sinHeat at +0xD4)
   
   Returns: 0 blocked, 1 applied
   
   INFERRED: owner type 0xE = player vehicle path. */

int __fastcall Weapon_ApplyShotHeatAndPowerCost(void *pWeapon)

{
  bool bVar1;
  undefined3 extraout_var;
  int ownerObject;
  int *piVar2;
  int iVar3;
  int extraout_EAX;
  uint16_t extraout_var_00;
  uint64_t uVar4;
  
  ownerObject = *(int *)(*(int *)(*(int *)((int)pWeapon + 4) + 4) + 0xb0 + (int)pWeapon);
  if ((ownerObject != 0) && (*(int *)(*(int *)(ownerObject + 0xa8) + 0x38) == 0xe)) {
    bVar1 = Weapon_CanFireHeatCheck(pWeapon);
    piVar2 = (int *)CONCAT31(extraout_var,bVar1);
    if (!bVar1) {
LAB_0056adca:
      return (uint)piVar2 & 0xffffff00;
    }
    if (0 < *(short *)((int)pWeapon + 0xd6)) {
      ownerObject = (**(code **)(**(int **)(*(int *)(*(int *)((int)pWeapon + 4) + 4) + 0xb0 +
                                           (int)pWeapon) + 0x1d4))();
      piVar2 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(ownerObject + 4) + 4) + 4 +
                                           ownerObject) + 0x210))(0);
      if (piVar2 != (int *)0x0) {
        if ((short)piVar2[0x4b] <= *(short *)((int)pWeapon + 0xd6)) goto LAB_0056adca;
        (**(code **)(*piVar2 + 0xb0))(CONCAT22(extraout_var_00,*(short *)((int)pWeapon + 0xd6)));
      }
    }
    iVar3 = (**(code **)(**(int **)(*(int *)(*(int *)((int)pWeapon + 4) + 4) + 0xb0 + (int)pWeapon)
                        + 0x1d4))();
    ownerObject = 0;
    if (iVar3 != 0) {
      uVar4 = (**(code **)(**(int **)(*(int *)(*(int *)((int)pWeapon + 4) + 4) + 0xb0 + (int)pWeapon
                                     ) + 0x1d4))((int)*(short *)((int)pWeapon + 0xd4));
      Vehicle_AddHeat((VehicleCombatPools_Inferred *)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      ownerObject = extraout_EAX;
    }
  }
  return CONCAT31((int3)((uint)ownerObject >> 8),1);
}
