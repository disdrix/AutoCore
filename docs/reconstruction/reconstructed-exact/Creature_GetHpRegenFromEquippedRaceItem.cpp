// =============================================================================
// Creature_GetHpRegenFromEquippedRaceItem
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4860
// Address:   0x004c4860  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
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

/* Creature_GetHpRegenFromEquippedRaceItem - if creature has a vehicle (+0x250),

   delegates to Vehicle_GetHpRegenRate; else returns 1.

   

   Used by VehicleCombatPool_OnTick for the owner-creature HP regen path. */



int __fastcall Creature_GetHpRegenFromEquippedRaceItem(void *pCreature)



{

  int iVar1;

  

  if (*(RE_VehicleCombatPoolFields **)((int)pCreature + 0x250) != (RE_VehicleCombatPoolFields *)0x0)

  {

    iVar1 = Vehicle_GetHpRegenRate(*(RE_VehicleCombatPoolFields **)((int)pCreature + 0x250));

    return iVar1;

  }

  return 1;

}
