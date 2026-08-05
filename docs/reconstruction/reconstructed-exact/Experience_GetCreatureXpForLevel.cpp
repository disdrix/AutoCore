// =============================================================================
// Experience_GetCreatureXpForLevel
// -----------------------------------------------------------------------------
// Stable ID: aa_004c97b0
// Address:   0x004c97b0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
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

/* Experience_GetCreatureXpForLevel - tCreatureExperienceLevel lookup

   

   Parameters: nCreatureLevel

   Returns: uint XP at map entry +0x10, or 0 if missing

   Lazy-inits via Experience_EnsureCreatureXpTableLoaded_INFERRED

   Map entry type: CreatureXpMapEntry_INFERRED */



uint __cdecl Experience_GetCreatureXpForLevel(int nCreatureLevel)



{

  void *pvVar1;

  int *extraout_EAX;

  int *unaff_EDI;

  uint8_t abScratch [4];

  

  if (g_nCreatureXpTableReady == 0) {

    Experience_EnsureCreatureXpTableLoaded_INFERRED();

  }

  Map_LowerBoundFindByIntKey(&DAT_00b04270,abScratch,&nCreatureLevel,unaff_EDI);

  pvVar1 = (void *)*extraout_EAX;

  if (g_nCreatureXpTableReady == 0) {

    Experience_EnsureCreatureXpTableLoaded_INFERRED();

  }

  if (pvVar1 != g_pCreatureXpMapEnd) {

    return *(uint *)((int)pvVar1 + 0x10);

  }

  return 0;

}
