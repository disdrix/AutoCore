// =============================================================================
// Experience_EnsureCreatureXpTableLoaded_INFERRED
// -----------------------------------------------------------------------------
// Stable ID: aa_005128f0
// Address:   0x005128f0  (autoassault.exe, image base 0x400000)
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

/* Experience_EnsureCreatureXpTableLoaded_INFERRED
   
   INFERRED lazy loader for tCreatureExperienceLevel map. */

void Experience_EnsureCreatureXpTableLoaded_INFERRED(void)

{
  int iVar1;
  
  FUN_007e1d80();
  iVar1 = FUN_007cd150(&DAT_00b04270);
  FUN_007b7df0();
  if (iVar1 < 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  return;
}
