// =============================================================================
// Mission_ComputeObjectiveXpAsFloat
// -----------------------------------------------------------------------------
// Purpose:  Thin presentation wrapper: objective* → float XP via
//           Mission_ComputeObjectiveXp, else 0.0f. Used by mission reward
//           chat toast only (display); no bias, no AddExperience.
//
// Address:  0x0051f510  (autoassault.exe, image base 0x400000)
// Body:     0x0051f510–0x0051f539 (42 bytes)
// Stable:   aa_0051f510
// System:   missions-progression
// Ghidra:   FUN_0051f510
//
// ABI:      stack formal pObjective; RET 4; return in x87 ST0
//           Body loads [esp+4] into ECX for __fastcall callee.
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W25-I seal).
// Twin/callee: Mission_ComputeObjectiveXp @ 0x0059dde0 (int pure calc)
// =============================================================================

// float g_flZero;  // 0.0f at 0x00a0f518
// int __fastcall Mission_ComputeObjectiveXp(void* pObjective);

/* Mission_ComputeObjectiveXpAsFloat

   Parameters:
     pObjective: CVOGObjective* (or compatible); mission def at +0x14c

   Returns:
     ST0 = (float)Mission_ComputeObjectiveXp(pObjective) when obj and
     mission def non-null; else ST0 = 0.0f.

   Notes:
     - Grant path does NOT use this wrapper; CompleteObjective calls the int
       calculator and applies g_flMissionXpRoundBias itself.
     - Toast may call the int calculator for a >0 gate, then this for float UI.
*/

float /* ST0 */ Mission_ComputeObjectiveXpAsFloat(void *pObjective)
{
  int xp;

  if (pObjective != 0 && *(int *)((char *)pObjective + 0x14c) != 0) {
    xp = Mission_ComputeObjectiveXp(pObjective);
    return (float)xp;
  }
  return 0.0f;  // g_flZero
}
