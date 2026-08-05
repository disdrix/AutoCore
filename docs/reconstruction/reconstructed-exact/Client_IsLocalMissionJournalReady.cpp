// =============================================================================
// Client_IsLocalMissionJournalReady
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2020
// Address:   0x008a2020  (autoassault.exe, image base 0x400000)
// System:    missions-progression / journal UI
// Generated: 2026-07-29 W21-F dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + image thiscall setup.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Thin client wrapper: if local character global DAT_00d1b6d8 is non-null,
//   forward mission pointer to CVOGCharacter_IsMissionJournalReady (0x0052b3b0);
//   else return false. Used by mission-detail panel (FUN_008a3510) to gate
//   "_done" icon suffix and "  [Complete]" label chrome when panel mode == 0.
//
// ABI (image-sealed)
//   __cdecl, 1 stack arg, bool in AL; caller add esp,4.
//   ECX for the inner thiscall is loaded from DAT_00d1b6d8 (not from a this arg).
//
// CF summary
//   if (g_localCharacter == 0) return false;
//   return IsMissionJournalReady(g_localCharacter, mission);
// =============================================================================

#include <cstdint>

// External symbols (image / dual-sealed siblings)
extern void* DAT_00d1b6d8; // local CVOGCharacter* (BSS; image zero)

// aa_0052b3b0 — CVOGCharacter_IsMissionJournalReady (thiscall, ret 4)
extern "C" uint8_t __thiscall CVOGCharacter_IsMissionJournalReady(void* self, void* mission);

// Ghidra name: FUN_008a2020
// Prior alias: Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_008a2020

extern "C" uint8_t __cdecl Client_IsLocalMissionJournalReady(void* mission)
{
  void* localChar = DAT_00d1b6d8;
  if (localChar == nullptr) {
    // image: xor al, al; ret
    return 0;
  }
  // image: push [esp+4]; call 0x0052b3b0 with ECX = localChar
  return CVOGCharacter_IsMissionJournalReady(localChar, mission);
}
