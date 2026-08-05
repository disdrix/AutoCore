// =============================================================================
// Vehicle_GetCoolRate
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3840
// Address:   0x004f3840  (autoassault.exe, image base 0x400000)
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

/* Vehicle_GetCoolRate — heat cool amount applied each regen pulse.
   
   pVehicle: VehicleCombatPools_Inferred*
   Returns: plant.nCoolRate + vehicle.nCoolRateAdjust, or adjust+1 if no plant.
   UI shows rate * g_flDisplayRateScaleOneThird as /sec. */

int __fastcall Vehicle_GetCoolRate(VehicleCombatPools_Inferred *pVehicle)

{
  if (pVehicle->pPowerPlant_Inferred != (PowerPlantRuntime_Inferred *)0x0) {
    return (int)pVehicle->nCoolRateAdjust_Inferred + (int)pVehicle->pPowerPlant_Inferred->nCoolRate;
  }
  return pVehicle->nCoolRateAdjust_Inferred + 1;
}
