// =============================================================================
// Vehicle_GetPowerRegenRate
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3870
// Address:   0x004f3870  (autoassault.exe, image base 0x400000)
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

/* Vehicle_GetPowerRegenRate — raw power points added each regen pulse.
   
   pVehicle: VehicleCombatPools_Inferred*
   Returns: PowerPlantRuntime_Inferred.nPowerRegenRate (short at plant+0xB8),
   or 1 if no plant.
   UI shows rate * g_flDisplayRateScaleOneThird as MKz/sec. */

int __fastcall Vehicle_GetPowerRegenRate(VehicleCombatPools_Inferred *pVehicle)

{
  if (pVehicle->pPowerPlant_Inferred != (PowerPlantRuntime_Inferred *)0x0) {
    return (int)pVehicle->pPowerPlant_Inferred->nPowerRegenRate;
  }
  return 1;
}
