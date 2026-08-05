// =============================================================================
// FUN_00589bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00589bc0
// Address:   0x00589bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00589bc0 @ 0x00589bc0
// Stable ID: aa_00589bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: __RTDynamicCast×2, FUN_00589bc0, Vehicle_AddHeat.
//  - Return sites: 1.

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

int FUN_00589bc0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int nHeatDelta;

  VehicleCombatPools_Inferred *pVehicle;

  int iVar1;

  

  pVehicle = (VehicleCombatPools_Inferred *)

             __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                             &CVOGVehicle::RTTI_Type_Descriptor,0);

  if ((pVehicle == (VehicleCombatPools_Inferred *)0x0) &&

     (iVar1 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGCreature::RTTI_Type_Descriptor,0), iVar1 != 0)) {

    pVehicle = *(VehicleCombatPools_Inferred **)(iVar1 + 0x250);

  }

  iVar1 = 0;

  if (pVehicle != (VehicleCombatPools_Inferred *)0x0) {

    nHeatDelta = *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4);

    iVar1 = pVehicle->nCurrentHeat;

    if ((*(int *)(pVehicle->pOpaqueHeader_Inferred + nHeatDelta + 0xa8) != 0) &&

       (*(char *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + nHeatDelta + 0xa8) + 0x7e) != '\0')) {

      Vehicle_AddHeat(pVehicle,nHeatDelta);

    }

    iVar1 = pVehicle->nCurrentHeat - iVar1;

  }

  return iVar1;

}
