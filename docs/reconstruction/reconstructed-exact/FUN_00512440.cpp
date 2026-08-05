// =============================================================================
// FUN_00512440
// -----------------------------------------------------------------------------
// Stable ID: aa_00512440
// Address:   0x00512440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00512440 @ 0x00512440
// Stable ID: aa_00512440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, while×1.
//  - Notable callees: Object_GetRootRaceId, chain.
//  - Return sites: 2.

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

/* ClonedObject_GetRootRaceId - walk owner chain (+0xAC) to the root object,

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
