// =============================================================================
// LookupClassDisplayName_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f940
// Address:   0x0051f940–0x0051f9f9  (autoassault.exe, image base 0x400000)
// System:    missions-progression / character display
// Generated: 2026-08-04 WQ9G-E dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed product strings.
// Verdict:   accept-with-gaps
// Terminal:  false
// Bit-for-bit / runtime / differential: DEFERRED / OPEN
// =============================================================================
//
// PURPOSE:
//   Leaf classId × raceId → product English display name C-string.
//   Primary mission consumer: Character_GetClassDisplayName_Inferred (aa_00521900)
//   which ring-buffers the result for [$class] replacement.
//
// ABI:    cdecl; two stack args; plain RET; returns const char* (static rodata)
//
// TABLE (sealed via decompile + string imm read_memory):
//   class 0: Commando / Champion / Terminator  (else Commando)
//   class 1: Engineer / Shaman / Constructor   (else Engineer)
//   class 2: Lieutenant / Archon / MasterMind  (else Officer)
//   class 3: Bounty Hunter / Avenger / Agent   (else Ranger)
//   other:   Unknown
//
// CALLEES: none (pure leaf)
//
// GAPS:
//   - Product/PDB function English (_Inferred)
//   - Race id product dictionary (peer Character_GetRaceDisplayName)
//   - Runtime / bit-exact
// =============================================================================

const char* LookupClassDisplayName_Inferred(unsigned classId, int raceId)
{
  switch (classId) {
  case 0:
    if (raceId == 1) return "Champion";
    if (raceId == 2) return "Terminator";
    return "Commando";

  case 1:
    if (raceId == 1) return "Shaman";
    if (raceId == 2) return "Constructor";
    return "Engineer";

  case 2:
    if (raceId == 0) return "Lieutenant";
    if (raceId == 1) return "Archon";
    if (raceId == 2) return "MasterMind";
    return "Officer";

  case 3:
    if (raceId == 0) return "Bounty Hunter";
    if (raceId == 1) return "Avenger";
    if (raceId == 2) return "Agent";
    return "Ranger";

  default:
    return "Unknown";
  }
}

// Ghidra alias
extern "C" const char* FUN_0051f940(unsigned classId, int raceId)
{
  return LookupClassDisplayName_Inferred(classId, raceId);
}
