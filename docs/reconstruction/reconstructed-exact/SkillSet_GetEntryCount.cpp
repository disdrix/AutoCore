// =============================================================================
// SkillSet_GetEntryCount
// -----------------------------------------------------------------------------
// Stable ID: aa_00402d80
// Address:   0x00402d80  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
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

/* SkillSet_GetEntryCount(pSkillSet)
   
   Returns (end-begin)/0x18 for NPCSkillSetEntry vector at +0x4/+0x8. */

int __fastcall SkillSet_GetEntryCount(void *pSkillSet)

{
  if (*(int *)((int)pSkillSet + 4) == 0) {
    return 0;
  }
  return (*(int *)((int)pSkillSet + 8) - *(int *)((int)pSkillSet + 4)) / 0x18;
}
