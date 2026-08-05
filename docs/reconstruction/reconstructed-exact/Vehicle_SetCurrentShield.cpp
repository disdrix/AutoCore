// =============================================================================
// Vehicle_SetCurrentShield
// -----------------------------------------------------------------------------
// Stable ID: aa_00419140
// Address:   0x00419140  (autoassault.exe, image base 0x400000)
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

/* Vehicle_SetCurrentShield
   
   Parameters:
     this       - vehicle (RE_VehicleCombatPoolFields*)
     nNewShield - desired current shield
   
   Algorithm:
     clamp to [0, MaxShield at +0x148]
     store at CurrentShield +0x144
   
   Returns: void
   
   NOTE: does NOT call NetObject_SetMaskBits — caller must dirty
   ShieldMask (0x04000000) when value changes. */

void __fastcall Vehicle_SetCurrentShield(VehicleCombatPools_Inferred *pVehicle,int nShield)

{
  int nMaxShield;
  int nClamped;
  int in_stack_00000004;
  
  nMaxShield = pVehicle->nMaxShield;
  nClamped = in_stack_00000004;
  if (nMaxShield <= in_stack_00000004) {
    nClamped = nMaxShield;
  }
  if (nClamped < 1) {
    nMaxShield = 0;
  }
  else if (in_stack_00000004 < nMaxShield) {
    pVehicle->nCurrentShield = in_stack_00000004;
    return;
  }
  pVehicle->nCurrentShield = nMaxShield;
  return;
}
