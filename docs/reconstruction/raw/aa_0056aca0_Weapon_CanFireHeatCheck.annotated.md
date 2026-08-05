# Annotated low-level: Weapon_CanFireHeatCheck

| Field | Value |
|---|---|
| Stable ID | a_0056aca0 |
| VA | 0x0056aca0 |
| System | unknown |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Can fire iff CurrentHeat(+0x150) < MaxHeat(+0x244).

## Plate / prior RE notes

`
Weapon_CanFireHeatCheck — returns true if vehicle heat < MaxHeat (can fire).
   
   Resolves owner character → vehicle (+0x250), then:
     return vehicle.CurrentHeat(+0x150) < vehicle.MaxHeat(+0x244)
   
   Overheat lock: heat >= max blocks all weapon fire.
`

## Named callees (decompiler)

- Weapon_CanFireHeatCheck

## Machine-level notes

- Source: raw capture for a_0056aca0.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
/* Weapon_CanFireHeatCheck — returns true if vehicle heat < MaxHeat (can fire).
   
   Resolves owner character → vehicle (+0x250), then:
     return vehicle.CurrentHeat(+0x150) < vehicle.MaxHeat(+0x244)
   
   Overheat lock: heat >= max blocks all weapon fire. */

bool __fastcall Weapon_CanFireHeatCheck(void *pWeapon)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pWeapon + 4) + 4) + 4 + (int)pWeapon) + 0x214
                      ))();
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1dc))();
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar1 + 0x250);
      goto compare_heat_to_max;
    }
  }
  iVar1 = 0;
compare_heat_to_max:
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0x150) < *(int *)(iVar1 + 0x244);
  }
  return true;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
