// =============================================================================
// FUN_0051f8e0  (Ghidra twin of LookupRaceDisplayName_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f8e0
// Address:   0x0051f8e0  (autoassault.exe, image base 0x400000)
// Body:      0x0051f8e0 – 0x0051f90b exclusive (43 B / 0x2B)
// System:    skills-abilities
// Generated: 2026-08-05 R12-017 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: LookupRaceDisplayName_Inferred.cpp
// =============================================================================

// PURPOSE: Race id → static English display name leaf (Human / Mutant / Biomek / Unknown).
// ABI: cdecl; stack raceId; plain RET; returns const char* (rodata imm).
// Callers: UI_AppendItemRequirements (0x00845360), UI_AppendCraftRequirements (0x00846820).

char * FUN_0051f8e0(int param_1)
{
  if (param_1 == 0) {
    return "Human";
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      return "Unknown";
    }
    return "Biomek";
  }
  return "Mutant";
}
