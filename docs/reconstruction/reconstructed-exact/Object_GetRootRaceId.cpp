// =============================================================================
// Object_GetRootRaceId
// -----------------------------------------------------------------------------
// Stable ID: aa_00512440
// Address:   0x00512440 – 0x0051245f  (autoassault.exe, image base 0x400000)
// System:    object / faction
// Generated: 2026-07-23 scaffold; Dual A/B sealed 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf: walk owner chain at +0xAC; return root race/faction DWORD at +0x10.
 * - __fastcall: pObject in ECX; return in EAX.
 * - No null check on pObject; no cycle guard on owner chain.
 * - Companion writer FUN_00512460 @ 0x00512460 (not this unit).
 * - Runtime / differential verification: OPEN.
 */

/* ClonedObject_GetRootRaceId — walk owner chain (+0xAC) to the root object,
   return race id at root+0x10.

   Used by VehicleCombatPoolAction_ctor to pick 3000 vs 5000 ms period
   (race ids 0/1/2 → 3000 ms). */

RACE_ID_INFERRED __fastcall Object_GetRootRaceId(void *pObject)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)((int)pObject + 0xac);
  while (pvVar1 = pvVar2, pvVar1 != (void *)0x0) {
    pObject = pvVar1;
    pvVar2 = *(void **)((int)pvVar1 + 0xac);
  }
  return *(RACE_ID_INFERRED *)((int)pObject + 0x10);
}
