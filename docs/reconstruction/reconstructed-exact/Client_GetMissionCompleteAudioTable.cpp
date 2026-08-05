// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_00723510, _atexit.
//  - Return sites: 1.

// =============================================================================
// Client_GetMissionCompleteAudioTable
// -----------------------------------------------------------------------------
// Stable ID: aa_00723820
// Address:   0x00723820  (autoassault.exe, image base 0x400000)
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

/* Client_GetMissionCompleteAudioTable

   

   One-time init of mission-complete audio/UI table at DAT_00d20210.

   Called with names mission_complete_3 / mission_complete_5 from CVOGReaction_CompleteObjective. */



undefined * Client_GetMissionCompleteAudioTable(void)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac7a0;

  local_c = ExceptionList;

  if ((DAT_00d20630 & 1) == 0) {

    DAT_00d20630 = DAT_00d20630 | 1;

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_00723510(&DAT_00d20210);

    _atexit((_func_4879 *)&LAB_009c3700);

  }

  ExceptionList = local_c;

  return &DAT_00d20210;

}
