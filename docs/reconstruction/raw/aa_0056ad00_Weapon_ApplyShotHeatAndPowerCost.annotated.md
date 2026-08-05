# Annotated low-level: Weapon_ApplyShotHeatAndPowerCost

| Field | Value |
|---|---|
| Stable ID | a_0056ad00 |
| VA | 0x0056ad00 |
| System | unknown |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Apply heat + power cost after shot.

## Plate / prior RE notes

`
Weapon_ApplyShotHeatAndPowerCost
   
   Parameters:
     pWeapon - weapon object (fastcall ECX)
   
   Algorithm:
     only for player vehicle owner type 0xE:
       1) Weapon_CanFireHeatCheck — abort if overheated
       2) optional power cost weapon short +0xD6 vs creature power
       3) Vehicle_AddHeat(weapon.sinHeat at +0xD4)
   
   Returns: 0 blocked, 1 applied
   
   INFERRED: owner type 0xE = player vehicle path.
`

## Named callees (decompiler)

- Vehicle_AddHeat
- Weapon_ApplyShotHeatAndPowerCost
- Weapon_CanFireHeatCheck

## Machine-level notes

- Source: raw capture for a_0056ad00.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
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
  undefined2 extraout_var_00;
  undefined8 uVar4;
  
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
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
