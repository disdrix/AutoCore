# Annotated low-level: Vehicle_RecalcCombatPools

| Field | Value |
|---|---|
| Stable ID | `aa_00501f60` |
| VA | `0x00501f60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00501f60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_RecalcCombatPools — recompute max HP after equip changes.
   
   Parameters:
     pVehicle (ECX): vehicle object
   Returns: void.
   
   Algorithm:
     Skip if flag@+0x2ac; require owner context@+0xb0
     dirty@+0x180 |= 0x80; pre-hooks vfunc+0x23c/+0x244
     maxHp = Vehicle_CalcMaxHitPoints(this); set max vfunc+0x248
     scale current HP vfunc+0x240(max * ratio)  // ratio may be ESI
     optional kill-XP weapon bonus if owner char@+0xa8
   
   Callers: Vehicle_SetEquippedArmor, Vehicle_SetEquippedRaceItem. */

void __fastcall Vehicle_RecalcCombatPools(void *pVehicle)

{
  char bAllowKillXp;
  int nMaxHpOrCtx;
  float flHpRatio_Inferred;
  int nBaseOrIface;
  byte *pbDirtyFlags;
  
  if (*(char *)((int)pVehicle + 0x2ac) == '\0') {
    nBaseOrIface = *(int *)(*(int *)((int)pVehicle + 4) + 4);
    nMaxHpOrCtx = *(int *)((int)pVehicle + nBaseOrIface + 0xb0);
    if ((nMaxHpOrCtx != 0) &&
       (((nMaxHpOrCtx = *(int *)(nMaxHpOrCtx + 0xa4), nMaxHpOrCtx == 0 ||
         (*(char *)(nMaxHpOrCtx + 0x7e) != '\0')) || (*(char *)(nMaxHpOrCtx + 0xf5) != '\0')))) {
      pbDirtyFlags = (byte *)((int)pVehicle + nBaseOrIface + 0x180);
      *pbDirtyFlags = *pbDirtyFlags | 0x80;
      nBaseOrIface = *(int *)(*(int *)((int)pVehicle + 4) + 4);
      (**(code **)(*(int *)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 4 + (int)pVehicle) + 0x23c))
                ();
      (**(code **)(*(int *)(nBaseOrIface + 4 + (int)pVehicle) + 0x244))();
      nBaseOrIface = *(int *)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 4 + (int)pVehicle);
      nMaxHpOrCtx = Vehicle_CalcMaxHitPoints(pVehicle);
      (**(code **)(nBaseOrIface + 0x248))(nMaxHpOrCtx);
      if (*(int *)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 0xa8 + (int)pVehicle) != 0) {
        bAllowKillXp = CVOGCharacter_WeaponAllowsKillXpBonus();
        if (bAllowKillXp != '\0') {
          FUN_004cf3b0(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 4 + (int)pVehicle,0,
                       *(undefined4 *)
                        (*(int *)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 0xa8 + (int)pVehicle)
                        + 0xe818));
        }
      }
      nBaseOrIface = *(int *)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 4 + (int)pVehicle);
      nMaxHpOrCtx = (**(code **)(*(int *)(*(int *)(*(int *)((int)pVehicle + 4) + 4) + 4 +
                                         (int)pVehicle) + 0x244))();
      (**(code **)(nBaseOrIface + 0x240))((int)((float)nMaxHpOrCtx * flHpRatio_Inferred));
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
