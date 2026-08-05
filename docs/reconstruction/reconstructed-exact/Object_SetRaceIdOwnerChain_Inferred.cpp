// =============================================================================
// Object_SetRaceIdOwnerChain_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00512460
// Address:   0x00512460 – 0x00512487  (autoassault.exe, image base 0x400000)
// System:    object / faction
// Generated: Dual A/B sealed 2026-07-29 (W24-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00512460
// =============================================================================

/*
 * Role:
 *   Propagate a race/faction id onto a cloned object and its entire owner chain.
 *   Paired with Object_GetRootRaceId (0x00512440), which reads root +0x10 after
 *   walking the same +0xAC links.
 *
 * Spawn (FactionDirty):
 *   raceId = Object_GetRootRaceId(spawnpoint);
 *   Object_SetRaceIdOwnerChain_Inferred(spawned, raceId);
 *   // template vehicles may also apply to driver
 *
 * ABI: MSVC __thiscall — ECX = pObject, stack DWORD = raceId, ret 4, void.
 * Leaf. No null check on pObject. No cycle guard.
 */

typedef int RACE_ID_INFERRED;

void __thiscall Object_SetRaceIdOwnerChain_Inferred(void *pObject, RACE_ID_INFERRED raceId)

{
  int owner;
  int *pOwnerSlot;
  
  owner = *(int *)((int)pObject + 0xac);
  pOwnerSlot = (int *)((int)pObject + 0xac);
  *(RACE_ID_INFERRED *)((int)pObject + 0x10) = raceId;
  while (owner != 0) {
    owner = *pOwnerSlot;
    *(RACE_ID_INFERRED *)(owner + 0x10) = raceId;
    pOwnerSlot = (int *)(owner + 0xac);
    owner = *pOwnerSlot;
  }
  return;
}
