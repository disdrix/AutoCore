// =============================================================================
// Vehicle_RecalcCombatPools
// -----------------------------------------------------------------------------
// Stable ID: aa_00501f60
// Address:   0x00501f60  (autoassault.exe, image base 0x400000)
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
                       *(uint32_t /* width from decompiler */ *)
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
